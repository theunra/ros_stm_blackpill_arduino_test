#ifndef _ROS_fukuro_common_Parameter_h
#define _ROS_fukuro_common_Parameter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class Parameter : public ros::Msg
  {
    public:
      typedef float _kp_type;
      _kp_type kp;
      typedef float _ki_type;
      _ki_type ki;
      typedef float _kd_type;
      _kd_type kd;

    Parameter():
      kp(0),
      ki(0),
      kd(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->kp);
      offset += serializeAvrFloat64(outbuffer + offset, this->ki);
      offset += serializeAvrFloat64(outbuffer + offset, this->kd);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kp));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ki));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kd));
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/Parameter"; };
    virtual const char * getMD5() override { return "972f4074b1c05b4e6ef321f04d38ec3f"; };

  };

}
#endif
