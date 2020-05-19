const Lights1 BombSwitch_Switch_Side_001_lights = gdSPDefLights1(
	0xBB, 0xBB, 0xBB,
	0xFE, 0xFE, 0xFE, 0x3F, 0x59, 0x3F);

const Lights1 BombSwitch_Bomb_001_lights = gdSPDefLights1(
	0xBB, 0xBB, 0xBB,
	0xFE, 0xFE, 0xFE, 0x3F, 0x59, 0x3F);

const u8 BombSwitch__4_ci8[] = {
	0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x6, 0x7, 
	0x8, 0x7, 0x9, 0x5, 0xA, 0x3, 0x1, 0xB, 0xA, 
	0xC, 0x3, 0xD, 0x3, 0x1, 0x9, 0x1, 0x5, 0x3, 
	0xE, 0xD, 0x6, 0xE, 0x8, 0xE, 0x3, 0xF, 0x10, 
	0x9, 0x5, 0xB, 0xB, 0x0, 0x6, 0xE, 0x1, 0x6, 
	0x5, 0x8, 0x11, 0xB, 0x6, 0xB, 0x12, 0x10, 0xC, 
	0x13, 0xC, 0x3, 0xA, 0xB, 0x5, 0xB, 0x14, 0x13, 
	0x12, 0x9, 0x15, 0xE, 0x3, 0xA, 0xD, 0x8, 0x5, 
	0xF, 0x5, 0x6, 0x15, 0x1, 0x8, 0xE, 0x12, 0xB, 
	0x2, 0x8, 0x10, 0x13, 0xC, 0xC, 0x6, 0x2, 0x13, 
	0x10, 0xB, 0xB, 0x8, 0x13, 0x13, 0x10, 0xA, 0x10, 
	0x8, 0x1, 0x8, 0x15, 0x3, 0xA, 0x16, 0x17, 0x18, 
	0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x17, 0x1D, 0x1A, 0x1E, 
	0x0, 0x12, 0x12, 0x3, 0x1, 0x3, 0x3, 0x5, 0xB, 
	0x1, 0xB, 0x12, 0x5, 0x3, 0x5, 0x5, 0x13, 0x1, 
	0x3, 0x15, 0x1F, 0xF, 0x8, 0xF, 0x15, 0x15, 0x1, 
	0x5, 0x1, 0xF, 0x15, 0x0, 0x20, 0xC, 0x21, 0x3, 
	0x3, 0x8, 0x1F, 0x1, 0x22, 0x5, 0x11, 0xB, 0x1, 
	0x0, 0x5, 0xB, 0x23, 0xE, 0x3, 0x10, 0x1, 0x13, 
	0x5, 0x12, 0xA, 0xD, 0x0, 0x5, 0xD, 0x7, 0xB, 
	0x24, 0x11, 0x11, 0x1, 0xF, 0x11, 0x3, 0xA, 0x6, 
	0x1, 0xA, 0x4, 0xB, 0x5, 0xA, 0x5, 0x12, 0x15, 
	0xE, 0xA, 0xE, 0x15, 0x22, 0x14, 0x13, 0x3, 0x7, 
	0x1, 0x12, 0x6, 0xB, 0x14, 0x25, 0xB, 0xE, 0x13, 
	0xB, 0xB, 0x10, 0x1, 0x11, 0x1, 0x5, 0x26, 0x10, 
	0xA, 0xA, 0x0, 0x5, 0x6, 0x5, 0x6, 0x4, 0x5, 
	0xD, 0x20, 0x10, 0x3, 0x0, 0x1, 0x3, 0x1, 0xB, 
	0x27, 0x25, 0x26, 0xD, 0x6, 0x8, 0x28, 0x1F, 0x11, 
	0x14, 0xF, 0x5, 0xA, 0x5, 0x29, 0x0, 0x2A, 0x1, 
	0x2, 0x5, 0x0, 0x1, 0x1, 0x5, 0x10, 0x24, 0xB, 
	0x6, 0xF, 0x8, 0x4, 0x11, 0x5, 0x29, 0x3, 0xB, 
	0x26, 0x28, 0x2B, 0x10, 0xA, 0x2C, 0x26, 0x1, 0x6, 
	0x10, 0x5, 0x2D, 0x2A, 0x5, 0x6, 0x26, 0x5, 0x3, 
	0xA, 0x5, 0x3, 0x6, 0x21, 0x3, 0x8, 0xB, 0x11, 
	0xF, 0xF, 0x26, 0x0, 0x1, 0xA, 0x26, 0x10, 0x1, 
	0x25, 0x5, 0x2A, 0x0, 0xA, 0xA, 0xA, 0x1B, 0x29, 
	0xB, 0x8, 0x5, 0x5, 0xF, 0x10, 0x0, 0x1, 0xA, 
	0x10, 0x10, 0x0, 0x20, 0x25, 0x2E, 0x5, 0x2F, 0x1, 
	0x2A, 0x25, 0xF, 0x3, 0x25, 0x28, 0xA, 0xA, 0x29, 
	0xA, 0x8, 0x2A, 0xF, 0x2C, 0x28, 0xB, 0x0, 0x2E, 
	0x2C, 0xE, 0x1, 0x26, 0x2C, 0x5, 0x2, 0x24, 0xD, 
	0x15, 0x29, 0x2F, 0x26, 0x28, 0x26, 0xF, 0xF, 0x2A, 
	0x2E, 0x2A, 0xF, 0x2A, 0xF, 0x5, 0xF, 0xA, 0xF, 
	0x25, 0x6, 0x1, 0x6, 0x5, 0xF, 0x2C, 0x5, 0x29, 
	0x26, 0x3, 0x15, 0x30, 0xA, 0x2C, 0xF, 0x29, 0x2A, 
	0x26, 0x31, 0xF, 0x29, 0x3, 0x26, 0x29, 0xA, 0x2A, 
	0x1B, 0x5, 0x29, 0x2A, 0x31, 0x29, 0x25, 0x0, 0xF, 
	0x29, 0x29, 0xE, 0x1, 0xF, 0x5, 0x29, 0x25, 0x5, 
	0xF, 0xF, 0x2D, 0x2D, 0xF, 0x2E, 0xF, 0xF, 0x31, 
	0x1B, 0xF, 0x26, 0x3, 0x29, 0xF, 0x29, 0xA, 0x2C, 
	0x1B, 0xF, 0xA, 0x26, 0xF, 0x2C, 0x0, 0x15, 0x6, 
	0x5, 0x29, 0x29, 0xA, 0x5, 0xF, 0x2C, 0xF, 0x32, 
	0xF, 0x33, 0xF, 0x2C, 0xF, 0x29, 0x2E, 0x29, 0x29, 
	0xF, 0x2C, 0x5, 0xF, 0x1B, 0x2D, 0x2C, 0x5, 0x2A, 
	0x5, 0xF, 0xF, 0x5, 0xF, 0x1B, 0xF, 0x2A, 0x29, 
	0xF, 0x29, 0xF, 0xF, 0x34, 0x2C, 0xF, 0x2C, 0x2D, 
	0x2D, 0x2C, 0xA, 0x0, 0x0, 0x35, 0xF, 0x29, 
};
const u8 BombSwitch__4_ci8_pal_rgba16[] = {
	0x8C, 0x63, 0xAD, 0x29, 0xCE, 0x31, 0xB5, 0x6B, 0xB5, 
	0xAD, 0xA4, 0xE7, 0xA5, 0x27, 0xA5, 0x29, 0x9C, 0xE5, 
	0x9C, 0xE7, 0x9C, 0xA5, 0xBD, 0xAD, 0xBD, 0xEF, 0xBD, 
	0xED, 0xAD, 0x69, 0x94, 0x63, 0xB5, 0xAB, 0xC6, 0x2F, 
	0xAD, 0x6B, 0xC5, 0xEF, 0xD6, 0x73, 0x94, 0xA3, 0x5A, 
	0x95, 0x84, 0x1F, 0x6B, 0x19, 0x73, 0x9D, 0x7B, 0x9D, 
	0x8C, 0x21, 0x7B, 0xDD, 0x73, 0x5B, 0x62, 0xD7, 0xDE, 
	0xB5, 0xDE, 0xF7, 0xCE, 0x71, 0xD6, 0xB3, 0x94, 0xA5, 
	0xD6, 0xB5, 0xB5, 0x69, 0xAD, 0x27, 0xDE, 0xF5, 0xBD, 
	0xAB, 0x9C, 0xA3, 0xA4, 0xE5, 0xC5, 0xED, 0x8C, 0x61, 
	0x8C, 0x1F, 0xA4, 0xA5, 0xAC, 0xE7, 0xCE, 0x73, 0x9C, 
	0x63, 0x83, 0x9D, 0x83, 0xDD, 0x8B, 0xDF, 0x83, 0xDF, 
	
};
const u8 BombSwitch_bomb_ci8[] = {
	0x0, 0x0, 0x1, 0x1, 0x0, 0x2, 0x0, 0x0, 0x3, 
	0x4, 0x0, 0x5, 0x6, 0x7, 0x0, 0x8, 0x9, 0xA, 
	0x3, 0x7, 0xB, 0xC, 0x0, 0x7, 0x7, 0xD, 0x8, 
	0x0, 0xE, 0x7, 0xB, 0xE, 0x7, 0xF, 0x0, 0x10, 
	0x11, 0x12, 0x0, 0xF, 0x0, 0x7, 0x2, 0xA, 0x13, 
	0x7, 0x7, 0x14, 0x9, 0x13, 0x2, 0x15, 0x13, 0x5, 
	0x15, 0x7, 0x16, 0x7, 0xE, 0xE, 0x13, 0x15, 0x15, 
	0xE, 0xC, 0x8, 0xE, 0x7, 0xC, 0x17, 0x8, 0x18, 
	0xE, 0x0, 0x8, 0xE, 0x15, 0xE, 0x19, 0x13, 0xE, 
	0x7, 0x1A, 0x13, 0xD, 0x1B, 0xE, 0x0, 0x8, 0xE, 
	0x7, 0x0, 0xA, 0x8, 0x1C, 0xE, 0x15, 0xD, 0x9, 
	0xE, 0x15, 0xE, 0x1D, 0x13, 0xD, 0xE, 0x8, 0x6, 
	0x1E, 0x8, 0x1F, 0x16, 0x6, 0x1F, 0xD, 0xE, 0x1E, 
	0x13, 0xD, 0x13, 0xD, 0x9, 0xE, 0xE, 0xE, 0x1D, 
	0x16, 0xD, 0xE, 0x8, 0x15, 0x13, 0x15, 0x20, 0x21, 
	0x14, 0x8, 0x6, 0x17, 0x1B, 0x8, 0x6, 0x1B, 0x8, 
	0x6, 0x13, 0x1D, 0xE, 0x6, 0x6, 0x8, 0x19, 0xE, 
	0x1C, 0x16, 0x17, 0x16, 0x15, 0x16, 0x8, 0x6, 0x1E, 
	0x9, 0x8, 0x15, 0xE, 0x9, 0xE, 0x1E, 0x19, 0x6, 
	0x0, 0x17, 0x9, 0x1A, 0xD, 0x6, 0x1E, 0x6, 0x8, 
	0xE, 0xE, 0x1E, 0x8, 0x1E, 0x9, 0x8, 0x0, 0xE, 
	0x9, 0x1F, 0xD, 0x15, 0xD, 0x9, 0xE, 0xE, 0xE, 
	0x1D, 0x15, 0xD, 0x8, 0x8, 0xE, 0xD, 0x1D, 0x16, 
	0xD, 0x15, 0xD, 0x6, 0xE, 0xE, 0x13, 0x1D, 0x15, 
	0xD, 0x6, 0x8, 0xE, 0x8, 0x1D, 0x16, 0xD, 0x17, 
	0x19, 0x1E, 0x15, 0x1F, 0x16, 0xE, 0x17, 0x1D, 0xD, 
	0x22, 0x8, 0x15, 0xE, 0x17, 0xE, 0x17, 0x19, 0x1E, 
	0x15, 0xE, 0x16, 0xE, 0x17, 0x1D, 0x1E, 0xE, 0x17, 
	0x15, 0xE, 0x17, 0xE, 0xC, 0x8, 0xE, 0x23, 0x0, 
	0xB, 0x8, 0x8, 0x8, 0x15, 0xA, 0x0, 0xA, 0x8, 
	0x1C, 0xE, 0xC, 0x8, 0xE, 0x7, 0x0, 0xB, 0x8, 
	0x6, 0x8, 0x15, 0xA, 0x0, 0xA, 0x8, 0x1C, 0xE, 
	0xE, 0x6, 0xD, 0xE, 0xF, 0x17, 0x5, 0x17, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0xE, 0x4, 0x17, 0x5, 0x17, 0xB, 0xD, 0x8, 
	0x0, 0xE, 0xE, 0x17, 0x5, 0xE, 0x0, 0x15, 0x15, 
	0x2, 0x13, 0x6, 0xE, 0x24, 0x24, 0x24, 0x25, 0x26, 
	0x27, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x7, 
	0x19, 0xE, 0x13, 0xE, 0x7, 0x2, 0x15, 0x6, 0x13, 
	0xE, 0x2, 0xF, 0x13, 0x7, 0x5, 0x5, 0x15, 0x28, 
	0x29, 0x24, 0x25, 0x26, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0xB, 0x6, 0x29, 0xA, 
	0x7, 0x7, 0xF, 0xB, 0x6, 0xC, 0xE, 0x3, 0x0, 
	0x5, 0x13, 0xB, 0x17, 0xE, 0x15, 0x24, 0x26, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x2A, 0x2A, 0x24, 0x24, 
	0x24, 0x24, 0x8, 0x17, 0xE, 0x15, 0x7, 0x5, 0x17, 
	0xE, 0x17, 0x7, 0xA, 0x7, 0xA, 0x5, 0x0, 0x7, 
	0x7, 0x7, 0x24, 0x27, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x2B, 0x2C, 0x2C, 0x2B, 0x24, 0x24, 0x24, 0x0, 0x3, 
	0x4, 0x7, 0x28, 0x8, 0x5, 0x0, 0x0, 0x29, 0x29, 
	0x11, 0xF, 0x15, 0x5, 0x0, 0xF, 0xC, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x2A, 0x2C, 0x2D, 0x2D, 0x2C, 
	0x2A, 0x24, 0x24, 0x24, 0x0, 0x7, 0x2, 0x7, 0x7, 
	0x7, 0x7, 0x0, 0x7, 0x15, 0x0, 0xB, 0x17, 0x8, 
	0x17, 0xE, 0x0, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x2A, 0x2C, 0x2D, 0x2D, 0x2C, 0x2A, 0x24, 0x24, 0x24, 
	0x17, 0xE, 0x0, 0x7, 0x15, 0xA, 0x4, 0x0, 0x9, 
	0xA, 0x3, 0x7, 0xB, 0xC, 0x0, 0x7, 0x7, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x2B, 0x2C, 0x2C, 
	0x2B, 0x24, 0x24, 0x24, 0x24, 0x3, 0x4, 0x0, 0x5, 
	0x6, 0x7, 0x0, 0x8, 0x9, 0x13, 0x2, 0x15, 0x13, 
	0x5, 0x15, 0x7, 0x16, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x2A, 0x2A, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x0, 0x7, 0x2, 0xA, 0x13, 0x7, 0x7, 0x14, 
	0xE, 0x7, 0x1A, 0x13, 0xD, 0x1B, 0xE, 0x0, 0x8, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0xE, 0x0, 0x8, 
	0xE, 0x15, 0xE, 0x19, 0x13, 0x6, 0x1F, 0xD, 0xE, 
	0x1E, 0x13, 0xD, 0x13, 0xD, 0x9, 0x24, 0x2A, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x2A, 
	0x24, 0x13, 0xD, 0xE, 0x8, 0x6, 0x1E, 0x8, 0x1F, 
	0x16, 0x6, 0x13, 0x1D, 0xE, 0x6, 0x6, 0x8, 0x19, 
	0xE, 0x1C, 0x24, 0x24, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 
	0x2A, 0x2A, 0x2A, 0x2A, 0x24, 0x24, 0x14, 0x8, 0x6, 
	0x17, 0x1B, 0x8, 0x6, 0x1B, 0x8, 0x6, 0x1E, 0x6, 
	0x8, 0xE, 0xE, 0x1E, 0x8, 0x1E, 0x9, 0x8, 0x24, 
	0x24, 0x2A, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2A, 0x24, 
	0x24, 0x9, 0xE, 0x1E, 0x19, 0x6, 0x0, 0x17, 0x9, 
	0x1A, 0xD, 0x15, 0xD, 0x6, 0xE, 0xE, 0x13, 0x1D, 
	0x15, 0xD, 0x6, 0x8, 0xE, 0x24, 0x24, 0x24, 0x2A, 
	0x2A, 0x2A, 0x24, 0x24, 0x24, 0xE, 0x1D, 0x15, 0xD, 
	0x8, 0x8, 0xE, 0xD, 0x1D, 0x16, 0xD, 0x17, 0x19, 
	0x1E, 0x15, 0xE, 0x16, 0xE, 0x17, 0x1D, 0x1E, 0xE, 
	0x17, 0x15, 0xE, 0x24, 0x24, 0x24, 0x24, 0x24, 0x15, 
	0x1F, 0x16, 0xE, 0x17, 0x1D, 0xD, 0x22, 0x8, 0x15, 
	0xE, 0x17, 0xE, 0xC, 0x8, 0xE, 0x7, 0x0, 0xB, 
	0x8, 0x6, 0x8, 0x15, 0xA, 0x0, 0xA, 0x8, 0x1C, 
	0xE, 0xC, 0x8, 0xE, 0x23, 0x0, 0xB, 0x8, 0x8, 
	0x8, 0x15, 0xA, 0x0, 0xA, 0x8, 0x1C, 0xE, 0xE, 
	0x6, 0x1E, 0xE, 0x4, 0x17, 0x5, 0x17, 0xB, 0xD, 
	0x8, 0x0, 0xE, 0xE, 0x17, 0x5, 0xE, 0x6, 0xD, 
	0xE, 0xF, 0x17, 0x5, 0x17, 0x6, 0x6, 0x8, 0x29, 
	0xA, 0xE, 0x17, 0x5, 0xE, 0x0, 0x15, 0x15, 0x0, 
	0x7, 0x19, 0xE, 0x13, 0xE, 0x7, 0x2, 0x15, 0x6, 
	0x13, 0xE, 0xE, 0x0, 0x15, 0x15, 0x2, 0x13, 0x6, 
	0xE, 0x7, 0xE, 0x15, 0xF, 0x7, 0x9, 0x13, 0xE, 
	0x2, 0x29, 0x13, 0xA, 0x7, 0x0, 0xB, 0x6, 0x29, 
	0xA, 0x7, 0x7, 0xF, 0xB, 0x6, 0xC, 0x2, 0xF, 
	0x13, 0x7, 0x5, 0x5, 0x15, 0x28, 0x29, 0x13, 0xA, 
	0x0, 0x29, 0x2E, 0x9, 0xC, 0xE, 0x0, 0x0, 0x15, 
	0x16, 0xB, 0x17, 0x8, 0x17, 0xE, 0x15, 0x7, 0x5, 
	0x17, 0xE, 0x17, 0xE, 0x3, 0x0, 0x5, 0x13, 0xB, 
	0x17, 0xE, 0x15, 0x7, 0x15, 0x0, 0xB, 0x17, 0x8, 
	0x17, 0x0, 0x0, 0x1, 0x1, 0x0, 0x2, 0x0, 0x0, 
	0x3, 0x4, 0x7, 0x28, 0x8, 0x5, 0x0, 0x0, 0x7, 
	0xA, 0x7, 0xA, 0x5, 0x0, 0x7, 0x7, 0x7, 0xD, 
	0x8, 0x0, 0xE, 0x7, 0xB, 0xE, 0x0, 0x29, 0xF, 
	0x10, 0x0, 0x12, 0x0, 0x29, 0x0, 0x7, 0x2, 0x7, 
	0x7, 0x7, 0x7, 0x0, 0x29, 0x29, 0x11, 0xF, 0x15, 
	0x5, 0x0, 0xF, 0xC, 0x16, 0x17, 0xE, 0x7, 0x7, 
	0x15, 0xE, 0xE, 0x0, 0x0, 0x15, 0x0, 0xB, 0x17, 
	0x8, 0x17, 0xE, 0x0, 0x7, 0x15, 0xA, 0x4, 0x0, 
	0x7, 0x15, 0x0, 0xB, 0x17, 0x8, 0x17, 0xE, 0x0, 
	0x0, 0x15, 0x0, 0xB, 0x17, 0x8, 0x17, 
};
const u8 BombSwitch_bomb_ci8_pal_rgba16[] = {
	0x94, 0x63, 0x8C, 0x1F, 0xA4, 0xA5, 0x9C, 0x63, 0x8C, 
	0x21, 0xAD, 0x27, 0xB5, 0x6B, 0x9C, 0xA3, 0xAD, 0x29, 
	0xBD, 0xAD, 0xA4, 0xE5, 0xB5, 0x69, 0x8C, 0x63, 0xAD, 
	0x69, 0xA4, 0xE7, 0x94, 0x61, 0x83, 0x9D, 0x94, 0x21, 
	0x83, 0xDD, 0x9C, 0xE5, 0xC6, 0x2F, 0x9C, 0xA5, 0x94, 
	0xA3, 0xA5, 0x27, 0xC6, 0x31, 0xB5, 0xAD, 0x94, 0xA5, 
	0xC5, 0xEF, 0xCE, 0x31, 0xAD, 0x6B, 0xB5, 0xAB, 0x9C, 
	0xE7, 0xD6, 0xB5, 0xBD, 0xEF, 0xA5, 0x29, 0x9C, 0xE3, 
	0x0, 0x1, 0xFD, 0xE1, 0xFC, 0x9, 0xB1, 0x81, 0xAC, 
	0xE7, 0x8C, 0x61, 0x32, 0x33, 0x53, 0xFF, 0x8D, 0x7F, 
	0xFF, 0xBF, 0xBD, 0xAB, 
};
const Vtx BombSwitch_Bomb_Switch_mesh_vtx_cull[8] = {
	{{{-76, 0, -76},0, {0xFFF0, 0xFFF0},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-76, 0, 76},0, {0xFFF0, 0xFFF0},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-76, 78, 76},0, {0xFFF0, 0xFFF0},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-76, 78, -76},0, {0xFFF0, 0xFFF0},{0x0, 0x0, 0x0, 0xFF}}},
	{{{76, 0, -76},0, {0xFFF0, 0xFFF0},{0x0, 0x0, 0x0, 0xFF}}},
	{{{76, 0, 76},0, {0xFFF0, 0xFFF0},{0x0, 0x0, 0x0, 0xFF}}},
	{{{76, 78, 76},0, {0xFFF0, 0xFFF0},{0x0, 0x0, 0x0, 0xFF}}},
	{{{76, 78, -76},0, {0xFFF0, 0xFFF0},{0x0, 0x0, 0x0, 0xFF}}},
};

