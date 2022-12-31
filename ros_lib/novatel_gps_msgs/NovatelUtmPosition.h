#ifndef _ROS_novatel_gps_msgs_NovatelUtmPosition_h
#define _ROS_novatel_gps_msgs_NovatelUtmPosition_h

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

  class NovatelUtmPosition : public ros::Msg
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
      typedef uint32_t _lon_zone_number_type;
      _lon_zone_number_type lon_zone_number;
      typedef const char* _lat_zone_letter_type;
      _lat_zone_letter_type lat_zone_letter;
      typedef double _northing_type;
      _northing_type northing;
      typedef double _easting_type;
      _easting_type easting;
      typedef double _height_type;
      _height_type height;
      typedef float _undulation_type;
      _undulation_type undulation;
      typedef const char* _datum_id_type;
      _datum_id_type datum_id;
      typedef float _northing_sigma_type;
      _northing_sigma_type northing_sigma;
      typedef float _easting_sigma_type;
      _easting_sigma_type easting_sigma;
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

    NovatelUtmPosition():
      header(),
      novatel_msg_header(),
      solution_status(""),
      position_type(""),
      lon_zone_number(0),
      lat_zone_letter(""),
      northing(0),
      easting(0),
      height(0),
      undulation(0),
      datum_id(""),
      northing_sigma(0),
      easting_sigma(0),
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
      *(outbuffer + offset + 0) = (this->lon_zone_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lon_zone_number >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lon_zone_number >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lon_zone_number >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lon_zone_number);
      uint32_t length_lat_zone_letter = strlen(this->lat_zone_letter);
      varToArr(outbuffer + offset, length_lat_zone_letter);
      offset += 4;
      memcpy(outbuffer + offset, this->lat_zone_letter, length_lat_zone_letter);
      offset += length_lat_zone_letter;
      union {
        double real;
        uint64_t base;
      } u_northing;
      u_northing.real = this->northing;
      *(outbuffer + offset + 0) = (u_northing.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_northing.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_northing.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_northing.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_northing.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_northing.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_northing.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_northing.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->northing);
      union {
        double real;
        uint64_t base;
      } u_easting;
      u_easting.real = this->easting;
      *(outbuffer + offset + 0) = (u_easting.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_easting.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_easting.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_easting.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_easting.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_easting.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_easting.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_easting.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->easting);
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
      } u_northing_sigma;
      u_northing_sigma.real = this->northing_sigma;
      *(outbuffer + offset + 0) = (u_northing_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_northing_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_northing_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_northing_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->northing_sigma);
      union {
        float real;
        uint32_t base;
      } u_easting_sigma;
      u_easting_sigma.real = this->easting_sigma;
      *(outbuffer + offset + 0) = (u_easting_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_easting_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_easting_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_easting_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->easting_sigma);
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
      this->lon_zone_number =  ((uint32_t) (*(inbuffer + offset)));
      this->lon_zone_number |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lon_zone_number |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lon_zone_number |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lon_zone_number);
      uint32_t length_lat_zone_letter;
      arrToVar(length_lat_zone_letter, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lat_zone_letter; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lat_zone_letter-1]=0;
      this->lat_zone_letter = (char *)(inbuffer + offset-1);
      offset += length_lat_zone_letter;
      union {
        double real;
        uint64_t base;
      } u_northing;
      u_northing.base = 0;
      u_northing.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_northing.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_northing.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_northing.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_northing.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_northing.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_northing.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_northing.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->northing = u_northing.real;
      offset += sizeof(this->northing);
      union {
        double real;
        uint64_t base;
      } u_easting;
      u_easting.base = 0;
      u_easting.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_easting.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_easting.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_easting.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_easting.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_easting.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_easting.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_easting.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->easting = u_easting.real;
      offset += sizeof(this->easting);
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
      } u_northing_sigma;
      u_northing_sigma.base = 0;
      u_northing_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_northing_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_northing_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_northing_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->northing_sigma = u_northing_sigma.real;
      offset += sizeof(this->northing_sigma);
      union {
        float real;
        uint32_t base;
      } u_easting_sigma;
      u_easting_sigma.base = 0;
      u_easting_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_easting_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_easting_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_easting_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->easting_sigma = u_easting_sigma.real;
      offset += sizeof(this->easting_sigma);
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

    const char * getType(){ return "novatel_gps_msgs/NovatelUtmPosition"; };
    const char * getMD5(){ return "401ec19560e710c1e0aab9f0eec02ece"; };

  };

}
#endif
