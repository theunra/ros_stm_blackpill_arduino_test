#ifndef _ROS_fukuro_common_HWControllerManual_h
#define _ROS_fukuro_common_HWControllerManual_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class HWControllerManual : public ros::Msg
  {
    public:
      typedef float _vx_type;
      _vx_type vx;
      typedef float _vy_type;
      _vy_type vy;
      typedef float _w_type;
      _w_type w;

    HWControllerManual():
      vx(0),
      vy(0),
      w(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->vx);
      offset += serializeAvrFloat64(outbuffer + offset, this->vy);
      offset += serializeAvrFloat64(outbuffer + offset, this->w);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->w));
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/HWControllerManual"; };
    virtual const char * getMD5() override { return "461e74593b26c77a7c97f00fe82c6d79"; };

  };

}
#endif
