#ifndef _ROS_novatel_gps_msgs_NovatelHeading2_h
#define _ROS_novatel_gps_msgs_NovatelHeading2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "novatel_gps_msgs/NovatelMessageHeader.h"
#include "novatel_gps_msgs/NovatelExtendedSolutionStatus.h"
#include "novatel_gps_msgs/NovatelSignalMask.h"

namespace novatel_gps_msgs
{

  class NovatelHeading2 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef novatel_gps_msgs::NovatelMessageHeader _novatel_msg_header_type;
      _novatel_msg_header_type novatel_msg_header;
      typedef const char* _solution_status_type;
      _solution_status_type solution_status;
      typedef const char* _position_type_type;
      _position_type_type position_type;
      typedef float _baseline_length_type;
      _baseline_length_type baseline_length;
      typedef float _heading_type;
      _heading_type heading;
      typedef float _pitch_type;
      _pitch_type pitch;
      typedef float _heading_sigma_type;
      _heading_sigma_type heading_sigma;
      typedef float _pitch_sigma_type;
      _pitch_sigma_type pitch_sigma;
      typedef const char* _rover_station_id_type;
      _rover_station_id_type rover_station_id;
      typedef const char* _master_station_id_type;
      _master_station_id_type master_station_id;
      typedef uint8_t _num_satellites_tracked_type;
      _num_satellites_tracked_type num_satellites_tracked;
      typedef uint8_t _num_satellites_used_in_solution_type;
      _num_satellites_used_in_solution_type num_satellites_used_in_solution;
      typedef uint8_t _num_satellites_above_elevation_mask_angle_type;
      _num_satellites_above_elevation_mask_angle_type num_satellites_above_elevation_mask_angle;
      typedef uint8_t _num_satellites_above_elevation_mask_angle_l2_type;
      _num_satellites_above_elevation_mask_angle_l2_type num_satellites_above_elevation_mask_angle_l2;
      typedef uint8_t _solution_source_type;
      _solution_source_type solution_source;
      typedef novatel_gps_msgs::NovatelExtendedSolutionStatus _extended_solution_status_type;
      _extended_solution_status_type extended_solution_status;
      typedef novatel_gps_msgs::NovatelSignalMask _signal_mask_type;
      _signal_mask_type signal_mask;
      enum { SOURCE_PRIMARY_ANTENNA = 0 };
      enum { SOURCE_SECONDARY_ANTENNA = 1 };

    NovatelHeading2():
      header(),
      novatel_msg_header(),
      solution_status(""),
      position_type(""),
      baseline_length(0),
      heading(0),
      pitch(0),
      heading_sigma(0),
      pitch_sigma(0),
      rover_station_id(""),
      master_station_id(""),
      num_satellites_tracked(0),
      num_satellites_used_in_solution(0),
      num_satellites_above_elevation_mask_angle(0),
      num_satellites_above_elevation_mask_angle_l2(0),
      solution_source(0),
      extended_solution_status(),
      signal_mask()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->novatel_msg_header.serialize(outbuffer + offset);
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
      } u_baseline_length;
      u_baseline_length.real = this->baseline_length;
      *(outbuffer + offset + 0) = (u_baseline_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_baseline_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_baseline_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_baseline_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->baseline_length);
      union {
        float real;
        uint32_t base;
      } u_heading;
      u_heading.real = this->heading;
      *(outbuffer + offset + 0) = (u_heading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->heading);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_heading_sigma;
      u_heading_sigma.real = this->heading_sigma;
      *(outbuffer + offset + 0) = (u_heading_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->heading_sigma);
      union {
        float real;
        uint32_t base;
      } u_pitch_sigma;
      u_pitch_sigma.real = this->pitch_sigma;
      *(outbuffer + offset + 0) = (u_pitch_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch_sigma);
      uint32_t length_rover_station_id = strlen(this->rover_station_id);
      varToArr(outbuffer + offset, length_rover_station_id);
      offset += 4;
      memcpy(outbuffer + offset, this->rover_station_id, length_rover_station_id);
      offset += length_rover_station_id;
      uint32_t length_master_station_id = strlen(this->master_station_id);
      varToArr(outbuffer + offset, length_master_station_id);
      offset += 4;
      memcpy(outbuffer + offset, this->master_station_id, length_master_station_id);
      offset += length_master_station_id;
      *(outbuffer + offset + 0) = (this->num_satellites_tracked >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_satellites_tracked);
      *(outbuffer + offset + 0) = (this->num_satellites_used_in_solution >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_satellites_used_in_solution);
      *(outbuffer + offset + 0) = (this->num_satellites_above_elevation_mask_angle >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_satellites_above_elevation_mask_angle);
      *(outbuffer + offset + 0) = (this->num_satellites_above_elevation_mask_angle_l2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_satellites_above_elevation_mask_angle_l2);
      *(outbuffer + offset + 0) = (this->solution_source >> (8 * 0)) & 0xFF;
      offset += sizeof(this->solution_source);
      offset += this->extended_solution_status.serialize(outbuffer + offset);
      offset += this->signal_mask.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->novatel_msg_header.deserialize(inbuffer + offset);
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
      } u_baseline_length;
      u_baseline_length.base = 0;
      u_baseline_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_baseline_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_baseline_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_baseline_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->baseline_length = u_baseline_length.real;
      offset += sizeof(this->baseline_length);
      union {
        float real;
        uint32_t base;
      } u_heading;
      u_heading.base = 0;
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->heading = u_heading.real;
      offset += sizeof(this->heading);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_heading_sigma;
      u_heading_sigma.base = 0;
      u_heading_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->heading_sigma = u_heading_sigma.real;
      offset += sizeof(this->heading_sigma);
      union {
        float real;
        uint32_t base;
      } u_pitch_sigma;
      u_pitch_sigma.base = 0;
      u_pitch_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch_sigma = u_pitch_sigma.real;
      offset += sizeof(this->pitch_sigma);
      uint32_t length_rover_station_id;
      arrToVar(length_rover_station_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_rover_station_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_rover_station_id-1]=0;
      this->rover_station_id = (char *)(inbuffer + offset-1);
      offset += length_rover_station_id;
      uint32_t length_master_station_id;
      arrToVar(length_master_station_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_master_station_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_master_station_id-1]=0;
      this->master_station_id = (char *)(inbuffer + offset-1);
      offset += length_master_station_id;
      this->num_satellites_tracked =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_satellites_tracked);
      this->num_satellites_used_in_solution =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_satellites_used_in_solution);
      this->num_satellites_above_elevation_mask_angle =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_satellites_above_elevation_mask_angle);
      this->num_satellites_above_elevation_mask_angle_l2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_satellites_above_elevation_mask_angle_l2);
      this->solution_source =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->solution_source);
      offset += this->extended_solution_status.deserialize(inbuffer + offset);
      offset += this->signal_mask.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/NovatelHeading2"; };
    const char * getMD5(){ return "1195c3bddd7a9ddbaf770e688a2f354a"; };

  };

}
#endif
