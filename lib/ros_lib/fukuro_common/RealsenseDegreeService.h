#ifndef _ROS_SERVICE_RealsenseDegreeService_h
#define _ROS_SERVICE_RealsenseDegreeService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

static const char REALSENSEDEGREESERVICE[] = "fukuro_common/RealsenseDegreeService";

  class RealsenseDegreeServiceRequest : public ros::Msg
  {
    public:
      typedef int8_t _object_enum_type;
      _object_enum_type object_enum;
      typedef bool _execute_type;
      _execute_type execute;

    RealsenseDegreeServiceRequest():
      object_enum(0),
      execute(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_object_enum;
      u_object_enum.real = this->object_enum;
      *(outbuffer + offset + 0) = (u_object_enum.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->object_enum);
      union {
        bool real;
        uint8_t base;
      } u_execute;
      u_execute.real = this->execute;
      *(outbuffer + offset + 0) = (u_execute.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->execute);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_object_enum;
      u_object_enum.base = 0;
      u_object_enum.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->object_enum = u_object_enum.real;
      offset += sizeof(this->object_enum);
      union {
        bool real;
        uint8_t base;
      } u_execute;
      u_execute.base = 0;
      u_execute.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->execute = u_execute.real;
      offset += sizeof(this->execute);
     return offset;
    }

    virtual const char * getType() override { return REALSENSEDEGREESERVICE; };
    virtual const char * getMD5() override { return "6e74a601fa000a59b6d257565832faa7"; };

  };

  class RealsenseDegreeServiceResponse : public ros::Msg
  {
    public:
      typedef const char* _status_type;
      _status_type status;

    RealsenseDegreeServiceResponse():
      status("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_status = strlen(this->status);
      varToArr(outbuffer + offset, length_status);
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_status;
      arrToVar(length_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
     return offset;
    }

    virtual const char * getType() override { return REALSENSEDEGREESERVICE; };
    virtual const char * getMD5() override { return "4fe5af303955c287688e7347e9b00278"; };

  };

  class RealsenseDegreeService {
    public:
    typedef RealsenseDegreeServiceRequest Request;
    typedef RealsenseDegreeServiceResponse Response;
  };

}
#endif
