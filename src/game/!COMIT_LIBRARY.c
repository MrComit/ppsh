#include <ultra64.h>
#include "sm64.h"
#include "level_update.h"

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