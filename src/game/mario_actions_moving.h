#ifndef _MARIO_ACTIONS_MOVING
#define _MARIO_ACTIONS_MOVING


struct MarioState;


void func_80263AD4(struct MarioState *m, s16 arg1, s16 arg2);
s32 mario_execute_moving_action(struct MarioState *m);
extern s32 grindInitTriggered;


#endif /* _MARIO_ACTIONS_MOVING */
