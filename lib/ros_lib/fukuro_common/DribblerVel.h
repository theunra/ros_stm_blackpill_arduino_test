#ifndef _ROS_fukuro_common_DribblerVel_h
#define _ROS_fukuro_common_DribblerVel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class DribblerVel : public ros::Msg
  {
    public:
      typedef float _d1_type;
      _d1_type d1;
      typedef float _d2_type;
      _d2_type d2;

    DribblerVel():
      d1(0),
      d2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_d1;
      u_d1.real = this->d1;
      *(outbuffer + offset + 0) = (u_d1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_d1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_d1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_d1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->d1);
      union {
        float real;
        uint32_t base;
      } u_d2;
      u_d2.real = this->d2;
      *(outbuffer + offset + 0) = (u_d2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_d2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_d2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_d2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->d2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_d1;
      u_d1.base = 0;
      u_d1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_d1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_d1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_d1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->d1 = u_d1.real;
      offset += sizeof(this->d1);
      union {
        float real;
        uint32_t base;
      } u_d2;
      u_d2.base = 0;
      u_d2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_d2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_d2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_d2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->d2 = u_d2.real;
      offset += sizeof(this->d2);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/DribblerVel"; };
    virtual const char * getMD5() override { return "1c78ad82c247783d0c3aa95ce147b845"; };

  };

}
#endif
