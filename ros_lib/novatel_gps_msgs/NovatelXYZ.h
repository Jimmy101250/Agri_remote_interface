#ifndef _ROS_novatel_gps_msgs_NovatelXYZ_h
#define _ROS_novatel_gps_msgs_NovatelXYZ_h

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

  class NovatelXYZ : public ros::Msg
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
      typedef double _x_type;
      _x_type x;
      typedef double _y_type;
      _y_type y;
      typedef double _z_type;
      _z_type z;
      typedef float _x_sigma_type;
      _x_sigma_type x_sigma;
      typedef float _y_sigma_type;
      _y_sigma_type y_sigma;
      typedef float _z_sigma_type;
      _z_sigma_type z_sigma;
      typedef const char* _velocity_solution_status_type;
      _velocity_solution_status_type velocity_solution_status;
      typedef const char* _velocity_type_type;
      _velocity_type_type velocity_type;
      typedef double _x_vel_type;
      _x_vel_type x_vel;
      typedef double _y_vel_type;
      _y_vel_type y_vel;
      typedef double _z_vel_type;
      _z_vel_type z_vel;
      typedef float _x_vel_sigma_type;
      _x_vel_sigma_type x_vel_sigma;
      typedef float _y_vel_sigma_type;
      _y_vel_sigma_type y_vel_sigma;
      typedef float _z_vel_sigma_type;
      _z_vel_sigma_type z_vel_sigma;
      typedef const char* _base_station_id_type;
      _base_station_id_type base_station_id;
      typedef float _velocity_latency_type;
      _velocity_latency_type velocity_latency;
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

    NovatelXYZ():
      header(),
      novatel_msg_header(),
      solution_status(""),
      position_type(""),
      x(0),
      y(0),
      z(0),
      x_sigma(0),
      y_sigma(0),
      z_sigma(0),
      velocity_solution_status(""),
      velocity_type(""),
      x_vel(0),
      y_vel(0),
      z_vel(0),
      x_vel_sigma(0),
      y_vel_sigma(0),
      z_vel_sigma(0),
      base_station_id(""),
      velocity_latency(0),
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
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_x_sigma;
      u_x_sigma.real = this->x_sigma;
      *(outbuffer + offset + 0) = (u_x_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_sigma);
      union {
        float real;
        uint32_t base;
      } u_y_sigma;
      u_y_sigma.real = this->y_sigma;
      *(outbuffer + offset + 0) = (u_y_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_sigma);
      union {
        float real;
        uint32_t base;
      } u_z_sigma;
      u_z_sigma.real = this->z_sigma;
      *(outbuffer + offset + 0) = (u_z_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_sigma);
      uint32_t length_velocity_solution_status = strlen(this->velocity_solution_status);
      varToArr(outbuffer + offset, length_velocity_solution_status);
      offset += 4;
      memcpy(outbuffer + offset, this->velocity_solution_status, length_velocity_solution_status);
      offset += length_velocity_solution_status;
      uint32_t length_velocity_type = strlen(this->velocity_type);
      varToArr(outbuffer + offset, length_velocity_type);
      offset += 4;
      memcpy(outbuffer + offset, this->velocity_type, length_velocity_type);
      offset += length_velocity_type;
      union {
        double real;
        uint64_t base;
      } u_x_vel;
      u_x_vel.real = this->x_vel;
      *(outbuffer + offset + 0) = (u_x_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_vel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x_vel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x_vel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x_vel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x_vel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x_vel);
      union {
        double real;
        uint64_t base;
      } u_y_vel;
      u_y_vel.real = this->y_vel;
      *(outbuffer + offset + 0) = (u_y_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_vel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y_vel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y_vel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y_vel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y_vel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y_vel);
      union {
        double real;
        uint64_t base;
      } u_z_vel;
      u_z_vel.real = this->z_vel;
      *(outbuffer + offset + 0) = (u_z_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_vel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_z_vel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_z_vel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_z_vel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_z_vel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->z_vel);
      union {
        float real;
        uint32_t base;
      } u_x_vel_sigma;
      u_x_vel_sigma.real = this->x_vel_sigma;
      *(outbuffer + offset + 0) = (u_x_vel_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_vel_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_vel_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_vel_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_vel_sigma);
      union {
        float real;
        uint32_t base;
      } u_y_vel_sigma;
      u_y_vel_sigma.real = this->y_vel_sigma;
      *(outbuffer + offset + 0) = (u_y_vel_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_vel_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_vel_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_vel_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_vel_sigma);
      union {
        float real;
        uint32_t base;
      } u_z_vel_sigma;
      u_z_vel_sigma.real = this->z_vel_sigma;
      *(outbuffer + offset + 0) = (u_z_vel_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_vel_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_vel_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_vel_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_vel_sigma);
      uint32_t length_base_station_id = strlen(this->base_station_id);
      varToArr(outbuffer + offset, length_base_station_id);
      offset += 4;
      memcpy(outbuffer + offset, this->base_station_id, length_base_station_id);
      offset += length_base_station_id;
      union {
        float real;
        uint32_t base;
      } u_velocity_latency;
      u_velocity_latency.real = this->velocity_latency;
      *(outbuffer + offset + 0) = (u_velocity_latency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_latency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_latency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_latency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_latency);
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
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_x_sigma;
      u_x_sigma.base = 0;
      u_x_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x_sigma = u_x_sigma.real;
      offset += sizeof(this->x_sigma);
      union {
        float real;
        uint32_t base;
      } u_y_sigma;
      u_y_sigma.base = 0;
      u_y_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y_sigma = u_y_sigma.real;
      offset += sizeof(this->y_sigma);
      union {
        float real;
        uint32_t base;
      } u_z_sigma;
      u_z_sigma.base = 0;
      u_z_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z_sigma = u_z_sigma.real;
      offset += sizeof(this->z_sigma);
      uint32_t length_velocity_solution_status;
      arrToVar(length_velocity_solution_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_velocity_solution_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_velocity_solution_status-1]=0;
      this->velocity_solution_status = (char *)(inbuffer + offset-1);
      offset += length_velocity_solution_status;
      uint32_t length_velocity_type;
      arrToVar(length_velocity_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_velocity_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_velocity_type-1]=0;
      this->velocity_type = (char *)(inbuffer + offset-1);
      offset += length_velocity_type;
      union {
        double real;
        uint64_t base;
      } u_x_vel;
      u_x_vel.base = 0;
      u_x_vel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_vel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_vel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_vel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x_vel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x_vel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x_vel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x_vel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x_vel = u_x_vel.real;
      offset += sizeof(this->x_vel);
      union {
        double real;
        uint64_t base;
      } u_y_vel;
      u_y_vel.base = 0;
      u_y_vel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_vel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_vel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_vel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y_vel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y_vel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y_vel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y_vel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y_vel = u_y_vel.real;
      offset += sizeof(this->y_vel);
      union {
        double real;
        uint64_t base;
      } u_z_vel;
      u_z_vel.base = 0;
      u_z_vel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_vel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_vel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_vel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_z_vel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_z_vel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_z_vel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_z_vel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->z_vel = u_z_vel.real;
      offset += sizeof(this->z_vel);
      union {
        float real;
        uint32_t base;
      } u_x_vel_sigma;
      u_x_vel_sigma.base = 0;
      u_x_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x_vel_sigma = u_x_vel_sigma.real;
      offset += sizeof(this->x_vel_sigma);
      union {
        float real;
        uint32_t base;
      } u_y_vel_sigma;
      u_y_vel_sigma.base = 0;
      u_y_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y_vel_sigma = u_y_vel_sigma.real;
      offset += sizeof(this->y_vel_sigma);
      union {
        float real;
        uint32_t base;
      } u_z_vel_sigma;
      u_z_vel_sigma.base = 0;
      u_z_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_vel_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z_vel_sigma = u_z_vel_sigma.real;
      offset += sizeof(this->z_vel_sigma);
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
      } u_velocity_latency;
      u_velocity_latency.base = 0;
      u_velocity_latency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_latency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_latency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_latency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_latency = u_velocity_latency.real;
      offset += sizeof(this->velocity_latency);
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

    const char * getType(){ return "novatel_gps_msgs/NovatelXYZ"; };
    const char * getMD5(){ return "d1ffc3181aa742b6133febb9d8f77d12"; };

  };

}
#endif
