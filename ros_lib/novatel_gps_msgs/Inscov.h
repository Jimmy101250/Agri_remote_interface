#ifndef _ROS_novatel_gps_msgs_Inscov_h
#define _ROS_novatel_gps_msgs_Inscov_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "novatel_gps_msgs/NovatelMessageHeader.h"

namespace novatel_gps_msgs
{

  class Inscov : public ros::Msg
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
      double position_covariance[9];
      double attitude_covariance[9];
      double velocity_covariance[9];

    Inscov():
      header(),
      novatel_msg_header(),
      week(0),
      seconds(0),
      position_covariance(),
      attitude_covariance(),
      velocity_covariance()
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
      for( uint32_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_position_covariancei;
      u_position_covariancei.real = this->position_covariance[i];
      *(outbuffer + offset + 0) = (u_position_covariancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_covariancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_covariancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_covariancei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_position_covariancei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_position_covariancei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_position_covariancei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_position_covariancei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->position_covariance[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_attitude_covariancei;
      u_attitude_covariancei.real = this->attitude_covariance[i];
      *(outbuffer + offset + 0) = (u_attitude_covariancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_attitude_covariancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_attitude_covariancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_attitude_covariancei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_attitude_covariancei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_attitude_covariancei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_attitude_covariancei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_attitude_covariancei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->attitude_covariance[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_velocity_covariancei;
      u_velocity_covariancei.real = this->velocity_covariance[i];
      *(outbuffer + offset + 0) = (u_velocity_covariancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_covariancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_covariancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_covariancei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocity_covariancei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocity_covariancei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocity_covariancei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocity_covariancei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocity_covariance[i]);
      }
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
      for( uint32_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_position_covariancei;
      u_position_covariancei.base = 0;
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->position_covariance[i] = u_position_covariancei.real;
      offset += sizeof(this->position_covariance[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_attitude_covariancei;
      u_attitude_covariancei.base = 0;
      u_attitude_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_attitude_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_attitude_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_attitude_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_attitude_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_attitude_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_attitude_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_attitude_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->attitude_covariance[i] = u_attitude_covariancei.real;
      offset += sizeof(this->attitude_covariance[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_velocity_covariancei;
      u_velocity_covariancei.base = 0;
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velocity_covariance[i] = u_velocity_covariancei.real;
      offset += sizeof(this->velocity_covariance[i]);
      }
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/Inscov"; };
    const char * getMD5(){ return "a4ae1586410fc24e8ab4019825bb8bdd"; };

  };

}
#endif
