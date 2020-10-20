Lights1 pillar_switch_Pillar_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 pillar_switch_Bricks_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx pillar_switch_pillar7_ci8_aligner[] = {gsSPEndDisplayList()};
u8 pillar_switch_pillar7_ci8[] = {
	0x0, 0x1, 0x2, 0x3, 0x4, 0x3, 0x5, 0x6, 0x7, 
	0x1, 0x8, 0x3, 0x9, 0xA, 0xB, 0x3, 0xC, 0x3, 
	0xC, 0xD, 0xE, 0x3, 0xF, 0x2, 0xF, 0x10, 0x7, 
	0x11, 0x9, 0xA, 0x12, 0xC, 0x9, 0x8, 0x13, 0x1, 
	0x14, 0xB, 0x15, 0x16, 0x16, 0x17, 0x18, 0x19, 0x1A, 
	0x1B, 0x1C, 0x6, 0x9, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 
	0x22, 0x3, 0x23, 0x21, 0x15, 0x13, 0x14, 0xB, 0x24, 
	0x2, 0x15, 0x7, 0x13, 0x17, 0xF, 0x10, 0x14, 0x25, 
	0x1A, 0x2, 0x6, 0x26, 0x27, 0xA, 0x28, 0x1A, 0xF, 
	0x21, 0x29, 0x13, 0x2A, 0xD, 0x10, 0x17, 0x0, 0x1D, 
	0xF, 0x10, 0x13, 0x2B, 0x13, 0x17, 0x5, 0x9, 0x6, 
	0xB, 0x5, 0xC, 0x2C, 0x0, 0x2D, 0x6, 0x1A, 0x2E, 
	0x2F, 0xD, 0x30, 0x31, 0x0, 0x32, 0x2F, 0x22, 0x33, 
	0x9, 0x9, 0x1B, 0x1A, 0x34, 0x7, 0x1D, 0x23, 0xB, 
	0x14, 0x25, 0x15, 0x13, 0xF, 0x10, 0x24, 0xD, 0x20, 
	0x35, 0xC, 0x1B, 0x2D, 0x23, 0xF, 0x36, 0x37, 0x22, 
	0x38, 0x39, 0xF, 0x13, 0x33, 0x3A, 0x6, 0x3B, 0x1E, 
	0x6, 0x37, 0x10, 0xC, 0x2, 0xF, 0x13, 0xC, 0x3C, 
	0x7, 0x1D, 0x9, 0x1B, 0x14, 0x3B, 0x14, 0x3B, 0x24, 
	0x2, 0x27, 0x21, 0x1F, 0x1D, 0xB, 0x2B, 0x3D, 0x2B, 
	0x23, 0x3E, 0x2E, 0x17, 0x29, 0xE, 0x28, 0x13, 0x9, 
	0x1B, 0x3F, 0x2A, 0x40, 0x13, 0x29, 0x13, 0x41, 0x42, 
	0x30, 0x9, 0x2F, 0x26, 0x37, 0xD, 0x6, 0x39, 0x14, 
	0x21, 0x0, 0x17, 0x6, 0x43, 0x9, 0x44, 0x6, 0x19, 
	0xC, 0x44, 0x2F, 0x3D, 0x13, 0x17, 0x23, 0x1D, 0x24, 
	0x22, 0xF, 0x3D, 0x45, 0x42, 0x1A, 0x2, 0x14, 0x8, 
	0x14, 0x46, 0x47, 0x26, 0x48, 0x4, 0x13, 0x17, 0x2E, 
	0x21, 0x2F, 0x49, 0x3A, 0x46, 0x29, 0x10, 0x6, 0xE, 
	0x9, 0x4A, 0x27, 0x10, 0x15, 0x16, 0x6, 0x4B, 0x3A, 
	0x46, 0x6, 0x8, 0x2F, 0xD, 0x4C, 0x4D, 0x27, 0xE, 
	0x27, 0x36, 0x42, 0x3, 0x1A, 0x22, 0x6, 0x21, 0x4E, 
	0x3, 0x2F, 0xA, 0xE, 0x39, 0xE, 0x39, 0x7, 0x17, 
	0x9, 0x3B, 0x24, 0x2, 0x42, 0x32, 0x22, 0xB, 0x27, 
	0xD, 0x27, 0x26, 0x4F, 0x2F, 0x41, 0x13, 0x24, 0x2, 
	0x2C, 0x0, 0x29, 0x0, 0x6, 0x43, 0x23, 0x1D, 0x9, 
	0x8, 0x22, 0x32, 0x50, 0x24, 0x5, 0x2F, 0x33, 0x13, 
	0xC, 0x1B, 0x37, 0x3D, 0x27, 0x26, 0x40, 0x1F, 0x50, 
	0x22, 0x51, 0x1A, 0x23, 0x4, 0x29, 0x0, 0x51, 0x1A, 
	0x52, 0xE, 0x4F, 0x13, 0x37, 0x3A, 0x29, 0x22, 0xC, 
	0x8, 0x37, 0x13, 0x52, 0x2, 0x27, 0x46, 0x23, 0xD, 
	0x2F, 0x48, 0x24, 0x10, 0x2F, 0x36, 0x40, 0x9, 0x29, 
	0x10, 0x1F, 0x4A, 0x5, 0x2A, 0x33, 0x22, 0x37, 0xD, 
	0x41, 0x3A, 0x28, 0x3A, 0x33, 0x4C, 0x29, 0xE, 0x53, 
	0x23, 0x1A, 0x26, 0x41, 0x9, 0x2D, 0x1C, 0x9, 0x1B, 
	0x54, 0x27, 0x55, 0xC, 0x23, 0x46, 0x10, 0x2B, 0x51, 
	0xF, 0x54, 0x27, 0x50, 0xD, 0x40, 0x4C, 0x28, 0x3A, 
	0x23, 0x21, 0xF, 0x3B, 0x30, 0x2F, 0x15, 0xC, 0x4F, 
	0x43, 0x40, 0x48, 0x9, 0x26, 0x48, 0x21, 0x40, 0x48, 
	0x13, 0x17, 0xD, 0x32, 0x54, 0x15, 0x56, 0x4F, 0x14, 
	0x26, 0x1C, 0x3D, 0x24, 0x22, 0xF, 0x42, 0xF, 0x36, 
	0x53, 0x2F, 0x57, 0x26, 0x54, 0x1B, 0x37, 0x0, 0xC, 
	0x2, 0x9, 0x1B, 0x54, 0x0, 0x13, 0xA, 0x9, 0x3E, 
	0x29, 0x58, 0x59, 0x33, 0x13, 0x4B, 0x1A, 0x36, 0x52, 
	0x22, 0x24, 0x5A, 0x37, 0x8, 0x2D, 0x14, 0x0, 0x1D, 
	0x28, 0x43, 0x29, 0xE, 0x42, 0x19, 0x13, 0x17, 0x51, 
	0xC, 0xB, 0x3, 0xD, 0x19, 0x6, 0xB, 0x53, 0x23, 
	0x13, 0x11, 0x13, 0x19, 0xC, 0x36, 0x2E, 0x3B, 0x4, 
	0x3, 0xC, 0xD, 0xE, 0x3, 0xF, 0x2, 0xF, 0x10, 
	0x7, 0x11, 0x9, 0xA, 0x12, 0xC, 0x0, 0x1, 0x2, 
	0x3, 0x4, 0x3, 0x5, 0x6, 0x7, 0x1, 0x8, 0x3, 
	0x9, 0xA, 0xB, 0x3, 0x9, 0x1D, 0x1E, 0x1F, 0x20, 
	0x21, 0x22, 0x3, 0x23, 0x21, 0x15, 0x13, 0x14, 0xB, 
	0x24, 0x2, 0x9, 0x8, 0x13, 0x1, 0x14, 0xB, 0x15, 
	0x16, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x6, 
	0xF, 0x21, 0x29, 0x13, 0x2A, 0xD, 0x10, 0x17, 0x0, 
	0x1D, 0xF, 0x10, 0x13, 0x2B, 0x13, 0x17, 0x15, 0x7, 
	0x13, 0x17, 0xF, 0x10, 0x14, 0x25, 0x1A, 0x2, 0x6, 
	0x26, 0x27, 0xA, 0x28, 0x1A, 0x0, 0x32, 0x2F, 0x22, 
	0x33, 0x9, 0x9, 0x1B, 0x1A, 0x34, 0x7, 0x1D, 0x23, 
	0xB, 0x14, 0x25, 0x5, 0x9, 0x6, 0xB, 0x5, 0xC, 
	0x2C, 0x0, 0x2D, 0x6, 0x1A, 0x2E, 0x2F, 0xD, 0x30, 
	0x31, 0x38, 0x39, 0xF, 0x13, 0x33, 0x3A, 0x6, 0x3B, 
	0x1E, 0x6, 0x37, 0x10, 0xC, 0x2, 0xF, 0x13, 0x15, 
	0x13, 0xF, 0x10, 0x24, 0xD, 0x20, 0x35, 0xC, 0x1B, 
	0x2D, 0x23, 0xF, 0x36, 0x37, 0x22, 0xB, 0x2B, 0x3D, 
	0x2B, 0x23, 0x3E, 0x2E, 0x17, 0x29, 0xE, 0x28, 0x13, 
	0x9, 0x1B, 0x3F, 0x2A, 0xC, 0x3C, 0x7, 0x1D, 0x9, 
	0x1B, 0x14, 0x3B, 0x14, 0x3B, 0x24, 0x2, 0x27, 0x21, 
	0x1F, 0x1D, 0x0, 0x17, 0x6, 0x43, 0x9, 0x44, 0x6, 
	0x19, 0xC, 0x44, 0x2F, 0x3D, 0x13, 0x17, 0x23, 0x1D, 
	0x40, 0x13, 0x29, 0x13, 0x41, 0x42, 0x30, 0x9, 0x2F, 
	0x26, 0x37, 0xD, 0x6, 0x39, 0x14, 0x21, 0x13, 0x17, 
	0x2E, 0x21, 0x2F, 0x49, 0x3A, 0x46, 0x29, 0x10, 0x6, 
	0xE, 0x9, 0x4A, 0x27, 0x10, 0x24, 0x22, 0xF, 0x3D, 
	0x45, 0x42, 0x1A, 0x2, 0x14, 0x8, 0x14, 0x46, 0x47, 
	0x26, 0x48, 0x4, 0x42, 0x3, 0x1A, 0x22, 0x6, 0x21, 
	0x4E, 0x3, 0x2F, 0xA, 0xE, 0x39, 0xE, 0x39, 0x7, 
	0x17, 0x15, 0x16, 0x6, 0x4B, 0x3A, 0x46, 0x6, 0x8, 
	0x2F, 0xD, 0x4C, 0x4D, 0x27, 0xE, 0x27, 0x36, 0x24, 
	0x2, 0x2C, 0x0, 0x29, 0x0, 0x6, 0x43, 0x23, 0x1D, 
	0x9, 0x8, 0x22, 0x32, 0x50, 0x24, 0x9, 0x3B, 0x24, 
	0x2, 0x42, 0x32, 0x22, 0xB, 0x27, 0xD, 0x27, 0x26, 
	0x4F, 0x2F, 0x41, 0x13, 0x23, 0x4, 0x29, 0x0, 0x51, 
	0x1A, 0x52, 0xE, 0x4F, 0x13, 0x37, 0x3A, 0x29, 0x22, 
	0xC, 0x8, 0x5, 0x2F, 0x33, 0x13, 0xC, 0x1B, 0x37, 
	0x3D, 0x27, 0x26, 0x40, 0x1F, 0x50, 0x22, 0x51, 0x1A, 
	0x29, 0x10, 0x1F, 0x4A, 0x5, 0x2A, 0x33, 0x22, 0x37, 
	0xD, 0x41, 0x3A, 0x28, 0x3A, 0x33, 0x4C, 0x37, 0x13, 
	0x52, 0x2, 0x27, 0x46, 0x23, 0xD, 0x2F, 0x48, 0x24, 
	0x10, 0x2F, 0x36, 0x40, 0x9, 0x23, 0x46, 0x10, 0x2B, 
	0x51, 0xF, 0x54, 0x27, 0x50, 0xD, 0x40, 0x4C, 0x28, 
	0x3A, 0x23, 0x21, 0x29, 0xE, 0x53, 0x23, 0x1A, 0x26, 
	0x41, 0x9, 0x2D, 0x1C, 0x9, 0x1B, 0x54, 0x27, 0x55, 
	0xC, 0x13, 0x17, 0xD, 0x32, 0x54, 0x15, 0x56, 0x4F, 
	0x14, 0x26, 0x1C, 0x3D, 0x24, 0x22, 0xF, 0x42, 0xF, 
	0x3B, 0x30, 0x2F, 0x15, 0xC, 0x4F, 0x43, 0x40, 0x48, 
	0x9, 0x26, 0x48, 0x21, 0x40, 0x48, 0x13, 0xA, 0x9, 
	0x3E, 0x29, 0x58, 0x59, 0x33, 0x13, 0x4B, 0x1A, 0x36, 
	0x52, 0x22, 0x24, 0x5A, 0xF, 0x36, 0x53, 0x2F, 0x57, 
	0x26, 0x54, 0x1B, 0x37, 0x0, 0xC, 0x2, 0x9, 0x1B, 
	0x54, 0x0, 0xB, 0x3, 0xD, 0x19, 0x6, 0xB, 0x53, 
	0x23, 0x13, 0x11, 0x13, 0x19, 0xC, 0x36, 0x2E, 0x3B, 
	0x37, 0x8, 0x2D, 0x14, 0x0, 0x1D, 0x28, 0x43, 0x29, 
	0xE, 0x42, 0x19, 0x13, 0x17, 0x51, 0xC, 
};

