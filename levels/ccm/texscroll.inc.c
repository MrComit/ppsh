void scroll_ccm_dl_Arena_mesh_vtx_0() {
	int i = 0;
	int count = 44;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_Arena_mesh_vtx_0);

	deltaX = (int)(1.2000000476837158 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;

}
void scroll_ccm_dl_Decal_mesh_vtx_0() {
	int i = 0;
	int count = 48;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_Decal_mesh_vtx_0);

	deltaX = (int)(0.4300000071525574 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;

}
void scroll_ccm_dl_Ground_mesh_vtx_2() {
	int i = 0;
	int count = 48;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_Ground_mesh_vtx_2);

	deltaY = (int)(0.7599999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_ccm() {
	scroll_ccm_dl_Arena_mesh_vtx_0();
	scroll_ccm_dl_Decal_mesh_vtx_0();
	scroll_ccm_dl_Ground_mesh_vtx_2();

}
