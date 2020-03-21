//bhv_bobomb_buddy_loop

s8 gKoopaSaved = 0;


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
        case 2:
            koopa_the_wimp_loop();
            break;
    }

}


void koopa_the_wimp_loop(void) {
s32 numPorcupuffers;

    switch (o->oKoopaAction) {
        case 0:
            o->oInteractType = 0x40000000;
            if (gKoopaSaved == 1) {
                o->oKoopaAction = 3;
                break;
            }
            set_obj_animation_and_sound_state(3);
            o->oPosX = o->oHomeX + sins(o->oKoopaRunAngleX) * 200.0f;
            o->oPosZ = o->oHomeZ + coss(o->oKoopaRunAngleX) * 400.0f;
            o->oMoveAngleYaw = o->oKoopaRunAngleX + 0x4000;
            o->oKoopaRunAngleX += 0x300;
            numPorcupuffers = count_objects_with_behavior(bhvPorcupuffer);
            if (numPorcupuffers == 0) {
                gKoopaSaved = 1;
                o->oKoopaAction = 1;
                play_puzzle_jingle();
            }
            break;
        case 1:
            o->oInteractType = 0x00800000;
            set_obj_animation_and_sound_state(7);
            bhv_bobomb_buddy_loop();
            if (o->oAction == 2) {
                o->oKoopaAction = 2;
            }

            break;
        case 2:
            if (o->oAction == 0) {
                o->oBehParams &= 0x00FFFFFFFF;
                o->oBehParams |= 0x06 << 24;
                create_star(-775.0f, -2091.0f, -8958.0f);
                o->oBehParams &= 0x00FFFFFFFF;
                o->oBehParams |= 0x02 << 24;
                o->oInteractType = 0x40000000;
                o->oKoopaAction = 3;
            }
            bhv_bobomb_buddy_loop();
            break;
        case 3:
            break;
    }
}