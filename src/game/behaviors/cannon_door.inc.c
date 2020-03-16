// cannon.c.inc

void bhv_cannon_closed_init(void) {
    //struct Object *cannon;

    /*if (save_file_is_cannon_unlocked() == 1) {
        // If the cannon is open, spawn a cannon and despawn the object.
        cannon = spawn_object(o, MODEL_CANNON_BASE, bhvCannon);
        cannon->oBehParams2ndByte = o->oBehParams2ndByte;
        cannon->oPosX = o->oHomeX;
        cannon->oPosY = o->oHomeY;
        cannon->oPosZ = o->oHomeZ;

        o->oAction = CANNON_TRAP_DOOR_ACT_OPEN;
        o->activeFlags = 0;
    }*/
}

void CannonTrapDoorOpeningLoop(void) {
    if (o->oTimer == 0)
        PlaySound2(SOUND_GENERAL_CANNON_UP);

    if (o->oTimer < 30) {
        o->oVelY = -0.5f;
        o->oPosY += o->oVelY;
        o->oVelX = 0;
    } else {
        if (o->oTimer == 100) {
            o->activeFlags = 0;
            set_mario_npc_dialog(0);
            return;
        }

        o->oVelX = 4.0f;
        o->oVelY = 0;
        o->oPosX += o->oVelX;
    }
}

void bhv_cannon_closed_loop(void) {
struct Object *pswitch;

    switch (o->oAction) {
        case CANNON_TRAP_DOOR_ACT_CLOSED:
            o->oVelX = 0;
            o->oVelY = 0;
            o->oDrawingDistance = 4000.0f;

            pswitch = obj_nearest_object_with_behavior(bhvFloorSwitchCannon);
            if (pswitch == NULL) {
                o->activeFlags = 0;
                break;
            }
            if (pswitch->oAction == 2) {
                o->oAction = CANNON_TRAP_DOOR_ACT_CAM_ZOOM;
                //set_mario_npc_dialog(1);
            }
            break;

        case CANNON_TRAP_DOOR_ACT_CAM_ZOOM:
            cutscene_object(0x96, o);
            CannonTrapDoorOpeningLoop();
            o->oDrawingDistance = 28672.0f;
            set_mario_npc_dialog(1);
            break;
    }
}
