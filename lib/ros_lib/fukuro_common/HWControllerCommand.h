#ifndef _ROS_fukuro_common_HWControllerCommand_h
#define _ROS_fukuro_common_HWControllerCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/VelCmd.h"
#include "fukuro_common/DribblerVel.h"
#include "fukuro_common/MotorVel.h"

namespace fukuro_common
{

  class HWControllerCommand : public ros::Msg
  {
    public:
      typedef fukuro_common::VelCmd _vel_type;
      _vel_type vel;
      typedef fukuro_common::DribblerVel _dribbler_type;
      _dribbler_type dribbler;
      typedef fukuro_common::MotorVel _motor_type;
      _motor_type motor;
      typedef float _servo_type;
      _servo_type servo;
      typedef int32_t _kick_type;
      _kick_type kick;
      typedef int8_t _dribbler_mode_type;
      _dribbler_mode_type dribbler_mode;
      typedef bool _pwm_test_type;
      _pwm_test_type pwm_test;
      typedef bool _motor_brake_type;
      _motor_brake_type motor_brake;

    HWControllerCommand():
      vel(),
      dribbler(),
      motor(),
      servo(0),
      kick(0),
      dribbler_mode(0),
      pwm_test(0),
      motor_brake(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->vel.serialize(outbuffer + offset);
      offset += this->dribbler.serialize(outbuffer + offset);
      offset += this->motor.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_servo;
      u_servo.real = this->servo;
      *(outbuffer + offset + 0) = (u_servo.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_servo.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_servo.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_servo.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->servo);
      union {
        int32_t real;
        uint32_t base;
      } u_kick;
      u_kick.real = this->kick;
      *(outbuffer + offset + 0) = (u_kick.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kick.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kick.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kick.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kick);
      union {
        int8_t real;
        uint8_t base;
      } u_dribbler_mode;
      u_dribbler_mode.real = this->dribbler_mode;
      *(outbuffer + offset + 0) = (u_dribbler_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dribbler_mode);
      union {
        bool real;
        uint8_t base;
      } u_pwm_test;
      u_pwm_test.real = this->pwm_test;
      *(outbuffer + offset + 0) = (u_pwm_test.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pwm_test);
      union {
        bool real;
        uint8_t base;
      } u_motor_brake;
      u_motor_brake.real = this->motor_brake;
      *(outbuffer + offset + 0) = (u_motor_brake.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_brake);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->vel.deserialize(inbuffer + offset);
      offset += this->dribbler.deserialize(inbuffer + offset);
      offset += this->motor.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_servo;
      u_servo.base = 0;
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->servo = u_servo.real;
      offset += sizeof(this->servo);
      union {
        int32_t real;
        uint32_t base;
      } u_kick;
      u_kick.base = 0;
      u_kick.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kick.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kick.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kick.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->kick = u_kick.real;
      offset += sizeof(this->kick);
      union {
        int8_t real;
        uint8_t base;
      } u_dribbler_mode;
      u_dribbler_mode.base = 0;
      u_dribbler_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->dribbler_mode = u_dribbler_mode.real;
      offset += sizeof(this->dribbler_mode);
      union {
        bool real;
        uint8_t base;
      } u_pwm_test;
      u_pwm_test.base = 0;
      u_pwm_test.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pwm_test = u_pwm_test.real;
      offset += sizeof(this->pwm_test);
      union {
        bool real;
        uint8_t base;
      } u_motor_brake;
      u_motor_brake.base = 0;
      u_motor_brake.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motor_brake = u_motor_brake.real;
      offset += sizeof(this->motor_brake);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/HWControllerCommand"; };
    virtual const char * getMD5() override { return "47467103153a6791139ce01ce98b8f42"; };

  };

}
#endif
