#ifndef _ROS_SERVICE_Shoot_h
#define _ROS_SERVICE_Shoot_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

static const char SHOOT[] = "fukuro_common/Shoot";

  class ShootRequest : public ros::Msg
  {
    public:
      typedef uint8_t _kick_request_type;
      _kick_request_type kick_request;
      typedef uint16_t _kick_power_type;
      _kick_power_type kick_power;

    ShootRequest():
      kick_request(0),
      kick_power(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->kick_request >> (8 * 0)) & 0xFF;
      offset += sizeof(this->kick_request);
      *(outbuffer + offset + 0) = (this->kick_power >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->kick_power >> (8 * 1)) & 0xFF;
      offset += sizeof(this->kick_power);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->kick_request =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->kick_request);
      this->kick_power =  ((uint16_t) (*(inbuffer + offset)));
      this->kick_power |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->kick_power);
     return offset;
    }

    virtual const char * getType() override { return SHOOT; };
    virtual const char * getMD5() override { return "c0ebfa63f511b35c5ab7ac2913ed3f0c"; };

  };

  class ShootResponse : public ros::Msg
  {
    public:
      typedef int64_t _ShootIsDone_type;
      _ShootIsDone_type ShootIsDone;

    ShootResponse():
      ShootIsDone(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_ShootIsDone;
      u_ShootIsDone.real = this->ShootIsDone;
      *(outbuffer + offset + 0) = (u_ShootIsDone.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ShootIsDone.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ShootIsDone.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ShootIsDone.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ShootIsDone.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ShootIsDone.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ShootIsDone.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ShootIsDone.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ShootIsDone);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_ShootIsDone;
      u_ShootIsDone.base = 0;
      u_ShootIsDone.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ShootIsDone.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ShootIsDone.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ShootIsDone.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ShootIsDone.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ShootIsDone.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ShootIsDone.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ShootIsDone.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ShootIsDone = u_ShootIsDone.real;
      offset += sizeof(this->ShootIsDone);
     return offset;
    }

    virtual const char * getType() override { return SHOOT; };
    virtual const char * getMD5() override { return "942dc5d9ce09e09747b9618619df0e71"; };

  };

  class Shoot {
    public:
    typedef ShootRequest Request;
    typedef ShootResponse Response;
  };

}
#endif
