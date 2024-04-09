#ifndef _ROS_fukuro_common_StaticObstacle_h
#define _ROS_fukuro_common_StaticObstacle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/Obstacle.h"

namespace fukuro_common
{

  class StaticObstacle : public ros::Msg
  {
    public:
      typedef fukuro_common::Obstacle _obstacle1_type;
      _obstacle1_type obstacle1;
      typedef fukuro_common::Obstacle _obstacle2_type;
      _obstacle2_type obstacle2;
      typedef fukuro_common::Obstacle _obstacle3_type;
      _obstacle3_type obstacle3;
      typedef fukuro_common::Obstacle _obstacle4_type;
      _obstacle4_type obstacle4;
      typedef fukuro_common::Obstacle _obstacle5_type;
      _obstacle5_type obstacle5;
      typedef fukuro_common::Obstacle _obstacle6_type;
      _obstacle6_type obstacle6;
      typedef fukuro_common::Obstacle _obstacle7_type;
      _obstacle7_type obstacle7;
      typedef fukuro_common::Obstacle _obstacle8_type;
      _obstacle8_type obstacle8;

    StaticObstacle():
      obstacle1(),
      obstacle2(),
      obstacle3(),
      obstacle4(),
      obstacle5(),
      obstacle6(),
      obstacle7(),
      obstacle8()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->obstacle1.serialize(outbuffer + offset);
      offset += this->obstacle2.serialize(outbuffer + offset);
      offset += this->obstacle3.serialize(outbuffer + offset);
      offset += this->obstacle4.serialize(outbuffer + offset);
      offset += this->obstacle5.serialize(outbuffer + offset);
      offset += this->obstacle6.serialize(outbuffer + offset);
      offset += this->obstacle7.serialize(outbuffer + offset);
      offset += this->obstacle8.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->obstacle1.deserialize(inbuffer + offset);
      offset += this->obstacle2.deserialize(inbuffer + offset);
      offset += this->obstacle3.deserialize(inbuffer + offset);
      offset += this->obstacle4.deserialize(inbuffer + offset);
      offset += this->obstacle5.deserialize(inbuffer + offset);
      offset += this->obstacle6.deserialize(inbuffer + offset);
      offset += this->obstacle7.deserialize(inbuffer + offset);
      offset += this->obstacle8.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/StaticObstacle"; };
    virtual const char * getMD5() override { return "46d3fb587aed8a021e47dcb530b200ee"; };

  };

}
#endif
