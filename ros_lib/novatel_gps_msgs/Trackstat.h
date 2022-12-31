#ifndef _ROS_novatel_gps_msgs_Trackstat_h
#define _ROS_novatel_gps_msgs_Trackstat_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "novatel_gps_msgs/TrackstatChannel.h"

namespace novatel_gps_msgs
{

  class Trackstat : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _solution_status_type;
      _solution_status_type solution_status;
      typedef const char* _position_type_type;
      _position_type_type position_type;
      typedef float _cutoff_type;
      _cutoff_type cutoff;
      uint32_t channels_length;
      typedef novatel_gps_msgs::TrackstatChannel _channels_type;
      _channels_type st_channels;
      _channels_type * channels;

    Trackstat():
      header(),
      solution_status(""),
      position_type(""),
      cutoff(0),
      channels_length(0), channels(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_solution_status = strlen(this->solution_status);
      varToArr(outbuffer + offset, length_solution_status);
      offset += 4;
      memcpy(outbuffer + offset, this->solution_status, length_solution_status);
      offset += length_solution_status;
      uint32_t length_position_type = strlen(this->position_type);
      varToArr(outbuffer + offset, length_position_type);
      offset += 4;
      memcpy(outbuffer + offset, this->position_type, length_position_type);
      offset += length_position_type;
      union {
        float real;
        uint32_t base;
      } u_cutoff;
      u_cutoff.real = this->cutoff;
      *(outbuffer + offset + 0) = (u_cutoff.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cutoff.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cutoff.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cutoff.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cutoff);
      *(outbuffer + offset + 0) = (this->channels_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channels_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->channels_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->channels_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->channels_length);
      for( uint32_t i = 0; i < channels_length; i++){
      offset += this->channels[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_solution_status;
      arrToVar(length_solution_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_solution_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_solution_status-1]=0;
      this->solution_status = (char *)(inbuffer + offset-1);
      offset += length_solution_status;
      uint32_t length_position_type;
      arrToVar(length_position_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_position_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_position_type-1]=0;
      this->position_type = (char *)(inbuffer + offset-1);
      offset += length_position_type;
      union {
        float real;
        uint32_t base;
      } u_cutoff;
      u_cutoff.base = 0;
      u_cutoff.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cutoff.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cutoff.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cutoff.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cutoff = u_cutoff.real;
      offset += sizeof(this->cutoff);
      uint32_t channels_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->channels_length);
      if(channels_lengthT > channels_length)
        this->channels = (novatel_gps_msgs::TrackstatChannel*)realloc(this->channels, channels_lengthT * sizeof(novatel_gps_msgs::TrackstatChannel));
      channels_length = channels_lengthT;
      for( uint32_t i = 0; i < channels_length; i++){
      offset += this->st_channels.deserialize(inbuffer + offset);
        memcpy( &(this->channels[i]), &(this->st_channels), sizeof(novatel_gps_msgs::TrackstatChannel));
      }
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/Trackstat"; };
    const char * getMD5(){ return "10e52c1ea54daca4de3c8cdda3a79817"; };

  };

}
#endif
