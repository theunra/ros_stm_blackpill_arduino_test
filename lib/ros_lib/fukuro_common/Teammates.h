#ifndef _ROS_fukuro_common_Teammates_h
#define _ROS_fukuro_common_Teammates_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace fukuro_common
{

  class Teammates : public ros::Msg
  {
    public:
      typedef int32_t _robotnumber_type;
      _robotnumber_type robotnumber;
      uint32_t pose_length;
      typedef geometry_msgs::Pose2D _pose_type;
      _pose_type st_pose;
      _pose_type * pose;
      uint32_t ball_pose_length;
      typedef geometry_msgs::Pose2D _ball_pose_type;
      _ball_pose_type st_ball_pose;
      _ball_pose_type * ball_pose;
      uint32_t available_length;
      typedef bool _available_type;
      _available_type st_available;
      _available_type * available;
      typedef int32_t _behavior_type;
      _behavior_type behavior;
      typedef int32_t _state_type;
      _state_type state;
      typedef bool _isConnected_type;
      _isConnected_type isConnected;
      typedef bool _isManualPositioning_type;
      _isManualPositioning_type isManualPositioning;
      typedef bool _isBallOwn_type;
      _isBallOwn_type isBallOwn;
      uint32_t pass_ball_length;
      typedef bool _pass_ball_type;
      _pass_ball_type st_pass_ball;
      _pass_ball_type * pass_ball;
      uint32_t receive_ball_length;
      typedef bool _receive_ball_type;
      _receive_ball_type st_receive_ball;
      _receive_ball_type * receive_ball;

    Teammates():
      robotnumber(0),
      pose_length(0), st_pose(), pose(nullptr),
      ball_pose_length(0), st_ball_pose(), ball_pose(nullptr),
      available_length(0), st_available(), available(nullptr),
      behavior(0),
      state(0),
      isConnected(0),
      isManualPositioning(0),
      isBallOwn(0),
      pass_ball_length(0), st_pass_ball(), pass_ball(nullptr),
      receive_ball_length(0), st_receive_ball(), receive_ball(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_robotnumber;
      u_robotnumber.real = this->robotnumber;
      *(outbuffer + offset + 0) = (u_robotnumber.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_robotnumber.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_robotnumber.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_robotnumber.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robotnumber);
      *(outbuffer + offset + 0) = (this->pose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_length);
      for( uint32_t i = 0; i < pose_length; i++){
      offset += this->pose[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->ball_pose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ball_pose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ball_pose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ball_pose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ball_pose_length);
      for( uint32_t i = 0; i < ball_pose_length; i++){
      offset += this->ball_pose[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->available_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->available_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->available_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->available_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->available_length);
      for( uint32_t i = 0; i < available_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_availablei;
      u_availablei.real = this->available[i];
      *(outbuffer + offset + 0) = (u_availablei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->available[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_behavior;
      u_behavior.real = this->behavior;
      *(outbuffer + offset + 0) = (u_behavior.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_behavior.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_behavior.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_behavior.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->behavior);
      union {
        int32_t real;
        uint32_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state);
      union {
        bool real;
        uint8_t base;
      } u_isConnected;
      u_isConnected.real = this->isConnected;
      *(outbuffer + offset + 0) = (u_isConnected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isConnected);
      union {
        bool real;
        uint8_t base;
      } u_isManualPositioning;
      u_isManualPositioning.real = this->isManualPositioning;
      *(outbuffer + offset + 0) = (u_isManualPositioning.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isManualPositioning);
      union {
        bool real;
        uint8_t base;
      } u_isBallOwn;
      u_isBallOwn.real = this->isBallOwn;
      *(outbuffer + offset + 0) = (u_isBallOwn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isBallOwn);
      *(outbuffer + offset + 0) = (this->pass_ball_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pass_ball_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pass_ball_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pass_ball_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pass_ball_length);
      for( uint32_t i = 0; i < pass_ball_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_pass_balli;
      u_pass_balli.real = this->pass_ball[i];
      *(outbuffer + offset + 0) = (u_pass_balli.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pass_ball[i]);
      }
      *(outbuffer + offset + 0) = (this->receive_ball_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->receive_ball_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->receive_ball_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->receive_ball_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->receive_ball_length);
      for( uint32_t i = 0; i < receive_ball_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_receive_balli;
      u_receive_balli.real = this->receive_ball[i];
      *(outbuffer + offset + 0) = (u_receive_balli.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->receive_ball[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_robotnumber;
      u_robotnumber.base = 0;
      u_robotnumber.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_robotnumber.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_robotnumber.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_robotnumber.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->robotnumber = u_robotnumber.real;
      offset += sizeof(this->robotnumber);
      uint32_t pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pose_length);
      if(pose_lengthT > pose_length)
        this->pose = (geometry_msgs::Pose2D*)realloc(this->pose, pose_lengthT * sizeof(geometry_msgs::Pose2D));
      pose_length = pose_lengthT;
      for( uint32_t i = 0; i < pose_length; i++){
      offset += this->st_pose.deserialize(inbuffer + offset);
        memcpy( &(this->pose[i]), &(this->st_pose), sizeof(geometry_msgs::Pose2D));
      }
      uint32_t ball_pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ball_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ball_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ball_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ball_pose_length);
      if(ball_pose_lengthT > ball_pose_length)
        this->ball_pose = (geometry_msgs::Pose2D*)realloc(this->ball_pose, ball_pose_lengthT * sizeof(geometry_msgs::Pose2D));
      ball_pose_length = ball_pose_lengthT;
      for( uint32_t i = 0; i < ball_pose_length; i++){
      offset += this->st_ball_pose.deserialize(inbuffer + offset);
        memcpy( &(this->ball_pose[i]), &(this->st_ball_pose), sizeof(geometry_msgs::Pose2D));
      }
      uint32_t available_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      available_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      available_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      available_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->available_length);
      if(available_lengthT > available_length)
        this->available = (bool*)realloc(this->available, available_lengthT * sizeof(bool));
      available_length = available_lengthT;
      for( uint32_t i = 0; i < available_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_available;
      u_st_available.base = 0;
      u_st_available.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_available = u_st_available.real;
      offset += sizeof(this->st_available);
        memcpy( &(this->available[i]), &(this->st_available), sizeof(bool));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_behavior;
      u_behavior.base = 0;
      u_behavior.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_behavior.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_behavior.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_behavior.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->behavior = u_behavior.real;
      offset += sizeof(this->behavior);
      union {
        int32_t real;
        uint32_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state = u_state.real;
      offset += sizeof(this->state);
      union {
        bool real;
        uint8_t base;
      } u_isConnected;
      u_isConnected.base = 0;
      u_isConnected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isConnected = u_isConnected.real;
      offset += sizeof(this->isConnected);
      union {
        bool real;
        uint8_t base;
      } u_isManualPositioning;
      u_isManualPositioning.base = 0;
      u_isManualPositioning.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isManualPositioning = u_isManualPositioning.real;
      offset += sizeof(this->isManualPositioning);
      union {
        bool real;
        uint8_t base;
      } u_isBallOwn;
      u_isBallOwn.base = 0;
      u_isBallOwn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isBallOwn = u_isBallOwn.real;
      offset += sizeof(this->isBallOwn);
      uint32_t pass_ball_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pass_ball_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pass_ball_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pass_ball_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pass_ball_length);
      if(pass_ball_lengthT > pass_ball_length)
        this->pass_ball = (bool*)realloc(this->pass_ball, pass_ball_lengthT * sizeof(bool));
      pass_ball_length = pass_ball_lengthT;
      for( uint32_t i = 0; i < pass_ball_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_pass_ball;
      u_st_pass_ball.base = 0;
      u_st_pass_ball.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_pass_ball = u_st_pass_ball.real;
      offset += sizeof(this->st_pass_ball);
        memcpy( &(this->pass_ball[i]), &(this->st_pass_ball), sizeof(bool));
      }
      uint32_t receive_ball_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      receive_ball_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      receive_ball_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      receive_ball_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->receive_ball_length);
      if(receive_ball_lengthT > receive_ball_length)
        this->receive_ball = (bool*)realloc(this->receive_ball, receive_ball_lengthT * sizeof(bool));
      receive_ball_length = receive_ball_lengthT;
      for( uint32_t i = 0; i < receive_ball_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_receive_ball;
      u_st_receive_ball.base = 0;
      u_st_receive_ball.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_receive_ball = u_st_receive_ball.real;
      offset += sizeof(this->st_receive_ball);
        memcpy( &(this->receive_ball[i]), &(this->st_receive_ball), sizeof(bool));
      }
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/Teammates"; };
    virtual const char * getMD5() override { return "85d315fb3afcf1e951316c4a577771e6"; };

  };

}
#endif
