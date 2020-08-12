Vtx spotlight_Spotlight_mesh_vtx_cull[8] = {
	{{{-736, 9, -637},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-736, 9, 637},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-736, 5980, 637},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-736, 5980, -637},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{2533, 9, -637},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{2533, 9, 637},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{2533, 5980, 637},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{2533, 5980, -637},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
};

Vtx spotlight_Spotlight_mesh_vtx_0[24] = {
	{{{368, 9, -637},0, {-16, 1008},{0x0, 0xE, 0x82, 0xFF}}},
	{{{-368, 9, -637},0, {-16, 1008},{0x0, 0xE, 0x82, 0xFF}}},
	{{{2533, 5980, 0},0, {-16, 1008},{0x0, 0xE, 0x82, 0xFF}}},
	{{{368, 9, 637},0, {-16, 1008},{0x6A, 0xE0, 0x3E, 0xFF}}},
	{{{736, 9, 0},0, {-16, 1008},{0x6A, 0xE0, 0x3E, 0xFF}}},
	{{{2533, 5980, 0},0, {-16, 1008},{0x6A, 0xE0, 0x3E, 0xFF}}},
	{{{-736, 9, 0},0, {-16, 1008},{0x9D, 0x37, 0x3A, 0xFF}}},
	{{{-368, 9, 637},0, {-16, 1008},{0x9D, 0x37, 0x3A, 0xFF}}},
	{{{2533, 5980, 0},0, {-16, 1008},{0x9D, 0x37, 0x3A, 0xFF}}},
	{{{-368, 9, -637},0, {-16, 1008},{0x9D, 0x37, 0xC6, 0xFF}}},
	{{{-736, 9, 0},0, {-16, 1008},{0x9D, 0x37, 0xC6, 0xFF}}},
	{{{2533, 5980, 0},0, {-16, 1008},{0x9D, 0x37, 0xC6, 0xFF}}},
	{{{736, 9, 0},0, {-16, 1008},{0x6A, 0xE0, 0xC2, 0xFF}}},
	{{{368, 9, -637},0, {-16, 1008},{0x6A, 0xE0, 0xC2, 0xFF}}},
	{{{2533, 5980, 0},0, {-16, 1008},{0x6A, 0xE0, 0xC2, 0xFF}}},
	{{{-368, 9, 637},0, {-16, 1008},{0x0, 0xE, 0x7E, 0xFF}}},
	{{{368, 9, 637},0, {-16, 1008},{0x0, 0xE, 0x7E, 0xFF}}},
	{{{2533, 5980, 0},0, {-16, 1008},{0x0, 0xE, 0x7E, 0xFF}}},
	{{{-736, 9, 0},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-368, 9, 637},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{368, 9, 637},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{368, 9, -637},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{736, 9, 0},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-368, 9, -637},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx spotlight_Spotlight_mesh_tri_0[] = {
	gsSPVertex(spotlight_Spotlight_mesh_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 20, 21, 18, 0),
	gsSP2Triangles(20, 22, 21, 0, 21, 23, 18, 0),
	gsSPEndDisplayList(),
};


Gfx mat_spotlight_GlassDisplay_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, 1, 0, 0, 0, ENVIRONMENT, 0, 0, 0, 1, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(187, 187, 187, 63),
	gsSPEndDisplayList(),
};


Gfx spotlight_Spotlight_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(spotlight_Spotlight_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_spotlight_GlassDisplay_001),
	gsSPDisplayList(spotlight_Spotlight_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx spotlight_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
