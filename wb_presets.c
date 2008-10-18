/*
 * UFRaw - Unidentified Flying Raw converter for digital camera images
 *
 * wb_presets.c - White balance preset values for various cameras
 * Copyright 2004-2008 by Udi Fuchs
 *
 * Thanks goes for all the people who sent in the preset values
 * for their cameras.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <glib.h>
#include <glib/gi18n.h>
#include "ufraw.h"

/* Column 1 - "make" of the camera.
 * Column 2 - "model" (use the "make" and "model" as provided by DCRaw).
 * Column 3 - WB name.
 * Column 4 - Fine tuning. MUST be in increasing order. 0 for no fine tuning.
 *	      It is enough to give only the extreme values, the other values
 *	      will be interpolated.
 * Column 5 - Channel multipliers.
 *
 * Minolta's ALPHA and MAXXUM models are treated as the DYNAX model.
 *
 * WB name is standardized to one of the following: */
// "Sunlight" and other variation should be switched to this:
static const char Daylight[] = N_("Daylight");
// Probably same as above:
static const char DirectSunlight[] = N_("Direct sunlight");
static const char Cloudy[] = N_("Cloudy");
// "Shadows" should be switched to this:
static const char Shade[] = N_("Shade");
static const char Incandescent[] = N_("Incandescent");
static const char IncandescentWarm[] = N_("Incandescent warm");
// Same as "Incandescent":
static const char Tungsten[] = N_("Tungsten");
static const char Fluorescent[] = N_("Fluorescent");
// In Canon cameras and Nikon D60 and D300:
static const char FluorescentHigh[] = N_("Fluorescent high");
static const char CoolWhiteFluorescent[] = N_("Cool white fluorescent");
static const char WarmWhiteFluorescent[] = N_("Warm white fluorescent");
static const char DaylightFluorescent[] = N_("Daylight fluorescent");
static const char NeutralFluorescent[] = N_("Neutral fluorescent");
static const char WhiteFluorescent[] = N_("White fluorescent");
// In Nikon D60 and D300
static const char SodiumVaporFluorescent[] = N_("Sodium-vapor fluorescent");
static const char DayWhiteFluorescent[] = N_("Day white fluorescent");
static const char HighTempMercuryVaporFluorescent[] = N_("High temp. mercury-vapor fluorescent");

static const char Flash[] = N_("Flash");
// For Olympus with no real "Flash" preset:
static const char FlashAuto[] = N_("Flash (auto mode)");
static const char EveningSun[] = N_("Evening sun");
static const char Underwater[] = N_("Underwater");
static const char BlackNWhite[] = N_("Black & white");

