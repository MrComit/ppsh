Lights1 colored_cube_Red_001_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx colored_cube_colored_cube_mesh_vtx_cull[8] = {
	{{{-46, 0, -46},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-46, 0, 46},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-46, 92, 46},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-46, 92, -46},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{46, 0, -46},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{46, 0, 46},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{46, 92, 46},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{46, 92, -46},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
};

Vtx colored_cube_colored_cube_mesh_vtx_0[24] = {
	{{{-46, 0, 46},0, {368, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-46, 92, 46},0, {624, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-46, 92, -46},0, {624, 752},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-46, 0, -46},0, {368, 752},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-46, 0, -46},0, {368, 752},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-46, 92, -46},0, {624, 752},{0x0, 0x0, 0x81, 0xFF}}},
	{{{46, 92, -46},0, {624, 496},{0x0, 0x0, 0x81, 0xFF}}},
	{{{46, 0, -46},0, {368, 496},{0x0, 0x0, 0x81, 0xFF}}},
	{{{46, 0, -46},0, {368, 496},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{46, 92, -46},0, {624, 496},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{46, 92, 46},0, {624, 240},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{46, 0, 46},0, {368, 240},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{46, 0, 46},0, {368, 240},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{46, 92, 46},0, {624, 240},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-46, 92, 46},0, {624, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-46, 0, 46},0, {368, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-46, 0, -46},0, {112, 496},{0x0, 0x81, 0x0, 0xFF}}},
	{{{46, 0, -46},0, {368, 496},{0x0, 0x81, 0x0, 0xFF}}},
	{{{46, 0, 46},0, {368, 240},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-46, 0, 46},0, {112, 240},{0x0, 0x81, 0x0, 0xFF}}},
	{{{46, 92, -46},0, {624, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-46, 92, -46},0, {880, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-46, 92, 46},0, {880, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{46, 92, 46},0, {624, 240},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx colored_cube_colored_cube_mesh_tri_0[] = {
	gsSPVertex(colored_cube_colored_cube_mesh_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSPEndDisplayList(),
};



Gfx mat_colored_cube_Red_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 0, 46, 255),
	gsSPSetLights1(colored_cube_Red_001_lights),
	gsSPEndDisplayList(),
};

Gfx mat_colored_cube_Blue_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(55, 0, 255, 255),
	gsSPSetLights1(colored_cube_Red_001_lights),
	gsSPEndDisplayList(),
};

Gfx mat_colored_cube_Teal_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(0, 187, 255, 255),
	gsSPSetLights1(colored_cube_Red_001_lights),
	gsSPEndDisplayList(),
};

Gfx mat_colored_cube_Green_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(0, 255, 0, 255),
	gsSPSetLights1(colored_cube_Red_001_lights),
	gsSPEndDisplayList(),
};


Gfx red_colored_cube_colored_cube_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(colored_cube_colored_cube_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_colored_cube_Red_001),
	gsSPDisplayList(colored_cube_colored_cube_mesh_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

Gfx blue_colored_cube_colored_cube_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(colored_cube_colored_cube_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_colored_cube_Blue_001),
	gsSPDisplayList(colored_cube_colored_cube_mesh_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

Gfx teal_colored_cube_colored_cube_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(colored_cube_colored_cube_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_colored_cube_Teal_001),
	gsSPDisplayList(colored_cube_colored_cube_mesh_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

Gfx green_colored_cube_colored_cube_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(colored_cube_colored_cube_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_colored_cube_Green_001),
	gsSPDisplayList(colored_cube_colored_cube_mesh_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



Gfx colored_cube_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
