/*
 * UFRaw - Unidentified Flying Raw converter for digital camera images
 *
 * dcraw_indi.c - DCRaw functions made independed
 * Copyright 2004-2006 by Udi Fuchs
 *
 * based on dcraw by Dave Coffin
 * http://www.cybercom.net/~dcoffin/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation. You should have received
 * a copy of the license along with this program.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <glib.h>
#include "dcraw_api.h"

#define ushort UshORt
typedef unsigned short ushort;
typedef gint64 INT64;

/* FIXME: Should be extern definition */
const double xyz_rgb[3][3] = {                  /* XYZ from RGB *//*UF*/
      { 0.412453, 0.357580, 0.180423 },
        { 0.212671, 0.715160, 0.072169 },
	  { 0.019334, 0.119193, 0.950227 } };
const float d65_white[3] = { 0.950456, 1, 1.088754 };

#define CLASS

#define FORC3 for (c=0; c < 3; c++)
#define FORC4 for (c=0; c < 4; c++)
#define FORCC for (c=0; c < colors; c++)

#define SQR(x) ((x)*(x))
#define LIM(x,min,max) MAX(min,MIN(x,max))
#define ULIM(x,y,z) ((y) < (z) ? LIM(x,y,z) : LIM(x,z,y))
#define CLIP(x) LIM(x,0,65535)
#define SWAP(a,b) { a ^= b; a ^= (b ^= a); }

/*
   In order to inline this calculation, I make the risky
   assumption that all filter patterns can be described
   by a repeating pattern of eight rows and two columns

   Return values are either 0/1/2/3 = G/M/C/Y or 0/1/2/3 = R/G1/B/G2
 */
#define FC(row,col) \
	(int)(filters >> ((((row) << 1 & 14) + ((col) & 1)) << 1) & 3)

int  fc_INDI (const unsigned filters, const int row, const int col)
{
  static const char filter[16][16] =
  { { 2,1,1,3,2,3,2,0,3,2,3,0,1,2,1,0 },
    { 0,3,0,2,0,1,3,1,0,1,1,2,0,3,3,2 },
    { 2,3,3,2,3,1,1,3,3,1,2,1,2,0,0,3 },
    { 0,1,0,1,0,2,0,2,2,0,3,0,1,3,2,1 },
    { 3,1,1,2,0,1,0,2,1,3,1,3,0,1,3,0 },
    { 2,0,0,3,3,2,3,1,2,0,2,0,3,2,2,1 },
    { 2,3,3,1,2,1,2,1,2,1,1,2,3,0,0,1 },
    { 1,0,0,2,3,0,0,3,0,3,0,3,2,1,2,3 },
    { 2,3,3,1,1,2,1,0,3,2,3,0,2,3,1,3 },
    { 1,0,2,0,3,0,3,2,0,1,1,2,0,1,0,2 },
    { 0,1,1,3,3,2,2,1,1,3,3,0,2,1,3,2 },
    { 2,3,2,0,0,1,3,0,2,0,1,2,3,0,1,0 },
    { 1,3,1,2,3,2,3,2,0,2,0,1,1,0,3,0 },
    { 0,2,0,3,1,0,0,1,1,3,3,2,3,2,2,1 },
    { 2,1,3,2,3,1,2,1,0,3,0,2,0,2,0,2 },
    { 0,3,1,0,0,2,0,3,2,1,3,1,1,3,1,3 } };

  if (filters != 1) return FC(row,col);
  /* Assume that we are handling the Leaf CatchLight with
   * top_margin = 8; left_margin = 18; */
//  return filter[(row+top_margin) & 15][(col+left_margin) & 15];
  return filter[(row+10) & 8][(col+18) & 15];
}

void CLASS merror (void *ptr, char *where)
{
    if (ptr) return;
    g_error("Out of memory in %s\n", where);
}

