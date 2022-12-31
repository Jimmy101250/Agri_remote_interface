#ifndef _ROS_novatel_gps_msgs_ClockSteering_h
#define _ROS_novatel_gps_msgs_ClockSteering_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace novatel_gps_msgs
{

  class ClockSteering : public ros::Msg
  {
    public:
      typedef const char* _source_type;
      _source_type source;
      typedef const char* _steering_state_type;
      _steering_state_type steering_state;
      typedef uint32_t _period_type;
      _period_type period;
      typedef double _pulse_width_type;
      _pulse_width_type pulse_width;
      typedef double _bandwidth_type;
      _bandwidth_type bandwidth;
      typedef float _slope_type;
      _slope_type slope;
      typedef double _offset_type;
      _offset_type offset;
      typedef double _drift_rate_type;
      _drift_rate_type drift_rate;
      enum { INTERNAL_SOURCE = 0 };
      enum { EXTERNAL_SOURCE = 1 };
      enum { FIRST_ORDER_STEERING_STATE = 0 };
      enum { SECOND_ORDER_STEERING_STATE = 1 };
      enum { CALIBRATE_HIGH_STEERING_STATE = 2 };
      enum { CALIBRATE_LOW_STEERING_STATE = 3 };
      enum { CALIBRATE_CENTER_STEERING_STATE = 4 };

    ClockSteering():
      source(""),
      steering_state(""),
      period(0),
      pulse_width(0),
      bandwidth(0),
      slope(0),
      offset(0),
      drift_rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_source = strlen(this->source);
      varToArr(outbuffer + offset, length_source);
      offset += 4;
      memcpy(outbuffer + offset, this->source, length_source);
      offset += length_source;
      uint32_t length_steering_state = strlen(this->steering_state);
      varToArr(outbuffer + offset, length_steering_state);
      offset += 4;
      memcpy(outbuffer + offset, this->steering_state, length_steering_state);
      offset += length_steering_state;
      *(outbuffer + offset + 0) = (this->period >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->period >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->period >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->period >> (8 * 3)) & 0xFF;
      offset += sizeof(this->period);
      union {
        double real;
        uint64_t base;
      } u_pulse_width;
      u_pulse_width.real = this->pulse_width;
      *(outbuffer + offset + 0) = (u_pulse_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pulse_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pulse_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pulse_width.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pulse_width.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pulse_width.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pulse_width.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pulse_width.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pulse_width);
      union {
        double real;
        uint64_t base;
      } u_bandwidth;
      u_bandwidth.real = this->bandwidth;
      *(outbuffer + offset + 0) = (u_bandwidth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bandwidth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bandwidth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bandwidth.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_bandwidth.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_bandwidth.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_bandwidth.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_bandwidth.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->bandwidth);
      union {
        float real;
        uint32_t base;
      } u_slope;
      u_slope.real = this->slope;
      *(outbuffer + offset + 0) = (u_slope.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_slope.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_slope.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_slope.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->slope);
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
      } u_drift_rate;
      u_drift_rate.real = this->drift_rate;
      *(outbuffer + offset + 0) = (u_drift_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drift_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_drift_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_drift_rate.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_drift_rate.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_drift_rate.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_drift_rate.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_drift_rate.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->drift_rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_source;
      arrToVar(length_source, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source-1]=0;
      this->source = (char *)(inbuffer + offset-1);
      offset += length_source;
      uint32_t length_steering_state;
      arrToVar(length_steering_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_steering_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_steering_state-1]=0;
      this->steering_state = (char *)(inbuffer + offset-1);
      offset += length_steering_state;
      this->period =  ((uint32_t) (*(inbuffer + offset)));
      this->period |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->period |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->period |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->period);
      union {
        double real;
        uint64_t base;
      } u_pulse_width;
      u_pulse_width.base = 0;
      u_pulse_width.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pulse_width.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pulse_width.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pulse_width.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pulse_width.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pulse_width.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pulse_width.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pulse_width.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pulse_width = u_pulse_width.real;
      offset += sizeof(this->pulse_width);
      union {
        double real;
        uint64_t base;
      } u_bandwidth;
      u_bandwidth.base = 0;
      u_bandwidth.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bandwidth.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bandwidth.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bandwidth.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_bandwidth.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_bandwidth.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_bandwidth.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_bandwidth.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->bandwidth = u_bandwidth.real;
      offset += sizeof(this->bandwidth);
      union {
        float real;
        uint32_t base;
      } u_slope;
      u_slope.base = 0;
      u_slope.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_slope.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_slope.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_slope.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->slope = u_slope.real;
      offset += sizeof(this->slope);
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
      } u_drift_rate;
      u_drift_rate.base = 0;
      u_drift_rate.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drift_rate.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_drift_rate.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_drift_rate.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_drift_rate.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_drift_rate.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_drift_rate.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_drift_rate.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->drift_rate = u_drift_rate.real;
      offset += sizeof(this->drift_rate);
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/ClockSteering"; };
    const char * getMD5(){ return "03024ea60365b742dd5e56411830735e"; };

  };

}
#endif
