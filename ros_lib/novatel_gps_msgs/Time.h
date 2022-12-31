#ifndef _ROS_novatel_gps_msgs_Time_h
#define _ROS_novatel_gps_msgs_Time_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace novatel_gps_msgs
{

  class Time : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _clock_status_type;
      _clock_status_type clock_status;
      typedef double _offset_type;
      _offset_type offset;
      typedef double _offset_std_type;
      _offset_std_type offset_std;
      typedef double _utc_offset_type;
      _utc_offset_type utc_offset;
      typedef uint32_t _utc_year_type;
      _utc_year_type utc_year;
      typedef uint8_t _utc_month_type;
      _utc_month_type utc_month;
      typedef uint8_t _utc_day_type;
      _utc_day_type utc_day;
      typedef uint8_t _utc_hour_type;
      _utc_hour_type utc_hour;
      typedef uint8_t _utc_minute_type;
      _utc_minute_type utc_minute;
      typedef uint32_t _utc_millisecond_type;
      _utc_millisecond_type utc_millisecond;
      typedef const char* _utc_status_type;
      _utc_status_type utc_status;

    Time():
      header(),
      clock_status(""),
      offset(0),
      offset_std(0),
      utc_offset(0),
      utc_year(0),
      utc_month(0),
      utc_day(0),
      utc_hour(0),
      utc_minute(0),
      utc_millisecond(0),
      utc_status("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_clock_status = strlen(this->clock_status);
      varToArr(outbuffer + offset, length_clock_status);
      offset += 4;
      memcpy(outbuffer + offset, this->clock_status, length_clock_status);
      offset += length_clock_status;
      union {
        double real;
        uint64_t base;
      } u_offset;
      u_offset.real = this->offset;
      *(outbuffer + offset + 0) = (u_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_offset.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_offset.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_offset.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_offset.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_offset.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->offset);
      union {
        double real;
        uint64_t base;
      } u_offset_std;
      u_offset_std.real = this->offset_std;
      *(outbuffer + offset + 0) = (u_offset_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_offset_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_offset_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_offset_std.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_offset_std.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_offset_std.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_offset_std.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_offset_std.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->offset_std);
      union {
        double real;
        uint64_t base;
      } u_utc_offset;
      u_utc_offset.real = this->utc_offset;
      *(outbuffer + offset + 0) = (u_utc_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_utc_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_utc_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_utc_offset.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_utc_offset.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_utc_offset.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_utc_offset.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_utc_offset.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->utc_offset);
      *(outbuffer + offset + 0) = (this->utc_year >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->utc_year >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->utc_year >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->utc_year >> (8 * 3)) & 0xFF;
      offset += sizeof(this->utc_year);
      *(outbuffer + offset + 0) = (this->utc_month >> (8 * 0)) & 0xFF;
      offset += sizeof(this->utc_month);
      *(outbuffer + offset + 0) = (this->utc_day >> (8 * 0)) & 0xFF;
      offset += sizeof(this->utc_day);
      *(outbuffer + offset + 0) = (this->utc_hour >> (8 * 0)) & 0xFF;
      offset += sizeof(this->utc_hour);
      *(outbuffer + offset + 0) = (this->utc_minute >> (8 * 0)) & 0xFF;
      offset += sizeof(this->utc_minute);
      *(outbuffer + offset + 0) = (this->utc_millisecond >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->utc_millisecond >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->utc_millisecond >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->utc_millisecond >> (8 * 3)) & 0xFF;
      offset += sizeof(this->utc_millisecond);
      uint32_t length_utc_status = strlen(this->utc_status);
      varToArr(outbuffer + offset, length_utc_status);
      offset += 4;
      memcpy(outbuffer + offset, this->utc_status, length_utc_status);
      offset += length_utc_status;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_clock_status;
      arrToVar(length_clock_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_clock_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_clock_status-1]=0;
      this->clock_status = (char *)(inbuffer + offset-1);
      offset += length_clock_status;
      union {
        double real;
        uint64_t base;
      } u_offset;
      u_offset.base = 0;
      u_offset.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_offset.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_offset.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_offset.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_offset.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_offset.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_offset.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_offset.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->offset = u_offset.real;
      offset += sizeof(this->offset);
      union {
        double real;
        uint64_t base;
      } u_offset_std;
      u_offset_std.base = 0;
      u_offset_std.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_offset_std.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_offset_std.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_offset_std.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_offset_std.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_offset_std.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_offset_std.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_offset_std.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->offset_std = u_offset_std.real;
      offset += sizeof(this->offset_std);
      union {
        double real;
        uint64_t base;
      } u_utc_offset;
      u_utc_offset.base = 0;
      u_utc_offset.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_utc_offset.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_utc_offset.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_utc_offset.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_utc_offset.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_utc_offset.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_utc_offset.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_utc_offset.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->utc_offset = u_utc_offset.real;
      offset += sizeof(this->utc_offset);
      this->utc_year =  ((uint32_t) (*(inbuffer + offset)));
      this->utc_year |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->utc_year |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->utc_year |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->utc_year);
      this->utc_month =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->utc_month);
      this->utc_day =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->utc_day);
      this->utc_hour =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->utc_hour);
      this->utc_minute =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->utc_minute);
      this->utc_millisecond =  ((uint32_t) (*(inbuffer + offset)));
      this->utc_millisecond |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->utc_millisecond |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->utc_millisecond |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->utc_millisecond);
      uint32_t length_utc_status;
      arrToVar(length_utc_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_utc_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_utc_status-1]=0;
      this->utc_status = (char *)(inbuffer + offset-1);
      offset += length_utc_status;
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/Time"; };
    const char * getMD5(){ return "65d339585d71de8242304ff93e8a4f1a"; };

  };

}
#endif
