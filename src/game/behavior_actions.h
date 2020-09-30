#ifndef _BEHAVIOR_ACTIONS_H
#define _BEHAVIOR_ACTIONS_H

extern void func_802AA618(s32,s32,f32);
extern void bhv_spawn_star_no_level_exit(u32);
extern void bhv_star_door_loop_2();
extern void spawn_triangle_break_particles(s16,s16,f32,s16);
extern void func_802ADA94(void);
extern void func_802ADBBC(u32);
extern void func_802ADC20(s16,s16);
extern s32 func_802B0C54(f32,f32);
extern s32 func_802B2894(f32*,f32*,f32,f32);
void func_802B8F7C(Vec3f dest,Vec3f src);
extern void func_802BCFC4(f32,f32,s16,s16);
extern void play_penguin_walking_sound(s32);
extern s32 func_802C5A64(s32*);
extern void func_802C76E0(s32, f32, f32, f32, f32);

void bhv_cap_switch_loop(void);
void bhv_tiny_star_particles_init(void);
void bhv_grindel_thwomp_loop(void);
void bhv_koopa_shell_underwater_loop(void);
void bhv_door_init(void);
void bhv_door_loop(void);
void bhv_star_door_loop(void);
void bhv_mr_i_loop(void);
void bhv_mr_i_body_loop(void);
void bhv_mr_i_particle_loop(void);
void bhv_piranha_particle_loop(void);
void bhv_giant_pole_loop(void);
void bhv_pole_init(void);
void BehClimbDetectLoop(void);
void bhv_thi_huge_island_top_loop(void);
void bhv_thi_tiny_island_top_loop(void);
void bhv_king_bobomb_loop(void);
void bhv_bobomb_anchor_mario_loop(void);
void bhv_beta_chest_bottom_init(void);
void bhv_beta_chest_bottom_loop(void);
void bhv_beta_chest_lid_loop(void);
void bhv_bubble_wave_init(void);
void bhv_bubble_maybe_loop(void);
void bhv_small_water_loop(void);
void bhv_water_air_bubble_init(void);
void bhv_water_air_bubble_loop(void);
void bhv_particle_init(void);
void bhv_particle_loop(void);
void bhv_water_waves_init(void);
void bhv_small_bubbles_loop(void);
void bhv_fish_group_loop(void);
void bhv_cannon_base_loop(void);
void bhv_cannon_barrel_loop(void);
void bhv_cannon_base_unused_loop(void);
void bhv_chuckya_loop(void);
void bhv_chuckya_anchor_mario_loop(void);
void bhv_rotating_platform_loop(void);
void bhv_wf_breakable_wall_loop(void);
void bhv_kickable_board_loop(void);
void bhv_tower_door_loop(void);
void bhv_wf_rotating_wooden_platform_loop(void);
void bhv_koopa_shell_underwater_loop(void);
void BehFadingWarpLoop(void);
void bhv_warp_loop(void);
void bhv_white_puff_exploding_loop(void);
void bhv_spawned_star_init(void);
void bhv_spawned_star_loop(void);
void bhv_coin_init(void);
void bhv_coin_loop(void);
void bhv_coin_inside_boo_loop(void);
void bhv_coin_formation_init(void);
void bhv_coin_formation_spawn_loop(void);
void bhv_coin_formation_loop(void);
void bhv_temp_coin_loop(void);
void bhv_coin_sparkles_loop(void);
void bhv_golden_coin_sparkles_loop(void);
void bhv_wall_tiny_star_particle_loop(void);
void bhv_pound_tiny_star_particle_loop(void);
void bhv_pound_tiny_star_particle_init(void);
void bhv_punch_tiny_triangle_loop(void);
void bhv_punch_tiny_triangle_init(void);
void bhv_tumbling_bridge_platform_loop(void);
void bhv_tumbling_bridge_loop(void);
void bhv_elevator_init(void);
void bhv_elevator_loop(void);
void bhv_water_mist_loop(void);
void bhv_water_mist_spawn_loop(void);
void bhv_water_mist_2_loop(void);
void bhv_pound_white_puffs_init(void);
void bhv_unused_0e40_init(void);
void bhv_ground_snow_init(void);
void bhv_wind_loop(void);
void bhv_unused_particle_spawn_loop(void);
void bhv_ukiki_cage_star_loop(void);
void bhv_ukiki_cage_loop(void);
void bhv_bitfs_sinking_platform_loop(void);
void bhv_bitfs_sinking_cage_platform_loop(void);
void bhv_ddd_moving_pole_loop(void);
void bhv_platform_normals_init(void);
void bhv_tilting_inverted_pyramid_loop(void);
void bhv_squishable_platform_loop(void);
void bhv_beta_moving_flames_spawn_loop(void);
void bhv_beta_moving_flames_loop(void);
void bhv_rr_rotating_bridge_platform_loop(void);
void bhv_flamethrower_loop(void);
void bhv_flamethrower_flame_loop(void);
void bhv_bouncing_fireball_loop(void);
void bhv_bouncing_fireball_flame_loop(void);
void bhv_bowser_shock_wave_loop(void);
void bhv_flame_mario_loop(void);
void bhv_black_smoke_mario_loop(void);
void bhv_black_smoke_bowser_loop(void);
void bhv_black_smoke_upward_loop(void);
void bhv_beta_fish_splash_spawner_loop(void);
void bhv_spindrift_loop(void);
void bhv_tower_platform_group_loop(void);
void bhv_wf_sliding_tower_platform_loop(void);
void bhv_wf_elevator_tower_platform_loop(void);
void bhv_wf_solid_tower_platform_loop(void);
void bhv_snow_leaf_particle_spawn_init(void);
void bhv_tree_snow_or_leaf_loop(void);
void bhv_piranha_plant_bubble_loop(void);
void bhv_piranha_plant_waking_bubbles_loop(void);
void bhv_purple_switch_loop(void);
void bhv_hidden_object_loop(void);
void bhv_breakable_box_loop(void);
void bhv_pushable_loop(void);
void bhv_init_room(void);
void bhv_small_water_wave_loop(void);
void bhv_yellow_coin_init(void);
void bhv_yellow_coin_loop(void);
void bhv_squarish_path_moving_loop(void);
void bhv_heave_ho_loop(void);
void bhv_heave_ho_throw_mario_loop(void);
void bhv_ccm_touched_star_spawn_loop(void);
void bhv_unused_poundable_platform(void);
void bhv_beta_trampoline_top_loop(void);
void bhv_beta_trampoline_spring_loop(void);
void bhv_jumping_box_loop(void);
void bhv_boo_cage_loop(void);
void bhv_bowser_key_loop(void);
void bhv_grand_star_loop(void);
void bhv_beta_boo_key_loop(void);
void bhv_alpha_boo_key_loop(void);
void bhv_bullet_bill_init(void);
void bhv_bullet_bill_loop(void);
void bhv_white_puff_smoke_init(void);
void bhv_bowser_tail_anchor_loop(void);
void bhv_bowser_init(void);
void bhv_bowser_loop(void);
void bhv_bowser_body_anchor_loop(void);
void bhv_bowser_flame_spawn_loop(void);
void bhv_falling_bowser_platform_loop(void);
void bhv_blue_bowser_flame_init(void);
void bhv_blue_bowser_flame_loop(void);
void bhv_flame_floating_landing_init(void);
void bhv_flame_floating_landing_loop(void);
void bhv_blue_flames_group_loop(void);
void bhv_flame_bouncing_init(void);
void bhv_flame_bouncing_loop(void);
void bhv_flame_moving_forward_growing_init(void);
void bhv_flame_moving_forward_growing_loop(void);
void bhv_flame_bowser_init(void);
void bhv_flame_bowser_loop(void);
void bhv_flame_large_burning_out_init(void);
void bhv_blue_fish_loop(void);
void bhv_tank_fish_group_loop(void);
void bhv_checkerboard_elevator_group_init(void);
void bhv_checkerboard_platform_init(void);
void bhv_checkerboard_platform_loop(void);
void bhv_bowser_key_unlock_door_loop(void);
void bhv_bowser_key_course_exit_loop(void);
void bhv_invisible_objects_under_bridge_init(void);
void bhv_water_level_pillar_init(void);
void bhv_water_level_pillar_loop(void);
void bhv_ddd_warp_loop(void);
void bhv_moat_grills_loop(void);
void bhv_rotating_clock_arm_loop(void);
void bhv_ukiki_init(void);
void bhv_ukiki_loop(void);
void bhv_lll_sinking_rock_block_loop(void);
void bhv_lll_moving_octagonal_mesh_platform_loop(void);
void bhv_lll_rotating_block_fire_bars_loop(void);
void bhv_lll_rotating_hex_flame_loop(void);
void bhv_lll_wood_piece_loop(void);
void bhv_lll_floating_wood_bridge_loop(void);
void bhv_volcano_flames_loop(void);
void bhv_lll_rotating_hexagonal_ring_loop(void);
void bhv_lll_sinking_rectangular_platform_loop(void);
void bhv_lll_sinking_square_platforms_loop(void);
void bhv_koopa_shell_loop(void);
void bhv_koopa_shell_flame_loop(void);
void bhv_tox_box_loop(void);
void bhv_piranha_plant_loop(void);
void bhv_lll_bowser_puzzle_piece_loop(void);
void bhv_lll_bowser_puzzle_loop(void);
void bhv_tuxies_mother_loop(void);
void bhv_small_penguin_loop(void);
void bhv_fish_loop(void);
void bhv_fish_group_2_loop(void);
void bhv_wdw_express_elevator_loop(void);
void bhv_bird_chirp_chirp_loop(void);
void bhv_cheep_cheep_loop(void);
void bhv_exclamation_box_loop(void);
void bhv_rotatin_exclamation_box_loop(void);
void bhv_sound_spawner_init(void);
void bhv_bowsers_sub_loop(void);
void bhv_sushi_shark_loop(void);
void bhv_sushi_shark_collision_loop(void);
void bhv_jrb_sliding_box_loop(void);
void bhv_ship_part_3_loop(void);
void bhv_sunken_ship_part_loop(void);
void bhv_white_puff_1_loop(void);
void bhv_white_puff_2_loop(void);
void bhv_blue_coin_switch_loop(void);
void bhv_hidden_blue_coin_loop(void);
void bhv_openable_cage_door_loop(void);
void bhv_openable_grill_loop(void);
void bhv_water_level_diamond_loop(void);
void bhv_init_changing_water_level_loop(void);
void bhv_tweester_sand_particle_loop(void);
void bhv_tweester_loop(void);
void bhv_merry_go_round_boo_manager_loop(void);
void bhv_animated_texture_loop(void);
void bhv_boo_in_castle_loop(void);
void bhv_boo_with_cage_init(void);
void bhv_boo_with_cage_loop(void);
void bhv_boo_init(void);
void bhv_big_boo_loop(void);
void bhv_courtyard_boo_triplet_init(void);
void bhv_boo_loop(void);
void bhv_boo_boss_spawned_bridge_loop(void);
void bhv_bbh_tilting_trap_platform_loop(void);
void bhv_haunted_bookshelf_loop(void);
void bhv_merry_go_round_loop(void);
void bhv_play_music_track_when_touched_loop(void);
void bhv_beta_bowser_anchor_loop(void);
void bhv_static_checkered_platform_loop(void);
void bhv_castle_floor_trap_init(void);
void bhv_castle_floor_trap_loop(void);
void bhv_floor_trap_in_castle_loop(void);
void bhv_sparkle_spawn_loop(void);
void bhv_scuttlebug_loop(void);
void bhv_scuttlebug_spawn_loop(void);
void bhv_whomp_loop(void);
void bhv_water_splash_loop(void);
void bhv_water_drops_loop(void);
void bhv_water_surface_white_wave_init(void);
void bhv_object_bubble_ripples_init(void);
void bhv_surface_waves_loop(void);
void bhv_surface_wave_shrinking_init(void);
void bhv_wave_trail_loop(void);
void bhv_white_wind_particle_loop(void);
void bhv_snowman_wind_blowing_loop(void);
void bhv_walking_penguin_loop(void);
void bhv_menu_button_init(void);
void bhv_menu_button_loop(void);
void bhv_menu_button_manager_init(void);
void bhv_menu_button_manager_loop(void);
void bhv_act_selector_star_type_loop(void);
void bhv_act_selector_init(void);
void bhv_act_selector_loop(void);
void bhv_moving_yellow_coin_init(void);
void bhv_moving_yellow_coin_loop(void);
void bhv_moving_blue_coin_init(void);
void bhv_moving_blue_coin_loop(void);
void bhv_blue_coin_sliding_jumping_init(void);
void bhv_blue_coin_sliding_loop(void);
void bhv_blue_coin_jumping_loop(void);
void bhv_seaweed_init(void);
void bhv_seaweed_bundle_init(void);
void bhv_bobomb_init(void);
void bhv_bobomb_loop(void);
void bhv_bobomb_fuse_smoke_init(void);
void bhv_bobomb_buddy_init(void);
void bhv_bobomb_buddy_loop(void);
void bhv_cannon_closed_init(void);
void bhv_cannon_closed_loop(void);
void bhv_whirlpool_init(void);
void bhv_whirlpool_loop(void);
void bhv_jet_stream_loop(void);
void bhv_homing_amp_init(void);
void bhv_homing_amp_loop(void);
void bhv_circling_amp_init(void);
void bhv_circling_amp_loop(void);
void bhv_butterfly_init(void);
void bhv_butterfly_loop(void);
void bhv_hoot_init(void);
void bhv_hoot_loop(void);
void bhv_beta_holdable_object_init(void);
void bhv_beta_holdable_object_loop(void);
void bhv_object_bubble_init(void);
void bhv_object_bubble_loop(void);
void bhv_object_water_wave_init(void);
void bhv_object_water_wave_loop(void);
void bhv_explosion_init(void);
void bhv_explosion_loop(void);
void bhv_bobomb_bully_death_smoke_init(void);
void bhv_bobomb_explosion_bubble_init(void);
void bhv_bobomb_explosion_bubble_loop(void);
void bhv_respawner_loop(void);
void bhv_small_bully_init(void);
void bhv_bully_loop(void);
void bhv_big_bully_init(void);
void bhv_big_bully_with_minions_init(void);
void bhv_big_bully_with_minions_loop(void);
void bhv_jet_stream_ring_spawner_loop(void);
void bhv_jet_stream_water_ring_init(void);
void bhv_jet_stream_water_ring_loop(void);
void bhv_manta_ray_water_ring_init(void);
void bhv_manta_ray_water_ring_loop(void);
void bhv_bowser_bomb_loop(void);
void bhv_bowser_bomb_explosion_loop(void);
void bhv_bowser_bomb_smoke_loop(void);
void bhv_celebration_star_init(void);
void bhv_celebration_star_loop(void);
void bhv_celebration_star_sparkle_loop(void);
void bhv_star_key_collection_puff_spawner_loop(void);
void bhv_lll_drawbridge_spawner_loop(void);
void bhv_lll_drawbridge_loop(void);
void bhv_small_bomp_init(void);
void bhv_small_bomp_loop(void);
void bhv_large_bomp_init(void);
void bhv_large_bomp_loop(void);
void bhv_wf_sliding_platform_init(void);
void bhv_wf_sliding_platform_loop(void);
void bhv_moneybag_init(void);
void bhv_moneybag_loop(void);
void bhv_moneybag_hidden_loop(void);
void bhv_bob_pit_bowling_ball_init(void);
void bhv_bob_pit_bowling_ball_loop(void);
void bhv_free_bowling_ball_init(void);
void bhv_free_bowling_ball_loop(void);
void bhv_bowling_ball_init(void);
void bhv_bowling_ball_loop(void);
void bhv_generic_bowling_ball_spawner_init(void);
void bhv_generic_bowling_ball_spawner_loop(void);
void bhv_thi_bowling_ball_spawner_loop(void);
void bhv_rr_cruiser_wing_init(void);
void bhv_rr_cruiser_wing_loop(void);
void bhv_spindel_init(void);
void bhv_spindel_loop(void);
void bhv_ssl_moving_pyramid_wall_init(void);
void bhv_ssl_moving_pyramid_wall_loop(void);
void bhv_pyramid_elevator_init(void);
void bhv_pyramid_elevator_loop(void);
void bhv_pyramid_elevator_trajectory_marker_ball_loop(void);
void bhv_pyramid_top_init(void);
void bhv_pyramid_top_loop(void);
void bhv_pyramid_top_fragment_init(void);
void bhv_pyramid_top_fragment_loop(void);
void bhv_pyramid_pillar_touch_detector_loop(void);
void bhv_waterfall_sound_loop(void);
void bhv_volcano_sound_loop(void);
void bhv_castle_flag_init(void);
void bhv_birds_sound_loop(void);
void bhv_ambient_sounds_init(void);
void bhv_sand_sound_loop(void);
void bhv_castle_cannon_grate_init(void);
void bhv_snowmans_bottom_init(void);
void bhv_snowmans_bottom_loop(void);
void bhv_snowmans_head_init(void);
void bhv_snowmans_head_loop(void);
void bhv_snowmans_body_checkpoint_loop(void);
void bhv_big_boulder_init(void);
void bhv_big_boulder_loop(void);
void bhv_big_boulder_generator_loop(void);
void bhv_wing_cap_init(void);
void bhv_wing_vanish_cap_loop(void);
void bhv_metal_cap_init(void);
void bhv_metal_cap_loop(void);
void bhv_normal_cap_init(void);
void bhv_normal_cap_loop(void);
void bhv_vanish_cap_init(void);
void bhv_collect_star_init(void);
void bhv_collect_star_loop(void);
void bhv_star_spawn_init(void);
void bhv_star_spawn_loop(void);
void bhv_hidden_red_coin_star_init(void);
void bhv_hidden_red_coin_star_loop(void);
void bhv_red_coin_init(void);
void bhv_red_coin_loop(void);
void bhv_bowser_course_red_coin_star_loop(void);
void bhv_hidden_star_init(void);
void bhv_hidden_star_loop(void);
void bhv_hidden_star_trigger_loop(void);
void bhv_ttm_rolling_log_init(void);
void bhv_rolling_log_loop(void);
void bhv_lll_rolling_log_init(void);
void bhv_1up_common_init(void);
void bhv_1up_walking_loop(void);
void bhv_1up_running_away_loop(void);
void bhv_1up_sliding_loop(void);
void bhv_1up_init(void);
void bhv_1up_loop(void);
void bhv_1up_jump_on_approach_loop(void);
void bhv_1up_hidden_loop(void);
void bhv_1up_hidden_trigger_loop(void);
void bhv_1up_hidden_in_pole_loop(void);
void bhv_1up_hidden_in_pole_trigger_loop(void);
void bhv_1up_hidden_in_pole_spawner_loop(void);
void bhv_controllable_platform_init(void);
void bhv_controllable_platform_loop(void);
void bhv_controllable_platform_sub_loop(void);
void bhv_breakable_box_small_init(void);
void bhv_breakable_box_small_loop(void);
void bhv_sliding_snow_mound_loop(void);
void bhv_snow_mound_spawn_loop(void);
void bhv_floating_platform_loop(void);
void bhv_arrow_lift_loop(void);
void bhv_orange_number_init(void);
void bhv_orange_number_loop(void);
void bhv_manta_ray_init(void);
void bhv_manta_ray_loop(void);
void bhv_falling_pillar_init(void);
void bhv_falling_pillar_loop(void);
void bhv_falling_pillar_hitbox_loop(void);
void bhv_jrb_floating_box_loop(void);
void bhv_decorative_pendulum_init(void);
void bhv_decorative_pendulum_loop(void);
void bhv_treasure_chest_ship_init(void);
void bhv_treasure_chest_ship_loop(void);
void bhv_treasure_chest_jrb_init(void);
void bhv_treasure_chest_jrb_loop(void);
void bhv_treasure_chest_init(void);
void bhv_treasure_chest_loop(void);
void bhv_treasure_chest_bottom_init(void);
void bhv_treasure_chest_bottom_loop(void);
void bhv_treasure_chest_top_loop(void);
void bhv_mips_init(void);
void bhv_mips_loop(void);
void bhv_yoshi_init(void);
void bhv_koopa_init(void);
void bhv_koopa_update(void);
void bhv_koopa_race_endpoint_update(void);
void bhv_pokey_update(void);
void bhv_pokey_body_part_update(void);
void bhv_swoop_update(void);
void bhv_fly_guy_update(void);
void bhv_goomba_init(void);
void bhv_goomba_update(void);
void bhv_goomba_triplet_spawner_update(void);
void bhv_chain_chomp_update(void);
void bhv_chain_chomp_chain_part_update(void);
void bhv_wooden_post_update(void);
void bhv_chain_chomp_gate_init(void);
void bhv_chain_chomp_gate_update(void);
void bhv_wiggler_update(void);
void bhv_wiggler_body_part_update(void);
void bhv_enemy_lakitu_update(void);
void bhv_camera_lakitu_init(void);
void bhv_camera_lakitu_update(void);
void bhv_cloud_update(void);
void bhv_cloud_part_update(void);
void bhv_spiny_update(void);
void bhv_monty_mole_init(void);
void bhv_monty_mole_update(void);
void bhv_monty_mole_hole_update(void);
void bhv_monty_mole_rock_update(void);
void bhv_platform_on_track_init(void);
void bhv_platform_on_track_update(void);
void bhv_track_ball_update(void);
void bhv_seesaw_platform_init(void);
void bhv_seesaw_platform_update(void);
void bhv_ferris_wheel_axle_init(void);
void bhv_ferris_wheel_platform_update(void);
void bhv_water_bomb_spawner_update(void);
void bhv_water_bomb_update(void);
void bhv_water_bomb_shadow_update(void);
void bhv_ttc_rotating_solid_init(void);
void bhv_ttc_rotating_solid_update(void);
void bhv_ttc_pendulum_init(void);
void bhv_ttc_pendulum_update(void);
void bhv_ttc_treadmill_init(void);
void bhv_ttc_treadmill_update(void);
void bhv_ttc_moving_bar_init(void);
void bhv_ttc_moving_bar_update(void);
void bhv_ttc_cog_init(void);
void bhv_ttc_cog_update(void);
void bhv_ttc_pit_block_init(void);
void bhv_ttc_pit_block_update(void);
void bhv_ttc_elevator_init(void);
void bhv_ttc_elevator_update(void);
void bhv_ttc_2d_rotator_init(void);
void bhv_ttc_2d_rotator_update(void);
void bhv_ttc_spinner_update(void);
void bhv_mr_blizzard_init(void);
void bhv_mr_blizzard_update(void);
void bhv_mr_blizzard_snowball(void);
void bhv_sliding_plat_2_init(void);
void bhv_sliding_plat_2_loop(void);
void bhv_rotating_octagonal_plat_init(void);
void bhv_rotating_octagonal_plat_loop(void);
void bhv_animates_on_floor_switch_press_init(void);
void bhv_animates_on_floor_switch_press_loop(void);
void bhv_activated_back_and_forth_platform_init(void);
void bhv_activated_back_and_forth_platform_update(void);
void bhv_recovery_heart_loop(void);
void bhv_water_bomb_cannon_loop(void);
void bhv_bubble_cannon_barrel_loop(void);
void bhv_unagi_init(void);
void bhv_unagi_loop(void);
void bhv_unagi_subobject_loop(void);
void bhv_dorrie_update(void);
void bhv_haunted_chair_init(void);
void bhv_haunted_chair_loop(void);
void bhv_mad_piano_update(void);
void bhv_flying_bookend_loop(void);
void bhv_bookend_spawn_loop(void);
void bhv_haunted_bookshelf_manager_loop(void);
void bhv_book_switch_loop(void);
void bhv_fire_piranha_plant_init(void);
void bhv_fire_piranha_plant_update(void);
void bhv_small_piranha_flame_loop(void);
void bhv_fire_spitter_update(void);
void bhv_fly_guy_flame_loop(void);
void bhv_snufit_loop(void);
void bhv_snufit_balls_loop(void);
void bhv_horizontal_grindel_init(void);
void bhv_horizontal_grindel_update(void);
void bhv_eyerok_boss_loop(void);
void bhv_eyerok_hand_loop(void);
void bhv_klepto_init(void);
void bhv_klepto_update(void);
void bhv_bird_update(void);
void bhv_racing_penguin_init(void);
void bhv_racing_penguin_update(void);
void bhv_penguin_race_finish_line_update(void);
void bhv_penguin_race_shortcut_check_update(void);
void bhv_coffin_spawner_loop(void);
void bhv_coffin_loop(void);
void bhv_clam_loop(void);
void bhv_skeeter_update(void);
void bhv_skeeter_wave_update(void);
void bhv_swing_platform_init(void);
void bhv_swing_platform_update(void);
void bhv_donut_platform_spawner_update(void);
void bhv_donut_platform_update(void);
void bhv_ddd_pole_init(void);
void bhv_ddd_pole_update(void);
void bhv_red_coin_star_marker_init(void);
void bhv_triplet_butterfly_update(void);
void bhv_bubba_loop(void);
void bhv_intro_lakitu_loop(void);
void bhv_intro_peach_loop(void);
void bhv_end_birds_1_loop(void);
void bhv_end_birds_2_loop(void);
void bhv_intro_scene_loop(void);
void BehDustSmokeLoop(void);
void BehYoshiLoop(void);
void bhvLllVolcanoFallingTrap_loop(void);

