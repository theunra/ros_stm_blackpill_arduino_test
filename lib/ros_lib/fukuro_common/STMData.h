#ifndef _ROS_fukuro_common_STMData_h
#define _ROS_fukuro_common_STMData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/MotorVel.h"
#include "fukuro_common/RobotVel.h"

namespace fukuro_common
{

  class STMData : public ros::Msg
  {
    public:
      typedef fukuro_common::MotorVel _encoder_type;
      _encoder_type encoder;
      typedef fukuro_common::RobotVel _freeenc_type;
      _freeenc_type freeenc;
      typedef bool _ready_kick_type;
      _ready_kick_type ready_kick;
      typedef bool _ir_type;
      _ir_type ir;
      typedef float _distance_type;
      _distance_type distance;
      typedef float _yaw_type;
      _yaw_type yaw;

    STMData():
      encoder(),
      freeenc(),
      ready_kick(0),
      ir(0),
      distance(0),
      yaw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->encoder.serialize(outbuffer + offset);
      offset += this->freeenc.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_ready_kick;
      u_ready_kick.real = this->ready_kick;
      *(outbuffer + offset + 0) = (u_ready_kick.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ready_kick);
      union {
        bool real;
        uint8_t base;
      } u_ir;
      u_ir.real = this->ir;
      *(outbuffer + offset + 0) = (u_ir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ir);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->encoder.deserialize(inbuffer + offset);
      offset += this->freeenc.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_ready_kick;
      u_ready_kick.base = 0;
      u_ready_kick.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ready_kick = u_ready_kick.real;
      offset += sizeof(this->ready_kick);
      union {
        bool real;
        uint8_t base;
      } u_ir;
      u_ir.base = 0;
      u_ir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ir = u_ir.real;
      offset += sizeof(this->ir);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/STMData"; };
    virtual const char * getMD5() override { return "9a6d018091262233961140398611f145"; };

  };

}
#endif
