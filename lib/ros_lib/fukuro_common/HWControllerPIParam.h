#ifndef _ROS_SERVICE_HWControllerPIParam_h
#define _ROS_SERVICE_HWControllerPIParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/MotorParameter.h"

namespace fukuro_common
{

static const char HWCONTROLLERPIPARAM[] = "fukuro_common/HWControllerPIParam";

  class HWControllerPIParamRequest : public ros::Msg
  {
    public:
      typedef fukuro_common::MotorParameter _k_type;
      _k_type k;

    HWControllerPIParamRequest():
      k()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->k.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->k.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return HWCONTROLLERPIPARAM; };
    virtual const char * getMD5() override { return "71a4035fa6895755720b4427569534e6"; };

  };

  class HWControllerPIParamResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    HWControllerPIParamResponse():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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

    virtual const char * getType() override { return HWCONTROLLERPIPARAM; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class HWControllerPIParam {
    public:
    typedef HWControllerPIParamRequest Request;
    typedef HWControllerPIParamResponse Response;
  };

}
#endif