const wb_data wb_preset[] = {

  { "", "", N_("Manual WB"), 0,	{ 0, 0, 0, 0 } },
  { "", "", N_("Camera WB"), 0,	{ 0, 0, 0, 0 } },
  { "", "", N_("Auto WB"), 0,	{ 0, 0, 0, 0 } },

  { "Canon", "PowerShot A630", Daylight, 0,	{ 1.831422, 1, 1.245671, 0 } },
  { "Canon", "PowerShot A630", Cloudy, 0,	{ 1.669924, 1, 1.326299, 0 } },
  { "Canon", "PowerShot A630", Tungsten, 0,	{ 1.696768, 1, 1.268658, 0 } },
  { "Canon", "PowerShot A630", Fluorescent, 0,	{ 1.869859, 1, 1.209110, 0 } },
  { "Canon", "PowerShot A630", FluorescentHigh, 0, { 1.855491, 1, 1.206855, 0 } },

  { "Canon", "PowerShot G2", Daylight, 0,	{ 2.011483, 1, 1.299522, 0 } },
  { "Canon", "PowerShot G2", Cloudy, 0,		{ 2.032505, 1, 1.285851, 0 } },
  { "Canon", "PowerShot G2", Tungsten, 0,	{ 1.976008, 1, 1.332054, 0 } },
  { "Canon", "PowerShot G2", Fluorescent, 0,	{ 2.022010, 1, 1.295694, 0 } },
  { "Canon", "PowerShot G2", FluorescentHigh, 0, { 2.029637, 1, 1.286807, 0 } },
  { "Canon", "PowerShot G2", Flash, 0,		{ 2.153576, 1, 1.140680, 0 } },

  { "Canon", "PowerShot G3", Daylight, 0,	{ 1.858513, 1, 1.387290, 0 } },
  { "Canon", "PowerShot G3", Cloudy, 0,		{ 1.951132, 1, 1.305125, 0 } },
  { "Canon", "PowerShot G3", Tungsten, 0,	{ 1.128386, 1, 2.313310, 0 } },
  { "Canon", "PowerShot G3", Fluorescent, 0,	{ 1.715573, 1, 2.194337, 0 } },
  { "Canon", "PowerShot G3", FluorescentHigh, 0, { 2.580563, 1, 1.496164, 0 } },
  { "Canon", "PowerShot G3", Flash, 0,		{ 2.293173, 1, 1.187416, 0 } },

  { "Canon", "PowerShot G5", Daylight, 0,	{ 1.639521, 1, 1.528144, 0 } },
  { "Canon", "PowerShot G5", Cloudy, 0,		{ 1.702153, 1, 1.462919, 0 } },
  { "Canon", "PowerShot G5", Tungsten, 0,	{ 1.135071, 1, 2.374408, 0 } },
  { "Canon", "PowerShot G5", Fluorescent, 0,	{ 1.660281, 1, 2.186462, 0 } },
  { "Canon", "PowerShot G5", FluorescentHigh, 0, { 1.463297, 1, 1.764140, 0 } },
  { "Canon", "PowerShot G5", Flash, 0,		{ 1.603593, 1, 1.562874, 0 } },

  { "Canon", "PowerShot G6", Daylight, 0,	{ 1.769704, 1, 1.637931, 0 } },
  { "Canon", "PowerShot G6", Cloudy, 0,		{ 2.062731, 1, 1.442804, 0 } },
  { "Canon", "PowerShot G6", Tungsten, 0,	{ 1.077106, 1, 2.721234, 0 } },
  { "Canon", "PowerShot G6", Fluorescent, 0,	{ 1.914922, 1, 2.142670, 0 } },
  { "Canon", "PowerShot G6", FluorescentHigh, 0, { 2.543677, 1, 1.650587, 0 } },
  { "Canon", "PowerShot G6", Flash, 0,		{ 2.285322, 1, 1.333333, 0 } },

  { "Canon", "PowerShot G9", Daylight, 0,	{ 2.089552, 1, 1.786452, 0 } },
  { "Canon", "PowerShot G9", Cloudy, 0,		{ 2.208716, 1, 1.660550, 0 } },
  { "Canon", "PowerShot G9", Tungsten, 0,	{ 1.533493, 1, 2.586124, 0 } },
  { "Canon", "PowerShot G9", Fluorescent, 0,	{ 2.065668, 1, 1.829493, 0 } },
  { "Canon", "PowerShot G9", FluorescentHigh, 0, { 2.237601, 1, 1.668974, 0 } },
  { "Canon", "PowerShot G9", Flash, 0,		{ 2.461538, 1, 1.498834, 0 } },
  { "Canon", "PowerShot G9", Underwater, 0,	{ 2.237327, 1, 1.661290, 0 } },

  /* Canon PowerShot S3 IS does not support native WB presets. These are made
     as custom WB presets. */
  { "Canon", "PowerShot S3 IS", Daylight, 0,	{ 1.627271, 1, 1.823491, 0 } },
  { "Canon", "PowerShot S3 IS", Cloudy, 0,	{ 1.794382, 1, 1.618412, 0 } },
  { "Canon", "PowerShot S3 IS", Tungsten, 0,	{ 1, 1.192243, 4.546950, 0 } },
  { "Canon", "PowerShot S3 IS", Flash, 0,	{ 1.884691, 1, 1.553869, 0 } },

  { "Canon", "PowerShot S30", Daylight, 0,	{ 1.741088, 1, 1.318949, 0 } },
  { "Canon", "PowerShot S30", Cloudy, 0,	{ 1.766635, 1, 1.298969, 0 } },
  { "Canon", "PowerShot S30", Tungsten, 0,	{ 1.498106, 1, 1.576705, 0 } },
  { "Canon", "PowerShot S30", Fluorescent, 0,	{ 1.660075, 1, 1.394539, 0 } },
  { "Canon", "PowerShot S30", FluorescentHigh, 0, { 1.753515, 1, 1.306467, 0 } },
  { "Canon", "PowerShot S30", Flash, 0,		{ 2.141705, 1, 1.097926, 0 } },

  { "Canon", "PowerShot S45", Daylight, 0,	{ 2.325175, 1, 1.080420, 0 } },
  { "Canon", "PowerShot S45", Cloudy, 0,	{ 2.145047, 1, 1.173349, 0 } },
  { "Canon", "PowerShot S45", Tungsten, 0,	{ 1.213018, 1, 2.087574, 0 } },
  { "Canon", "PowerShot S45", Fluorescent, 0,	{ 1.888183, 1, 1.822109, 0 } },
  { "Canon", "PowerShot S45", FluorescentHigh, 0, { 2.964422, 1, 1.354511, 0 } },
  { "Canon", "PowerShot S45", Flash, 0,		{ 2.534884, 1, 1.065663, 0 } },

  { "Canon", "PowerShot S50", Daylight, 0,	{ 1.772506, 1, 1.536496, 0 } },
  { "Canon", "PowerShot S50", Cloudy, 0,	{ 1.831311, 1, 1.484223, 0 } },
  { "Canon", "PowerShot S50", Tungsten, 0,	{ 1.185542, 1, 2.480723, 0 } },
  { "Canon", "PowerShot S50", Fluorescent, 0,	{ 1.706410, 1, 2.160256, 0 } },
  { "Canon", "PowerShot S50", FluorescentHigh, 0, { 1.562500, 1, 1.817402, 0 } },
  { "Canon", "PowerShot S50", Flash, 0,		{ 1.776156, 1, 1.531630, 0 } },

  { "Canon", "PowerShot S60", Daylight, 0,	{ 1.759169, 1, 1.590465, 0 } },
  { "Canon", "PowerShot S60", Cloudy, 0,	{ 1.903659, 1, 1.467073, 0 } },
  { "Canon", "PowerShot S60", Tungsten, 0,	{ 1.138554, 1, 2.704819, 0 } },
  { "Canon", "PowerShot S60", Fluorescent, 0,	{ 1.720721, 1, 2.185328, 0 } },
  { "Canon", "PowerShot S60", FluorescentHigh, 0, { 2.877095, 1, 2.216480, 0 } },
  { "Canon", "PowerShot S60", Flash, 0,		{ 2.182540, 1, 1.236773, 0 } },
  { "Canon", "PowerShot S60", Underwater, 0,	{ 2.725369, 1, 1.240148, 0 } },

  { "Canon", "PowerShot S70", Daylight, 0,	{ 1.943834, 1, 1.456654, 0 } },
  { "Canon", "PowerShot S70", Cloudy, 0,	{ 2.049939, 1, 1.382460, 0 } },
  { "Canon", "PowerShot S70", Tungsten, 0,	{ 1.169492, 1, 2.654964, 0 } },
  { "Canon", "PowerShot S70", Fluorescent, 0,	{ 1.993456, 1, 2.056283, 0 } },
  { "Canon", "PowerShot S70", FluorescentHigh, 0, { 2.645914, 1, 1.565499, 0 } },
  { "Canon", "PowerShot S70", Flash, 0,		{ 2.389189, 1, 1.147297, 0 } },
  { "Canon", "PowerShot S70", Underwater, 0,	{ 3.110565, 1, 1.162162, 0 } },

  { "Canon", "PowerShot Pro1", Daylight, 0,	{ 1.829238, 1, 1.571253, 0 } },
  { "Canon", "PowerShot Pro1", Cloudy, 0,	{ 1.194139, 1, 2.755800, 0 } },
  { "Canon", "PowerShot Pro1", Tungsten, 0,	{ 1.701416, 1, 2.218790, 0 } },
  { "Canon", "PowerShot Pro1", Fluorescent, 0,	{ 2.014066, 1, 1.776215, 0 } },
  { "Canon", "PowerShot Pro1", FluorescentHigh, 0, { 2.248663, 1, 1.227273, 0 } },
  { "Canon", "PowerShot Pro1", Flash, 0,	{ 2.130081, 1, 1.422764, 0 } },

  { "Canon", "EOS D60", Daylight, 0,		{ 2.472594, 1, 1.225335, 0 } },
  { "Canon", "EOS D60", Cloudy, 0,		{ 2.723926, 1, 1.137423, 0 } },
  { "Canon", "EOS D60", Tungsten, 0,		{ 1.543054, 1, 1.907003, 0 } },
  { "Canon", "EOS D60", Fluorescent, 0,		{ 1.957346, 1, 1.662322, 0 } },
  { "Canon", "EOS D60", Flash, 0,		{ 2.829840, 1, 1.108508, 0 } },

  { "Canon", "EOS 5D", Flash, 0,		{ 2.211914, 1, 1.260742, 0 } }, /*6550K*/
  { "Canon", "EOS 5D", Fluorescent, 0,		{ 1.726054, 1, 2.088123, 0 } }, /*3850K*/
  { "Canon", "EOS 5D", Tungsten, 0,		{ 1.373285, 1, 2.301006, 0 } }, /*3250K*/
  { "Canon", "EOS 5D", Cloudy, 0,		{ 2.151367, 1, 1.321289, 0 } }, /*6100K*/
  { "Canon", "EOS 5D", Shade, 0,		{ 2.300781, 1, 1.208008, 0 } }, /*7200K*/
  { "Canon", "EOS 5D", Daylight, 0,		{ 1.988281, 1, 1.457031, 0 } }, /*5250K*/

  { "Canon", "EOS 10D", Daylight, 0,		{ 2.159856, 1, 1.218750, 0 } },
  { "Canon", "EOS 10D", Shade, 0,		{ 2.533654, 1, 1.036058, 0 } },
  { "Canon", "EOS 10D", Cloudy, 0,		{ 2.348558, 1, 1.116587, 0 } },
  { "Canon", "EOS 10D", Tungsten, 0,		{ 1.431544, 1, 1.851040, 0 } },
  { "Canon", "EOS 10D", Fluorescent, 0,		{ 1.891509, 1, 1.647406, 0 } },
  { "Canon", "EOS 10D", Flash, 0,		{ 2.385817, 1, 1.115385, 0 } },

  { "Canon", "EOS 20D", Daylight, 0,		{ 1.954680, 1, 1.478818, 0 } },
  { "Canon", "EOS 20D", Shade, 0,		{ 2.248276, 1, 1.227586, 0 } },
  { "Canon", "EOS 20D", Cloudy, 0,		{ 2.115271, 1, 1.336946, 0 } },
  { "Canon", "EOS 20D", Tungsten, 0,		{ 1.368087, 1, 2.417044, 0 } },
  { "Canon", "EOS 20D", Fluorescent, 0,		{ 1.752709, 1, 2.060098, 0 } },
  { "Canon", "EOS 20D", Flash, 0,		{ 2.145813, 1, 1.293596, 0 } },

  { "Canon", "EOS 30D", DirectSunlight, 0,	{ 1.920898, 1, 1.514648, 0 } },
  { "Canon", "EOS 30D", Shade, 0,		{ 2.211914, 1, 1.251953, 0 } },
  { "Canon", "EOS 30D", Cloudy, 0,		{ 2.073242, 1, 1.373047, 0 } },
  { "Canon", "EOS 30D", Tungsten, 0,		{ 1.340369, 1, 2.383465, 0 } },
  { "Canon", "EOS 30D", Fluorescent, 0,		{ 1.684063, 1, 2.245107, 0 } },
  { "Canon", "EOS 30D", Flash, 0,		{ 2.093750, 1, 1.330078, 0 } },

  { "Canon", "EOS 40D", Daylight, 0,		{ 2.197266, 1, 1.438477, 0 } },
  { "Canon", "EOS 40D", Shade, 0,		{ 2.546875, 1, 1.185547, 0 } },
  { "Canon", "EOS 40D", Cloudy, 0,		{ 2.370117, 1, 1.290039, 0 } },
  { "Canon", "EOS 40D", Tungsten, 0,		{ 1.510563, 1, 2.235915, 0 } },
  { "Canon", "EOS 40D", Fluorescent, 0,		{ 2.019084, 1, 2.129771, 0 } },
  { "Canon", "EOS 40D", Flash, 0,		{ 2.409180, 1, 1.260742, 0 } },

  { "Canon", "EOS 300D DIGITAL", Daylight, 0,	{ 2.072115, 1, 1.217548, 0 } },
  { "Canon", "EOS 300D DIGITAL", Shade, 0,	{ 2.455529, 1, 1.026442, 0 } },
  { "Canon", "EOS 300D DIGITAL", Cloudy, 0,	{ 2.254808, 1, 1.108173, 0 } },
  { "Canon", "EOS 300D DIGITAL", Tungsten, 0,	{ 1.349057, 1, 1.896226, 0 } },
  { "Canon", "EOS 300D DIGITAL", Fluorescent, 0, { 1.794664, 1, 1.711137, 0 } },
  { "Canon", "EOS 300D DIGITAL", Flash, 0,	{ 2.326923, 1, 1.098558, 0 } },

  { "Canon", "EOS DIGITAL REBEL", Daylight, 0,	{ 2.072115, 1, 1.217548, 0 } },
  { "Canon", "EOS DIGITAL REBEL", Shade, 0,	{ 2.455529, 1, 1.026442, 0 } },
  { "Canon", "EOS DIGITAL REBEL", Cloudy, 0,	{ 2.254808, 1, 1.108173, 0 } },
  { "Canon", "EOS DIGITAL REBEL", Tungsten, 0,	{ 1.349057, 1, 1.896226, 0 } },
  { "Canon", "EOS DIGITAL REBEL", Fluorescent, 0, { 1.794664, 1, 1.711137, 0 } },
  { "Canon", "EOS DIGITAL REBEL", Flash, 0,	{ 2.326923, 1, 1.098558, 0 } },

  { "Canon", "EOS Kiss Digital", Daylight, 0,	{ 2.072115, 1, 1.217548, 0 } },
  { "Canon", "EOS Kiss Digital", Shade, 0,	{ 2.455529, 1, 1.026442, 0 } },
  { "Canon", "EOS Kiss Digital", Cloudy, 0,	{ 2.254808, 1, 1.108173, 0 } },
  { "Canon", "EOS Kiss Digital", Tungsten, 0,	{ 1.349057, 1, 1.896226, 0 } },
  { "Canon", "EOS Kiss Digital", Fluorescent, 0, { 1.794664, 1, 1.711137, 0 } },
  { "Canon", "EOS Kiss Digital", Flash, 0,	{ 2.326923, 1, 1.098558, 0 } },

  { "Canon", "EOS 350D DIGITAL", Tungsten, 0,	{ 1.451524, 1, 2.333333, 0 } },
  { "Canon", "EOS 350D DIGITAL", Daylight, 0,	{ 2.202756, 1, 1.488189, 0 } },
  { "Canon", "EOS 350D DIGITAL", Fluorescent, 0, { 1.846004, 1, 1.987329, 0 } },
  { "Canon", "EOS 350D DIGITAL", Shade, 0,	{ 2.617126, 1, 1.235236, 0 } },
  { "Canon", "EOS 350D DIGITAL", Flash, 0,	{ 2.508858, 1, 1.297244, 0 } },
  { "Canon", "EOS 350D DIGITAL", Cloudy, 0,	{ 2.409449, 1, 1.344488, 0 } },

  { "Canon", "EOS DIGITAL REBEL XT", Tungsten, 0, { 1.451524, 1, 2.333333, 0 } },
  { "Canon", "EOS DIGITAL REBEL XT", Daylight, 0, { 2.202756, 1, 1.488189, 0 } },
  { "Canon", "EOS DIGITAL REBEL XT", Fluorescent, 0, { 1.846004, 1, 1.987329, 0 } },
  { "Canon", "EOS DIGITAL REBEL XT", Shade, 0,	{ 2.617126, 1, 1.235236, 0 } },
  { "Canon", "EOS DIGITAL REBEL XT", Flash, 0,	{ 2.508858, 1, 1.297244, 0 } },
  { "Canon", "EOS DIGITAL REBEL XT", Cloudy, 0,	{ 2.409449, 1, 1.344488, 0 } },

  { "Canon", "EOS Kiss Digital N", Tungsten, 0,	{ 1.451524, 1, 2.333333, 0 } },
  { "Canon", "EOS Kiss Digital N", Daylight, 0,	{ 2.202756, 1, 1.488189, 0 } },
  { "Canon", "EOS Kiss Digital N", Fluorescent, 0, { 1.846004, 1, 1.987329, 0 } },
  { "Canon", "EOS Kiss Digital N", Shade, 0,	{ 2.617126, 1, 1.235236, 0 } },
  { "Canon", "EOS Kiss Digital N", Flash, 0,	{ 2.508858, 1, 1.297244, 0 } },
  { "Canon", "EOS Kiss Digital N", Cloudy, 0,	{ 2.409449, 1, 1.344488, 0 } },

  { "Canon", "EOS 400D DIGITAL", "Daylight", 0,	{ 2.300781, 1, 1.462891, 0 } },
  { "Canon", "EOS 400D DIGITAL", "Shade", 0,	{ 2.708984, 1, 1.208984, 0 } },
  { "Canon", "EOS 400D DIGITAL", "Cloudy", 0,	{ 2.509766, 1, 1.323242, 0 } },
  { "Canon", "EOS 400D DIGITAL", "Tungsten", 0,	{ 1.526123, 1, 2.330889, 0 } },
  { "Canon", "EOS 400D DIGITAL", "Fluorescent", 0, { 1.910506, 1, 2.080739, 0 } },
  { "Canon", "EOS 400D DIGITAL", "Flash", 0,	{ 2.708984, 1, 1.272461, 0 } },

  { "Canon", "EOS DIGITAL REBEL XTi", "Daylight", 0, { 2.300781, 1, 1.462891, 0 } },
  { "Canon", "EOS DIGITAL REBEL XTi", "Shade", 0, { 2.708984, 1, 1.208984, 0 } },
  { "Canon", "EOS DIGITAL REBEL XTi", "Cloudy", 0, { 2.509766, 1, 1.323242, 0 } },
  { "Canon", "EOS DIGITAL REBEL XTi", "Tungsten", 0, { 1.526123, 1, 2.330889, 0 } },
  { "Canon", "EOS DIGITAL REBEL XTi", "Fluorescent", 0, { 1.910506, 1, 2.080739, 0 } },
  { "Canon", "EOS DIGITAL REBEL XTi", "Flash", 0, { 2.708984, 1, 1.272461, 0 } },

  { "Canon", "EOS Kiss Digital X", "Daylight", 0, { 2.300781, 1, 1.462891, 0 } },
  { "Canon", "EOS Kiss Digital X", "Shade", 0,	{ 2.708984, 1, 1.208984, 0 } },
  { "Canon", "EOS Kiss Digital X", "Cloudy", 0,	{ 2.509766, 1, 1.323242, 0 } },
  { "Canon", "EOS Kiss Digital X", "Tungsten", 0, { 1.526123, 1, 2.330889, 0 } },
  { "Canon", "EOS Kiss Digital X", "Fluorescent", 0, { 1.910506, 1, 2.080739, 0 } },
  { "Canon", "EOS Kiss Digital X", "Flash", 0,	{ 2.708984, 1, 1.272461, 0 } },

  { "Canon", "EOS-1D Mark II", Cloudy, 0,	{ 2.093750, 1, 1.166016, 0 } },
  { "Canon", "EOS-1D Mark II", Daylight, 0,	{ 1.957031, 1, 1.295898, 0 } },
  { "Canon", "EOS-1D Mark II", Flash, 0,	{ 2.225586, 1, 1.172852, 0 } },
  { "Canon", "EOS-1D Mark II", Fluorescent, 0,	{ 1.785853, 1, 1.785853, 0 } },
  { "Canon", "EOS-1D Mark II", Shade, 0,	{ 2.220703, 1, 1.069336, 0 } },
  { "Canon", "EOS-1D Mark II", Tungsten, 0,	{ 1.415480, 1, 2.160142, 0 } },

  { "Canon", "EOS-1D Mark II N", Cloudy, 0,	{ 2.183594, 1, 1.220703, 0 } },
  { "Canon", "EOS-1D Mark II N", Daylight, 0,	{ 2.019531, 1, 1.349609, 0 } },
  { "Canon", "EOS-1D Mark II N", Flash, 0,	{ 2.291016, 1, 1.149414, 0 } },
  { "Canon", "EOS-1D Mark II N", Fluorescent, 0, { 1.802899, 1, 1.990338, 0 } },
  { "Canon", "EOS-1D Mark II N", Shade, 0,	{ 2.337891, 1, 1.112305, 0 } },
  { "Canon", "EOS-1D Mark II N", Tungsten, 0,	{ 1.408514, 1, 2.147645, 0 } },

  { "FUJIFILM", "FinePix E900", Daylight, 0,	{ 1.571875, 1, 1.128125, 0 } },
  { "FUJIFILM", "FinePix E900", Shade, 0,	{ 1.668750, 1, 1.006250, 0 } },
  { "FUJIFILM", "FinePix E900", DaylightFluorescent, 0, { 1.907609, 1, 1.016304, 0 } },
  { "FUJIFILM", "FinePix E900", WarmWhiteFluorescent, 0, { 1.654891, 1, 1.241848, 0 } },
  { "FUJIFILM", "FinePix E900", CoolWhiteFluorescent, 0, { 1.554348, 1, 1.519022, 0 } },
  { "FUJIFILM", "FinePix E900", Incandescent, 0, { 1.037611, 1, 1.842920, 0 } },

  { "FUJIFILM", "FinePix F700", Daylight, 0,	{ 1.725000, 1, 1.500000, 0 } },
  { "FUJIFILM", "FinePix F700", Shade, 0,	{ 1.950000, 1, 1.325000, 0 } },
  { "FUJIFILM", "FinePix F700", DaylightFluorescent, 0, { 2.032609, 1, 1.336957, 0 } },
  { "FUJIFILM", "FinePix F700", WarmWhiteFluorescent, 0, { 1.706522, 1, 1.663043, 0 } },
  { "FUJIFILM", "FinePix F700", CoolWhiteFluorescent, 0, { 1.684783, 1, 2.152174, 0 } },
  { "FUJIFILM", "FinePix F700", Incandescent, 0, { 1.168142, 1, 2.477876, 0 } },

  { "FUJIFILM", "FinePix S20Pro", Daylight, 0,	{ 1.712500, 1, 1.500000, 0 } },
  { "FUJIFILM", "FinePix S20Pro", Cloudy, 0,	{ 1.887500, 1, 1.262500, 0 } },
  { "FUJIFILM", "FinePix S20Pro", DaylightFluorescent, 0, { 2.097826, 1, 1.304348, 0 } },
  { "FUJIFILM", "FinePix S20Pro", WarmWhiteFluorescent, 0, { 1.782609, 1, 1.619565, 0 } },
  { "FUJIFILM", "FinePix S20Pro", CoolWhiteFluorescent, 0, { 1.670213, 1, 2.063830, 0 } },
  { "FUJIFILM", "FinePix S20Pro", Incandescent, 0, { 1.069565, 1, 2.486957 } },

  { "FUJIFILM", "FinePix S2Pro", Daylight, 0,	{ 1.509804, 1, 1.401961, 0 } },
  { "FUJIFILM", "FinePix S2Pro", Cloudy, 0,	{ 1.666667, 1, 1.166667, 0 } },
  { "FUJIFILM", "FinePix S2Pro", Flash, 0,	{ 1, 1.014084, 2.542253, 0 } },
  { "FUJIFILM", "FinePix S2Pro", DaylightFluorescent, 0, { 1.948718, 1, 1.230769, 0 } },
  { "FUJIFILM", "FinePix S2Pro", WarmWhiteFluorescent, 0, { 1.675214, 1, 1.572650, 0 } },
  { "FUJIFILM", "FinePix S2Pro", CoolWhiteFluorescent, 0, { 1.649573, 1, 2.094017, 0 } },

  { "FUJIFILM", "FinePix S5000", Incandescent, 0, { 1.212081, 1, 2.672364, 0 } },
  { "FUJIFILM", "FinePix S5000", Fluorescent, 0, { 1.772316, 1, 2.349902, 0 } },
  { "FUJIFILM", "FinePix S5000", Daylight, 0,	{ 1.860403, 1, 1.515946, 0 } },
  { "FUJIFILM", "FinePix S5000", Flash, 0,	{ 2.202181, 1, 1.423284, 0 } },
  { "FUJIFILM", "FinePix S5000", Cloudy, 0,	{ 2.036578, 1, 1.382513, 0 } },
  { "FUJIFILM", "FinePix S5000", Shade, 0,	{ 2.357215, 1, 1.212016, 0 } },

  { "FUJIFILM", "FinePix S5200", Daylight, 0,	{ 1.587500, 1, 1.381250, 0 } },
  { "FUJIFILM", "FinePix S5200", Shade, 0,	{ 1.946875, 1, 1.175000, 0 } },
  { "FUJIFILM", "FinePix S5200", DaylightFluorescent, 0, { 1.948370, 1, 1.187500, 0 } },
  { "FUJIFILM", "FinePix S5200", WarmWhiteFluorescent, 0, { 1.682065, 1, 1.437500, 0 } },
  { "FUJIFILM", "FinePix S5200", CoolWhiteFluorescent, 0, { 1.595109, 1, 1.839674, 0 } },
  { "FUJIFILM", "FinePix S5200", Incandescent, 0, { 1.077434, 1, 2.170354, 0 } },

  { "FUJIFILM", "FinePix S5500", Daylight, 0,	{ 1.712500, 1, 1.550000, 0 } },
  { "FUJIFILM", "FinePix S5500", Shade, 0,	{ 1.912500, 1, 1.375000, 0 } },
  { "FUJIFILM", "FinePix S5500", DaylightFluorescent, 0, { 1.978261, 1, 1.380435, 0 } },
  { "FUJIFILM", "FinePix S5500", WarmWhiteFluorescent, 0, { 1.673913, 1, 1.673913, 0 } },
  { "FUJIFILM", "FinePix S5500", CoolWhiteFluorescent, 0, { 1.663043, 1, 2.163043, 0 } },
  { "FUJIFILM", "FinePix S5500", Incandescent, 0, { 1.115044, 1, 2.566372, 0 } },

  { "FUJIFILM", "FinePix S5600", Daylight, 0,	{ 1.587500, 1, 1.381250, 0 } },
  { "FUJIFILM", "FinePix S5600", Shade, 0,	{ 1.946875, 1, 1.175000, 0 } },
  { "FUJIFILM", "FinePix S5600", DaylightFluorescent, 0, { 1.948370, 1, 1.187500, 0 } },
  { "FUJIFILM", "FinePix S5600", WarmWhiteFluorescent, 0, { 1.682065, 1, 1.437500, 0 } },
  { "FUJIFILM", "FinePix S5600", CoolWhiteFluorescent, 0, { 1.595109, 1, 1.839674, 0 } },
  { "FUJIFILM", "FinePix S5600", Incandescent, 0, { 1.077434, 1, 2.170354, 0 } },

  { "FUJIFILM", "FinePix S6000fd", Daylight, 0,	{ 1.511905, 1, 1.431548, 0 } },
  { "FUJIFILM", "FinePix S6000fd", Shade, 0,	{ 1.699405, 1, 1.232143, 0 } },
  { "FUJIFILM", "FinePix S6000fd", DaylightFluorescent, 0, { 1.866071, 1, 1.309524, 0 } },
  { "FUJIFILM", "FinePix S6000fd", WarmWhiteFluorescent, 0, { 1.568452, 1, 1.627976, 0 } },
  { "FUJIFILM", "FinePix S6000fd", CoolWhiteFluorescent, 0, { 1.598214, 1, 2.038691, 0 } },
  { "FUJIFILM", "FinePix S6000fd", Incandescent, 0, { 1, 1.024390, 2.466463, 0 } },

  { "FUJIFILM", "FinePix S6500fd", Daylight, 0,	{ 1.398810, 1, 1.470238, 0 } },
  { "FUJIFILM", "FinePix S6500fd", Shade, 0,	{ 1.580357, 1, 1.270833, 0 } },
  { "FUJIFILM", "FinePix S6500fd", DaylightFluorescent, 0, { 1.735119, 1, 1.348214, 0 } },
  { "FUJIFILM", "FinePix S6500fd", WarmWhiteFluorescent, 0, { 1.455357, 1, 1.672619, 0 } },
  { "FUJIFILM", "FinePix S6500fd", CoolWhiteFluorescent, 0, { 1.482143, 1, 2.089286, 0 } },
  { "FUJIFILM", "FinePix S6500fd", Incandescent, 0, { 1, 1.123746, 2.769231, 0 } },

  { "FUJIFILM", "FinePix S7000", Daylight, 0,	{ 1.900000, 1, 1.525000, 0 } },
  { "FUJIFILM", "FinePix S7000", Shade, 0,	{ 2.137500, 1, 1.350000, 0 } },
  { "FUJIFILM", "FinePix S7000", DaylightFluorescent, 0, { 2.315217, 1, 1.347826, 0 } },
  { "FUJIFILM", "FinePix S7000", WarmWhiteFluorescent, 0, { 1.902174, 1, 1.663043, 0 } },
  { "FUJIFILM", "FinePix S7000", CoolWhiteFluorescent, 0, { 1.836957, 1, 2.130435, 0 } },
  { "FUJIFILM", "FinePix S7000", Incandescent, 0, { 1.221239, 1, 2.548673, 0 } },

 /* The S9000 and S9500 are the same camera */
  { "FUJIFILM", "FinePix S9000", Daylight, 0,	{ 1.618750, 1, 1.231250, 0 } },
  { "FUJIFILM", "FinePix S9000", Cloudy, 0,	{ 1.700000, 1, 1.046875, 0 } },
  { "FUJIFILM", "FinePix S9000", DaylightFluorescent, 0, { 1.902174, 1, 1.057065, 0 } },
  { "FUJIFILM", "FinePix S9000", WarmWhiteFluorescent, 0, { 1.633152, 1, 1.293478, 0 } },
  { "FUJIFILM", "FinePix S9000", CoolWhiteFluorescent, 0, { 1.546196, 1, 1.622283, 0 } },
  { "FUJIFILM", "FinePix S9000", Incandescent, 0, { 1.064159, 1, 1.960177, 0 } },

  { "FUJIFILM", "FinePix S9500", Daylight, 0,	{ 1.618750, 1, 1.231250, 0 } },
  { "FUJIFILM", "FinePix S9500", Cloudy, 0,	{ 1.700000, 1, 1.046875, 0 } },
  { "FUJIFILM", "FinePix S9500", DaylightFluorescent, 0, { 1.902174, 1, 1.057065, 0 } },
  { "FUJIFILM", "FinePix S9500", WarmWhiteFluorescent, 0, { 1.633152, 1, 1.293478, 0 } },
  { "FUJIFILM", "FinePix S9500", CoolWhiteFluorescent, 0, { 1.546196, 1, 1.622283, 0 } },
  { "FUJIFILM", "FinePix S9500", Incandescent, 0, { 1.064159, 1, 1.960177, 0 } },

  { "FUJIFILM", "FinePix S9100", Daylight, 0,	{ 1.506250, 1, 1.318750 } },
  { "FUJIFILM", "FinePix S9100", Cloudy, 0,	{ 1.587500, 1, 1.128125 } },
  { "FUJIFILM", "FinePix S9100", DaylightFluorescent, 0, { 1.777174, 1, 1.138587 } },
  { "FUJIFILM", "FinePix S9100", WarmWhiteFluorescent, 0, { 1.521739, 1, 1.380435 } },
  { "FUJIFILM", "FinePix S9100", CoolWhiteFluorescent, 0, { 1.437500, 1, 1.720109 } },
  { "FUJIFILM", "FinePix S9100", Incandescent, 0, { 1, 1.024943, 2.113379 } },

  { "FUJIFILM", "FinePix S9600", Daylight, 0,	{ 1.534375, 1, 1.300000 } },
  { "FUJIFILM", "FinePix S9600", Shade, 0,	{ 1.615625, 1, 1.112500 } },
  { "FUJIFILM", "FinePix S9600", DaylightFluorescent, 0, { 1.809783, 1, 1.122283 } },
  { "FUJIFILM", "FinePix S9600", WarmWhiteFluorescent, 0, { 1.551630, 1, 1.361413 } },
  { "FUJIFILM", "FinePix S9600", CoolWhiteFluorescent, 0, { 1.467391, 1, 1.692935 } },
  { "FUJIFILM", "FinePix S9600", Incandescent, 0, { 1, 1.004444, 2.040000 } },

  { "KODAK", "P850 ZOOM", Daylight, 0,		{ 1.859375, 1, 1.566406, 0 } },
  { "KODAK", "P850 ZOOM", Cloudy, 0,		{ 1.960938, 1, 1.570313, 0 } },
  { "KODAK", "P850 ZOOM", Shade, 0,		{ 2.027344, 1, 1.519531, 0 } },
  { "KODAK", "P850 ZOOM", EveningSun, 0,	{ 1.679688, 1, 1.812500, 0 } },
  { "KODAK", "P850 ZOOM", Tungsten, 0,		{ 1.140625, 1, 2.726563, 0 } },
  { "KODAK", "P850 ZOOM", Fluorescent, 0,	{ 1.113281, 1, 2.949219, 0 } },

  { "Leica Camera AG", "M8 Digital Camera", Cloudy, 0, { 2.136719, 1, 1.168213, 0 } },
  { "Leica Camera AG", "M8 Digital Camera", Daylight, 0, { 2.007996, 1, 1.268982, 0 } },
  { "Leica Camera AG", "M8 Digital Camera", Flash, 0, { 2.164490, 1, 1.177795, 0 } },
  { "Leica Camera AG", "M8 Digital Camera", Fluorescent, 0, { 1.655579, 1, 2.070374, 0 } },
  { "Leica Camera AG", "M8 Digital Camera", Shade, 0, { 2.197754, 1, 1.111084, 0 } },
  { "Leica Camera AG", "M8 Digital Camera", Tungsten, 0, { 1.160034, 1, 2.028381, 0 } },

  { "Leica Camera AG", "R8 - Digital Back DMR", Incandescent, 0, { 1, 1.109985, 2.430664, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", Fluorescent, 0, { 1.234985, 1, 1.791138, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", Daylight, 0, { 1.459961, 1, 1.184937, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", Flash, 0, { 1.395020, 1, 1.144897, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", Cloudy, 0, { 1.541992, 1, 1.052856, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", Shade, 0, { 1.644897, 1.033936, 1, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "2600K", 0, { 1, 1.220825, 2.999390, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "2700K", 0, { 1, 1.172607, 2.747192, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "2800K", 0, { 1, 1.129639, 2.527710, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "2900K", 0, { 1, 1.088867, 2.333130, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "3000K", 0, { 1, 1.049438, 2.156494, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "3100K", 0, { 1, 1.015503, 2.008423, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "3200K", 0, { 1.008789, 1, 1.904663, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "3300K", 0, { 1.032349, 1, 1.841187, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "3400K", 0, { 1.056763, 1, 1.780273, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "3500K", 0, { 1.081543, 1, 1.723755, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "3600K", 0, { 1.105591, 1, 1.673828, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "3700K", 0, { 1.128052, 1, 1.625732, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "3800K", 0, { 1.149536, 1, 1.580688, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "3900K", 0, { 1.170532, 1, 1.540527, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "4000K", 0, { 1.191040, 1, 1.504150, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "4100K", 0, { 1.209106, 1, 1.466919, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "4200K", 0, { 1.226807, 1, 1.433228, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "4300K", 0, { 1.244019, 1, 1.402466, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "4400K", 0, { 1.261108, 1, 1.374268, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "4500K", 0, { 1.276611, 1, 1.346924, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "4600K", 0, { 1.290771, 1, 1.320435, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "4700K", 0, { 1.304565, 1, 1.295898, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "4800K", 0, { 1.318115, 1, 1.273315, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "4900K", 0, { 1.331543, 1, 1.252441, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "5000K", 0, { 1.344360, 1, 1.233032, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "5200K", 0, { 1.365479, 1, 1.193970, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "5400K", 0, { 1.385498, 1, 1.160034, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "5600K", 0, { 1.404663, 1, 1.130127, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "5800K", 0, { 1.421387, 1, 1.102661, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "6000K", 0, { 1.435303, 1, 1.076782, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "6200K", 0, { 1.448608, 1, 1.053833, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "6400K", 0, { 1.461304, 1, 1.032959, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "6600K", 0, { 1.473511, 1, 1.014160, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "6800K", 0, { 1.488647, 1.003906, 1, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "7000K", 0, { 1.522705, 1.021118, 1, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "7200K", 0, { 1.555176, 1.037476, 1, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "7400K", 0, { 1.586182, 1.052979, 1, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "7600K", 0, { 1.615967, 1.067627, 1, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "7800K", 0, { 1.644409, 1.081665, 1, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "8000K", 0, { 1.671875, 1.094849, 1, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "8300K", 0, { 1.708740, 1.114624, 1, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "8600K", 0, { 1.743286, 1.133057, 1, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "8900K", 0, { 1.775879, 1.150269, 1.000000, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "9200K", 0, { 1.806274, 1.166382, 1.000000, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "9500K", 0, { 1.835449, 1.181519, 1.000000, 0 } },
  { "Leica Camera AG", "R8 - Digital Back DMR", "9800K", 0, { 1.862793, 1.195801, 1.000000, 0 } },

  { "Leica Camera AG", "R9 - Digital Back DMR", Incandescent, 0, { 1, 1.109985, 2.430664, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", Fluorescent, 0, { 1.234985, 1, 1.791138, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", Daylight, 0, { 1.459961, 1, 1.184937, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", Flash, 0, { 1.395020, 1, 1.144897, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", Cloudy, 0, { 1.541992, 1, 1.052856, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", Shade, 0, { 1.644897, 1.033936, 1, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "2600K", 0, { 1, 1.220825, 2.999390, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "2700K", 0, { 1, 1.172607, 2.747192, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "2800K", 0, { 1, 1.129639, 2.527710, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "2900K", 0, { 1, 1.088867, 2.333130, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "3000K", 0, { 1, 1.049438, 2.156494, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "3100K", 0, { 1, 1.015503, 2.008423, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "3200K", 0, { 1.008789, 1, 1.904663, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "3300K", 0, { 1.032349, 1, 1.841187, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "3400K", 0, { 1.056763, 1, 1.780273, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "3500K", 0, { 1.081543, 1, 1.723755, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "3600K", 0, { 1.105591, 1, 1.673828, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "3700K", 0, { 1.128052, 1, 1.625732, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "3800K", 0, { 1.149536, 1, 1.580688, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "3900K", 0, { 1.170532, 1, 1.540527, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "4000K", 0, { 1.191040, 1, 1.504150, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "4100K", 0, { 1.209106, 1, 1.466919, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "4200K", 0, { 1.226807, 1, 1.433228, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "4300K", 0, { 1.244019, 1, 1.402466, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "4400K", 0, { 1.261108, 1, 1.374268, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "4500K", 0, { 1.276611, 1, 1.346924, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "4600K", 0, { 1.290771, 1, 1.320435, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "4700K", 0, { 1.304565, 1, 1.295898, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "4800K", 0, { 1.318115, 1, 1.273315, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "4900K", 0, { 1.331543, 1, 1.252441, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "5000K", 0, { 1.344360, 1, 1.233032, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "5200K", 0, { 1.365479, 1, 1.193970, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "5400K", 0, { 1.385498, 1, 1.160034, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "5600K", 0, { 1.404663, 1, 1.130127, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "5800K", 0, { 1.421387, 1, 1.102661, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "6000K", 0, { 1.435303, 1, 1.076782, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "6200K", 0, { 1.448608, 1, 1.053833, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "6400K", 0, { 1.461304, 1, 1.032959, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "6600K", 0, { 1.473511, 1, 1.014160, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "6800K", 0, { 1.488647, 1.003906, 1, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "7000K", 0, { 1.522705, 1.021118, 1, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "7200K", 0, { 1.555176, 1.037476, 1, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "7400K", 0, { 1.586182, 1.052979, 1, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "7600K", 0, { 1.615967, 1.067627, 1, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "7800K", 0, { 1.644409, 1.081665, 1, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "8000K", 0, { 1.671875, 1.094849, 1, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "8300K", 0, { 1.708740, 1.114624, 1, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "8600K", 0, { 1.743286, 1.133057, 1, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "8900K", 0, { 1.775879, 1.150269, 1.000000, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "9200K", 0, { 1.806274, 1.166382, 1.000000, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "9500K", 0, { 1.835449, 1.181519, 1.000000, 0 } },
  { "Leica Camera AG", "R9 - Digital Back DMR", "9800K", 0, { 1.862793, 1.195801, 1.000000, 0 } },

  { "LEICA", "DIGILUX 2", Daylight, 0,		{ 1.628906, 1, 1.488281, 0 } },
  { "LEICA", "DIGILUX 2", Cloudy, 0,		{ 1.835938, 1, 1.343750, 0 } },
  { "LEICA", "DIGILUX 2", Incandescent, 0,	{ 1.078125, 1, 2.203125, 0 } },
  { "LEICA", "DIGILUX 2", Flash, 0,		{ 2.074219, 1, 1.304688, 0 } },
  { "LEICA", "DIGILUX 2", BlackNWhite, 0,	{ 1.632812, 1, 1.550781, 0 } },

  { "Minolta", "DiMAGE 5", Daylight, 0,		{ 2.023438, 1, 1.371094, 0 } },
  { "Minolta", "DiMAGE 5", Incandescent, 0,	{ 1.113281, 1, 2.480469, 0 } },
  { "Minolta", "DiMAGE 5", Fluorescent, 0,	{ 1.957031, 1, 2.058594, 0 } },
  { "Minolta", "DiMAGE 5", Cloudy, 0,		{ 2.199219, 1, 1.300781, 0 } },

  { "Minolta", "DiMAGE 7", Cloudy, 0,		{ 2.082031, 1, 1.226562, 0 } },
  { "Minolta", "DiMAGE 7", Daylight, 0,		{ 1.914062, 1, 1.527344, 0 } },
  { "Minolta", "DiMAGE 7", Fluorescent, 0,	{ 1.917969, 1, 2.007812, 0 } },
  { "Minolta", "DiMAGE 7", Tungsten, 0,		{ 1.050781, 1, 2.437500, 0 } },

  { "Minolta", "DiMAGE 7i", Daylight, 0,	{ 1.441406, 1, 1.457031, 0 } },
  { "Minolta", "DiMAGE 7i", Tungsten, 0,	{ 1, 1.333333, 3.572917, 0 } },
  { "Minolta", "DiMAGE 7i", Fluorescent, 0,	{ 1.554688, 1, 2.230469, 0 } },
  { "Minolta", "DiMAGE 7i", Cloudy, 0,		{ 1.550781, 1, 1.402344, 0 } },

  { "Minolta", "DiMAGE 7Hi", Daylight, 0,	{ 1.609375, 1, 1.328125, 0 } }, /*5500K*/
  { "Minolta", "DiMAGE 7Hi", Tungsten, 0,	{ 1, 1.137778, 2.768889, 0 } }, /*2800K*/
  { "Minolta", "DiMAGE 7Hi", WhiteFluorescent, 0, { 1.664062, 1, 2.105469, 0 } }, /*4060K*/
  { "Minolta", "DiMAGE 7Hi", CoolWhiteFluorescent, 0, { 1.796875, 1, 1.734375, 0 } }, /*4938K*/
  { "Minolta", "DiMAGE 7Hi", Cloudy, 0,		{ 1.730469, 1, 1.269531, 0 } }, /*5823K*/

  { "Minolta", "DiMAGE A1", Daylight, 0,	{ 1.808594, 1, 1.304688, 0 } },
  { "Minolta", "DiMAGE A1", Tungsten, 0,	{ 1.062500, 1, 2.675781, 0 } },
  { "Minolta", "DiMAGE A1", Fluorescent, 0,	{ 1.707031, 1, 2.039063, 0 } },
  { "Minolta", "DiMAGE A1", Cloudy, 0,		{ 1.960938, 1, 1.339844, 0 } },
  { "Minolta", "DiMAGE A1", Shade, 0,		{ 2.253906, 1, 1.199219, 0 } },
  { "Minolta", "DiMAGE A1", Shade, 2,		{ 2.000000, 1, 1.183594, 0 } },
  { "Minolta", "DiMAGE A1", Flash, 0,		{ 1.972656, 1, 1.265625, 0 } },

  { "Minolta", "DiMAGE A2", Cloudy, -3,		{ 2.109375, 1, 1.578125, 0 } },
  { "Minolta", "DiMAGE A2", Cloudy, 0,		{ 2.203125, 1, 1.296875, 0 } },
  { "Minolta", "DiMAGE A2", Cloudy, 3,		{ 2.296875, 1, 1.015625, 0 } },
  { "Minolta", "DiMAGE A2", Daylight, -3,	{ 1.867188, 1, 1.683594, 0 } },
  { "Minolta", "DiMAGE A2", Daylight, 0,	{ 1.960938, 1, 1.402344, 0 } },
  { "Minolta", "DiMAGE A2", Daylight, 3,	{ 2.054688, 1, 1.121094, 0 } },
  { "Minolta", "DiMAGE A2", Flash, -3,		{ 1.945312, 1, 1.613281, 0 } },
  { "Minolta", "DiMAGE A2", Flash, 0,		{ 2.039062, 1, 1.332031, 0 } },
  { "Minolta", "DiMAGE A2", Flash, 3,		{ 2.132812, 1, 1.050781, 0 } },
  { "Minolta", "DiMAGE A2", Fluorescent, -2,	{ 1.136719, 1, 2.746094, 0 } },
  { "Minolta", "DiMAGE A2", Fluorescent, 0,	{ 1.722656, 1, 2.132812, 0 } },
  { "Minolta", "DiMAGE A2", Fluorescent, 4,	{ 2.347656, 1, 1.535156, 0 } },
  { "Minolta", "DiMAGE A2", Shade, -3,		{ 2.273438, 1, 1.546875, 0 } },
  { "Minolta", "DiMAGE A2", Shade, 0,		{ 2.367188, 1, 1.265625, 0 } },
  { "Minolta", "DiMAGE A2", Shade, 3,		{ 2.500000, 1.015873, 1, 0 } },
  { "Minolta", "DiMAGE A2", Tungsten, -3,	{ 1.003906, 1, 3.164062, 0 } },
  { "Minolta", "DiMAGE A2", Tungsten, 0,	{ 1.097656, 1, 2.882812, 0 } },
  { "Minolta", "DiMAGE A2", Tungsten, 3,	{ 1.191406, 1, 2.601562, 0 } },

  { "Minolta", "DiMAGE Z2", Daylight, 0,	{ 1.843749, 1, 1.664062, 0 } },
  { "Minolta", "DiMAGE Z2", Cloudy, 0,		{ 2.195312, 1, 1.449218, 0 } },
  { "Minolta", "DiMAGE Z2", Tungsten, 0,	{ 1.097656, 1, 3.050780, 0 } },
  { "Minolta", "DiMAGE Z2", Fluorescent, 0,	{ 1.796874, 1, 2.257810, 0 } },
  { "Minolta", "DiMAGE Z2", Flash, 0,		{ 2.117186, 1, 1.472656, 0 } },

  { "Minolta", "DiMAGE G500", Daylight, 0,	{ 1.496094, 1, 1.121094, 0 } },
  { "Minolta", "DiMAGE G500", Cloudy, 0,	{ 1.527344, 1, 1.105469, 0 } },
  { "Minolta", "DiMAGE G500", Fluorescent, 0,	{ 1.382813, 1, 1.347656, 0 } },
  { "Minolta", "DiMAGE G500", Tungsten, 0,	{ 1.042969, 1, 1.859375, 0 } },
  { "Minolta", "DiMAGE G500", Flash, 0,		{ 1.647078, 1, 1.218159, 0 } },

  { "MINOLTA", "DYNAX 5D", Daylight, -3,	{ 1.593750, 1, 1.875000, 0 } },
  { "MINOLTA", "DYNAX 5D", Daylight, -2,	{ 1.644531, 1, 1.792969, 0 } },
  { "MINOLTA", "DYNAX 5D", Daylight, -1,	{ 1.699219, 1, 1.718750, 0 } },
  { "MINOLTA", "DYNAX 5D", Daylight, 0,		{ 1.757812, 1, 1.636719, 0 } },
  { "MINOLTA", "DYNAX 5D", Daylight, 1,		{ 1.804688, 1, 1.566406, 0 } },
  { "MINOLTA", "DYNAX 5D", Daylight, 2,		{ 1.863281, 1, 1.500000, 0 } },
  { "MINOLTA", "DYNAX 5D", Daylight, 3,		{ 1.925781, 1, 1.437500, 0 } },
  { "MINOLTA", "DYNAX 5D", Shade, -3,		{ 1.835938, 1, 1.644531, 0 } },
  { "MINOLTA", "DYNAX 5D", Shade, -2,		{ 1.894531, 1, 1.574219, 0 } },
  { "MINOLTA", "DYNAX 5D", Shade, -1,		{ 1.957031, 1, 1.507812, 0 } },
  { "MINOLTA", "DYNAX 5D", Shade, 0,		{ 2.011719, 1, 1.433594, 0 } },
  { "MINOLTA", "DYNAX 5D", Shade, 1,		{ 2.078125, 1, 1.375000, 0 } },
  { "MINOLTA", "DYNAX 5D", Shade, 2,		{ 2.148438, 1, 1.316406, 0 } },
  { "MINOLTA", "DYNAX 5D", Shade, 3,		{ 2.218750, 1, 1.261719, 0 } },
  { "MINOLTA", "DYNAX 5D", Cloudy, -3,		{ 1.718750, 1, 1.738281, 0 } },
  { "MINOLTA", "DYNAX 5D", Cloudy, -2,		{ 1.773438, 1, 1.664062, 0 } },
  { "MINOLTA", "DYNAX 5D", Cloudy, -1,		{ 1.835938, 1, 1.593750, 0 } },
  { "MINOLTA", "DYNAX 5D", Cloudy, 0,		{ 1.886719, 1, 1.500000, 0 } },
  { "MINOLTA", "DYNAX 5D", Cloudy, 1,		{ 1.945312, 1, 1.460938, 0 } },
  { "MINOLTA", "DYNAX 5D", Cloudy, 2,		{ 2.007812, 1, 1.390625, 0 } },
  { "MINOLTA", "DYNAX 5D", Cloudy, 3,		{ 2.078125, 1, 1.332031, 0 } },
  { "MINOLTA", "DYNAX 5D", Tungsten, -3,	{ 1, 1.066667, 4.262500, 0 } },
  { "MINOLTA", "DYNAX 5D", Tungsten, -2,	{ 1, 1.032258, 3.951613, 0 } },
  { "MINOLTA", "DYNAX 5D", Tungsten, -1,	{ 1, 1.000000, 3.671875, 0 } },
  { "MINOLTA", "DYNAX 5D", Tungsten, 0,		{ 1.023438, 1, 3.496094, 0 } },
  { "MINOLTA", "DYNAX 5D", Tungsten, 1,		{ 1.062500, 1, 3.367188, 0 } },
  { "MINOLTA", "DYNAX 5D", Tungsten, 2,		{ 1.097656, 1, 3.203125, 0 } },
  { "MINOLTA", "DYNAX 5D", Tungsten, 3,		{ 1.132812, 1, 3.070312, 0 } },
  { "MINOLTA", "DYNAX 5D", Fluorescent, -2,	{ 1.148438, 1, 3.429688, 0 } },
  { "MINOLTA", "DYNAX 5D", Fluorescent, -1,	{ 1.285156, 1, 3.250000, 0 } },
  { "MINOLTA", "DYNAX 5D", Fluorescent, 0,	{ 1.703125, 1, 2.582031, 0 } },
  { "MINOLTA", "DYNAX 5D", Fluorescent, 1,	{ 1.761719, 1, 2.335938, 0 } },
  { "MINOLTA", "DYNAX 5D", Fluorescent, 2,	{ 1.730469, 1, 1.878906, 0 } },
  { "MINOLTA", "DYNAX 5D", Fluorescent, 3,	{ 1.996094, 1, 1.527344, 0 } },
  { "MINOLTA", "DYNAX 5D", Fluorescent, 4,	{ 2.218750, 1, 1.714844, 0 } },
  { "MINOLTA", "DYNAX 5D", Flash, -3,		{ 1.738281, 1, 1.683594, 0 } },
  { "MINOLTA", "DYNAX 5D", Flash, -2,		{ 1.792969, 1, 1.609375, 0 } },
  { "MINOLTA", "DYNAX 5D", Flash, -1,		{ 1.855469, 1, 1.542969, 0 } },
  { "MINOLTA", "DYNAX 5D", Flash, 0,		{ 1.917969, 1, 1.457031, 0 } },
  { "MINOLTA", "DYNAX 5D", Flash, 1,		{ 1.968750, 1, 1.406250, 0 } },
  { "MINOLTA", "DYNAX 5D", Flash, 2,		{ 2.031250, 1, 1.347656, 0 } },
  { "MINOLTA", "DYNAX 5D", Flash, 3,		{ 2.101562, 1, 1.289062, 0 } },

  { "MINOLTA", "DYNAX 7D", Daylight, -3,	{ 1.476562, 1, 1.824219, 0 } },
  { "MINOLTA", "DYNAX 7D", Daylight, 0,		{ 1.621094, 1, 1.601562, 0 } },
  { "MINOLTA", "DYNAX 7D", Daylight, 3,		{ 1.785156, 1, 1.414062, 0 } },
  { "MINOLTA", "DYNAX 7D", Shade, -3,		{ 1.683594, 1, 1.585938, 0 } },
  { "MINOLTA", "DYNAX 7D", Shade, 0,		{ 1.855469, 1, 1.402344, 0 } },
  { "MINOLTA", "DYNAX 7D", Shade, 3,		{ 2.031250, 1, 1.226562, 0 } },
  { "MINOLTA", "DYNAX 7D", Cloudy, -3,		{ 1.593750, 1, 1.671875, 0 } },
  { "MINOLTA", "DYNAX 7D", Cloudy, 0,		{ 1.738281, 1, 1.464844, 0 } },
  { "MINOLTA", "DYNAX 7D", Cloudy, 3,		{ 1.925781, 1, 1.296875, 0 } },
  { "MINOLTA", "DYNAX 7D", Tungsten, -3,	{ 0.867188, 1, 3.765625, 0 } },
  { "MINOLTA", "DYNAX 7D", Tungsten, 0,		{ 0.945312, 1, 3.292969, 0 } },
  { "MINOLTA", "DYNAX 7D", Tungsten, 3,		{ 1.050781, 1, 2.921875, 0 } },
  { "MINOLTA", "DYNAX 7D", Fluorescent, -2,	{ 1.058594, 1, 3.230469, 0 } },
  { "MINOLTA", "DYNAX 7D", Fluorescent, 0,	{ 1.570312, 1, 2.453125, 0 } },
  { "MINOLTA", "DYNAX 7D", Fluorescent, 1,	{ 1.625000, 1, 2.226562, 0 } },
  { "MINOLTA", "DYNAX 7D", Fluorescent, 4,	{ 2.046875, 1, 1.675781, 0 } },
  { "MINOLTA", "DYNAX 7D", Flash, -3,		{ 1.738281, 1, 1.656250, 0 } },
  { "MINOLTA", "DYNAX 7D", Flash, 0,		{ 1.890625, 1, 1.445312, 0 } },
  { "MINOLTA", "DYNAX 7D", Flash, 3,		{ 2.101562, 1, 1.281250, 0 } },
  { "MINOLTA", "DYNAX 7D", "2500K", 0,		{ 1, 1.207547, 4.801887, 0 } },
  { "MINOLTA", "DYNAX 7D", "2600K", 0,		{ 1, 1.153153, 4.297297, 0 } },
  { "MINOLTA", "DYNAX 7D", "2700K", 0,		{ 1, 1.089362, 3.829787, 0 } },
  { "MINOLTA", "DYNAX 7D", "2800K", 0,		{ 1, 1.044898, 3.477551, 0 } },
  { "MINOLTA", "DYNAX 7D", "2900K", 0,		{ 1, 1.007874, 3.173228, 0 } },
  { "MINOLTA", "DYNAX 7D", "3000K", 0,		{ 1.031250, 1, 3.000000, 0 } },
  { "MINOLTA", "DYNAX 7D", "3100K", 0,		{ 1.066406, 1, 2.875000, 0 } },
  { "MINOLTA", "DYNAX 7D", "3200K", 0,		{ 1.109375, 1, 2.765625, 0 } },
  { "MINOLTA", "DYNAX 7D", "3300K", 0,		{ 1.144531, 1, 2.648438, 0 } },
  { "MINOLTA", "DYNAX 7D", "3400K", 0,		{ 1.175781, 1, 2.554688, 0 } },
  { "MINOLTA", "DYNAX 7D", "3500K", 0,		{ 1.207031, 1, 2.468750, 0 } },
  { "MINOLTA", "DYNAX 7D", "3600K", 0,		{ 1.242188, 1, 2.390625, 0 } },
  { "MINOLTA", "DYNAX 7D", "3700K", 0,		{ 1.277344, 1, 2.312500, 0 } },
  { "MINOLTA", "DYNAX 7D", "3800K", 0,		{ 1.304688, 1, 2.242188, 0 } },
  { "MINOLTA", "DYNAX 7D", "3900K", 0,		{ 1.339844, 1, 2.179688, 0 } },
  { "MINOLTA", "DYNAX 7D", "4000K", 0,		{ 1.363281, 1, 2.125000, 0 } },
  { "MINOLTA", "DYNAX 7D", "4100K", 0,		{ 1.390625, 1, 2.078125, 0 } },
  { "MINOLTA", "DYNAX 7D", "4200K", 0,		{ 1.421875, 1, 2.023438, 0 } },
  { "MINOLTA", "DYNAX 7D", "4300K", 0,		{ 1.445312, 1, 1.976562, 0 } },
  { "MINOLTA", "DYNAX 7D", "4400K", 0,		{ 1.476562, 1, 1.937500, 0 } },
  { "MINOLTA", "DYNAX 7D", "4500K", 0,		{ 1.500000, 1, 1.894531, 0 } },
  { "MINOLTA", "DYNAX 7D", "4600K", 0,		{ 1.527344, 1, 1.855469, 0 } },
  { "MINOLTA", "DYNAX 7D", "4700K", 0,		{ 1.542969, 1, 1.824219, 0 } },
  { "MINOLTA", "DYNAX 7D", "4800K", 0,		{ 1.566406, 1, 1.785156, 0 } },
  { "MINOLTA", "DYNAX 7D", "4900K", 0,		{ 1.593750, 1, 1.757812, 0 } },
  { "MINOLTA", "DYNAX 7D", "5000K", 0,		{ 1.609375, 1, 1.726562, 0 } },
  { "MINOLTA", "DYNAX 7D", "5100K", 0,		{ 1.636719, 1, 1.699219, 0 } },
  { "MINOLTA", "DYNAX 7D", "5200K", 0,		{ 1.656250, 1, 1.671875, 0 } },
  { "MINOLTA", "DYNAX 7D", "5300K", 0,		{ 1.671875, 1, 1.644531, 0 } },
  { "MINOLTA", "DYNAX 7D", "5400K", 0,		{ 1.691406, 1, 1.621094, 0 } },
  { "MINOLTA", "DYNAX 7D", "5500K", 0,		{ 1.710938, 1, 1.601562, 0 } },
  { "MINOLTA", "DYNAX 7D", "5600K", 0,		{ 1.726562, 1, 1.585938, 0 } },
  { "MINOLTA", "DYNAX 7D", "5700K", 0,		{ 1.757812, 1, 1.558594, 0 } },
  { "MINOLTA", "DYNAX 7D", "5800K", 0,		{ 1.765625, 1, 1.535156, 0 } },
  { "MINOLTA", "DYNAX 7D", "5900K", 0,		{ 1.785156, 1, 1.515625, 0 } },
  { "MINOLTA", "DYNAX 7D", "6000K", 0,		{ 1.792969, 1, 1.500000, 0 } },
  { "MINOLTA", "DYNAX 7D", "6100K", 0,		{ 1.812500, 1, 1.484375, 0 } },
  { "MINOLTA", "DYNAX 7D", "6200K", 0,		{ 1.835938, 1, 1.468750, 0 } },
  { "MINOLTA", "DYNAX 7D", "6300K", 0,		{ 1.843750, 1, 1.453125, 0 } },
  { "MINOLTA", "DYNAX 7D", "6400K", 0,		{ 1.863281, 1, 1.437500, 0 } },
  { "MINOLTA", "DYNAX 7D", "6500K", 0,		{ 1.875000, 1, 1.421875, 0 } },
  { "MINOLTA", "DYNAX 7D", "6600K", 0,		{ 1.894531, 1, 1.414062, 0 } },
  { "MINOLTA", "DYNAX 7D", "6700K", 0,		{ 1.914062, 1, 1.398438, 0 } },
  { "MINOLTA", "DYNAX 7D", "6800K", 0,		{ 1.925781, 1, 1.382812, 0 } },
  { "MINOLTA", "DYNAX 7D", "6900K", 0,		{ 1.937500, 1, 1.375000, 0 } },
  { "MINOLTA", "DYNAX 7D", "7000K", 0,		{ 1.945312, 1, 1.363281, 0 } },
  { "MINOLTA", "DYNAX 7D", "7100K", 0,		{ 1.957031, 1, 1.347656, 0 } },
  { "MINOLTA", "DYNAX 7D", "7200K", 0,		{ 1.976562, 1, 1.339844, 0 } },
  { "MINOLTA", "DYNAX 7D", "7300K", 0,		{ 1.988281, 1, 1.324219, 0 } },
  { "MINOLTA", "DYNAX 7D", "7400K", 0,		{ 2.000000, 1, 1.316406, 0 } },
  { "MINOLTA", "DYNAX 7D", "7500K", 0,		{ 2.007812, 1, 1.304688, 0 } },
  { "MINOLTA", "DYNAX 7D", "7600K", 0,		{ 2.023438, 1, 1.304688, 0 } },
  { "MINOLTA", "DYNAX 7D", "7700K", 0,		{ 2.031250, 1, 1.289062, 0 } },
  { "MINOLTA", "DYNAX 7D", "7800K", 0,		{ 2.046875, 1, 1.277344, 0 } },
  { "MINOLTA", "DYNAX 7D", "7900K", 0,		{ 2.054688, 1, 1.277344, 0 } },
  { "MINOLTA", "DYNAX 7D", "8000K", 0,		{ 2.062500, 1, 1.261719, 0 } },
  { "MINOLTA", "DYNAX 7D", "8100K", 0,		{ 2.085938, 1, 1.253906, 0 } },
  { "MINOLTA", "DYNAX 7D", "8200K", 0,		{ 2.085938, 1, 1.250000, 0 } },
  { "MINOLTA", "DYNAX 7D", "8300K", 0,		{ 2.101562, 1, 1.234375, 0 } },
  { "MINOLTA", "DYNAX 7D", "8400K", 0,		{ 2.109375, 1, 1.234375, 0 } },
  { "MINOLTA", "DYNAX 7D", "8500K", 0,		{ 2.125000, 1, 1.226562, 0 } },
  { "MINOLTA", "DYNAX 7D", "8600K", 0,		{ 2.132812, 1, 1.214844, 0 } },
  { "MINOLTA", "DYNAX 7D", "8700K", 0,		{ 2.132812, 1, 1.207031, 0 } },
  { "MINOLTA", "DYNAX 7D", "8800K", 0,		{ 2.148438, 1, 1.207031, 0 } },
  { "MINOLTA", "DYNAX 7D", "8900K", 0,		{ 2.156250, 1, 1.195312, 0 } },
  { "MINOLTA", "DYNAX 7D", "9000K", 0,		{ 2.171875, 1, 1.187500, 0 } },
  { "MINOLTA", "DYNAX 7D", "9100K", 0,		{ 2.179688, 1, 1.187500, 0 } },
  { "MINOLTA", "DYNAX 7D", "9200K", 0,		{ 2.179688, 1, 1.183594, 0 } },
  { "MINOLTA", "DYNAX 7D", "9300K", 0,		{ 2.195312, 1, 1.175781, 0 } },
  { "MINOLTA", "DYNAX 7D", "9400K", 0,		{ 2.203125, 1, 1.171875, 0 } },
  { "MINOLTA", "DYNAX 7D", "9500K", 0,		{ 2.218750, 1, 1.164062, 0 } },
  { "MINOLTA", "DYNAX 7D", "9600K", 0,		{ 2.218750, 1, 1.156250, 0 } },
  { "MINOLTA", "DYNAX 7D", "9700K", 0,		{ 2.226562, 1, 1.152344, 0 } },
  { "MINOLTA", "DYNAX 7D", "9800K", 0,		{ 2.226562, 1, 1.144531, 0 } },
  { "MINOLTA", "DYNAX 7D", "9900K", 0,		{ 2.242188, 1, 1.144531, 0 } },

  { "NIKON", "D1", Incandescent, -3,		{ 1, 1.439891, 2.125769, 0 } },
  { "NIKON", "D1", Incandescent, 0,		{ 1, 1.582583, 2.556096, 0 } },
  { "NIKON", "D1", Incandescent, 3,		{ 1, 1.745033, 3.044175, 0 } },
  { "NIKON", "D1", Fluorescent, -3,		{ 1, 1.013461, 1.489820, 0 } },
  { "NIKON", "D1", Fluorescent, 0,		{ 1, 1.077710, 1.672660, 0 } },
  { "NIKON", "D1", Fluorescent, 3,		{ 1, 1.143167, 1.875227, 0 } },
  { "NIKON", "D1", DirectSunlight, -3,		{ 1.084705, 1.039344, 1, 0 } },
  { "NIKON", "D1", DirectSunlight, 0,		{ 1.000000, 1.000000, 1, 0 } },
  { "NIKON", "D1", DirectSunlight, 3,		{ 1, 1.049801, 1.109411, 0 } },
  { "NIKON", "D1", Flash, -3,			{ 1.317409, 1.116197, 1, 0 } },
  { "NIKON", "D1", Flash, 0,			{ 1.235772, 1.078231, 1, 0 } },
  { "NIKON", "D1", Flash, 3,			{ 1.100855, 1.016026, 1, 0 } },
  { "NIKON", "D1", Cloudy, -3,			{ 1.241160, 1.116197, 1, 0 } },
  { "NIKON", "D1", Cloudy, 0,			{ 1.162116, 1.078231, 1, 0 } },
  { "NIKON", "D1", Cloudy, 3,			{ 1.063923, 1.032573, 1, 0 } },
  { "NIKON", "D1", Shade, -3,			{ 1.361330, 1.191729, 1, 0 } },
  { "NIKON", "D1", Shade, 0,			{ 1.284963, 1.136201, 1, 0 } },
  { "NIKON", "D1", Shade, 3,			{ 1.205117, 1.096886, 1, 0 } },

  { "NIKON", "D1H", Incandescent, -3,		{ 1.503906, 1, 1.832031, 0 } },
  { "NIKON", "D1H", Incandescent, 0,		{ 1.363281, 1, 1.996094, 0 } },
  { "NIKON", "D1H", Incandescent, 3,		{ 1.246094, 1, 2.148438, 0 } },
  { "NIKON", "D1H", Fluorescent, -3,		{ 2.546875, 1, 1.175781, 0 } },
  { "NIKON", "D1H", Fluorescent, 0,		{ 1.925781, 1, 2.054688, 0 } },
  { "NIKON", "D1H", Fluorescent, 3,		{ 1.234375, 1, 2.171875, 0 } },
  { "NIKON", "D1H", DirectSunlight, -3,		{ 2.230469, 1, 1.187500, 0 } },
  { "NIKON", "D1H", DirectSunlight, 0,		{ 2.148438, 1, 1.246094, 0 } },
  { "NIKON", "D1H", DirectSunlight, 3,		{ 2.066406, 1, 1.316406, 0 } },
  { "NIKON", "D1H", Flash, -3,			{ 2.453125, 1, 1.117188, 0 } },
  { "NIKON", "D1H", Flash, 0,			{ 2.347656, 1, 1.140625, 0 } },
  { "NIKON", "D1H", Flash, 3,			{ 2.242188, 1, 1.164062, 0 } },
  { "NIKON", "D1H", Cloudy, -3,			{ 2.441406, 1, 1.046875, 0 } },
  { "NIKON", "D1H", Cloudy, 0,			{ 2.300781, 1, 1.128906, 0 } },
  { "NIKON", "D1H", Cloudy, 3,			{ 2.207031, 1, 1.199219, 0 } },
  { "NIKON", "D1H", Shade, -3,			{ 2.839844, 1, 1.000000, 0 } },
  { "NIKON", "D1H", Shade, 0,			{ 2.628906, 1, 1.011719, 0 } },
  { "NIKON", "D1H", Shade, 3,			{ 2.441406, 1, 1.046875, 0 } },

  { "NIKON", "D1X", Incandescent, -3,		{ 1.503906, 1, 1.832031, 0 } }, /*3250K*/
  { "NIKON", "D1X", Incandescent, -2,		{ 1.445312, 1, 1.890625, 0 } }, /*3150K*/
  { "NIKON", "D1X", Incandescent, -1,		{ 1.410156, 1, 1.937500, 0 } }, /*3100K*/
  { "NIKON", "D1X", Incandescent, 0,		{ 1.363281, 1, 1.996094, 0 } }, /*3000K*/
  { "NIKON", "D1X", Incandescent, 1,		{ 1.316406, 1, 2.042969, 0 } }, /*2900K*/
  { "NIKON", "D1X", Incandescent, 2,		{ 1.281250, 1, 2.101562, 0 } }, /*2800K*/
  { "NIKON", "D1X", Incandescent, 3,		{ 1.246094, 1, 2.148438, 0 } }, /*2700K*/
  { "NIKON", "D1X", Fluorescent, -3,		{ 2.546875, 1, 1.175781, 0 } }, /*7200K*/
  { "NIKON", "D1X", Fluorescent, -2,		{ 2.464844, 1, 1.210938, 0 } }, /*6500K*/
  { "NIKON", "D1X", Fluorescent, -1,		{ 2.160156, 1, 1.386719, 0 } }, /*5000K*/
  { "NIKON", "D1X", Fluorescent, 0,		{ 1.925781, 1, 2.054688, 0 } }, /*4200K*/
  { "NIKON", "D1X", Fluorescent, 1,		{ 1.703125, 1, 2.277344, 0 } }, /*3700K*/
  { "NIKON", "D1X", Fluorescent, 2,		{ 1.328125, 1, 2.394531, 0 } }, /*3000K*/
  { "NIKON", "D1X", Fluorescent, 3,		{ 1.234375, 1, 2.171875, 0 } }, /*2700K*/
  { "NIKON", "D1X", DirectSunlight, -3,		{ 2.230469, 1, 1.187500, 0 } }, /*5600K*/
  { "NIKON", "D1X", DirectSunlight, -2,		{ 2.207031, 1, 1.210938, 0 } }, /*5400K*/
  { "NIKON", "D1X", DirectSunlight, -1,		{ 2.171875, 1, 1.222656, 0 } }, /*5300K*/
  { "NIKON", "D1X", DirectSunlight, 0,		{ 2.148438, 1, 1.246094, 0 } }, /*5200K*/
  { "NIKON", "D1X", DirectSunlight, 1,		{ 2.113281, 1, 1.269531, 0 } }, /*5000K*/
  { "NIKON", "D1X", DirectSunlight, 2,		{ 2.089844, 1, 1.292969, 0 } }, /*4900K*/
  { "NIKON", "D1X", DirectSunlight, 3,		{ 2.066406, 1, 1.316406, 0 } }, /*4800K*/
  { "NIKON", "D1X", Flash, -3,			{ 2.453125, 1, 1.117188, 0 } }, /*6000K*/
  { "NIKON", "D1X", Flash, -2,			{ 2.417969, 1, 1.128906, 0 } }, /*5800K*/
  { "NIKON", "D1X", Flash, -1,			{ 2.382812, 1, 1.128906, 0 } }, /*5600K*/
  { "NIKON", "D1X", Flash, 0,			{ 2.347656, 1, 1.140625, 0 } }, /*5400K*/
  { "NIKON", "D1X", Flash, 1,			{ 2.312500, 1, 1.152344, 0 } }, /*5200K*/
  { "NIKON", "D1X", Flash, 2,			{ 2.277344, 1, 1.164062, 0 } }, /*5000K*/
  { "NIKON", "D1X", Flash, 3,			{ 2.242188, 1, 1.164062, 0 } }, /*4800K*/
  { "NIKON", "D1X", Cloudy, -3,			{ 2.441406, 1, 1.046875, 0 } }, /*6600K*/
  { "NIKON", "D1X", Cloudy, -2,			{ 2.394531, 1, 1.082031, 0 } }, /*6400K*/
  { "NIKON", "D1X", Cloudy, -1,			{ 2.347656, 1, 1.105469, 0 } }, /*6200K*/
  { "NIKON", "D1X", Cloudy, 0,			{ 2.300781, 1, 1.128906, 0 } }, /*6000K*/
  { "NIKON", "D1X", Cloudy, 1,			{ 2.253906, 1, 1.164062, 0 } }, /*5800K*/
  { "NIKON", "D1X", Cloudy, 2,			{ 2.230469, 1, 1.187500, 0 } }, /*5600K*/
  { "NIKON", "D1X", Cloudy, 3,			{ 2.207031, 1, 1.199219, 0 } }, /*5400K*/
  { "NIKON", "D1X", Shade, -3,			{ 2.839844, 1, 1.000000, 0 } }, /*9200K*/
  { "NIKON", "D1X", Shade, -2,			{ 2.769531, 1, 1.000000, 0 } }, /*8800K*/
  { "NIKON", "D1X", Shade, -1,			{ 2.699219, 1, 1.000000, 0 } }, /*8400K*/
  { "NIKON", "D1X", Shade, 0,			{ 2.628906, 1, 1.011719, 0 } }, /*8000K*/
  { "NIKON", "D1X", Shade, 1,			{ 2.558594, 1, 1.023438, 0 } }, /*7500K*/
  { "NIKON", "D1X", Shade, 2,			{ 2.500000, 1, 1.035156, 0 } }, /*7100K*/
  { "NIKON", "D1X", Shade, 3,			{ 2.441406, 1, 1.046875, 0 } }, /*6700K*/

  { "NIKON", "D100", Incandescent, -3,		{ 1.527344, 1, 2.539062, 0 } }, /*3300K*/
  { "NIKON", "D100", Incandescent, -2,		{ 1.476562, 1, 2.656250, 0 } }, /*3200K*/
  { "NIKON", "D100", Incandescent, -1,		{ 1.457031, 1, 2.707031, 0 } }, /*3100K*/
  { "NIKON", "D100", Incandescent, 0,		{ 1.406250, 1, 2.828125, 0 } }, /*3000K*/
  { "NIKON", "D100", Incandescent, 1,		{ 1.367188, 1, 2.937500, 0 } }, /*2900K*/
  { "NIKON", "D100", Incandescent, 2,		{ 1.316406, 1, 3.046875, 0 } }, /*2800K*/
  { "NIKON", "D100", Incandescent, 3,		{ 1.269531, 1, 3.167969, 0 } }, /*2700K*/
  { "NIKON", "D100", Fluorescent, -3,		{ 3.148438, 1, 1.847656, 0 } }, /*7200K*/
  { "NIKON", "D100", Fluorescent, -2,		{ 2.609375, 1, 1.617187, 0 } }, /*6500K*/
  { "NIKON", "D100", Fluorescent, -1,		{ 2.250000, 1, 2.039062, 0 } }, /*5000K*/
  { "NIKON", "D100", Fluorescent, 0,		{ 2.058594, 1, 2.617187, 0 } }, /*4200K*/
  { "NIKON", "D100", Fluorescent, 1,		{ 1.886719, 1, 2.726562, 0 } }, /*3700K*/
  { "NIKON", "D100", Fluorescent, 2,		{ 1.429688, 1, 3.359375, 0 } }, /*3000K*/
  { "NIKON", "D100", Fluorescent, 3,		{ 1.250000, 1, 2.699219, 0 } }, /*2700K*/
  { "NIKON", "D100", DirectSunlight, -3,	{ 2.386719, 1, 1.687500, 0 } }, /*5600K*/
  { "NIKON", "D100", DirectSunlight, -2,	{ 2.316406, 1, 1.726563, 0 } }, /*5400K*/
  { "NIKON", "D100", DirectSunlight, -1,	{ 2.296875, 1, 1.738281, 0 } }, /*5300K*/
  { "NIKON", "D100", DirectSunlight, 0,		{ 2.257812, 1, 1.757812, 0 } }, /*5200K*/
  { "NIKON", "D100", DirectSunlight, 1,		{ 2.187500, 1, 1.796875, 0 } }, /*5000K*/
  { "NIKON", "D100", DirectSunlight, 2,		{ 2.156250, 1, 1.816406, 0 } }, /*4900K*/
  { "NIKON", "D100", DirectSunlight, 3,		{ 2.117187, 1, 1.847656, 0 } }, /*4800K*/
  { "NIKON", "D100", Flash, -3,			{ 2.718750, 1, 1.519531, 0 } }, /*6000K*/
  { "NIKON", "D100", Flash, -2,			{ 2.656250, 1, 1.527344, 0 } }, /*5800K*/
  { "NIKON", "D100", Flash, -1,			{ 2.597656, 1, 1.527344, 0 } }, /*5600K*/
  { "NIKON", "D100", Flash, 0,			{ 2.539062, 1, 1.539062, 0 } }, /*5400K*/
  { "NIKON", "D100", Flash, 1,			{ 2.476562, 1, 1.539062, 0 } }, /*5200K*/
  { "NIKON", "D100", Flash, 2,			{ 2.437500, 1, 1.546875, 0 } }, /*5000K*/
  { "NIKON", "D100", Flash, 3,			{ 2.398438, 1, 1.546875, 0 } }, /*4800K*/
  { "NIKON", "D100", Cloudy, -3,		{ 2.648438, 1, 1.558594, 0 } }, /*6600K*/
  { "NIKON", "D100", Cloudy, -2,		{ 2.609375, 1, 1.578125, 0 } }, /*6400K*/
  { "NIKON", "D100", Cloudy, -1,		{ 2.558594, 1, 1.597656, 0 } }, /*6200K*/
  { "NIKON", "D100", Cloudy, 0,			{ 2.507813, 1, 1.628906, 0 } }, /*6000K*/
  { "NIKON", "D100", Cloudy, 1,			{ 2.449219, 1, 1.656250, 0 } }, /*5800K*/
  { "NIKON", "D100", Cloudy, 2,			{ 2.398438, 1, 1.687500, 0 } }, /*5600K*/
  { "NIKON", "D100", Cloudy, 3,			{ 2.316406, 1, 1.726563, 0 } }, /*5400K*/
  { "NIKON", "D100", Shade, -3,			{ 3.046875, 1, 1.386719, 0 } }, /*9200K*/
  { "NIKON", "D100", Shade, -2,			{ 3.000000, 1, 1.406250, 0 } }, /*8800K*/
  { "NIKON", "D100", Shade, -1,			{ 2.957031, 1, 1.417969, 0 } }, /*8400K*/
  { "NIKON", "D100", Shade, 0,			{ 2.906250, 1, 1.437500, 0 } }, /*8000K*/
  { "NIKON", "D100", Shade, 1,			{ 2.816406, 1, 1.476562, 0 } }, /*7500K*/
  { "NIKON", "D100", Shade, 2,			{ 2.750000, 1, 1.519531, 0 } }, /*7100K*/
  { "NIKON", "D100", Shade, 3,			{ 2.667969, 1, 1.546875, 0 } }, /*6700K*/

  /*
   * D2X with firmware A 1.01 and B 1.01
   */

  /* D2X basic + fine tune presets */
  { "NIKON", "D2X", Incandescent, -3,		{ 0.98462, 1, 2.61154, 0 } }, /*3300K*/
  { "NIKON", "D2X", Incandescent, -2,		{ 0.95880, 1, 2.71536, 0 } }, /*3200K*/
  { "NIKON", "D2X", Incandescent, -1,		{ 0.94465, 1, 2.77122, 0 } }, /*3100K*/
  { "NIKON", "D2X", Incandescent, 0,		{ 0.92086, 1, 2.89928, 0 } }, /*3000K*/
  { "NIKON", "D2X", Incandescent, 1,		{ 0.89510, 1, 3.03846, 0 } }, /*2900K*/
  { "NIKON", "D2X", Incandescent, 2,		{ 0.86486, 1, 3.17905, 0 } }, /*2800K*/
  { "NIKON", "D2X", Incandescent, 3,		{ 0.83388, 1, 3.34528, 0 } }, /*2700K*/
  { "NIKON", "D2X", Fluorescent, -3,		{ 2.01562, 1, 1.72266, 0 } }, /*7200K*/
  { "NIKON", "D2X", Fluorescent, -2,		{ 1.67969, 1, 1.42578, 0 } }, /*6500K*/
  { "NIKON", "D2X", Fluorescent, -1,		{ 1.42969, 1, 1.80078, 0 } }, /*5000K*/
  { "NIKON", "D2X", Fluorescent, 0,		{ 1.42969, 1, 2.62891, 0 } }, /*4200K*/
  { "NIKON", "D2X", Fluorescent, 1,		{ 1.13672, 1, 3.02734, 0 } }, /*3700K*/
  { "NIKON", "D2X", Fluorescent, 2,		{ 0.94118, 1, 2.68498, 0 } }, /*3000K*/
  { "NIKON", "D2X", Fluorescent, 3,		{ 0.83388, 1, 3.51140, 0 } }, /*2700K*/
  { "NIKON", "D2X", DirectSunlight, -3,		{ 1.61328, 1, 1.61328, 0 } }, /*5600K*/
  { "NIKON", "D2X", DirectSunlight, -2,		{ 1.57031, 1, 1.65234, 0 } }, /*5400K*/
  { "NIKON", "D2X", DirectSunlight, -1,		{ 1.55078, 1, 1.67578, 0 } }, /*5300K*/
  { "NIKON", "D2X", DirectSunlight, 0,		{ 1.52734, 1, 1.69531, 0 } }, /*5200K*/
  { "NIKON", "D2X", DirectSunlight, 1,		{ 1.48438, 1, 1.74609, 0 } }, /*5000K*/
  { "NIKON", "D2X", DirectSunlight, 2,		{ 1.45312, 1, 1.76953, 0 } }, /*4900K*/
  { "NIKON", "D2X", DirectSunlight, 3,		{ 1.42578, 1, 1.78906, 0 } }, /*4800K*/
  { "NIKON", "D2X", Flash, -3,			{ 1.71484, 1, 1.48438, 0 } }, /*6000K*/
  { "NIKON", "D2X", Flash, -2,			{ 1.67578, 1, 1.48438, 0 } }, /*5800K*/
  { "NIKON", "D2X", Flash, -1,			{ 1.66797, 1, 1.50781, 0 } }, /*5600K*/
  { "NIKON", "D2X", Flash, 0,			{ 1.66016, 1, 1.53125, 0 } }, /*5400K*/
  { "NIKON", "D2X", Flash, 1,			{ 1.64453, 1, 1.54297, 0 } }, /*5200K*/
  { "NIKON", "D2X", Flash, 2,			{ 1.62891, 1, 1.54297, 0 } }, /*5000K*/
  { "NIKON", "D2X", Flash, 3,			{ 1.57031, 1, 1.56641, 0 } }, /*4800K*/
  { "NIKON", "D2X", Cloudy, -3,			{ 1.79297, 1, 1.46875, 0 } }, /*6600K*/
  { "NIKON", "D2X", Cloudy, -2,			{ 1.76172, 1, 1.49219, 0 } }, /*6400K*/
  { "NIKON", "D2X", Cloudy, -1,			{ 1.72656, 1, 1.51953, 0 } }, /*6200K*/
  { "NIKON", "D2X", Cloudy, 0,			{ 1.69141, 1, 1.54688, 0 } }, /*6000K*/
  { "NIKON", "D2X", Cloudy, 1,			{ 1.65234, 1, 1.57812, 0 } }, /*5800K*/
  { "NIKON", "D2X", Cloudy, 2,			{ 1.61328, 1, 1.61328, 0 } }, /*5600K*/
  { "NIKON", "D2X", Cloudy, 3,			{ 1.57031, 1, 1.65234, 0 } }, /*5400K*/
  { "NIKON", "D2X", Shade, -3,			{ 2.10938, 1, 1.23828, 0 } }, /*9200K*/
  { "NIKON", "D2X", Shade, -2,			{ 2.07031, 1, 1.26562, 0 } }, /*8800K*/
  { "NIKON", "D2X", Shade, -1,			{ 2.02734, 1, 1.29688, 0 } }, /*8400K*/
  { "NIKON", "D2X", Shade, 0,			{ 1.98047, 1, 1.32812, 0 } }, /*8000K*/
  { "NIKON", "D2X", Shade, 1,			{ 1.92188, 1, 1.37109, 0 } }, /*7500K*/
  { "NIKON", "D2X", Shade, 2,			{ 1.86719, 1, 1.41406, 0 } }, /*7100K*/
  { "NIKON", "D2X", Shade, 3,			{ 1.80859, 1, 1.45703, 0 } }, /*6700K*/

  /* D2X Kelvin presets */
  { "NIKON", "D2X", "2500K", 0,			{ 0.74203, 1, 3.67536, 0 } },
  { "NIKON", "D2X", "2550K", 0,			{ 0.76877, 1, 3.58859, 0 } },
  { "NIKON", "D2X", "2650K", 0,			{ 0.81529, 1, 3.42675, 0 } },
  { "NIKON", "D2X", "2700K", 0,			{ 0.83388, 1, 3.34528, 0 } },
  { "NIKON", "D2X", "2800K", 0,			{ 0.86486, 1, 3.17905, 0 } },
  { "NIKON", "D2X", "2850K", 0,			{ 0.87973, 1, 3.10309, 0 } },
  { "NIKON", "D2X", "2950K", 0,			{ 0.90780, 1, 2.96454, 0 } },
  { "NIKON", "D2X", "3000K", 0,			{ 0.92086, 1, 2.89928, 0 } },
  { "NIKON", "D2X", "3100K", 0,			{ 0.94465, 1, 2.77122, 0 } },
  { "NIKON", "D2X", "3200K", 0,			{ 0.96970, 1, 2.65530, 0 } },
  { "NIKON", "D2X", "3300K", 0,			{ 0.99611, 1, 2.55642, 0 } },
  { "NIKON", "D2X", "3400K", 0,			{ 1.01953, 1, 2.46484, 0 } },
  { "NIKON", "D2X", "3600K", 0,			{ 1.07422, 1, 2.34375, 0 } },
  { "NIKON", "D2X", "3700K", 0,			{ 1.09766, 1, 2.26172, 0 } },
  { "NIKON", "D2X", "3800K", 0,			{ 1.12500, 1, 2.18750, 0 } },
  { "NIKON", "D2X", "4000K", 0,			{ 1.17969, 1, 2.06250, 0 } },
  { "NIKON", "D2X", "4200K", 0,			{ 1.24219, 1, 1.96094, 0 } },
  { "NIKON", "D2X", "4300K", 0,			{ 1.27344, 1, 1.91797, 0 } },
  { "NIKON", "D2X", "4500K", 0,			{ 1.33594, 1, 1.83984, 0 } },
  { "NIKON", "D2X", "4800K", 0,			{ 1.42578, 1, 1.78906, 0 } },
  { "NIKON", "D2X", "5000K", 0,			{ 1.48438, 1, 1.74609, 0 } },
  { "NIKON", "D2X", "5300K", 0,			{ 1.55078, 1, 1.67578, 0 } },
  { "NIKON", "D2X", "5600K", 0,			{ 1.61328, 1, 1.61328, 0 } },
  { "NIKON", "D2X", "5900K", 0,			{ 1.67188, 1, 1.56250, 0 } },
  { "NIKON", "D2X", "6300K", 0,			{ 1.74219, 1, 1.50391, 0 } },
  { "NIKON", "D2X", "6700K", 0,			{ 1.80859, 1, 1.45703, 0 } },
  { "NIKON", "D2X", "7100K", 0,			{ 1.86719, 1, 1.41406, 0 } },
  { "NIKON", "D2X", "7700K", 0,			{ 1.94531, 1, 1.35547, 0 } },
  { "NIKON", "D2X", "8300K", 0,			{ 2.01562, 1, 1.30469, 0 } },
  { "NIKON", "D2X", "9100K", 0,			{ 2.09766, 1, 1.24609, 0 } },
  { "NIKON", "D2X", "10000K", 0,		{ 2.17578, 1, 1.18359, 0 } },

  { "NIKON", "D3", Daylight, 0, 		{ 1.81640, 1, 1.35546, 0 } },
  { "NIKON", "D3", Flash, 0, 			{ 2.03906, 1, 1.17187, 0 } },
  { "NIKON", "D3", Cloudy, 0, 			{ 1.94921, 1, 1.22265, 0 } },
  { "NIKON", "D3", Shade, 0,			{ 2.24609, 1, 1.08593, 0 } },
  { "NIKON", "D3", Incandescent, 0, 		{ 1.16796, 1, 2.31640, 0 } },
  { "NIKON", "D3", Fluorescent, 0,		{ 1.68750, 1, 2.10156, 0 } },
  { "NIKON", "D3", "2500K", 0,			{ 1.00390, 1, 3.00000, 0 } },
  { "NIKON", "D3", "2560K", 0,			{ 1.02343, 1, 2.89062, 0 } },
  { "NIKON", "D3", "2630K", 0,			{ 1.04296, 1, 2.78125, 0 } },
  { "NIKON", "D3", "2700K", 0,			{ 1.06640, 1, 2.67968, 0 } },
  { "NIKON", "D3", "2780K", 0,			{ 1.09375, 1, 2.57812, 0 } },
  { "NIKON", "D3", "2860K", 0,			{ 1.11718, 1, 2.47656, 0 } },
  { "NIKON", "D3", "2940K", 0,			{ 1.14843, 1, 2.38281, 0 } },
  { "NIKON", "D3", "3000K", 0,			{ 1.16796, 1, 2.31640, 0 } },
  { "NIKON", "D3", "3030K", 0,			{ 1.17578, 1, 2.28906, 0 } },
  { "NIKON", "D3", "3130K", 0,			{ 1.20703, 1, 2.19921, 0 } },
  { "NIKON", "D3", "3230K", 0,			{ 1.24218, 1, 2.10937, 0 } },
  { "NIKON", "D3", "3330K", 0,			{ 1.27734, 1, 2.02343, 0 } },
  { "NIKON", "D3", "3450K", 0,			{ 1.31350, 1, 1.94140, 0 } },
  { "NIKON", "D3", "3570K", 0,			{ 1.35156, 1, 1.85937, 0 } },
  { "NIKON", "D3", "3700K", 0,			{ 1.39062, 1, 1.78125, 0 } },
  { "NIKON", "D3", "3850K", 0,			{ 1.43359, 1, 1.70703, 0 } },
  { "NIKON", "D3", "4000K", 0,			{ 1.47656, 1, 1.63281, 0 } },
  { "NIKON", "D3", "4170K", 0,			{ 1.52343, 1, 1.56640, 0 } },
  { "NIKON", "D3", "4350K", 0,			{ 1.60156, 1, 1.55078, 0 } },
  { "NIKON", "D3", "4550K", 0,			{ 1.66406, 1, 1.51562, 0 } },
  { "NIKON", "D3", "4760K", 0,			{ 1.72265, 1, 1.46093, 0 } },
  { "NIKON", "D3", "5000K", 0,			{ 1.77734, 1, 1.40234, 0 } },
  { "NIKON", "D3", "5200K", 0,			{ 1.81640, 1, 1.35546, 0 } },
  { "NIKON", "D3", "5260K", 0,			{ 1.82812, 1, 1.34375, 0 } },
  { "NIKON", "D3", "5560K", 0,			{ 1.87890, 1, 1.28515, 0 } },
  { "NIKON", "D3", "5880K", 0,			{ 1.93359, 1, 1.23437, 0 } },
  { "NIKON", "D3", "6000K", 0,			{ 1.94921, 1, 1.22265, 0 } },
  { "NIKON", "D3", "6250K", 0,			{ 1.99218, 1, 1.19140, 0 } },
  { "NIKON", "D3", "6400K", 0,			{ 2.03906, 1, 1.17187, 0 } },
  { "NIKON", "D3", "6670K", 0,			{ 2.05468, 1, 1.15625, 0 } },
  { "NIKON", "D3", "7140K", 0,			{ 2.12500, 1, 1.12500, 0 } },
  { "NIKON", "D3", "7690K", 0,			{ 2.20312, 1, 1.09765, 0 } },
  { "NIKON", "D3", "8000K", 0,			{ 2.24609, 1, 1.08593, 0 } },
  { "NIKON", "D3", "8330K", 0,			{ 2.28906, 1, 1.07031, 0 } },
  { "NIKON", "D3", "9090K", 0,			{ 2.38281, 1, 1.03515, 0 } },
  { "NIKON", "D3", "10000K", 0,			{ 2.48046, 1, 1.00000, 0 } },

  /* D200 basic + fine tune WB presets */
  { "NIKON", "D200", Incandescent, -2,		{ 1.199219, 1, 2.238281, 0 } },
  { "NIKON", "D200", Incandescent, -1,		{ 1.183594, 1, 2.289063, 0 } },
  { "NIKON", "D200", Incandescent, 0,		{ 1.148437, 1, 2.398438, 0 } },
  { "NIKON", "D200", Incandescent, 1,		{ 1.113281, 1, 2.519531, 0 } },
  { "NIKON", "D200", Incandescent, 2,		{ 1.074219, 1, 2.648438, 0 } },
  { "NIKON", "D200", Incandescent, 3,		{ 1.03125, 1, 2.804688, 0 } },
  { "NIKON", "D200", Fluorescent, -3,		{ 2.273438, 1, 1.410156, 0 } },
  { "NIKON", "D200", Fluorescent, -2,		{ 1.933594, 1, 1.152344, 0 } },
  { "NIKON", "D200", Fluorescent, -1,		{ 1.675781, 1, 1.453125, 0 } },
  { "NIKON", "D200", Fluorescent, 0,		{ 1.664062, 1, 2.148437, 0 } },
  { "NIKON", "D200", Fluorescent, 1,		{ 1.335937, 1, 2.453125, 0 } },
  { "NIKON", "D200", Fluorescent, 2,		{ 1.140625, 1, 2.214844, 0 } },
  { "NIKON", "D200", Fluorescent, 3,		{ 1.035156, 1, 2.410156, 0 } },
  { "NIKON", "D200", DirectSunlight, -3,	{ 1.863281, 1, 1.320312, 0 } },
  { "NIKON", "D200", DirectSunlight, -2,	{ 1.835938, 1, 1.355469, 0 } },
  { "NIKON", "D200", DirectSunlight, -1,	{ 1.820313, 1, 1.375, 0 } },
  { "NIKON", "D200", DirectSunlight, 0,		{ 1.804688, 1, 1.398437, 0 } },
  { "NIKON", "D200", DirectSunlight, 1,		{ 1.746094, 1, 1.425781, 0 } },
  { "NIKON", "D200", DirectSunlight, 2,		{ 1.714844, 1, 1.4375, 0 } },
  { "NIKON", "D200", DirectSunlight, 3,		{ 1.6875, 1, 1.449219, 0 } },
  { "NIKON", "D200", Flash, -3,			{ 2.066406, 1, 1.183594, 0 } },
  { "NIKON", "D200", Flash, -2,			{ 2.046875, 1, 1.191406, 0 } },
  { "NIKON", "D200", Flash, -1,			{ 2.027344, 1, 1.199219, 0 } },
  { "NIKON", "D200", Flash, 0,			{ 2.007813, 1, 1.171875, 0 } },
  { "NIKON", "D200", Flash, 1,			{ 1.984375, 1, 1.207031, 0 } },
  { "NIKON", "D200", Flash, 2,			{ 1.964844, 1, 1.214844, 0 } },
  { "NIKON", "D200", Flash, 3,			{ 1.945312, 1, 1.222656, 0 } },
  { "NIKON", "D200", Cloudy, -3,		{ 2.027344, 1, 1.210937, 0 } },
  { "NIKON", "D200", Cloudy, -2,		{ 1.992187, 1, 1.226562, 0 } },
  { "NIKON", "D200", Cloudy, -1,		{ 1.953125, 1, 1.242187, 0 } },
  { "NIKON", "D200", Cloudy, 0,			{ 1.917969, 1, 1.261719, 0 } },
  { "NIKON", "D200", Cloudy, 1,			{ 1.890625, 1, 1.285156, 0 } },
  { "NIKON", "D200", Cloudy, 2,			{ 1.863281, 1, 1.320312, 0 } },
  { "NIKON", "D200", Cloudy, 3,			{ 1.835938, 1, 1.355469, 0 } },
  { "NIKON", "D200", Shade, -3,			{ 2.378906, 1, 1.066406, 0 } },
  { "NIKON", "D200", Shade, -2,			{ 2.332031, 1, 1.085938, 0 } },
  { "NIKON", "D200", Shade, -1,			{ 2.289063, 1, 1.105469, 0 } },
  { "NIKON", "D200", Shade, 0,			{ 2.234375, 1, 1.125, 0 } },
  { "NIKON", "D200", Shade, 1,			{ 2.167969, 1, 1.152344, 0 } },
  { "NIKON", "D200", Shade, 2,			{ 2.105469, 1, 1.175781, 0 } },
  { "NIKON", "D200", Shade, 3,			{ 2.046875, 1, 1.199219, 0 } },

  /* D200 Kelvin presets */
  { "NIKON", "D200", "2500K", 0,		{ 1, 1, 3.121094, 0 } },
  { "NIKON", "D200", "2550K", 0,		{ 1, 1, 3.035156, 0 } },
  { "NIKON", "D200", "2650K", 0,		{ 1.011719, 1, 2.878906, 0 } },
  { "NIKON", "D200", "2700K", 0,		{ 1.031250, 1, 2.804688, 0 } },
  { "NIKON", "D200", "2800K", 0,		{ 1.074219, 1, 2.648438, 0 } },
  { "NIKON", "D200", "2850K", 0,		{ 1.089844, 1, 2.589844, 0 } },
  { "NIKON", "D200", "2950K", 0,		{ 1.132813, 1, 2.453125, 0 } },
  { "NIKON", "D200", "3000K", 0,		{ 1.148438, 1, 2.398438, 0 } },
  { "NIKON", "D200", "3100K", 0,		{ 1.183594, 1, 2.289063, 0 } },
  { "NIKON", "D200", "3200K", 0,		{ 1.218750, 1, 2.187500, 0 } },
  { "NIKON", "D200", "3300K", 0,		{ 1.250000, 1, 2.097656, 0 } },
  { "NIKON", "D200", "3400K", 0,		{ 1.281250, 1, 2.015625, 0 } },
  { "NIKON", "D200", "3600K", 0,		{ 1.343750, 1, 1.871094, 0 } },
  { "NIKON", "D200", "3700K", 0,		{ 1.371094, 1, 1.820313, 0 } },
  { "NIKON", "D200", "3800K", 0,		{ 1.402344, 1, 1.761719, 0 } },
  { "NIKON", "D200", "4000K", 0,		{ 1.457031, 1, 1.667969, 0 } },
  { "NIKON", "D200", "4200K", 0,		{ 1.511719, 1, 1.593750, 0 } },
  { "NIKON", "D200", "4300K", 0,		{ 1.535156, 1, 1.558594, 0 } },
  { "NIKON", "D200", "4500K", 0,		{ 1.589844, 1, 1.500000, 0 } },
  { "NIKON", "D200", "4800K", 0,		{ 1.687500, 1, 1.449219, 0 } },
  { "NIKON", "D200", "5000K", 0,		{ 1.746094, 1, 1.425781, 0 } },
  { "NIKON", "D200", "5300K", 0,		{ 1.820313, 1, 1.375000, 0 } },
  { "NIKON", "D200", "5600K", 0,		{ 1.863281, 1, 1.320313, 0 } },
  { "NIKON", "D200", "5900K", 0,		{ 1.902344, 1, 1.273438, 0 } },
  { "NIKON", "D200", "6300K", 0,		{ 1.972656, 1, 1.234375, 0 } },
  { "NIKON", "D200", "6700K", 0,		{ 2.046875, 1, 1.199219, 0 } },
  { "NIKON", "D200", "7100K", 0,		{ 2.105469, 1, 1.175781, 0 } },
  { "NIKON", "D200", "7700K", 0,		{ 2.191406, 1, 1.144531, 0 } },
  { "NIKON", "D200", "8300K", 0,		{ 2.277344, 1, 1.109375, 0 } },
  { "NIKON", "D200", "9300K", 0,		{ 2.367188, 1, 1.070313, 0 } },
  { "NIKON", "D200", "10000K", 0,		{ 2.453125, 1, 1.035156, 0 } },

  /* D300 basic + fine tune WB presets */
  { "NIKON", "D300", Incandescent, -6,        { 1.097656, 1, 1.898438, 0 } },
  { "NIKON", "D300", Incandescent, -5,        { 1.085938, 1, 1.929687, 0 } },
  { "NIKON", "D300", Incandescent, -4,        { 1.070313, 1, 1.964844, 0 } },
  { "NIKON", "D300", Incandescent, -3,        { 1.058594, 1, 2, 0 } },
  { "NIKON", "D300", Incandescent, -2,        { 1.042969, 1, 2.035156, 0 } },
  { "NIKON", "D300", Incandescent, -1,        { 1.03125, 1, 2.074219, 0 } },
  { "NIKON", "D300", Incandescent, 0,         { 1.019531, 1, 2.109375, 0 } },
  { "NIKON", "D300", Incandescent, 1,         { 1.007813, 1, 2.144531, 0 } },
  { "NIKON", "D300", Incandescent, 2,         { 1, 1, 2.183594, 0 } },
  { "NIKON", "D300", Incandescent, 3,         { 1, 1, 2.21875, 0 } },
  { "NIKON", "D300", Incandescent, 4,         { 1, 1, 2.257812, 0 } },
  { "NIKON", "D300", Incandescent, 5,         { 1, 1, 2.296875, 0 } },
  { "NIKON", "D300", Incandescent, 6,         { 1, 1, 2.335937, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, -6,         { 1.03125, 1, 2.101563, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, -5,         { 1.015625, 1, 2.136719, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, -4,         { 1.003906, 1, 2.167969, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, -3,         { 0.9882813, 1, 2.207031, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, -2,         { 0.9765625, 1, 2.242187, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, -1,         { 0.9609375, 1, 2.28125, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, 0,          { 0.9492188, 1, 2.320313, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, 1,          { 0.9492188, 1, 2.363281, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, 2,          { 0.9492188, 1, 2.410156, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, 3,          { 0.9492188, 1, 2.457031, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, 4,          { 0.9492188, 1, 2.503906, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, 5,          { 0.9492188, 1, 2.558594, 0 } },
  { "NIKON", "D300", SodiumVaporFluorescent, 6,          { 0.9492188, 1, 2.613281, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, -6,         { 1.128906, 1, 1.847656, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, -5,         { 1.113281, 1, 1.867187, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, -4,         { 1.097656, 1, 1.886719, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, -3,         { 1.085938, 1, 1.90625, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, -2,         { 1.070313, 1, 1.925781, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, -1,         { 1.058594, 1, 1.945312, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, 0,          { 1.046875, 1, 1.960937, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, 1,          { 1.035156, 1, 1.980469, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, 2,          { 1.023437, 1, 1.996094, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, 3,          { 1.007813, 1, 2.015625, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, 4,          { 1, 1, 2.03125, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, 5,          { 1, 1, 2.046875, 0 } },
  { "NIKON", "D300", WarmWhiteFluorescent, 6,          { 1, 1, 2.0625, 0 } },
  { "NIKON", "D300", WhiteFluorescent, -6,            { 1.453125, 1, 2.050781, 0 } },
  { "NIKON", "D300", WhiteFluorescent, -5,            { 1.414062, 1, 2.09375, 0 } },
  { "NIKON", "D300", WhiteFluorescent, -4,            { 1.371094, 1, 2.132813, 0 } },
  { "NIKON", "D300", WhiteFluorescent, -3,            { 1.328125, 1, 2.175781, 0 } },
  { "NIKON", "D300", WhiteFluorescent, -2,            { 1.285156, 1, 2.21875, 0 } },
  { "NIKON", "D300", WhiteFluorescent, -1,            { 1.238281, 1, 2.261719, 0 } },
  { "NIKON", "D300", WhiteFluorescent, 0,             { 1.191406, 1, 2.304688, 0 } },
  { "NIKON", "D300", WhiteFluorescent, 1,             { 1.140625, 1, 2.351563, 0 } },
  { "NIKON", "D300", WhiteFluorescent, 2,             { 1.089844, 1, 2.394531, 0 } },
  { "NIKON", "D300", WhiteFluorescent, 3,             { 1.039062, 1, 2.441406, 0 } },
  { "NIKON", "D300", WhiteFluorescent, 4,             { 1, 1, 2.488281, 0 } },
  { "NIKON", "D300", WhiteFluorescent, 5,             { 1, 1, 2.535156, 0 } },
  { "NIKON", "D300", WhiteFluorescent, 6,             { 1, 1, 2.582031, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, -6,         { 1.667969, 1, 1.800781, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, -5,         { 1.636719, 1, 1.835938, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, -4,         { 1.605469, 1, 1.875, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, -3,         { 1.574219, 1, 1.914062, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, -2,         { 1.539063, 1, 1.953125, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, -1,         { 1.503906, 1, 1.996094, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, 0,          { 1.46875, 1, 2.035156, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, 1,          { 1.429687, 1, 2.074219, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, 2,          { 1.386719, 1, 2.117188, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, 3,          { 1.347656, 1, 2.160156, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, 4,          { 1.304687, 1, 2.203125, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, 5,          { 1.257812, 1, 2.246094, 0 } },
  { "NIKON", "D300", CoolWhiteFluorescent, 6,          { 1.210937, 1, 2.289063, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, -6,        { 1.625, 1, 1.195313, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, -5,        { 1.601563, 1, 1.222656, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, -4,        { 1.582031, 1, 1.253906, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, -3,        { 1.558594, 1, 1.28125, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, -2,        { 1.535156, 1, 1.308594, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, -1,        { 1.515625, 1, 1.335937, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, 0,         { 1.492188, 1, 1.363281, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, 1,         { 1.472656, 1, 1.390625, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, 2,         { 1.453125, 1, 1.417969, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, 3,         { 1.433594, 1, 1.441406, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, 4,         { 1.410156, 1, 1.46875, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, 5,         { 1.390625, 1, 1.492188, 0 } },
  { "NIKON", "D300", DayWhiteFluorescent, 6,         { 1.375, 1, 1.519531, 0 } },
  { "NIKON", "D300", DaylightFluorescent, -6,         { 1.851563, 1, 1, 0 } },
  { "NIKON", "D300", DaylightFluorescent, -5,         { 1.824219, 1, 1, 0 } },
  { "NIKON", "D300", DaylightFluorescent, -4,         { 1.796875, 1, 1, 0 } },
  { "NIKON", "D300", DaylightFluorescent, -3,         { 1.773438, 1, 1.007813, 0 } },
  { "NIKON", "D300", DaylightFluorescent, -2,         { 1.75, 1, 1.039062, 0 } },
  { "NIKON", "D300", DaylightFluorescent, -1,         { 1.722656, 1, 1.070313, 0 } },
  { "NIKON", "D300", DaylightFluorescent, 0,          { 1.699219, 1, 1.101563, 0 } },
  { "NIKON", "D300", DaylightFluorescent, 1,          { 1.675781, 1, 1.128906, 0 } },
  { "NIKON", "D300", DaylightFluorescent, 2,          { 1.652344, 1, 1.160156, 0 } },
  { "NIKON", "D300", DaylightFluorescent, 3,          { 1.628906, 1, 1.1875, 0 } },
  { "NIKON", "D300", DaylightFluorescent, 4,          { 1.605469, 1, 1.21875, 0 } },
  { "NIKON", "D300", DaylightFluorescent, 5,          { 1.585938, 1, 1.246094, 0 } },
  { "NIKON", "D300", DaylightFluorescent, 6,          { 1.5625, 1, 1.273437, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, -6,        { 2.039063, 1, 1.15625, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, -5,        { 2.027344, 1, 1.183594, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, -4,        { 2.015625, 1, 1.210937, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, -3,        { 2.003906, 1, 1.238281, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, -2,        { 1.992187, 1, 1.269531, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, -1,        { 1.976563, 1, 1.300781, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, 0,         { 1.960937, 1, 1.328125, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, 1,         { 1.945312, 1, 1.359375, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, 2,         { 1.929687, 1, 1.390625, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, 3,         { 1.914062, 1, 1.421875, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, 4,         { 1.894531, 1, 1.457031, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, 5,         { 1.875, 1, 1.488281, 0 } },
  { "NIKON", "D300", HighTempMercuryVaporFluorescent, 6,         { 1.855469, 1, 1.523437, 0 } },
  { "NIKON", "D300", DirectSunlight, -6,     { 1.6875, 1, 1.167969, 0 } },
  { "NIKON", "D300", DirectSunlight, -5,     { 1.664062, 1, 1.1875, 0 } },
  { "NIKON", "D300", DirectSunlight, -4,     { 1.644531, 1, 1.207031, 0 } },
  { "NIKON", "D300", DirectSunlight, -3,     { 1.625, 1, 1.230469, 0 } },
  { "NIKON", "D300", DirectSunlight, -2,     { 1.601563, 1, 1.253906, 0 } },
  { "NIKON", "D300", DirectSunlight, -1,     { 1.582031, 1, 1.28125, 0 } },
  { "NIKON", "D300", DirectSunlight, 0,      { 1.5625, 1, 1.308594, 0 } },
  { "NIKON", "D300", DirectSunlight, 1,      { 1.542969, 1, 1.335937, 0 } },
  { "NIKON", "D300", DirectSunlight, 2,      { 1.523437, 1, 1.359375, 0 } },
  { "NIKON", "D300", DirectSunlight, 3,      { 1.503906, 1, 1.386719, 0 } },
  { "NIKON", "D300", DirectSunlight, 4,      { 1.480469, 1, 1.414062, 0 } },
  { "NIKON", "D300", DirectSunlight, 5,      { 1.457031, 1, 1.4375, 0 } },
  { "NIKON", "D300", DirectSunlight, 6,      { 1.429687, 1, 1.457031, 0 } },
  { "NIKON", "D300", Flash, -6,               { 1.910156, 1, 1.058594, 0 } },
  { "NIKON", "D300", Flash, -5,               { 1.863281, 1, 1.078125, 0 } },
  { "NIKON", "D300", Flash, -4,               { 1.820313, 1, 1.09375, 0 } },
  { "NIKON", "D300", Flash, -3,               { 1.78125, 1, 1.105469, 0 } },
  { "NIKON", "D300", Flash, -2,               { 1.746094, 1, 1.121094, 0 } },
  { "NIKON", "D300", Flash, -1,               { 1.714844, 1, 1.136719, 0 } },
  { "NIKON", "D300", Flash, 0,                { 1.6875, 1, 1.152344, 0 } },
  { "NIKON", "D300", Flash, 1,                { 1.660156, 1, 1.164062, 0 } },
  { "NIKON", "D300", Flash, 2,                { 1.636719, 1, 1.179687, 0 } },
  { "NIKON", "D300", Flash, 3,                { 1.613281, 1, 1.195313, 0 } },
  { "NIKON", "D300", Flash, 4,                { 1.59375, 1, 1.210937, 0 } },
  { "NIKON", "D300", Flash, 5,                { 1.574219, 1, 1.230469, 0 } },
  { "NIKON", "D300", Flash, 6,                { 1.554688, 1, 1.246094, 0 } },
  { "NIKON", "D300", Cloudy, -6,              { 1.820313, 1, 1.09375, 0 } },
  { "NIKON", "D300", Cloudy, -5,              { 1.789063, 1, 1.105469, 0 } },
  { "NIKON", "D300", Cloudy, -4,              { 1.761719, 1, 1.117188, 0 } },
  { "NIKON", "D300", Cloudy, -3,              { 1.734375, 1, 1.132813, 0 } },
  { "NIKON", "D300", Cloudy, -2,              { 1.710937, 1, 1.148437, 0 } },
  { "NIKON", "D300", Cloudy, -1,              { 1.6875, 1, 1.167969, 0 } },
  { "NIKON", "D300", Cloudy, 0,               { 1.664062, 1, 1.1875, 0 } },
  { "NIKON", "D300", Cloudy, 1,               { 1.644531, 1, 1.207031, 0 } },
  { "NIKON", "D300", Cloudy, 2,               { 1.625, 1, 1.230469, 0 } },
  { "NIKON", "D300", Cloudy, 3,               { 1.601563, 1, 1.253906, 0 } },
  { "NIKON", "D300", Cloudy, 4,               { 1.582031, 1, 1.28125, 0 } },
  { "NIKON", "D300", Cloudy, 5,               { 1.5625, 1, 1.308594, 0 } },
  { "NIKON", "D300", Cloudy, 6,               { 1.542969, 1, 1.335937, 0 } },
  { "NIKON", "D300", Shade, -6,               { 2.15625, 1, 1, 0 } },
  { "NIKON", "D300", Shade, -5,               { 2.109375, 1, 1, 0 } },
  { "NIKON", "D300", Shade, -4,               { 2.0625, 1, 1.011719, 0 } },
  { "NIKON", "D300", Shade, -3,               { 2.019531, 1, 1.027344, 0 } },
  { "NIKON", "D300", Shade, -2,               { 1.976563, 1, 1.042969, 0 } },
  { "NIKON", "D300", Shade, -1,               { 1.9375, 1, 1.054688, 0 } },
  { "NIKON", "D300", Shade, 0,                { 1.902344, 1, 1.066406, 0 } },
  { "NIKON", "D300", Shade, 1,                { 1.867187, 1, 1.074219, 0 } },
  { "NIKON", "D300", Shade, 2,                { 1.832031, 1, 1.085938, 0 } },
  { "NIKON", "D300", Shade, 3,                { 1.804688, 1, 1.097656, 0 } },
  { "NIKON", "D300", Shade, 4,                { 1.773438, 1, 1.113281, 0 } },
  { "NIKON", "D300", Shade, 5,                { 1.746094, 1, 1.125, 0 } },
  { "NIKON", "D300", Shade, 6,                { 1.722656, 1, 1.140625, 0 } },

  /* D300 Kelvin presets */
  { "NIKON", "D300", "2500K", 0,                { 1, 1, 2.632813, 0 } },
  { "NIKON", "D300", "2560K", 0,                { 1, 1, 2.550781, 0 } },
  { "NIKON", "D300", "2630K", 0,                { 1, 1, 2.46875, 0 } },
  { "NIKON", "D300", "2700K", 0,                { 1, 1, 2.390625, 0 } },
  { "NIKON", "D300", "2780K", 0,                { 1, 1, 2.3125, 0 } },
  { "NIKON", "D300", "2860K", 0,                { 1, 1, 2.234375, 0 } },
  { "NIKON", "D300", "2940K", 0,                { 1.003906, 1, 2.160156, 0 } },
  { "NIKON", "D300", "3030K", 0,                { 1.027344, 1, 2.085938, 0 } },
  { "NIKON", "D300", "3130K", 0,                { 1.050781, 1, 2.015625, 0 } },
  { "NIKON", "D300", "3230K", 0,                { 1.078125, 1, 1.945312, 0 } },
  { "NIKON", "D300", "3330K", 0,                { 1.109375, 1, 1.875, 0 } },
  { "NIKON", "D300", "3450K", 0,                { 1.136719, 1, 1.808594, 0 } },
  { "NIKON", "D300", "3570K", 0,                { 1.167969, 1, 1.742187, 0 } },
  { "NIKON", "D300", "3700K", 0,                { 1.203125, 1, 1.679688, 0 } },
  { "NIKON", "D300", "3850K", 0,                { 1.238281, 1, 1.617188, 0 } },
  { "NIKON", "D300", "4000K", 0,                { 1.277344, 1, 1.554688, 0 } },
  { "NIKON", "D300", "4170K", 0,                { 1.316406, 1, 1.5, 0 } },
  { "NIKON", "D300", "4350K", 0,                { 1.386719, 1, 1.484375, 0 } },
  { "NIKON", "D300", "4550K", 0,                { 1.441406, 1, 1.449219, 0 } },
  { "NIKON", "D300", "4760K", 0,                { 1.488281, 1, 1.402344, 0 } },
  { "NIKON", "D300", "5000K", 0,                { 1.53125, 1, 1.351563, 0 } },
  { "NIKON", "D300", "5260K", 0,                { 1.570313, 1, 1.296875, 0 } },
  { "NIKON", "D300", "5560K", 0,                { 1.613281, 1, 1.246094, 0 } },
  { "NIKON", "D300", "5880K", 0,                { 1.652344, 1, 1.199219, 0 } },
  { "NIKON", "D300", "6250K", 0,                { 1.695313, 1, 1.160156, 0 } },
  { "NIKON", "D300", "6670K", 0,                { 1.746094, 1, 1.125, 0 } },
  { "NIKON", "D300", "7140K", 0,                { 1.804688, 1, 1.097656, 0 } },
  { "NIKON", "D300", "7690K", 0,                { 1.867187, 1, 1.074219, 0 } },
  { "NIKON", "D300", "8330K", 0,                { 1.9375, 1, 1.054688, 0 } },
  { "NIKON", "D300", "9090K", 0,                { 2.019531, 1, 1.027344, 0 } },
  { "NIKON", "D300", "10000K", 0,               { 2.109375, 1, 1, 0 } },


  { "NIKON", "D40", Incandescent, -3,		{ 1.492188, 1, 2.164063, 0 } },
  { "NIKON", "D40", Incandescent, -2,		{ 1.437500, 1, 2.367188, 0 } },
  { "NIKON", "D40", Incandescent, -1,		{ 1.417969, 1, 2.414062, 0 } },
  { "NIKON", "D40", Incandescent, 0,		{ 1.375000, 1, 2.511719, 0 } },
  { "NIKON", "D40", Incandescent, 1,		{ 1.324219, 1, 2.628906, 0 } },
  { "NIKON", "D40", Incandescent, 2,		{ 1.277344, 1, 2.753906, 0 } },
  { "NIKON", "D40", Incandescent, 3,		{ 1.222656, 1, 2.914063, 0 } },
  { "NIKON", "D40", Fluorescent, -3,		{ 2.738281, 1, 1.492188, 0 } },
  { "NIKON", "D40", Fluorescent, -2,		{ 2.417969, 1, 1.246094, 0 } },
  { "NIKON", "D40", Fluorescent, -1,		{ 2.093750, 1, 1.570312, 0 } },
  { "NIKON", "D40", Fluorescent, 0,		{ 2.007813, 1, 2.269531, 0 } },
  { "NIKON", "D40", Fluorescent, 1,		{ 1.613281, 1, 2.593750, 0 } },
  { "NIKON", "D40", Fluorescent, 2,		{ 1.394531, 1, 2.343750, 0 } },
  { "NIKON", "D40", Fluorescent, 3,		{ 1.210938, 1, 2.621094, 0 } },
  { "NIKON", "D40", DirectSunlight, -3,		{ 2.328125, 1, 1.371094, 0 } },
  { "NIKON", "D40", DirectSunlight, -2,		{ 2.269531, 1, 1.394531, 0 } },
  { "NIKON", "D40", DirectSunlight, -1,		{ 2.230469, 1, 1.410156, 0 } },
  { "NIKON", "D40", DirectSunlight, 0,		{ 2.195313, 1, 1.421875, 0 } },
  { "NIKON", "D40", DirectSunlight, 1,		{ 2.113281, 1, 1.445312, 0 } },
  { "NIKON", "D40", DirectSunlight, 2,		{ 2.070312, 1, 1.453125, 0 } },
  { "NIKON", "D40", DirectSunlight, 3,		{ 2.039063, 1, 1.457031, 0 } },
  { "NIKON", "D40", Flash, -3,			{ 2.667969, 1, 1.214844, 0 } },
  { "NIKON", "D40", Flash, -2,			{ 2.605469, 1, 1.234375, 0 } },
  { "NIKON", "D40", Flash, -1,			{ 2.539062, 1, 1.257812, 0 } },
  { "NIKON", "D40", Flash, 0,			{ 2.464844, 1, 1.281250, 0 } },
  { "NIKON", "D40", Flash, 1,			{ 2.390625, 1, 1.312500, 0 } },
  { "NIKON", "D40", Flash, 2,			{ 2.308594, 1, 1.343750, 0 } },
  { "NIKON", "D40", Flash, 3,			{ 2.222656, 1, 1.386719, 0 } },
  { "NIKON", "D40", Cloudy, -3,			{ 2.570313, 1, 1.246094, 0 } },
  { "NIKON", "D40", Cloudy, -2,			{ 2.523438, 1, 1.269531, 0 } },
  { "NIKON", "D40", Cloudy, -1,			{ 2.476562, 1, 1.296875, 0 } },
  { "NIKON", "D40", Cloudy, 0,			{ 2.429688, 1, 1.320313, 0 } },
  { "NIKON", "D40", Cloudy, 1,			{ 2.382812, 1, 1.343750, 0 } },
  { "NIKON", "D40", Cloudy, 2,			{ 2.328125, 1, 1.371094, 0 } },
  { "NIKON", "D40", Cloudy, 3,			{ 2.269531, 1, 1.394531, 0 } },
  { "NIKON", "D40", Shade, -3,			{ 2.957031, 1, 1.054688, 0 } },
  { "NIKON", "D40", Shade, -2,			{ 2.921875, 1, 1.074219, 0 } },
  { "NIKON", "D40", Shade, -1,			{ 2.878906, 1, 1.097656, 0 } },
  { "NIKON", "D40", Shade, 0,			{ 2.820313, 1, 1.125000, 0 } },
  { "NIKON", "D40", Shade, 1,			{ 2.746094, 1, 1.160156, 0 } },
  { "NIKON", "D40", Shade, 2,			{ 2.671875, 1, 1.195312, 0 } },
  { "NIKON", "D40", Shade, 3,			{ 2.597656, 1, 1.234375, 0 } },

  { "NIKON", "D40X", Incandescent, -3,		{ 1.234375, 1, 2.140625, 0 } },
  { "NIKON", "D40X", Incandescent, 0,		{ 1.148438, 1, 2.386719, 0 } },
  { "NIKON", "D40X", Incandescent, 3,		{ 1.039062, 1, 2.734375, 0 } },
  { "NIKON", "D40X", Fluorescent, -3,		{ 2.296875, 1, 1.398438, 0 } },
  { "NIKON", "D40X", Fluorescent, 0,		{ 1.683594, 1, 2.117188, 0 } },
  { "NIKON", "D40X", Fluorescent, 3,		{ 1.000000, 1, 2.527344, 0 } },
  { "NIKON", "D40X", DirectSunlight, -3,	{ 1.882812, 1, 1.300781, 0 } },
  { "NIKON", "D40X", DirectSunlight, 0,		{ 1.792969, 1, 1.371094, 0 } },
  { "NIKON", "D40X", DirectSunlight, 3,		{ 1.695312, 1, 1.437500, 0 } },
  { "NIKON", "D40X", Flash, -3,			{ 2.089844, 1, 1.132812, 0 } },
  { "NIKON", "D40X", Flash, 0,			{ 1.949219, 1, 1.187500, 0 } },
  { "NIKON", "D40X", Flash, 3,			{ 1.769531, 1, 1.269531, 0 } },
  { "NIKON", "D40X", Cloudy, -3,		{ 2.070312, 1, 1.191406, 0 } },
  { "NIKON", "D40X", Cloudy, 0,			{ 1.960938, 1, 1.253906, 0 } },
  { "NIKON", "D40X", Cloudy, 3,			{ 1.835938, 1, 1.332031, 0 } },
  { "NIKON", "D40X", Shade, -3,			{ 2.414062, 1, 1.042969, 0 } },
  { "NIKON", "D40X", Shade, 0,			{ 2.277344, 1, 1.089844, 0 } },
  { "NIKON", "D40X", Shade, 3,			{ 2.085938, 1, 1.183594, 0 } },

  { "NIKON", "D50", Incandescent, 0,		{ 1.328125, 1, 2.500000, 0 } },
  { "NIKON", "D50", Fluorescent, 0,		{ 1.945312, 1, 2.191406, 0 } },
  { "NIKON", "D50", DirectSunlight, 0,		{ 2.140625, 1, 1.398438, 0 } },
  { "NIKON", "D50", Flash, 0,			{ 2.398438, 1, 1.339844, 0 } },
  { "NIKON", "D50", Shade, 0,			{ 2.746094, 1, 1.156250, 0 } },

  { "NIKON", "D60", DirectSunlight, 0,		{ 1.792969, 1, 1.371094, 0 } },
  { "NIKON", "D60", Flash, 0,			{ 2.007813, 1, 1.187500, 0 } },
  { "NIKON", "D60", Cloudy, 0,			{ 1.960937, 1, 1.253906, 0 } },
  { "NIKON", "D60", Shade, 0,			{ 2.277344, 1, 1.089844, 0 } },
  { "NIKON", "D60", Incandescent, 0,		{ 1.148437, 1, 2.382812, 0 } },
  { "NIKON", "D60", SodiumVaporFluorescent, 0,	{ 1.035156, 1, 2.468750, 0 } },
  { "NIKON", "D60", WarmWhiteFluorescent, 0,	{ 1.136719, 1, 2.167969, 0 } },
  { "NIKON", "D60", WhiteFluorescent, 0,	{ 1.343750, 1, 2.480469, 0 } },
  { "NIKON", "D60", CoolWhiteFluorescent, 0,	{ 1.683594, 1, 2.117187, 0 } },
  { "NIKON", "D60", DayWhiteFluorescent, 0,	{ 1.679688, 1, 1.414063, 0 } },
  { "NIKON", "D60", DaylightFluorescent, 0,	{ 1.953125, 1, 1.121094, 0 } },
  { "NIKON", "D60", HighTempMercuryVaporFluorescent, 0, { 2.296875, 1, 1.398438, 0 } },

  { "NIKON", "D70", Incandescent, -3,		{ 1.429688, 1, 2.539062, 0 } },
  { "NIKON", "D70", Incandescent, 0,		{ 1.343750, 1, 2.816406, 0 } }, /*3000K*/
  { "NIKON", "D70", Incandescent, 3,		{ 1.253906, 1, 3.250000, 0 } },
  { "NIKON", "D70", Fluorescent, -3,		{ 2.734375, 1, 1.621094, 0 } },
  { "NIKON", "D70", Fluorescent, 0,		{ 1.964844, 1, 2.476563, 0 } }, /*4200K*/
  { "NIKON", "D70", Fluorescent, 3,		{ 1.312500, 1, 2.562500, 0 } },
  { "NIKON", "D70", DirectSunlight, -3,		{ 2.156250, 1, 1.523438, 0 } },
  { "NIKON", "D70", DirectSunlight, 0,		{ 2.062500, 1, 1.597656, 0 } }, /*5200K*/
  { "NIKON", "D70", DirectSunlight, 3,		{ 1.953125, 1, 1.695312, 0 } },
  { "NIKON", "D70", Flash, -3,			{ 2.578125, 1, 1.476562, 0 } },
  { "NIKON", "D70", Flash, 0,			{ 2.441406, 1, 1.500000, 0 } }, /*5400K*/
  { "NIKON", "D70", Flash, 3,			{ 2.378906, 1, 1.523438, 0 } },
  { "NIKON", "D70", Cloudy, -3,			{ 2.375000, 1, 1.386719, 0 } },
  { "NIKON", "D70", Cloudy, 0,			{ 2.257813, 1, 1.457031, 0 } }, /*6000K*/
  { "NIKON", "D70", Cloudy, 3,			{ 2.109375, 1, 1.562500, 0 } },
  { "NIKON", "D70", Shade, -3,			{ 2.757812, 1, 1.226562, 0 } },
  { "NIKON", "D70", Shade, 0,			{ 2.613281, 1, 1.277344, 0 } }, /*8000K*/
  { "NIKON", "D70", Shade, 3,			{ 2.394531, 1, 1.375000, 0 } },

  { "NIKON", "D70s", Incandescent, -3,		{ 1.429688, 1, 2.539062, 0 } },
  { "NIKON", "D70s", Incandescent, 0,		{ 1.343750, 1, 2.816406, 0 } }, /*3000K*/
  { "NIKON", "D70s", Incandescent, 3,		{ 1.253906, 1, 3.250000, 0 } },
  { "NIKON", "D70s", Fluorescent, -3,		{ 2.734375, 1, 1.621094, 0 } },
  { "NIKON", "D70s", Fluorescent, 0,		{ 1.964844, 1, 2.476563, 0 } }, /*4200K*/
  { "NIKON", "D70s", Fluorescent, 3,		{ 1.312500, 1, 2.562500, 0 } },
  { "NIKON", "D70s", DirectSunlight, -3,	{ 2.156250, 1, 1.523438, 0 } },
  { "NIKON", "D70s", DirectSunlight, 0,		{ 2.062500, 1, 1.597656, 0 } }, /*5200K*/
  { "NIKON", "D70s", DirectSunlight, 3,		{ 1.953125, 1, 1.695312, 0 } },
  { "NIKON", "D70s", Flash, -3,			{ 2.578125, 1, 1.476562, 0 } },
  { "NIKON", "D70s", Flash, 0,			{ 2.441406, 1, 1.500000, 0 } }, /*5400K*/
  { "NIKON", "D70s", Flash, 3,			{ 2.378906, 1, 1.523438, 0 } },
  { "NIKON", "D70s", Cloudy, -3,		{ 2.375000, 1, 1.386719, 0 } },
  { "NIKON", "D70s", Cloudy, 0,			{ 2.257813, 1, 1.457031, 0 } }, /*6000K*/
  { "NIKON", "D70s", Cloudy, 3,			{ 2.109375, 1, 1.562500, 0 } },
  { "NIKON", "D70s", Shade, -3,			{ 2.757812, 1, 1.226562, 0 } },
  { "NIKON", "D70s", Shade, 0,			{ 2.613281, 1, 1.277344, 0 } }, /*8000K*/
  { "NIKON", "D70s", Shade, 3,			{ 2.394531, 1, 1.375000, 0 } },

  { "NIKON", "D80", Incandescent, -3,		{ 1.234375, 1, 2.140625, 0 } },
  { "NIKON", "D80", Incandescent, 0,		{ 1.148438, 1, 2.386719, 0 } },
  { "NIKON", "D80", Incandescent, 3,		{ 1.039062, 1, 2.734375, 0 } },
  { "NIKON", "D80", Fluorescent, -3,		{ 2.296875, 1, 1.398438, 0 } },
  { "NIKON", "D80", Fluorescent, 0,		{ 1.683594, 1, 2.117188, 0 } },
  { "NIKON", "D80", Fluorescent, 3,		{ 1.000000, 1, 2.527344, 0 } },
  { "NIKON", "D80", Daylight, -3,		{ 1.882812, 1, 1.300781, 0 } },
  { "NIKON", "D80", Daylight, 0,		{ 1.792969, 1, 1.371094, 0 } },
  { "NIKON", "D80", Daylight, 3,		{ 1.695312, 1, 1.437500, 0 } },
  { "NIKON", "D80", Flash, -3,			{ 2.070312, 1, 1.144531, 0 } },
  { "NIKON", "D80", Flash, 0,			{ 2.007812, 1, 1.242188, 0 } },
  { "NIKON", "D80", Flash, 3,			{ 1.972656, 1, 1.156250, 0 } },
  { "NIKON", "D80", Cloudy, -3,			{ 2.070312, 1, 1.191406, 0 } },
  { "NIKON", "D80", Cloudy, 0,			{ 1.960938, 1, 1.253906, 0 } },
  { "NIKON", "D80", Cloudy, 3,			{ 1.835938, 1, 1.332031, 0 } },
  { "NIKON", "D80", Shade, -3,			{ 2.414062, 1, 1.042969, 0 } },
  { "NIKON", "D80", Shade, 0,			{ 2.277344, 1, 1.089844, 0 } },
  { "NIKON", "D80", Shade, 3,			{ 2.085938, 1, 1.183594, 0 } },
  { "NIKON", "D80", "4300K", 0,			{ 1.562500, 1, 1.523438, 0 } },
  { "NIKON", "D80", "5000K", 0,			{ 1.746094, 1, 1.410156, 0 } },
  { "NIKON", "D80", "5900K", 0,			{ 1.941406, 1, 1.265625, 0 } },

  { "NIKON", "E5400", Daylight, -3,		{ 2.046875, 1, 1.449219, 0 } },
  { "NIKON", "E5400", Daylight, 0,		{ 1.800781, 1, 1.636719, 0 } },
  { "NIKON", "E5400", Daylight, 3,		{ 1.539062, 1, 1.820312, 0 } },
  { "NIKON", "E5400", Incandescent, -3,		{ 1.218750, 1, 2.656250, 0 } },
  { "NIKON", "E5400", Incandescent, 0,		{ 1.218750, 1, 2.656250, 0 } },
  { "NIKON", "E5400", Incandescent, 3,		{ 1.382812, 1, 2.351562, 0 } },
  { "NIKON", "E5400", Fluorescent, -3,		{ 1.703125, 1, 2.460938, 0 } },
  { "NIKON", "E5400", Fluorescent, 0,		{ 1.218750, 1, 2.656250, 0 } },
  { "NIKON", "E5400", Fluorescent, 3,		{ 1.953125, 1, 1.906250, 0 } },
  { "NIKON", "E5400", Cloudy, -3,		{ 1.703125, 1, 2.460938, 0 } },
  { "NIKON", "E5400", Cloudy, 0,		{ 1.996094, 1, 1.421875, 0 } },
  { "NIKON", "E5400", Cloudy, 3,		{ 2.265625, 1, 1.261719, 0 } },
  { "NIKON", "E5400", Flash, -3,		{ 2.792969, 1, 1.152344, 0 } },
  { "NIKON", "E5400", Flash, 0,			{ 2.328125, 1, 1.386719, 0 } },
  { "NIKON", "E5400", Flash, 3,			{ 2.328125, 1, 1.386719, 0 } },
  { "NIKON", "E5400", Shade, -3,		{ 2.722656, 1, 1.011719, 0 } },
  { "NIKON", "E5400", Shade, 0,			{ 2.269531, 1, 1.218750, 0 } },
  { "NIKON", "E5400", Shade, 3,			{ 2.269531, 1, 1.218750, 0 } },

  { "NIKON", "E8700", Daylight, 0,		{ 1.968750, 1, 1.582031, 0 } },
  { "NIKON", "E8700", Incandescent, 0,		{ 1.265625, 1, 2.765625, 0 } },
  { "NIKON", "E8700", Fluorescent, 0,		{ 1.863281, 1, 2.304688, 0 } },
  { "NIKON", "E8700", Cloudy, 0,		{ 2.218750, 1, 1.359375, 0 } },
  { "NIKON", "E8700", Flash, 0,			{ 2.535156, 1, 1.273438, 0 } },
  { "NIKON", "E8700", Shade, 0,			{ 2.527344, 1, 1.175781, 0 } },

  { "OLYMPUS", "C5050Z", Shade, -7,		{ 3.887324, 1.201878, 1, 0 } },
  { "OLYMPUS", "C5050Z", Shade, 0,		{ 1.757812, 1, 1.437500, 0 } },
  { "OLYMPUS", "C5050Z", Shade, 7,		{ 1.019531, 1, 2.140625, 0 } },
  { "OLYMPUS", "C5050Z", Cloudy, -7,		{ 3.255507, 1.127753, 1, 0 } },
  { "OLYMPUS", "C5050Z", Cloudy, 0,		{ 1.570312, 1, 1.531250, 0 } },
  { "OLYMPUS", "C5050Z", Cloudy, 7,		{ 1, 1.098712, 2.506438, 0 } },
  { "OLYMPUS", "C5050Z", Daylight, -7,		{ 2.892116, 1.062241, 1, 0 } },
  { "OLYMPUS", "C5050Z", Daylight, 0,		{ 1.480469, 1, 1.628906, 0 } },
  { "OLYMPUS", "C5050Z", Daylight, 7,		{ 1, 1.168950, 2.835616, 0 } },
  { "OLYMPUS", "C5050Z", EveningSun, -7,	{ 3.072649, 1.094017, 1, 0 } },
  { "OLYMPUS", "C5050Z", EveningSun, 0,		{ 1.527344, 1, 1.578125, 0 } },
  { "OLYMPUS", "C5050Z", EveningSun, 7,		{ 1, 1.132743, 2.659292, 0 } },
  { "OLYMPUS", "C5050Z", DaylightFluorescent, -7, { 3.321267, 1.158371, 1, 0 } }, /*6700K*/
  { "OLYMPUS", "C5050Z", DaylightFluorescent, 0, { 1.558594, 1, 1.492188, 0 } }, /*6700K*/
  { "OLYMPUS", "C5050Z", DaylightFluorescent, 7, { 1, 1.108225, 2.463203, 0 } }, /*6700K*/
  { "OLYMPUS", "C5050Z", NeutralFluorescent, -7, { 2.606426, 1.028112, 1, 0 } }, /*5000K*/
  { "OLYMPUS", "C5050Z", NeutralFluorescent, 0,	{ 1.378906, 1, 1.679688, 0 } }, /*5000K*/
  { "OLYMPUS", "C5050Z", NeutralFluorescent, 7,	{ 1, 1.254902, 3.137255, 0 } }, /*5000K*/
  { "OLYMPUS", "C5050Z", CoolWhiteFluorescent, -7, { 2.519531, 1, 1.281250, 0 } }, /*4200K*/
  { "OLYMPUS", "C5050Z", CoolWhiteFluorescent, 0, { 1.371094, 1, 2.210938, 0 } }, /*4200K*/
  { "OLYMPUS", "C5050Z", CoolWhiteFluorescent, 7, { 1, 1.261084, 4.152709, 0 } }, /*4200K*/
  { "OLYMPUS", "C5050Z", WhiteFluorescent, -7,	{ 1.707031, 1, 1.699219, 0 } }, /*3500K*/
  { "OLYMPUS", "C5050Z", WhiteFluorescent, 0,	{ 1, 1.075630, 3.151261, 0 } }, /*3500K*/
  { "OLYMPUS", "C5050Z", WhiteFluorescent, 7,	{ 1, 1.855072, 8.094203, 0 } }, /*3500K*/
  { "OLYMPUS", "C5050Z", Incandescent, -7,	{ 1.679688, 1, 1.652344, 0 } }, /*3000K*/
  { "OLYMPUS", "C5050Z", Incandescent, 0,	{ 1, 1.094017, 3.123932, 0 } }, /*3000K*/
  { "OLYMPUS", "C5050Z", Incandescent, 7,	{ 1, 1.896296, 8.066667, 0 } }, /*3000K*/

  { "OLYMPUS", "C5060WZ", Shade, 0,		{ 1.949219, 1, 1.195312, 0 } },
  { "OLYMPUS", "C5060WZ", Cloudy, 0,		{ 1.621094, 1, 1.410156, 0 } },
  { "OLYMPUS", "C5060WZ", DirectSunlight, 0,	{ 1.511719, 1, 1.500000, 0 } },
  { "OLYMPUS", "C5060WZ", EveningSun, 0,	{ 1.636719, 1, 1.496094, 0 } },
  { "OLYMPUS", "C5060WZ", DaylightFluorescent, 0, { 1.734375, 1, 1.343750, 0 } },
  { "OLYMPUS", "C5060WZ", NeutralFluorescent, 0, { 1.457031, 1, 1.691406, 0 } },
  { "OLYMPUS", "C5060WZ", CoolWhiteFluorescent, 0, { 1.417969, 1, 2.230469, 0 } },
  { "OLYMPUS", "C5060WZ", WhiteFluorescent, 0,	{ 1, 1.103448, 3.422414, 0 } },
  { "OLYMPUS", "C5060WZ", Incandescent, 0,	{ 1, 1.153153, 3.662162, 0 } },
  { "OLYMPUS", "C5060WZ", FlashAuto, 0,		{ 1.850000, 1, 1.308044, 0 } },

  // Olympus C8080WZ - firmware 757-78
  { "OLYMPUS", "C8080WZ", Shade, -7,		{ 1.515625, 1, 1.773438, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, -6,		{ 1.671875, 1, 1.691406, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, -5,		{ 1.832031, 1, 1.605469, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, -4,		{ 1.988281, 1, 1.523438, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, -3,		{ 2.144531, 1, 1.441406, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, -2,		{ 2.300781, 1, 1.355469, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, -1,		{ 2.457031, 1, 1.273438, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, 0,		{ 2.617188, 1, 1.191406, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, 1,		{ 2.929688, 1, 1.117188, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, 2,		{ 3.242188, 1, 1.046875, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, 3,		{ 3.644000, 1.024000, 1, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, 4,		{ 4.290043, 1.108225, 1, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, 5,		{ 5.032864, 1.201878, 1, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, 6,		{ 5.907692, 1.312821, 1, 0 } },
  { "OLYMPUS", "C8080WZ", Shade, 7,		{ 7.000000, 1.454545, 1, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, -7,		{ 1.277344, 1, 2.164062, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, -6,		{ 1.406250, 1, 2.062500, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, -5,		{ 1.539062, 1, 1.960938, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, -4,		{ 1.671875, 1, 1.859375, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, -3,		{ 1.804688, 1, 1.757812, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, -2,		{ 1.937500, 1, 1.656250, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, -1,		{ 2.070312, 1, 1.554688, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, 0,		{ 2.203125, 1, 1.453125, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, 1,		{ 2.464844, 1, 1.363281, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, 2,		{ 2.730469, 1, 1.277344, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, 3,		{ 2.996094, 1, 1.191406, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, 4,		{ 3.257812, 1, 1.101562, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, 5,		{ 3.523438, 1, 1.015625, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, 6,		{ 4.075630, 1.075630, 1, 0 } },
  { "OLYMPUS", "C8080WZ", Cloudy, 7,		{ 4.823256, 1.190698, 1, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, -7,		{ 1.234375, 1, 2.343750, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, -6,		{ 1.359375, 1, 2.234375, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, -5,		{ 1.488281, 1, 2.125000, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, -4,		{ 1.617188, 1, 2.011719, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, -3,		{ 1.742188, 1, 1.902344, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, -2,		{ 1.871094, 1, 1.792969, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, -1,		{ 2.000000, 1, 1.683594, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, 0,		{ 2.128906, 1, 1.574219, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, 1,		{ 2.382812, 1, 1.476562, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, 2,		{ 2.636719, 1, 1.382812, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, 3,		{ 2.894531, 1, 1.289062, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, 4,		{ 3.148438, 1, 1.195312, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, 5,		{ 3.406250, 1, 1.101562, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, 6,		{ 3.660156, 1, 1.003906, 0 } },
  { "OLYMPUS", "C8080WZ", Daylight, 7,		{ 4.300429, 1.098712, 1, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, -7,	{ 1.308594, 1, 2.199219, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, -6,	{ 1.445312, 1, 2.093750, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, -5,	{ 1.582031, 1, 1.992188, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, -4,	{ 1.718750, 1, 1.886719, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, -3,	{ 1.851562, 1, 1.785156, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, -2,	{ 1.988281, 1, 1.679688, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, -1,	{ 2.125000, 1, 1.578125, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, 0,	{ 2.261719, 1, 1.476562, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, 1,	{ 2.531250, 1, 1.386719, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, 2,	{ 2.800781, 1, 1.296875, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, 3,	{ 3.074219, 1, 1.207031, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, 4,	{ 3.343750, 1, 1.121094, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, 5,	{ 3.617188, 1, 1.031250, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, 6,	{ 4.128631, 1.062241, 1, 0 } },
  { "OLYMPUS", "C8080WZ", EveningSun, 7,	{ 4.863014, 1.168950, 1, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, -7,	{ 1.488281, 1, 2.214844, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, -6,	{ 1.652344, 1, 2.105469, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, -5,	{ 1.812500, 1, 1.992188, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, -4,	{ 1.976562, 1, 1.882812, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, -3,	{ 2.117188, 1, 1.773438, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, -2,	{ 2.253906, 1, 1.675781, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, -1,	{ 2.425781, 1, 1.585938, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, 0,		{ 2.570312, 1, 1.468750, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, 1,		{ 2.890625, 1, 1.386719, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, 2,		{ 3.199219, 1, 1.308594, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, 3,		{ 3.500000, 1, 1.214844, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, 4,		{ 3.820312, 1, 1.125000, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, 5,		{ 4.128906, 1, 1.039062, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, 6,		{ 4.711934, 1.053498, 1, 0 } },
  { "OLYMPUS", "C8080WZ", FlashAuto, 7,		{ 5.450450, 1.153153, 1, 0 } },
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, -7, { 1.425781, 1, 2.097656, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, -6, { 1.574219, 1, 2.000000, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, -5, { 1.722656, 1, 1.902344, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, -4, { 1.867188, 1, 1.804688, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, -3, { 2.015625, 1, 1.703125, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, -2, { 2.164062, 1, 1.605469, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, -1, { 2.312500, 1, 1.507812, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, 0, { 2.460938, 1, 1.410156, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, 1, { 2.753906, 1, 1.324219, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, 2, { 3.050781, 1, 1.238281, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, 3, { 3.343750, 1, 1.156250, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, 4, { 3.640625, 1, 1.070312, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, 5, { 4.000000, 1.015873, 1, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, 6, { 4.688312, 1.108225, 1, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", DaylightFluorescent, 7, { 5.545455, 1.224880, 1, 0 } }, /*6700K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, -7, { 1.195312, 1, 2.589844, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, -6, { 1.316406, 1, 2.464844, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, -5, { 1.441406, 1, 2.343750, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, -4, { 1.566406, 1, 2.222656, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, -3, { 1.687500, 1, 2.101562, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, -2, { 1.812500, 1, 1.980469, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, -1, { 1.937500, 1, 1.859375, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, 0, { 2.062500, 1, 1.738281, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, 1, { 2.308594, 1, 1.632812, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, 2, { 2.554688, 1, 1.527344, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, 3, { 2.804688, 1, 1.421875, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, 4, { 3.050781, 1, 1.320312, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, 5, { 3.296875, 1, 1.214844, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, 6, { 3.546875, 1, 1.109375, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", NeutralFluorescent, 7, { 3.792969, 1, 1.007812, 0 } }, /*5000K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, -7, { 1.109375, 1, 3.257812, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, -6, { 1.226562, 1, 3.105469, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, -5, { 1.339844, 1, 2.953125, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, -4, { 1.457031, 1, 2.796875, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, -3, { 1.570312, 1, 2.644531, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, -2, { 1.687500, 1, 2.492188, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, -1, { 1.800781, 1, 2.339844, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, 0, { 1.917969, 1, 2.187500, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, 1, { 2.144531, 1, 2.054688, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, 2, { 2.375000, 1, 1.921875, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, 3, { 2.605469, 1, 1.792969, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, 4, { 2.835938, 1, 1.660156, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, 5, { 3.066406, 1, 1.531250, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, 6, { 3.296875, 1, 1.398438, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", CoolWhiteFluorescent, 7, { 3.527344, 1, 1.265625, 0 } }, /*4200K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, -7,	{ 1, 1.347368, 5.963158, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, -6,	{ 1, 1.224880, 5.167464, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, -5,	{ 1, 1.117904, 4.484716, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, -4,	{ 1, 1.028112, 3.911647, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, -3,	{ 1.046875, 1, 3.593750, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, -2,	{ 1.125000, 1, 3.386719, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, -1,	{ 1.203125, 1, 3.179688, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, 0,	{ 1.281250, 1, 2.972656, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, 1,	{ 1.433594, 1, 2.792969, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, 2,	{ 1.585938, 1, 2.613281, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, 3,	{ 1.742188, 1, 2.437500, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, 4,	{ 1.894531, 1, 2.257812, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, 5,	{ 2.046875, 1, 2.078125, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, 6,	{ 2.203125, 1, 1.902344, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", WhiteFluorescent, 7,	{ 2.355469, 1, 1.722656, 0 } }, /*3500K*/
  { "OLYMPUS", "C8080WZ", Tungsten, -7,		{ 1, 1.488372, 6.988372, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, -6,		{ 1, 1.347368, 6.026316, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, -5,		{ 1, 1.230769, 5.235577, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, -4,		{ 1, 1.132743, 4.566372, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, -3,		{ 1, 1.049180, 4.000000, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, -2,		{ 1.023438, 1, 3.589844, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, -1,		{ 1.093750, 1, 3.371094, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, 0,		{ 1.164062, 1, 3.152344, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, 1,		{ 1.300781, 1, 2.960938, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, 2,		{ 1.441406, 1, 2.773438, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, 3,		{ 1.582031, 1, 2.582031, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, 4,		{ 1.722656, 1, 2.394531, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, 5,		{ 1.722656, 1, 2.394531, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, 6,		{ 2.000000, 1, 2.015625, 0 } }, /*3000K*/
  { "OLYMPUS", "C8080WZ", Tungsten, 7,		{ 2.140625, 1, 1.828125, 0 } }, /*3000K*/
// Fin ajout

  { "OLYMPUS", "E-1", Tungsten, -7,		{ 1.015625, 1, 1.867188, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, -6,		{ 1.007812, 1, 1.875000, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, -5,		{ 1, 1, 1.890625, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, -4,		{ 1, 1.007874, 1.913386, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, -3,		{ 1, 1.015873, 1.944444, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, -2,		{ 1, 1.015873, 1.952381, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, -1,		{ 1, 1.024000, 1.984000, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, 0,		{ 1, 1.024000, 1.992000, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, 1,		{ 1, 1.032258, 2.008065, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, 2,		{ 1, 1.040650, 2.040650, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, 3,		{ 1, 1.040650, 2.048780, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, 4,		{ 1, 1.049180, 2.081967, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, 5,		{ 1, 1.057851, 2.107438, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, 6,		{ 1, 1.066667, 2.141667, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", Tungsten, 7,		{ 1, 1.075630, 2.168067, 0 } }, /*3000K*/
  { "OLYMPUS", "E-1", "3300K", -7,		{ 1.109375, 1, 1.695312, 0 } },
  { "OLYMPUS", "E-1", "3300K", -6,		{ 1.101562, 1, 1.710938, 0 } },
  { "OLYMPUS", "E-1", "3300K", -5,		{ 1.093750, 1, 1.718750, 0 } },
  { "OLYMPUS", "E-1", "3300K", -4,		{ 1.093750, 1, 1.734375, 0 } },
  { "OLYMPUS", "E-1", "3300K", -3,		{ 1.085938, 1, 1.742188, 0 } },
  { "OLYMPUS", "E-1", "3300K", -2,		{ 1.078125, 1, 1.750000, 0 } },
  { "OLYMPUS", "E-1", "3300K", -1,		{ 1.070312, 1, 1.765625, 0 } },
  { "OLYMPUS", "E-1", "3300K", 0,		{ 1.070312, 1, 1.773438, 0 } },
  { "OLYMPUS", "E-1", "3300K", 1,		{ 1.054688, 1, 1.781250, 0 } },
  { "OLYMPUS", "E-1", "3300K", 2,		{ 1.046875, 1, 1.796875, 0 } },
  { "OLYMPUS", "E-1", "3300K", 3,		{ 1.046875, 1, 1.804688, 0 } },
  { "OLYMPUS", "E-1", "3300K", 4,		{ 1.039062, 1, 1.820312, 0 } },
  { "OLYMPUS", "E-1", "3300K", 5,		{ 1.031250, 1, 1.828125, 0 } },
  { "OLYMPUS", "E-1", "3300K", 6,		{ 1.023438, 1, 1.843750, 0 } },
  { "OLYMPUS", "E-1", "3300K", 7,		{ 1.015625, 1, 1.851562, 0 } },
  { "OLYMPUS", "E-1", Incandescent, -7,		{ 1.195312, 1, 1.562500, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, -6,		{ 1.187500, 1, 1.578125, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, -5,		{ 1.187500, 1, 1.585938, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, -4,		{ 1.179688, 1, 1.601562, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, -3,		{ 1.171875, 1, 1.609375, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, -2,		{ 1.164062, 1, 1.617188, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, -1,		{ 1.156250, 1, 1.632812, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, 0,		{ 1.156250, 1, 1.640625, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, 1,		{ 1.140625, 1, 1.648438, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, 2,		{ 1.132812, 1, 1.664062, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, 3,		{ 1.125000, 1, 1.671875, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, 4,		{ 1.117188, 1, 1.679688, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, 5,		{ 1.117188, 1, 1.695312, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, 6,		{ 1.109375, 1, 1.703125, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", Incandescent, 7,		{ 1.101562, 1, 1.718750, 0 } }, /*3600K*/
  { "OLYMPUS", "E-1", "3900K", -7,		{ 1.335938, 1, 1.414062, 0 } },
  { "OLYMPUS", "E-1", "3900K", -6,		{ 1.320312, 1, 1.429688, 0 } },
  { "OLYMPUS", "E-1", "3900K", -5,		{ 1.304688, 1, 1.445312, 0 } },
  { "OLYMPUS", "E-1", "3900K", -4,		{ 1.289062, 1, 1.460938, 0 } },
  { "OLYMPUS", "E-1", "3900K", -3,		{ 1.273438, 1, 1.476562, 0 } },
  { "OLYMPUS", "E-1", "3900K", -2,		{ 1.257812, 1, 1.492188, 0 } },
  { "OLYMPUS", "E-1", "3900K", -1,		{ 1.242188, 1, 1.507812, 0 } },
  { "OLYMPUS", "E-1", "3900K", 0,		{ 1.234375, 1, 1.523438, 0 } },
  { "OLYMPUS", "E-1", "3900K", 1,		{ 1.218750, 1, 1.531250, 0 } },
  { "OLYMPUS", "E-1", "3900K", 2,		{ 1.210938, 1, 1.546875, 0 } },
  { "OLYMPUS", "E-1", "3900K", 3,		{ 1.203125, 1, 1.554688, 0 } },
  { "OLYMPUS", "E-1", "3900K", 4,		{ 1.195312, 1, 1.562500, 0 } },
  { "OLYMPUS", "E-1", "3900K", 5,		{ 1.187500, 1, 1.578125, 0 } },
  { "OLYMPUS", "E-1", "3900K", 6,		{ 1.187500, 1, 1.585938, 0 } },
  { "OLYMPUS", "E-1", "3900K", 7,		{ 1.179688, 1, 1.601562, 0 } },
  { "OLYMPUS", "E-1", WhiteFluorescent, -7,	{ 2.296875, 1, 1.445312, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, -6,	{ 2.273438, 1, 1.468750, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, -5,	{ 2.242188, 1, 1.492188, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, -4,	{ 2.210938, 1, 1.523438, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, -3,	{ 2.171875, 1, 1.562500, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, -2,	{ 2.132812, 1, 1.601562, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, -1,	{ 2.093750, 1, 1.640625, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, 0,	{ 2.062500, 1, 1.679688, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, 1,	{ 2.039062, 1, 1.703125, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, 2,	{ 2.015625, 1, 1.734375, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, 3,	{ 2.000000, 1, 1.757812, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, 4,	{ 1.984375, 1, 1.789062, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, 5,	{ 1.968750, 1, 1.812500, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, 6,	{ 1.945312, 1, 1.835938, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", WhiteFluorescent, 7,	{ 1.929688, 1, 1.867188, 0 } }, /*4000K*/
  { "OLYMPUS", "E-1", "4300K", -7,		{ 1.484375, 1, 1.281250, 0 } },
  { "OLYMPUS", "E-1", "4300K", -6,		{ 1.468750, 1, 1.289062, 0 } },
  { "OLYMPUS", "E-1", "4300K", -5,		{ 1.460938, 1, 1.296875, 0 } },
  { "OLYMPUS", "E-1", "4300K", -4,		{ 1.445312, 1, 1.304688, 0 } },
  { "OLYMPUS", "E-1", "4300K", -3,		{ 1.437500, 1, 1.312500, 0 } },
  { "OLYMPUS", "E-1", "4300K", -2,		{ 1.429688, 1, 1.328125, 0 } },
  { "OLYMPUS", "E-1", "4300K", -1,		{ 1.414062, 1, 1.335938, 0 } },
  { "OLYMPUS", "E-1", "4300K", 0,		{ 1.414062, 1, 1.343750, 0 } },
  { "OLYMPUS", "E-1", "4300K", 1,		{ 1.390625, 1, 1.359375, 0 } },
  { "OLYMPUS", "E-1", "4300K", 2,		{ 1.375000, 1, 1.375000, 0 } },
  { "OLYMPUS", "E-1", "4300K", 3,		{ 1.359375, 1, 1.390625, 0 } },
  { "OLYMPUS", "E-1", "4300K", 4,		{ 1.343750, 1, 1.406250, 0 } },
  { "OLYMPUS", "E-1", "4300K", 5,		{ 1.328125, 1, 1.421875, 0 } },
  { "OLYMPUS", "E-1", "4300K", 6,		{ 1.312500, 1, 1.437500, 0 } },
  { "OLYMPUS", "E-1", "4300K", 7,		{ 1.296875, 1, 1.453125, 0 } },
  { "OLYMPUS", "E-1", NeutralFluorescent, -7,	{ 1.984375, 1, 1.203125, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, -6,	{ 1.960938, 1, 1.218750, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, -5,	{ 1.937500, 1, 1.234375, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, -4,	{ 1.921875, 1, 1.257812, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, -3,	{ 1.898438, 1, 1.273438, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, -2,	{ 1.875000, 1, 1.289062, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, -1,	{ 1.851562, 1, 1.304688, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, 0,	{ 1.835938, 1, 1.320312, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, 1,	{ 1.804688, 1, 1.343750, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, 2,	{ 1.773438, 1, 1.367188, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, 3,	{ 1.750000, 1, 1.390625, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, 4,	{ 1.718750, 1, 1.414062, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, 5,	{ 1.695312, 1, 1.437500, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, 6,	{ 1.656250, 1, 1.476562, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", NeutralFluorescent, 7,	{ 1.617188, 1, 1.515625, 0 } }, /*4500K*/
  { "OLYMPUS", "E-1", "4800K", -7,		{ 1.601562, 1, 1.179688, 0 } },
  { "OLYMPUS", "E-1", "4800K", -6,		{ 1.593750, 1, 1.187500, 0 } },
  { "OLYMPUS", "E-1", "4800K", -5,		{ 1.585938, 1, 1.195312, 0 } },
  { "OLYMPUS", "E-1", "4800K", -4,		{ 1.578125, 1, 1.203125, 0 } },
  { "OLYMPUS", "E-1", "4800K", -3,		{ 1.562500, 1, 1.203125, 0 } },
  { "OLYMPUS", "E-1", "4800K", -2,		{ 1.554688, 1, 1.210938, 0 } },
  { "OLYMPUS", "E-1", "4800K", -1,		{ 1.546875, 1, 1.218750, 0 } },
  { "OLYMPUS", "E-1", "4800K", 0,		{ 1.546875, 1, 1.226562, 0 } },
  { "OLYMPUS", "E-1", "4800K", 1,		{ 1.531250, 1, 1.234375, 0 } },
  { "OLYMPUS", "E-1", "4800K", 2,		{ 1.515625, 1, 1.242188, 0 } },
  { "OLYMPUS", "E-1", "4800K", 3,		{ 1.507812, 1, 1.257812, 0 } },
  { "OLYMPUS", "E-1", "4800K", 4,		{ 1.500000, 1, 1.265625, 0 } },
  { "OLYMPUS", "E-1", "4800K", 5,		{ 1.484375, 1, 1.273438, 0 } },
  { "OLYMPUS", "E-1", "4800K", 6,		{ 1.476562, 1, 1.281250, 0 } },
  { "OLYMPUS", "E-1", "4800K", 7,		{ 1.460938, 1, 1.289062, 0 } },
  { "OLYMPUS", "E-1", Daylight, -7,		{ 1.726562, 1, 1.093750, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, -6,		{ 1.710938, 1, 1.101562, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, -5,		{ 1.703125, 1, 1.109375, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, -4,		{ 1.695312, 1, 1.117188, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, -3,		{ 1.687500, 1, 1.117188, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, -2,		{ 1.671875, 1, 1.125000, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, -1,		{ 1.664062, 1, 1.132812, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, 0,		{ 1.664062, 1, 1.140625, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, 1,		{ 1.648438, 1, 1.148438, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, 2,		{ 1.640625, 1, 1.156250, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, 3,		{ 1.632812, 1, 1.164062, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, 4,		{ 1.617188, 1, 1.164062, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, 5,		{ 1.609375, 1, 1.171875, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, 6,		{ 1.601562, 1, 1.179688, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Daylight, 7,		{ 1.593750, 1, 1.187500, 0 } }, /*5300K*/
  { "OLYMPUS", "E-1", Cloudy, -7,		{ 2.008130, 1.040650, 1, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, -6,		{ 1.967742, 1.032258, 1, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, -5,		{ 1.920635, 1.015873, 1, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, -4,		{ 1.867188, 1, 1, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, -3,		{ 1.851562, 1, 1.007812, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, -2,		{ 1.828125, 1, 1.023438, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, -1,		{ 1.812500, 1, 1.031250, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, 0,		{ 1.796875, 1, 1.046875, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, 1,		{ 1.781250, 1, 1.054688, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, 2,		{ 1.773438, 1, 1.062500, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, 3,		{ 1.757812, 1, 1.070312, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, 4,		{ 1.750000, 1, 1.070312, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, 5,		{ 1.742188, 1, 1.078125, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, 6,		{ 1.734375, 1, 1.085938, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", Cloudy, 7,		{ 1.726562, 1, 1.093750, 0 } }, /*6000K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, -7,	{ 2.819820, 1.153153, 1, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, -6,	{ 2.669565, 1.113043, 1, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, -5,	{ 2.521008, 1.075630, 1, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, -4,	{ 2.390244, 1.040650, 1, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, -3,	{ 2.259843, 1.007874, 1, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, -2,	{ 2.195312, 1, 1.023438, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, -1,	{ 2.140625, 1, 1.054688, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, 0,	{ 2.101562, 1, 1.085938, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, 1,	{ 2.070312, 1, 1.101562, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, 2,	{ 2.046875, 1, 1.117188, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, 3,	{ 2.023438, 1, 1.132812, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, 4,	{ 2.000000, 1, 1.156250, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, 5,	{ 1.976562, 1, 1.171875, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, 6,	{ 1.953125, 1, 1.187500, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", DaylightFluorescent, 7,	{ 1.929688, 1, 1.203125, 0 } }, /*6600K*/
  { "OLYMPUS", "E-1", Shade, -7,		{ 2.584906, 1.207547, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, -6,		{ 2.532710, 1.196262, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, -5,		{ 2.467890, 1.174312, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, -4,		{ 2.396396, 1.153153, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, -3,		{ 2.357143, 1.142857, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, -2,		{ 2.289474, 1.122807, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, -1,		{ 2.252174, 1.113043, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, 0,			{ 2.196581, 1.094017, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, 1,			{ 2.126050, 1.075630, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, 2,			{ 2.091667, 1.066667, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, 3,			{ 2.032787, 1.049180, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, 4,			{ 2.000000, 1.040650, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, 5,			{ 1.944000, 1.024000, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, 6,			{ 1.897638, 1.007874, 1, 0 } }, /*7500K*/
  { "OLYMPUS", "E-1", Shade, 7,			{ 1.859375, 1, 1, 0 } }, /*7500K*/

  { "OLYMPUS", "E-10", Incandescent, 0,		{ 1, 1.153153, 3.441442, 0 } }, /*3000K*/
  { "OLYMPUS", "E-10", IncandescentWarm, 0,	{ 1.101562, 1, 2.351562, 0 } }, /*3700K*/
  { "OLYMPUS", "E-10", WhiteFluorescent, 0,	{ 1.460938, 1, 2.546875, 0 } }, /*4000K*/
  { "OLYMPUS", "E-10", DaylightFluorescent, 0,	{ 1.460938, 1, 1.843750, 0 } }, /*4500K*/
  { "OLYMPUS", "E-10", Daylight, 0,		{ 1.523438, 1, 1.617188, 0 } }, /*5500K*/
  { "OLYMPUS", "E-10", Cloudy, 0,		{ 1.687500, 1, 1.437500, 0 } }, /*6500K*/
  { "OLYMPUS", "E-10", Shade, 0,		{ 1.812500, 1, 1.312500, 0 } }, /*7500K*/

  { "OLYMPUS", "E-3", Daylight, 0,		{ 2.007813, 1, 1.390625, 0 } },
  { "OLYMPUS", "E-3", Shade, 0,			{ 2.421875, 1, 1.085937, 0 } },
  { "OLYMPUS", "E-3", Cloudy, 0,		{ 2.218750, 1, 1.257812, 0 } },
  { "OLYMPUS", "E-3", Tungsten, 0,		{ 1.156250, 1, 2.679687, 0 } },
  { "OLYMPUS", "E-3", Fluorescent, 0,		{ 1.828125, 1, 2.078125, 0 } },
  { "OLYMPUS", "E-3", NeutralFluorescent, 0,	{ 1.867188, 1, 1.679688, 0 } },
  { "OLYMPUS", "E-3", DaylightFluorescent, 0,	{ 2.195313, 1, 1.406250, 0 } },
  { "OLYMPUS", "E-3", Flash, 0,			{ 2.210937, 1, 1.265625, 0 } },
  { "OLYMPUS", "E-3", "2000K", 0,		{ 1, 2.285714, 9.803572, 0 } },
  { "OLYMPUS", "E-3", "2050K", 0,		{ 1, 2.000000, 8.281250, 0 } },
  { "OLYMPUS", "E-3", "2100K", 0,		{ 1, 1.802817, 7.239437, 0 } },
  { "OLYMPUS", "E-3", "2150K", 0,		{ 1, 1.641026, 6.397436, 0 } },
  { "OLYMPUS", "E-3", "2200K", 0,		{ 1, 1.488372, 5.616279, 0 } },
  { "OLYMPUS", "E-3", "2250K", 0,		{ 1, 1.391304, 5.086956, 0 } },
  { "OLYMPUS", "E-3", "2300K", 0,		{ 1, 1.292929, 4.585859, 0 } },
  { "OLYMPUS", "E-3", "2350K", 0,		{ 1, 1.230769, 4.240385, 0 } },
  { "OLYMPUS", "E-3", "2400K", 0,		{ 1, 1.163636, 3.890909, 0 } },
  { "OLYMPUS", "E-3", "2450K", 0,		{ 1, 1.113043, 3.617391, 0 } },
  { "OLYMPUS", "E-3", "2500K", 0,		{ 1, 1.057851, 3.347108, 0 } },
  { "OLYMPUS", "E-3", "2550K", 0,		{ 1, 1.015873, 3.119048, 0 } },
  { "OLYMPUS", "E-3", "2600K", 0,		{ 1.023437, 1, 2.984375, 0 } },
  { "OLYMPUS", "E-3", "2650K", 0,		{ 1.062500, 1, 2.898438, 0 } },
  { "OLYMPUS", "E-3", "2700K", 0,		{ 1.093750, 1, 2.820313, 0 } },
  { "OLYMPUS", "E-3", "2750K", 0,		{ 1.132812, 1, 2.742188, 0 } },
  { "OLYMPUS", "E-3", "2800K", 0,		{ 1.156250, 1, 2.679687, 0 } },
  { "OLYMPUS", "E-3", "2900K", 0,		{ 1.218750, 1, 2.539062, 0 } },
  { "OLYMPUS", "E-3", "3000K", 0,		{ 1.273437, 1, 2.414062, 0 } },
  { "OLYMPUS", "E-3", "3100K", 0,		{ 1.328125, 1, 2.289063, 0 } },
  { "OLYMPUS", "E-3", "3200K", 0,		{ 1.382813, 1, 2.171875, 0 } },
  { "OLYMPUS", "E-3", "3300K", 0,		{ 1.429688, 1, 2.070312, 0 } },
  { "OLYMPUS", "E-3", "3400K", 0,		{ 1.468750, 1, 2.015625, 0 } },
  { "OLYMPUS", "E-3", "3500K", 0,		{ 1.507812, 1, 1.953125, 0 } },
  { "OLYMPUS", "E-3", "3600K", 0,		{ 1.546875, 1, 1.898438, 0 } },
  { "OLYMPUS", "E-3", "3700K", 0,		{ 1.578125, 1, 1.851563, 0 } },
  { "OLYMPUS", "E-3", "3800K", 0,		{ 1.609375, 1, 1.804688, 0 } },
  { "OLYMPUS", "E-3", "3900K", 0,		{ 1.648437, 1, 1.757812, 0 } },
  { "OLYMPUS", "E-3", "4000K", 0,		{ 1.671875, 1, 1.734375, 0 } },
  { "OLYMPUS", "E-3", "4200K", 0,		{ 1.718750, 1, 1.679688, 0 } },
  { "OLYMPUS", "E-3", "4400K", 0,		{ 1.765625, 1, 1.625000, 0 } },
  { "OLYMPUS", "E-3", "4600K", 0,		{ 1.828125, 1, 1.562500, 0 } },
  { "OLYMPUS", "E-3", "4800K", 0,		{ 1.890625, 1, 1.500000, 0 } },
  { "OLYMPUS", "E-3", "5000K", 0,		{ 1.937500, 1, 1.460938, 0 } },
  { "OLYMPUS", "E-3", "5200K", 0,		{ 1.984375, 1, 1.414063, 0 } },
  { "OLYMPUS", "E-3", "5400K", 0,		{ 2.031250, 1, 1.375000, 0 } },
  { "OLYMPUS", "E-3", "5600K", 0,		{ 2.101563, 1, 1.335937, 0 } },
  { "OLYMPUS", "E-3", "5800K", 0,		{ 2.156250, 1, 1.296875, 0 } },
  { "OLYMPUS", "E-3", "6000K", 0,		{ 2.218750, 1, 1.257812, 0 } },
  { "OLYMPUS", "E-3", "6200K", 0,		{ 2.242187, 1, 1.234375, 0 } },
  { "OLYMPUS", "E-3", "6400K", 0,		{ 2.273437, 1, 1.210938, 0 } },
  { "OLYMPUS", "E-3", "6600K", 0,		{ 2.304688, 1, 1.179688, 0 } },
  { "OLYMPUS", "E-3", "6800K", 0,		{ 2.328125, 1, 1.164062, 0 } },
  { "OLYMPUS", "E-3", "7000K", 0,		{ 2.359375, 1, 1.132813, 0 } },
  { "OLYMPUS", "E-3", "7400K", 0,		{ 2.406250, 1, 1.101563, 0 } },
  { "OLYMPUS", "E-3", "7800K", 0,		{ 2.445313, 1, 1.062500, 0 } },
  { "OLYMPUS", "E-3", "8200K", 0,		{ 2.492188, 1, 1.023438, 0 } },
  { "OLYMPUS", "E-3", "8600K", 0,		{ 2.523438, 1, 1.000000, 0 } },
  { "OLYMPUS", "E-3", "9000K", 0,		{ 2.616000, 1.024000, 1, 0 } },
  { "OLYMPUS", "E-3", "9400K", 0,		{ 2.735537, 1.057851, 1, 0 } },
  { "OLYMPUS", "E-3", "9800K", 0,		{ 2.806723, 1.075630, 1, 0 } },
  { "OLYMPUS", "E-3", "10000K", 0,		{ 2.871795, 1.094017, 1, 0 } },
  { "OLYMPUS", "E-3", "11000K", 0,		{ 3.090090, 1.153153, 1, 0 } },
  { "OLYMPUS", "E-3", "12000K", 0,		{ 3.292453, 1.207547, 1, 0 } },
  { "OLYMPUS", "E-3", "13000K", 0,		{ 3.504950, 1.267327, 1, 0 } },
  { "OLYMPUS", "E-3", "14000K", 0,		{ 3.653061, 1.306122, 1, 0 } },

  { "OLYMPUS", "E-300", Incandescent, -7,	{ 1.179688, 1, 2.125000, 0 } },
  { "OLYMPUS", "E-300", Incandescent, 0,	{ 1.140625, 1, 2.203125, 0 } },
  { "OLYMPUS", "E-300", Incandescent, 7,	{ 1.093750, 1, 2.273438, 0 } },
  { "OLYMPUS", "E-300", IncandescentWarm, -7,	{ 1.382812, 1, 1.859375, 0 } },
  { "OLYMPUS", "E-300", IncandescentWarm, 0,	{ 1.312500, 1, 1.906250, 0 } },
  { "OLYMPUS", "E-300", IncandescentWarm, 7,	{ 1.257812, 1, 1.984375, 0 } },
  { "OLYMPUS", "E-300", WhiteFluorescent, -7,	{ 2.109375, 1, 1.710938, 0 } },
  { "OLYMPUS", "E-300", WhiteFluorescent, 0,	{ 1.976562, 1, 1.921875, 0 } },
  { "OLYMPUS", "E-300", WhiteFluorescent, 7,	{ 1.804688, 1, 2.062500, 0 } },
  { "OLYMPUS", "E-300", NeutralFluorescent, -7,	{ 1.945312, 1, 1.445312, 0 } },
  { "OLYMPUS", "E-300", NeutralFluorescent, 0,	{ 1.820312, 1, 1.562500, 0 } },
  { "OLYMPUS", "E-300", NeutralFluorescent, 7,	{ 1.585938, 1, 1.945312, 0 } },
  { "OLYMPUS", "E-300", DaylightFluorescent, -7, { 2.203125, 1, 1.000000, 0 } },
  { "OLYMPUS", "E-300", DaylightFluorescent, 0,	{ 2.031250, 1, 1.328125, 0 } },
  { "OLYMPUS", "E-300", DaylightFluorescent, 7,	{ 1.765625, 1, 1.367188, 0 } },
  { "OLYMPUS", "E-300", Daylight, -7,		{ 1.835938, 1, 1.304688, 0 } },
  { "OLYMPUS", "E-300", Daylight, 0,		{ 1.789062, 1, 1.351562, 0 } },
  { "OLYMPUS", "E-300", Daylight, 7,		{ 1.726562, 1, 1.398438, 0 } },
  { "OLYMPUS", "E-300", Cloudy, -7,		{ 2.000000, 1, 1.156250, 0 } },
  { "OLYMPUS", "E-300", Cloudy, 0,		{ 1.890625, 1, 1.257812, 0 } },
  { "OLYMPUS", "E-300", Cloudy, 7,		{ 1.835938, 1, 1.304688, 0 } },
  { "OLYMPUS", "E-300", Shade, -7,		{ 2.179688, 1, 1.007812, 0 } },
  { "OLYMPUS", "E-300", Shade, 0,		{ 2.070312, 1, 1.109375, 0 } },
  { "OLYMPUS", "E-300", Shade, 7,		{ 1.945312, 1, 1.210938, 0 } },

  { "OLYMPUS", "E-330", Daylight, 0,		{ 1.812500, 1, 1.296875, 0 } }, /*5300K*/
  { "OLYMPUS", "E-330", Cloudy, 0,		{ 1.953125, 1, 1.195312, 0 } }, /*6000K*/
  { "OLYMPUS", "E-330", Shade, 0,		{ 2.187500, 1, 1.054688, 0 } }, /*7500K*/
  { "OLYMPUS", "E-330", Incandescent, 0,	{ 1.039062, 1, 2.437500, 0 } }, /*3000K*/
  { "OLYMPUS", "E-330", WhiteFluorescent, 0,	{ 1.710938, 1, 1.906250, 0 } }, /*4000K*/
  { "OLYMPUS", "E-330", NeutralFluorescent, 0,	{ 1.750000, 1, 1.531250, 0 } }, /*4500K*/
  { "OLYMPUS", "E-330", DaylightFluorescent, 0,	{ 2.062500, 1, 1.289062, 0 } }, /*6600K*/

  { "OLYMPUS", "E-400", Daylight, -7,		{ 2.554687, 1, 1.390625, 0 } },
  { "OLYMPUS", "E-400", Daylight, 0,		{ 2.312500, 1, 1.179687, 0 } },
  { "OLYMPUS", "E-400", Daylight, 7,		{ 2.096774, 1.032258, 1, 0 } },
  { "OLYMPUS", "E-400", Cloudy, -7,		{ 2.695312, 1, 1.289062, 0 } },
  { "OLYMPUS", "E-400", Cloudy, 0,		{ 2.437500, 1, 1.093750, 0 } },
  { "OLYMPUS", "E-400", Cloudy, 7,		{ 2.554545, 1.163636, 1, 0 } },
  { "OLYMPUS", "E-400", Shade, -7,		{ 2.835937, 1, 1.187500, 0 } },
  { "OLYMPUS", "E-400", Shade, 0,		{ 2.754098, 1.049180, 1, 0 } },
  { "OLYMPUS", "E-400", Shade, 7,		{ 3.202128, 1.361702, 1, 0 } },
  { "OLYMPUS", "E-400", Incandescent, -7,	{ 1.500000, 1, 2.710938, 0 } },
  { "OLYMPUS", "E-400", Incandescent, 0,	{ 1.460937, 1, 2.171875, 0 } },
  { "OLYMPUS", "E-400", Incandescent, 7,	{ 1.367187, 1, 1.679688, 0 } },
  { "OLYMPUS", "E-400", WhiteFluorescent, -7,	{ 2.523438, 1, 2.250000, 0 } },
  { "OLYMPUS", "E-400", WhiteFluorescent, 0,	{ 2.390625, 1, 1.796875, 0 } },
  { "OLYMPUS", "E-400", WhiteFluorescent, 7,	{ 2.164063, 1, 1.429688, 0 } },
  { "OLYMPUS", "E-400", NeutralFluorescent, -7,	{ 2.226562, 1, 1.828125, 0 } },
  { "OLYMPUS", "E-400", NeutralFluorescent, 0,	{ 2.132812, 1, 1.468750, 0 } },
  { "OLYMPUS", "E-400", NeutralFluorescent, 7,	{ 1.953125, 1, 1.156250, 0 } },
  { "OLYMPUS", "E-400", DaylightFluorescent, -7, { 2.593750, 1, 1.359375, 0 } },
  { "OLYMPUS", "E-400", DaylightFluorescent, 0,	{ 2.445313, 1, 1.195313, 0 } },
  { "OLYMPUS", "E-400", DaylightFluorescent, 7,	{ 3.293478, 1.391304, 1, 0 } },

  { "OLYMPUS", "E-410", Daylight, 0,		{ 1.914063, 1, 1.367188, 0 } }, /*5300K*/
  { "OLYMPUS", "E-410", Cloudy, 0,		{ 2.054688, 1, 1.250000, 0 } }, /*6000K*/
  { "OLYMPUS", "E-410", Shade, 0,		{ 2.304688, 1, 1.031250, 0 } }, /*7500K*/
  { "OLYMPUS", "E-410", Incandescent, 0,	{ 1.062500, 1, 2.781250, 0 } }, /*3000K*/
  { "OLYMPUS", "E-410", WhiteFluorescent, 0,	{ 1.726562, 1, 2.226562, 0 } }, /*4000K*/
  { "OLYMPUS", "E-410", NeutralFluorescent, 0,	{ 1.703125, 1, 1.796875, 0 } }, /*4500K*/
  { "OLYMPUS", "E-410", DaylightFluorescent, 0,	{ 2.039063, 1, 1.476562, 0 } }, /*6600K*/

  { "OLYMPUS", "E-500", Daylight, 0,		{ 1.898438, 1, 1.359375, 0 } }, /*5300K*/
  { "OLYMPUS", "E-500", Cloudy, 0,		{ 1.992188, 1, 1.265625, 0 } }, /*6000K*/
  { "OLYMPUS", "E-500", Shade, 0,		{ 2.148438, 1, 1.125000, 0 } }, /*7500K*/
  { "OLYMPUS", "E-500", Incandescent, 0,	{ 1.265625, 1, 2.195312, 0 } }, /*3000K*/
  { "OLYMPUS", "E-500", WhiteFluorescent, 0,	{ 1.976562, 1, 1.914062, 0 } }, /*4000K*/
  { "OLYMPUS", "E-500", NeutralFluorescent, 0,	{ 1.828125, 1, 1.562500, 0 } }, /*4500K*/
  { "OLYMPUS", "E-500", DaylightFluorescent, 0,	{ 2.046875, 1, 1.359375, 0 } }, /*6600K*/

  { "OLYMPUS", "E-510", Daylight, -7,		{ 2.164063, 1, 1.546875, 0 } },
  { "OLYMPUS", "E-510", Daylight, 0,		{ 1.968750, 1, 1.296875, 0 } },
  { "OLYMPUS", "E-510", Daylight, 7,		{ 1.742187, 1, 1.062500, 0 } },
  { "OLYMPUS", "E-510", Shade, -7,		{ 2.492188, 1, 1.273438, 0 } },
  { "OLYMPUS", "E-510", Shade, 0,		{ 2.439024, 1.040650, 1, 0 } },
  { "OLYMPUS", "E-510", Shade, 7,		{ 3.055556, 1.422222, 1, 0 } },
  { "OLYMPUS", "E-510", Cloudy, -7,		{ 2.312500, 1, 1.414062, 0 } },
  { "OLYMPUS", "E-510", Cloudy, 0,		{ 2.109375, 1, 1.187500, 0 } },
  { "OLYMPUS", "E-510", Cloudy, 7,		{ 2.192982, 1.122807, 1, 0 } },
  { "OLYMPUS", "E-510", Incandescent, -7,	{ 1.109375, 1, 3.351562, 0 } },
  { "OLYMPUS", "E-510", Incandescent, 0,	{ 1.093750, 1, 2.671875, 0 } },
  { "OLYMPUS", "E-510", Incandescent, 7,	{ 1.031250, 1, 2.054688, 0 } },
  { "OLYMPUS", "E-510", WhiteFluorescent, -7,	{ 1.578125, 1, 2.250000, 0 } },
  { "OLYMPUS", "E-510", WhiteFluorescent, 0,	{ 1.718750, 1, 2.109375, 0 } },
  { "OLYMPUS", "E-510", WhiteFluorescent, 7,	{ 1.523437, 1, 1.265625, 0 } },
  { "OLYMPUS", "E-510", NeutralFluorescent, -7,	{ 1.835938, 1, 1.828125, 0 } },
  { "OLYMPUS", "E-510", NeutralFluorescent, 0,	{ 1.687500, 1, 1.710938, 0 } },
  { "OLYMPUS", "E-510", NeutralFluorescent, 7,	{ 1.726562, 1, 1.078125, 0 } },
  { "OLYMPUS", "E-510", DaylightFluorescent, -7, { 2.203125, 1, 1.500000, 0 } },
  { "OLYMPUS", "E-510", DaylightFluorescent, 0,	{ 2.023438, 1, 1.398437, 0 } },
  { "OLYMPUS", "E-510", DaylightFluorescent, 7,	{ 3.193182, 1.454545, 1, 0 } },

  { "OLYMPUS", "E-520", Daylight, 0,		{ 1.859375, 1, 1.445312, 0 } },
  { "OLYMPUS", "E-520", Shade, 0,		{ 2.234375, 1, 1.140625, 0 } },
  { "OLYMPUS", "E-520", Cloudy, 0,		{ 2.046875, 1, 1.296875, 0 } },
  { "OLYMPUS", "E-520", Tungsten, 0,		{ 1.062500, 1, 2.687500, 0 } },
  { "OLYMPUS", "E-520", Fluorescent, 0,		{ 1.703125, 1, 2.109375, 0 } },
  { "OLYMPUS", "E-520", NeutralFluorescent, 0,	{ 1.718750, 1, 1.765625, 0 } },
  { "OLYMPUS", "E-520", DaylightFluorescent, 0,	{ 2.101563, 1, 1.375000, 0 } },
  { "OLYMPUS", "E-520", Flash, 0,		{ 2.039063, 1, 1.296875, 0 } },
  { "OLYMPUS", "E-520", "2000K", 0,		{ 1, 2.461538, 10.576923, 0 } },
  { "OLYMPUS", "E-520", "2050K", 0,		{ 1, 2.169491, 9.000000, 0 } },
  { "OLYMPUS", "E-520", "2100K", 0,		{ 1, 1.939394, 7.803031, 0 } },
  { "OLYMPUS", "E-520", "2150K", 0,		{ 1, 1.777778, 6.944445, 0 } },
  { "OLYMPUS", "E-520", "2200K", 0,		{ 1, 1.620253, 6.126582, 0 } },
  { "OLYMPUS", "E-520", "2250K", 0,		{ 1, 1.505882, 5.517647, 0 } },
  { "OLYMPUS", "E-520", "2300K", 0,		{ 1, 1.406593, 5.000000, 0 } },
  { "OLYMPUS", "E-520", "2350K", 0,		{ 1, 1.333333, 4.604167, 0 } },
  { "OLYMPUS", "E-520", "2400K", 0,		{ 1, 1.254902, 4.205882, 0 } },
  { "OLYMPUS", "E-520", "2450K", 0,		{ 1, 1.207547, 3.933962, 0 } },
  { "OLYMPUS", "E-520", "2500K", 0,		{ 1, 1.153153, 3.657658, 0 } },
  { "OLYMPUS", "E-520", "2550K", 0,		{ 1, 1.103448, 3.396552, 0 } },
  { "OLYMPUS", "E-520", "2600K", 0,		{ 1, 1.066667, 3.191667, 0 } },
  { "OLYMPUS", "E-520", "2650K", 0,		{ 1, 1.024000, 2.976000, 0 } },
  { "OLYMPUS", "E-520", "2700K", 0,		{ 1.007812, 1, 2.828125, 0 } },
  { "OLYMPUS", "E-520", "2750K", 0,		{ 1.039062, 1, 2.750000, 0 } },
  { "OLYMPUS", "E-520", "2800K", 0,		{ 1.062500, 1, 2.687500, 0 } },
  { "OLYMPUS", "E-520", "2900K", 0,		{ 1.117188, 1, 2.546875, 0 } },
  { "OLYMPUS", "E-520", "3000K", 0,		{ 1.171875, 1, 2.421875, 0 } },
  { "OLYMPUS", "E-520", "3100K", 0,		{ 1.218750, 1, 2.296875, 0 } },
  { "OLYMPUS", "E-520", "3200K", 0,		{ 1.265625, 1, 2.179688, 0 } },
  { "OLYMPUS", "E-520", "3300K", 0,		{ 1.312500, 1, 2.078125, 0 } },
  { "OLYMPUS", "E-520", "3400K", 0,		{ 1.343750, 1, 2.023438, 0 } },
  { "OLYMPUS", "E-520", "3500K", 0,		{ 1.382812, 1, 1.960937, 0 } },
  { "OLYMPUS", "E-520", "3600K", 0,		{ 1.414063, 1, 1.906250, 0 } },
  { "OLYMPUS", "E-520", "3700K", 0,		{ 1.445312, 1, 1.859375, 0 } },
  { "OLYMPUS", "E-520", "3800K", 0,		{ 1.476563, 1, 1.812500, 0 } },
  { "OLYMPUS", "E-520", "3900K", 0,		{ 1.507813, 1, 1.765625, 0 } },
  { "OLYMPUS", "E-520", "4000K", 0,		{ 1.531250, 1, 1.757812, 0 } },
  { "OLYMPUS", "E-520", "4200K", 0,		{ 1.578125, 1, 1.726562, 0 } },
  { "OLYMPUS", "E-520", "4400K", 0,		{ 1.625000, 1, 1.679688, 0 } },
  { "OLYMPUS", "E-520", "4600K", 0,		{ 1.687500, 1, 1.617187, 0 } },
  { "OLYMPUS", "E-520", "4800K", 0,		{ 1.742187, 1, 1.554687, 0 } },
  { "OLYMPUS", "E-520", "5000K", 0,		{ 1.789062, 1, 1.515625, 0 } },
  { "OLYMPUS", "E-520", "5200K", 0,		{ 1.835938, 1, 1.468750, 0 } },
  { "OLYMPUS", "E-520", "5400K", 0,		{ 1.882812, 1, 1.429687, 0 } },
  { "OLYMPUS", "E-520", "5600K", 0,		{ 1.937500, 1, 1.382812, 0 } },
  { "OLYMPUS", "E-520", "5800K", 0,		{ 1.992187, 1, 1.343750, 0 } },
  { "OLYMPUS", "E-520", "6000K", 0,		{ 2.046875, 1, 1.296875, 0 } },
  { "OLYMPUS", "E-520", "6200K", 0,		{ 2.070312, 1, 1.273438, 0 } },
  { "OLYMPUS", "E-520", "6400K", 0,		{ 2.101563, 1, 1.250000, 0 } },
  { "OLYMPUS", "E-520", "6600K", 0,		{ 2.125000, 1, 1.226563, 0 } },
  { "OLYMPUS", "E-520", "6800K", 0,		{ 2.148437, 1, 1.210937, 0 } },
  { "OLYMPUS", "E-520", "7000K", 0,		{ 2.179688, 1, 1.187500, 0 } },
  { "OLYMPUS", "E-520", "7400K", 0,		{ 2.218750, 1, 1.156250, 0 } },
  { "OLYMPUS", "E-520", "7800K", 0,		{ 2.257812, 1, 1.117187, 0 } },
  { "OLYMPUS", "E-520", "8200K", 0,		{ 2.296875, 1, 1.085938, 0 } },
  { "OLYMPUS", "E-520", "8600K", 0,		{ 2.328125, 1, 1.062500, 0 } },
  { "OLYMPUS", "E-520", "9000K", 0,		{ 2.359375, 1, 1.039063, 0 } },
  { "OLYMPUS", "E-520", "9400K", 0,		{ 2.382812, 1, 1.015625, 0 } },
  { "OLYMPUS", "E-520", "9800K", 0,		{ 2.406250, 1, 1.000000, 0 } },
  { "OLYMPUS", "E-520", "10000K", 0,		{ 2.460317, 1.015873, 1, 0 } },
  { "OLYMPUS", "E-520", "11000K", 0,		{ 2.641667, 1.066667, 1, 0 } },
  { "OLYMPUS", "E-520", "12000K", 0,		{ 2.775862, 1.103448, 1, 0 } },
  { "OLYMPUS", "E-520", "13000K", 0,		{ 2.919643, 1.142857, 1, 0 } },
  { "OLYMPUS", "E-520", "14000K", 0,		{ 3.036697, 1.174312, 1, 0 } },

  { "OLYMPUS", "SP500UZ", Daylight, -7,		{ 1.136719, 1, 2.359375, 0 } },
  { "OLYMPUS", "SP500UZ", Daylight, 0,		{ 1.960937, 1, 1.585937, 0 } },
  { "OLYMPUS", "SP500UZ", Daylight, 7,		{ 3.927660, 1.089362, 1, 0 } },
  { "OLYMPUS", "SP500UZ", Cloudy, -7,		{ 1.191406, 1, 2.210937, 0 } },
  { "OLYMPUS", "SP500UZ", Cloudy, 0,		{ 2.058594, 1, 1.484375, 0 } },
  { "OLYMPUS", "SP500UZ", Cloudy, 7,		{ 4.404545, 1.163636, 1, 0 } },
  { "OLYMPUS", "SP500UZ", EveningSun, -7,	{ 1.199219, 1, 2.214844, 0 } },
  { "OLYMPUS", "SP500UZ", EveningSun, 0,	{ 2.074219, 1, 1.488281, 0 } },
  { "OLYMPUS", "SP500UZ", EveningSun, 7,	{ 4.440909, 1.163636, 1, 0 } },
  { "OLYMPUS", "SP500UZ", Tungsten, -7,		{ 1, 1.590062, 6.490683, 0 } },
  { "OLYMPUS", "SP500UZ", Tungsten, 0,		{ 1.085937, 1, 2.742188, 0 } },
  { "OLYMPUS", "SP500UZ", Tungsten, 7,		{ 1.996094, 1, 1.589844, 0 } },
  { "OLYMPUS", "SP500UZ", Fluorescent, -7,	{ 1.324219, 1, 2.214844, 0 } },
  { "OLYMPUS", "SP500UZ", Fluorescent, 0,	{ 2.285156, 1, 1.488281, 0 } },
  { "OLYMPUS", "SP500UZ", Fluorescent, 7,	{ 4.890909, 1.163636, 1, 0 } },

  { "OLYMPUS", "SP510UZ", Daylight, 0,		{ 1.656250, 1, 1.621094, 0 } },
  { "OLYMPUS", "SP510UZ", Cloudy, 0,		{ 1.789063, 1, 1.546875, 0 } },
  { "OLYMPUS", "SP510UZ", Incandescent, 0,	{ 1, 1.066667, 2.891667, 0 } },
  { "OLYMPUS", "SP510UZ", WhiteFluorescent, 0,	{ 1.929688, 1, 1.562500, 0 } },
  { "OLYMPUS", "SP510UZ", NeutralFluorescent, 0, { 1.644531, 1, 1.843750, 0 } },
  { "OLYMPUS", "SP510UZ", DaylightFluorescent, 0, { 1.628906, 1, 2.210938, 0 } },

  { "Panasonic", "DMC-FZ8", Daylight, 0,	{ 1.904943, 1, 1.596958, 0 } },
  { "Panasonic", "DMC-FZ8", Cloudy, 0,		{ 2.060836, 1, 1.498099, 0 } },
  { "Panasonic", "DMC-FZ8", Shade, 0,		{ 2.258555, 1, 1.391635, 0 } },
  { "Panasonic", "DMC-FZ8", Incandescent, 0,	{ 1.247148, 1, 2.288973, 0 } },
  { "Panasonic", "DMC-FZ8", Flash, 0,		{ 2.072243, 1, 1.456274, 0 } },

  { "Panasonic", "DMC-FZ18", Daylight, 0,	{ 1.783270, 1, 1.889734, 0 } },
  { "Panasonic", "DMC-FZ18", Cloudy, 0,		{ 1.946768, 1, 1.680608, 0 } },
  { "Panasonic", "DMC-FZ18", Shade, 0,		{ 2.117871, 1, 1.558935, 0 } },
  { "Panasonic", "DMC-FZ18", Incandescent, 0,	{ 1.140684, 1, 2.627376, 0 } },
  { "Panasonic", "DMC-FZ18", Flash, 0,		{ 1.882129, 1, 1.703422, 0 } },

  { "Panasonic", "DMC-FZ30", Daylight, 0,	{ 1.757576, 1, 1.446970, 0 } },
  { "Panasonic", "DMC-FZ30", Cloudy, 0,		{ 1.943182, 1, 1.276515, 0 } },
  { "Panasonic", "DMC-FZ30", Incandescent, 0,	{ 1.098485, 1, 2.106061, 0 } },
  { "Panasonic", "DMC-FZ30", Flash, 0,		{ 1.965909, 1, 1.303030, 0 } },

  { "Panasonic", "DMC-FZ50", Daylight, 0,	{ 2.095057, 1, 1.642586, 0 } },
  { "Panasonic", "DMC-FZ50", Cloudy, 0,		{ 2.319392, 1, 1.482890, 0 } },
  { "Panasonic", "DMC-FZ50", Shade, 0,		{ 2.463878, 1, 1.414449, 0 } },
  { "Panasonic", "DMC-FZ50", Incandescent, 0,	{ 1.365019, 1, 2.311787, 0 } },
  { "Panasonic", "DMC-FZ50", Flash, 0,		{ 2.338403, 1, 1.338403, 0 } },

  { "Panasonic", "DMC-L1", Daylight, 0,		{ 1.980989, 1, 1.444867, 0 } },
  { "Panasonic", "DMC-L1", Cloudy, 0,		{ 2.129278, 1, 1.300380, 0 } },
  { "Panasonic", "DMC-L1", Shade, 0,		{ 2.361217, 1, 1.167300, 0 } },
  { "Panasonic", "DMC-L1", Incandescent, 0,	{ 1.368821, 1, 2.091255, 0 } },
  { "Panasonic", "DMC-L1", Flash, 0,		{ 2.319392, 1, 1.053232, 0 } },

  /* DMC-L1 Kelvin presets */
  { "Panasonic", "DMC-L1", "2500K", 0,		{ 1.209126, 2.722434, 1, 0 } },
  { "Panasonic", "DMC-L1", "2600K", 0,		{ 1.243346, 2.623574, 1, 0 } },
  { "Panasonic", "DMC-L1", "2700K", 0,		{ 1.285171, 2.520913, 1, 0 } },
  { "Panasonic", "DMC-L1", "2800K", 0,		{ 1.323194, 2.418251, 1, 0 } },
  { "Panasonic", "DMC-L1", "2900K", 0,		{ 1.365019, 2.319392, 1, 0 } },
  { "Panasonic", "DMC-L1", "3000K", 0,		{ 1.406844, 2.209126, 1, 0 } },
  { "Panasonic", "DMC-L1", "3100K", 0,		{ 1.441065, 2.193916, 1, 0 } },
  { "Panasonic", "DMC-L1", "3200K", 0,		{ 1.482890, 2.178707, 1, 0 } },
  { "Panasonic", "DMC-L1", "3300K", 0,		{ 1.524715, 2.163498, 1, 0 } },
  { "Panasonic", "DMC-L1", "3400K", 0,		{ 1.566540, 2.148289, 1, 0 } },
  { "Panasonic", "DMC-L1", "3500K", 0,		{ 1.608365, 2.136882, 1, 0 } },
  { "Panasonic", "DMC-L1", "3600K", 0,		{ 1.638783, 2.091255, 1, 0 } },
  { "Panasonic", "DMC-L1", "3800K", 0,		{ 1.699620, 2.000000, 1, 0 } },
  { "Panasonic", "DMC-L1", "4000K", 0,		{ 1.760456, 1.897338, 1, 0 } },
  { "Panasonic", "DMC-L1", "4200K", 0,		{ 1.813688, 1.809886, 1, 0 } },
  { "Panasonic", "DMC-L1", "4400K", 0,		{ 1.874525, 1.722433, 1, 0 } },
  { "Panasonic", "DMC-L1", "4600K", 0,		{ 1.912547, 1.642585, 1, 0 } },
  { "Panasonic", "DMC-L1", "4800K", 0,		{ 1.923954, 1.585551, 1, 0 } },
  { "Panasonic", "DMC-L1", "5000K", 0,		{ 1.942966, 1.528517, 1, 0 } },
  { "Panasonic", "DMC-L1", "5300K", 0,		{ 1.984791, 1.456274, 1, 0 } },
  { "Panasonic", "DMC-L1", "5500K", 0,		{ 2.019011, 1.403042, 1, 0 } },
  { "Panasonic", "DMC-L1", "5800K", 0,		{ 2.057034, 1.361217, 1, 0 } },
  { "Panasonic", "DMC-L1", "6000K", 0,		{ 2.079848, 1.323194, 1, 0 } },
  { "Panasonic", "DMC-L1", "6300K", 0,		{ 2.159696, 1.281369, 1, 0 } },
  { "Panasonic", "DMC-L1", "6500K", 0,		{ 2.216730, 1.243346, 1, 0 } },
  { "Panasonic", "DMC-L1", "6800K", 0,		{ 2.273764, 1.228137, 1, 0 } },
  { "Panasonic", "DMC-L1", "7300K", 0,		{ 2.380228, 1.186312, 1, 0 } },
  { "Panasonic", "DMC-L1", "7800K", 0,		{ 2.452471, 1.144487, 1, 0 } },
  { "Panasonic", "DMC-L1", "8300K", 0,		{ 2.501901, 1.106464, 1, 0 } },
  { "Panasonic", "DMC-L1", "9000K", 0,		{ 2.574145, 1.068441, 1, 0 } },
  { "Panasonic", "DMC-L1", "10000K", 0,		{ 2.692015, 1.011407, 1, 0 } },

  { "Panasonic", "DMC-LX1", Daylight, 0,	{ 1.837121, 1, 1.484848, 0 } },
  { "Panasonic", "DMC-LX1", Cloudy, 0,		{ 2.003788, 1, 1.310606, 0 } },
  { "Panasonic", "DMC-LX1", Incandescent, 0,	{ 1.098485, 1, 2.272727, 0 } },

  { "Panasonic", "DMC-LX2", Daylight, -3, 	{ 2.456274, 1, 1.806084, 0 } },
  { "Panasonic", "DMC-LX2", Daylight, 0, 	{ 2.114068, 1, 1.726236, 0 } },
  { "Panasonic", "DMC-LX2", Daylight, 3, 	{ 1.916350, 1, 1.585551, 0 } },
  { "Panasonic", "DMC-LX2", Cloudy, -3, 	{ 2.714829, 1, 1.650190, 0 } },
  { "Panasonic", "DMC-LX2", Cloudy, 0, 		{ 2.338403, 1, 1.577947, 0 } },
  { "Panasonic", "DMC-LX2", Cloudy, 3, 		{ 2.121673, 1, 1.448669, 0 } },
  { "Panasonic", "DMC-LX2", Shade, -3, 		{ 2.939163, 1, 1.577947, 0 } },
  { "Panasonic", "DMC-LX2", Shade, 0, 		{ 2.532319, 1, 1.509506, 0 } },
  { "Panasonic", "DMC-LX2", Shade, 3, 		{ 2.292776, 1, 1.384030, 0 } },
  { "Panasonic", "DMC-LX2", Incandescent, -3, 	{ 1.581749, 1, 2.524715, 0 } },
  { "Panasonic", "DMC-LX2", Incandescent, 0, 	{ 1.365019, 1, 2.410646, 0 } },
  { "Panasonic", "DMC-LX2", Incandescent, 3, 	{ 1.235741, 1, 2.212928, 0 } },

  { "Panasonic", "DMC-LX3", Daylight, 0,	{ 2.022814, 1, 1.623574, 0 } },
  { "Panasonic", "DMC-LX3", Cloudy, 0,		{ 2.224335, 1, 1.520913, 0 } },
  { "Panasonic", "DMC-LX3", Shade, 0,		{ 2.475285, 1, 1.399240, 0 } },
  { "Panasonic", "DMC-LX3", Flash, 0,		{ 2.296578, 1, 1.482890, 0 } },
  { "Panasonic", "DMC-LX3", Incandescent, 0,	{ 1.346008, 1, 2.269962, 0 } },

  /* It seems that the *ist D WB settings are not really presets. */
  { "PENTAX", "*ist D", Daylight, 0,		{ 1.460938, 1, 1.019531, 0 } },
  { "PENTAX", "*ist D", Shade, 0,		{ 1.734375, 1, 1.000000, 0 } },
  { "PENTAX", "*ist D", Cloudy, 0,		{ 1.634921, 1.015873, 1, 0 } },
  { "PENTAX", "*ist D", DaylightFluorescent, 0,	{ 1.657025, 1.057851, 1, 0 } },
  { "PENTAX", "*ist D", NeutralFluorescent, 0,	{ 1.425781, 1, 1.117188, 0 } },
  { "PENTAX", "*ist D", WhiteFluorescent, 0,	{ 1.328125, 1, 1.210938, 0 } },
  { "PENTAX", "*ist D", Tungsten, 0,		{ 1.000000, 1, 2.226563, 0 } },
  { "PENTAX", "*ist D", Flash, 0,		{ 1.750000, 1, 1.000000, 0 } },

  /* It seems that the *ist DL WB settings are not really presets. */
  { "PENTAX", "*ist DL", Daylight, 0,		{ 1.546875, 1, 1.007812, 0 } },
  { "PENTAX", "*ist DL", Shade, 0,		{ 1.933594, 1, 1.027344, 0 } },
  { "PENTAX", "*ist DL", Cloudy, 0,		{ 1.703125, 1, 1.003906, 0 } },
  { "PENTAX", "*ist DL", DaylightFluorescent, 0, { 2.593909, 1.299492, 1, 0 } },
  { "PENTAX", "*ist DL", NeutralFluorescent, 0,	{ 1.539062, 1, 1.003906, 0 } },
  { "PENTAX", "*ist DL", WhiteFluorescent, 0,	{ 1.390625, 1, 1.117188, 0 } },
  { "PENTAX", "*ist DL", Tungsten, 0,		{ 1.000000, 1, 2.074219, 0 } },
  { "PENTAX", "*ist DL", Flash, 0,		{ 1.621094, 1, 1.027344, 0 } },

  /* It seems that the *ist DS WB settings are not really presets. */
  { "PENTAX", "*ist DS", Daylight, 0,		{ 1.632812, 1, 1, 0 } },
  { "PENTAX", "*ist DS", Shade, 0,		{ 1.964844, 1, 1, 0 } },
  { "PENTAX", "*ist DS", Cloudy, 0,		{ 1.761719, 1, 1, 0 } },
  { "PENTAX", "*ist DS", DaylightFluorescent, 0, { 1.910156, 1, 1, 0 } },
  { "PENTAX", "*ist DS", NeutralFluorescent, 0,	{ 1.521569, 1.003922, 1, 0 } },
  { "PENTAX", "*ist DS", WhiteFluorescent, 0,	{ 1.496094, 1, 1.023438, 0 } },
  { "PENTAX", "*ist DS", Tungsten, 0,		{ 1, 1, 2.027344, 0 } },
  { "PENTAX", "*ist DS", Flash, 0,		{ 1.695312, 1, 1, 0 } },

  { "PENTAX", "K10D", Daylight, 0,		{ 1.660156, 1, 1.066406, 0 } },
  { "PENTAX", "K10D", Shade, 0,			{ 2.434783, 1.236715, 1, 0 } },
  { "PENTAX", "K10D", Cloudy, 0,		{ 1.872428, 1.053498, 1, 0 } },
  { "PENTAX", "K10D", DaylightFluorescent, 0,	{ 2.121094, 1, 1.078125, 0 } },
  { "PENTAX", "K10D", NeutralFluorescent, 0,	{ 1.773438, 1, 1.226562, 0 } },
  { "PENTAX", "K10D", WhiteFluorescent, 0,	{ 1.597656, 1, 1.488281, 0 } },
  { "PENTAX", "K10D", Tungsten, 0,		{ 1.000000, 1, 2.558594, 0 } },
  { "PENTAX", "K10D", Flash, 0,			{ 1.664062, 1, 1.046875, 0 } },

  { "PENTAX", "K20D", Daylight, 0,		{ 1.691406, 1, 1.257812, 0 } },
  { "PENTAX", "K20D", Shade, 0,			{ 2.012245, 1.299492, 1, 0 } },
  { "PENTAX", "K20D", Cloudy, 0,		{ 1.792969, 1, 1.109375, 0 } },
  { "PENTAX", "K20D", DaylightFluorescent, 0,	{ 2.234375, 1, 1.183594, 0 } },
  { "PENTAX", "K20D", NeutralFluorescent, 0,	{ 1.898438, 1, 1.347656, 0 } },
  { "PENTAX", "K20D", WhiteFluorescent, 0,	{ 1.769531, 1, 1.675781, 0 } },
  { "PENTAX", "K20D", Tungsten, 0,		{ 1, 1.089362, 2.961702, 0 } },
  { "PENTAX", "K20D", Flash, 0,			{ 1.792969, 1, 1.183594, 0 } },

  { "PENTAX", "K100D", Daylight, 0,		{ 1.468750, 1, 1.023438, 0 } },
  { "PENTAX", "K100D", Shade, 0,		{ 1.769531, 1, 1, 0 } },
  { "PENTAX", "K100D", Cloudy, 0,		{ 1.589844, 1, 1, 0 } },
  { "PENTAX", "K100D", DaylightFluorescent, 0,	{ 1.722656, 1, 1.039063, 0 } },
  { "PENTAX", "K100D", NeutralFluorescent, 0,	{ 1.425781, 1, 1.160156, 0 } },
  { "PENTAX", "K100D", WhiteFluorescent, 0,	{ 1.265625, 1, 1.414063, 0 } },
  { "PENTAX", "K100D", Tungsten, 0,		{ 1, 1.015873, 2.055556, 0 } },
  { "PENTAX", "K100D", Flash, 0,		{ 1.527344, 1, 1, 0 } },

  { "PENTAX", "K100D Super", Daylight, 0,	{ 1.593750, 1, 1.011719, 0 } },
  { "PENTAX", "K100D Super", Shade, 0,		{ 1.917969, 1, 1, 0 } },
  { "PENTAX", "K100D Super", Cloudy, 0,		{ 1.703125, 1, 1.015625, 0 } },
  { "PENTAX", "K100D Super", DaylightFluorescent, 0, { 1.708502, 1.036437, 1, 0 } },
  { "PENTAX", "K100D Super", NeutralFluorescent, 0, { 1.634538, 1.028112, 1, 0 } },
  { "PENTAX", "K100D Super", WhiteFluorescent, 0, { 1.425781, 1, 1.136719, 0 } },
  { "PENTAX", "K100D Super", Tungsten, 0,	{ 1.015625, 1, 2.046875, 0 } },
  { "PENTAX", "K100D Super", Flash, 0,		{ 1.670588, 1.003922, 1, 0 } },

  { "PENTAX", "K110D", Daylight, 0,		{ 1.468750, 1, 1.023438, 0 } },
  { "PENTAX", "K110D", Shade, 0,		{ 1.769531, 1, 1, 0 } },
  { "PENTAX", "K110D", Cloudy, 0,		{ 1.589844, 1, 1, 0 } },
  { "PENTAX", "K110D", DaylightFluorescent, 0,	{ 1.722656, 1, 1.039063, 0 } },
  { "PENTAX", "K110D", NeutralFluorescent, 0,	{ 1.425781, 1, 1.160156, 0 } },
  { "PENTAX", "K110D", WhiteFluorescent, 0,	{ 1.265625, 1, 1.414063, 0 } },
  { "PENTAX", "K110D", Tungsten, 0,		{ 1, 1.015873, 2.055556, 0 } },
  { "PENTAX", "K110D", Flash, 0,		{ 1.527344, 1, 1, 0 } },

  { "PENTAX", "K200D", Daylight, 0,		{ 1.804688, 1, 1.304688, 0 } },
  { "PENTAX", "K200D", Shade, 0,		{ 2.140625, 1, 1.085937, 0 } },
  { "PENTAX", "K200D", Cloudy, 0,		{ 1.957031, 1, 1.179687, 0 } },
  { "PENTAX", "K200D", DaylightFluorescent, 0,	{ 2.121094, 1, 1.195313, 0 } },
  { "PENTAX", "K200D", NeutralFluorescent, 0,	{ 1.773438, 1, 1.359375, 0 } },
  { "PENTAX", "K200D", WhiteFluorescent, 0,	{ 1.597656, 1, 1.648437, 0 } },
  { "PENTAX", "K200D", Tungsten, 0,		{ 1.000000, 1, 2.835937, 0 } },
  { "PENTAX", "K200D", Flash, 0,		{ 1.917969, 1, 1.214844, 0 } },

  { "RICOH", "Caplio GX100", Daylight, 0,	{ 1.910001, 1, 1.820002, 0 } },
  { "RICOH", "Caplio GX100", Cloudy, 0,		{ 2.240003, 1, 1.530002, 0 } },
  { "RICOH", "Caplio GX100", Incandescent, 0,	{ 1.520002, 1, 2.520003, 0 } },
  { "RICOH", "Caplio GX100", Fluorescent, 0,	{ 1.840001, 1, 1.970001, 0 } },

  { "SAMSUNG", "GX-1S", Daylight, 0,		{ 1.574219, 1, 1.109375, 0 } },
  { "SAMSUNG", "GX-1S", Shade, 0,		{ 1.855469, 1, 1.000000, 0 } },
  { "SAMSUNG", "GX-1S", Cloudy, 0,		{ 1.664062, 1, 1.000000, 0 } },
  { "SAMSUNG", "GX-1S", DaylightFluorescent, 0,	{ 1.854251, 1.036437, 1, 0 } },
  { "SAMSUNG", "GX-1S", NeutralFluorescent, 0,	{ 1.574219, 1, 1.171875, 0 } },
  { "SAMSUNG", "GX-1S", WhiteFluorescent, 0,	{ 1.363281, 1, 1.335938, 0 } },
  { "SAMSUNG", "GX-1S", Tungsten, 0,		{ 1.000000, 1, 2.226562, 0 } },
  { "SAMSUNG", "GX-1S", Flash, 0,		{ 1.609375, 1, 1.031250, 0 } },

  { "SAMSUNG", "GX10", Daylight, 0,		{ 1.660156, 1, 1.066406, 0 } },
  { "SAMSUNG", "GX10", Shade, 0,		{ 2.434783, 1.236715, 1, 0 } },
  { "SAMSUNG", "GX10", Cloudy, 0,		{ 1.872428, 1.053498, 1, 0 } },
  { "SAMSUNG", "GX10", DaylightFluorescent, 0,	{ 2.121094, 1, 1.078125, 0 } },
  { "SAMSUNG", "GX10", NeutralFluorescent, 0,	{ 1.773438, 1, 1.226562, 0 } },
  { "SAMSUNG", "GX10", WhiteFluorescent, 0,	{ 1.597656, 1, 1.488281, 0 } },
  { "SAMSUNG", "GX10", Tungsten, 0,		{ 1.000000, 1, 2.558594, 0 } },
  { "SAMSUNG", "GX10", Flash, 0,		{ 1.664062, 1, 1.046875, 0 } },

  { "SONY", "DSLR-A100", Daylight, -3,		{ 1.601562, 1, 2.101562, 0 } },
  { "SONY", "DSLR-A100", Daylight, 0,		{ 1.746094, 1, 1.843750, 0 } },
  { "SONY", "DSLR-A100", Daylight, 3,		{ 1.914062, 1, 1.628906, 0 } },
  { "SONY", "DSLR-A100", Shade, -3,		{ 1.906250, 1, 1.843750, 0 } },
  { "SONY", "DSLR-A100", Shade, 0,		{ 2.070312, 1, 1.609375, 0 } },
  { "SONY", "DSLR-A100", Shade, 3,		{ 2.281250, 1, 1.429688, 0 } },
  { "SONY", "DSLR-A100", Cloudy, -3,		{ 1.691406, 1, 1.863281, 0 } },
  { "SONY", "DSLR-A100", Cloudy, 0,		{ 1.855469, 1, 1.628906, 0 } },
  { "SONY", "DSLR-A100", Cloudy, 3,		{ 2.023438, 1, 1.445312, 0 } },
  { "SONY", "DSLR-A100", Tungsten, -3,		{ 1, 1.028112, 4.610442, 0 } },
  { "SONY", "DSLR-A100", Tungsten, 0,		{ 1.054688, 1, 3.917969, 0 } },
  { "SONY", "DSLR-A100", Tungsten, 3,		{ 1.164062, 1, 3.476562, 0 } },
  { "SONY", "DSLR-A100", Fluorescent, -2,	{ 1.058594, 1, 4.453125, 0 } },
  { "SONY", "DSLR-A100", Fluorescent, 0,	{ 1.718750, 1, 3.058594, 0 } },
  { "SONY", "DSLR-A100", Fluorescent, 3,	{ 2.238281, 1, 1.949219, 0 } },
  { "SONY", "DSLR-A100", Fluorescent, 4,	{ 1.992188, 1, 1.757812, 0 } },
  { "SONY", "DSLR-A100", Flash, -3,		{ 1.710938, 1, 1.988281, 0 } },
  { "SONY", "DSLR-A100", Flash, 0,		{ 1.859375, 1, 1.746094, 0 } },
  { "SONY", "DSLR-A100", Flash, 3,		{ 2.046875, 1, 1.542969, 0 } },

  { "SONY", "DSLR-A200", Daylight, -3 ,		{ 1.507812, 1, 1.996094, 0 } },
  { "SONY", "DSLR-A200", Daylight, 0 ,		{ 1.664062, 1, 1.757812, 0 } },
  { "SONY", "DSLR-A200", Daylight, 3 ,		{ 1.820313, 1, 1.546875, 0 } },
  { "SONY", "DSLR-A200", Shade, -3 ,		{ 1.800781, 1, 1.578125, 0 } },
  { "SONY", "DSLR-A200", Shade, 0 ,		{ 1.972656, 1, 1.390625, 0 } },
  { "SONY", "DSLR-A200", Shade, 3 ,		{ 2.164063, 1, 1.218750, 0 } },
  { "SONY", "DSLR-A200", Cloudy, -3 ,		{ 1.636719, 1, 1.800781, 0 } },
  { "SONY", "DSLR-A200", Cloudy, 0 ,		{ 1.800781, 1, 1.585937, 0 } },
  { "SONY", "DSLR-A200", Cloudy, 3 ,		{ 1.972656, 1, 1.390625, 0 } },
  { "SONY", "DSLR-A200", Tungsten, -3 ,		{ 1, 1.136719, 4.355469, 0 } },
  { "SONY", "DSLR-A200", Tungsten, 0 ,		{ 1, 1.027344, 3.492187, 0 } },
  { "SONY", "DSLR-A200", Tungsten, 3 ,		{ 1.082031, 1, 3.019531, 0 } },
  { "SONY", "DSLR-A200", Fluorescent, -2 ,	{ 1, 1.066406, 4.453125, 0 } },
  { "SONY", "DSLR-A200", Fluorescent, 0 ,	{ 1.554687, 1, 2.601562, 0 } },
  { "SONY", "DSLR-A200", Fluorescent, 3 ,	{ 2.109375, 1, 1.828125, 0 } },
  { "SONY", "DSLR-A200", Flash, -3 ,		{ 1.746094, 1, 1.660156, 0 } },
  { "SONY", "DSLR-A200", Flash, 0 ,		{ 1.917969, 1, 1.460937, 0 } },
  { "SONY", "DSLR-A200", Flash, 3 ,		{ 2.109375, 1, 1.285156, 0 } },
  { "SONY", "DSLR-A200", "5600K", 0 ,		{ 1.710938, 1, 1.683594, 0 } },

  { "SONY", "DSLR-A300", Daylight, -3,		{ 1.480469, 1, 1.960937, 0 } },
  { "SONY", "DSLR-A300", Daylight, 0,		{ 1.632813, 1, 1.730469, 0 } },
  { "SONY", "DSLR-A300", Daylight, 3,		{ 1.789062, 1, 1.527344, 0 } },
  { "SONY", "DSLR-A300", Shade, -3,		{ 1.769531, 1, 1.554687, 0 } },
  { "SONY", "DSLR-A300", Shade, 0,		{ 1.937500, 1, 1.371094, 0 } },
  { "SONY", "DSLR-A300", Shade, 3,		{ 2.121094, 1, 1.207031, 0 } },
  { "SONY", "DSLR-A300", Cloudy, -3,		{ 1.609375, 1, 1.769531, 0 } },
  { "SONY", "DSLR-A300", Cloudy, 0,		{ 1.769531, 1, 1.566406, 0 } },
  { "SONY", "DSLR-A300", Cloudy, 3,		{ 1.937500, 1, 1.371094, 0 } },
  { "SONY", "DSLR-A300", Tungsten, -3,		{ 1, 1.152344, 4.308594, 0 } },
  { "SONY", "DSLR-A300", Tungsten, 0,		{ 1, 1.039063, 3.449219, 0 } },
  { "SONY", "DSLR-A300", Tungsten, 3,		{ 1.066406, 1, 2.953125, 0 } },
  { "SONY", "DSLR-A300", Fluorescent, -2,	{ 1, 1.082031, 4.410156, 0 } },
  { "SONY", "DSLR-A300", Fluorescent, -1,	{ 1.117187, 1, 3.343750, 0 } },
  { "SONY", "DSLR-A300", Fluorescent, 0,	{ 1.527344, 1, 2.546875, 0 } },
  { "SONY", "DSLR-A300", Fluorescent, 1,	{ 1.714844, 1, 2.109375, 0 } },
  { "SONY", "DSLR-A300", Fluorescent, 2,	{ 1.546875, 1, 1.769531, 0 } },
  { "SONY", "DSLR-A300", Fluorescent, 3,	{ 2.070312, 1, 1.796875, 0 } },
  { "SONY", "DSLR-A300", Fluorescent, 4,	{ 1.761719, 1, 1.527344, 0 } },
  { "SONY", "DSLR-A300", Flash, -3,		{ 1.714844, 1, 1.632812, 0 } },
  { "SONY", "DSLR-A300", Flash, 0,		{ 1.882812, 1, 1.441406, 0 } },
  { "SONY", "DSLR-A300", Flash, 3,		{ 2.070312, 1, 1.273438, 0 } },

  /* Sony A700 presets - firmware v2 */
  { "SONY", "DSLR-A700", Daylight, -3,		{ 1.937500, 1, 1.640625, 0 } },
  { "SONY", "DSLR-A700", Daylight, 0,		{ 2.101563, 1, 1.484375, 0 } },
  { "SONY", "DSLR-A700", Daylight, 3,		{ 2.273437, 1, 1.343750, 0 } },
  { "SONY", "DSLR-A700", Shade, -3,		{ 2.257812, 1, 1.359375, 0 } },
  { "SONY", "DSLR-A700", Shade, 0,		{ 2.445313, 1, 1.226563, 0 } },
  { "SONY", "DSLR-A700", Shade, 3,		{ 2.652344, 1, 1.113281, 0 } },
  { "SONY", "DSLR-A700", Cloudy, -3,		{ 2.070312, 1, 1.507812, 0 } },
  { "SONY", "DSLR-A700", Cloudy, 0,		{ 2.250000, 1, 1.367188, 0 } },
  { "SONY", "DSLR-A700", Cloudy, 3,		{ 2.429688, 1, 1.234375, 0 } },
  { "SONY", "DSLR-A700", Tungsten, -3,		{ 1.230469, 1, 2.859375, 0 } },
  { "SONY", "DSLR-A700", Tungsten, 0,		{ 1.335938, 1, 2.597656, 0 } },
  { "SONY", "DSLR-A700", Tungsten, 3,		{ 1.449219, 1, 2.343750, 0 } },
  { "SONY", "DSLR-A700", Fluorescent, -2,	{ 1.292969, 1, 3.199219, 0 } },
  { "SONY", "DSLR-A700", Fluorescent, 0,	{ 1.878906, 1, 2.152344, 0 } },
  { "SONY", "DSLR-A700", Fluorescent, 3,	{ 2.433594, 1, 1.539063, 0 } },
  { "SONY", "DSLR-A700", Fluorescent, 4,	{ 2.273437, 1, 1.347656, 0 } },
  { "SONY", "DSLR-A700", Flash, -3,		{ 2.128906, 1, 1.460937, 0 } },
  { "SONY", "DSLR-A700", Flash, 0,		{ 2.277344, 1, 1.312500, 0 } },
  { "SONY", "DSLR-A700", Flash, 3,		{ 2.496094, 1, 1.199219, 0 } },

};

const int wb_preset_count = sizeof(wb_preset) / sizeof(wb_data);
