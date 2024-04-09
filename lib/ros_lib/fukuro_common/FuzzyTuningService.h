#ifndef _ROS_SERVICE_FuzzyTuningService_h
#define _ROS_SERVICE_FuzzyTuningService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

static const char FUZZYTUNINGSERVICE[] = "fukuro_common/FuzzyTuningService";

  class FuzzyTuningServiceRequest : public ros::Msg
  {
    public:
      typedef uint8_t _variable_id_type;
      _variable_id_type variable_id;
      typedef const char* _member_id_type;
      _member_id_type member_id;
      typedef int32_t _member_shape_type;
      _member_shape_type member_shape;
      uint32_t member_param_length;
      typedef float _member_param_type;
      _member_param_type st_member_param;
      _member_param_type * member_param;

    FuzzyTuningServiceRequest():
      variable_id(0),
      member_id(""),
      member_shape(0),
      member_param_length(0), st_member_param(), member_param(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->variable_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->variable_id);
      uint32_t length_member_id = strlen(this->member_id);
      varToArr(outbuffer + offset, length_member_id);
      offset += 4;
      memcpy(outbuffer + offset, this->member_id, length_member_id);
      offset += length_member_id;
      union {
        int32_t real;
        uint32_t base;
      } u_member_shape;
      u_member_shape.real = this->member_shape;
      *(outbuffer + offset + 0) = (u_member_shape.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_member_shape.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_member_shape.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_member_shape.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->member_shape);
      *(outbuffer + offset + 0) = (this->member_param_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->member_param_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->member_param_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->member_param_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->member_param_length);
      for( uint32_t i = 0; i < member_param_length; i++){
      union {
        float real;
        uint32_t base;
      } u_member_parami;
      u_member_parami.real = this->member_param[i];
      *(outbuffer + offset + 0) = (u_member_parami.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_member_parami.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_member_parami.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_member_parami.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->member_param[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->variable_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->variable_id);
      uint32_t length_member_id;
      arrToVar(length_member_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_member_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_member_id-1]=0;
      this->member_id = (char *)(inbuffer + offset-1);
      offset += length_member_id;
      union {
        int32_t real;
        uint32_t base;
      } u_member_shape;
      u_member_shape.base = 0;
      u_member_shape.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_member_shape.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_member_shape.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_member_shape.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->member_shape = u_member_shape.real;
      offset += sizeof(this->member_shape);
      uint32_t member_param_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      member_param_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      member_param_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      member_param_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->member_param_length);
      if(member_param_lengthT > member_param_length)
        this->member_param = (float*)realloc(this->member_param, member_param_lengthT * sizeof(float));
      member_param_length = member_param_lengthT;
      for( uint32_t i = 0; i < member_param_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_member_param;
      u_st_member_param.base = 0;
      u_st_member_param.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_member_param.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_member_param.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_member_param.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_member_param = u_st_member_param.real;
      offset += sizeof(this->st_member_param);
        memcpy( &(this->member_param[i]), &(this->st_member_param), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return FUZZYTUNINGSERVICE; };
    virtual const char * getMD5() override { return "1bf92ced75961daa1e93a4fd45ad8411"; };

  };

  class FuzzyTuningServiceResponse : public ros::Msg
  {
    public:
      typedef uint8_t _ok_type;
      _ok_type ok;

    FuzzyTuningServiceResponse():
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

    virtual const char * getType() override { return FUZZYTUNINGSERVICE; };
    virtual const char * getMD5() override { return "ebb43f57b7820ff999dc120ba80eb7d8"; };

  };

  class FuzzyTuningService {
    public:
    typedef FuzzyTuningServiceRequest Request;
    typedef FuzzyTuningServiceResponse Response;
  };

}
#endif
