#ifndef _ROS_SERVICE_HWControllerAutotuning_h
#define _ROS_SERVICE_HWControllerAutotuning_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

static const char HWCONTROLLERAUTOTUNING[] = "fukuro_common/HWControllerAutotuning";

  class HWControllerAutotuningRequest : public ros::Msg
  {
    public:
      typedef float _setpoint_type;
      _setpoint_type setpoint;

    HWControllerAutotuningRequest():
      setpoint(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint));
     return offset;
    }

    virtual const char * getType() override { return HWCONTROLLERAUTOTUNING; };
    virtual const char * getMD5() override { return "8a299d01e21b4327e6da9991f27e5d62"; };

  };

  class HWControllerAutotuningResponse : public ros::Msg
  {
    public:
      typedef int64_t _ok_type;
      _ok_type ok;

    HWControllerAutotuningResponse():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ok.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ok.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ok.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ok.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ok.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ok.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ok.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return HWCONTROLLERAUTOTUNING; };
    virtual const char * getMD5() override { return "ffe45f316ca87fa4adf13cb9d40744eb"; };

  };

  class HWControllerAutotuning {
    public:
    typedef HWControllerAutotuningRequest Request;
    typedef HWControllerAutotuningResponse Response;
  };

}
#endif
