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
            if (gMarioObject->platform == o && o->oDistanceToMario > 6000) {
                sDelayedWarpOp = 0x10;
                sDelayedWarpTimer = 12;
                sSourceWarpNodeId = 0xAB;
                func_8024A48C(sSourceWarpNodeId);
                play_transition(1, 0xC, 0x00, 0x00, 0x00);
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}