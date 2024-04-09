#ifndef _ROS_SERVICE_RealsenseDistanceService_h
#define _ROS_SERVICE_RealsenseDistanceService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

static const char REALSENSEDISTANCESERVICE[] = "fukuro_common/RealsenseDistanceService";

  class RealsenseDistanceServiceRequest : public ros::Msg
  {
    public:
      typedef float _ok_type;
      _ok_type ok;

    RealsenseDistanceServiceRequest():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ok.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ok.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ok.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ok.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ok.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ok.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return REALSENSEDISTANCESERVICE; };
    virtual const char * getMD5() override { return "2991260901f1e54fdc610afd7d79eeb1"; };

  };

  class RealsenseDistanceServiceResponse : public ros::Msg
  {
    public:
      typedef float _distancekanan_type;
      _distancekanan_type distancekanan;
      typedef float _distancekiri_type;
      _distancekiri_type distancekiri;

    RealsenseDistanceServiceResponse():
      distancekanan(0),
      distancekiri(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_distancekanan;
      u_distancekanan.real = this->distancekanan;
      *(outbuffer + offset + 0) = (u_distancekanan.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distancekanan.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distancekanan.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distancekanan.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distancekanan);
      union {
        float real;
        uint32_t base;
      } u_distancekiri;
      u_distancekiri.real = this->distancekiri;
      *(outbuffer + offset + 0) = (u_distancekiri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distancekiri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distancekiri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distancekiri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distancekiri);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_distancekanan;
      u_distancekanan.base = 0;
      u_distancekanan.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distancekanan.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distancekanan.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distancekanan.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distancekanan = u_distancekanan.real;
      offset += sizeof(this->distancekanan);
      union {
        float real;
        uint32_t base;
      } u_distancekiri;
      u_distancekiri.base = 0;
      u_distancekiri.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distancekiri.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distancekiri.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distancekiri.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distancekiri = u_distancekiri.real;
      offset += sizeof(this->distancekiri);
     return offset;
    }

    virtual const char * getType() override { return REALSENSEDISTANCESERVICE; };
    virtual const char * getMD5() override { return "82e18ed449198e5bd7e9163a7376d888"; };

  };

  class RealsenseDistanceService {
    public:
    typedef RealsenseDistanceServiceRequest Request;
    typedef RealsenseDistanceServiceResponse Response;
  };

}
#endif
