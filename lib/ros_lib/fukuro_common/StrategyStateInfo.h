#ifndef _ROS_fukuro_common_StrategyStateInfo_h
#define _ROS_fukuro_common_StrategyStateInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class StrategyStateInfo : public ros::Msg
  {
    public:
      typedef const char* _robot_name_type;
      _robot_name_type robot_name;
      typedef const char* _robot_role_type;
      _robot_role_type robot_role;
      typedef const char* _strategy_state_type;
      _strategy_state_type strategy_state;
      typedef const char* _strategy_option_type;
      _strategy_option_type strategy_option;
      typedef const char* _transition_state_type;
      _transition_state_type transition_state;
      typedef const char* _transition_option_type;
      _transition_option_type transition_option;
      typedef const char* _outcome_type;
      _outcome_type outcome;
      typedef const char* _state_type;
      _state_type state;
      typedef const char* _state_info_type;
      _state_info_type state_info;
      typedef bool _is_ball_visible_type;
      _is_ball_visible_type is_ball_visible;
      typedef bool _is_ball_engaged_type;
      _is_ball_engaged_type is_ball_engaged;
      typedef bool _ball_passed_type;
      _ball_passed_type ball_passed;
      typedef bool _ready_receive_type;
      _ready_receive_type ready_receive;

    StrategyStateInfo():
      robot_name(""),
      robot_role(""),
      strategy_state(""),
      strategy_option(""),
      transition_state(""),
      transition_option(""),
      outcome(""),
      state(""),
      state_info(""),
      is_ball_visible(0),
      is_ball_engaged(0),
      ball_passed(0),
      ready_receive(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_robot_name = strlen(this->robot_name);
      varToArr(outbuffer + offset, length_robot_name);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_name, length_robot_name);
      offset += length_robot_name;
      uint32_t length_robot_role = strlen(this->robot_role);
      varToArr(outbuffer + offset, length_robot_role);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_role, length_robot_role);
      offset += length_robot_role;
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
      uint32_t length_transition_state = strlen(this->transition_state);
      varToArr(outbuffer + offset, length_transition_state);
      offset += 4;
      memcpy(outbuffer + offset, this->transition_state, length_transition_state);
      offset += length_transition_state;
      uint32_t length_transition_option = strlen(this->transition_option);
      varToArr(outbuffer + offset, length_transition_option);
      offset += 4;
      memcpy(outbuffer + offset, this->transition_option, length_transition_option);
      offset += length_transition_option;
      uint32_t length_outcome = strlen(this->outcome);
      varToArr(outbuffer + offset, length_outcome);
      offset += 4;
      memcpy(outbuffer + offset, this->outcome, length_outcome);
      offset += length_outcome;
      uint32_t length_state = strlen(this->state);
      varToArr(outbuffer + offset, length_state);
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      uint32_t length_state_info = strlen(this->state_info);
      varToArr(outbuffer + offset, length_state_info);
      offset += 4;
      memcpy(outbuffer + offset, this->state_info, length_state_info);
      offset += length_state_info;
      union {
        bool real;
        uint8_t base;
      } u_is_ball_visible;
      u_is_ball_visible.real = this->is_ball_visible;
      *(outbuffer + offset + 0) = (u_is_ball_visible.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_ball_visible);
      union {
        bool real;
        uint8_t base;
      } u_is_ball_engaged;
      u_is_ball_engaged.real = this->is_ball_engaged;
      *(outbuffer + offset + 0) = (u_is_ball_engaged.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_ball_engaged);
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
      uint32_t length_robot_name;
      arrToVar(length_robot_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_name-1]=0;
      this->robot_name = (char *)(inbuffer + offset-1);
      offset += length_robot_name;
      uint32_t length_robot_role;
      arrToVar(length_robot_role, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_role; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_role-1]=0;
      this->robot_role = (char *)(inbuffer + offset-1);
      offset += length_robot_role;
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
      uint32_t length_transition_state;
      arrToVar(length_transition_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_transition_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_transition_state-1]=0;
      this->transition_state = (char *)(inbuffer + offset-1);
      offset += length_transition_state;
      uint32_t length_transition_option;
      arrToVar(length_transition_option, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_transition_option; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_transition_option-1]=0;
      this->transition_option = (char *)(inbuffer + offset-1);
      offset += length_transition_option;
      uint32_t length_outcome;
      arrToVar(length_outcome, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_outcome; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_outcome-1]=0;
      this->outcome = (char *)(inbuffer + offset-1);
      offset += length_outcome;
      uint32_t length_state;
      arrToVar(length_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
      uint32_t length_state_info;
      arrToVar(length_state_info, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state_info-1]=0;
      this->state_info = (char *)(inbuffer + offset-1);
      offset += length_state_info;
      union {
        bool real;
        uint8_t base;
      } u_is_ball_visible;
      u_is_ball_visible.base = 0;
      u_is_ball_visible.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_ball_visible = u_is_ball_visible.real;
      offset += sizeof(this->is_ball_visible);
      union {
        bool real;
        uint8_t base;
      } u_is_ball_engaged;
      u_is_ball_engaged.base = 0;
      u_is_ball_engaged.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_ball_engaged = u_is_ball_engaged.real;
      offset += sizeof(this->is_ball_engaged);
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

    virtual const char * getType() override { return "fukuro_common/StrategyStateInfo"; };
    virtual const char * getMD5() override { return "d704da518bf1b3684c1bb627c66a4cbf"; };

  };

}
#endif
