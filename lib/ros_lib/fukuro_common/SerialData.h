#ifndef _ROS_fukuro_common_SerialData_h
#define _ROS_fukuro_common_SerialData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/MotorVel.h"
#include "fukuro_common/DribblerVel.h"

namespace fukuro_common
{

  class SerialData : public ros::Msg
  {
    public:
      typedef fukuro_common::MotorVel _motor_type;
      _motor_type motor;
      typedef fukuro_common::DribblerVel _dribbler_type;
      _dribbler_type dribbler;
      typedef bool _motor_brake_type;
      _motor_brake_type motor_brake;
      typedef int8_t _kick_type;
      _kick_type kick;

    SerialData():
      motor(),
      dribbler(),
      motor_brake(0),
      kick(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->motor.serialize(outbuffer + offset);
      offset += this->dribbler.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_motor_brake;
      u_motor_brake.real = this->motor_brake;
      *(outbuffer + offset + 0) = (u_motor_brake.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_brake);
      union {
        int8_t real;
        uint8_t base;
      } u_kick;
      u_kick.real = this->kick;
      *(outbuffer + offset + 0) = (u_kick.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->kick);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->motor.deserialize(inbuffer + offset);
      offset += this->dribbler.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_motor_brake;
      u_motor_brake.base = 0;
      u_motor_brake.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motor_brake = u_motor_brake.real;
      offset += sizeof(this->motor_brake);
      union {
        int8_t real;
        uint8_t base;
      } u_kick;
      u_kick.base = 0;
      u_kick.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->kick = u_kick.real;
      offset += sizeof(this->kick);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/SerialData"; };
    virtual const char * getMD5() override { return "97544cb7f0c0a6dab75c7914677b3f02"; };

  };

}
#endif
