extern s8 gSpinCoinCollected;

void bhv_spinning_coins_init(void) {
f32 mag;
s16 dirAdd;
s16 dir = 0;
s8 i;
//struct Object *coin1, *coin2, *coin3, *coin4, *coin5, *coin6, *coin7, *coin8;
struct Object *coin;

    mag = (f32)((o->oBehParams >> 24) & 0xFF) * 20.0f;
    dirAdd = ((o->oBehParams >> 16) & 0xFF) << 4;

    if ((o->oBehParams & 0xFF00) == 0) {
        coin = spawn_object(o, MODEL_YELLOW_COIN, bhvSpinningYCoin);
        coin->oCoinMag = mag;
        coin->oCoinDirAdd = dirAdd;
        coin->oCoinDir = dir;
        coin->oHomeX = o->oPosX;
        coin->oHomeY = o->oPosY;
        coin->oHomeZ = o->oPosZ;
    } else if (!(gSpinCoinCollected)) {
        coin = spawn_object(o, MODEL_RED_COIN, bhvSpinningRCoin);
        coin->oCoinMag = mag;
        coin->oCoinDirAdd = dirAdd;
        coin->oCoinDir = dir;
        coin->oHomeX = o->oPosX;
        coin->oHomeY = o->oPosY;
        coin->oHomeZ = o->oPosZ;
    }

    for (i = 0; i < 7; i++) {
        dir += 0x2000;
        coin = spawn_object(o, MODEL_YELLOW_COIN, bhvSpinningYCoin);
        coin->oCoinMag = mag;
        coin->oCoinDirAdd = dirAdd;
        coin->oCoinDir = dir;
        coin->oHomeX = o->oPosX;
        coin->oHomeY = o->oPosY;
        coin->oHomeZ = o->oPosZ;
    }

}