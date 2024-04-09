#ifndef _ROS_fukuro_common_WorldModel_h
#define _ROS_fukuro_common_WorldModel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Point.h"
#include "fukuro_common/Obstacle.h"
#include "fukuro_common/Point2d.h"

namespace fukuro_common
{

  class WorldModel : public ros::Msg
  {
    public:
      typedef const char* _robot_name_type;
      _robot_name_type robot_name;
      typedef bool _ball_visible_type;
      _ball_visible_type ball_visible;
      typedef bool _ballp_visible_type;
      _ballp_visible_type ballp_visible;
      typedef bool _obstacle_visible_type;
      _obstacle_visible_type obstacle_visible;
      typedef bool _friend_visible_type;
      _friend_visible_type friend_visible;
      uint32_t available_length;
      typedef bool _available_type;
      _available_type st_available;
      _available_type * available;
      typedef bool _set_obstacle_type;
      _set_obstacle_type set_obstacle;
      typedef geometry_msgs::Pose2D _position_type;
      _position_type position;
      uint32_t teammates_length;
      typedef geometry_msgs::Pose2D _teammates_type;
      _teammates_type st_teammates;
      _teammates_type * teammates;
      typedef geometry_msgs::Pose2D _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Point _local_friend_type;
      _local_friend_type local_friend;
      typedef geometry_msgs::Point _global_friend_type;
      _global_friend_type global_friend;
      typedef geometry_msgs::Point _local_ball_type;
      _local_ball_type local_ball;
      typedef geometry_msgs::Point _global_ball_type;
      _global_ball_type global_ball;
      typedef geometry_msgs::Point _local_ballp_type;
      _local_ballp_type local_ballp;
      typedef geometry_msgs::Point _global_ballp_type;
      _global_ballp_type global_ballp;
      uint32_t local_balls_length;
      typedef geometry_msgs::Point _local_balls_type;
      _local_balls_type st_local_balls;
      _local_balls_type * local_balls;
      uint32_t balls_length;
      typedef geometry_msgs::Point _balls_type;
      _balls_type st_balls;
      _balls_type * balls;
      uint32_t way_points_length;
      typedef geometry_msgs::Point _way_points_type;
      _way_points_type st_way_points;
      _way_points_type * way_points;
      uint32_t obstacles_length;
      typedef fukuro_common::Obstacle _obstacles_type;
      _obstacles_type st_obstacles;
      _obstacles_type * obstacles;
      typedef fukuro_common::Obstacle _obstacle1_type;
      _obstacle1_type obstacle1;
      typedef fukuro_common::Obstacle _obstacle2_type;
      _obstacle2_type obstacle2;
      typedef fukuro_common::Obstacle _kiper_obstacle_type;
      _kiper_obstacle_type kiper_obstacle;
      uint32_t local_obstacles_length;
      typedef fukuro_common::Point2d _local_obstacles_type;
      _local_obstacles_type st_local_obstacles;
      _local_obstacles_type * local_obstacles;
      uint32_t global_obstacles_length;
      typedef fukuro_common::Point2d _global_obstacles_type;
      _global_obstacles_type st_global_obstacles;
      _global_obstacles_type * global_obstacles;

