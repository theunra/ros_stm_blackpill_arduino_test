#ifndef _ROS_SERVICE_PlannerInfoSrv_h
#define _ROS_SERVICE_PlannerInfoSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

static const char PLANNERINFOSRV[] = "fukuro_common/PlannerInfoSrv";

  class PlannerInfoSrvRequest : public ros::Msg
  {
    public:
      typedef float _width_type;
      _width_type width;
      typedef float _height_type;
      _height_type height;
      typedef float _grid_size_type;
      _grid_size_type grid_size;

    PlannerInfoSrvRequest():
      width(0),
      height(0),
      grid_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->width);
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      offset += serializeAvrFloat64(outbuffer + offset, this->grid_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->width));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->grid_size));
     return offset;
    }

    virtual const char * getType() override { return PLANNERINFOSRV; };
    virtual const char * getMD5() override { return "802049f50763bc7219af4576c0df7321"; };

  };

  class PlannerInfoSrvResponse : public ros::Msg
  {
    public:
      typedef uint8_t _ok_type;
      _ok_type ok;

    PlannerInfoSrvResponse():
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

    virtual const char * getType() override { return PLANNERINFOSRV; };
    virtual const char * getMD5() override { return "ebb43f57b7820ff999dc120ba80eb7d8"; };

  };

  class PlannerInfoSrv {
    public:
    typedef PlannerInfoSrvRequest Request;
    typedef PlannerInfoSrvResponse Response;
  };

}
#endif
