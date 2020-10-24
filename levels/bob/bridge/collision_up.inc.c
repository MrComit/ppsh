const Collision bridge_up_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(474, 17, 39),
	COL_VERTEX(-496, 1874, 12196),
	COL_VERTEX(-496, 1844, 12192),
	COL_VERTEX(475, -13, 36),
	COL_VERTEX(-474, -17, -39),
	COL_VERTEX(-1445, 1840, 12117),
	COL_VERTEX(-1445, 1870, 12120),
	COL_VERTEX(-475, 13, -36),
	COL_TRI_INIT(SURFACE_DEFAULT, 12),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(7, 6, 1),
	COL_TRI(7, 1, 0),
	COL_TRI(3, 4, 7),
	COL_TRI(3, 7, 0),
	COL_TRI(5, 2, 1),
	COL_TRI(5, 1, 6),
	COL_TRI(3, 2, 5),
	COL_TRI(3, 5, 4),
	COL_TRI_STOP(),
	COL_END()
};
