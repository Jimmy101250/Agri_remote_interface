#ifndef _ROS_novatel_gps_msgs_Range_h
#define _ROS_novatel_gps_msgs_Range_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "novatel_gps_msgs/NovatelMessageHeader.h"
#include "novatel_gps_msgs/RangeInformation.h"

namespace novatel_gps_msgs
{

  class Range : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef novatel_gps_msgs::NovatelMessageHeader _novatel_msg_header_type;
      _novatel_msg_header_type novatel_msg_header;
      typedef int32_t _numb_of_observ_type;
      _numb_of_observ_type numb_of_observ;
      uint32_t info_length;
      typedef novatel_gps_msgs::RangeInformation _info_type;
      _info_type st_info;
      _info_type * info;

    Range():
      header(),
      novatel_msg_header(),
      numb_of_observ(0),
      info_length(0), info(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->novatel_msg_header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_numb_of_observ;
      u_numb_of_observ.real = this->numb_of_observ;
      *(outbuffer + offset + 0) = (u_numb_of_observ.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_numb_of_observ.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_numb_of_observ.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_numb_of_observ.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numb_of_observ);
      *(outbuffer + offset + 0) = (this->info_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->info_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->info_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->info_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->info_length);
      for( uint32_t i = 0; i < info_length; i++){
      offset += this->info[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->novatel_msg_header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_numb_of_observ;
      u_numb_of_observ.base = 0;
      u_numb_of_observ.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_numb_of_observ.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_numb_of_observ.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_numb_of_observ.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->numb_of_observ = u_numb_of_observ.real;
      offset += sizeof(this->numb_of_observ);
      uint32_t info_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      info_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      info_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      info_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->info_length);
      if(info_lengthT > info_length)
        this->info = (novatel_gps_msgs::RangeInformation*)realloc(this->info, info_lengthT * sizeof(novatel_gps_msgs::RangeInformation));
      info_length = info_lengthT;
      for( uint32_t i = 0; i < info_length; i++){
      offset += this->st_info.deserialize(inbuffer + offset);
        memcpy( &(this->info[i]), &(this->st_info), sizeof(novatel_gps_msgs::RangeInformation));
      }
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/Range"; };
    const char * getMD5(){ return "536f13bea0b312445fad655869b252bf"; };

  };

}
#endif
