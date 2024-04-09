#ifndef _ROS_fukuro_common_PathPlan_h
#define _ROS_fukuro_common_PathPlan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/Point2d.h"

namespace fukuro_common
{

  class PathPlan : public ros::Msg
  {
    public:
      uint32_t obstacles_length;
      typedef fukuro_common::Point2d _obstacles_type;
      _obstacles_type st_obstacles;
      _obstacles_type * obstacles;
      uint32_t solutions_length;
      typedef fukuro_common::Point2d _solutions_type;
      _solutions_type st_solutions;
      _solutions_type * solutions;
      typedef fukuro_common::Point2d _start_type;
      _start_type start;
      typedef fukuro_common::Point2d _goal_type;
      _goal_type goal;
      typedef int64_t _size_type;
      _size_type size;
      typedef float _search_time_type;
      _search_time_type search_time;
      typedef bool _solved_type;
      _solved_type solved;
      typedef bool _updated_type;
      _updated_type updated;

    PathPlan():
      obstacles_length(0), st_obstacles(), obstacles(nullptr),
      solutions_length(0), st_solutions(), solutions(nullptr),
      start(),
      goal(),
      size(0),
      search_time(0),
      solved(0),
      updated(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->obstacles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obstacles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obstacles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obstacles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obstacles_length);
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->obstacles[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->solutions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->solutions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->solutions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->solutions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->solutions_length);
      for( uint32_t i = 0; i < solutions_length; i++){
      offset += this->solutions[i].serialize(outbuffer + offset);
      }
      offset += this->start.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_size;
      u_size.real = this->size;
      *(outbuffer + offset + 0) = (u_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_size.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_size.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_size.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_size.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_size.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->size);
      offset += serializeAvrFloat64(outbuffer + offset, this->search_time);
      union {
        bool real;
        uint8_t base;
      } u_solved;
      u_solved.real = this->solved;
      *(outbuffer + offset + 0) = (u_solved.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->solved);
      union {
        bool real;
        uint8_t base;
      } u_updated;
      u_updated.real = this->updated;
      *(outbuffer + offset + 0) = (u_updated.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->updated);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t obstacles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obstacles_length);
      if(obstacles_lengthT > obstacles_length)
        this->obstacles = (fukuro_common::Point2d*)realloc(this->obstacles, obstacles_lengthT * sizeof(fukuro_common::Point2d));
      obstacles_length = obstacles_lengthT;
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->st_obstacles.deserialize(inbuffer + offset);
        memcpy( &(this->obstacles[i]), &(this->st_obstacles), sizeof(fukuro_common::Point2d));
      }
      uint32_t solutions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      solutions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      solutions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      solutions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->solutions_length);
      if(solutions_lengthT > solutions_length)
        this->solutions = (fukuro_common::Point2d*)realloc(this->solutions, solutions_lengthT * sizeof(fukuro_common::Point2d));
      solutions_length = solutions_lengthT;
      for( uint32_t i = 0; i < solutions_length; i++){
      offset += this->st_solutions.deserialize(inbuffer + offset);
        memcpy( &(this->solutions[i]), &(this->st_solutions), sizeof(fukuro_common::Point2d));
      }
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_size;
      u_size.base = 0;
      u_size.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_size.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_size.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_size.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_size.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_size.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_size.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_size.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->size = u_size.real;
      offset += sizeof(this->size);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->search_time));
      union {
        bool real;
        uint8_t base;
      } u_solved;
      u_solved.base = 0;
      u_solved.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->solved = u_solved.real;
      offset += sizeof(this->solved);
      union {
        bool real;
        uint8_t base;
      } u_updated;
      u_updated.base = 0;
      u_updated.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->updated = u_updated.real;
      offset += sizeof(this->updated);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/PathPlan"; };
    virtual const char * getMD5() override { return "6a83d3c88ab72a8453f5bd8c4eb700b3"; };

  };

}
#endif
