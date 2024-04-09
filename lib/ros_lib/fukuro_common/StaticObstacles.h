#ifndef _ROS_SERVICE_StaticObstacles_h
#define _ROS_SERVICE_StaticObstacles_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

static const char STATICOBSTACLES[] = "fukuro_common/StaticObstacles";

  class StaticObstaclesRequest : public ros::Msg
  {
    public:
      typedef bool _obstacle1_type;
      _obstacle1_type obstacle1;
      typedef bool _obstacle2_type;
      _obstacle2_type obstacle2;
      typedef bool _obstacle3_type;
      _obstacle3_type obstacle3;
      typedef bool _obstacle4_type;
      _obstacle4_type obstacle4;
      typedef bool _obstacle5_type;
      _obstacle5_type obstacle5;
      typedef bool _obstacle6_type;
      _obstacle6_type obstacle6;
      typedef bool _obstacle7_type;
      _obstacle7_type obstacle7;
      typedef bool _obstacle8_type;
      _obstacle8_type obstacle8;
      typedef bool _obstacle_kiper_type;
      _obstacle_kiper_type obstacle_kiper;

    StaticObstaclesRequest():
      obstacle1(0),
      obstacle2(0),
      obstacle3(0),
      obstacle4(0),
      obstacle5(0),
      obstacle6(0),
      obstacle7(0),
      obstacle8(0),
      obstacle_kiper(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_obstacle1;
      u_obstacle1.real = this->obstacle1;
      *(outbuffer + offset + 0) = (u_obstacle1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacle1);
      union {
        bool real;
        uint8_t base;
      } u_obstacle2;
      u_obstacle2.real = this->obstacle2;
      *(outbuffer + offset + 0) = (u_obstacle2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacle2);
      union {
        bool real;
        uint8_t base;
      } u_obstacle3;
      u_obstacle3.real = this->obstacle3;
      *(outbuffer + offset + 0) = (u_obstacle3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacle3);
      union {
        bool real;
        uint8_t base;
      } u_obstacle4;
      u_obstacle4.real = this->obstacle4;
      *(outbuffer + offset + 0) = (u_obstacle4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacle4);
      union {
        bool real;
        uint8_t base;
      } u_obstacle5;
      u_obstacle5.real = this->obstacle5;
      *(outbuffer + offset + 0) = (u_obstacle5.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacle5);
      union {
        bool real;
        uint8_t base;
      } u_obstacle6;
      u_obstacle6.real = this->obstacle6;
      *(outbuffer + offset + 0) = (u_obstacle6.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacle6);
      union {
        bool real;
        uint8_t base;
      } u_obstacle7;
      u_obstacle7.real = this->obstacle7;
      *(outbuffer + offset + 0) = (u_obstacle7.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacle7);
      union {
        bool real;
        uint8_t base;
      } u_obstacle8;
      u_obstacle8.real = this->obstacle8;
      *(outbuffer + offset + 0) = (u_obstacle8.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacle8);
      union {
        bool real;
        uint8_t base;
      } u_obstacle_kiper;
      u_obstacle_kiper.real = this->obstacle_kiper;
      *(outbuffer + offset + 0) = (u_obstacle_kiper.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacle_kiper);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_obstacle1;
      u_obstacle1.base = 0;
      u_obstacle1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->obstacle1 = u_obstacle1.real;
      offset += sizeof(this->obstacle1);
      union {
        bool real;
        uint8_t base;
      } u_obstacle2;
      u_obstacle2.base = 0;
      u_obstacle2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->obstacle2 = u_obstacle2.real;
      offset += sizeof(this->obstacle2);
      union {
        bool real;
        uint8_t base;
      } u_obstacle3;
      u_obstacle3.base = 0;
      u_obstacle3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->obstacle3 = u_obstacle3.real;
      offset += sizeof(this->obstacle3);
      union {
        bool real;
        uint8_t base;
      } u_obstacle4;
      u_obstacle4.base = 0;
      u_obstacle4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->obstacle4 = u_obstacle4.real;
      offset += sizeof(this->obstacle4);
      union {
        bool real;
        uint8_t base;
      } u_obstacle5;
      u_obstacle5.base = 0;
      u_obstacle5.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->obstacle5 = u_obstacle5.real;
      offset += sizeof(this->obstacle5);
      union {
        bool real;
        uint8_t base;
      } u_obstacle6;
      u_obstacle6.base = 0;
      u_obstacle6.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->obstacle6 = u_obstacle6.real;
      offset += sizeof(this->obstacle6);
      union {
        bool real;
        uint8_t base;
      } u_obstacle7;
      u_obstacle7.base = 0;
      u_obstacle7.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->obstacle7 = u_obstacle7.real;
      offset += sizeof(this->obstacle7);
      union {
        bool real;
        uint8_t base;
      } u_obstacle8;
      u_obstacle8.base = 0;
      u_obstacle8.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->obstacle8 = u_obstacle8.real;
      offset += sizeof(this->obstacle8);
      union {
        bool real;
        uint8_t base;
      } u_obstacle_kiper;
      u_obstacle_kiper.base = 0;
      u_obstacle_kiper.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->obstacle_kiper = u_obstacle_kiper.real;
      offset += sizeof(this->obstacle_kiper);
     return offset;
    }

    virtual const char * getType() override { return STATICOBSTACLES; };
    virtual const char * getMD5() override { return "c73a535d4322a594587f130ce0daad38"; };

  };

  class StaticObstaclesResponse : public ros::Msg
  {
    public:
      typedef uint8_t _ok_type;
      _ok_type ok;

    StaticObstaclesResponse():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ok >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->ok =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return STATICOBSTACLES; };
    virtual const char * getMD5() override { return "ebb43f57b7820ff999dc120ba80eb7d8"; };

  };

  class StaticObstacles {
    public:
    typedef StaticObstaclesRequest Request;
    typedef StaticObstaclesResponse Response;
  };

}
#endif
