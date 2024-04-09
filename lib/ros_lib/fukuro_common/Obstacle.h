#ifndef _ROS_fukuro_common_Obstacle_h
#define _ROS_fukuro_common_Obstacle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/Point2d.h"

namespace fukuro_common
{

  class Obstacle : public ros::Msg
  {
    public:
      typedef fukuro_common::Point2d _pos_type;
      _pos_type pos;
      typedef float _r_type;
      _r_type r;
      typedef int8_t _shape_type;
      _shape_type shape;

    Obstacle():
      pos(),
      r(0),
      shape(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pos.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->r);
      union {
        int8_t real;
        uint8_t base;
      } u_shape;
      u_shape.real = this->shape;
      *(outbuffer + offset + 0) = (u_shape.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->shape);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pos.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->r));
      union {
        int8_t real;
        uint8_t base;
      } u_shape;
      u_shape.base = 0;
      u_shape.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->shape = u_shape.real;
      offset += sizeof(this->shape);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/Obstacle"; };
    virtual const char * getMD5() override { return "204658f3eba3518a7ff5338be777b1e8"; };

  };

}
#endif
