#ifndef _ROS_fukuro_common_StrategyParam_h
#define _ROS_fukuro_common_StrategyParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class StrategyParam : public ros::Msg
  {
    public:
      typedef float _radius_dribble_auto_on_type;
      _radius_dribble_auto_on_type radius_dribble_auto_on;
      typedef float _angle_dribble_auto_on_type;
      _angle_dribble_auto_on_type angle_dribble_auto_on;
      typedef float _radius_mulai_dribble_bola_type;
      _radius_mulai_dribble_bola_type radius_mulai_dribble_bola;
      typedef float _angle_mulai_dribble_bola_type;
      _angle_mulai_dribble_bola_type angle_mulai_dribble_bola;
      typedef float _min_error_posisi_kick_type;
      _min_error_posisi_kick_type min_error_posisi_kick;
      typedef float _min_error_sudut_kick_type;
      _min_error_sudut_kick_type min_error_sudut_kick;
      typedef float _min_error_posisi_homing_type;
      _min_error_posisi_homing_type min_error_posisi_homing;
      typedef float _min_error_sudut_homing_type;
      _min_error_sudut_homing_type min_error_sudut_homing;
      typedef float _error_positioning_type;
      _error_positioning_type error_positioning;
      typedef float _error_sudut_positioning_type;
      _error_sudut_positioning_type error_sudut_positioning;
      typedef float _radius_mulai_kick_off_type;
      _radius_mulai_kick_off_type radius_mulai_kick_off;
      typedef float _upper_saturate_type;
      _upper_saturate_type upper_saturate;
      typedef float _lower_saturate_type;
      _lower_saturate_type lower_saturate;
      typedef float _upper_saturate_engaged_type;
      _upper_saturate_engaged_type upper_saturate_engaged;
      typedef float _lower_saturate_engaged_type;
      _lower_saturate_engaged_type lower_saturate_engaged;
      typedef float _max_angle_saturate_type;
      _max_angle_saturate_type max_angle_saturate;

    StrategyParam():
      radius_dribble_auto_on(0),
      angle_dribble_auto_on(0),
      radius_mulai_dribble_bola(0),
      angle_mulai_dribble_bola(0),
      min_error_posisi_kick(0),
      min_error_sudut_kick(0),
      min_error_posisi_homing(0),
      min_error_sudut_homing(0),
      error_positioning(0),
      error_sudut_positioning(0),
      radius_mulai_kick_off(0),
      upper_saturate(0),
      lower_saturate(0),
      upper_saturate_engaged(0),
      lower_saturate_engaged(0),
      max_angle_saturate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_radius_dribble_auto_on;
      u_radius_dribble_auto_on.real = this->radius_dribble_auto_on;
      *(outbuffer + offset + 0) = (u_radius_dribble_auto_on.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius_dribble_auto_on.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius_dribble_auto_on.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius_dribble_auto_on.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius_dribble_auto_on);
      union {
        float real;
        uint32_t base;
      } u_angle_dribble_auto_on;
      u_angle_dribble_auto_on.real = this->angle_dribble_auto_on;
      *(outbuffer + offset + 0) = (u_angle_dribble_auto_on.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_dribble_auto_on.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_dribble_auto_on.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_dribble_auto_on.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_dribble_auto_on);
      union {
        float real;
        uint32_t base;
      } u_radius_mulai_dribble_bola;
      u_radius_mulai_dribble_bola.real = this->radius_mulai_dribble_bola;
      *(outbuffer + offset + 0) = (u_radius_mulai_dribble_bola.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius_mulai_dribble_bola.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius_mulai_dribble_bola.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius_mulai_dribble_bola.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius_mulai_dribble_bola);
      union {
        float real;
        uint32_t base;
      } u_angle_mulai_dribble_bola;
      u_angle_mulai_dribble_bola.real = this->angle_mulai_dribble_bola;
      *(outbuffer + offset + 0) = (u_angle_mulai_dribble_bola.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_mulai_dribble_bola.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_mulai_dribble_bola.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_mulai_dribble_bola.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_mulai_dribble_bola);
      union {
        float real;
        uint32_t base;
      } u_min_error_posisi_kick;
      u_min_error_posisi_kick.real = this->min_error_posisi_kick;
      *(outbuffer + offset + 0) = (u_min_error_posisi_kick.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_error_posisi_kick.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_error_posisi_kick.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_error_posisi_kick.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_error_posisi_kick);
      union {
        float real;
        uint32_t base;
      } u_min_error_sudut_kick;
      u_min_error_sudut_kick.real = this->min_error_sudut_kick;
      *(outbuffer + offset + 0) = (u_min_error_sudut_kick.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_error_sudut_kick.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_error_sudut_kick.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_error_sudut_kick.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_error_sudut_kick);
      union {
        float real;
        uint32_t base;
      } u_min_error_posisi_homing;
      u_min_error_posisi_homing.real = this->min_error_posisi_homing;
      *(outbuffer + offset + 0) = (u_min_error_posisi_homing.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_error_posisi_homing.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_error_posisi_homing.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_error_posisi_homing.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_error_posisi_homing);
      union {
        float real;
        uint32_t base;
      } u_min_error_sudut_homing;
      u_min_error_sudut_homing.real = this->min_error_sudut_homing;
      *(outbuffer + offset + 0) = (u_min_error_sudut_homing.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_error_sudut_homing.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_error_sudut_homing.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_error_sudut_homing.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_error_sudut_homing);
      union {
        float real;
        uint32_t base;
      } u_error_positioning;
      u_error_positioning.real = this->error_positioning;
      *(outbuffer + offset + 0) = (u_error_positioning.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_positioning.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_positioning.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_positioning.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_positioning);
      union {
        float real;
        uint32_t base;
      } u_error_sudut_positioning;
      u_error_sudut_positioning.real = this->error_sudut_positioning;
      *(outbuffer + offset + 0) = (u_error_sudut_positioning.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_sudut_positioning.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_sudut_positioning.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_sudut_positioning.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_sudut_positioning);
      union {
        float real;
        uint32_t base;
      } u_radius_mulai_kick_off;
      u_radius_mulai_kick_off.real = this->radius_mulai_kick_off;
      *(outbuffer + offset + 0) = (u_radius_mulai_kick_off.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius_mulai_kick_off.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius_mulai_kick_off.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius_mulai_kick_off.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius_mulai_kick_off);
      union {
        float real;
        uint32_t base;
      } u_upper_saturate;
      u_upper_saturate.real = this->upper_saturate;
      *(outbuffer + offset + 0) = (u_upper_saturate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_upper_saturate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_upper_saturate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_upper_saturate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->upper_saturate);
      union {
        float real;
        uint32_t base;
      } u_lower_saturate;
      u_lower_saturate.real = this->lower_saturate;
      *(outbuffer + offset + 0) = (u_lower_saturate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lower_saturate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lower_saturate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lower_saturate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lower_saturate);
      union {
        float real;
        uint32_t base;
      } u_upper_saturate_engaged;
      u_upper_saturate_engaged.real = this->upper_saturate_engaged;
      *(outbuffer + offset + 0) = (u_upper_saturate_engaged.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_upper_saturate_engaged.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_upper_saturate_engaged.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_upper_saturate_engaged.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->upper_saturate_engaged);
      union {
        float real;
        uint32_t base;
      } u_lower_saturate_engaged;
      u_lower_saturate_engaged.real = this->lower_saturate_engaged;
      *(outbuffer + offset + 0) = (u_lower_saturate_engaged.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lower_saturate_engaged.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lower_saturate_engaged.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lower_saturate_engaged.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lower_saturate_engaged);
      union {
        float real;
        uint32_t base;
      } u_max_angle_saturate;
      u_max_angle_saturate.real = this->max_angle_saturate;
      *(outbuffer + offset + 0) = (u_max_angle_saturate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_angle_saturate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_angle_saturate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_angle_saturate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_angle_saturate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_radius_dribble_auto_on;
      u_radius_dribble_auto_on.base = 0;
      u_radius_dribble_auto_on.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius_dribble_auto_on.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius_dribble_auto_on.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius_dribble_auto_on.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius_dribble_auto_on = u_radius_dribble_auto_on.real;
      offset += sizeof(this->radius_dribble_auto_on);
      union {
        float real;
        uint32_t base;
      } u_angle_dribble_auto_on;
      u_angle_dribble_auto_on.base = 0;
      u_angle_dribble_auto_on.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_dribble_auto_on.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_dribble_auto_on.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_dribble_auto_on.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_dribble_auto_on = u_angle_dribble_auto_on.real;
      offset += sizeof(this->angle_dribble_auto_on);
      union {
        float real;
        uint32_t base;
      } u_radius_mulai_dribble_bola;
      u_radius_mulai_dribble_bola.base = 0;
      u_radius_mulai_dribble_bola.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius_mulai_dribble_bola.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius_mulai_dribble_bola.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius_mulai_dribble_bola.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius_mulai_dribble_bola = u_radius_mulai_dribble_bola.real;
      offset += sizeof(this->radius_mulai_dribble_bola);
      union {
        float real;
        uint32_t base;
      } u_angle_mulai_dribble_bola;
      u_angle_mulai_dribble_bola.base = 0;
      u_angle_mulai_dribble_bola.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_mulai_dribble_bola.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_mulai_dribble_bola.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_mulai_dribble_bola.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_mulai_dribble_bola = u_angle_mulai_dribble_bola.real;
      offset += sizeof(this->angle_mulai_dribble_bola);
      union {
        float real;
        uint32_t base;
      } u_min_error_posisi_kick;
      u_min_error_posisi_kick.base = 0;
      u_min_error_posisi_kick.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_error_posisi_kick.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_error_posisi_kick.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_error_posisi_kick.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_error_posisi_kick = u_min_error_posisi_kick.real;
      offset += sizeof(this->min_error_posisi_kick);
      union {
        float real;
        uint32_t base;
      } u_min_error_sudut_kick;
      u_min_error_sudut_kick.base = 0;
      u_min_error_sudut_kick.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_error_sudut_kick.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_error_sudut_kick.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_error_sudut_kick.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_error_sudut_kick = u_min_error_sudut_kick.real;
      offset += sizeof(this->min_error_sudut_kick);
      union {
        float real;
        uint32_t base;
      } u_min_error_posisi_homing;
      u_min_error_posisi_homing.base = 0;
      u_min_error_posisi_homing.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_error_posisi_homing.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_error_posisi_homing.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_error_posisi_homing.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_error_posisi_homing = u_min_error_posisi_homing.real;
      offset += sizeof(this->min_error_posisi_homing);
      union {
        float real;
        uint32_t base;
      } u_min_error_sudut_homing;
      u_min_error_sudut_homing.base = 0;
      u_min_error_sudut_homing.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_error_sudut_homing.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_error_sudut_homing.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_error_sudut_homing.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_error_sudut_homing = u_min_error_sudut_homing.real;
      offset += sizeof(this->min_error_sudut_homing);
      union {
        float real;
        uint32_t base;
      } u_error_positioning;
      u_error_positioning.base = 0;
      u_error_positioning.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_positioning.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_positioning.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_positioning.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error_positioning = u_error_positioning.real;
      offset += sizeof(this->error_positioning);
      union {
        float real;
        uint32_t base;
      } u_error_sudut_positioning;
      u_error_sudut_positioning.base = 0;
      u_error_sudut_positioning.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_sudut_positioning.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_sudut_positioning.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_sudut_positioning.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error_sudut_positioning = u_error_sudut_positioning.real;
      offset += sizeof(this->error_sudut_positioning);
      union {
        float real;
        uint32_t base;
      } u_radius_mulai_kick_off;
      u_radius_mulai_kick_off.base = 0;
      u_radius_mulai_kick_off.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius_mulai_kick_off.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius_mulai_kick_off.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius_mulai_kick_off.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius_mulai_kick_off = u_radius_mulai_kick_off.real;
      offset += sizeof(this->radius_mulai_kick_off);
      union {
        float real;
        uint32_t base;
      } u_upper_saturate;
      u_upper_saturate.base = 0;
      u_upper_saturate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_upper_saturate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_upper_saturate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_upper_saturate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->upper_saturate = u_upper_saturate.real;
      offset += sizeof(this->upper_saturate);
      union {
        float real;
        uint32_t base;
      } u_lower_saturate;
      u_lower_saturate.base = 0;
      u_lower_saturate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lower_saturate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lower_saturate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lower_saturate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lower_saturate = u_lower_saturate.real;
      offset += sizeof(this->lower_saturate);
      union {
        float real;
        uint32_t base;
      } u_upper_saturate_engaged;
      u_upper_saturate_engaged.base = 0;
      u_upper_saturate_engaged.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_upper_saturate_engaged.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_upper_saturate_engaged.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_upper_saturate_engaged.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->upper_saturate_engaged = u_upper_saturate_engaged.real;
      offset += sizeof(this->upper_saturate_engaged);
      union {
        float real;
        uint32_t base;
      } u_lower_saturate_engaged;
      u_lower_saturate_engaged.base = 0;
      u_lower_saturate_engaged.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lower_saturate_engaged.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lower_saturate_engaged.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lower_saturate_engaged.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lower_saturate_engaged = u_lower_saturate_engaged.real;
      offset += sizeof(this->lower_saturate_engaged);
      union {
        float real;
        uint32_t base;
      } u_max_angle_saturate;
      u_max_angle_saturate.base = 0;
      u_max_angle_saturate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_angle_saturate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_angle_saturate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_angle_saturate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_angle_saturate = u_max_angle_saturate.real;
      offset += sizeof(this->max_angle_saturate);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/StrategyParam"; };
    virtual const char * getMD5() override { return "21766f045e3facf112f156a585dc8583"; };

  };

}
#endif
