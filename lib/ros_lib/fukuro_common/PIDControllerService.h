#ifndef _ROS_SERVICE_PIDControllerService_h
#define _ROS_SERVICE_PIDControllerService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

static const char PIDCONTROLLERSERVICE[] = "fukuro_common/PIDControllerService";

  class PIDControllerServiceRequest : public ros::Msg
  {
    public:
      typedef float _p_lin_type;
      _p_lin_type p_lin;
      typedef float _i_lin_type;
      _i_lin_type i_lin;
      typedef float _d_lin_type;
      _d_lin_type d_lin;
      typedef float _p_ang_type;
      _p_ang_type p_ang;
      typedef float _i_ang_type;
      _i_ang_type i_ang;
      typedef float _d_ang_type;
      _d_ang_type d_ang;
      typedef float _low_type;
      _low_type low;
      typedef float _high_type;
      _high_type high;

    PIDControllerServiceRequest():
      p_lin(0),
      i_lin(0),
      d_lin(0),
      p_ang(0),
      i_ang(0),
      d_ang(0),
      low(0),
      high(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->p_lin);
      offset += serializeAvrFloat64(outbuffer + offset, this->i_lin);
      offset += serializeAvrFloat64(outbuffer + offset, this->d_lin);
      offset += serializeAvrFloat64(outbuffer + offset, this->p_ang);
      offset += serializeAvrFloat64(outbuffer + offset, this->i_ang);
      offset += serializeAvrFloat64(outbuffer + offset, this->d_ang);
      offset += serializeAvrFloat64(outbuffer + offset, this->low);
      offset += serializeAvrFloat64(outbuffer + offset, this->high);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->p_lin));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i_lin));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d_lin));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->p_ang));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i_ang));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d_ang));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->low));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->high));
     return offset;
    }

    virtual const char * getType() override { return PIDCONTROLLERSERVICE; };
    virtual const char * getMD5() override { return "c27e635c932d5a3df5cec10f8ebe1233"; };

  };

  class PIDControllerServiceResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    PIDControllerServiceResponse():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return PIDCONTROLLERSERVICE; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class PIDControllerService {
    public:
    typedef PIDControllerServiceRequest Request;
    typedef PIDControllerServiceResponse Response;
  };

}
#endif
