void BoulderExplodeLoop(void) {
    struct Object *explosion;
    if (o->oTimer < 5)
        obj_scale(1.0f + (f32) o->oTimer / 50.0f);
    else {
        explosion = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
        explosion->oGraphYOffset += 100.0f;
        o->activeFlags = 0;
    }
}


void bhv_bomb_boulder_loop(void) {
    struct Object *bombswitch;
    load_object_collision_model();

    if (o->oBehParams == 0xFF000000) {
        bombswitch = CL_obj_nearest_object_behavior_params(bhvBombSwitch, 0x20000000);
        if (bombswitch == NULL || bombswitch->oAction == 2)
            o->oAction = 1;
    }

    switch (o->oAction) {
        case 0:
            break;
        case 1:
            BoulderExplodeLoop();
            break;
    }
}


void bhv_bomb_switch_loop(void) {
struct Object *boulder;

    load_object_collision_model();
    switch (o->oAction) {
        case 0:
            if (obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
                o->oVelY = -20.0f;
            }
            break;
        case 1:
            if (o->oTimer > 5)
                o->oAction = 2;
            else
                obj_move_using_fvel_and_gravity();
            break;
        case 2:
            o->oPosY = gMarioObject->oPosY - 40.0f;
            o->activeFlags = 0;
            func_802A3004();
            boulder = CL_obj_nearest_object_behavior_params(bhvBombBoulder, o->oBehParams);
            if (boulder != NULL)
                boulder->oAction = 1;
            break;

    }
}