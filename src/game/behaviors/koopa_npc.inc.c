//bhv_bobomb_buddy_loop




void bhv_koopa_npc_loop(void) {
s8 koopaType = o->oBehParams >> 24 & 0xFF;

    switch(koopaType) {
        case 0:
            bhv_bobomb_buddy_loop();
            break;
        case 1:
            break;
        break;
    }

}