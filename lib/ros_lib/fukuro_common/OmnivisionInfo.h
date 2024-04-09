#ifndef _ROS_fukuro_common_OmnivisionInfo_h
#define _ROS_fukuro_common_OmnivisionInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/Point2d.h"

namespace fukuro_common
{

  class OmnivisionInfo : public ros::Msg
  {
    public:
      typedef fukuro_common::Point2d _local_ball_type;
      _local_ball_type local_ball;
      typedef bool _ball_visible_type;
      _ball_visible_type ball_visible;
      typedef fukuro_common::Point2d _local_obstacle_type;
      _local_obstacle_type local_obstacle;
      typedef bool _obs_visible_type;
      _obs_visible_type obs_visible;
      typedef fukuro_common::Point2d _robot_friend_pos_type;
      _robot_friend_pos_type robot_friend_pos;
      typedef bool _friend_visible_type;
      _friend_visible_type friend_visible;

    OmnivisionInfo():
      local_ball(),
      ball_visible(0),
      local_obstacle(),
      obs_visible(0),
      robot_friend_pos(),
      friend_visible(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->local_ball.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_ball_visible;
      u_ball_visible.real = this->ball_visible;
      *(outbuffer + offset + 0) = (u_ball_visible.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ball_visible);
      offset += this->local_obstacle.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_obs_visible;
      u_obs_visible.real = this->obs_visible;
      *(outbuffer + offset + 0) = (u_obs_visible.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obs_visible);
      offset += this->robot_friend_pos.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_friend_visible;
      u_friend_visible.real = this->friend_visible;
      *(outbuffer + offset + 0) = (u_friend_visible.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->friend_visible);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->local_ball.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_ball_visible;
      u_ball_visible.base = 0;
      u_ball_visible.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ball_visible = u_ball_visible.real;
      offset += sizeof(this->ball_visible);
      offset += this->local_obstacle.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_obs_visible;
      u_obs_visible.base = 0;
      u_obs_visible.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->obs_visible = u_obs_visible.real;
      offset += sizeof(this->obs_visible);
      offset += this->robot_friend_pos.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_friend_visible;
      u_friend_visible.base = 0;
      u_friend_visible.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->friend_visible = u_friend_visible.real;
      offset += sizeof(this->friend_visible);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/OmnivisionInfo"; };
    virtual const char * getMD5() override { return "fba85346654e08337110412dda45e35e"; };

  };

}
#endif
