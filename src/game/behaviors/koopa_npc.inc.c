//bhv_bobomb_buddy_loop




void bhv_koopa_npc_loop(void) {
struct Object *pswitch;
s8 koopaType = o->oBehParams >> 24 & 0xFF;

    switch(koopaType) {
        case 0:
            bhv_bobomb_buddy_loop();
            break;
        case 1:
            pswitch = obj_nearest_object_with_behavior(bhvFloorSwitchGrills);
            if (pswitch == NULL){
                o->activeFlags = 0;
            } else if (pswitch->oAction == 2) {
                o->oBehParams2ndByte = 2;
            }
            bhv_bobomb_buddy_loop();
            break;
    }

}