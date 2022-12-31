#ifndef _ROS_novatel_gps_msgs_Inspva_h
#define _ROS_novatel_gps_msgs_Inspva_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "novatel_gps_msgs/NovatelMessageHeader.h"

namespace novatel_gps_msgs
{

  class Inspva : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef novatel_gps_msgs::NovatelMessageHeader _novatel_msg_header_type;
      _novatel_msg_header_type novatel_msg_header;
      typedef uint32_t _week_type;
      _week_type week;
      typedef double _seconds_type;
      _seconds_type seconds;
      typedef double _latitude_type;
      _latitude_type latitude;
      typedef double _longitude_type;
      _longitude_type longitude;
      typedef double _height_type;
      _height_type height;
      typedef double _north_velocity_type;
      _north_velocity_type north_velocity;
      typedef double _east_velocity_type;
      _east_velocity_type east_velocity;
      typedef double _up_velocity_type;
      _up_velocity_type up_velocity;
      typedef double _roll_type;
      _roll_type roll;
      typedef double _pitch_type;
      _pitch_type pitch;
      typedef double _azimuth_type;
      _azimuth_type azimuth;
      typedef const char* _status_type;
      _status_type status;

    Inspva():
      header(),
      novatel_msg_header(),
      week(0),
      seconds(0),
      latitude(0),
      longitude(0),
      height(0),
      north_velocity(0),
      east_velocity(0),
      up_velocity(0),
      roll(0),
      pitch(0),
      azimuth(0),
      status("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->novatel_msg_header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->week >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->week >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->week >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->week >> (8 * 3)) & 0xFF;
      offset += sizeof(this->week);
      union {
        double real;
        uint64_t base;
      } u_seconds;
      u_seconds.real = this->seconds;
      *(outbuffer + offset + 0) = (u_seconds.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_seconds.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_seconds.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_seconds.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_seconds.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_seconds.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_seconds.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_seconds.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->seconds);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_latitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_latitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_latitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_latitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_longitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_longitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_longitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_longitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->longitude);
      union {
        double real;
        uint64_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_height.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_height.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_height.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_height.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->height);
      union {
        double real;
        uint64_t base;
      } u_north_velocity;
      u_north_velocity.real = this->north_velocity;
      *(outbuffer + offset + 0) = (u_north_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_north_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_north_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_north_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_north_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_north_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_north_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_north_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->north_velocity);
      union {
        double real;
        uint64_t base;
      } u_east_velocity;
      u_east_velocity.real = this->east_velocity;
      *(outbuffer + offset + 0) = (u_east_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_east_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_east_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_east_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_east_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_east_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_east_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_east_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->east_velocity);
      union {
        double real;
        uint64_t base;
      } u_up_velocity;
      u_up_velocity.real = this->up_velocity;
      *(outbuffer + offset + 0) = (u_up_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_up_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_up_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_up_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_up_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_up_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_up_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_up_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->up_velocity);
      union {
        double real;
        uint64_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_roll.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_roll.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_roll.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_roll.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->roll);
      union {
        double real;
        uint64_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pitch.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pitch.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pitch.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pitch.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        double real;
        uint64_t base;
      } u_azimuth;
      u_azimuth.real = this->azimuth;
      *(outbuffer + offset + 0) = (u_azimuth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_azimuth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_azimuth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_azimuth.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_azimuth.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_azimuth.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_azimuth.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_azimuth.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->azimuth);
      uint32_t length_status = strlen(this->status);
      varToArr(outbuffer + offset, length_status);
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->novatel_msg_header.deserialize(inbuffer + offset);
      this->week =  ((uint32_t) (*(inbuffer + offset)));
      this->week |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->week |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->week |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->week);
      union {
        double real;
        uint64_t base;
      } u_seconds;
      u_seconds.base = 0;
      u_seconds.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_seconds.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_seconds.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_seconds.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_seconds.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_seconds.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_seconds.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_seconds.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->seconds = u_seconds.real;
      offset += sizeof(this->seconds);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      union {
        double real;
        uint64_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->height = u_height.real;
      offset += sizeof(this->height);
      union {
        double real;
        uint64_t base;
      } u_north_velocity;
      u_north_velocity.base = 0;
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->north_velocity = u_north_velocity.real;
      offset += sizeof(this->north_velocity);
      union {
        double real;
        uint64_t base;
      } u_east_velocity;
      u_east_velocity.base = 0;
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->east_velocity = u_east_velocity.real;
      offset += sizeof(this->east_velocity);
      union {
        double real;
        uint64_t base;
      } u_up_velocity;
      u_up_velocity.base = 0;
      u_up_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_up_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_up_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_up_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_up_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_up_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_up_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_up_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->up_velocity = u_up_velocity.real;
      offset += sizeof(this->up_velocity);
      union {
        double real;
        uint64_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      union {
        double real;
        uint64_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        double real;
        uint64_t base;
      } u_azimuth;
      u_azimuth.base = 0;
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_azimuth.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->azimuth = u_azimuth.real;
      offset += sizeof(this->azimuth);
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

    const char * getType(){ return "novatel_gps_msgs/Inspva"; };
    const char * getMD5(){ return "f6fbcfee08847158b28edeb7f76b942f"; };

  };

}
#endif