Gfx pillar_switch_pillar7_ci8_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 pillar_switch_pillar7_ci8_pal_rgba16[] = {
	0xC6, 0x2F, 0xEF, 0xBD, 0xCE, 0xB3, 0xF7, 0xFD, 0xD7, 
	0x39, 0x8C, 0x61, 0xB5, 0xEF, 0xBD, 0xF1, 0xDE, 0xF5, 
	0xB5, 0xAB, 0xDE, 0xF9, 0xE7, 0x3B, 0xAD, 0x69, 0xCE, 
	0xB5, 0xC6, 0x73, 0xA5, 0x6B, 0xCE, 0x71, 0xFF, 0xBF, 
	0x84, 0x21, 0xBE, 0x31, 0xAD, 0xAD, 0x94, 0xA7, 0xB6, 
	0x31, 0xE7, 0x7B, 0xE6, 0xF9, 0xF7, 0xBD, 0xA5, 0x2B, 
	0xDE, 0xF7, 0xA5, 0x69, 0xEF, 0x79, 0x94, 0xE5, 0xBE, 
	0x2F, 0xAD, 0xAF, 0xDF, 0x39, 0xC6, 0x31, 0xB5, 0xAD, 
	0xA5, 0x29, 0xE6, 0xF7, 0xD6, 0xB5, 0xAD, 0xAB, 0x94, 
	0xE7, 0x9D, 0x29, 0xAD, 0x6D, 0xEF, 0xBB, 0xA4, 0xE9, 
	0x84, 0x63, 0xBD, 0xED, 0xAD, 0x6B, 0x8C, 0xA3, 0xB5, 
	0x6D, 0xF7, 0xBB, 0x9C, 0xE7, 0xCE, 0x31, 0xDE, 0xB7, 
	0xD6, 0xB3, 0x9D, 0x27, 0xB5, 0xF1, 0xEF, 0x7B, 0xBD, 
	0xEF, 0xD6, 0xF7, 0xCE, 0xB7, 0xCE, 0x73, 0xEF, 0x39, 
	0x7C, 0x63, 0x94, 0xA5, 0x9C, 0xE5, 0xC6, 0x71, 0xE7, 
	0x39, 0xD6, 0xF5, 0xA5, 0x6D, 0xDF, 0x37, 0xA5, 0xAD, 
	0xB5, 0xED, 0xD6, 0xB7, 0xE7, 0x37, 0xEF, 0x3B, 0xB5, 
	0xAF, 0xE7, 0x79, 0xC6, 0x75, 0x8C, 0xA5, 0x9C, 0xE9, 
	0x7C, 0x21, 0xA5, 0x27, 0x8C, 0x63, 0x94, 0xA3, 0x84, 
	0x61, 0x73, 0xDF, 0x9D, 0x2B, 0xBE, 0x73, 0x73, 0x9D, 
	0xC6, 0x33, 
};

