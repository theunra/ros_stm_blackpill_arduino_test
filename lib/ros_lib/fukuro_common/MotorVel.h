#ifndef _ROS_fukuro_common_MotorVel_h
#define _ROS_fukuro_common_MotorVel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class MotorVel : public ros::Msg
  {
    public:
      typedef float _m1_type;
      _m1_type m1;
      typedef float _m2_type;
      _m2_type m2;
      typedef float _m3_type;
      _m3_type m3;

    MotorVel():
      m1(0),
      m2(0),
      m3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_m1;
      u_m1.real = this->m1;
      *(outbuffer + offset + 0) = (u_m1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->m1);
      union {
        float real;
        uint32_t base;
      } u_m2;
      u_m2.real = this->m2;
      *(outbuffer + offset + 0) = (u_m2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->m2);
      union {
        float real;
        uint32_t base;
      } u_m3;
      u_m3.real = this->m3;
      *(outbuffer + offset + 0) = (u_m3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->m3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_m1;
      u_m1.base = 0;
      u_m1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->m1 = u_m1.real;
      offset += sizeof(this->m1);
      union {
        float real;
        uint32_t base;
      } u_m2;
      u_m2.base = 0;
      u_m2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->m2 = u_m2.real;
      offset += sizeof(this->m2);
      union {
        float real;
        uint32_t base;
      } u_m3;
      u_m3.base = 0;
      u_m3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->m3 = u_m3.real;
      offset += sizeof(this->m3);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/MotorVel"; };
    virtual const char * getMD5() override { return "a86e25d23be69cefa1d2e044fba11b0c"; };

  };

}
#endif