const Vtx BombSwitch_Bomb_Switch_mesh_vtx_0[16] = {
	{{{-76, 0, 76},0, {0x3DC, 0x1F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-76, 78, 76},0, {0x3DC, 0xFFF0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-76, 78, -76},0, {0xFFF0, 0xFFF0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-76, 0, -76},0, {0xFFF0, 0x1F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-76, 0, -76},0, {0x3DC, 0x1F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-76, 78, -76},0, {0x3DC, 0xFFF0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{76, 78, -76},0, {0xFFF0, 0xFFF0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{76, 0, -76},0, {0xFFF0, 0x1F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{76, 0, -76},0, {0x3DC, 0x1F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{76, 78, -76},0, {0x3DC, 0xFFF0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{76, 78, 76},0, {0xFFF0, 0xFFF0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{76, 0, 76},0, {0xFFF0, 0x1F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{76, 0, 76},0, {0x3DC, 0x1F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{76, 78, 76},0, {0x3DC, 0xFFF0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-76, 78, 76},0, {0xFFF0, 0xFFF0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-76, 0, 76},0, {0xFFF0, 0x1F0},{0x0, 0x0, 0x7F, 0xFF}}},
};

const Gfx BombSwitch_Bomb_Switch_mesh_tri_0[] = {
	gsSPVertex(BombSwitch_Bomb_Switch_mesh_vtx_0 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSPEndDisplayList(),
};const Vtx BombSwitch_Bomb_Switch_mesh_vtx_1[4] = {
	{{{76, 78, -76},0, {0x36B, 0x75},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-76, 78, -76},0, {0x75, 0x75},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-76, 78, 76},0, {0x75, 0x36B},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{76, 78, 76},0, {0x36B, 0x36B},{0x0, 0x7F, 0x0, 0xFF}}},
};

const Gfx BombSwitch_Bomb_Switch_mesh_tri_1[] = {
	gsSPVertex(BombSwitch_Bomb_Switch_mesh_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


const Gfx mat_BombSwitch_Switch_Side_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, BombSwitch__4_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 53),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 32, BombSwitch__4_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 60),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 60),
	gsSPSetLights1(BombSwitch_Switch_Side_001_lights),
	gsSPEndDisplayList(),
};

const Gfx mat_revert_BombSwitch_Switch_Side_001[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};


const Gfx mat_BombSwitch_Bomb_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, BombSwitch_bomb_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 46),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 32, BombSwitch_bomb_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(BombSwitch_Bomb_001_lights),
	gsSPEndDisplayList(),
};

const Gfx mat_revert_BombSwitch_Bomb_001[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};


const Gfx BombSwitch_Bomb_Switch_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(BombSwitch_Bomb_Switch_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_BombSwitch_Switch_Side_001),
	gsSPDisplayList(BombSwitch_Bomb_Switch_mesh_tri_0),
	gsSPDisplayList(mat_revert_BombSwitch_Switch_Side_001),
	gsSPDisplayList(mat_BombSwitch_Bomb_001),
	gsSPDisplayList(BombSwitch_Bomb_Switch_mesh_tri_1),
	gsSPDisplayList(mat_revert_BombSwitch_Bomb_001),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



const Gfx BombSwitch_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