Gfx pillar_switch_xx_48_ci8_aligner[] = {gsSPEndDisplayList()};
u8 pillar_switch_xx_48_ci8[] = {
	0x0, 0x0, 0x1, 0x1, 0x1, 0x0, 0x2, 0x3, 0x1, 
	0x4, 0x0, 0x1, 0x0, 0x5, 0x1, 0x6, 0x6, 0x5, 
	0x5, 0x6, 0x6, 0x6, 0x5, 0x0, 0x1, 0x7, 0x5, 
	0x8, 0x9, 0x4, 0x4, 0xA, 0x1, 0xB, 0x3, 0x3, 
	0x3, 0x3, 0x3, 0xC, 0x6, 0x1, 0x5, 0xD, 0x6, 
	0x6, 0x6, 0x8, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 
	0x6, 0x7, 0x1, 0x5, 0x1, 0x0, 0x4, 0x4, 0x4, 
	0x1, 0x0, 0xD, 0xE, 0x8, 0x8, 0x3, 0x8, 0xF, 
	0x8, 0x6, 0x6, 0x5, 0x8, 0x8, 0x7, 0x8, 0x5, 
	0x2, 0x5, 0x1, 0x7, 0x6, 0x1, 0x1, 0x1, 0x6, 
	0x5, 0x4, 0x0, 0x2, 0x10, 0x0, 0x1, 0x11, 0xE, 
	0x3, 0xE, 0xB, 0xB, 0x12, 0xE, 0xD, 0x8, 0xB, 
	0x5, 0x6, 0x2, 0x8, 0xD, 0x1, 0x6, 0x6, 0x1, 
	0x6, 0xD, 0x6, 0x6, 0x1, 0x13, 0x14, 0x9, 0x4, 
	0x9, 0x6, 0xD, 0xB, 0xC, 0x3, 0x11, 0x8, 0xE, 
	0x15, 0x1, 0x4, 0x0, 0x16, 0x1, 0x7, 0x1, 0x8, 
	0x6, 0x6, 0x8, 0x6, 0x1, 0x0, 0x1, 0x6, 0x1, 
	0x2, 0x7, 0x13, 0x9, 0x4, 0x4, 0x6, 0x1, 0xE, 
	0x17, 0xC, 0x6, 0x1, 0x8, 0x18, 0x6, 0x2, 0x2, 
	0x1, 0x1, 0x6, 0x6, 0xE, 0x6, 0x1, 0xE, 0x8, 
	0x0, 0x4, 0x0, 0x6, 0x1, 0x2, 0x7, 0x8, 0x9, 
	0x2, 0x4, 0x19, 0x5, 0xB, 0xE, 0xD, 0x5, 0x5, 
	0x5, 0x12, 0x6, 0x10, 0x4, 0x1, 0x1, 0x5, 0x7, 
	0x6, 0x1, 0x6, 0x6, 0x0, 0x4, 0x4, 0x4, 0x5, 
	0x1, 0x10, 0x7, 0x8, 0x9, 0x4, 0x9, 0x1A, 0xF, 
	0x15, 0x15, 0xF, 0xF, 0x1B, 0x18, 0x1C, 0xB, 0x6, 
	0x11, 0xB, 0x13, 0x3, 0x8, 0xB, 0x18, 0xE, 0xE, 
	0x8, 0x3, 0x8, 0x8, 0x6, 0x8, 0x8, 0xE, 0xB, 
	0x6, 0x8, 0x13, 0x1D, 0x6, 0x8, 0x8, 0x8, 0x1, 
	0x6, 0x1, 0x11, 0x8, 0x8, 0x8, 0x5, 0x1, 0x1, 
	0x6, 0xB, 0x8, 0x1, 0x7, 0x18, 0x8, 0x11, 0x8, 
	0x8, 0x11, 0x18, 0xC, 0xE, 0x8, 0xE, 0xB, 0x12, 
	0x4, 0x8, 0xD, 0x6, 0x1, 0x7, 0x1, 0x13, 0x5, 
	0xD, 0x5, 0x2, 0x0, 0x6, 0x5, 0x8, 0x0, 0x8, 
	0x8, 0x18, 0x8, 0xE, 0x11, 0x8, 0xE, 0xB, 0xE, 
	0x8, 0xD, 0x3, 0x3, 0xC, 0x0, 0x6, 0x8, 0x1, 
	0x5, 0x1, 0x0, 0x14, 0x5, 0x1, 0x1, 0x1, 0x5, 
	0x8, 0x6, 0x8, 0x0, 0x6, 0x8, 0x12, 0xB, 0xE, 
	0xE, 0x11, 0xE, 0xE, 0xE, 0xE, 0x3, 0x1D, 0x3, 
	0x1E, 0x8, 0x8, 0xE, 0xB, 0x8, 0x11, 0xD, 0xC, 
	0x6, 0x7, 0x6, 0x5, 0x6, 0x6, 0x11, 0xC, 0x1, 
	0x2, 0x5, 0xF, 0x8, 0x3, 0xE, 0x8, 0x11, 0x3, 
	0x3, 0x3, 0x1D, 0x1D, 0x8, 0x18, 0x1, 0x1, 0x6, 
	0x6, 0x6, 0x1, 0x0, 0x8, 0x6, 0x1, 0x7, 0x7, 
	0x6, 0x8, 0x6, 0xB, 0x6, 0x1, 0x5, 0x1E, 0xE, 
	0xB, 0xB, 0x3, 0x3, 0xE, 0xE, 0xE, 0x11, 0xE, 
	0x11, 0xB, 0x4, 0x4, 0x9, 0x4, 0x9, 0x4, 0x9, 
	0x7, 0x8, 0x6, 0x1, 0x6, 0x6, 0xD, 0x6, 0xB, 
	0x8, 0x6, 0x8, 0xF, 0x8, 0x1F, 0xE, 0xB, 0x11, 
	0x6, 0xD, 0x8, 0x11, 0x11, 0x3, 0x18, 0x0, 0x9, 
	0x4, 0x4, 0x9, 0x0, 0x4, 0x7, 0x1, 0x4, 0x1, 
	0x6, 0x6, 0x6, 0x8, 0x3, 0x0, 0x0, 0x11, 0x12, 
	0x6, 0x7, 0x6, 0xE, 0xD, 0x5, 0x1, 0x6, 0xD, 
	0x3, 0x3, 0x18, 0x6, 0x1, 0x6, 0x6, 0x6, 0x6, 
	0x7, 0xE, 0xC, 0x8, 0xE, 0xE, 0x11, 0xB, 0x11, 
	0x1D, 0x18, 0x12, 0x15, 0x20, 0x8, 0x11, 0xC, 0x18, 
	0xC, 0x3, 0x11, 0x8, 0x17, 0x21, 0x6, 0xB, 0x6, 
	0x6, 0x6, 0x6, 0x6, 0x6, 0x5, 0x7, 0x1, 0x1, 
	0x22, 0x14, 0x1, 0xD, 0x6, 0x6, 0x1, 0xC, 0x8, 
	0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 
	0xE, 0xC, 0x0, 0x6, 0x1, 0x5, 0x5, 0x5, 0x5, 
	0x6, 0x6, 0x0, 0x1, 0x1, 0x8, 0x1, 0x5, 0x5, 
	0x6, 0x6, 0x1, 0x11, 0x1, 0x6, 0x0, 0x7, 0x1, 
	0x7, 0x7, 0x8, 0xD, 0x2, 0x1D, 0x8, 0x1, 0x6, 
	0x1, 0x0, 0x1, 0x1, 0x7, 0x6, 0x1, 0x1, 0x5, 
	0x1, 0x8, 0x6, 0x7, 0x23, 0x6, 0x1, 0x7, 0xB, 
	0x1, 0x1, 0x1, 0x0, 0x1, 0x0, 0x7, 0xD, 0x1, 
	0x10, 0x11, 0x8, 0x1, 0x6, 0x5, 0x5, 0x5, 0x6, 
	0x1, 0x6, 0xD, 0x6, 0x6, 0x1, 0xE, 0x11, 0x1, 
	0x1, 0xD, 0xD, 0x1, 0x16, 0x24, 0xC, 0x18, 0x17, 
	0xC, 0x18, 0x18, 0xB, 0x17, 0xC, 0x12, 0xB, 0x1, 
	0x6, 0x5, 0xD, 0x8, 0x6, 0x1, 0x0, 0x1, 0x6, 
	0x1, 0x4, 0xB, 0xE, 0x5, 0x1, 0x0, 0x5, 0x5, 
	0xE, 0xC, 0x17, 0x3, 0xE, 0x18, 0xB, 0x8, 0xD, 
	0x3, 0x11, 0xC, 0x16, 0x11, 0x8, 0x6, 0x1, 0x11, 
	0x8, 0x0, 0x4, 0x0, 0x6, 0x7, 0x4, 0x8, 0xE, 
	0x6, 0x0, 0x4, 0x0, 0x6, 0x6, 0x25, 0x11, 0x8, 
	0x7, 0x6, 0x0, 0x10, 0x1, 0x0, 0x2, 0x8, 0xB, 
	0x6, 0x6, 0x6, 0xD, 0x6, 0x7, 0x2, 0x4, 0x2, 
	0x6, 0x6, 0x4, 0x8, 0xD, 0x0, 0x2, 0x2, 0x2, 
	0x1, 0xE, 0x8, 0x8, 0x8, 0x11, 0x18, 0x6, 0x1, 
	0x1, 0x7, 0x7, 0xE, 0xB, 0x6, 0x6, 0xE, 0xB, 
	0xB, 0x8, 0xE, 0x6, 0x16, 0x18, 0x8, 0x6, 0xB, 
	0xC, 0x8, 0x8, 0x8, 0xC, 0xE, 0xC, 0x18, 0xB, 
	0x1D, 0x18, 0x12, 0xB, 0x8, 0xD, 0xB, 0x18, 0xC, 
	0xC, 0xB, 0xE, 0x6, 0x6, 0x8, 0x6, 0x0, 0x7, 
	0x6, 0x0, 0x9, 0x0, 0x4, 0x4, 0x4, 0x4, 0x9, 
	0x8, 0x1, 0x0, 0xD, 0x6, 0x0, 0x7, 0x2, 0x7, 
	0x1, 0x8, 0x8, 0xE, 0x4, 0x7, 0x1, 0x1, 0x1, 
	0x8, 0x8, 0x6, 0x5, 0x7, 0x6, 0x0, 0x4, 0x2, 
	0x4, 0x4, 0x4, 0x4, 0x9, 0x8, 0x1, 0x5, 0x8, 
	0x6, 0x7, 0x0, 0x6, 0x6, 0x5, 0x13, 0xD, 0x6, 
	0x0, 0x8, 0x6, 0x5, 0x1, 0x6, 0x8, 0x6, 0x6, 
	0x1, 0x8, 0x6, 0x9, 0x4, 0x4, 0x4, 0x4, 0x4, 
	0x4, 0x8, 0x1, 0x1, 0x1, 0x1, 0x7, 0x1, 0x6, 
	0x5, 0x1, 0x1, 0x6, 0x8, 0x1, 0x8, 0x6, 0x6, 
	0x6, 0x5, 0x6, 0x8, 0x1, 0x0, 0x8, 0x5, 0x9, 
	0x4, 0x4, 0x4, 0x0, 0x4, 0x9, 0x3, 0xB, 0xE, 
	0xE, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0x22, 0x18, 
	0x18, 0x7, 0x6, 0xE, 0x11, 0x6, 0x6, 0x1, 0x6, 
	0x5, 0x4, 0x7, 0x0, 0x9, 0x4, 0x4, 0x4, 0x4, 
	0x4, 0x9, 0x8, 0x1, 0x0, 0x5, 0x1, 0x1, 0x5, 
	0x6, 0x1, 0x1, 0x19, 0x8, 0xB, 0x1, 0x8, 0xD, 
	0x6, 0x6, 0x5, 0x7, 0x5, 0x7, 0x1, 0x6, 0x0, 
	0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0xD, 0x1, 
	0x5, 0x6, 0x1, 0x6, 0x6, 0x6, 0x6, 0x6, 0x1, 
	0x6, 0xB, 0x5, 0x8, 0x6, 0x6, 0x1, 0x7, 0x1, 
	0x1, 0x0, 0x8, 0x8, 0x4, 0x9, 0x9, 0x26, 0x4, 
	0x4, 0x9, 0x2, 0x3, 0x1, 0x0, 0x2, 0x1, 0xD, 
	0xD, 0x6, 0x8, 0x1, 0x4, 0x6, 0xB, 0x1, 0x6, 
	0x8, 0x6, 0xB, 0x3, 0x1D, 0xB, 0xB, 0x8, 0xC, 
	0x1D, 0xB, 0xB, 0xB, 0x1D, 0xB, 0xB, 0xC, 0x1E, 
	0x0, 0x0, 0x1, 0x1, 0x5, 0x6, 0x8, 0x5, 0x5, 
	0x7, 0x1, 0x12, 0xB, 0x18, 0xB, 0xB, 
};

