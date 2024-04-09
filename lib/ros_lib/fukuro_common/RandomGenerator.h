#ifndef _ROS_fukuro_common_RandomGenerator_h
#define _ROS_fukuro_common_RandomGenerator_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class RandomGenerator : public ros::Msg
  {
    public:
      typedef float _yx_type;
      _yx_type yx;
      typedef float _yy_type;
      _yy_type yy;
      typedef float _yz_type;
      _yz_type yz;
      typedef float _yd1_type;
      _yd1_type yd1;
      typedef float _yd2_type;
      _yd2_type yd2;
      typedef float _ym1_type;
      _ym1_type ym1;
      typedef float _ym2_type;
      _ym2_type ym2;
      typedef float _ym3_type;
      _ym3_type ym3;

    RandomGenerator():
      yx(0),
      yy(0),
      yz(0),
      yd1(0),
      yd2(0),
      ym1(0),
      ym2(0),
      ym3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->yx);
      offset += serializeAvrFloat64(outbuffer + offset, this->yy);
      offset += serializeAvrFloat64(outbuffer + offset, this->yz);
      offset += serializeAvrFloat64(outbuffer + offset, this->yd1);
      offset += serializeAvrFloat64(outbuffer + offset, this->yd2);
      offset += serializeAvrFloat64(outbuffer + offset, this->ym1);
      offset += serializeAvrFloat64(outbuffer + offset, this->ym2);
      offset += serializeAvrFloat64(outbuffer + offset, this->ym3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yz));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yd1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yd2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ym1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ym2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ym3));
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/RandomGenerator"; };
    virtual const char * getMD5() override { return "5ab015667f392bb9eb5c657ae0523c45"; };

  };

}
#endif
