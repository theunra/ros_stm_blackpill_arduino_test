#ifndef _ROS_SERVICE_CommunicationService_h
#define _ROS_SERVICE_CommunicationService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fukuro_common
{

static const char COMMUNICATIONSERVICE[] = "fukuro_common/CommunicationService";

  class CommunicationServiceRequest : public ros::Msg
  {
    public:
      typedef uint8_t _connect_type;
      _connect_type connect;
      typedef const char* _address_type;
      _address_type address;
      typedef int64_t _tx_port_type;
      _tx_port_type tx_port;
      typedef int64_t _rx_port_type;
      _rx_port_type rx_port;

    CommunicationServiceRequest():
      connect(0),
      address(""),
      tx_port(0),
      rx_port(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->connect >> (8 * 0)) & 0xFF;
      offset += sizeof(this->connect);
      uint32_t length_address = strlen(this->address);
      varToArr(outbuffer + offset, length_address);
      offset += 4;
      memcpy(outbuffer + offset, this->address, length_address);
      offset += length_address;
      union {
        int64_t real;
        uint64_t base;
      } u_tx_port;
      u_tx_port.real = this->tx_port;
      *(outbuffer + offset + 0) = (u_tx_port.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tx_port.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tx_port.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tx_port.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tx_port.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tx_port.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tx_port.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tx_port.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->tx_port);
      union {
        int64_t real;
        uint64_t base;
      } u_rx_port;
      u_rx_port.real = this->rx_port;
      *(outbuffer + offset + 0) = (u_rx_port.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rx_port.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rx_port.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rx_port.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rx_port.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rx_port.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rx_port.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rx_port.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rx_port);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->connect =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->connect);
      uint32_t length_address;
      arrToVar(length_address, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_address; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_address-1]=0;
      this->address = (char *)(inbuffer + offset-1);
      offset += length_address;
      union {
        int64_t real;
        uint64_t base;
      } u_tx_port;
      u_tx_port.base = 0;
      u_tx_port.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tx_port.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tx_port.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tx_port.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_tx_port.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_tx_port.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_tx_port.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_tx_port.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->tx_port = u_tx_port.real;
      offset += sizeof(this->tx_port);
      union {
        int64_t real;
        uint64_t base;
      } u_rx_port;
      u_rx_port.base = 0;
      u_rx_port.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rx_port.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rx_port.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rx_port.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rx_port.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rx_port.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rx_port.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rx_port.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rx_port = u_rx_port.real;
      offset += sizeof(this->rx_port);
     return offset;
    }

    virtual const char * getType() override { return COMMUNICATIONSERVICE; };
    virtual const char * getMD5() override { return "9850078dcf04bfa18c947ca41a0a993a"; };

  };

  class CommunicationServiceResponse : public ros::Msg
  {
    public:
      typedef uint8_t _success_type;
      _success_type success;

    CommunicationServiceResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->success >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->success =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return COMMUNICATIONSERVICE; };
    virtual const char * getMD5() override { return "6cca7c80398b8b31af04b80534923f16"; };

  };

  class CommunicationService {
    public:
    typedef CommunicationServiceRequest Request;
    typedef CommunicationServiceResponse Response;
  };

}
#endif
