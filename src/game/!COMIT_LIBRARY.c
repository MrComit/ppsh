#include <ultra64.h>
#include "sm64.h"
#include "level_update.h"
#include "camera.h"
#include "object_list_processor.h"
#define o gCurrentObject

//returns random number between min and max inclusive
u16 CL_RandomMinMaxU16(u16 min, u16 max) {
    u16 num = RandomU16();
    return (num % ((max + 1) - min)) + min;
}

void CL_kill_mario() {
    gMarioState->hurtCounter = 0xFF;
}

//
u8 CL_run_timer(u16 timer) {
    print_text_fmt_int(120, 210, "%d", timer / 30);
    timer--;
    if (!timer)
        return TRUE;
    return FALSE;
}


void CL_Move() {
    obj_compute_vel_xz();
    obj_move_using_vel_and_gravity();
}

struct Object *CL_Create_Star_Ptr(f32 sp20, f32 sp24, f32 sp28) {
    struct Object *sp1C;
    sp1C = func_802F1A50(sp1C, sp20, sp24, sp28);
    sp1C->oBehParams2ndByte = 0;
    return sp1C;
}

s16 CL_object_to_point(struct Object *o, Vec3f point) {
    f32 dx = point[0] - o->oPosX;
    f32 dz = point[2] - o->oPosZ;

    return atan2s(dz, dx);
}

extern struct ModeTransitionInfo sModeInfo;

void CL_set_camera_pos(Vec3f pos) {
    struct MarioState *marioStates = &gMarioStates[0];
    struct LinearTransitionPoint *start = &sModeInfo.transitionStart;
    struct LinearTransitionPoint *end = &sModeInfo.transitionEnd;

    vec3f_copy(gLakituState.curPos, pos);
    vec3f_copy(gLakituState.curFocus, pos);
    vec3f_copy(gLakituState.goalPos, pos);
    vec3f_copy(gLakituState.goalFocus, pos);
    vec3f_copy(start->focus, pos);
    vec3f_copy(start->pos, pos);
    vec3f_copy(end->focus, pos);
    vec3f_copy(end->pos, pos);
}


struct Object *CL_obj_nearest_object_behavior_params(const BehaviorScript *behavior, u32 params) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    f32 minDist = 0x20000;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr && obj->oBehParams == params) {
            if (obj->activeFlags != ACTIVE_FLAGS_DEACTIVATED && obj != o) {
                f32 objDist = dist_between_objects(o, obj);
                if (objDist < minDist) {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
        }
        obj = (struct Object *) obj->header.next;
    }

    return closestObj;
}