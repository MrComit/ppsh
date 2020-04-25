void bhv_splat_loop(void) {
    o->oAngleVelYaw = (((o->oBehParams >> 16) & 0xFF00) / 12);
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oPosX = o->oHomeX + (sins((s16)o->oFaceAngleYaw - 0x4000) * (f32)o->oBehParams2ndByte * 30.0);
    o->oPosZ = o->oHomeZ + (coss((s16)o->oFaceAngleYaw - 0x4000) * (f32)o->oBehParams2ndByte * 30.0);
}