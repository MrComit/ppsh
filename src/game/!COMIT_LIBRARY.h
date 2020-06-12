#ifndef _!COMIT_LIBRARY_H
#define _!COMIT_LIBRARY_H


u16 CL_RandomMinMaxU16(u16 min, u16 max);
void CL_kill_mario();
u8 CL_run_timer(u16 time);
void CL_Move();
struct Object *CL_Create_Star_Ptr(f32 sp20, f32 sp24, f32 sp28);
s16 CL_object_to_point(struct Object *o, Vec3f point);
void CL_set_camera_pos(Vec3f pos);
struct Object *CL_obj_nearest_object_behavior_params(const BehaviorScript *behavior, u32 params);
void CL_dist_between_points(Vec3f from, Vec3f to, f32 *dist);

#endif