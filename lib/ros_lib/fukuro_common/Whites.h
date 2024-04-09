#ifndef _ROS_fukuro_common_Whites_h
#define _ROS_fukuro_common_Whites_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/Point2d.h"

namespace fukuro_common
{

  class Whites : public ros::Msg
  {
    public:
      uint32_t whites_length;
      typedef fukuro_common::Point2d _whites_type;
      _whites_type st_whites;
      _whites_type * whites;

    Whites():
      whites_length(0), st_whites(), whites(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->whites_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->whites_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->whites_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->whites_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->whites_length);
      for( uint32_t i = 0; i < whites_length; i++){
      offset += this->whites[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t whites_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      whites_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      whites_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      whites_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->whites_length);
      if(whites_lengthT > whites_length)
        this->whites = (fukuro_common::Point2d*)realloc(this->whites, whites_lengthT * sizeof(fukuro_common::Point2d));
      whites_length = whites_lengthT;
      for( uint32_t i = 0; i < whites_length; i++){
      offset += this->st_whites.deserialize(inbuffer + offset);
        memcpy( &(this->whites[i]), &(this->st_whites), sizeof(fukuro_common::Point2d));
      }
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/Whites"; };
    virtual const char * getMD5() override { return "3888bbcb4197c33e8f1471d84dc66374"; };

  };

}
#endif
