#ifndef _ROS_fukuro_common_RobotControl_h
#define _ROS_fukuro_common_RobotControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"
#include "std_msgs/String.h"

namespace fukuro_common
{

  class RobotControl : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _target_pose_type;
      _target_pose_type target_pose;
      typedef std_msgs::String _option_type;
      _option_type option;
      typedef std_msgs::String _control_type;
      _control_type control;
      typedef int32_t _dribbler_state_type;
      _dribbler_state_type dribbler_state;
      typedef float _linear_speed_limit_type;
      _linear_speed_limit_type linear_speed_limit;
      typedef float _angular_speed_limit_type;
      _angular_speed_limit_type angular_speed_limit;
      typedef bool _plan_type;
      _plan_type plan;
      typedef bool _approach_ball_type;
      _approach_ball_type approach_ball;
      typedef bool _motor_brake_type;
      _motor_brake_type motor_brake;
      typedef bool _absolute_move_type;
      _absolute_move_type absolute_move;

    RobotControl():
      target_pose(),
      option(),
      control(),
      dribbler_state(0),
      linear_speed_limit(0),
      angular_speed_limit(0),
      plan(0),
      approach_ball(0),
      motor_brake(0),
      absolute_move(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->target_pose.serialize(outbuffer + offset);
      offset += this->option.serialize(outbuffer + offset);
      offset += this->control.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_dribbler_state;
      u_dribbler_state.real = this->dribbler_state;
      *(outbuffer + offset + 0) = (u_dribbler_state.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dribbler_state.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dribbler_state.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dribbler_state.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dribbler_state);
      union {
        float real;
        uint32_t base;
      } u_linear_speed_limit;
      u_linear_speed_limit.real = this->linear_speed_limit;
      *(outbuffer + offset + 0) = (u_linear_speed_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linear_speed_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linear_speed_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linear_speed_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->linear_speed_limit);
      union {
        float real;
        uint32_t base;
      } u_angular_speed_limit;
      u_angular_speed_limit.real = this->angular_speed_limit;
      *(outbuffer + offset + 0) = (u_angular_speed_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angular_speed_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angular_speed_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angular_speed_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angular_speed_limit);
      union {
        bool real;
        uint8_t base;
      } u_plan;
      u_plan.real = this->plan;
      *(outbuffer + offset + 0) = (u_plan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->plan);
      union {
        bool real;
        uint8_t base;
      } u_approach_ball;
      u_approach_ball.real = this->approach_ball;
      *(outbuffer + offset + 0) = (u_approach_ball.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->approach_ball);
      union {
        bool real;
        uint8_t base;
      } u_motor_brake;
      u_motor_brake.real = this->motor_brake;
      *(outbuffer + offset + 0) = (u_motor_brake.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_brake);
      union {
        bool real;
        uint8_t base;
      } u_absolute_move;
      u_absolute_move.real = this->absolute_move;
      *(outbuffer + offset + 0) = (u_absolute_move.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->absolute_move);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->target_pose.deserialize(inbuffer + offset);
      offset += this->option.deserialize(inbuffer + offset);
      offset += this->control.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_dribbler_state;
      u_dribbler_state.base = 0;
      u_dribbler_state.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dribbler_state.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dribbler_state.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dribbler_state.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dribbler_state = u_dribbler_state.real;
      offset += sizeof(this->dribbler_state);
      union {
        float real;
        uint32_t base;
      } u_linear_speed_limit;
      u_linear_speed_limit.base = 0;
      u_linear_speed_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linear_speed_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linear_speed_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linear_speed_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->linear_speed_limit = u_linear_speed_limit.real;
      offset += sizeof(this->linear_speed_limit);
      union {
        float real;
        uint32_t base;
      } u_angular_speed_limit;
      u_angular_speed_limit.base = 0;
      u_angular_speed_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angular_speed_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angular_speed_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angular_speed_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angular_speed_limit = u_angular_speed_limit.real;
      offset += sizeof(this->angular_speed_limit);
      union {
        bool real;
        uint8_t base;
      } u_plan;
      u_plan.base = 0;
      u_plan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->plan = u_plan.real;
      offset += sizeof(this->plan);
      union {
        bool real;
        uint8_t base;
      } u_approach_ball;
      u_approach_ball.base = 0;
      u_approach_ball.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->approach_ball = u_approach_ball.real;
      offset += sizeof(this->approach_ball);
      union {
        bool real;
        uint8_t base;
      } u_motor_brake;
      u_motor_brake.base = 0;
      u_motor_brake.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motor_brake = u_motor_brake.real;
      offset += sizeof(this->motor_brake);
      union {
        bool real;
        uint8_t base;
      } u_absolute_move;
      u_absolute_move.base = 0;
      u_absolute_move.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->absolute_move = u_absolute_move.real;
      offset += sizeof(this->absolute_move);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/RobotControl"; };
    virtual const char * getMD5() override { return "93b688d0728f99c2706e2fba98f1aecc"; };

  };

}
#endif
