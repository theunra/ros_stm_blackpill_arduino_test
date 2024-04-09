#ifndef _ROS_fukuro_common_DribblerControl_h
#define _ROS_fukuro_common_DribblerControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class DribblerControl : public ros::Msg
  {
    public:
      typedef uint8_t _dir_in_type;
      _dir_in_type dir_in;
      typedef float _speed_type;
      _speed_type speed;

    DribblerControl():
      dir_in(0),
      speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->dir_in >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dir_in);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->dir_in =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->dir_in);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/DribblerControl"; };
    virtual const char * getMD5() override { return "d4af231b2c1c93c434a1a477fb94ba80"; };

  };

}
#endif