void CLASS scale_colors_INDI(ushort (*image)[4], int maximum,
       const int black, const int use_auto_wb, const int use_camera_wb,
       const float cam_mul[4],
       const int height, const int width, const int colors,
       float pre_mul[4], const unsigned filters, /*const*/ ushort white[8][8],
       const char *ifname, void *dcraw)
{
  int row, col, x, y, c, val; // , shift=0; /*UF*/
  int min[4], max[4], sum[8];
  double dsum[8], dmin;

  maximum -= black; /* maximum is changed only locally */
  if (use_auto_wb || (use_camera_wb && cam_mul[0] == -1)) {
    FORC4 min[c] = INT_MAX;
    FORC4 max[c] = 0;
    memset (dsum, 0, sizeof dsum);
    for (row=0; row < height-7; row++)
      for (col=0; col < width-7; col++) {
       memset (sum, 0, sizeof sum);
       for (y=row; y < row+7; y++)
         for (x=col; x < col+7; x++)
           FORC4 {
             val = image[y*width+x][c];
             if (!val) continue;
             if (min[c] > val) min[c] = val;
             if (max[c] < val) max[c] = val;
             val -= black;
             if (val > maximum-25) goto skip_block;
             if (val < 0) val = 0;
             sum[c] += val;
             sum[c+4]++;
           }
       for (c=0; c < 8; c++) dsum[c] += sum[c];
skip_block:
       continue;
      }
    FORC4 if (dsum[c]) pre_mul[c] = dsum[c+4] / dsum[c];
  }
  if (use_camera_wb && cam_mul[0] != -1) {
    memset (sum, 0, sizeof sum);
    for (row=0; row < 8; row++)
      for (col=0; col < 8; col++) {
	c = FC(row,col);
	if ((val = white[row][col] - black) > 0)
	  sum[c] += val;
	sum[c+4]++;
      }
    if (sum[0] && sum[1] && sum[2] && sum[3])
      FORC4 pre_mul[c] = (float) sum[c+4] / sum[c];
    else if (cam_mul[0] && cam_mul[2])
      /* 'sizeof pre_mul' does not work because pre_mul is an argument (UF)*/
      memcpy (pre_mul, cam_mul, 4*sizeof(float));
    else
      dcraw_message (dcraw, DCRAW_NO_CAMERA_WB,
	      "%s: Cannot use camera white balance.\n", ifname);
  }
  if (pre_mul[3] == 0) pre_mul[3] = colors < 4 ? pre_mul[1] : 1;
  dmin = DBL_MAX;
  FORC4 if (dmin > pre_mul[c])
	    dmin = pre_mul[c];
  FORC4 pre_mul[c] /= dmin;

  dcraw_message(dcraw, DCRAW_VERBOSE, "Scaling with black=%d, pre_mul[] =",
	  black);
  FORC4 dcraw_message(dcraw, DCRAW_VERBOSE, " %f", pre_mul[c]);
  dcraw_message(dcraw, DCRAW_VERBOSE, "\n");
 
/* The rest of the scaling is done somewhere else UF*/
#if 0
  if (raw_color || !output_color) {
    pre_mul[0] *= red_scale;
    pre_mul[2] *= blue_scale;
  }
  while (maximum << shift < 0x8000) shift++;
  FORC4 pre_mul[c] *= 1 << shift;
  maximum <<= shift;

  if (write_fun != write_ppm || bright < 1) {
    maximum *= bright;
    if (maximum > 0xffff)
	maximum = 0xffff;
    FORC4 pre_mul[c] *= bright;
  }
  clip_max = clip_color ? maximum : 0xffff;
  for (row=0; row < height; row++)
    for (col=0; col < width; col++)
      FORC4 {
	val = image[row*width+col][c];
	if (!val) continue;
	val -= black;
	val *= pre_mul[c];
	image[row*width+col][c] = CLIP(val);
      }
  if (filters && colors == 3) {
    if (four_color_rgb) {
      colors++;
      FORC3 rgb_cam[c][3] = rgb_cam[c][1] /= 2;
    } else {
      for (row = FC(1,0) >> 1; row < height; row+=2)
        for (col = FC(row,1) & 1; col < width; col+=2)
          image[row*width+col][1] = image[row*width+col][3];
      filters &= ~((filters & 0x55555555) << 1);
    }
  }
#endif
}