/* custom */
void bhv_koopa_npc_loop(void);
void koopa_the_wimp_loop(void);
void koopa_the_sick_loop(void);
void bhv_koopa_npc_init(void);
void koopa_the_mechanic_loop(void);

void bhv_star_piece_loop(void);
void bhv_star_piece_switch_loop(void);
void bhv_star_piece_star_loop(void);

void bhv_sand_mound_loop(void);
void bhv_star_by_switch_loop(void);
void bhv_construction_loop(void);
void bhv_barricade_loop(void);
void bhv_spinning_coins_init(void);

void bhv_spinning_ycoin_loop(void);
void bhv_spinning_rcoin_loop(void);

void bhv_porcupuffer_loop(void);
void bhv_porcupuffer_init(void);

void bhv_FBblock_loop(void);
void bhv_FBblock_init(void);

void bhv_ii_bridge_loop(void);
void bhv_mole_npc_loop(void);
void bhv_queen_mole_loop(void);
void bhv_queen_mole_init(void);
void mole_npc_default_loop(void);
void mole_npc_act0(void);
void mole_npc_act1(void);
void mole_npc_act2(void);
void mole_npc_act3(void);
void mole_npc_act4(void);
void mole_npc_act5(void);
void bhv_canyon_elevator_loop(void);
void bhv_wrench_init(void);
void bhv_wrench_loop(void);
void bhv_star_by_wrench_loop(void);
void bhv_splat_loop(void);
void bhv_float_rock_loop(void);
void bhv_horizontal_rock_loop(void);
void bhv_float_rock_queen_loop(void);
void bhv_horizontal_rock_queen_loop(void);
void bhv_rock_door_loop(void);
void bhv_rock_door_init(void);
void bhv_queen_wrench_loop(void);
void bhv_queen_wrench_init(void);
void bhv_bomb_switch_loop(void);
void bhv_bomb_boulder_loop(void);
void bhv_wrench_thrower_loop(void);
void bhv_colored_cube_init(void);
void bhv_colored_cube_loop(void);
void bhv_star_by_cube_loop(void);
void bhv_colored_boo_loop(void);
void bhv_colored_boo_init(void);
void bhv_colored_dash_boo_loop(void);
void bhv_colored_dash_boo_init(void);
void bhv_dash_boo_spawner_loop(void);
void bhv_timed_gate_loop(void);
void bhv_simp_truck_loop(void);
void bhv_simp_truck_init(void);
void bhv_simp_big_truck_loop(void);
void bhv_simp_big_truck_init(void);
void bhv_simp_mine_loop(void);
void bhv_simp_mg_toad_loop(void);
void bhv_simp_elevator_loop(void);
void bhv_spotlight_loop(void);
void bhv_gang_toad_loop(void);
void bhv_gang_toad_init(void);
void bhv_bounce_box_loop(void);
void bhv_appearing_block_loop(void);
void bhv_purple_switch_init(void);
void bhv_deathwarp_loop(void);
void bhv_bonus_star_loop(void);
void bhv_magic_door_init(void);
void bhv_magic_door_loop(void);


