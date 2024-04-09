#ifndef _ROS_SERVICE_HWControllerSrv_h
#define _ROS_SERVICE_HWControllerSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fukuro_common/Compass.h"

namespace fukuro_common
{

static const char HWCONTROLLERSRV[] = "fukuro_common/HWControllerSrv";

  class HWControllerSrvRequest : public ros::Msg
  {
    public:
      typedef uint8_t _refresh_type;
      _refresh_type refresh;
      typedef int64_t _STMConnect_type;
      _STMConnect_type STMConnect;
      typedef uint8_t _isSTM_type;
      _isSTM_type isSTM;
      typedef int64_t _ArduinoConnect_type;
      _ArduinoConnect_type ArduinoConnect;
      typedef uint8_t _isArduino_type;
      _isArduino_type isArduino;
      typedef fukuro_common::Compass _Compass_type;
      _Compass_type Compass;

    HWControllerSrvRequest():
      refresh(0),
      STMConnect(0),
      isSTM(0),
      ArduinoConnect(0),
      isArduino(0),
      Compass()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->refresh >> (8 * 0)) & 0xFF;
      offset += sizeof(this->refresh);
      union {
        int64_t real;
        uint64_t base;
      } u_STMConnect;
      u_STMConnect.real = this->STMConnect;
      *(outbuffer + offset + 0) = (u_STMConnect.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_STMConnect.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_STMConnect.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_STMConnect.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_STMConnect.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_STMConnect.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_STMConnect.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_STMConnect.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->STMConnect);
      *(outbuffer + offset + 0) = (this->isSTM >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isSTM);
      union {
        int64_t real;
        uint64_t base;
      } u_ArduinoConnect;
      u_ArduinoConnect.real = this->ArduinoConnect;
      *(outbuffer + offset + 0) = (u_ArduinoConnect.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ArduinoConnect.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ArduinoConnect.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ArduinoConnect.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ArduinoConnect.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ArduinoConnect.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ArduinoConnect.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ArduinoConnect.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ArduinoConnect);
      *(outbuffer + offset + 0) = (this->isArduino >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isArduino);
      offset += this->Compass.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->refresh =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->refresh);
      union {
        int64_t real;
        uint64_t base;
      } u_STMConnect;
      u_STMConnect.base = 0;
      u_STMConnect.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_STMConnect.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_STMConnect.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_STMConnect.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_STMConnect.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_STMConnect.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_STMConnect.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_STMConnect.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->STMConnect = u_STMConnect.real;
      offset += sizeof(this->STMConnect);
      this->isSTM =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->isSTM);
      union {
        int64_t real;
        uint64_t base;
      } u_ArduinoConnect;
      u_ArduinoConnect.base = 0;
      u_ArduinoConnect.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ArduinoConnect.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ArduinoConnect.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ArduinoConnect.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ArduinoConnect.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ArduinoConnect.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ArduinoConnect.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ArduinoConnect.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ArduinoConnect = u_ArduinoConnect.real;
      offset += sizeof(this->ArduinoConnect);
      this->isArduino =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->isArduino);
      offset += this->Compass.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return HWCONTROLLERSRV; };
    virtual const char * getMD5() override { return "aa64da40807e371629cc4f509a53fcf9"; };

  };

  class HWControllerSrvResponse : public ros::Msg
  {
    public:
      uint32_t port_list_length;
      typedef char* _port_list_type;
      _port_list_type st_port_list;
      _port_list_type * port_list;
      uint32_t manufacturer_list_length;
      typedef char* _manufacturer_list_type;
      _manufacturer_list_type st_manufacturer_list;
      _manufacturer_list_type * manufacturer_list;
      typedef uint8_t _STMSuccess_type;
      _STMSuccess_type STMSuccess;
      typedef uint8_t _ArduinoSuccess_type;
      _ArduinoSuccess_type ArduinoSuccess;
      typedef uint8_t _Compassuccess_type;
      _Compassuccess_type Compassuccess;

    HWControllerSrvResponse():
      port_list_length(0), st_port_list(), port_list(nullptr),
      manufacturer_list_length(0), st_manufacturer_list(), manufacturer_list(nullptr),
      STMSuccess(0),
      ArduinoSuccess(0),
      Compassuccess(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->port_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->port_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->port_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->port_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->port_list_length);
      for( uint32_t i = 0; i < port_list_length; i++){
      uint32_t length_port_listi = strlen(this->port_list[i]);
      varToArr(outbuffer + offset, length_port_listi);
      offset += 4;
      memcpy(outbuffer + offset, this->port_list[i], length_port_listi);
      offset += length_port_listi;
      }
      *(outbuffer + offset + 0) = (this->manufacturer_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->manufacturer_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->manufacturer_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->manufacturer_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->manufacturer_list_length);
      for( uint32_t i = 0; i < manufacturer_list_length; i++){
      uint32_t length_manufacturer_listi = strlen(this->manufacturer_list[i]);
      varToArr(outbuffer + offset, length_manufacturer_listi);
      offset += 4;
      memcpy(outbuffer + offset, this->manufacturer_list[i], length_manufacturer_listi);
      offset += length_manufacturer_listi;
      }
      *(outbuffer + offset + 0) = (this->STMSuccess >> (8 * 0)) & 0xFF;
      offset += sizeof(this->STMSuccess);
      *(outbuffer + offset + 0) = (this->ArduinoSuccess >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ArduinoSuccess);
      *(outbuffer + offset + 0) = (this->Compassuccess >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Compassuccess);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t port_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      port_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      port_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      port_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->port_list_length);
      if(port_list_lengthT > port_list_length)
        this->port_list = (char**)realloc(this->port_list, port_list_lengthT * sizeof(char*));
      port_list_length = port_list_lengthT;
      for( uint32_t i = 0; i < port_list_length; i++){
      uint32_t length_st_port_list;
      arrToVar(length_st_port_list, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_port_list; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_port_list-1]=0;
      this->st_port_list = (char *)(inbuffer + offset-1);
      offset += length_st_port_list;
        memcpy( &(this->port_list[i]), &(this->st_port_list), sizeof(char*));
      }
      uint32_t manufacturer_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      manufacturer_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      manufacturer_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      manufacturer_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->manufacturer_list_length);
      if(manufacturer_list_lengthT > manufacturer_list_length)
        this->manufacturer_list = (char**)realloc(this->manufacturer_list, manufacturer_list_lengthT * sizeof(char*));
      manufacturer_list_length = manufacturer_list_lengthT;
      for( uint32_t i = 0; i < manufacturer_list_length; i++){
      uint32_t length_st_manufacturer_list;
      arrToVar(length_st_manufacturer_list, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_manufacturer_list; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_manufacturer_list-1]=0;
      this->st_manufacturer_list = (char *)(inbuffer + offset-1);
      offset += length_st_manufacturer_list;
        memcpy( &(this->manufacturer_list[i]), &(this->st_manufacturer_list), sizeof(char*));
      }
      this->STMSuccess =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->STMSuccess);
      this->ArduinoSuccess =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ArduinoSuccess);
      this->Compassuccess =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Compassuccess);
     return offset;
    }

    virtual const char * getType() override { return HWCONTROLLERSRV; };
    virtual const char * getMD5() override { return "15c18a38ca129ceffe9c3e2ec45ec9e1"; };

  };

  class HWControllerSrv {
    public:
    typedef HWControllerSrvRequest Request;
    typedef HWControllerSrvResponse Response;
  };

}
#endif
