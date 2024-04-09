#ifndef _ROS_fukuro_common_Angle_h
#define _ROS_fukuro_common_Angle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class Angle : public ros::Msg
  {
    public:
      typedef float _theta_type;
      _theta_type theta;
      typedef float _rad_type;
      _rad_type rad;

    Angle():
      theta(0),
      rad(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->theta);
      offset += serializeAvrFloat64(outbuffer + offset, this->rad);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->theta));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rad));
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/Angle"; };
    virtual const char * getMD5() override { return "3a2f5a7d9a3c91939c8d1626290be18b"; };

  };

}
#endif
