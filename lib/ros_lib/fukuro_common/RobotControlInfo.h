#ifndef _ROS_fukuro_common_RobotControlInfo_h
#define _ROS_fukuro_common_RobotControlInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace fukuro_common
{

  class RobotControlInfo : public ros::Msg
  {
    public:
      typedef float _error_radius_type;
      _error_radius_type error_radius;
      typedef float _error_angle_type;
      _error_angle_type error_angle;
      typedef float _d_error_radius_type;
      _d_error_radius_type d_error_radius;
      typedef float _d_error_angle_type;
      _d_error_angle_type d_error_angle;
      typedef geometry_msgs::Pose2D _setpoint_type;
      _setpoint_type setpoint;
      typedef bool _is_plan_type;
      _is_plan_type is_plan;
      typedef bool _is_local_type;
      _is_local_type is_local;

    RobotControlInfo():
      error_radius(0),
      error_angle(0),
      d_error_radius(0),
      d_error_angle(0),
      setpoint(),
      is_plan(0),
      is_local(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->error_radius);
      offset += serializeAvrFloat64(outbuffer + offset, this->error_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->d_error_radius);
      offset += serializeAvrFloat64(outbuffer + offset, this->d_error_angle);
      offset += this->setpoint.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_plan;
      u_is_plan.real = this->is_plan;
      *(outbuffer + offset + 0) = (u_is_plan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_plan);
      union {
        bool real;
        uint8_t base;
      } u_is_local;
      u_is_local.real = this->is_local;
      *(outbuffer + offset + 0) = (u_is_local.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_local);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->error_radius));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->error_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d_error_radius));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d_error_angle));
      offset += this->setpoint.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_plan;
      u_is_plan.base = 0;
      u_is_plan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_plan = u_is_plan.real;
      offset += sizeof(this->is_plan);
      union {
        bool real;
        uint8_t base;
      } u_is_local;
      u_is_local.base = 0;
      u_is_local.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_local = u_is_local.real;
      offset += sizeof(this->is_local);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/RobotControlInfo"; };
    virtual const char * getMD5() override { return "61119e8a24c6d3be85229e0144bd84c7"; };

  };

}
#endif
