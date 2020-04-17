const Lights1 canyon_button_Button_lights = gdSPDefLights1(
	0xBB, 0xBB, 0xBB,
	0xFE, 0xFE, 0xFE, 0x3F, 0x59, 0x3F);

const u8 canyon_button_xx_3_ci8[] = {
	0x0, 0x1, 0x2, 0x3, 0x4, 0x4, 0x4, 0x3, 0x5, 
	0x6, 0x5, 0x5, 0x7, 0x3, 0x3, 0x5, 0x5, 0x3, 
	0x4, 0x2, 0x2, 0x2, 0x5, 0x5, 0x3, 0x7, 0x5, 
	0x5, 0x3, 0x8, 0x9, 0x0, 0xA, 0x3, 0xB, 0xB, 
	0xC, 0xC, 0xC, 0xB, 0xD, 0xE, 0xD, 0xD, 0xF, 
	0xD, 0xD, 0x10, 0xC, 0xB, 0x10, 0x11, 0x12, 0xB, 
	0xB, 0x11, 0xB, 0x13, 0xB, 0xF, 0xB, 0xD, 0x14, 
	0x15, 0x16, 0xD, 0x17, 0x18, 0x19, 0x18, 0x18, 0x1A, 
	0x18, 0x18, 0x18, 0x1B, 0x18, 0x18, 0x1C, 0x1C, 0x14, 
	0x18, 0x18, 0x18, 0x18, 0x1B, 0x14, 0xE, 0x18, 0x1D, 
	0x1D, 0x18, 0x18, 0x18, 0xD, 0x15, 0x1E, 0xD, 0xD, 
	0xD, 0x18, 0x17, 0x18, 0x1A, 0x18, 0x1D, 0x14, 0x18, 
	0x18, 0x18, 0xB, 0x1F, 0xD, 0xD, 0x19, 0x20, 0x18, 
	0xD, 0x21, 0x18, 0x18, 0x1D, 0x1D, 0x9, 0x18, 0x1A, 
	0x22, 0x0, 0x11, 0xD, 0xD, 0xD, 0x23, 0x17, 0x18, 
	0x18, 0x17, 0x24, 0x18, 0x14, 0x18, 0x14, 0x1F, 0x14, 
	0x18, 0x19, 0x19, 0x20, 0xD, 0xD, 0x18, 0xD, 0x18, 
	0xD, 0x1C, 0x1B, 0x18, 0x1C, 0x14, 0x25, 0x11, 0xE, 
	0x18, 0x14, 0x24, 0x17, 0x17, 0x1B, 0x26, 0x17, 0x18, 
	0x14, 0x14, 0x14, 0x14, 0x1B, 0x18, 0x18, 0x20, 0x19, 
	0x19, 0x19, 0x18, 0xD, 0xD, 0xD, 0xD, 0x18, 0x18, 
	0x14, 0x1B, 0x27, 0x28, 0xD, 0x18, 0x14, 0x18, 0x18, 
	0x29, 0x17, 0x2A, 0x26, 0x18, 0x18, 0xD, 0xD, 0x14, 
	0x1B, 0x18, 0x14, 0x14, 0xD, 0x1C, 0xD, 0x18, 0x14, 
	0xD, 0xD, 0xD, 0x14, 0x14, 0xD, 0x9, 0x27, 0x1E, 
	0x14, 0x18, 0x19, 0x18, 0x18, 0x1D, 0x1D, 0x17, 0x17, 
	0x17, 0x17, 0x18, 0x18, 0x1C, 0xD, 0x14, 0x18, 0x14, 
	0xD, 0xD, 0x1B, 0x17, 0x9, 0x14, 0xE, 0xD, 0x14, 
	0x18, 0x18, 0x18, 0x25, 0x2B, 0xD, 0x19, 0x18, 0x18, 
	0x17, 0x17, 0x1D, 0x1D, 0x18, 0x18, 0x17, 0x18, 0x18, 
	0xD, 0x11, 0xD, 0x14, 0xD, 0x14, 0x18, 0x17, 0x17, 
	0x17, 0x17, 0x2C, 0x19, 0xE, 0x1B, 0x18, 0x18, 0x2D, 
	0x1E, 0xD, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x1C, 0xD, 0x18, 0xE, 0x19, 0x18, 0x10, 0xD, 0x14, 
	0x14, 0x1D, 0x18, 0x17, 0x1D, 0x17, 0x17, 0x29, 0x1D, 
	0x19, 0xE, 0xE, 0x18, 0x0, 0x2E, 0x1C, 0xD, 0xC, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1B, 0x18, 0xE, 
	0x18, 0x18, 0x18, 0x18, 0x14, 0x17, 0x17, 0x18, 0x18, 
	0x14, 0xE, 0x14, 0x18, 0x1D, 0x18, 0x14, 0x18, 0x17, 
	0x27, 0x1E, 0x14, 0x18, 0xE, 0x18, 0x17, 0x23, 0x18, 
	0x18, 0x18, 0x14, 0x18, 0x18, 0x20, 0x18, 0x18, 0x14, 
	0x18, 0x17, 0x23, 0x14, 0x14, 0xD, 0x14, 0x1B, 0x1C, 
	0x14, 0x14, 0x18, 0x18, 0x17, 0x2F, 0x1E, 0x1C, 0x18, 
	0x18, 0x1B, 0x30, 0x17, 0x18, 0xD, 0xD, 0xD, 0xD, 
	0x18, 0x18, 0x18, 0x18, 0x14, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x1B, 0x14, 0x14, 0x18, 0x14, 0x18, 0x18, 
	0x18, 0x2F, 0x31, 0xD, 0x18, 0x14, 0x18, 0x18, 0x18, 
	0xE, 0xD, 0xD, 0x10, 0xD, 0xD, 0x14, 0x14, 0xD, 
	0xD, 0xE, 0x18, 0xD, 0x10, 0xC, 0xE, 0x18, 0xD, 
	0x14, 0x18, 0x14, 0xD, 0x14, 0x1B, 0x32, 0x31, 0xD, 
	0x18, 0xD, 0x18, 0x19, 0x19, 0xC, 0x19, 0x18, 0x19, 
	0xD, 0x14, 0x1B, 0x1B, 0x18, 0xD, 0x18, 0x14, 0x10, 
	0x11, 0xB, 0xD, 0xD, 0x19, 0xD, 0x1C, 0x1C, 0x1C, 
	0x18, 0x17, 0x27, 0x28, 0xF, 0x18, 0x18, 0x18, 0x18, 
	0x19, 0xD, 0x18, 0x20, 0x18, 0x1B, 0x18, 0x1B, 0x18, 
	0x14, 0x14, 0xD, 0x14, 0x14, 0xC, 0xD, 0x13, 0x11, 
	0x18, 0xD, 0x1C, 0x18, 0xD, 0x18, 0x17, 0x32, 0x2E, 
	0xD, 0x17, 0x30, 0x18, 0x18, 0x18, 0x18, 0xE, 0x17, 
	0x17, 0x24, 0x18, 0x18, 0x18, 0xD, 0x14, 0x18, 0x17, 
	0x18, 0xD, 0x18, 0x18, 0xD, 0xD, 0xD, 0xD, 0xD, 
	0x18, 0x18, 0x9, 0x25, 0x1E, 0x18, 0x17, 0x18, 0xE, 
	0x18, 0x9, 0x9, 0x14, 0x20, 0x17, 0x2C, 0x17, 0x1B, 
	0x14, 0x1C, 0x1C, 0x17, 0x18, 0x22, 0x1C, 0x18, 0x18, 
	0xD, 0x1F, 0xC, 0x13, 0xD, 0x1C, 0x18, 0x1B, 0x32, 
	0x12, 0xC, 0x18, 0x1B, 0x14, 0x18, 0x9, 0xD, 0xB, 
	0xC, 0xD, 0x18, 0x20, 0x18, 0x18, 0x14, 0x18, 0xD, 
	0xD, 0xD, 0xD, 0xD, 0xD, 0xD, 0xD, 0xB, 0xE, 
	0xE, 0xD, 0x18, 0x9, 0x32, 0x12, 0x10, 0x18, 0x18, 
	0x18, 0x18, 0x14, 0xB, 0xB, 0x10, 0xE, 0xD, 0x18, 
	0x18, 0x18, 0x19, 0x18, 0xD, 0x14, 0x19, 0x18, 0xD, 
	0xB, 0xD, 0xB, 0x1F, 0x10, 0xD, 0x10, 0xD, 0x18, 
	0x25, 0x1E, 0xD, 0x19, 0xD, 0xD, 0xD, 0x1A, 0x18, 
	0x19, 0x18, 0xD, 0xD, 0xD, 0x18, 0xD, 0xE, 0x19, 
	0xE, 0x18, 0x23, 0x2A, 0x18, 0xD, 0xD, 0xD, 0xD, 
	0x18, 0x18, 0xD, 0xD, 0x18, 0x32, 0x1E, 0xB, 0xB, 
	0xC, 0xD, 0xD, 0x18, 0x20, 0x1D, 0x1D, 0xD, 0xC, 
	0xE, 0x1F, 0xD, 0xD, 0x14, 0xD, 0xD, 0x23, 0x2C, 
	0x18, 0xB, 0x22, 0xD, 0x1C, 0x1B, 0x18, 0x14, 0x1F, 
	0x18, 0x32, 0x1E, 0xB, 0xB, 0xD, 0x1F, 0x18, 0x18, 
	0x18, 0x17, 0x17, 0x18, 0xC, 0xD, 0xD, 0x10, 0xD, 
	0xD, 0x14, 0xD, 0x18, 0x24, 0x17, 0xB, 0xE, 0x1C, 
	0xD, 0x19, 0x18, 0x19, 0xD, 0xD, 0x25, 0x1, 0xD, 
	0x18, 0x14, 0x14, 0x14, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x19, 0x19, 0xD, 0xD, 0xD, 0xD, 0xD, 0x18, 
	0x24, 0x14, 0xD, 0x18, 0x14, 0xB, 0x19, 0x1D, 0x18, 
	0x21, 0x19, 0x33, 0x1E, 0x10, 0xE, 0x14, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1C, 
	0xD, 0xD, 0xD, 0xD, 0x1C, 0x18, 0x18, 0xD, 0x18, 
	0x14, 0xB, 0x18, 0x18, 0x14, 0xD, 0x18, 0x25, 0x1E, 
	0xD, 0x18, 0x18, 0x18, 0x18, 0x17, 0x19, 0xD, 0x14, 
	0x1C, 0x18, 0x18, 0xE, 0xD, 0x1C, 0xE, 0x14, 0x23, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x17, 0x26, 
	0x18, 0xD, 0x1B, 0x32, 0x1, 0x10, 0x18, 0xD, 0x1A, 
	0x17, 0x24, 0x17, 0x18, 0xD, 0xD, 0x18, 0x1D, 0x18, 
	0x14, 0xE, 0x10, 0xE, 0x23, 0xE, 0xD, 0x1F, 0xD, 
	0x18, 0x23, 0x20, 0x23, 0x1D, 0x18, 0x18, 0x18, 0x27, 
	0x31, 0xB, 0x14, 0xD, 0x18, 0x17, 0x24, 0x23, 0xE, 
	0xC, 0xD, 0xE, 0x18, 0x1D, 0x18, 0x1D, 0xD, 0x1F, 
	0xE, 0x14, 0x10, 0x10, 0xE, 0x18, 0x30, 0x18, 0x18, 
	0x14, 0xD, 0x1D, 0x1D, 0x2F, 0xB, 0xC, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0xD, 0xD, 0xD, 0x10, 0xB, 0xC, 
	0x18, 0x18, 0x30, 0x20, 0xD, 0x18, 0x18, 0x18, 0x18, 
	0xD, 0x14, 0x30, 0x18, 0xE, 0x1B, 0xE, 0x18, 0x30, 
	0x2F, 0x18, 0xD, 0xE, 0xE, 0x18, 0x18, 0xD, 0xD, 
	0x18, 0x18, 0x19, 0x18, 0xB, 0x14, 0x14, 0x18, 0x18, 
	0xD, 0x14, 0xE, 0x18, 0x18, 0xD, 0xD, 0x14, 0x18, 
	0x18, 0x18, 0xD, 0xD, 0x30, 0x2F, 0x2D, 0x24, 0x17, 
	0x34, 0x34, 0x35, 0x24, 0x17, 0x17, 0x17, 0x18, 0x1D, 
	0x17, 0x17, 0x17, 0x17, 0x9, 0x34, 0x26, 0x17, 0x17, 
	0x17, 0x17, 0x17, 0x34, 0x30, 0x17, 0x17, 0x17, 0x17, 
	0x25, 0x2D, 0x33, 0x0, 0x25, 0x27, 0x2F, 0x2F, 0x2F, 
	0x27, 0x27, 0x27, 0x25, 0x27, 0x27, 0x27, 0x27, 0x27, 
	0x27, 0x27, 0x27, 0x36, 0x36, 0x2F, 0x27, 0x2F, 0x27, 
	0x27, 0x2F, 0x27, 0x27, 0x25, 0x24, 0x2D, 
};
const u8 canyon_button_xx_3_ci8_pal_rgba16[] = {
	0x4A, 0x53, 0x84, 0x23, 0x9D, 0x2B, 0x9C, 0xE9, 0x94, 
	0xE9, 0x9D, 0x29, 0x95, 0x27, 0x95, 0x29, 0x8C, 0xA5, 
	0x63, 0x19, 0x7B, 0xDF, 0x73, 0xDF, 0x6B, 0x9F, 0x6B, 
	0x9D, 0x6B, 0x5D, 0x6B, 0xDD, 0x73, 0x9F, 0x73, 0xE1, 
	0x7B, 0xE1, 0x6B, 0xDF, 0x6B, 0x5B, 0x52, 0x95, 0x8C, 
	0x63, 0x5B, 0x19, 0x63, 0x5B, 0x63, 0x5D, 0x63, 0x9B, 
	0x63, 0x59, 0x6B, 0x9B, 0x5B, 0x1B, 0x7C, 0x21, 0x73, 
	0x9D, 0x5B, 0x5B, 0x63, 0x9D, 0x73, 0xDD, 0x63, 0x1B, 
	0x52, 0xD7, 0x42, 0x53, 0x52, 0xD9, 0x42, 0x11, 0x74, 
	0x1F, 0x53, 0x19, 0x4A, 0xD7, 0x84, 0x21, 0x5A, 0xD9, 
	0x4A, 0x95, 0x7C, 0x1F, 0x3A, 0x11, 0x5B, 0x59, 0x7C, 
	0x23, 0x42, 0x51, 0x4A, 0x55, 0x5B, 0x17, 0x53, 0x17, 
	0x42, 0x13, 
};
const Gfx mat_canyon_button_Button[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, canyon_button_xx_3_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 54),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 32, canyon_button_xx_3_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(canyon_button_Button_lights),
	gsSPEndDisplayList(),
};

