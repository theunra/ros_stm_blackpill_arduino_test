#ifndef _ROS_SERVICE_LocalizationSrv_h
#define _ROS_SERVICE_LocalizationSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

static const char LOCALIZATIONSRV[] = "fukuro_common/LocalizationSrv";

  class LocalizationSrvRequest : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _w_type;
      _w_type w;
      typedef uint8_t _initial_pos_type;
      _initial_pos_type initial_pos;

    LocalizationSrvRequest():
      x(0),
      y(0),
      w(0),
      initial_pos(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->w);
      *(outbuffer + offset + 0) = (this->initial_pos >> (8 * 0)) & 0xFF;
      offset += sizeof(this->initial_pos);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->w));
      this->initial_pos =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->initial_pos);
     return offset;
    }

    virtual const char * getType() override { return LOCALIZATIONSRV; };
    virtual const char * getMD5() override { return "b4b2d4e2b93ce3abeef0af878ab6cd7b"; };

  };

  class LocalizationSrvResponse : public ros::Msg
  {
    public:
      typedef uint8_t _ok_type;
      _ok_type ok;

    LocalizationSrvResponse():
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

    virtual const char * getType() override { return LOCALIZATIONSRV; };
    virtual const char * getMD5() override { return "ebb43f57b7820ff999dc120ba80eb7d8"; };

  };

  class LocalizationSrv {
    public:
    typedef LocalizationSrvRequest Request;
    typedef LocalizationSrvResponse Response;
  };

}
#endif