void CLASS border_interpolate_INDI (const int height, const int width,
	ushort (*image)[4], const unsigned filters, int colors,
	int border)
{
  int row, col, y, x, f, c, sum[8];

  for (row=0; row < height; row++)
    for (col=0; col < width; col++) {
      if (col==border && row >= border && row < height-border)
	col = width-border;
      memset (sum, 0, sizeof sum);
      for (y=row-1; y != row+2; y++)
	for (x=col-1; x != col+2; x++)
	  if (y >= 0 && y < height && x >= 0 && x < width) {
	    f = fc_INDI(filters, y, x);
	    sum[f] += image[y*width + x][f];
	    sum[f+4]++;
	  }
      f = fc_INDI(filters,row,col);
      FORCC if (c != f && sum[c+4])
	image[row*width+col][c] = sum[c] / sum[c+4];
    }
}

void CLASS lin_interpolate_INDI(ushort (*image)[4], const unsigned filters,
        const int width, const int height, const int colors, void *dcraw) /*UF*/
{
  int code[16][16][32], *ip, sum[4];
  int c, i, x, y, row, col, shift, color;
  ushort *pix;

  dcraw_message (dcraw, DCRAW_VERBOSE, "Bilinear interpolation...\n"); /*UF*/

  border_interpolate_INDI (height, width, image, filters, colors, 1);
  for (row=0; row < 16; row++)
    for (col=0; col < 16; col++) {
      ip = code[row][col];
      memset (sum, 0, sizeof sum);
      for (y=-1; y <= 1; y++)
	for (x=-1; x <= 1; x++) {
	  shift = (y==0) + (x==0);
	  if (shift == 2) continue;
	  color = fc_INDI(filters,row+y,col+x);
	  *ip++ = (width*y + x)*4 + color;
	  *ip++ = shift;
	  *ip++ = color;
	  sum[color] += 1 << shift;
	}
      FORCC
	if (c != fc_INDI(filters,row,col)) {
	  *ip++ = c;
	  *ip++ = sum[c];
	}
    }
  for (row=1; row < height-1; row++)
    for (col=1; col < width-1; col++) {
      pix = image[row*width+col];
      ip = code[row & 15][col & 15];
      memset (sum, 0, sizeof sum);
      for (i=8; i--; ip+=3)
	sum[ip[2]] += pix[ip[0]] << ip[1];
      for (i=colors; --i; ip+=2)
	pix[ip[0]] = sum[ip[0]] / ip[1];
    }
}

/*
   This algorithm is officially called:

   "Interpolation using a Threshold-based variable number of gradients"

   described in http://www-ise.stanford.edu/~tingchen/algodep/vargra.html

   I've extended the basic idea to work with non-Bayer filter arrays.
   Gradients are numbered clockwise from NW=0 to W=7.
 */
