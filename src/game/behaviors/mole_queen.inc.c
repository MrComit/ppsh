#define QUEEN_DEATH 2

static struct ObjectHitbox sMoleQueenHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 0,
    /* radius:            */ 30,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 80,
    /* hurtboxHeight:     */ 40,
};

static struct ObjectHitbox sWrenchQueenHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 60,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 60,
    /* hurtboxHeight:     */ 100,
};


//static Vec3f phasePos[3] = {{0.0f, 0.0f, 0.0f}, {-16524.0f, 5894.0f, 8000.0f/*9540.0f*/}, {-159.0f, 171.0f, 10.0f}};

static f32 fSpeeds[3] = {0.0f, 90.0f, 100.0f};
static f32 ySpeeds[3] = {20.0f, 140.0f, 80.0f};

static s16 angles[3] = {0x0000, 0xC000, 0x7000};

static f32 respawnPos[3][3] = {{-16524.0f, 5894.0f, 8000.0f}, {-7754.0f, 4652.0f, 2968.0f}, {-4225.0f, 3929.0f, 11470.0f}};


static s32 cringe_anim_thing(s32 arg0, s32 arg1) {
    set_obj_animation_and_sound_state(arg0);
    return obj_check_anim_frame(arg1);
}

void damage_queen(struct MarioState *m) {
    s16 health = --o->oHealth;
    m->pos[0] = o->oPosX;
    m->pos[1] = o->oPosY + o->hitboxHeight;
    m->pos[2] = o->oPosZ;
    m->faceAngle[1] = (m->angleVel[1] = angles[health]);
    m->vel[1] = ySpeeds[health];
    mario_set_forward_vel(m, fSpeeds[health]);
    set_mario_action(m, ACT_CUTSCENE_JUMP, 0);
    PlaySound2(SOUND_OBJ_DYING_ENEMY1);
}

void queen_attack_handler(void) {
struct Object *wrench;
    switch (o->oSubAction) {
        case 0:
            o->oBobombBlinkTimer = CL_RandomMinMaxU16(30, 100);
            o->oSubAction = 1;
            break;
        case 1:
            if (o->oTimer > o->oBobombBlinkTimer) {
                o->oSubAction = 2;
            }
            break;
        case 2:
            if (cringe_anim_thing(8, 10)) {
                PlaySound2(SOUND_OBJ_MONTY_MOLE_ATTACK);
                o->oSubAction = 3;
                wrench = spawn_object(o, MODEL_WRENCH, bhvThrowingWrench);
                wrench->oPosY += 900.0f;
                wrench->oFaceAngleRoll = 0x4000;
                wrench->oForwardVel = (lateral_dist_between_objects(gMarioState->marioObj, wrench))/ 40.0f;
                wrench->oVelY = 150.0f;
                wrench->oGravity = -7.5f;

            }
            break;
        case 3:
            set_obj_animation_and_sound_state(3);
            o->oTimer = 0;
            o->oSubAction = 0;
            break;
    }
}


void bhv_queen_mole_init(void) {
    set_object_hitbox(o, &sMoleQueenHitbox);
}

void bhv_queen_mole_loop(void) {
struct MarioState *m = gMarioState;
s16 angle;
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 7500.0f && m->pos[1] > 3800.0f) {
                o->oAction = 1;
                o->oHealth = 3;
                //play_sequence(0, SEQ_EVENT_BOSS, 40);
            }
            break;
        case 1:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x100);
            if (o->oDistanceToMario > 2600.0f)
                queen_attack_handler();
            else
                set_obj_animation_and_sound_state(3);
            if (o->oDistanceToMario > 10000.0f)
                o->oAction = 0;
            if (o->oInteractStatus & INT_STATUS_INTERACTED && !(o->oInteractStatus & INT_STATUS_ATTACKED_MARIO))
                damage_queen(m);
            if (o->oHealth == 0)
                o->oAction = QUEEN_DEATH;
            if (m->pos[1] < 2300.0f) {
                if (m->health <= 0x280) {
                    level_trigger_warp(m, WARP_OP_WARP_FLOOR);
                    o->oAction = 0;
                } else {
                    o->oAction = 3;
                }
            }
            if (lateral_dist_between_objects(m->marioObj, o) < 1800.0f && m->pos[1] - o->oPosY < 1200.0f) {
                take_damage_and_knock_back(m, o);
            }
            break;
        case QUEEN_DEATH:
            create_star(o->oPosX, o->oPosY + 300.0f, o->oPosZ);
            o->activeFlags = 0;
            break;
        case 3:
            switch (o->oTimer) {
                case 0:
                    play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, 0xC, 0x00, 0x00, 0x00);
                    break;
                case 9:
                    vec3f_copy(m->pos, respawnPos[o->oHealth - 1]);
                    CL_set_camera_pos(respawnPos[o->oHealth - 1]);
                    angle = (m->faceAngle[1] = mario_angle_to_object(m, o));
                    s8DirModeYawOffset = (s16)(angle & 0xC000) - 0x4000;
                    set_mario_action(m, ACT_JUMP_LAND_STOP, 0);
                    break;
                case 12:
                    play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 5, 0x00, 0x00, 0x00);
                    m->hurtCounter = 8;
                    o->oAction = 1;
                    break;
            }
            break;
    }
    o->oInteractStatus = 0;
}

void bhv_queen_wrench_init(void) {
    set_object_hitbox(o, &sWrenchQueenHitbox);
}

void bhv_queen_wrench_loop(void) {
    s16 moveRate;
    if (o->oBehParams2ndByte == 30)
        moveRate = 0x4000;
    else
        moveRate = 0x300;
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, moveRate);
    CL_Move();
    o->oFaceAnglePitch += 0x2000;
    if (o->oInteractStatus || o->oTimer > 120)
        o->activeFlags = 0;
}

s32 obj_should_throw_wrench(struct MarioState *m) {
    if (m->pos[1] < 1600.0f && (-14630.0f < m->pos[0] && m->pos[0] < -9876.0f) && (-2569.0f < m->pos[2] && m->pos[2] < 3000.0f))
        return TRUE;
    return FALSE;
}


void bhv_wrench_thrower_loop(void) {
struct Object *wrench;
struct MarioState *m = gMarioState;
struct Object *queen = obj_nearest_object_with_behavior(bhvQueenMole);
    if (queen == NULL)
        o->activeFlags = 0;

    if (obj_should_throw_wrench(m)) {
        switch (o->oAction) {
            case 0:
                o->oBobombBlinkTimer = CL_RandomMinMaxU16(30, 100);
                o->oAction = 1;
                break;
            case 1:
                if (o->oTimer > o->oBobombBlinkTimer) {
                    o->oAction = 2;
                }
                break;
            case 2:
                    PlaySound2(SOUND_OBJ_MONTY_MOLE_ATTACK);
                    wrench = spawn_object(o, MODEL_WRENCH, bhvThrowingWrench);
                    wrench->oPosX = m->pos[0];
                    wrench->oPosY = m->pos[1] + 900.0f;
                    wrench->oPosZ = m->pos[2];
                    wrench->oFaceAngleRoll = 0x4000;
                    wrench->oForwardVel = 15.0f;
                    wrench->oGravity = -5.0f;
                    wrench->oBehParams2ndByte = 30;
                    wrench->oMoveAngleYaw = wrench->oAngleToMario;
                    o->oAction = 0;
                break;
        }
    }
}