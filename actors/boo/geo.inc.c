// 0x0C000224
const GeoLayout boo_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x96, 70),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 26214),
      GEO_OPEN_NODE(),
         //GEO_ASM(0, Geo18_8029D924),
         GEO_SWITCH_CASE(4, geo_switch_anim_state),
         GEO_OPEN_NODE(),
            //GEO_DISPLAY_LIST(LAYER_OPAQUE, boo_seg5_dl_0500C1B0),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, red_boo_seg5_dl_0500C1B0),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, blue_boo_seg5_dl_0500C1B0),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, teal_boo_seg5_dl_0500C1B0),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, green_boo_seg5_dl_0500C1B0),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(), //! more close than open nodes
GEO_END(),
};