void CLASS vng_interpolate_INDI(ushort (*image)[4], const unsigned filters,
        const int width, const int height, const int colors, void *dcraw) /*UF*/
{
  static const signed char *cp, terms[] = {
    -2,-2,+0,-1,0,0x01, -2,-2,+0,+0,1,0x01, -2,-1,-1,+0,0,0x01,
    -2,-1,+0,-1,0,0x02, -2,-1,+0,+0,0,0x03, -2,-1,+0,+1,1,0x01,
    -2,+0,+0,-1,0,0x06, -2,+0,+0,+0,1,0x02, -2,+0,+0,+1,0,0x03,
    -2,+1,-1,+0,0,0x04, -2,+1,+0,-1,1,0x04, -2,+1,+0,+0,0,0x06,
    -2,+1,+0,+1,0,0x02, -2,+2,+0,+0,1,0x04, -2,+2,+0,+1,0,0x04,
    -1,-2,-1,+0,0,0x80, -1,-2,+0,-1,0,0x01, -1,-2,+1,-1,0,0x01,
    -1,-2,+1,+0,1,0x01, -1,-1,-1,+1,0,0x88, -1,-1,+1,-2,0,0x40,
    -1,-1,+1,-1,0,0x22, -1,-1,+1,+0,0,0x33, -1,-1,+1,+1,1,0x11,
    -1,+0,-1,+2,0,0x08, -1,+0,+0,-1,0,0x44, -1,+0,+0,+1,0,0x11,
    -1,+0,+1,-2,1,0x40, -1,+0,+1,-1,0,0x66, -1,+0,+1,+0,1,0x22,
    -1,+0,+1,+1,0,0x33, -1,+0,+1,+2,1,0x10, -1,+1,+1,-1,1,0x44,
    -1,+1,+1,+0,0,0x66, -1,+1,+1,+1,0,0x22, -1,+1,+1,+2,0,0x10,
    -1,+2,+0,+1,0,0x04, -1,+2,+1,+0,1,0x04, -1,+2,+1,+1,0,0x04,
    +0,-2,+0,+0,1,0x80, +0,-1,+0,+1,1,0x88, +0,-1,+1,-2,0,0x40,
    +0,-1,+1,+0,0,0x11, +0,-1,+2,-2,0,0x40, +0,-1,+2,-1,0,0x20,
    +0,-1,+2,+0,0,0x30, +0,-1,+2,+1,1,0x10, +0,+0,+0,+2,1,0x08,
    +0,+0,+2,-2,1,0x40, +0,+0,+2,-1,0,0x60, +0,+0,+2,+0,1,0x20,
    +0,+0,+2,+1,0,0x30, +0,+0,+2,+2,1,0x10, +0,+1,+1,+0,0,0x44,
    +0,+1,+1,+2,0,0x10, +0,+1,+2,-1,1,0x40, +0,+1,+2,+0,0,0x60,
    +0,+1,+2,+1,0,0x20, +0,+1,+2,+2,0,0x10, +1,-2,+1,+0,0,0x80,
    +1,-1,+1,+1,0,0x88, +1,+0,+1,+2,0,0x08, +1,+0,+2,-1,0,0x40,
    +1,+0,+2,+1,0,0x10
  }, chood[] = { -1,-1, -1,0, -1,+1, 0,+1, +1,+1, +1,0, +1,-1, 0,-1 };
  ushort (*brow[5])[4], *pix;
  int prow=7, pcol=1, *ip, *code[16][16], gval[8], gmin, gmax, sum[4];
  int row, col, x, y, x1, x2, y1, y2, t, weight, grads, color, diag;
  int g, diff, thold, num, c;
      
  lin_interpolate_INDI(image, filters, width, height, colors, dcraw); /*UF*/
  dcraw_message (dcraw, DCRAW_VERBOSE, "VNG interpolation...\n"); /*UF*/

  if (filters == 1) prow = pcol = 15;
  ip = (int *) calloc ((prow+1)*(pcol+1), 1280);
  merror (ip, "vng_interpolate()");
  for (row=0; row <= prow; row++)               /* Precalculate for VNG */
    for (col=0; col <= pcol; col++) {
      code[row][col] = ip;
      for (cp=terms, t=0; t < 64; t++) {
	y1 = *cp++;  x1 = *cp++;
	y2 = *cp++;  x2 = *cp++;
	weight = *cp++;
	grads = *cp++;
	color = fc_INDI(filters,row+y1,col+x1);
	if (fc_INDI(filters,row+y2,col+x2) != color) continue;
	diag = (fc_INDI(filters,row,col+1) == color && fc_INDI(filters,row+1,col) == color) ? 2:1;
	if (abs(y1-y2) == diag && abs(x1-x2) == diag) continue;
	*ip++ = (y1*width + x1)*4 + color;
	*ip++ = (y2*width + x2)*4 + color;
	*ip++ = weight;
	for (g=0; g < 8; g++)
	  if (grads & 1<<g) *ip++ = g;
	*ip++ = -1;
      }
      *ip++ = INT_MAX;
      for (cp=chood, g=0; g < 8; g++) {
	y = *cp++;  x = *cp++;
	*ip++ = (y*width + x) * 4;
	color = fc_INDI(filters,row,col);
	if (fc_INDI(filters,row+y,col+x) != color && fc_INDI(filters,row+y*2,col+x*2) == color)
	  *ip++ = (y*width + x) * 8 + color;
	else
	  *ip++ = 0;
      }
    }
  brow[4] = (ushort (*)[4]) calloc (width*3, sizeof **brow);
  merror (brow[4], "vng_interpolate()");
  for (row=0; row < 3; row++)
    brow[row] = brow[4] + row*width;
  for (row=2; row < height-2; row++) {		/* Do VNG interpolation */
    for (col=2; col < width-2; col++) {
      pix = image[row*width+col];
      ip = code[row & prow][col & pcol];
      memset (gval, 0, sizeof gval);
      while ((g = ip[0]) != INT_MAX) {		/* Calculate gradients */
	diff = ABS(pix[g] - pix[ip[1]]) << ip[2];
	gval[ip[3]] += diff;
	ip += 5;
	if ((g = ip[-1]) == -1) continue;
	gval[g] += diff;
	while ((g = *ip++) != -1)
	  gval[g] += diff;
      }
      ip++;
      gmin = gmax = gval[0];			/* Choose a threshold */
      for (g=1; g < 8; g++) {
	if (gmin > gval[g]) gmin = gval[g];
	if (gmax < gval[g]) gmax = gval[g];
      }
      if (gmax == 0) {
	memcpy (brow[2][col], pix, sizeof *image);
	continue;
      }
      thold = gmin + (gmax >> 1);
      memset (sum, 0, sizeof sum);
      color = fc_INDI(filters,row,col);
      for (num=g=0; g < 8; g++,ip+=2) {		/* Average the neighbors */
	if (gval[g] <= thold) {
	  FORCC
	    if (c == color && ip[1])
	      sum[c] += (pix[c] + pix[ip[1]]) >> 1;
	    else
	      sum[c] += pix[ip[0] + c];
	  num++;
	}
      }
      FORCC {					/* Save to buffer */
	t = pix[color];
	if (c != color)
	  t += (sum[c] - sum[color]) / num;
	brow[2][col][c] = CLIP(t);
      }
    }
    if (row > 3)				/* Write buffer to image */
      memcpy (image[(row-2)*width+2], brow[0]+2, (width-4)*sizeof *image);
    for (g=0; g < 4; g++)
      brow[(g-1) & 3] = brow[g];
  }
  memcpy (image[(row-2)*width+2], brow[0]+2, (width-4)*sizeof *image);
  memcpy (image[(row-1)*width+2], brow[1]+2, (width-4)*sizeof *image);
  free (brow[4]);
}

