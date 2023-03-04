#ifndef _ROS_nexus_base_ros_Encoders_h
#define _ROS_nexus_base_ros_Encoders_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace nexus_base_ros
{

  class Encoders : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _enc0_type;
      _enc0_type enc0;
      typedef int16_t _enc1_type;
      _enc1_type enc1;
      typedef int16_t _enc2_type;
      _enc2_type enc2;
      typedef int16_t _enc3_type;
      _enc3_type enc3;

    Encoders():
      header(),
      enc0(0),
      enc1(0),
      enc2(0),
      enc3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_enc0;
      u_enc0.real = this->enc0;
      *(outbuffer + offset + 0) = (u_enc0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_enc0.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->enc0);
      union {
        int16_t real;
        uint16_t base;
      } u_enc1;
      u_enc1.real = this->enc1;
      *(outbuffer + offset + 0) = (u_enc1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_enc1.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->enc1);
      union {
        int16_t real;
        uint16_t base;
      } u_enc2;
      u_enc2.real = this->enc2;
      *(outbuffer + offset + 0) = (u_enc2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_enc2.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->enc2);
      union {
        int16_t real;
        uint16_t base;
      } u_enc3;
      u_enc3.real = this->enc3;
      *(outbuffer + offset + 0) = (u_enc3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_enc3.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->enc3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_enc0;
      u_enc0.base = 0;
      u_enc0.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_enc0.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->enc0 = u_enc0.real;
      offset += sizeof(this->enc0);
      union {
        int16_t real;
        uint16_t base;
      } u_enc1;
      u_enc1.base = 0;
      u_enc1.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_enc1.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->enc1 = u_enc1.real;
      offset += sizeof(this->enc1);
      union {
        int16_t real;
        uint16_t base;
      } u_enc2;
      u_enc2.base = 0;
      u_enc2.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_enc2.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->enc2 = u_enc2.real;
      offset += sizeof(this->enc2);
      union {
        int16_t real;
        uint16_t base;
      } u_enc3;
      u_enc3.base = 0;
      u_enc3.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_enc3.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->enc3 = u_enc3.real;
      offset += sizeof(this->enc3);
     return offset;
    }

    virtual const char * getType() override { return "nexus_base_ros/Encoders"; };
    virtual const char * getMD5() override { return "91265c100859579da2418bced8966c34"; };

  };

}
#endif
