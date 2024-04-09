#ifndef _ROS_SERVICE_SpeedTuning_h
#define _ROS_SERVICE_SpeedTuning_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/Parameter.h"

namespace fukuro_common
{

static const char SPEEDTUNING[] = "fukuro_common/SpeedTuning";

  class SpeedTuningRequest : public ros::Msg
  {
    public:
      typedef fukuro_common::Parameter _linear_type;
      _linear_type linear;
      typedef fukuro_common::Parameter _angular_type;
      _angular_type angular;

    SpeedTuningRequest():
      linear(),
      angular()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->linear.serialize(outbuffer + offset);
      offset += this->angular.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->linear.deserialize(inbuffer + offset);
      offset += this->angular.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SPEEDTUNING; };
    virtual const char * getMD5() override { return "3094cde591fc0e253ec2416e29f6fff2"; };

  };

  class SpeedTuningResponse : public ros::Msg
  {
    public:
      typedef bool _tune_ok_type;
      _tune_ok_type tune_ok;

    SpeedTuningResponse():
      tune_ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_tune_ok;
      u_tune_ok.real = this->tune_ok;
      *(outbuffer + offset + 0) = (u_tune_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tune_ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_tune_ok;
      u_tune_ok.base = 0;
      u_tune_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tune_ok = u_tune_ok.real;
      offset += sizeof(this->tune_ok);
     return offset;
    }

    virtual const char * getType() override { return SPEEDTUNING; };
    virtual const char * getMD5() override { return "b731fe652071ec695a1ec7ac77e39ebe"; };

  };

  class SpeedTuning {
    public:
    typedef SpeedTuningRequest Request;
    typedef SpeedTuningResponse Response;
  };

}
#endif