void CLASS cam_to_cielab_INDI (ushort cam[4], float lab[3],
	const int colors, const float rgb_cam[3][4])
{
  int c, i, j, k;
  float r, xyz[3];
  static float cbrt[0x10000], xyz_cam[3][4];

  if (cam == NULL) {
    for (i=0; i < 0x10000; i++) {
      r = (float) i / 65535.0;
      cbrt[i] = r > 0.008856 ? pow(r,1/3.0) : 7.787*r + 16/116.0;
    }
    for (i=0; i < 3; i++)
      for (j=0; j < colors; j++)
        for (xyz_cam[i][j] = k=0; k < 3; k++)
	  xyz_cam[i][j] += xyz_rgb[i][k] * rgb_cam[k][j] / d65_white[i];
  } else {
    for (i=0; i < 3; i++) {
      for (xyz[i]=0.5, c=0; c < colors; c++)
	xyz[i] += xyz_cam[i][c] * cam[c];
      xyz[i] = cbrt[CLIP((int) xyz[i])];
    }
    lab[0] = 116 * xyz[1] - 16;
    lab[1] = 500 * (xyz[0] - xyz[1]);
    lab[2] = 200 * (xyz[1] - xyz[2]);
  }
}

/*
   Adaptive Homogeneity-Directed interpolation is based on
   the work of Keigo Hirakawa, Thomas Parks, and Paul Lee.
 */
#define TS 256		/* Tile Size */

