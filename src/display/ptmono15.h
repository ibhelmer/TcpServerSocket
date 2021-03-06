// This software is part of OpenMono, see http://developer.openmono.com
// and is available under the MIT license, see LICENSE.txt

#include "font_interface.h"

namespace mono { namespace display {

static const unsigned char pt_mono_15_4bit_bitmap[] = {
  0xff,
  0xff,0xff,0xff,0xff,0xff,0xfd,0xc,0xff,0xff,0xff,0x46,0xf5,0x4f,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0x80,0x0,0x1d,0xff,0xe1,0x5,0xff,0x28,0xff,0xff,0x40,0x8,
  0xff,0xff,0xff,0xfd,0xc,0xff,0xff,0xff,0xff,0xd6,0x4f,0xff,0xff,0x46,0xdf,0xff,
  0xff,0xff,0x36,0xf7,0x2f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x64,0xff,0xff,
  0x80,0x0,0x7f,0xff,0xff,0xfd,0x19,0xff,0xff,0xfd,0x50,0x0,0x7f,0xff,0xf4,0x0,
  0x0,0xc,0xff,0xff,0xff,0xf5,0x4f,0xff,0xfe,0x10,0x0,0xc,0xff,0xff,0xff,0x90,
  0x3f,0xff,0xe1,0x0,0x0,0x5,0xff,0xff,0x80,0x0,0x6f,0xff,0xff,0x60,0x0,0x7f,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x40,0x0,0x6f,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfa,0xa,0xff,0xff,0xf9,0x0,0x0,0x6e,0xff,0xff,0xd5,
  0x0,0x3,0xef,0xf4,0x0,0x4,0xcf,0xff,0xf9,0x0,0x0,0x4,0xff,0xfc,0x0,0x0,
  0x4,0xff,0xff,0xc3,0x0,0x5,0xff,0xd0,0xcf,0xff,0xc0,0xcf,0xc0,0x0,0x0,0x0,
  0xcf,0xf8,0x0,0x0,0xa,0xff,0xf4,0x8f,0xff,0xb0,0xaf,0xf5,0x4f,0xff,0xff,0xff,
  0xd0,0xaf,0xff,0xb0,0xcf,0xe1,0xcf,0xff,0xc1,0xef,0xff,0x80,0x0,0x7f,0xff,0xf9,
  0x0,0x0,0x8f,0xff,0xff,0x80,0x0,0x7f,0xff,0xf9,0x0,0x0,0x9f,0xff,0xff,0x70,
  0x0,0xb,0xff,0x90,0x0,0x0,0x0,0xaf,0xd0,0xcf,0xff,0xd0,0xcf,0x44,0xff,0xff,
  0xf6,0x4f,0x48,0xff,0xff,0xf9,0x4f,0xb0,0xaf,0xff,0xd0,0x9f,0x42,0xff,0xff,0xf4,
  0x3f,0xc0,0x0,0x0,0x0,0xcf,0xff,0x50,0x0,0x9,0xff,0xf4,0x6f,0xff,0xff,0xff,
  0xfa,0x0,0x0,0x4f,0xff,0xff,0xfe,0xb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xf2,0x1e,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x10,0x9f,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xf4,0x5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0x30,
  0x5,0xff,0xff,0xff,0xff,0xff,0xfe,0x10,0x9f,0xff,0xff,0xff,0xff,0xfd,0x5,0xff,
  0xff,0xff,0xff,0x90,0xbf,0xff,0x40,0x4f,0xff,0xff,0xff,0xfc,0x0,0xcf,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x70,0x3,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xf4,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfc,0xc,0xff,0xff,0xff,0x48,0xf4,0x4f,0xff,0xff,0xf3,
  0x9f,0x65,0xff,0xfa,0x8,0x4a,0x8f,0xff,0x82,0xb0,0xcc,0xd,0xff,0xfb,0xc,0xa1,
  0xef,0xff,0xff,0xfc,0xc,0xff,0xff,0xff,0xfa,0x1,0x9f,0xff,0xff,0x91,0xa,0xff,
  0xff,0xff,0x91,0xb1,0xaf,0xff,0xff,0xff,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x1a,0xff,0xfa,
  0x8,0xe8,0x8,0xff,0xff,0x90,0x8,0xff,0xff,0xfb,0x2b,0xd8,0xa,0xff,0xfb,0xaa,
  0xa1,0xc,0xff,0xff,0xff,0x80,0x4f,0xff,0xfe,0x17,0xaa,0xae,0xff,0xff,0xe2,0x8,
  0xdf,0xff,0xfa,0xaa,0xa9,0x5,0xff,0xf9,0x8,0xd9,0x8,0xff,0xf4,0xa,0xe9,0x5,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe8,0xef,
  0xff,0xff,0xff,0xff,0xff,0xe8,0xef,0xff,0xff,0xff,0xd0,0x2b,0xd7,0x6,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xf4,0x4,0xff,0xff,0xf9,0x2b,0xb7,0x4,0xff,0xfe,0x10,
  0x8c,0x81,0xef,0xf4,0x5c,0x91,0xa,0xff,0xf9,0x9,0xaa,0xab,0xff,0xfc,0x9,0xaa,
  0xab,0xff,0xfc,0x1,0xac,0x54,0xff,0xc0,0xcf,0xff,0xc0,0xcf,0xe9,0xa7,0x7,0xaa,
  0xff,0xfc,0xaa,0xa9,0x8,0xff,0xf4,0x8f,0xfe,0x14,0xff,0xf4,0x4f,0xff,0xff,0xff,
  0xc0,0x1e,0xff,0x20,0xcf,0xe1,0x3f,0xff,0xc1,0xef,0xf8,0x7,0xc6,0x7,0xff,0xf9,
  0x2b,0xb6,0x4,0xff,0xf8,0x7,0xc6,0x7,0xff,0xf9,0x2b,0xb5,0xa,0xff,0xf6,0x7,
  0xcb,0x28,0xff,0x90,0xa7,0x7,0xa1,0x8f,0xc0,0xcf,0xff,0xc0,0xcf,0x90,0xdf,0xff,
  0xe1,0x8f,0x54,0xff,0xff,0xf7,0x4f,0xf3,0x1e,0xff,0x42,0xef,0xb0,0x9f,0xff,0xb0,
  0xbf,0xe9,0xaa,0xaa,0x0,0xcf,0xff,0x45,0xbb,0xac,0xff,0xf9,0x1e,0xff,0xff,0xff,
  0xfd,0xab,0xb5,0x4f,0xff,0xff,0xf6,0x2,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xfe,0x19,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc2,0x8f,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfd,0x54,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf4,0x1b,
  0xbb,0xff,0xff,0xff,0xff,0xff,0xff,0xb1,0x8f,0xff,0xff,0xff,0xff,0xfc,0x4,0xff,
  0xff,0xff,0xff,0x80,0x9f,0xff,0xd5,0x4f,0xff,0xff,0xff,0xff,0xa0,0xcf,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0x8,0xbc,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xfc,0xb8,0x6,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfc,0xc,0xff,0xff,0xff,0x48,0xf4,0x8f,0xff,0xff,0xe1,
  0xdf,0x3a,0xff,0xf8,0x2f,0x6e,0xff,0xff,0x68,0xf2,0xc4,0x6f,0xff,0xfb,0xe,0xb1,
  0xef,0xff,0xff,0xfc,0x1e,0xff,0xff,0xff,0xc0,0x5f,0xff,0xff,0xff,0xff,0x50,0xcf,
  0xff,0xfe,0xe3,0x3,0xee,0xff,0xff,0xfe,0xe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0x1e,0xff,0xf2,
  0x5f,0xff,0x52,0xff,0xf5,0x7,0x28,0xff,0xff,0xff,0xff,0xff,0x28,0xff,0xff,0xff,
  0xc0,0x8f,0xff,0xff,0xfb,0x0,0x4f,0xff,0xfe,0x1c,0xff,0xff,0xff,0xff,0x30,0xdf,
  0xff,0xff,0xff,0xff,0xfc,0xc,0xff,0xf4,0x3f,0xff,0x43,0xff,0xe1,0xaf,0xff,0x71,
  0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa,0x0,0xcf,
  0xff,0xff,0xff,0xff,0xff,0xc0,0xa,0xff,0xff,0xff,0xfa,0xff,0xff,0x54,0xff,0xff,
  0xfd,0xaa,0xcf,0xff,0xff,0xd0,0x40,0xdf,0xff,0xf8,0x4f,0xff,0x63,0xff,0xf8,0xb,
  0xff,0xc0,0xef,0xf4,0x8f,0xfe,0x12,0xff,0xf9,0x1e,0xff,0xff,0xff,0xfc,0x1e,0xff,
  0xff,0xff,0xf4,0x1e,0xff,0x82,0xff,0xc0,0xcf,0xff,0xc0,0xcf,0xff,0xfd,0xc,0xff,
  0xff,0xff,0xff,0xfe,0x18,0xff,0xf4,0x8f,0xf4,0x1e,0xff,0xf4,0x4f,0xff,0xff,0xff,
  0xc0,0x7,0xf9,0x0,0xcf,0xe1,0x9,0xff,0xc1,0xef,0xe1,0x5f,0xff,0x41,0xef,0xf8,
  0x4f,0xff,0x61,0xef,0xe1,0x5f,0xff,0x41,0xef,0xf8,0x4f,0xfe,0x15,0xff,0xf4,0x5f,
  0xff,0x37,0xff,0x73,0xfd,0xc,0xf3,0x7f,0xc0,0xcf,0xff,0xc0,0xcf,0xd0,0x9f,0xff,
  0xb0,0xdf,0x82,0xff,0xff,0xf4,0x8f,0xfc,0x8,0xfb,0xb,0xff,0xf4,0x1e,0xff,0x24,
  0xff,0xff,0xff,0xfc,0x7,0xff,0xff,0x48,0xff,0xff,0xff,0xfe,0x19,0xff,0xff,0xff,
  0xff,0xff,0xf9,0x4f,0xff,0xff,0xc0,0x91,0x9f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xdd,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf4,0x8f,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0x94,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe1,0x9f,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf4,0x8f,0xff,0xff,0xff,0xff,0xff,0xef,0xff,
  0xff,0xff,0xff,0xfe,0xff,0xff,0xf9,0x4f,0xff,0xff,0xff,0xff,0xf1,0xcf,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf4,0x5f,0xff,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xff,0xff,0x53,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfc,0xc,0xff,0xff,0xff,0x4b,0xf4,0x7f,0xff,0xfb,0x70,
  0x89,0x4,0xdf,0xf8,0x1d,0x6e,0xff,0xff,0x75,0xe1,0x70,0xdf,0xff,0xfd,0x15,0x17,
  0xff,0xff,0xff,0xfc,0x1e,0xff,0xff,0xff,0x42,0xff,0xff,0xff,0xff,0xff,0xf2,0x4f,
  0xff,0xc0,0x0,0x0,0x0,0xbf,0xff,0xfe,0x2e,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf2,0x7f,0xff,0xe0,
  0xbf,0xfb,0x1,0xef,0xfa,0xaf,0x48,0xff,0xff,0xff,0xff,0xff,0x47,0xff,0xff,0xfe,
  0x15,0xff,0xff,0xff,0xe1,0x69,0x4f,0xff,0xfe,0x1c,0xff,0xff,0xff,0xfb,0xc,0xff,
  0xff,0xff,0xff,0xff,0xf4,0x4f,0xff,0xf5,0x2e,0xff,0x26,0xff,0xe0,0xbf,0xff,0xc0,
  0xdf,0xff,0xfa,0xa,0xff,0xff,0xff,0xfb,0x9,0xff,0xff,0xff,0xfe,0x40,0x4d,0xff,
  0xfe,0xee,0xee,0xee,0xff,0xfe,0x40,0x3d,0xff,0xff,0xff,0xff,0xff,0x83,0xff,0xff,
  0x70,0x0,0x9,0xff,0xff,0x91,0xd1,0x9f,0xff,0xf8,0x4f,0xff,0x43,0xff,0xe2,0x4f,
  0xff,0xed,0xff,0xf4,0x8f,0xff,0xa0,0xcf,0xf9,0x1e,0xff,0xff,0xff,0xfc,0x1e,0xff,
  0xff,0xff,0xe1,0x8f,0xff,0xed,0xff,0xc0,0xcf,0xff,0xc0,0xcf,0xff,0xfc,0xc,0xff,
  0xff,0xff,0xff,0xfe,0x18,0xff,0xf4,0x8f,0x90,0xbf,0xff,0xf4,0x4f,0xff,0xff,0xff,
  0xc0,0x0,0x91,0x0,0xcf,0xe1,0x0,0xdf,0xc1,0xef,0xc0,0xbf,0xff,0xb0,0xcf,0xf8,
  0x4f,0xff,0xb1,0xef,0xc0,0xbf,0xff,0xb0,0xcf,0xf8,0x4f,0xff,0x44,0xff,0xf4,0x3e,
  0xff,0xde,0xff,0xed,0xfc,0xc,0xfd,0xef,0xc0,0xcf,0xff,0xc0,0xcf,0xf3,0x4f,0xff,
  0x62,0xff,0xb1,0xef,0xae,0xf2,0xaf,0xff,0x71,0xc2,0x5f,0xff,0xfd,0x7,0xfa,0xd,
  0xff,0xff,0xff,0xe1,0x2f,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0x72,0xff,0xff,0xff,
  0xff,0xff,0xf8,0x4f,0xff,0xff,0x26,0xf8,0x1e,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xfe,0x84,0x2,0xcf,0xff,0xf4,0x47,0x0,0x6e,0xff,0xff,0xb2,
  0x0,0x4b,0xff,0xff,0xb4,0x1,0x4,0xff,0xff,0xb2,0x0,0x8f,0xff,0xf7,0x40,0x14,
  0x3a,0xff,0xff,0xc5,0x0,0x49,0xff,0xf4,0x57,0x0,0x4d,0xff,0xfa,0x34,0x5a,0xff,
  0xff,0xf9,0x34,0x55,0xdf,0xff,0xf8,0x4f,0xff,0x75,0xff,0xff,0xe1,0xcf,0xff,0xff,
  0xa8,0x50,0x99,0x3,0xef,0x74,0xb9,0x0,0x5e,0xff,0xff,0x90,0x1,0xaf,0xff,0x74,
  0x98,0x0,0x5d,0xff,0xff,0xc4,0x0,0x4a,0xff,0xe5,0x46,0xc5,0x4,0xff,0xff,0xa1,
  0x0,0x7d,0xff,0xa3,0x2,0x44,0x3a,0xff,0x74,0xaf,0xfa,0x49,0xff,0xc3,0xdf,0xff,
  0xd4,0xcf,0x6a,0xff,0xff,0xfb,0x6f,0xe4,0x8f,0xff,0xa4,0xef,0xc3,0xcf,0xff,0xe4,
  0xcf,0xf7,0x44,0x45,0x58,0xff,0xff,0xf4,0x8f,0xff,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xff,0xff,0x94,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfc,0xc,0xff,0xff,0xff,0x3b,0xf4,0xaf,0xff,0xf7,0x0,
  0x52,0x4,0xaf,0xfc,0x0,0x1e,0xff,0xff,0xb0,0x0,0x6,0xff,0xff,0xfe,0x10,0x6f,
  0xff,0xff,0xff,0xfc,0x1e,0xff,0xff,0xfd,0xa,0xff,0xff,0xff,0xff,0xff,0xfb,0xd,
  0xff,0xfc,0xd2,0x2,0xdc,0xff,0xff,0xfe,0x2e,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xb0,0xef,0xff,0xc0,
  0xcf,0xa0,0x0,0xcf,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0xfd,0xb,0xff,0xff,0xf4,
  0xd,0xff,0xff,0xff,0x32,0xf9,0x4f,0xff,0xfe,0x14,0x79,0xef,0xff,0xf4,0x5d,0xab,
  0xef,0xff,0xff,0xff,0xc0,0xcf,0xff,0xfd,0x1,0xb6,0xd,0xff,0xe1,0x8f,0xff,0xb0,
  0xdf,0xff,0xf8,0x7,0xff,0xff,0xff,0xf9,0x5,0xff,0xff,0xff,0x90,0x1b,0xff,0xff,
  0xe0,0x0,0x0,0x0,0xef,0xff,0xfb,0x10,0x8f,0xff,0xff,0xff,0xfc,0x8,0xff,0xf6,
  0xb,0xff,0x42,0xff,0xff,0x35,0xf5,0x3f,0xff,0xf9,0x3e,0xd7,0xb,0xff,0xe1,0x8f,
  0xff,0xff,0xff,0xf4,0x8f,0xff,0xc0,0xcf,0xf9,0x1c,0xdd,0xde,0xff,0xfc,0x1d,0xff,
  0xff,0xff,0xc0,0xcf,0xff,0xff,0xff,0xc0,0x9e,0xee,0xa0,0xcf,0xff,0xfc,0xc,0xff,
  0xff,0xff,0xff,0xfe,0x18,0xff,0xf4,0x6d,0x8,0xff,0xff,0xf4,0x4f,0xff,0xff,0xff,
  0xc0,0xa2,0x2,0xb0,0xcf,0xe1,0x91,0x4f,0xc1,0xef,0xc0,0xcf,0xff,0xc0,0xcf,0xf8,
  0x4f,0xff,0x71,0xef,0xc0,0xcf,0xff,0xc0,0xcf,0xf8,0x4f,0xfa,0xa,0xff,0xfa,0x0,
  0xaf,0xff,0xff,0xff,0xfc,0xc,0xff,0xff,0xc0,0xcf,0xff,0xc0,0xcf,0xf9,0xd,0xff,
  0x28,0xff,0xc0,0xdc,0xa,0xe1,0xcf,0xff,0xe1,0x1,0xef,0xff,0xff,0x70,0xb2,0x6f,
  0xff,0xff,0xff,0x50,0xdf,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0xd0,0xaf,0xff,0xff,
  0xff,0xff,0xf8,0x4f,0xff,0xf8,0x1e,0xff,0x26,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xfb,0x8,0xa4,0x1e,0xff,0xf4,0x3,0xb8,0x4,0xff,0xf9,0x3,
  0xaa,0x33,0xff,0xf8,0x5,0xb9,0x24,0xff,0xf9,0x6,0xb9,0x5,0xff,0xfb,0x70,0x79,
  0x8c,0xff,0xfb,0x3,0xaa,0x51,0xef,0xf4,0x1,0xa9,0x5,0xff,0xfd,0x89,0x18,0xff,
  0xff,0xfa,0x99,0x80,0xcf,0xff,0xf8,0x4f,0xf5,0xc,0xff,0xff,0xe1,0xcf,0xff,0xff,
  0x90,0x47,0x1,0x80,0x9f,0xa2,0x0,0x98,0x5,0xff,0xf8,0x7,0xc7,0x7,0xff,0xa1,
  0x0,0x88,0x1,0xef,0xf9,0x4,0xba,0x33,0xff,0xfa,0x70,0x6,0x90,0xcf,0xfa,0x7,
  0xc9,0x18,0xff,0xc8,0x14,0x99,0x8c,0xff,0xb1,0x8f,0xfc,0x4,0xff,0xe1,0x6f,0xff,
  0x81,0xef,0x45,0xff,0xef,0xf8,0x3f,0xf9,0x9,0xfb,0x9,0xff,0xe1,0x5f,0xff,0xb0,
  0xdf,0xfa,0x99,0x95,0x4,0xff,0xff,0xf4,0x8f,0xff,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xff,0xff,0x84,0xff,0xff,0xff,0xa9,0xcf,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfc,0xc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x58,
  0xf9,0x4f,0xff,0xff,0xc1,0x1,0xcf,0xff,0xfd,0xba,0xc,0xcd,0xff,0xe2,0x22,0x4f,
  0xf5,0xaf,0xff,0xff,0xff,0xff,0xff,0xfc,0x1e,0xff,0xff,0xff,0xff,0xff,0xfe,0x1c,
  0xff,0xff,0x91,0xc1,0xaf,0xff,0xc0,0x0,0x0,0x0,0xcf,0xff,0xff,0xff,0xff,0xff,
  0xff,0xee,0xee,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x35,0xff,0xff,0xd0,
  0xb9,0x8,0xb0,0xcf,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0xf3,0x3f,0xff,0xff,0xc0,
  0x0,0x4e,0xff,0xf7,0x1e,0xf9,0x4f,0xff,0xff,0x87,0x50,0x1d,0xff,0xe1,0x0,0x10,
  0xa,0xff,0xff,0xff,0x43,0xff,0xff,0xff,0x80,0x0,0x7f,0xff,0xf8,0x3,0x85,0x1,
  0xef,0xff,0xff,0xcf,0xff,0xff,0xff,0xff,0xcf,0xff,0xff,0xc1,0x9,0xff,0xff,0xff,
  0xfe,0xee,0xee,0xee,0xff,0xff,0xff,0xf9,0x1,0xcf,0xff,0xff,0xa0,0x6f,0xff,0xc0,
  0xbf,0xff,0xb1,0xef,0xfd,0xb,0xfa,0xd,0xff,0xf9,0x0,0x0,0x1e,0xff,0xe1,0xaf,
  0xff,0xff,0xff,0xf4,0x8f,0xff,0xd0,0xcf,0xf9,0x0,0x0,0x6,0xff,0xfc,0x0,0x0,
  0x6,0xff,0xc0,0xcf,0xd9,0x9a,0xff,0xc0,0x0,0x0,0x0,0xcf,0xff,0xfc,0xc,0xff,
  0xff,0xff,0xff,0xfe,0x18,0xff,0xf4,0x0,0xd,0xff,0xff,0xf4,0x4f,0xff,0xff,0xff,
  0xc0,0xcb,0xb,0xd0,0xcf,0xe1,0xc9,0xa,0xd1,0xef,0xc0,0xef,0xff,0xe0,0xcf,0xf9,
  0x2c,0xb6,0x5,0xff,0xc0,0xef,0xff,0xe0,0xcf,0xf9,0x0,0x0,0x5f,0xff,0xff,0xb2,
  0x0,0x9f,0xff,0xff,0xfc,0xc,0xff,0xff,0xc0,0xcf,0xff,0xc0,0xcf,0xfd,0x9,0xfc,
  0xd,0xff,0xe1,0xc9,0x6,0xc1,0xef,0xff,0xf7,0x5,0xff,0xff,0xff,0xe1,0x1,0xef,
  0xff,0xff,0xfa,0xa,0xff,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0xf5,0x2f,0xff,0xff,
  0xff,0xff,0xf8,0x4f,0xff,0xd0,0x9f,0xff,0xb0,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xc,0xff,0xf4,0x2f,0xff,0x80,0xef,0xe1,0x5f,
  0xff,0x83,0xff,0xe1,0x7f,0xff,0x94,0xff,0xe1,0x6f,0xff,0xa1,0xef,0xff,0xf1,0xcf,
  0xff,0xff,0xf2,0x4f,0xff,0xc1,0xef,0xf4,0x3f,0xff,0x72,0xef,0xff,0xff,0x48,0xff,
  0xff,0xff,0xff,0xf1,0xcf,0xff,0xf8,0x4f,0x70,0xcf,0xff,0xff,0xe1,0xcf,0xff,0xff,
  0x91,0xed,0xb,0xf3,0x8f,0xf4,0x1d,0xff,0x82,0xff,0xe1,0x8f,0xff,0x71,0xef,0xf5,
  0x1d,0xff,0xb0,0xcf,0xe1,0x5f,0xff,0x94,0xff,0xff,0xf1,0xaf,0xf2,0x9f,0xf8,0x1e,
  0xff,0xff,0xff,0xff,0x48,0xff,0xff,0xff,0xf4,0x8f,0xff,0x54,0xff,0xf7,0x1e,0xff,
  0x26,0xff,0x92,0xfc,0xa,0xf4,0x7f,0xff,0x70,0x91,0x6f,0xff,0xf8,0xe,0xff,0x63,
  0xff,0xff,0xff,0xf3,0x2e,0xff,0xff,0xd0,0x8f,0xff,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xff,0xff,0x90,0xdf,0xff,0xf2,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfe,0xd,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xb6,0x11,
  0x72,0x9,0xff,0xff,0xfe,0x10,0xc,0xff,0xff,0xf5,0x32,0x0,0xcf,0x91,0xed,0x7,
  0xf3,0x9f,0xff,0xff,0xff,0xff,0xff,0xfb,0x1e,0xff,0xff,0xff,0xff,0xff,0xfe,0x1a,
  0xff,0xff,0x27,0xf8,0x2f,0xff,0xea,0xa9,0x19,0xaa,0xef,0xff,0xff,0xff,0xff,0xff,
  0xfe,0x0,0x0,0xe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xc,0xff,0xff,0xc0,
  0x0,0x9f,0xc0,0xcf,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0x51,0xdf,0xff,0xff,0xff,
  0xea,0x7,0xff,0xa0,0x19,0x95,0x18,0xaf,0xff,0xff,0xfd,0x18,0xff,0xe1,0x7f,0xff,
  0x61,0xef,0xff,0xfc,0xb,0xff,0xff,0xfa,0x9,0xd6,0x9,0xff,0xff,0xc7,0x58,0x31,
  0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xb0,0x8,0xff,0xff,0xff,
  0xf7,0x67,0x77,0x76,0xef,0xff,0xff,0xf9,0x0,0xbf,0xff,0xfb,0x9,0xff,0xff,0x82,
  0xfb,0x76,0x51,0xef,0xfa,0xa,0xda,0x9,0xff,0xf9,0x3e,0xea,0x12,0xef,0xe1,0x9f,
  0xff,0xff,0xff,0xf4,0x8f,0xff,0xc0,0xcf,0xf9,0x1d,0xee,0xef,0xff,0xfc,0xb,0xcc,
  0xce,0xff,0xc0,0xcf,0xc3,0x21,0xef,0xc0,0xae,0xee,0xb0,0xcf,0xff,0xfc,0xc,0xff,
  0xff,0xff,0xff,0xfe,0x18,0xff,0xf4,0x7c,0x3,0xff,0xff,0xf4,0x4f,0xff,0xff,0xff,
  0xc0,0xcf,0xbf,0xc0,0xcf,0xe1,0xcf,0x31,0xa1,0xef,0xc0,0xcf,0xff,0xc0,0xcf,0xf9,
  0x0,0x0,0x9f,0xff,0xc0,0xcf,0xff,0xc0,0xcf,0xf9,0x2c,0x80,0xbf,0xff,0xff,0xff,
  0xc3,0x5,0xff,0xff,0xfc,0xc,0xff,0xff,0xc0,0xcf,0xff,0xc0,0xcf,0xff,0x44,0xf7,
  0x2f,0xff,0xf2,0x85,0x3,0xa2,0xef,0xff,0xe1,0x0,0xdf,0xff,0xff,0xf9,0x9,0xff,
  0xff,0xff,0xd0,0x5f,0xff,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0xfc,0xc,0xff,0xff,
  0xff,0xff,0xf8,0x4f,0xff,0xda,0xff,0xff,0xfa,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xb7,0x67,0xc,0xff,0xf4,0x8f,0xff,0xc0,0xcf,0xd0,0xcf,
  0xff,0xff,0xff,0xc0,0xcf,0xff,0x84,0xff,0xe1,0x0,0x0,0x1,0xef,0xff,0xe1,0xcf,
  0xff,0xff,0xe1,0xaf,0xff,0xc1,0xef,0xf4,0x8f,0xff,0xa1,0xef,0xff,0xff,0x48,0xff,
  0xff,0xff,0xff,0xe1,0xcf,0xff,0xf9,0x15,0xb,0xff,0xff,0xff,0xe1,0xcf,0xff,0xff,
  0x84,0xfc,0xc,0xf4,0x8f,0xf4,0x6f,0xff,0xa1,0xef,0xc0,0xcf,0xff,0xc0,0xcf,0xf9,
  0x4f,0xff,0xe1,0xcf,0xd0,0xcf,0xff,0x84,0xff,0xff,0xe1,0xcf,0xfd,0xef,0xfd,0x0,
  0x28,0xdf,0xff,0xff,0x48,0xff,0xff,0xff,0xf4,0x8f,0xff,0x44,0xff,0xfd,0x9,0xfb,
  0xd,0xff,0xc0,0xe8,0x4,0xf2,0xbf,0xff,0xf4,0x3,0xff,0xff,0xfd,0x9,0xfe,0x19,
  0xff,0xff,0xfe,0x21,0xef,0xff,0xfb,0x13,0xef,0xff,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xff,0xff,0xf4,0x1b,0xff,0xfc,0xef,0xd9,0x9d,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfe,0xe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xb2,0x8,
  0x60,0x6a,0xff,0xff,0xfe,0x6e,0x18,0xff,0xff,0xc0,0x91,0xe5,0x7f,0x84,0xff,0xa0,
  0x40,0xdf,0xff,0xff,0xff,0xff,0xff,0xf9,0x1e,0xff,0xff,0xff,0xff,0xff,0xfe,0x19,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x2e,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xdd,0xed,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf5,0x4f,0xff,0xff,0xd0,
  0xa,0xff,0xc0,0xdf,0xff,0xff,0x48,0xff,0xff,0xff,0xf6,0xc,0xff,0xff,0xff,0xff,
  0xff,0x73,0xff,0xc6,0x65,0x60,0x5,0x8f,0xff,0xff,0xff,0x54,0xff,0xd0,0xcf,0xff,
  0xc0,0xdf,0xff,0xf5,0x2f,0xff,0xff,0xf2,0x6f,0xff,0x52,0xff,0xff,0xff,0xff,0x27,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x90,0xa,0xff,0xff,
  0xe7,0x77,0x77,0x77,0xff,0xff,0xfa,0x0,0x9f,0xff,0xff,0xf6,0x4f,0xff,0xff,0x49,
  0xa0,0x69,0x61,0xef,0xf4,0x0,0x0,0x4,0xff,0xf8,0x4f,0xff,0xc0,0xbf,0xe1,0x5f,
  0xff,0xff,0xff,0xf4,0x8f,0xff,0xb0,0xcf,0xf9,0x1e,0xff,0xff,0xff,0xfc,0x1e,0xff,
  0xff,0xff,0xd0,0x9f,0xff,0xc1,0xef,0xc0,0xcf,0xff,0xc0,0xcf,0xff,0xfc,0xc,0xff,
  0xff,0xff,0xff,0xfe,0x18,0xff,0xf4,0x8f,0xa0,0x6f,0xff,0xf4,0x4f,0xff,0xc1,0xef,
  0xc0,0xcf,0xff,0xc0,0xcf,0xe1,0xcf,0xd0,0x1,0xef,0xc0,0xbf,0xff,0xc0,0xcf,0xf9,
  0x3f,0xff,0xff,0xff,0xc0,0xbf,0xff,0xc0,0xcf,0xf8,0x4f,0xf2,0x2f,0xff,0xfa,0xef,
  0xff,0x81,0xef,0xff,0xfc,0xc,0xff,0xff,0xc0,0xcf,0xff,0xc0,0xcf,0xff,0xa1,0xd2,
  0x8f,0xff,0xf4,0x0,0x91,0x14,0xff,0xff,0x41,0xc1,0x4f,0xff,0xff,0xfc,0xc,0xff,
  0xff,0xff,0x31,0xef,0xff,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0xff,0x44,0xff,0xff,
  0xff,0xff,0xf8,0x4f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xf6,0x6,0x97,0xc,0xff,0xf4,0x8f,0xff,0xc0,0xcf,0xd0,0xcf,
  0xff,0xff,0xff,0xc0,0xcf,0xff,0x94,0xff,0xe1,0x7b,0xbb,0xbc,0xff,0xff,0xe1,0xcf,
  0xff,0xff,0xe1,0xaf,0xff,0xc1,0xef,0xf4,0x8f,0xff,0xc1,0xef,0xff,0xff,0x48,0xff,
  0xff,0xff,0xff,0xe1,0xcf,0xff,0xf9,0x15,0x9,0xff,0xff,0xff,0xe1,0xcf,0xff,0xff,
  0x84,0xfc,0xc,0xf4,0x8f,0xf4,0x8f,0xff,0xc1,0xef,0xc0,0xbf,0xff,0xc0,0xcf,0xf8,
  0x4f,0xff,0xe1,0xcf,0xc0,0xcf,0xff,0x94,0xff,0xff,0xe1,0xcf,0xff,0xff,0xff,0xfb,
  0x70,0x8,0xff,0xff,0x48,0xff,0xff,0xff,0xf4,0x6f,0xff,0x44,0xff,0xff,0x52,0xf5,
  0x4f,0xff,0xe0,0xa2,0x31,0xb1,0xdf,0xff,0xf4,0x3,0xff,0xff,0xff,0x52,0xfc,0xd,
  0xff,0xff,0xf4,0x1e,0xff,0xff,0xf3,0xa,0xff,0xff,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xff,0xff,0xfa,0x2,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa,0x2f,
  0xd1,0xef,0xff,0xff,0xfe,0x6f,0x28,0xff,0xff,0x46,0xc2,0xf8,0x8f,0x82,0xef,0xf7,
  0x2,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x1e,0xff,0xff,0xff,0xff,0xff,0xfe,0x1c,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x1e,0xff,0xff,0xff,0xff,0xef,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xd0,0xbf,0xff,0xff,0xf2,
  0x4f,0xff,0x62,0xff,0xff,0xff,0x48,0xff,0xff,0xff,0x61,0xdf,0xff,0xff,0xff,0xff,
  0xff,0x35,0xff,0xff,0xff,0xf9,0x4f,0xff,0xff,0xff,0xff,0x27,0xff,0xe1,0x9f,0xff,
  0xa1,0xef,0xff,0xd0,0xbf,0xff,0xff,0xf2,0x7f,0xff,0x71,0xef,0xff,0xff,0xf4,0x1e,
  0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xfe,0x60,0x1c,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfc,0x10,0x6e,0xff,0xff,0xff,0xfe,0xef,0xff,0xff,0x58,
  0x52,0xff,0xa1,0xef,0xd0,0xaf,0xff,0x90,0xdf,0xf8,0x4f,0xff,0xa0,0xdf,0xf6,0xc,
  0xff,0xf1,0xcf,0xf4,0x8f,0xfe,0x22,0xff,0xf9,0x1e,0xff,0xff,0xff,0xfc,0x1e,0xff,
  0xff,0xff,0xf2,0x2e,0xff,0xc1,0xef,0xc0,0xcf,0xff,0xc0,0xcf,0xff,0xfd,0xc,0xff,
  0xff,0xff,0xff,0xfc,0xb,0xff,0xf4,0x8f,0xf7,0xa,0xff,0xf4,0x4f,0xff,0xc1,0xef,
  0xc0,0xcf,0xff,0xc0,0xcf,0xe1,0xcf,0xf8,0x1,0xef,0xe1,0x5f,0xff,0x61,0xef,0xf8,
  0x4f,0xff,0xff,0xff,0xe1,0x5f,0xff,0x61,0xef,0xf8,0x4f,0xfb,0x9,0xff,0xe0,0xcf,
  0xff,0xb1,0xef,0xff,0xfd,0xc,0xff,0xff,0xe1,0x8f,0xff,0xa1,0xef,0xff,0xe0,0x50,
  0xdf,0xff,0xf8,0x2,0xe3,0x7,0xff,0xfa,0xa,0xfa,0xa,0xff,0xff,0xfc,0xc,0xff,
  0xff,0xf8,0xc,0xff,0xff,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0xff,0xb0,0xdf,0xff,
  0xff,0xff,0xf8,0x4f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xe1,0x8f,0xfd,0xc,0xff,0xf4,0x8f,0xff,0x81,0xef,0xe1,0x5f,
  0xff,0xff,0xff,0xd0,0x9f,0xff,0x44,0xff,0xe1,0x8f,0xff,0xff,0xff,0xff,0xe1,0xcf,
  0xff,0xff,0xe1,0x5f,0xff,0x71,0xef,0xf4,0x8f,0xff,0xc1,0xef,0xff,0xff,0x48,0xff,
  0xff,0xff,0xff,0xe1,0xcf,0xff,0xf8,0x4f,0x70,0x9f,0xff,0xff,0xe1,0xaf,0xff,0xff,
  0x84,0xfc,0xc,0xf4,0x8f,0xf4,0x8f,0xff,0xc1,0xef,0xe1,0x8f,0xff,0xa0,0xef,0xf8,
  0x4f,0xff,0xa0,0xcf,0xe1,0x9f,0xff,0x54,0xff,0xff,0xe1,0xcf,0xff,0xff,0xff,0xff,
  0xff,0x53,0xff,0xff,0x46,0xff,0xff,0xff,0xf5,0x4f,0xff,0x24,0xff,0xff,0xc0,0x80,
  0xbf,0xff,0xf3,0x1,0xd2,0x2,0xef,0xff,0x51,0xa1,0x5f,0xff,0xff,0xc0,0xb8,0x2f,
  0xff,0xff,0x41,0xef,0xff,0xff,0xfe,0x60,0xcf,0xff,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xff,0xff,0xd0,0x6e,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfc,0xb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf5,0x6f,
  0x82,0xff,0xff,0xfc,0x8b,0x6,0xa,0xff,0xfc,0xd,0xd0,0x81,0x8f,0xc0,0x3c,0xc3,
  0x0,0xaf,0xff,0xff,0xff,0xff,0xff,0xfc,0xc,0xff,0xff,0xff,0xff,0xff,0xfc,0xc,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x6e,0xff,0xff,0xff,0xf9,0x6,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0x8,0xff,0xff,0xff,0x82,0xff,0xff,0xff,0xf9,
  0x8,0xe9,0x9,0xff,0xfe,0xaa,0x33,0xac,0xff,0xf4,0x5,0xba,0xac,0xff,0xfb,0xbc,
  0xb3,0xc,0xff,0xff,0xff,0xf8,0x3f,0xff,0xf9,0x9c,0xb4,0xc,0xff,0xf6,0x9,0xd9,
  0x5,0xff,0xff,0x52,0xff,0xff,0xff,0xf5,0xa,0xda,0x5,0xff,0xff,0xea,0x10,0xcf,
  0xff,0xff,0xf9,0x8,0xff,0xff,0xff,0xf9,0x6,0xff,0xff,0xff,0xff,0xfd,0x30,0xaf,
  0xff,0xff,0xff,0xff,0xff,0xa0,0x3d,0xff,0xff,0xff,0xff,0xf6,0x4f,0xff,0xff,0x48,
  0x71,0xba,0x1,0xbf,0x91,0xef,0xff,0xd0,0x9f,0xf9,0x2b,0xc7,0x3,0xff,0xfd,0x0,
  0x8c,0xa0,0xbf,0xf4,0x5c,0xa1,0xb,0xff,0xf9,0x8,0xaa,0xab,0xff,0xfc,0x1e,0xff,
  0xff,0xff,0xfb,0x1,0xbc,0x71,0xef,0xc0,0xcf,0xff,0xc0,0xcf,0xea,0xa8,0x4,0xaa,
  0xef,0xf7,0x4b,0xa1,0x1e,0xff,0xf4,0x8f,0xff,0x30,0xdf,0xf4,0x2a,0xaa,0x81,0xef,
  0xc0,0xcf,0xff,0xc0,0xcf,0xe1,0xcf,0xff,0x21,0xef,0xf7,0x7,0xd7,0x7,0xff,0xf8,
  0x4f,0xff,0xff,0xff,0xf7,0x7,0xd7,0x7,0xff,0xf8,0x4f,0xff,0x41,0xef,0xe1,0x3a,
  0xc9,0x3,0xff,0xff,0xb8,0x4,0xcf,0xff,0xf4,0x8,0xc9,0x4,0xff,0xff,0xf4,0x3,
  0xff,0xff,0xf9,0x7,0xf8,0x9,0xff,0xe1,0x4f,0xff,0x41,0xdf,0xff,0xfc,0xc,0xff,
  0xff,0xd0,0xa,0xaa,0xaa,0xef,0xff,0x48,0xff,0xff,0xff,0xff,0xff,0xf2,0x6f,0xff,
  0xff,0xff,0xf8,0x4f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xf2,0x3c,0xa0,0x9,0xef,0xf4,0x3c,0xc8,0x7,0xff,0xf7,0x4,
  0xbb,0x70,0xdf,0xf2,0xa,0xd8,0x3,0xcf,0xf7,0x7,0xdc,0x51,0xff,0xfc,0xb0,0x8c,
  0xbd,0xff,0xf6,0x9,0xda,0x1,0xef,0xf4,0x8f,0xff,0xc1,0xef,0xfd,0xbb,0x26,0xcc,
  0xff,0xff,0xff,0xe1,0xcf,0xff,0xf8,0x4f,0xf6,0x9,0xdf,0xff,0xf2,0x4d,0x88,0xff,
  0x84,0xfc,0xc,0xf4,0x8f,0xf4,0x8f,0xff,0xc1,0xef,0xf5,0x9,0xea,0x5,0xff,0xf9,
  0x1b,0xea,0x4,0xff,0xf4,0xa,0xd8,0x4,0xff,0xfc,0xb0,0x8c,0xcf,0xff,0xf5,0x1b,
  0xdc,0x15,0xff,0xff,0x60,0xae,0xa2,0xff,0xf9,0xb,0xd4,0x3,0xcf,0xff,0xf3,0x2,
  0xff,0xff,0xf6,0x5,0xf8,0x4,0xff,0xf9,0xb,0xfb,0x8,0xff,0xff,0xf2,0x31,0x8f,
  0xff,0xf6,0x7,0xcc,0xcc,0xff,0xff,0xf2,0x7f,0xff,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xff,0xff,0x82,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfb,0xa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xfa,0x0,0x0,0x9f,0xff,0xf5,0x5f,0xf8,0x4,0xef,0xfb,0x0,0x4,
  0xe8,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0x24,0xff,0xff,0xff,0xff,0xff,0xf4,0x2f,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0x4,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0x9,0xff,0xff,0xfe,0x19,0xff,0xff,0xff,0xff,
  0x80,0x0,0x8f,0xff,0xfc,0x0,0x0,0x3,0xff,0xe1,0x0,0x0,0x1,0xef,0xf5,0x0,
  0x2,0xcf,0xff,0xff,0xff,0xf9,0x4f,0xff,0xf8,0x0,0x1,0xcf,0xff,0xff,0x70,0x0,
  0x6f,0xff,0xfe,0xa,0xff,0xff,0xff,0xfe,0x50,0x0,0x6f,0xff,0xff,0x30,0x7d,0xff,
  0xff,0xff,0xf9,0x9,0xff,0xff,0xff,0xf9,0x4,0xff,0xff,0xff,0xff,0xff,0xfc,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xf4,0x1e,0xff,0xff,0x82,
  0xd3,0x1,0x60,0x1e,0x45,0xff,0xff,0xf4,0x4f,0xf9,0x0,0x0,0x7f,0xff,0xff,0xd3,
  0x0,0x5,0xef,0xf4,0x0,0x4,0xcf,0xff,0xf9,0x0,0x0,0x1,0xef,0xfc,0x1e,0xff,
  0xff,0xff,0xff,0xb1,0x0,0x7,0xff,0xc0,0xcf,0xff,0xc0,0xdf,0xc0,0x0,0x0,0x0,
  0xdf,0xfa,0x0,0x3,0xdf,0xff,0xf4,0x8f,0xff,0xe1,0x2f,0xf5,0x0,0x0,0x1,0xef,
  0xc0,0xdf,0xff,0xc0,0xdf,0xe1,0xcf,0xff,0xc1,0xef,0xff,0x70,0x0,0x8f,0xff,0xf9,
  0x4f,0xff,0xff,0xff,0xff,0x70,0x0,0x7f,0xff,0xf9,0x4f,0xff,0xc0,0x9f,0xfa,0x20,
  0x0,0x5e,0xff,0xff,0x40,0x0,0x3f,0xff,0xfe,0x60,0x0,0x5e,0xff,0xff,0xfa,0x9,
  0xff,0xff,0xfc,0xb,0xfc,0xc,0xff,0x61,0xef,0xff,0xd1,0x5f,0xff,0xfc,0xc,0xff,
  0xff,0xc0,0x0,0x0,0x0,0xcf,0xff,0x48,0xff,0xff,0xff,0xff,0xff,0xfa,0xe,0xff,
  0xff,0xff,0xf8,0x4f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xfb,0x0,0x9,0x10,0xcf,0xf9,0x0,0x0,0x9f,0xff,0xff,0x80,
  0x0,0x1a,0xff,0xfd,0x30,0x2,0x90,0x2e,0xff,0x80,0x0,0x2b,0xff,0xf4,0x0,0x0,
  0x9,0xff,0xfe,0x50,0x0,0x41,0xef,0xf4,0x9f,0xff,0xc1,0xef,0xf9,0x0,0x0,0x1,
  0xef,0xff,0xff,0xe1,0xcf,0xff,0xf9,0x4f,0xff,0x70,0x7f,0xff,0xfa,0x0,0xa,0xff,
  0x94,0xfd,0xd,0xf4,0x9f,0xf5,0x8f,0xff,0xc1,0xef,0xff,0x70,0x0,0x6f,0xff,0xf9,
  0x0,0x0,0x6f,0xff,0xfe,0x30,0x1,0x24,0xff,0xe1,0x0,0x0,0x1e,0xff,0xfc,0x30,
  0x0,0x4e,0xff,0xff,0xf4,0x0,0x8,0xff,0xfe,0x20,0x4,0x60,0x4f,0xff,0xfa,0x9,
  0xff,0xff,0xfa,0xb,0xfd,0x8,0xff,0xd0,0x9f,0xff,0x80,0xcf,0xff,0xfa,0x0,0xcf,
  0xff,0xf4,0x0,0x0,0x3,0xff,0xff,0xf4,0x8f,0xff,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xff,0xff,0x84,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xfd,0xe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xa0,0x8f,0xff,0xff,0xff,0xff,0x80,0xaf,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x35,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xfa,0x1e,0xff,0xff,0xff,0xff,
  0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xef,0xff,0xff,0xff,0xff,0xef,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0x35,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,
  0x8f,0xff,0xfe,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xee,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xee,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfc,0x6,0xeb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0xff,0xfe,0x18,0xff,
  0xff,0xff,0xf8,0x4f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xef,0xff,0xff,0xff,0xfe,0xef,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xef,0x91,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xd0,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xf8,
  0x3f,0xef,0xff,0xff,0xff,0xfe,0xef,0x94,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xef,0xff,0xff,0xff,0xff,0xfe,0xff,0xff,0xff,0xfe,0xef,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x82,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf4,0x7f,0xff,0xff,0xff,0xfe,0x2e,0xff,0xff,
  0xff,0xff,0x83,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0x3,0xbf,0xff,0xff,0xb3,0x7,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf5,0x2e,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf5,0x6f,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf5,0x2e,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,
  0x5,0xce,0xa1,0x4f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0x90,0x0,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x48,0xff,0xff,0xff,0xff,0xff,0xff,0x85,0xff,
  0xff,0xff,0xf7,0x4f,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xcc,0xcc,0xcc,0xef,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xfe,0x4b,0xda,0x5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xe1,0x9c,0x40,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,
  0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0x84,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0x58,0x8,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf4,0x2e,0xff,0xff,0xff,0xfe,0x3e,0xff,0xff,
  0xff,0xfe,0x24,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xb2,0x2f,0xff,0xff,0x21,0xbf,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xb1,0x0,0x6,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x30,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,
  0xfa,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0xbf,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xfd,0x10,0x0,0x6e,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xe7,0x0,0xa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,
  0x5f,0xff,0xff,0xff,0xff,0xff,0xff,0x94,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0x0,0x6f,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,
  0xf3,0x0,0xa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xee,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xcb,0xbb,0xbd,0xff,0xff,0xff,0xff,0xff,0xff,
  0xfd,0xbb,0xbb,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xeb,0xbc,0xff,0xff,0xff,0xff,0xff,0xff,
  0xfc,0xbb,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  
};

    static const MonoFont PT_Mono_15 = {
        pt_mono_15_4bit_bitmap,
        "PT Mono",
        15,
        960,
        15,
        10,
        4,
        32,
        0
    };

} }
