#ifndef _LEVEL_GEO_H
#define _LEVEL_GEO_H

struct Struct802761D0
{
    u16 unk0;
    s16 unk2;
    u8 filler4[0x18-0x4];
};

extern Gfx *geo_enfvx_main(s32 a, struct GraphNode *b, f32 c[4][4]);
extern Gfx *geo_skybox_main(s32 a, struct GraphNode *b, UNUSED Mat4 *c);
extern Gfx *geo_update_bob_light(s32 callContext, struct GraphNode *node);
//extern Gfx *geo_sc_cam_pos(s32 callContext, struct GraphNode *node);

extern u8 gLightColor;
extern u8 gLightAction;
extern u8 gLightApproach;
extern u8 gLightSpeed;
extern u32 gLightTimer;

#endif /* _LEVEL_GEO_H */
