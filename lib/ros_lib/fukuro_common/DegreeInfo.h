#ifndef _ROS_fukuro_common_DegreeInfo_h
#define _ROS_fukuro_common_DegreeInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/Point2d.h"

namespace fukuro_common
{

  class DegreeInfo : public ros::Msg
  {
    public:
      typedef float _target_degree_type;
      _target_degree_type target_degree;
      typedef bool _target_centered_type;
      _target_centered_type target_centered;
      typedef bool _target_on_screen_type;
      _target_on_screen_type target_on_screen;
      typedef fukuro_common::Point2d _coords_type;
      _coords_type coords;

    DegreeInfo():
      target_degree(0),
      target_centered(0),
      target_on_screen(0),
      coords()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_target_degree;
      u_target_degree.real = this->target_degree;
      *(outbuffer + offset + 0) = (u_target_degree.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_degree.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_degree.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_degree.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_degree);
      union {
        bool real;
        uint8_t base;
      } u_target_centered;
      u_target_centered.real = this->target_centered;
      *(outbuffer + offset + 0) = (u_target_centered.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->target_centered);
      union {
        bool real;
        uint8_t base;
      } u_target_on_screen;
      u_target_on_screen.real = this->target_on_screen;
      *(outbuffer + offset + 0) = (u_target_on_screen.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->target_on_screen);
      offset += this->coords.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_target_degree;
      u_target_degree.base = 0;
      u_target_degree.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_degree.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_degree.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_degree.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_degree = u_target_degree.real;
      offset += sizeof(this->target_degree);
      union {
        bool real;
        uint8_t base;
      } u_target_centered;
      u_target_centered.base = 0;
      u_target_centered.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->target_centered = u_target_centered.real;
      offset += sizeof(this->target_centered);
      union {
        bool real;
        uint8_t base;
      } u_target_on_screen;
      u_target_on_screen.base = 0;
      u_target_on_screen.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->target_on_screen = u_target_on_screen.real;
      offset += sizeof(this->target_on_screen);
      offset += this->coords.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/DegreeInfo"; };
    virtual const char * getMD5() override { return "58e3422e6777df14f471211116a25425"; };

  };

}
#endif
