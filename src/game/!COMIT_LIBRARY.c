#include <ultra64.h>
#include "sm64.h"


u16 RandomMinMaxU16(u16 min, u16 max) {
    u16 num = RandomU16();
    return (num % ((max + 1) - min)) + min;
}