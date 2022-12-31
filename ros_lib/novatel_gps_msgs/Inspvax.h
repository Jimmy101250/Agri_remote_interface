#ifndef _ROS_novatel_gps_msgs_Inspvax_h
#define _ROS_novatel_gps_msgs_Inspvax_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "novatel_gps_msgs/NovatelMessageHeader.h"
#include "novatel_gps_msgs/NovatelExtendedSolutionStatus.h"

namespace novatel_gps_msgs
{

  class Inspvax : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef novatel_gps_msgs::NovatelMessageHeader _novatel_msg_header_type;
      _novatel_msg_header_type novatel_msg_header;
      typedef const char* _ins_status_type;
      _ins_status_type ins_status;
      typedef const char* _position_type_type;
      _position_type_type position_type;
      typedef double _latitude_type;
      _latitude_type latitude;
      typedef double _longitude_type;
      _longitude_type longitude;
      typedef double _altitude_type;
      _altitude_type altitude;
      typedef float _undulation_type;
      _undulation_type undulation;
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
      typedef float _latitude_std_type;
      _latitude_std_type latitude_std;
      typedef float _longitude_std_type;
      _longitude_std_type longitude_std;
      typedef float _altitude_std_type;
      _altitude_std_type altitude_std;
      typedef float _north_velocity_std_type;
      _north_velocity_std_type north_velocity_std;
      typedef float _east_velocity_std_type;
      _east_velocity_std_type east_velocity_std;
      typedef float _up_velocity_std_type;
      _up_velocity_std_type up_velocity_std;
      typedef float _roll_std_type;
      _roll_std_type roll_std;
      typedef float _pitch_std_type;
      _pitch_std_type pitch_std;
      typedef float _azimuth_std_type;
      _azimuth_std_type azimuth_std;
      typedef novatel_gps_msgs::NovatelExtendedSolutionStatus _extended_status_type;
      _extended_status_type extended_status;
      typedef uint16_t _seconds_since_update_type;
      _seconds_since_update_type seconds_since_update;

