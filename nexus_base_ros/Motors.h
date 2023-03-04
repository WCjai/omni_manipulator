#ifndef _ROS_nexus_base_ros_Motors_h
#define _ROS_nexus_base_ros_Motors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace nexus_base_ros
{

  class Motors : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _motor0_type;
      _motor0_type motor0;
      typedef int16_t _motor1_type;
      _motor1_type motor1;
      typedef int16_t _motor2_type;
      _motor2_type motor2;
      typedef int16_t _motor3_type;
      _motor3_type motor3;

    Motors():
      header(),
      motor0(0),
      motor1(0),
      motor2(0),
      motor3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_motor0;
      u_motor0.real = this->motor0;
      *(outbuffer + offset + 0) = (u_motor0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor0.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor0);
      union {
        int16_t real;
        uint16_t base;
      } u_motor1;
      u_motor1.real = this->motor1;
      *(outbuffer + offset + 0) = (u_motor1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor1.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor1);
      union {
        int16_t real;
        uint16_t base;
      } u_motor2;
      u_motor2.real = this->motor2;
      *(outbuffer + offset + 0) = (u_motor2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor2.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor2);
      union {
        int16_t real;
        uint16_t base;
      } u_motor3;
      u_motor3.real = this->motor3;
      *(outbuffer + offset + 0) = (u_motor3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor3.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_motor0;
      u_motor0.base = 0;
      u_motor0.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor0.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->motor0 = u_motor0.real;
      offset += sizeof(this->motor0);
      union {
        int16_t real;
        uint16_t base;
      } u_motor1;
      u_motor1.base = 0;
      u_motor1.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor1.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->motor1 = u_motor1.real;
      offset += sizeof(this->motor1);
      union {
        int16_t real;
        uint16_t base;
      } u_motor2;
      u_motor2.base = 0;
      u_motor2.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor2.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->motor2 = u_motor2.real;
      offset += sizeof(this->motor2);
      union {
        int16_t real;
        uint16_t base;
      } u_motor3;
      u_motor3.base = 0;
      u_motor3.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor3.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->motor3 = u_motor3.real;
      offset += sizeof(this->motor3);
     return offset;
    }

    virtual const char * getType() override { return "nexus_base_ros/Motors"; };
    virtual const char * getMD5() override { return "719eec730df6a3a60b418715ff2725dd"; };

  };

}
#endif
