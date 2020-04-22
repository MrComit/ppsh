void bhv_canyon_elevator_loop(void) {
    o->oPosY += o->oVelY;
    switch(o->oAction){
        case 0:
            o->oAction = 2;
            break;
        case 1:
            break;
        case 2:
            o->oPosY = o->oHomeY;
            if (gMarioObject->platform == o || absi(o->oHomeY - gMarioObject->oPosY) > absi((o->oHomeY + 1852.0f) - gMarioObject->oPosY)) {
                o->oAction = 3;
                o->oVelY = 20.0f;
            }
            break;
        case 3:
            PlaySound(SOUND_ENV_ELEVATOR1);
            if (o->oPosY > o->oHomeY + 1852.0f) {
                o->oPosY = o->oHomeY + 1852.0f;
                o->oAction = 4;
                o->oVelY = 0;
                ShakeScreen(SHAKE_POS_SMALL);
                PlaySound2(SOUND_GENERAL_METAL_POUND);
            }
            break;
        case 4:
            if (gMarioObject->platform != o)
                o->oAction = 5;
            break;
        case 5:
            o->oPosY = o->oHomeY + 1852.0f;
            if (gMarioObject->platform == o || absi(o->oHomeY - gMarioObject->oPosY) < absi((o->oHomeY + 1852.0f) - gMarioObject->oPosY)) {
                o->oAction = 6;
                o->oVelY = -20.0f;
            }
            break;
        case 6:
            PlaySound(SOUND_ENV_ELEVATOR1);
            if (o->oPosY < o->oHomeY) {
                o->oPosY = o->oHomeY;
                o->oAction = 7;
                o->oVelY = 0;
                ShakeScreen(SHAKE_POS_SMALL);
                PlaySound2(SOUND_GENERAL_METAL_POUND);
            }
            break;
        case 7:
            if (gMarioObject->platform != o)
                o->oAction = 2;
            break;
    }
}