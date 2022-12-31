#ifndef _ROS_novatel_gps_msgs_NovatelCorrectedImuData_h
#define _ROS_novatel_gps_msgs_NovatelCorrectedImuData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "novatel_gps_msgs/NovatelMessageHeader.h"

namespace novatel_gps_msgs
{

  class NovatelCorrectedImuData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef novatel_gps_msgs::NovatelMessageHeader _novatel_msg_header_type;
      _novatel_msg_header_type novatel_msg_header;
      typedef uint32_t _gps_week_num_type;
      _gps_week_num_type gps_week_num;
      typedef double _gps_seconds_type;
      _gps_seconds_type gps_seconds;
      typedef double _pitch_rate_type;
      _pitch_rate_type pitch_rate;
      typedef double _roll_rate_type;
      _roll_rate_type roll_rate;
      typedef double _yaw_rate_type;
      _yaw_rate_type yaw_rate;
      typedef double _lateral_acceleration_type;
      _lateral_acceleration_type lateral_acceleration;
      typedef double _longitudinal_acceleration_type;
      _longitudinal_acceleration_type longitudinal_acceleration;
      typedef double _vertical_acceleration_type;
      _vertical_acceleration_type vertical_acceleration;

    NovatelCorrectedImuData():
      header(),
      novatel_msg_header(),
      gps_week_num(0),
      gps_seconds(0),
      pitch_rate(0),
      roll_rate(0),
      yaw_rate(0),
      lateral_acceleration(0),
      longitudinal_acceleration(0),
      vertical_acceleration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->novatel_msg_header.serialize(outbuffer + offset);
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
      union {
        double real;
        uint64_t base;
      } u_pitch_rate;
      u_pitch_rate.real = this->pitch_rate;
      *(outbuffer + offset + 0) = (u_pitch_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch_rate.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pitch_rate.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pitch_rate.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pitch_rate.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pitch_rate.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pitch_rate);
      union {
        double real;
        uint64_t base;
      } u_roll_rate;
      u_roll_rate.real = this->roll_rate;
      *(outbuffer + offset + 0) = (u_roll_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll_rate.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_roll_rate.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_roll_rate.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_roll_rate.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_roll_rate.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->roll_rate);
      union {
        double real;
        uint64_t base;
      } u_yaw_rate;
      u_yaw_rate.real = this->yaw_rate;
      *(outbuffer + offset + 0) = (u_yaw_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_rate.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_yaw_rate.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_yaw_rate.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_yaw_rate.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_yaw_rate.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->yaw_rate);
      union {
        double real;
        uint64_t base;
      } u_lateral_acceleration;
      u_lateral_acceleration.real = this->lateral_acceleration;
      *(outbuffer + offset + 0) = (u_lateral_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lateral_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lateral_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lateral_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lateral_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lateral_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lateral_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lateral_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lateral_acceleration);
      union {
        double real;
        uint64_t base;
      } u_longitudinal_acceleration;
      u_longitudinal_acceleration.real = this->longitudinal_acceleration;
      *(outbuffer + offset + 0) = (u_longitudinal_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitudinal_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitudinal_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitudinal_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_longitudinal_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_longitudinal_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_longitudinal_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_longitudinal_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->longitudinal_acceleration);
      union {
        double real;
        uint64_t base;
      } u_vertical_acceleration;
      u_vertical_acceleration.real = this->vertical_acceleration;
      *(outbuffer + offset + 0) = (u_vertical_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vertical_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vertical_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vertical_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vertical_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vertical_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vertical_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vertical_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vertical_acceleration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->novatel_msg_header.deserialize(inbuffer + offset);
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
      union {
        double real;
        uint64_t base;
      } u_pitch_rate;
      u_pitch_rate.base = 0;
      u_pitch_rate.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_rate.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch_rate.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch_rate.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pitch_rate.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pitch_rate.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pitch_rate.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pitch_rate.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pitch_rate = u_pitch_rate.real;
      offset += sizeof(this->pitch_rate);
      union {
        double real;
        uint64_t base;
      } u_roll_rate;
      u_roll_rate.base = 0;
      u_roll_rate.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_rate.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll_rate.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll_rate.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_roll_rate.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_roll_rate.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_roll_rate.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_roll_rate.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->roll_rate = u_roll_rate.real;
      offset += sizeof(this->roll_rate);
      union {
        double real;
        uint64_t base;
      } u_yaw_rate;
      u_yaw_rate.base = 0;
      u_yaw_rate.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_rate.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_rate.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_rate.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_yaw_rate.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_yaw_rate.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_yaw_rate.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_yaw_rate.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->yaw_rate = u_yaw_rate.real;
      offset += sizeof(this->yaw_rate);
      union {
        double real;
        uint64_t base;
      } u_lateral_acceleration;
      u_lateral_acceleration.base = 0;
      u_lateral_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lateral_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lateral_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lateral_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_lateral_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_lateral_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_lateral_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_lateral_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->lateral_acceleration = u_lateral_acceleration.real;
      offset += sizeof(this->lateral_acceleration);
      union {
        double real;
        uint64_t base;
      } u_longitudinal_acceleration;
      u_longitudinal_acceleration.base = 0;
      u_longitudinal_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitudinal_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitudinal_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitudinal_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_longitudinal_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_longitudinal_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_longitudinal_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_longitudinal_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->longitudinal_acceleration = u_longitudinal_acceleration.real;
      offset += sizeof(this->longitudinal_acceleration);
      union {
        double real;
        uint64_t base;
      } u_vertical_acceleration;
      u_vertical_acceleration.base = 0;
      u_vertical_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vertical_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vertical_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vertical_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vertical_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vertical_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vertical_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vertical_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vertical_acceleration = u_vertical_acceleration.real;
      offset += sizeof(this->vertical_acceleration);
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/NovatelCorrectedImuData"; };
    const char * getMD5(){ return "81ec3aad90f65315c03ad2199cdd99cf"; };

  };

}
#endif
