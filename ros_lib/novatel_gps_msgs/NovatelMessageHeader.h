#ifndef _ROS_novatel_gps_msgs_NovatelMessageHeader_h
#define _ROS_novatel_gps_msgs_NovatelMessageHeader_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "novatel_gps_msgs/NovatelReceiverStatus.h"

namespace novatel_gps_msgs
{

  class NovatelMessageHeader : public ros::Msg
  {
    public:
      typedef const char* _message_name_type;
      _message_name_type message_name;
      typedef const char* _port_type;
      _port_type port;
      typedef uint32_t _sequence_num_type;
      _sequence_num_type sequence_num;
      typedef float _percent_idle_time_type;
      _percent_idle_time_type percent_idle_time;
      typedef const char* _gps_time_status_type;
      _gps_time_status_type gps_time_status;
      typedef uint32_t _gps_week_num_type;
      _gps_week_num_type gps_week_num;
      typedef double _gps_seconds_type;
      _gps_seconds_type gps_seconds;
      typedef novatel_gps_msgs::NovatelReceiverStatus _receiver_status_type;
      _receiver_status_type receiver_status;
      typedef uint32_t _receiver_software_version_type;
      _receiver_software_version_type receiver_software_version;

    NovatelMessageHeader():
      message_name(""),
      port(""),
      sequence_num(0),
      percent_idle_time(0),
      gps_time_status(""),
      gps_week_num(0),
      gps_seconds(0),
      receiver_status(),
      receiver_software_version(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_message_name = strlen(this->message_name);
      varToArr(outbuffer + offset, length_message_name);
      offset += 4;
      memcpy(outbuffer + offset, this->message_name, length_message_name);
      offset += length_message_name;
      uint32_t length_port = strlen(this->port);
      varToArr(outbuffer + offset, length_port);
      offset += 4;
      memcpy(outbuffer + offset, this->port, length_port);
      offset += length_port;
      *(outbuffer + offset + 0) = (this->sequence_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sequence_num >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sequence_num >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sequence_num >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sequence_num);
      union {
        float real;
        uint32_t base;
      } u_percent_idle_time;
      u_percent_idle_time.real = this->percent_idle_time;
      *(outbuffer + offset + 0) = (u_percent_idle_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_percent_idle_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_percent_idle_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_percent_idle_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->percent_idle_time);
      uint32_t length_gps_time_status = strlen(this->gps_time_status);
      varToArr(outbuffer + offset, length_gps_time_status);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_time_status, length_gps_time_status);
      offset += length_gps_time_status;
      *(outbuffer + offset + 0) = (this->gps_week_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gps_week_num >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gps_week_num >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gps_week_num >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gps_week_num);
      union {
        double real;
        uint64_t base;
      } u_gps_seconds;
      u_gps_seconds.real = this->gps_seconds;
      *(outbuffer + offset + 0) = (u_gps_seconds.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gps_seconds.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gps_seconds.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gps_seconds.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_gps_seconds.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_gps_seconds.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_gps_seconds.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_gps_seconds.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->gps_seconds);
      offset += this->receiver_status.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->receiver_software_version >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->receiver_software_version >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->receiver_software_version >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->receiver_software_version >> (8 * 3)) & 0xFF;
      offset += sizeof(this->receiver_software_version);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_message_name;
      arrToVar(length_message_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message_name-1]=0;
      this->message_name = (char *)(inbuffer + offset-1);
      offset += length_message_name;
      uint32_t length_port;
      arrToVar(length_port, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_port; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_port-1]=0;
      this->port = (char *)(inbuffer + offset-1);
      offset += length_port;
      this->sequence_num =  ((uint32_t) (*(inbuffer + offset)));
      this->sequence_num |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sequence_num |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sequence_num |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sequence_num);
      union {
        float real;
        uint32_t base;
      } u_percent_idle_time;
      u_percent_idle_time.base = 0;
      u_percent_idle_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_percent_idle_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_percent_idle_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_percent_idle_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->percent_idle_time = u_percent_idle_time.real;
      offset += sizeof(this->percent_idle_time);
      uint32_t length_gps_time_status;
      arrToVar(length_gps_time_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_time_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_time_status-1]=0;
      this->gps_time_status = (char *)(inbuffer + offset-1);
      offset += length_gps_time_status;
      this->gps_week_num =  ((uint32_t) (*(inbuffer + offset)));
      this->gps_week_num |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gps_week_num |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->gps_week_num |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->gps_week_num);
      union {
        double real;
        uint64_t base;
      } u_gps_seconds;
      u_gps_seconds.base = 0;
      u_gps_seconds.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gps_seconds.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gps_seconds.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gps_seconds.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_gps_seconds.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_gps_seconds.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_gps_seconds.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_gps_seconds.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->gps_seconds = u_gps_seconds.real;
      offset += sizeof(this->gps_seconds);
      offset += this->receiver_status.deserialize(inbuffer + offset);
      this->receiver_software_version =  ((uint32_t) (*(inbuffer + offset)));
      this->receiver_software_version |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->receiver_software_version |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->receiver_software_version |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->receiver_software_version);
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/NovatelMessageHeader"; };
    const char * getMD5(){ return "43b536606c527a56309297282bb7adef"; };

  };

}
#endif
