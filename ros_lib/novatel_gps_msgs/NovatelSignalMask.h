#ifndef _ROS_novatel_gps_msgs_NovatelSignalMask_h
#define _ROS_novatel_gps_msgs_NovatelSignalMask_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace novatel_gps_msgs
{

  class NovatelSignalMask : public ros::Msg
  {
    public:
      typedef uint32_t _original_mask_type;
      _original_mask_type original_mask;
      typedef bool _gps_L1_used_in_solution_type;
      _gps_L1_used_in_solution_type gps_L1_used_in_solution;
      typedef bool _gps_L2_used_in_solution_type;
      _gps_L2_used_in_solution_type gps_L2_used_in_solution;
      typedef bool _gps_L3_used_in_solution_type;
      _gps_L3_used_in_solution_type gps_L3_used_in_solution;
      typedef bool _glonass_L1_used_in_solution_type;
      _glonass_L1_used_in_solution_type glonass_L1_used_in_solution;
      typedef bool _glonass_L2_used_in_solution_type;
      _glonass_L2_used_in_solution_type glonass_L2_used_in_solution;

    NovatelSignalMask():
      original_mask(0),
      gps_L1_used_in_solution(0),
      gps_L2_used_in_solution(0),
      gps_L3_used_in_solution(0),
      glonass_L1_used_in_solution(0),
      glonass_L2_used_in_solution(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->original_mask >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->original_mask >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->original_mask >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->original_mask >> (8 * 3)) & 0xFF;
      offset += sizeof(this->original_mask);
      union {
        bool real;
        uint8_t base;
      } u_gps_L1_used_in_solution;
      u_gps_L1_used_in_solution.real = this->gps_L1_used_in_solution;
      *(outbuffer + offset + 0) = (u_gps_L1_used_in_solution.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gps_L1_used_in_solution);
      union {
        bool real;
        uint8_t base;
      } u_gps_L2_used_in_solution;
      u_gps_L2_used_in_solution.real = this->gps_L2_used_in_solution;
      *(outbuffer + offset + 0) = (u_gps_L2_used_in_solution.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gps_L2_used_in_solution);
      union {
        bool real;
        uint8_t base;
      } u_gps_L3_used_in_solution;
      u_gps_L3_used_in_solution.real = this->gps_L3_used_in_solution;
      *(outbuffer + offset + 0) = (u_gps_L3_used_in_solution.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gps_L3_used_in_solution);
      union {
        bool real;
        uint8_t base;
      } u_glonass_L1_used_in_solution;
      u_glonass_L1_used_in_solution.real = this->glonass_L1_used_in_solution;
      *(outbuffer + offset + 0) = (u_glonass_L1_used_in_solution.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->glonass_L1_used_in_solution);
      union {
        bool real;
        uint8_t base;
      } u_glonass_L2_used_in_solution;
      u_glonass_L2_used_in_solution.real = this->glonass_L2_used_in_solution;
      *(outbuffer + offset + 0) = (u_glonass_L2_used_in_solution.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->glonass_L2_used_in_solution);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->original_mask =  ((uint32_t) (*(inbuffer + offset)));
      this->original_mask |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->original_mask |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->original_mask |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->original_mask);
      union {
        bool real;
        uint8_t base;
      } u_gps_L1_used_in_solution;
      u_gps_L1_used_in_solution.base = 0;
      u_gps_L1_used_in_solution.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gps_L1_used_in_solution = u_gps_L1_used_in_solution.real;
      offset += sizeof(this->gps_L1_used_in_solution);
      union {
        bool real;
        uint8_t base;
      } u_gps_L2_used_in_solution;
      u_gps_L2_used_in_solution.base = 0;
      u_gps_L2_used_in_solution.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gps_L2_used_in_solution = u_gps_L2_used_in_solution.real;
      offset += sizeof(this->gps_L2_used_in_solution);
      union {
        bool real;
        uint8_t base;
      } u_gps_L3_used_in_solution;
      u_gps_L3_used_in_solution.base = 0;
      u_gps_L3_used_in_solution.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gps_L3_used_in_solution = u_gps_L3_used_in_solution.real;
      offset += sizeof(this->gps_L3_used_in_solution);
      union {
        bool real;
        uint8_t base;
      } u_glonass_L1_used_in_solution;
      u_glonass_L1_used_in_solution.base = 0;
      u_glonass_L1_used_in_solution.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->glonass_L1_used_in_solution = u_glonass_L1_used_in_solution.real;
      offset += sizeof(this->glonass_L1_used_in_solution);
      union {
        bool real;
        uint8_t base;
      } u_glonass_L2_used_in_solution;
      u_glonass_L2_used_in_solution.base = 0;
      u_glonass_L2_used_in_solution.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->glonass_L2_used_in_solution = u_glonass_L2_used_in_solution.real;
      offset += sizeof(this->glonass_L2_used_in_solution);
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/NovatelSignalMask"; };
    const char * getMD5(){ return "007d687355f8f3c12ea4e18109172710"; };

  };

}
#endif
