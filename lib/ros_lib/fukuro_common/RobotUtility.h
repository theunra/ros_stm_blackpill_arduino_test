#ifndef _ROS_fukuro_common_RobotUtility_h
#define _ROS_fukuro_common_RobotUtility_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class RobotUtility : public ros::Msg
  {
    public:
      typedef bool _ball_engage_type;
      _ball_engage_type ball_engage;
      typedef float _ball_distance_type;
      _ball_distance_type ball_distance;
      typedef bool _collision_type;
      _collision_type collision;
      typedef bool _ready_kick_type;
      _ready_kick_type ready_kick;

    RobotUtility():
      ball_engage(0),
      ball_distance(0),
      collision(0),
      ready_kick(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ball_engage;
      u_ball_engage.real = this->ball_engage;
      *(outbuffer + offset + 0) = (u_ball_engage.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ball_engage);
      union {
        float real;
        uint32_t base;
      } u_ball_distance;
      u_ball_distance.real = this->ball_distance;
      *(outbuffer + offset + 0) = (u_ball_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ball_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ball_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ball_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ball_distance);
      union {
        bool real;
        uint8_t base;
      } u_collision;
      u_collision.real = this->collision;
      *(outbuffer + offset + 0) = (u_collision.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->collision);
      union {
        bool real;
        uint8_t base;
      } u_ready_kick;
      u_ready_kick.real = this->ready_kick;
      *(outbuffer + offset + 0) = (u_ready_kick.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ready_kick);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ball_engage;
      u_ball_engage.base = 0;
      u_ball_engage.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ball_engage = u_ball_engage.real;
      offset += sizeof(this->ball_engage);
      union {
        float real;
        uint32_t base;
      } u_ball_distance;
      u_ball_distance.base = 0;
      u_ball_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ball_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ball_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ball_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ball_distance = u_ball_distance.real;
      offset += sizeof(this->ball_distance);
      union {
        bool real;
        uint8_t base;
      } u_collision;
      u_collision.base = 0;
      u_collision.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->collision = u_collision.real;
      offset += sizeof(this->collision);
      union {
        bool real;
        uint8_t base;
      } u_ready_kick;
      u_ready_kick.base = 0;
      u_ready_kick.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ready_kick = u_ready_kick.real;
      offset += sizeof(this->ready_kick);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/RobotUtility"; };
    virtual const char * getMD5() override { return "aaa97d54de402a9e7dc9f3a4b32660e0"; };

  };

}
#endif
