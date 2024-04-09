#ifndef _ROS_fukuro_common_StrategyInfo_h
#define _ROS_fukuro_common_StrategyInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class StrategyInfo : public ros::Msg
  {
    public:
      typedef const char* _strategy_state_type;
      _strategy_state_type strategy_state;
      typedef const char* _role_type;
      _role_type role;
      typedef const char* _option_type;
      _option_type option;
      typedef bool _ball_passed_type;
      _ball_passed_type ball_passed;
      typedef bool _ready_receive_type;
      _ready_receive_type ready_receive;

    StrategyInfo():
      strategy_state(""),
      role(""),
      option(""),
      ball_passed(0),
      ready_receive(0)
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
      uint32_t length_role = strlen(this->role);
      varToArr(outbuffer + offset, length_role);
      offset += 4;
      memcpy(outbuffer + offset, this->role, length_role);
      offset += length_role;
      uint32_t length_option = strlen(this->option);
      varToArr(outbuffer + offset, length_option);
      offset += 4;
      memcpy(outbuffer + offset, this->option, length_option);
      offset += length_option;
      union {
        bool real;
        uint8_t base;
      } u_ball_passed;
      u_ball_passed.real = this->ball_passed;
      *(outbuffer + offset + 0) = (u_ball_passed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ball_passed);
      union {
        bool real;
        uint8_t base;
      } u_ready_receive;
      u_ready_receive.real = this->ready_receive;
      *(outbuffer + offset + 0) = (u_ready_receive.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ready_receive);
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
      uint32_t length_role;
      arrToVar(length_role, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_role; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_role-1]=0;
      this->role = (char *)(inbuffer + offset-1);
      offset += length_role;
      uint32_t length_option;
      arrToVar(length_option, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_option; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_option-1]=0;
      this->option = (char *)(inbuffer + offset-1);
      offset += length_option;
      union {
        bool real;
        uint8_t base;
      } u_ball_passed;
      u_ball_passed.base = 0;
      u_ball_passed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ball_passed = u_ball_passed.real;
      offset += sizeof(this->ball_passed);
      union {
        bool real;
        uint8_t base;
      } u_ready_receive;
      u_ready_receive.base = 0;
      u_ready_receive.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ready_receive = u_ready_receive.real;
      offset += sizeof(this->ready_receive);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/StrategyInfo"; };
    virtual const char * getMD5() override { return "b91c76e9e4337807ddef2cd407b15d2a"; };

  };

}
#endif
