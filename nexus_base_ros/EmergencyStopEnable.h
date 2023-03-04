#ifndef _ROS_SERVICE_EmergencyStopEnable_h
#define _ROS_SERVICE_EmergencyStopEnable_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nexus_base_ros
{

static const char EMERGENCYSTOPENABLE[] = "nexus_base_ros/EmergencyStopEnable";

  class EmergencyStopEnableRequest : public ros::Msg
  {
    public:
      typedef bool _enable_type;
      _enable_type enable;

    EmergencyStopEnableRequest():
      enable(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.real = this->enable;
      *(outbuffer + offset + 0) = (u_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.base = 0;
      u_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable = u_enable.real;
      offset += sizeof(this->enable);
     return offset;
    }

    virtual const char * getType() override { return EMERGENCYSTOPENABLE; };
    virtual const char * getMD5() override { return "8c1211af706069c994c06e00eb59ac9e"; };

  };

  class EmergencyStopEnableResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    EmergencyStopEnableResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return EMERGENCYSTOPENABLE; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class EmergencyStopEnable {
    public:
    typedef EmergencyStopEnableRequest Request;
    typedef EmergencyStopEnableResponse Response;
  };

}
#endif
