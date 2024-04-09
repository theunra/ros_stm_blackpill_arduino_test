#ifndef _ROS_fukuro_common_OdometryInfo_h
#define _ROS_fukuro_common_OdometryInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace fukuro_common
{

  class OdometryInfo : public ros::Msg
  {
    public:
      typedef float _vx_type;
      _vx_type vx;
      typedef float _vy_type;
      _vy_type vy;
      typedef float _w_type;
      _w_type w;
      typedef geometry_msgs::Pose2D _position_type;
      _position_type position;
      typedef geometry_msgs::Pose2D _velocity_type;
      _velocity_type velocity;

    OdometryInfo():
      vx(0),
      vy(0),
      w(0),
      position(),
      velocity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->vx);
      offset += serializeAvrFloat64(outbuffer + offset, this->vy);
      offset += serializeAvrFloat64(outbuffer + offset, this->w);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->w));
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/OdometryInfo"; };
    virtual const char * getMD5() override { return "ba676638abfd6dd3d3cce86d90468aab"; };

  };

}
#endif
