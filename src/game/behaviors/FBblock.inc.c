void bhv_FBblock_init(void) {

    o->oMoveAngleYaw = 0x4000;
    if (((o->oBehParams >> 24) && 0xFF) == 0) {
        o->oForwardVel = 20.0f;
        o->oHomeX = -9000.0f;
        o->oYoshiUnkF4 = 9000.0f;
    } else {
        o->oForwardVel = -20.0f;
        o->oHomeX = 10159.0f;
        o->oYoshiUnkF4 = -10159.0f;
    }
}


void bhv_FBblock_loop(void) {
    obj_move_using_fvel_and_gravity();
    switch ((o->oBehParams >> 24) && 0xFF) {
        case 0:
            if (o->oPosX > o->oYoshiUnkF4) {
                o->oPosX = o->oHomeX;
            }
            break;
        default:
            if (o->oPosX < o->oYoshiUnkF4) {
                o->oPosX = o->oHomeX;
            }
            break;
    }
}