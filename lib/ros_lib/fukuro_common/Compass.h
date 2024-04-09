#ifndef _ROS_fukuro_common_Compass_h
#define _ROS_fukuro_common_Compass_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class Compass : public ros::Msg
  {
    public:
      typedef float _cmps_type;
      _cmps_type cmps;

    Compass():
      cmps(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->cmps);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cmps));
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/Compass"; };
    virtual const char * getMD5() override { return "9fef2f746f54270aba8e56b443ad3f25"; };

  };

}
#endif
