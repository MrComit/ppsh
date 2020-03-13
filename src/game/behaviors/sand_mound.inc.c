

void bhv_sand_mound_loop(void) {
    switch (o->oAction) {
        case 0:
            if (obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
            }
            break;
        case 1:

            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0, 0.2f);

            if (o->header.gfx.scale[1] == 0) {
                o->activeFlags = 0;
                func_802AA618(0, 0, 46.0f);
            }
            break;
    }
}