    Inspvax():
      header(),
      novatel_msg_header(),
      ins_status(""),
      position_type(""),
      latitude(0),
      longitude(0),
      altitude(0),
      undulation(0),
      north_velocity(0),
      east_velocity(0),
      up_velocity(0),
      roll(0),
      pitch(0),
      azimuth(0),
      latitude_std(0),
      longitude_std(0),
      altitude_std(0),
      north_velocity_std(0),
      east_velocity_std(0),
      up_velocity_std(0),
      roll_std(0),
      pitch_std(0),
      azimuth_std(0),
      extended_status(),
      seconds_since_update(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->novatel_msg_header.serialize(outbuffer + offset);
      uint32_t length_ins_status = strlen(this->ins_status);
      varToArr(outbuffer + offset, length_ins_status);
      offset += 4;
      memcpy(outbuffer + offset, this->ins_status, length_ins_status);
      offset += length_ins_status;
      uint32_t length_position_type = strlen(this->position_type);
      varToArr(outbuffer + offset, length_position_type);
      offset += 4;
      memcpy(outbuffer + offset, this->position_type, length_position_type);
      offset += length_position_type;
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
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_altitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_altitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_altitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_altitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_undulation;
      u_undulation.real = this->undulation;
      *(outbuffer + offset + 0) = (u_undulation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_undulation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_undulation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_undulation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->undulation);
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
      union {
        float real;
        uint32_t base;
      } u_latitude_std;
      u_latitude_std.real = this->latitude_std;
      *(outbuffer + offset + 0) = (u_latitude_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude_std);
      union {
        float real;
        uint32_t base;
      } u_longitude_std;
      u_longitude_std.real = this->longitude_std;
      *(outbuffer + offset + 0) = (u_longitude_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitude_std);
      union {
        float real;
        uint32_t base;
      } u_altitude_std;
      u_altitude_std.real = this->altitude_std;
      *(outbuffer + offset + 0) = (u_altitude_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude_std);
      union {
        float real;
        uint32_t base;
      } u_north_velocity_std;
      u_north_velocity_std.real = this->north_velocity_std;
      *(outbuffer + offset + 0) = (u_north_velocity_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_north_velocity_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_north_velocity_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_north_velocity_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->north_velocity_std);
      union {
        float real;
        uint32_t base;
      } u_east_velocity_std;
      u_east_velocity_std.real = this->east_velocity_std;
      *(outbuffer + offset + 0) = (u_east_velocity_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_east_velocity_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_east_velocity_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_east_velocity_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->east_velocity_std);
      union {
        float real;
        uint32_t base;
      } u_up_velocity_std;
      u_up_velocity_std.real = this->up_velocity_std;
      *(outbuffer + offset + 0) = (u_up_velocity_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_up_velocity_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_up_velocity_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_up_velocity_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->up_velocity_std);
      union {
        float real;
        uint32_t base;
      } u_roll_std;
      u_roll_std.real = this->roll_std;
      *(outbuffer + offset + 0) = (u_roll_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll_std);
      union {
        float real;
        uint32_t base;
      } u_pitch_std;
      u_pitch_std.real = this->pitch_std;
      *(outbuffer + offset + 0) = (u_pitch_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch_std);
      union {
        float real;
        uint32_t base;
      } u_azimuth_std;
      u_azimuth_std.real = this->azimuth_std;
      *(outbuffer + offset + 0) = (u_azimuth_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_azimuth_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_azimuth_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_azimuth_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->azimuth_std);
      offset += this->extended_status.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->seconds_since_update >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seconds_since_update >> (8 * 1)) & 0xFF;
      offset += sizeof(this->seconds_since_update);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->novatel_msg_header.deserialize(inbuffer + offset);
      uint32_t length_ins_status;
      arrToVar(length_ins_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ins_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ins_status-1]=0;
      this->ins_status = (char *)(inbuffer + offset-1);
      offset += length_ins_status;
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
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_undulation;
      u_undulation.base = 0;
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->undulation = u_undulation.real;
      offset += sizeof(this->undulation);
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
      union {
        float real;
        uint32_t base;
      } u_latitude_std;
      u_latitude_std.base = 0;
      u_latitude_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude_std = u_latitude_std.real;
      offset += sizeof(this->latitude_std);
      union {
        float real;
        uint32_t base;
      } u_longitude_std;
      u_longitude_std.base = 0;
      u_longitude_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitude_std = u_longitude_std.real;
      offset += sizeof(this->longitude_std);
      union {
        float real;
        uint32_t base;
      } u_altitude_std;
      u_altitude_std.base = 0;
      u_altitude_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude_std = u_altitude_std.real;
      offset += sizeof(this->altitude_std);
      union {
        float real;
        uint32_t base;
      } u_north_velocity_std;
      u_north_velocity_std.base = 0;
      u_north_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_north_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_north_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_north_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->north_velocity_std = u_north_velocity_std.real;
      offset += sizeof(this->north_velocity_std);
      union {
        float real;
        uint32_t base;
      } u_east_velocity_std;
      u_east_velocity_std.base = 0;
      u_east_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_east_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_east_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_east_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->east_velocity_std = u_east_velocity_std.real;
      offset += sizeof(this->east_velocity_std);
      union {
        float real;
        uint32_t base;
      } u_up_velocity_std;
      u_up_velocity_std.base = 0;
      u_up_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_up_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_up_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_up_velocity_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->up_velocity_std = u_up_velocity_std.real;
      offset += sizeof(this->up_velocity_std);
      union {
        float real;
        uint32_t base;
      } u_roll_std;
      u_roll_std.base = 0;
      u_roll_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll_std = u_roll_std.real;
      offset += sizeof(this->roll_std);
      union {
        float real;
        uint32_t base;
      } u_pitch_std;
      u_pitch_std.base = 0;
      u_pitch_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch_std = u_pitch_std.real;
      offset += sizeof(this->pitch_std);
      union {
        float real;
        uint32_t base;
      } u_azimuth_std;
      u_azimuth_std.base = 0;
      u_azimuth_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_azimuth_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_azimuth_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_azimuth_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->azimuth_std = u_azimuth_std.real;
      offset += sizeof(this->azimuth_std);
      offset += this->extended_status.deserialize(inbuffer + offset);
      this->seconds_since_update =  ((uint16_t) (*(inbuffer + offset)));
      this->seconds_since_update |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->seconds_since_update);
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/Inspvax"; };
    const char * getMD5(){ return "cebf3b182479d01907e3894361b97eba"; };

  };

}
#endif
