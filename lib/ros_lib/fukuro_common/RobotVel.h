#ifndef _ROS_fukuro_common_RobotVel_h
#define _ROS_fukuro_common_RobotVel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class RobotVel : public ros::Msg
  {
    public:
      typedef float _free1_type;
      _free1_type free1;
      typedef float _free2_type;
      _free2_type free2;
      typedef float _free3_type;
      _free3_type free3;

    RobotVel():
      free1(0),
      free2(0),
      free3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_free1;
      u_free1.real = this->free1;
      *(outbuffer + offset + 0) = (u_free1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_free1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_free1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_free1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->free1);
      union {
        float real;
        uint32_t base;
      } u_free2;
      u_free2.real = this->free2;
      *(outbuffer + offset + 0) = (u_free2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_free2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_free2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_free2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->free2);
      union {
        float real;
        uint32_t base;
      } u_free3;
      u_free3.real = this->free3;
      *(outbuffer + offset + 0) = (u_free3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_free3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_free3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_free3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->free3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_free1;
      u_free1.base = 0;
      u_free1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_free1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_free1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_free1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->free1 = u_free1.real;
      offset += sizeof(this->free1);
      union {
        float real;
        uint32_t base;
      } u_free2;
      u_free2.base = 0;
      u_free2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_free2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_free2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_free2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->free2 = u_free2.real;
      offset += sizeof(this->free2);
      union {
        float real;
        uint32_t base;
      } u_free3;
      u_free3.base = 0;
      u_free3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_free3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_free3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_free3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->free3 = u_free3.real;
      offset += sizeof(this->free3);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/RobotVel"; };
    virtual const char * getMD5() override { return "5c8b02a70b5431ee21c709a8d3e87494"; };

  };

}
#endif
