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


void bhv_star_by_wrench_loop(void) {
    switch(o->oAction) {
        case 0:
            break;
        case 1:
            if (o->oHiddenStarTriggerCounter >= 5) {
                create_star(o->oPosX, o->oPosY, o->oPosZ);
                o->oAction = 0;
            }
            break;
    }
}