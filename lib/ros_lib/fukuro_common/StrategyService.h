#ifndef _ROS_SERVICE_StrategyService_h
#define _ROS_SERVICE_StrategyService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace fukuro_common
{

static const char STRATEGYSERVICE[] = "fukuro_common/StrategyService";

  class StrategyServiceRequest : public ros::Msg
  {
    public:
      typedef const char* _strategy_state_type;
      _strategy_state_type strategy_state;
      typedef const char* _strategy_option_type;
      _strategy_option_type strategy_option;
      typedef const char* _role_type;
      _role_type role;
      typedef int32_t _obs1_pos_type;
      _obs1_pos_type obs1_pos;
      typedef int32_t _obs2_pos_type;
      _obs2_pos_type obs2_pos;
      typedef int32_t _kiper_pos_type;
      _kiper_pos_type kiper_pos;
      typedef const char* _option_type;
      _option_type option;
      typedef geometry_msgs::Pose2D _home_pos_type;
      _home_pos_type home_pos;
      typedef geometry_msgs::Pose2D _kick_pos_type;
      _kick_pos_type kick_pos;

    StrategyServiceRequest():
      strategy_state(""),
      strategy_option(""),
      role(""),
      obs1_pos(0),
      obs2_pos(0),
      kiper_pos(0),
      option(""),
      home_pos(),
      kick_pos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_strategy_state = strlen(this->strategy_state);
      varToArr(outbuffer + offset, length_strategy_state);
      offset += 4;
      memcpy(outbuffer + offset, this->strategy_state, length_strategy_state);
      offset += length_strategy_state;
      uint32_t length_strategy_option = strlen(this->strategy_option);
      varToArr(outbuffer + offset, length_strategy_option);
      offset += 4;
      memcpy(outbuffer + offset, this->strategy_option, length_strategy_option);
      offset += length_strategy_option;
      uint32_t length_role = strlen(this->role);
      varToArr(outbuffer + offset, length_role);
      offset += 4;
      memcpy(outbuffer + offset, this->role, length_role);
      offset += length_role;
      union {
        int32_t real;
        uint32_t base;
      } u_obs1_pos;
      u_obs1_pos.real = this->obs1_pos;
      *(outbuffer + offset + 0) = (u_obs1_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs1_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs1_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs1_pos.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs1_pos);
      union {
        int32_t real;
        uint32_t base;
      } u_obs2_pos;
      u_obs2_pos.real = this->obs2_pos;
      *(outbuffer + offset + 0) = (u_obs2_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs2_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs2_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs2_pos.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs2_pos);
      union {
        int32_t real;
        uint32_t base;
      } u_kiper_pos;
      u_kiper_pos.real = this->kiper_pos;
      *(outbuffer + offset + 0) = (u_kiper_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kiper_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kiper_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kiper_pos.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kiper_pos);
      uint32_t length_option = strlen(this->option);
      varToArr(outbuffer + offset, length_option);
      offset += 4;
      memcpy(outbuffer + offset, this->option, length_option);
      offset += length_option;
      offset += this->home_pos.serialize(outbuffer + offset);
      offset += this->kick_pos.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_strategy_state;
      arrToVar(length_strategy_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_strategy_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_strategy_state-1]=0;
      this->strategy_state = (char *)(inbuffer + offset-1);
      offset += length_strategy_state;
      uint32_t length_strategy_option;
      arrToVar(length_strategy_option, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_strategy_option; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_strategy_option-1]=0;
      this->strategy_option = (char *)(inbuffer + offset-1);
      offset += length_strategy_option;
      uint32_t length_role;
      arrToVar(length_role, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_role; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_role-1]=0;
      this->role = (char *)(inbuffer + offset-1);
      offset += length_role;
      union {
        int32_t real;
        uint32_t base;
      } u_obs1_pos;
      u_obs1_pos.base = 0;
      u_obs1_pos.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs1_pos.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs1_pos.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs1_pos.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs1_pos = u_obs1_pos.real;
      offset += sizeof(this->obs1_pos);
      union {
        int32_t real;
        uint32_t base;
      } u_obs2_pos;
      u_obs2_pos.base = 0;
      u_obs2_pos.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs2_pos.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs2_pos.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs2_pos.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs2_pos = u_obs2_pos.real;
      offset += sizeof(this->obs2_pos);
      union {
        int32_t real;
        uint32_t base;
      } u_kiper_pos;
      u_kiper_pos.base = 0;
      u_kiper_pos.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kiper_pos.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kiper_pos.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kiper_pos.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->kiper_pos = u_kiper_pos.real;
      offset += sizeof(this->kiper_pos);
      uint32_t length_option;
      arrToVar(length_option, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_option; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_option-1]=0;
      this->option = (char *)(inbuffer + offset-1);
      offset += length_option;
      offset += this->home_pos.deserialize(inbuffer + offset);
      offset += this->kick_pos.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return STRATEGYSERVICE; };
    virtual const char * getMD5() override { return "36813d2bf1dd74d02dfcbc81194a6945"; };

  };

  class StrategyServiceResponse : public ros::Msg
  {
    public:
      typedef uint8_t _ok_type;
      _ok_type ok;

    StrategyServiceResponse():
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

    virtual const char * getType() override { return STRATEGYSERVICE; };
    virtual const char * getMD5() override { return "ebb43f57b7820ff999dc120ba80eb7d8"; };

  };

  class StrategyService {
    public:
    typedef StrategyServiceRequest Request;
    typedef StrategyServiceResponse Response;
  };

}
#endif
