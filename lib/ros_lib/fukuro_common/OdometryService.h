#ifndef _ROS_SERVICE_OdometryService_h
#define _ROS_SERVICE_OdometryService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

static const char ODOMETRYSERVICE[] = "fukuro_common/OdometryService";

  class OdometryServiceRequest : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _w_type;
      _w_type w;

    OdometryServiceRequest():
      x(0),
      y(0),
      w(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->w);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->w));
     return offset;
    }

    virtual const char * getType() override { return ODOMETRYSERVICE; };
    virtual const char * getMD5() override { return "d4ac4ccb643ea4fbabe284bb1c6d7206"; };

  };

  class OdometryServiceResponse : public ros::Msg
  {
    public:
      typedef int64_t _ok_type;
      _ok_type ok;

    OdometryServiceResponse():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ok.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ok.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ok.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ok.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ok.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ok.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ok.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ok.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return ODOMETRYSERVICE; };
    virtual const char * getMD5() override { return "ffe45f316ca87fa4adf13cb9d40744eb"; };

  };

  class OdometryService {
    public:
    typedef OdometryServiceRequest Request;
    typedef OdometryServiceResponse Response;
  };

}
#endif
