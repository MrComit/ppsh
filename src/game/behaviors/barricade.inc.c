void bhv_barricade_loop(void){
struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            if (m->action == ACT_DASH_ATTACK || m->action == ACT_DASH_ATTACK_END) {
            //if (m->action == ACT_BACKWARD_WATER_KB) {
                if (m->wall != NULL) {
                    if (m->wall->object != NULL) {
                        if (m->wall->object == o) {
                            o->oAction = 1;
                            set_mario_action(m, ACT_BACKWARD_WATER_KB, 0);
                            m->forwardVel = -10.0f;
                            ShakeScreen(SHAKE_POS_MEDIUM);
                            //play_puzzle_jingle();
                        }
                    }
                }
            }
            load_object_collision_model();
            break;
        case 1:
            //PlaySound(SOUND_GENERAL_SWISH_WATER);
            PlaySound2(SOUND_GENERAL_UNKNOWN4);
            o->oFaceAngleRoll = approach_s16_symmetric((s16)o->oFaceAngleRoll, 0xC000, 0x200);
            o->oPosY += 2.0f;
            if (o->oTimer > 32) {
                o->oAction = 2;
                play_puzzle_jingle();
                //m->wall = NULL;
            }
            load_object_collision_model();
            break;
        case 2:
            break;
    }
}