const Gfx mat_revert_canyon_button_Button[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};


const Vtx canyon_button_layer1button_mesh_vtx[] = {
	{{{-159, 0, 159},0, {0x3F0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-159, 42, 159},0, {0x3F0, 0x367},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-159, 42, -159},0, {0xFFF0, 0x367},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-159, 0, -159},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{159, 0, 159},0, {0x3F0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-159, 42, 159},0, {0xFFF0, 0x367},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-159, 0, 159},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{159, 42, 159},0, {0x3F0, 0x367},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{159, 42, -159},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-159, 42, -159},0, {0x3F0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-159, 42, 159},0, {0x3F0, 0xFFF0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{159, 42, 159},0, {0xFFF0, 0xFFF0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-159, 0, -159},0, {0x3F0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-159, 42, -159},0, {0x3F0, 0x367},{0x0, 0x0, 0x81, 0xFF}}},
	{{{159, 42, -159},0, {0xFFF0, 0x367},{0x0, 0x0, 0x81, 0xFF}}},
	{{{159, 0, -159},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{159, 0, -159},0, {0x3F0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{159, 42, 159},0, {0xFFF0, 0x367},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{159, 0, 159},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{159, 42, -159},0, {0x3F0, 0x367},{0x7F, 0x0, 0x0, 0xFF}}},
};

