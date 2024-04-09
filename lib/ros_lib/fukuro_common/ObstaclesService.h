#ifndef _ROS_SERVICE_ObstaclesService_h
#define _ROS_SERVICE_ObstaclesService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/Point2d.h"

namespace fukuro_common
{

static const char OBSTACLESSERVICE[] = "fukuro_common/ObstaclesService";

  class ObstaclesServiceRequest : public ros::Msg
  {
    public:
      typedef int64_t _total_type;
      _total_type total;
      uint32_t obstacles_length;
      typedef fukuro_common::Point2d _obstacles_type;
      _obstacles_type st_obstacles;
      _obstacles_type * obstacles;

    ObstaclesServiceRequest():
      total(0),
      obstacles_length(0), st_obstacles(), obstacles(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_total;
      u_total.real = this->total;
      *(outbuffer + offset + 0) = (u_total.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_total.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_total.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_total.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_total.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->total);
      *(outbuffer + offset + 0) = (this->obstacles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obstacles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obstacles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obstacles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obstacles_length);
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->obstacles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_total;
      u_total.base = 0;
      u_total.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_total.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_total.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_total.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_total.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->total = u_total.real;
      offset += sizeof(this->total);
      uint32_t obstacles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obstacles_length);
      if(obstacles_lengthT > obstacles_length)
        this->obstacles = (fukuro_common::Point2d*)realloc(this->obstacles, obstacles_lengthT * sizeof(fukuro_common::Point2d));
      obstacles_length = obstacles_lengthT;
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->st_obstacles.deserialize(inbuffer + offset);
        memcpy( &(this->obstacles[i]), &(this->st_obstacles), sizeof(fukuro_common::Point2d));
      }
     return offset;
    }

    virtual const char * getType() override { return OBSTACLESSERVICE; };
    virtual const char * getMD5() override { return "907b339499491383a73548a99de15df6"; };

  };

  class ObstaclesServiceResponse : public ros::Msg
  {
    public:
      typedef uint8_t _ok_type;
      _ok_type ok;

    ObstaclesServiceResponse():
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

    virtual const char * getType() override { return OBSTACLESSERVICE; };
    virtual const char * getMD5() override { return "ebb43f57b7820ff999dc120ba80eb7d8"; };

  };

  class ObstaclesService {
    public:
    typedef ObstaclesServiceRequest Request;
    typedef ObstaclesServiceResponse Response;
  };

}
#endif
