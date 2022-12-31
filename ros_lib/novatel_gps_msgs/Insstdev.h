#ifndef _ROS_novatel_gps_msgs_Insstdev_h
#define _ROS_novatel_gps_msgs_Insstdev_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "novatel_gps_msgs/NovatelMessageHeader.h"
#include "novatel_gps_msgs/NovatelExtendedSolutionStatus.h"

namespace novatel_gps_msgs
{

  class Insstdev : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef novatel_gps_msgs::NovatelMessageHeader _novatel_msg_header_type;
      _novatel_msg_header_type novatel_msg_header;
      typedef float _latitude_dev_type;
      _latitude_dev_type latitude_dev;
      typedef float _longitude_dev_type;
      _longitude_dev_type longitude_dev;
      typedef float _height_dev_type;
      _height_dev_type height_dev;
      typedef float _north_velocity_dev_type;
      _north_velocity_dev_type north_velocity_dev;
      typedef float _east_velocity_dev_type;
      _east_velocity_dev_type east_velocity_dev;
      typedef float _up_velocity_dev_type;
      _up_velocity_dev_type up_velocity_dev;
      typedef float _roll_dev_type;
      _roll_dev_type roll_dev;
      typedef float _pitch_dev_type;
      _pitch_dev_type pitch_dev;
      typedef float _azimuth_dev_type;
      _azimuth_dev_type azimuth_dev;
      typedef novatel_gps_msgs::NovatelExtendedSolutionStatus _extended_solution_status_type;
      _extended_solution_status_type extended_solution_status;
      typedef uint16_t _time_since_update_type;
      _time_since_update_type time_since_update;

    Insstdev():
      header(),
      novatel_msg_header(),
      latitude_dev(0),
      longitude_dev(0),
      height_dev(0),
      north_velocity_dev(0),
      east_velocity_dev(0),
      up_velocity_dev(0),
      roll_dev(0),
      pitch_dev(0),
      azimuth_dev(0),
      extended_solution_status(),
      time_since_update(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->novatel_msg_header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_latitude_dev;
      u_latitude_dev.real = this->latitude_dev;
      *(outbuffer + offset + 0) = (u_latitude_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude_dev);
      union {
        float real;
        uint32_t base;
      } u_longitude_dev;
      u_longitude_dev.real = this->longitude_dev;
      *(outbuffer + offset + 0) = (u_longitude_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitude_dev);
      union {
        float real;
        uint32_t base;
      } u_height_dev;
      u_height_dev.real = this->height_dev;
      *(outbuffer + offset + 0) = (u_height_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height_dev);
      union {
        float real;
        uint32_t base;
      } u_north_velocity_dev;
      u_north_velocity_dev.real = this->north_velocity_dev;
      *(outbuffer + offset + 0) = (u_north_velocity_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_north_velocity_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_north_velocity_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_north_velocity_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->north_velocity_dev);
      union {
        float real;
        uint32_t base;
      } u_east_velocity_dev;
      u_east_velocity_dev.real = this->east_velocity_dev;
      *(outbuffer + offset + 0) = (u_east_velocity_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_east_velocity_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_east_velocity_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_east_velocity_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->east_velocity_dev);
      union {
        float real;
        uint32_t base;
      } u_up_velocity_dev;
      u_up_velocity_dev.real = this->up_velocity_dev;
      *(outbuffer + offset + 0) = (u_up_velocity_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_up_velocity_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_up_velocity_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_up_velocity_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->up_velocity_dev);
      union {
        float real;
        uint32_t base;
      } u_roll_dev;
      u_roll_dev.real = this->roll_dev;
      *(outbuffer + offset + 0) = (u_roll_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll_dev);
      union {
        float real;
        uint32_t base;
      } u_pitch_dev;
      u_pitch_dev.real = this->pitch_dev;
      *(outbuffer + offset + 0) = (u_pitch_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch_dev);
      union {
        float real;
        uint32_t base;
      } u_azimuth_dev;
      u_azimuth_dev.real = this->azimuth_dev;
      *(outbuffer + offset + 0) = (u_azimuth_dev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_azimuth_dev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_azimuth_dev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_azimuth_dev.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->azimuth_dev);
      offset += this->extended_solution_status.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->time_since_update >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_since_update >> (8 * 1)) & 0xFF;
      offset += sizeof(this->time_since_update);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->novatel_msg_header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_latitude_dev;
      u_latitude_dev.base = 0;
      u_latitude_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude_dev = u_latitude_dev.real;
      offset += sizeof(this->latitude_dev);
      union {
        float real;
        uint32_t base;
      } u_longitude_dev;
      u_longitude_dev.base = 0;
      u_longitude_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitude_dev = u_longitude_dev.real;
      offset += sizeof(this->longitude_dev);
      union {
        float real;
        uint32_t base;
      } u_height_dev;
      u_height_dev.base = 0;
      u_height_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height_dev = u_height_dev.real;
      offset += sizeof(this->height_dev);
      union {
        float real;
        uint32_t base;
      } u_north_velocity_dev;
      u_north_velocity_dev.base = 0;
      u_north_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_north_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_north_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_north_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->north_velocity_dev = u_north_velocity_dev.real;
      offset += sizeof(this->north_velocity_dev);
      union {
        float real;
        uint32_t base;
      } u_east_velocity_dev;
      u_east_velocity_dev.base = 0;
      u_east_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_east_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_east_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_east_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->east_velocity_dev = u_east_velocity_dev.real;
      offset += sizeof(this->east_velocity_dev);
      union {
        float real;
        uint32_t base;
      } u_up_velocity_dev;
      u_up_velocity_dev.base = 0;
      u_up_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_up_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_up_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_up_velocity_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->up_velocity_dev = u_up_velocity_dev.real;
      offset += sizeof(this->up_velocity_dev);
      union {
        float real;
        uint32_t base;
      } u_roll_dev;
      u_roll_dev.base = 0;
      u_roll_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll_dev = u_roll_dev.real;
      offset += sizeof(this->roll_dev);
      union {
        float real;
        uint32_t base;
      } u_pitch_dev;
      u_pitch_dev.base = 0;
      u_pitch_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch_dev = u_pitch_dev.real;
      offset += sizeof(this->pitch_dev);
      union {
        float real;
        uint32_t base;
      } u_azimuth_dev;
      u_azimuth_dev.base = 0;
      u_azimuth_dev.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_azimuth_dev.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_azimuth_dev.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_azimuth_dev.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->azimuth_dev = u_azimuth_dev.real;
      offset += sizeof(this->azimuth_dev);
      offset += this->extended_solution_status.deserialize(inbuffer + offset);
      this->time_since_update =  ((uint16_t) (*(inbuffer + offset)));
      this->time_since_update |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->time_since_update);
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/Insstdev"; };
    const char * getMD5(){ return "5a3ffc9969b49cd107b55c9843133d1c"; };

  };

}
#endif