const Gfx canyon_button_layer1button_mesh_tri_0[] = {
	gsSPVertex(canyon_button_layer1button_mesh_vtx + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSPEndDisplayList(),
};

const Gfx canyon_button_layer1button_mesh[] = {
	gsSPDisplayList(mat_canyon_button_Button),
	gsSPDisplayList(canyon_button_layer1button_mesh_tri_0),
	gsSPDisplayList(mat_revert_canyon_button_Button),
	gsSPEndDisplayList(),
};



const Vtx canyon_button_layer2button_mesh_vtx[] = {
	{{{154, 0, 154},0, {0x36D, 0x36D},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-154, 0, 154},0, {0x73, 0x36D},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-213, 0, 213},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{213, 0, 213},0, {0x3F0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-154, 0, 154},0, {0x36D, 0x36D},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-154, 0, -154},0, {0x73, 0x36D},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-213, 0, -213},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-213, 0, 213},0, {0x3F0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-154, 0, -154},0, {0x36D, 0x36D},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{154, 0, -154},0, {0x73, 0x36D},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{213, 0, -213},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-213, 0, -213},0, {0x3F0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{154, 0, -154},0, {0x36D, 0x36D},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{154, 0, 154},0, {0x73, 0x36D},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{213, 0, 213},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{213, 0, -213},0, {0x3F0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
};

const Gfx canyon_button_layer2button_mesh_tri_0[] = {
	gsSPVertex(canyon_button_layer2button_mesh_vtx + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSPEndDisplayList(),
};

const Gfx canyon_button_layer2button_mesh[] = {
	gsSPDisplayList(mat_canyon_button_Button),
	gsSPDisplayList(canyon_button_layer2button_mesh_tri_0),
	gsSPDisplayList(mat_revert_canyon_button_Button),
	gsSPEndDisplayList(),
};



const Gfx canyon_button_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
