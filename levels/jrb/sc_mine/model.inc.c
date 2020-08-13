Lights1 sc_mine_Mine_001_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 sc_mine_Mine2_001_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx sc_mine_Mine_mesh_vtx_cull[8] = {
	{{{-165, -158, -132},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-165, -158, 196},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-165, 173, 196},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-165, 173, -132},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{204, -158, -132},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{204, -158, 196},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{204, 173, 196},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{204, 173, -132},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
};

Vtx sc_mine_Mine_mesh_vtx_0[22] = {
	{{{2, -136, 0},0, {822, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{102, -60, 72},0, {729, 847},{0x5C, 0xC7, 0x42, 0xFF}}},
	{{{-36, -60, 116},0, {915, 847},{0xDD, 0xC7, 0x6C, 0xFF}}},
	{{{40, 63, 116},0, {822, 686},{0x23, 0x39, 0x6C, 0xFF}}},
	{{{125, 63, 0},0, {636, 686},{0x72, 0x39, 0x0, 0xFF}}},
	{{{102, -60, -72},0, {543, 847},{0x5C, 0xC7, 0xBE, 0xFF}}},
	{{{2, -136, 0},0, {636, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{40, 63, -117},0, {449, 686},{0x23, 0x39, 0x94, 0xFF}}},
	{{{-36, -60, -117},0, {356, 847},{0xDD, 0xC7, 0x94, 0xFF}}},
	{{{2, -136, 0},0, {449, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-97, 63, -72},0, {263, 686},{0xA4, 0x39, 0xBE, 0xFF}}},
	{{{-120, -60, 0},0, {170, 847},{0x8E, 0xC7, 0x0, 0xFF}}},
	{{{2, -136, 0},0, {263, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-97, 63, 72},0, {77, 686},{0xA4, 0x39, 0x42, 0xFF}}},
	{{{-36, -60, 116},0, {-16, 847},{0xDD, 0xC7, 0x6C, 0xFF}}},
	{{{2, -136, 0},0, {77, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{2, 139, 0},0, {170, 524},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{2, 139, 0},0, {729, 524},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{2, 139, 0},0, {356, 524},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{2, 139, 0},0, {543, 524},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-97, 63, 72},0, {1008, 686},{0xA4, 0x39, 0x42, 0xFF}}},
	{{{2, 139, 0},0, {915, 524},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx sc_mine_Mine_mesh_tri_0[] = {
	gsSPVertex(sc_mine_Mine_mesh_vtx_0 + 0, 22, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(1, 4, 3, 0, 1, 5, 4, 0),
	gsSP2Triangles(1, 6, 5, 0, 5, 7, 4, 0),
	gsSP2Triangles(5, 8, 7, 0, 9, 8, 5, 0),
	gsSP2Triangles(8, 10, 7, 0, 8, 11, 10, 0),
	gsSP2Triangles(12, 11, 8, 0, 11, 13, 10, 0),
	gsSP2Triangles(11, 14, 13, 0, 15, 14, 11, 0),
	gsSP2Triangles(10, 13, 16, 0, 3, 4, 17, 0),
	gsSP2Triangles(7, 10, 18, 0, 4, 7, 19, 0),
	gsSP2Triangles(2, 3, 20, 0, 20, 3, 21, 0),
	gsSPEndDisplayList(),
};Vtx sc_mine_Mine_mesh_vtx_1[63] = {
	{{{7, 68, -84},0, {368, 496},{0x79, 0x21, 0xEC, 0xFF}}},
	{{{-26, 173, -112},0, {624, 240},{0x79, 0x21, 0xEC, 0xFF}}},
	{{{6, 110, -21},0, {368, 240},{0x79, 0x21, 0xEC, 0xFF}}},
	{{{6, 110, -21},0, {368, 1008},{0xB2, 0x43, 0x4A, 0xFF}}},
	{{{-26, 173, -112},0, {624, 752},{0xB2, 0x43, 0x4A, 0xFF}}},
	{{{-53, 78, -55},0, {368, 752},{0xB2, 0x43, 0x4A, 0xFF}}},
	{{{-53, 78, -55},0, {368, 752},{0xC7, 0xD2, 0x98, 0xFF}}},
	{{{-26, 173, -112},0, {624, 496},{0xC7, 0xD2, 0x98, 0xFF}}},
	{{{7, 68, -84},0, {368, 496},{0xC7, 0xD2, 0x98, 0xFF}}},
	{{{39, 73, 76},0, {368, 496},{0xA3, 0x32, 0x46, 0xFF}}},
	{{{92, 173, 74},0, {624, 240},{0xA3, 0x32, 0x46, 0xFF}}},
	{{{14, 111, 16},0, {368, 240},{0xA3, 0x32, 0x46, 0xFF}}},
	{{{14, 111, 16},0, {368, 1008},{0x28, 0x34, 0x93, 0xFF}}},
	{{{92, 173, 74},0, {624, 752},{0x28, 0x34, 0x93, 0xFF}}},
	{{{80, 73, 22},0, {368, 752},{0x28, 0x34, 0x93, 0xFF}}},
	{{{80, 73, 22},0, {368, 752},{0x5F, 0xD0, 0x45, 0xFF}}},
	{{{92, 173, 74},0, {624, 496},{0x5F, 0xD0, 0x45, 0xFF}}},
	{{{39, 73, 76},0, {368, 496},{0x5F, 0xD0, 0x45, 0xFF}}},
	{{{7, 42, 106},0, {368, 496},{0x63, 0xCF, 0x3E, 0xFF}}},
	{{{-59, 25, 196},0, {624, 240},{0x63, 0xCF, 0x3E, 0xFF}}},
	{{{-24, -27, 100},0, {368, 240},{0x63, 0xCF, 0x3E, 0xFF}}},
	{{{-24, -27, 100},0, {368, 1008},{0x90, 0xC5, 0xF7, 0xFF}}},
	{{{-59, 25, 196},0, {624, 752},{0x90, 0xC5, 0xF7, 0xFF}}},
	{{{-57, 39, 84},0, {368, 752},{0x90, 0xC5, 0xF7, 0xFF}}},
	{{{-57, 39, 84},0, {368, 752},{0xF5, 0x7E, 0xF, 0xFF}}},
	{{{-59, 25, 196},0, {624, 496},{0xF5, 0x7E, 0xF, 0xFF}}},
	{{{7, 42, 106},0, {368, 496},{0xF5, 0x7E, 0xF, 0xFF}}},
	{{{-58, -43, -75},0, {368, 496},{0x2A, 0x18, 0x8A, 0xFF}}},
	{{{-165, -35, -111},0, {624, 240},{0x2A, 0x18, 0x8A, 0xFF}}},
	{{{-80, 29, -68},0, {368, 240},{0x2A, 0x18, 0x8A, 0xFF}}},
	{{{-80, 29, -68},0, {368, 1008},{0xAB, 0x49, 0x3B, 0xFF}}},
	{{{-165, -35, -111},0, {624, 752},{0xAB, 0x49, 0x3B, 0xFF}}},
	{{{-96, -28, -21},0, {368, 752},{0xAB, 0x49, 0x3B, 0xFF}}},
	{{{-96, -28, -21},0, {368, 752},{0xEF, 0x84, 0x17, 0xFF}}},
	{{{-165, -35, -111},0, {624, 496},{0xEF, 0x84, 0x17, 0xFF}}},
	{{{-58, -43, -75},0, {368, 496},{0xEF, 0x84, 0x17, 0xFF}}},
	{{{100, -43, 28},0, {368, 496},{0x2D, 0x2A, 0x6F, 0xFF}}},
	{{{204, -40, -15},0, {624, 240},{0x2D, 0x2A, 0x6F, 0xFF}}},
	{{{110, 25, -2},0, {368, 240},{0x2D, 0x2A, 0x6F, 0xFF}}},
	{{{110, 25, -2},0, {368, 1008},{0x19, 0x3A, 0x92, 0xFF}}},
	{{{204, -40, -15},0, {624, 752},{0x19, 0x3A, 0x92, 0xFF}}},
	{{{94, -39, -39},0, {368, 752},{0x19, 0x3A, 0x92, 0xFF}}},
	{{{94, -39, -39},0, {368, 752},{0x1, 0x81, 0xF7, 0xFF}}},
	{{{204, -40, -15},0, {624, 496},{0x1, 0x81, 0xF7, 0xFF}}},
	{{{100, -43, 28},0, {368, 496},{0x1, 0x81, 0xF7, 0xFF}}},
	{{{5, -102, -40},0, {368, 496},{0x52, 0xC1, 0x49, 0xFF}}},
	{{{51, -149, -132},0, {624, 240},{0x52, 0xC1, 0x49, 0xFF}}},
	{{{61, -57, -64},0, {368, 240},{0x52, 0xC1, 0x49, 0xFF}}},
	{{{61, -57, -64},0, {368, 1008},{0x25, 0x46, 0x9D, 0xFF}}},
	{{{51, -149, -132},0, {624, 752},{0x25, 0x46, 0x9D, 0xFF}}},
	{{{-9, -62, -93},0, {368, 752},{0x25, 0x46, 0x9D, 0xFF}}},
	{{{-9, -62, -93},0, {368, 752},{0x95, 0xBF, 0xEA, 0xFF}}},
	{{{51, -149, -132},0, {624, 496},{0x95, 0xBF, 0xEA, 0xFF}}},
	{{{5, -102, -40},0, {368, 496},{0x95, 0xBF, 0xEA, 0xFF}}},
	{{{-27, -111, 34},0, {368, 496},{0xE1, 0xC1, 0x96, 0xFF}}},
	{{{-115, -158, 87},0, {624, 240},{0xE1, 0xC1, 0x96, 0xFF}}},
	{{{-87, -66, 24},0, {368, 240},{0xE1, 0xC1, 0x96, 0xFF}}},
	{{{-87, -66, 24},0, {368, 1008},{0xAD, 0x46, 0x41, 0xFF}}},
	{{{-115, -158, 87},0, {624, 752},{0xAD, 0x46, 0x41, 0xFF}}},
	{{{-43, -71, 86},0, {368, 752},{0xAD, 0x46, 0x41, 0xFF}}},
	{{{-43, -71, 86},0, {368, 752},{0x4F, 0xC0, 0x4B, 0xFF}}},
	{{{-115, -158, 87},0, {624, 496},{0x4F, 0xC0, 0x4B, 0xFF}}},
	{{{-27, -111, 34},0, {368, 496},{0x4F, 0xC0, 0x4B, 0xFF}}},
};

Gfx sc_mine_Mine_mesh_tri_1[] = {
	gsSPVertex(sc_mine_Mine_mesh_vtx_1 + 0, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
	gsSPVertex(sc_mine_Mine_mesh_vtx_1 + 30, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
	gsSPVertex(sc_mine_Mine_mesh_vtx_1 + 60, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};


Gfx mat_sc_mine_Mine_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, 1, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, 1),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(21, 21, 28, 255),
	gsSPSetLights1(sc_mine_Mine_001_lights),
	gsSPEndDisplayList(),
};


Gfx mat_sc_mine_Mine2_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, 1, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, 1),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(187, 187, 187, 255),
	gsSPSetLights1(sc_mine_Mine2_001_lights),
	gsSPEndDisplayList(),
};


Gfx sc_mine_Mine_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(sc_mine_Mine_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_sc_mine_Mine_001),
	gsSPDisplayList(sc_mine_Mine_mesh_tri_0),
	gsSPDisplayList(mat_sc_mine_Mine2_001),
	gsSPDisplayList(sc_mine_Mine_mesh_tri_1),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



Gfx sc_mine_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};