void CLASS ahd_interpolate_INDI(ushort (*image)[4], const unsigned filters,
        const int width, const int height, const int colors,
       	const float rgb_cam[3][4], void *dcraw)
{
  int i, j, top, left, row, col, tr, tc, fc, c, d, val, hm[2];
  ushort (*pix)[4], (*rix)[3];
  static const int dir[4] = { -1, 1, -TS, TS };
  unsigned ldiff[2][4], abdiff[2][4], leps, abeps;
  float flab[3];
  ushort (*rgb)[TS][TS][3];
   short (*lab)[TS][TS][3];
   char (*homo)[TS][TS], *buffer;

  dcraw_message (dcraw, DCRAW_VERBOSE, "AHD interpolation...\n"); /*UF*/

  border_interpolate_INDI (height, width, image, filters, colors, 3);
  buffer = (char *) malloc (26*TS*TS);		/* 1664 kB */
  merror (buffer, "ahd_interpolate()");
  rgb  = (ushort(*)[TS][TS][3]) buffer;
  lab  = (short (*)[TS][TS][3])(buffer + 12*TS*TS);
  homo = (char  (*)[TS][TS])   (buffer + 24*TS*TS);

  for (top=0; top < height; top += TS-6)
    for (left=0; left < width; left += TS-6) {
      memset (rgb, 0, 12*TS*TS);

/*  Interpolate green horizontally and vertically:		*/
      for (row = top < 2 ? 2:top; row < top+TS && row < height-2; row++) {
	col = left + (FC(row,left) == 1);
	if (col < 2) col += 2;
	for (fc = FC(row,col); col < left+TS && col < width-2; col+=2) {
	  pix = image + row*width+col;
	  val = ((pix[-1][1] + pix[0][fc] + pix[1][1]) * 2
		- pix[-2][fc] - pix[2][fc]) >> 2;
	  rgb[0][row-top][col-left][1] = ULIM(val,pix[-1][1],pix[1][1]);
	  val = ((pix[-width][1] + pix[0][fc] + pix[width][1]) * 2
		- pix[-2*width][fc] - pix[2*width][fc]) >> 2;
	  rgb[1][row-top][col-left][1] = ULIM(val,pix[-width][1],pix[width][1]);
	}
      }
/*  Interpolate red and blue, and convert to CIELab:		*/
      for (d=0; d < 2; d++)
	for (row=top+1; row < top+TS-1 && row < height-1; row++)
	  for (col=left+1; col < left+TS-1 && col < width-1; col++) {
	    pix = image + row*width+col;
	    rix = &rgb[d][row-top][col-left];
	    if ((c = 2 - FC(row,col)) == 1) {
	      c = FC(row+1,col);
	      val = pix[0][1] + (( pix[-1][2-c] + pix[1][2-c]
				 - rix[-1][1] - rix[1][1] ) >> 1);
	      rix[0][2-c] = CLIP(val);
	      val = pix[0][1] + (( pix[-width][c] + pix[width][c]
				 - rix[-TS][1] - rix[TS][1] ) >> 1);
	    } else
	      val = rix[0][1] + (( pix[-width-1][c] + pix[-width+1][c]
				 + pix[+width-1][c] + pix[+width+1][c]
				 - rix[-TS-1][1] - rix[-TS+1][1]
				 - rix[+TS-1][1] - rix[+TS+1][1] + 1) >> 2);
	    rix[0][c] = CLIP(val);
	    c = FC(row,col);
	    rix[0][c] = pix[0][c];
	    cam_to_cielab_INDI (rix[0], flab, colors, rgb_cam);
	    FORC3 lab[d][row-top][col-left][c] = 64*flab[c];
	  }
/*  Build homogeneity maps from the CIELab images:		*/
      memset (homo, 0, 2*TS*TS);
      for (row=top+2; row < top+TS-2 && row < height; row++) {
	tr = row-top;
	for (col=left+2; col < left+TS-2 && col < width; col++) {
	  tc = col-left;
	  for (d=0; d < 2; d++)
	    for (i=0; i < 4; i++)
	      ldiff[d][i] = ABS(lab[d][tr][tc][0]-lab[d][tr][tc+dir[i]][0]);
	  leps = MIN(MAX(ldiff[0][0],ldiff[0][1]),
		     MAX(ldiff[1][2],ldiff[1][3]));
	  for (d=0; d < 2; d++)
	    for (i=0; i < 4; i++)
	      if (i >> 1 == d || ldiff[d][i] <= leps)
		abdiff[d][i] = SQR(lab[d][tr][tc][1]-lab[d][tr][tc+dir[i]][1])
			     + SQR(lab[d][tr][tc][2]-lab[d][tr][tc+dir[i]][2]);
	  abeps = MIN(MAX(abdiff[0][0],abdiff[0][1]),
		      MAX(abdiff[1][2],abdiff[1][3]));
	  for (d=0; d < 2; d++)
	    for (i=0; i < 4; i++)
	      if (ldiff[d][i] <= leps && abdiff[d][i] <= abeps)
		homo[d][tr][tc]++;
	}
      }
/*  Combine the most homogenous pixels for the final result:	*/
      for (row=top+3; row < top+TS-3 && row < height-3; row++) {
	tr = row-top;
	for (col=left+3; col < left+TS-3 && col < width-3; col++) {
	  tc = col-left;
	  for (d=0; d < 2; d++)
	    for (hm[d]=0, i=tr-1; i <= tr+1; i++)
	      for (j=tc-1; j <= tc+1; j++)
		hm[d] += homo[d][i][j];
	  if (hm[0] != hm[1])
	    FORC3 image[row*width+col][c] = rgb[hm[1] > hm[0]][tr][tc][c];
	  else
	    FORC3 image[row*width+col][c] =
		(rgb[0][tr][tc][c] + rgb[1][tr][tc][c]) >> 1;
	}
      }
    }
  free (buffer);
}
#undef TS

