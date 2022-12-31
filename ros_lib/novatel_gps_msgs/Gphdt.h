#ifndef _ROS_novatel_gps_msgs_Gphdt_h
#define _ROS_novatel_gps_msgs_Gphdt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace novatel_gps_msgs
{

  class Gphdt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _message_id_type;
      _message_id_type message_id;
      typedef double _heading_type;
      _heading_type heading;
      typedef const char* _t_type;
      _t_type t;

    Gphdt():
      header(),
      message_id(""),
      heading(0),
      t("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_message_id = strlen(this->message_id);
      varToArr(outbuffer + offset, length_message_id);
      offset += 4;
      memcpy(outbuffer + offset, this->message_id, length_message_id);
      offset += length_message_id;
      union {
        double real;
        uint64_t base;
      } u_heading;
      u_heading.real = this->heading;
      *(outbuffer + offset + 0) = (u_heading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_heading.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_heading.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_heading.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_heading.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->heading);
      uint32_t length_t = strlen(this->t);
      varToArr(outbuffer + offset, length_t);
      offset += 4;
      memcpy(outbuffer + offset, this->t, length_t);
      offset += length_t;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_message_id;
      arrToVar(length_message_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message_id-1]=0;
      this->message_id = (char *)(inbuffer + offset-1);
      offset += length_message_id;
      union {
        double real;
        uint64_t base;
      } u_heading;
      u_heading.base = 0;
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->heading = u_heading.real;
      offset += sizeof(this->heading);
      uint32_t length_t;
      arrToVar(length_t, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_t; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_t-1]=0;
      this->t = (char *)(inbuffer + offset-1);
      offset += length_t;
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/Gphdt"; };
    const char * getMD5(){ return "ddf912a83c312999924f468d3d13a183"; };

  };

}
#endif
