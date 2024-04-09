#ifndef _ROS_fukuro_common_Ball_h
#define _ROS_fukuro_common_Ball_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class Ball : public ros::Msg
  {
    public:
      typedef float _ball_x_type;
      _ball_x_type ball_x;
      typedef float _ball_y_type;
      _ball_y_type ball_y;
      typedef bool _is_visible_type;
      _is_visible_type is_visible;

    Ball():
      ball_x(0),
      ball_y(0),
      is_visible(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->ball_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->ball_y);
      union {
        bool real;
        uint8_t base;
      } u_is_visible;
      u_is_visible.real = this->is_visible;
      *(outbuffer + offset + 0) = (u_is_visible.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_visible);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ball_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ball_y));
      union {
        bool real;
        uint8_t base;
      } u_is_visible;
      u_is_visible.base = 0;
      u_is_visible.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_visible = u_is_visible.real;
      offset += sizeof(this->is_visible);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/Ball"; };
    virtual const char * getMD5() override { return "88ac6da9dfce2ccdcb4a5d2627e96b2f"; };

  };

}
#endif
