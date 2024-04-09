#ifndef _ROS_fukuro_common_MotorParameter_h
#define _ROS_fukuro_common_MotorParameter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

  class MotorParameter : public ros::Msg
  {
    public:
      typedef int8_t _n_speed_type;
      _n_speed_type n_speed;
      uint32_t motor1_length;
      typedef float _motor1_type;
      _motor1_type st_motor1;
      _motor1_type * motor1;
      uint32_t motor2_length;
      typedef float _motor2_type;
      _motor2_type st_motor2;
      _motor2_type * motor2;
      uint32_t motor3_length;
      typedef float _motor3_type;
      _motor3_type st_motor3;
      _motor3_type * motor3;

    MotorParameter():
      n_speed(0),
      motor1_length(0), st_motor1(), motor1(nullptr),
      motor2_length(0), st_motor2(), motor2(nullptr),
      motor3_length(0), st_motor3(), motor3(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_n_speed;
      u_n_speed.real = this->n_speed;
      *(outbuffer + offset + 0) = (u_n_speed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->n_speed);
      *(outbuffer + offset + 0) = (this->motor1_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor1_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor1_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor1_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor1_length);
      for( uint32_t i = 0; i < motor1_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->motor1[i]);
      }
      *(outbuffer + offset + 0) = (this->motor2_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor2_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor2_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor2_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor2_length);
      for( uint32_t i = 0; i < motor2_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->motor2[i]);
      }
      *(outbuffer + offset + 0) = (this->motor3_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor3_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor3_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor3_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor3_length);
      for( uint32_t i = 0; i < motor3_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->motor3[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_n_speed;
      u_n_speed.base = 0;
      u_n_speed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->n_speed = u_n_speed.real;
      offset += sizeof(this->n_speed);
      uint32_t motor1_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor1_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor1_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor1_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor1_length);
      if(motor1_lengthT > motor1_length)
        this->motor1 = (float*)realloc(this->motor1, motor1_lengthT * sizeof(float));
      motor1_length = motor1_lengthT;
      for( uint32_t i = 0; i < motor1_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_motor1));
        memcpy( &(this->motor1[i]), &(this->st_motor1), sizeof(float));
      }
      uint32_t motor2_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor2_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor2_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor2_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor2_length);
      if(motor2_lengthT > motor2_length)
        this->motor2 = (float*)realloc(this->motor2, motor2_lengthT * sizeof(float));
      motor2_length = motor2_lengthT;
      for( uint32_t i = 0; i < motor2_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_motor2));
        memcpy( &(this->motor2[i]), &(this->st_motor2), sizeof(float));
      }
      uint32_t motor3_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor3_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor3_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor3_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor3_length);
      if(motor3_lengthT > motor3_length)
        this->motor3 = (float*)realloc(this->motor3, motor3_lengthT * sizeof(float));
      motor3_length = motor3_lengthT;
      for( uint32_t i = 0; i < motor3_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_motor3));
        memcpy( &(this->motor3[i]), &(this->st_motor3), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/MotorParameter"; };
    virtual const char * getMD5() override { return "8645ce99acc3de9f5817e6d22e97aae7"; };

  };

}
#endif
