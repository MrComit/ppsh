#include "levels/bob/bridge/collision_header.h"

void bhv_ii_bridge_loop(void) {

    switch (o->oAction) {
        case 0:
            o->collisionData = segmented_to_virtual(bridge_down_collision);
            o->oAnimState = 0;

            if (save_file_get_star_flags(gCurrSaveFileNum - 1, 0) & 0x01 != 0) {
                o->collisionData = segmented_to_virtual(bridge_up_collision);
                o->oAction = 1;
                o->oAnimState = 1;
            }
            break;
        case 1:
            if (gMarioObject->platform == o && o->oDistanceToMario > 7000) {
                o->activeFlags = 0;
            }
            break;
    }
}