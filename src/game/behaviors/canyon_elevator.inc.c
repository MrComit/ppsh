/*void bhv_canyon_elevator_loop(void) {

    switch(o->oAction){
        case 0:
            o->oAction = 2;
            break;
        case 1:
            break;
        case 2:
            if (gMarioObject == o) {
                o->oAction = 3;
            }
            break;
        case 3:
            PlaySound(SOUND_ENV_ELEVATOR1);
            if (o->oPosY < o->oHomeY + 1000.0f)
                o->oPosY += 30.0f;
            else {
                o->oPosY = o->oHomeY + 1000.0f;
                o->oAction = 4;
            }
            break;
        case 4:
            break;
    }
}*/