    WorldModel():
      robot_name(""),
      ball_visible(0),
      ballp_visible(0),
      obstacle_visible(0),
      friend_visible(0),
      available_length(0), st_available(), available(nullptr),
      set_obstacle(0),
      position(),
      teammates_length(0), st_teammates(), teammates(nullptr),
      velocity(),
      local_friend(),
      global_friend(),
      local_ball(),
      global_ball(),
      local_ballp(),
      global_ballp(),
      local_balls_length(0), st_local_balls(), local_balls(nullptr),
      balls_length(0), st_balls(), balls(nullptr),
      way_points_length(0), st_way_points(), way_points(nullptr),
      obstacles_length(0), st_obstacles(), obstacles(nullptr),
      obstacle1(),
      obstacle2(),
      kiper_obstacle(),
      local_obstacles_length(0), st_local_obstacles(), local_obstacles(nullptr),
      global_obstacles_length(0), st_global_obstacles(), global_obstacles(nullptr)
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
      union {
        bool real;
        uint8_t base;
      } u_ball_visible;
      u_ball_visible.real = this->ball_visible;
      *(outbuffer + offset + 0) = (u_ball_visible.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ball_visible);
      union {
        bool real;
        uint8_t base;
      } u_ballp_visible;
      u_ballp_visible.real = this->ballp_visible;
      *(outbuffer + offset + 0) = (u_ballp_visible.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ballp_visible);
      union {
        bool real;
        uint8_t base;
      } u_obstacle_visible;
      u_obstacle_visible.real = this->obstacle_visible;
      *(outbuffer + offset + 0) = (u_obstacle_visible.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacle_visible);
      union {
        bool real;
        uint8_t base;
      } u_friend_visible;
      u_friend_visible.real = this->friend_visible;
      *(outbuffer + offset + 0) = (u_friend_visible.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->friend_visible);
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
        bool real;
        uint8_t base;
      } u_set_obstacle;
      u_set_obstacle.real = this->set_obstacle;
      *(outbuffer + offset + 0) = (u_set_obstacle.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_obstacle);
      offset += this->position.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->teammates_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->teammates_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->teammates_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->teammates_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->teammates_length);
      for( uint32_t i = 0; i < teammates_length; i++){
      offset += this->teammates[i].serialize(outbuffer + offset);
      }
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->local_friend.serialize(outbuffer + offset);
      offset += this->global_friend.serialize(outbuffer + offset);
      offset += this->local_ball.serialize(outbuffer + offset);
      offset += this->global_ball.serialize(outbuffer + offset);
      offset += this->local_ballp.serialize(outbuffer + offset);
      offset += this->global_ballp.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->local_balls_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->local_balls_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->local_balls_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->local_balls_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->local_balls_length);
      for( uint32_t i = 0; i < local_balls_length; i++){
      offset += this->local_balls[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->balls_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->balls_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->balls_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->balls_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->balls_length);
      for( uint32_t i = 0; i < balls_length; i++){
      offset += this->balls[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->way_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->way_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->way_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->way_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->way_points_length);
      for( uint32_t i = 0; i < way_points_length; i++){
      offset += this->way_points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->obstacles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obstacles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obstacles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obstacles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obstacles_length);
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->obstacles[i].serialize(outbuffer + offset);
      }
      offset += this->obstacle1.serialize(outbuffer + offset);
      offset += this->obstacle2.serialize(outbuffer + offset);
      offset += this->kiper_obstacle.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->local_obstacles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->local_obstacles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->local_obstacles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->local_obstacles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->local_obstacles_length);
      for( uint32_t i = 0; i < local_obstacles_length; i++){
      offset += this->local_obstacles[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->global_obstacles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->global_obstacles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->global_obstacles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->global_obstacles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->global_obstacles_length);
      for( uint32_t i = 0; i < global_obstacles_length; i++){
      offset += this->global_obstacles[i].serialize(outbuffer + offset);
      }
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
      union {
        bool real;
        uint8_t base;
      } u_ball_visible;
      u_ball_visible.base = 0;
      u_ball_visible.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ball_visible = u_ball_visible.real;
      offset += sizeof(this->ball_visible);
      union {
        bool real;
        uint8_t base;
      } u_ballp_visible;
      u_ballp_visible.base = 0;
      u_ballp_visible.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ballp_visible = u_ballp_visible.real;
      offset += sizeof(this->ballp_visible);
      union {
        bool real;
        uint8_t base;
      } u_obstacle_visible;
      u_obstacle_visible.base = 0;
      u_obstacle_visible.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->obstacle_visible = u_obstacle_visible.real;
      offset += sizeof(this->obstacle_visible);
      union {
        bool real;
        uint8_t base;
      } u_friend_visible;
      u_friend_visible.base = 0;
      u_friend_visible.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->friend_visible = u_friend_visible.real;
      offset += sizeof(this->friend_visible);
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
        bool real;
        uint8_t base;
      } u_set_obstacle;
      u_set_obstacle.base = 0;
      u_set_obstacle.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_obstacle = u_set_obstacle.real;
      offset += sizeof(this->set_obstacle);
      offset += this->position.deserialize(inbuffer + offset);
      uint32_t teammates_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      teammates_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      teammates_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      teammates_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->teammates_length);
      if(teammates_lengthT > teammates_length)
        this->teammates = (geometry_msgs::Pose2D*)realloc(this->teammates, teammates_lengthT * sizeof(geometry_msgs::Pose2D));
      teammates_length = teammates_lengthT;
      for( uint32_t i = 0; i < teammates_length; i++){
      offset += this->st_teammates.deserialize(inbuffer + offset);
        memcpy( &(this->teammates[i]), &(this->st_teammates), sizeof(geometry_msgs::Pose2D));
      }
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->local_friend.deserialize(inbuffer + offset);
      offset += this->global_friend.deserialize(inbuffer + offset);
      offset += this->local_ball.deserialize(inbuffer + offset);
      offset += this->global_ball.deserialize(inbuffer + offset);
      offset += this->local_ballp.deserialize(inbuffer + offset);
      offset += this->global_ballp.deserialize(inbuffer + offset);
      uint32_t local_balls_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      local_balls_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      local_balls_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      local_balls_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->local_balls_length);
      if(local_balls_lengthT > local_balls_length)
        this->local_balls = (geometry_msgs::Point*)realloc(this->local_balls, local_balls_lengthT * sizeof(geometry_msgs::Point));
      local_balls_length = local_balls_lengthT;
      for( uint32_t i = 0; i < local_balls_length; i++){
      offset += this->st_local_balls.deserialize(inbuffer + offset);
        memcpy( &(this->local_balls[i]), &(this->st_local_balls), sizeof(geometry_msgs::Point));
      }
      uint32_t balls_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      balls_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      balls_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      balls_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->balls_length);
      if(balls_lengthT > balls_length)
        this->balls = (geometry_msgs::Point*)realloc(this->balls, balls_lengthT * sizeof(geometry_msgs::Point));
      balls_length = balls_lengthT;
      for( uint32_t i = 0; i < balls_length; i++){
      offset += this->st_balls.deserialize(inbuffer + offset);
        memcpy( &(this->balls[i]), &(this->st_balls), sizeof(geometry_msgs::Point));
      }
      uint32_t way_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      way_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      way_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      way_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->way_points_length);
      if(way_points_lengthT > way_points_length)
        this->way_points = (geometry_msgs::Point*)realloc(this->way_points, way_points_lengthT * sizeof(geometry_msgs::Point));
      way_points_length = way_points_lengthT;
      for( uint32_t i = 0; i < way_points_length; i++){
      offset += this->st_way_points.deserialize(inbuffer + offset);
        memcpy( &(this->way_points[i]), &(this->st_way_points), sizeof(geometry_msgs::Point));
      }
      uint32_t obstacles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obstacles_length);
      if(obstacles_lengthT > obstacles_length)
        this->obstacles = (fukuro_common::Obstacle*)realloc(this->obstacles, obstacles_lengthT * sizeof(fukuro_common::Obstacle));
      obstacles_length = obstacles_lengthT;
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->st_obstacles.deserialize(inbuffer + offset);
        memcpy( &(this->obstacles[i]), &(this->st_obstacles), sizeof(fukuro_common::Obstacle));
      }
      offset += this->obstacle1.deserialize(inbuffer + offset);
      offset += this->obstacle2.deserialize(inbuffer + offset);
      offset += this->kiper_obstacle.deserialize(inbuffer + offset);
      uint32_t local_obstacles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      local_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      local_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      local_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->local_obstacles_length);
      if(local_obstacles_lengthT > local_obstacles_length)
        this->local_obstacles = (fukuro_common::Point2d*)realloc(this->local_obstacles, local_obstacles_lengthT * sizeof(fukuro_common::Point2d));
      local_obstacles_length = local_obstacles_lengthT;
      for( uint32_t i = 0; i < local_obstacles_length; i++){
      offset += this->st_local_obstacles.deserialize(inbuffer + offset);
        memcpy( &(this->local_obstacles[i]), &(this->st_local_obstacles), sizeof(fukuro_common::Point2d));
      }
      uint32_t global_obstacles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      global_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      global_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      global_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->global_obstacles_length);
      if(global_obstacles_lengthT > global_obstacles_length)
        this->global_obstacles = (fukuro_common::Point2d*)realloc(this->global_obstacles, global_obstacles_lengthT * sizeof(fukuro_common::Point2d));
      global_obstacles_length = global_obstacles_lengthT;
      for( uint32_t i = 0; i < global_obstacles_length; i++){
      offset += this->st_global_obstacles.deserialize(inbuffer + offset);
        memcpy( &(this->global_obstacles[i]), &(this->st_global_obstacles), sizeof(fukuro_common::Point2d));
      }
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/WorldModel"; };
    virtual const char * getMD5() override { return "02c047e59b46f4c9f46bcbf596be20d8"; };

  };

}
#endif
