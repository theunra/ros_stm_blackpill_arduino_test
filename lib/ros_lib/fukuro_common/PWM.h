#ifndef _ROS_fukuro_common_PWM_h
#define _ROS_fukuro_common_PWM_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class PWM : public ros::Msg
  {
    public:
      typedef float _m1_type;
      _m1_type m1;
      typedef float _m2_type;
      _m2_type m2;
      typedef float _m3_type;
      _m3_type m3;
      typedef float _dl_type;
      _dl_type dl;
      typedef float _dr_type;
      _dr_type dr;

    PWM():
      m1(0),
      m2(0),
      m3(0),
      dl(0),
      dr(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->m1);
      offset += serializeAvrFloat64(outbuffer + offset, this->m2);
      offset += serializeAvrFloat64(outbuffer + offset, this->m3);
      offset += serializeAvrFloat64(outbuffer + offset, this->dl);
      offset += serializeAvrFloat64(outbuffer + offset, this->dr);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->m1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->m2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->m3));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dl));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dr));
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/PWM"; };
    virtual const char * getMD5() override { return "58ac09ce70b43d400c963b6ae6abf81d"; };

  };

}
#endif
