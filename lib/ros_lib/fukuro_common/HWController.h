#ifndef _ROS_fukuro_common_HWController_h
#define _ROS_fukuro_common_HWController_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/Encoder.h"
#include "fukuro_common/PWM.h"
#include "fukuro_common/Compass.h"
#include "geometry_msgs/Pose2D.h"

namespace fukuro_common
{

  class HWController : public ros::Msg
  {
    public:
      typedef fukuro_common::Encoder _encoder_type;
      _encoder_type encoder;
      typedef fukuro_common::Encoder _freewheel_type;
      _freewheel_type freewheel;
      typedef fukuro_common::PWM _pwm_type;
      _pwm_type pwm;
      typedef fukuro_common::Compass _compass_type;
      _compass_type compass;
      typedef int8_t _ir_type;
      _ir_type ir;
      typedef geometry_msgs::Pose2D _vel_type;
      _vel_type vel;
      typedef geometry_msgs::Pose2D _vel_cmd_type;
      _vel_cmd_type vel_cmd;

    HWController():
      encoder(),
      freewheel(),
      pwm(),
      compass(),
      ir(0),
      vel(),
      vel_cmd()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->encoder.serialize(outbuffer + offset);
      offset += this->freewheel.serialize(outbuffer + offset);
      offset += this->pwm.serialize(outbuffer + offset);
      offset += this->compass.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_ir;
      u_ir.real = this->ir;
      *(outbuffer + offset + 0) = (u_ir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ir);
      offset += this->vel.serialize(outbuffer + offset);
      offset += this->vel_cmd.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->encoder.deserialize(inbuffer + offset);
      offset += this->freewheel.deserialize(inbuffer + offset);
      offset += this->pwm.deserialize(inbuffer + offset);
      offset += this->compass.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_ir;
      u_ir.base = 0;
      u_ir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ir = u_ir.real;
      offset += sizeof(this->ir);
      offset += this->vel.deserialize(inbuffer + offset);
      offset += this->vel_cmd.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/HWController"; };
    virtual const char * getMD5() override { return "0897f331a92bc0854a645fdfb9d5ab2a"; };

  };

}
#endif