Gfx pillar_switch_xx_48_ci8_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 pillar_switch_xx_48_ci8_pal_rgba16[] = {
	0xEF, 0x7B, 0xE7, 0x39, 0xF7, 0x7D, 0xCE, 0x33, 0xF7, 
	0xBD, 0xE6, 0xF9, 0xDE, 0xF7, 0xEF, 0x3B, 0xD6, 0xB5, 
	0xFF, 0xFF, 0xDE, 0xF5, 0xC6, 0x31, 0xBD, 0xEF, 0xDE, 
	0xB7, 0xCE, 0x73, 0xAD, 0x6B, 0xFF, 0xBF, 0xD6, 0x75, 
	0xA5, 0x29, 0xDE, 0xB5, 0xD6, 0x73, 0x9C, 0xE7, 0xCE, 
	0x31, 0xBD, 0xAF, 0xB5, 0xAD, 0xE6, 0xF7, 0xE7, 0x3B, 
	0xAD, 0x2B, 0x8C, 0x63, 0xC5, 0xF1, 0xB5, 0x6D, 0xD6, 
	0xB7, 0x94, 0xA5, 0xB5, 0xAF, 0xC5, 0xEF, 0xEF, 0x39, 
	0xB5, 0x6B, 0xDE, 0xF9, 0xF7, 0xFD, 
};

