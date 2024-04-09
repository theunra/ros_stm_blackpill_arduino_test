#ifndef _ROS_fukuro_common_Obstacles_h
#define _ROS_fukuro_common_Obstacles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/Obstacle.h"

namespace fukuro_common
{

  class Obstacles : public ros::Msg
  {
    public:
      uint32_t obs_length;
      typedef fukuro_common::Obstacle _obs_type;
      _obs_type st_obs;
      _obs_type * obs;

    Obstacles():
      obs_length(0), st_obs(), obs(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->obs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_length);
      for( uint32_t i = 0; i < obs_length; i++){
      offset += this->obs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t obs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obs_length);
      if(obs_lengthT > obs_length)
        this->obs = (fukuro_common::Obstacle*)realloc(this->obs, obs_lengthT * sizeof(fukuro_common::Obstacle));
      obs_length = obs_lengthT;
      for( uint32_t i = 0; i < obs_length; i++){
      offset += this->st_obs.deserialize(inbuffer + offset);
        memcpy( &(this->obs[i]), &(this->st_obs), sizeof(fukuro_common::Obstacle));
      }
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/Obstacles"; };
    virtual const char * getMD5() override { return "3a9d0234d57573448b583f3223c799a5"; };

  };

}
#endif