void CLASS fuji_rotate_INDI(ushort (**image_p)[4], int *height_p,
    int *width_p, int *fuji_width_p, const int colors, const double step,
    void *dcraw)
{
  int height = *height_p, width = *width_p, fuji_width = *fuji_width_p; /*UF*/
  ushort (*image)[4] = *image_p; /*UF*/
  int i, wide, high, row, col;
//  double step;
  float r, c, fr, fc;
  int ur, uc;
  ushort (*img)[4], (*pix)[4];

  if (!fuji_width) return;
  dcraw_message (dcraw, DCRAW_VERBOSE, "Rotating image 45 degrees...\n");
//  fuji_width = (fuji_width - 1 + shrink) >> shrink;
//  step = sqrt(0.5);
  wide = fuji_width / step;
  high = (height - fuji_width) / step;
  img = (ushort (*)[4]) calloc (wide*high, sizeof *img);
  merror (img, "fuji_rotate()");

  for (row=0; row < high; row++)
    for (col=0; col < wide; col++) {
      ur = r = fuji_width + (row-col)*step;
      uc = c = (row+col)*step;
      if (ur > height-2 || uc > width-2) continue;
      fr = r - ur;
      fc = c - uc;
      pix = image + ur*width + uc;
      for (i=0; i < colors; i++)
	img[row*wide+col][i] =
	  (pix[    0][i]*(1-fc) + pix[      1][i]*fc) * (1-fr) +
	  (pix[width][i]*(1-fc) + pix[width+1][i]*fc) * fr;
    }
  free (image);
  width  = wide;
  height = high;
  image  = img;
  fuji_width = 0;
  *height_p = height; /* INDI - UF*/
  *width_p = width;
  *fuji_width_p = fuji_width;
  *image_p = image;
}

void CLASS flip_image_INDI(ushort (*image)[4], int *height_p, int *width_p,
    /*const*/ int flip) /*UF*/
{
  unsigned *flag;
  int size, base, dest, next, row, col;
  INT64 *img, hold;
  int height = *height_p, width = *width_p;/* INDI - UF*/

//  Message is suppressed because error handling is not enabled here.
//  dcraw_message (dcraw, DCRAW_VERBOSE, "Flipping image %c:%c:%c...\n",
//	flip & 1 ? 'H':'0', flip & 2 ? 'V':'0', flip & 4 ? 'T':'0'); /*UF*/
  
  img = (INT64 *) image;
  size = height * width;
  flag = calloc ((size+31) >> 5, sizeof *flag);
  merror (flag, "flip_image()");
  for (base = 0; base < size; base++) {
    if (flag[base >> 5] & (1 << (base & 31)))
      continue;
    dest = base;
    hold = img[base];
    while (1) {
      if (flip & 4) {
	row = dest % height;
	col = dest / height;
      } else {
	row = dest / width;
	col = dest % width;
      }
      if (flip & 2)
	row = height - 1 - row;
      if (flip & 1)
	col = width - 1 - col;
      next = row * width + col;
      if (next == base) break;
      flag[next >> 5] |= 1 << (next & 31);
      img[dest] = img[next];
      dest = next;
    }
    img[dest] = hold;
  }
  free (flag);
  if (flip & 4) {
    SWAP (height, width);
//  SWAP (ymag, xmag); /* We always stretch before we flip - UF*/
  }
  *height_p = height; /* INDI - UF*/
  *width_p = width;
}