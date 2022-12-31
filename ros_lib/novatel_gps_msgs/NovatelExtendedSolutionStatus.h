#ifndef _ROS_novatel_gps_msgs_NovatelExtendedSolutionStatus_h
#define _ROS_novatel_gps_msgs_NovatelExtendedSolutionStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace novatel_gps_msgs
{

  class NovatelExtendedSolutionStatus : public ros::Msg
  {
    public:
      typedef uint32_t _original_mask_type;
      _original_mask_type original_mask;
      typedef bool _advance_rtk_verified_type;
      _advance_rtk_verified_type advance_rtk_verified;
      typedef const char* _psuedorange_iono_correction_type;
      _psuedorange_iono_correction_type psuedorange_iono_correction;

    NovatelExtendedSolutionStatus():
      original_mask(0),
      advance_rtk_verified(0),
      psuedorange_iono_correction("")
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
      } u_advance_rtk_verified;
      u_advance_rtk_verified.real = this->advance_rtk_verified;
      *(outbuffer + offset + 0) = (u_advance_rtk_verified.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->advance_rtk_verified);
      uint32_t length_psuedorange_iono_correction = strlen(this->psuedorange_iono_correction);
      varToArr(outbuffer + offset, length_psuedorange_iono_correction);
      offset += 4;
      memcpy(outbuffer + offset, this->psuedorange_iono_correction, length_psuedorange_iono_correction);
      offset += length_psuedorange_iono_correction;
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
      } u_advance_rtk_verified;
      u_advance_rtk_verified.base = 0;
      u_advance_rtk_verified.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->advance_rtk_verified = u_advance_rtk_verified.real;
      offset += sizeof(this->advance_rtk_verified);
      uint32_t length_psuedorange_iono_correction;
      arrToVar(length_psuedorange_iono_correction, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_psuedorange_iono_correction; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_psuedorange_iono_correction-1]=0;
      this->psuedorange_iono_correction = (char *)(inbuffer + offset-1);
      offset += length_psuedorange_iono_correction;
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/NovatelExtendedSolutionStatus"; };
    const char * getMD5(){ return "f0e19d53094c207c4dafdfbde750c4b1"; };

  };

}
#endif