Vtx pillar_switch_Switch_001_mesh_vtx_cull[8] = {
	{{{-134, 0, -134},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-134, 0, 134},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-134, 28, 134},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-134, 28, -134},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{134, 0, -134},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{134, 0, 134},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{134, 28, 134},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{134, 28, -134},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
};

Vtx pillar_switch_Switch_001_mesh_vtx_0[32] = {
	{{{-134, 0, 134},0, {128, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-134, 28, 134},0, {-81, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-134, 28, -134},0, {-81, 2007},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-134, 0, -134},0, {128, 2007},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-134, 0, -134},0, {128, 2007},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-134, 28, -134},0, {-81, 2007},{0x0, 0x0, 0x81, 0xFF}}},
	{{{134, 28, -134},0, {-81, 3007},{0x0, 0x0, 0x81, 0xFF}}},
	{{{134, 0, -134},0, {128, 3007},{0x0, 0x0, 0x81, 0xFF}}},
	{{{134, 0, -134},0, {128, -991},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{134, 28, -134},0, {-81, -991},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{134, 28, 134},0, {-81, 8},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{134, 0, 134},0, {128, 8},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{134, 0, 134},0, {128, 8},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{134, 28, 134},0, {-81, 8},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-134, 28, 134},0, {-81, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-134, 0, 134},0, {128, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-104, 28, -104},0, {541, -298},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{104, 28, -104},0, {541, 1290},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{134, 28, -134},0, {771, 1520},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-134, 28, -134},0, {771, -528},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{104, 28, 104},0, {541, -298},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-104, 28, 104},0, {541, 1290},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-134, 28, 134},0, {771, 1520},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{134, 28, 134},0, {771, -528},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{104, 28, -104},0, {541, -298},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{104, 28, 104},0, {541, 1290},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{134, 28, 134},0, {771, 1520},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{134, 28, -134},0, {771, -528},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-104, 28, 104},0, {541, -298},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-104, 28, -104},0, {541, 1290},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-134, 28, -134},0, {771, 1520},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-134, 28, 134},0, {771, -528},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx pillar_switch_Switch_001_mesh_tri_0[] = {
	gsSPVertex(pillar_switch_Switch_001_mesh_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPEndDisplayList(),
};Vtx pillar_switch_Switch_001_mesh_vtx_1[4] = {
	{{{104, 28, -104},0, {-342, 1334},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-104, 28, -104},0, {1334, 1334},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-104, 28, 104},0, {1334, -342},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{104, 28, 104},0, {-342, -342},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx pillar_switch_Switch_001_mesh_tri_1[] = {
	gsSPVertex(pillar_switch_Switch_001_mesh_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_pillar_switch_Pillar[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, pillar_switch_pillar7_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 90),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 32, pillar_switch_pillar7_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(pillar_switch_Pillar_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_pillar_switch_Pillar[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};


Gfx mat_pillar_switch_Bricks[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, pillar_switch_xx_48_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 38),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 32, pillar_switch_xx_48_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(pillar_switch_Bricks_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_pillar_switch_Bricks[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};


Gfx pillar_switch_Switch_001_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(pillar_switch_Switch_001_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_pillar_switch_Pillar),
	gsSPDisplayList(pillar_switch_Switch_001_mesh_tri_0),
	gsSPDisplayList(mat_revert_pillar_switch_Pillar),
	gsSPDisplayList(mat_pillar_switch_Bricks),
	gsSPDisplayList(pillar_switch_Switch_001_mesh_tri_1),
	gsSPDisplayList(mat_revert_pillar_switch_Bricks),
	gsSPEndDisplayList(),
};



Gfx pillar_switch_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
