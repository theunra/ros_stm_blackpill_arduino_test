#ifndef _ROS_SERVICE_HWControllerParam_h
#define _ROS_SERVICE_HWControllerParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/MotorParameter.h"

namespace fukuro_common
{

static const char HWCONTROLLERPARAM[] = "fukuro_common/HWControllerParam";

  class HWControllerParamRequest : public ros::Msg
  {
    public:
      typedef fukuro_common::MotorParameter _cw_type;
      _cw_type cw;
      typedef fukuro_common::MotorParameter _ccw_type;
      _ccw_type ccw;

    HWControllerParamRequest():
      cw(),
      ccw()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->cw.serialize(outbuffer + offset);
      offset += this->ccw.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->cw.deserialize(inbuffer + offset);
      offset += this->ccw.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return HWCONTROLLERPARAM; };
    virtual const char * getMD5() override { return "cebca7b8ef71cbcc546a13f7adc0c415"; };

  };

  class HWControllerParamResponse : public ros::Msg
  {
    public:
      typedef fukuro_common::MotorParameter _cw_type;
      _cw_type cw;
      typedef fukuro_common::MotorParameter _ccw_type;
      _ccw_type ccw;
      typedef bool _ok_type;
      _ok_type ok;

    HWControllerParamResponse():
      cw(),
      ccw(),
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->cw.serialize(outbuffer + offset);
      offset += this->ccw.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->cw.deserialize(inbuffer + offset);
      offset += this->ccw.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return HWCONTROLLERPARAM; };
    virtual const char * getMD5() override { return "ff0b5bf0e538bb3b55d6c840655838b7"; };

  };

  class HWControllerParam {
    public:
    typedef HWControllerParamRequest Request;
    typedef HWControllerParamResponse Response;
  };

}
#endif