extern Gfx *Geo18_802B1BB0(s32 run, UNUSED struct GraphNode *node, Mat4 mtx);

// Bowser
extern Gfx *Geo18_802B7D44(s32 a0, struct GraphNode *node, UNUSED s32 a2);
extern Gfx *Geo18_802B798C(s32 run, UNUSED struct GraphNode *node, Mat4 mtx);
extern Gfx *geo_switch_bowser_eyes(s32 run, struct GraphNode *node, UNUSED Mat4 *mtx);

// Tuxie
extern Gfx *geo_switch_tuxie_mother_eyes(s32 run, struct GraphNode *node, UNUSED Mat4 *mtx);

// Cap switch
extern Gfx *Geo18_802A719C(s32 run, UNUSED struct GraphNode *node, Mat4 mtx);

// Snufit
extern Gfx *Geo18_8030D93C(s32 arg0, struct GraphNode *node, UNUSED void *arg2);
extern Gfx *Geo18_8030D9AC(s32 arg0, struct GraphNode *node, UNUSED void *arg2);

// Bowser key cutscene
extern Gfx *Geo18_802BA2B0(s32 run, struct GraphNode *node, UNUSED f32 mtx[4][4]);

// Water splash
extern struct WaterSplashParams D_8032FDD0;
extern struct WaterSplashParams D_8032FE18;

#endif // _BEHAVIOR_ACTIONS_H
