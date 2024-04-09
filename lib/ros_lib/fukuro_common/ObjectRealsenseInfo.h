#ifndef _ROS_fukuro_common_ObjectRealsenseInfo_h
#define _ROS_fukuro_common_ObjectRealsenseInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class ObjectRealsenseInfo : public ros::Msg
  {
    public:
      typedef float _degree_type;
      _degree_type degree;
      typedef bool _centered_type;
      _centered_type centered;
      typedef bool _on_screen_type;
      _on_screen_type on_screen;
      typedef float _local_x_type;
      _local_x_type local_x;

    ObjectRealsenseInfo():
      degree(0),
      centered(0),
      on_screen(0),
      local_x(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_degree;
      u_degree.real = this->degree;
      *(outbuffer + offset + 0) = (u_degree.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_degree.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_degree.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_degree.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->degree);
      union {
        bool real;
        uint8_t base;
      } u_centered;
      u_centered.real = this->centered;
      *(outbuffer + offset + 0) = (u_centered.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->centered);
      union {
        bool real;
        uint8_t base;
      } u_on_screen;
      u_on_screen.real = this->on_screen;
      *(outbuffer + offset + 0) = (u_on_screen.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->on_screen);
      union {
        float real;
        uint32_t base;
      } u_local_x;
      u_local_x.real = this->local_x;
      *(outbuffer + offset + 0) = (u_local_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_local_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_local_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_local_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->local_x);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_degree;
      u_degree.base = 0;
      u_degree.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_degree.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_degree.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_degree.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->degree = u_degree.real;
      offset += sizeof(this->degree);
      union {
        bool real;
        uint8_t base;
      } u_centered;
      u_centered.base = 0;
      u_centered.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->centered = u_centered.real;
      offset += sizeof(this->centered);
      union {
        bool real;
        uint8_t base;
      } u_on_screen;
      u_on_screen.base = 0;
      u_on_screen.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->on_screen = u_on_screen.real;
      offset += sizeof(this->on_screen);
      union {
        float real;
        uint32_t base;
      } u_local_x;
      u_local_x.base = 0;
      u_local_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_local_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_local_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_local_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->local_x = u_local_x.real;
      offset += sizeof(this->local_x);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/ObjectRealsenseInfo"; };
    virtual const char * getMD5() override { return "07c986774802f95e57abb77adff251b1"; };

  };

}
#endif
