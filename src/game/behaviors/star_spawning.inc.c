void bhv_star_by_switch_loop(void) {
struct Object *pswitch;

    pswitch = obj_nearest_object_with_behavior(bhvFloorSwitchGrills);
    if (pswitch == NULL){
        o->activeFlags = 0;
    }

    if (pswitch->oAction == 2) {
        create_star(o->oPosX, o->oPosY, o->oPosZ);
        o->activeFlags = 0;
    }


}