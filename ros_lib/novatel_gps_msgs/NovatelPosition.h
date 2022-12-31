#ifndef _ROS_novatel_gps_msgs_NovatelPosition_h
#define _ROS_novatel_gps_msgs_NovatelPosition_h

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

  class NovatelPosition : public ros::Msg
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
      typedef double _lat_type;
      _lat_type lat;
      typedef double _lon_type;
      _lon_type lon;
      typedef double _height_type;
      _height_type height;
      typedef float _undulation_type;
      _undulation_type undulation;
      typedef const char* _datum_id_type;
      _datum_id_type datum_id;
      typedef float _lat_sigma_type;
      _lat_sigma_type lat_sigma;
      typedef float _lon_sigma_type;
      _lon_sigma_type lon_sigma;
      typedef float _height_sigma_type;
      _height_sigma_type height_sigma;
      typedef const char* _base_station_id_type;
      _base_station_id_type base_station_id;
      typedef float _diff_age_type;
      _diff_age_type diff_age;
      typedef float _solution_age_type;
      _solution_age_type solution_age;
      typedef uint8_t _num_satellites_tracked_type;
      _num_satellites_tracked_type num_satellites_tracked;
      typedef uint8_t _num_satellites_used_in_solution_type;
      _num_satellites_used_in_solution_type num_satellites_used_in_solution;
      typedef uint8_t _num_gps_and_glonass_l1_used_in_solution_type;
      _num_gps_and_glonass_l1_used_in_solution_type num_gps_and_glonass_l1_used_in_solution;
      typedef uint8_t _num_gps_and_glonass_l1_and_l2_used_in_solution_type;
      _num_gps_and_glonass_l1_and_l2_used_in_solution_type num_gps_and_glonass_l1_and_l2_used_in_solution;
      typedef novatel_gps_msgs::NovatelExtendedSolutionStatus _extended_solution_status_type;
      _extended_solution_status_type extended_solution_status;
      typedef novatel_gps_msgs::NovatelSignalMask _signal_mask_type;
      _signal_mask_type signal_mask;

    NovatelPosition():
      header(),
      novatel_msg_header(),
      solution_status(""),
      position_type(""),
      lat(0),
      lon(0),
      height(0),
      undulation(0),
      datum_id(""),
      lat_sigma(0),
      lon_sigma(0),
      height_sigma(0),
      base_station_id(""),
      diff_age(0),
      solution_age(0),
      num_satellites_tracked(0),
      num_satellites_used_in_solution(0),
      num_gps_and_glonass_l1_used_in_solution(0),
      num_gps_and_glonass_l1_and_l2_used_in_solution(0),
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
        double real;
        uint64_t base;
      } u_lat;
      u_lat.real = this->lat;
      *(outbuffer + offset + 0) = (u_lat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lat.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lat.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lat.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lat.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lat.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lat);
      union {
        double real;
        uint64_t base;
      } u_lon;
      u_lon.real = this->lon;
      *(outbuffer + offset + 0) = (u_lon.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lon.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lon.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lon.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lon.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lon.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lon.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lon.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lon);
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
        float real;
        uint32_t base;
      } u_undulation;
      u_undulation.real = this->undulation;
      *(outbuffer + offset + 0) = (u_undulation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_undulation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_undulation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_undulation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->undulation);
      uint32_t length_datum_id = strlen(this->datum_id);
      varToArr(outbuffer + offset, length_datum_id);
      offset += 4;
      memcpy(outbuffer + offset, this->datum_id, length_datum_id);
      offset += length_datum_id;
      union {
        float real;
        uint32_t base;
      } u_lat_sigma;
      u_lat_sigma.real = this->lat_sigma;
      *(outbuffer + offset + 0) = (u_lat_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lat_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lat_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lat_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lat_sigma);
      union {
        float real;
        uint32_t base;
      } u_lon_sigma;
      u_lon_sigma.real = this->lon_sigma;
      *(outbuffer + offset + 0) = (u_lon_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lon_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lon_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lon_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lon_sigma);
      union {
        float real;
        uint32_t base;
      } u_height_sigma;
      u_height_sigma.real = this->height_sigma;
      *(outbuffer + offset + 0) = (u_height_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height_sigma);
      uint32_t length_base_station_id = strlen(this->base_station_id);
      varToArr(outbuffer + offset, length_base_station_id);
      offset += 4;
      memcpy(outbuffer + offset, this->base_station_id, length_base_station_id);
      offset += length_base_station_id;
      union {
        float real;
        uint32_t base;
      } u_diff_age;
      u_diff_age.real = this->diff_age;
      *(outbuffer + offset + 0) = (u_diff_age.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_diff_age.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_diff_age.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_diff_age.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->diff_age);
      union {
        float real;
        uint32_t base;
      } u_solution_age;
      u_solution_age.real = this->solution_age;
      *(outbuffer + offset + 0) = (u_solution_age.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_solution_age.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_solution_age.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_solution_age.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->solution_age);
      *(outbuffer + offset + 0) = (this->num_satellites_tracked >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_satellites_tracked);
      *(outbuffer + offset + 0) = (this->num_satellites_used_in_solution >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_satellites_used_in_solution);
      *(outbuffer + offset + 0) = (this->num_gps_and_glonass_l1_used_in_solution >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_gps_and_glonass_l1_used_in_solution);
      *(outbuffer + offset + 0) = (this->num_gps_and_glonass_l1_and_l2_used_in_solution >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_gps_and_glonass_l1_and_l2_used_in_solution);
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
        double real;
        uint64_t base;
      } u_lat;
      u_lat.base = 0;
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->lat = u_lat.real;
      offset += sizeof(this->lat);
      union {
        double real;
        uint64_t base;
      } u_lon;
      u_lon.base = 0;
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->lon = u_lon.real;
      offset += sizeof(this->lon);
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
      uint32_t length_datum_id;
      arrToVar(length_datum_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_datum_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_datum_id-1]=0;
      this->datum_id = (char *)(inbuffer + offset-1);
      offset += length_datum_id;
      union {
        float real;
        uint32_t base;
      } u_lat_sigma;
      u_lat_sigma.base = 0;
      u_lat_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lat_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lat_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lat_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lat_sigma = u_lat_sigma.real;
      offset += sizeof(this->lat_sigma);
      union {
        float real;
        uint32_t base;
      } u_lon_sigma;
      u_lon_sigma.base = 0;
      u_lon_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lon_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lon_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lon_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lon_sigma = u_lon_sigma.real;
      offset += sizeof(this->lon_sigma);
      union {
        float real;
        uint32_t base;
      } u_height_sigma;
      u_height_sigma.base = 0;
      u_height_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height_sigma = u_height_sigma.real;
      offset += sizeof(this->height_sigma);
      uint32_t length_base_station_id;
      arrToVar(length_base_station_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_base_station_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_base_station_id-1]=0;
      this->base_station_id = (char *)(inbuffer + offset-1);
      offset += length_base_station_id;
      union {
        float real;
        uint32_t base;
      } u_diff_age;
      u_diff_age.base = 0;
      u_diff_age.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_diff_age.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_diff_age.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_diff_age.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->diff_age = u_diff_age.real;
      offset += sizeof(this->diff_age);
      union {
        float real;
        uint32_t base;
      } u_solution_age;
      u_solution_age.base = 0;
      u_solution_age.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_solution_age.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_solution_age.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_solution_age.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->solution_age = u_solution_age.real;
      offset += sizeof(this->solution_age);
      this->num_satellites_tracked =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_satellites_tracked);
      this->num_satellites_used_in_solution =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_satellites_used_in_solution);
      this->num_gps_and_glonass_l1_used_in_solution =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_gps_and_glonass_l1_used_in_solution);
      this->num_gps_and_glonass_l1_and_l2_used_in_solution =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_gps_and_glonass_l1_and_l2_used_in_solution);
      offset += this->extended_solution_status.deserialize(inbuffer + offset);
      offset += this->signal_mask.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/NovatelPosition"; };
    const char * getMD5(){ return "16508625c306bc93a852c2381bb2573c"; };

  };

}
#endif
