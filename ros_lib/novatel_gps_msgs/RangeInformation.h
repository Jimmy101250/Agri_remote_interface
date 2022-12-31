#ifndef _ROS_novatel_gps_msgs_RangeInformation_h
#define _ROS_novatel_gps_msgs_RangeInformation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace novatel_gps_msgs
{

  class RangeInformation : public ros::Msg
  {
    public:
      typedef uint16_t _prn_number_type;
      _prn_number_type prn_number;
      typedef uint16_t _glofreq_type;
      _glofreq_type glofreq;
      typedef double _psr_type;
      _psr_type psr;
      typedef float _psr_std_type;
      _psr_std_type psr_std;
      typedef double _adr_type;
      _adr_type adr;
      typedef float _adr_std_type;
      _adr_std_type adr_std;
      typedef float _dopp_type;
      _dopp_type dopp;
      typedef float _noise_density_ratio_type;
      _noise_density_ratio_type noise_density_ratio;
      typedef float _locktime_type;
      _locktime_type locktime;
      typedef uint32_t _tracking_status_type;
      _tracking_status_type tracking_status;

    RangeInformation():
      prn_number(0),
      glofreq(0),
      psr(0),
      psr_std(0),
      adr(0),
      adr_std(0),
      dopp(0),
      noise_density_ratio(0),
      locktime(0),
      tracking_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->prn_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->prn_number >> (8 * 1)) & 0xFF;
      offset += sizeof(this->prn_number);
      *(outbuffer + offset + 0) = (this->glofreq >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->glofreq >> (8 * 1)) & 0xFF;
      offset += sizeof(this->glofreq);
      union {
        double real;
        uint64_t base;
      } u_psr;
      u_psr.real = this->psr;
      *(outbuffer + offset + 0) = (u_psr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_psr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_psr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_psr.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_psr.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_psr.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_psr.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_psr.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->psr);
      union {
        float real;
        uint32_t base;
      } u_psr_std;
      u_psr_std.real = this->psr_std;
      *(outbuffer + offset + 0) = (u_psr_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_psr_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_psr_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_psr_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->psr_std);
      union {
        double real;
        uint64_t base;
      } u_adr;
      u_adr.real = this->adr;
      *(outbuffer + offset + 0) = (u_adr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_adr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_adr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_adr.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_adr.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_adr.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_adr.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_adr.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->adr);
      union {
        float real;
        uint32_t base;
      } u_adr_std;
      u_adr_std.real = this->adr_std;
      *(outbuffer + offset + 0) = (u_adr_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_adr_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_adr_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_adr_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->adr_std);
      union {
        float real;
        uint32_t base;
      } u_dopp;
      u_dopp.real = this->dopp;
      *(outbuffer + offset + 0) = (u_dopp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dopp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dopp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dopp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dopp);
      union {
        float real;
        uint32_t base;
      } u_noise_density_ratio;
      u_noise_density_ratio.real = this->noise_density_ratio;
      *(outbuffer + offset + 0) = (u_noise_density_ratio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_noise_density_ratio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_noise_density_ratio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_noise_density_ratio.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->noise_density_ratio);
      union {
        float real;
        uint32_t base;
      } u_locktime;
      u_locktime.real = this->locktime;
      *(outbuffer + offset + 0) = (u_locktime.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_locktime.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_locktime.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_locktime.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->locktime);
      *(outbuffer + offset + 0) = (this->tracking_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tracking_status >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tracking_status >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tracking_status >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tracking_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->prn_number =  ((uint16_t) (*(inbuffer + offset)));
      this->prn_number |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->prn_number);
      this->glofreq =  ((uint16_t) (*(inbuffer + offset)));
      this->glofreq |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->glofreq);
      union {
        double real;
        uint64_t base;
      } u_psr;
      u_psr.base = 0;
      u_psr.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_psr.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_psr.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_psr.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_psr.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_psr.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_psr.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_psr.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->psr = u_psr.real;
      offset += sizeof(this->psr);
      union {
        float real;
        uint32_t base;
      } u_psr_std;
      u_psr_std.base = 0;
      u_psr_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_psr_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_psr_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_psr_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->psr_std = u_psr_std.real;
      offset += sizeof(this->psr_std);
      union {
        double real;
        uint64_t base;
      } u_adr;
      u_adr.base = 0;
      u_adr.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_adr.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_adr.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_adr.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_adr.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_adr.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_adr.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_adr.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->adr = u_adr.real;
      offset += sizeof(this->adr);
      union {
        float real;
        uint32_t base;
      } u_adr_std;
      u_adr_std.base = 0;
      u_adr_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_adr_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_adr_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_adr_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->adr_std = u_adr_std.real;
      offset += sizeof(this->adr_std);
      union {
        float real;
        uint32_t base;
      } u_dopp;
      u_dopp.base = 0;
      u_dopp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dopp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dopp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dopp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dopp = u_dopp.real;
      offset += sizeof(this->dopp);
      union {
        float real;
        uint32_t base;
      } u_noise_density_ratio;
      u_noise_density_ratio.base = 0;
      u_noise_density_ratio.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_noise_density_ratio.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_noise_density_ratio.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_noise_density_ratio.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->noise_density_ratio = u_noise_density_ratio.real;
      offset += sizeof(this->noise_density_ratio);
      union {
        float real;
        uint32_t base;
      } u_locktime;
      u_locktime.base = 0;
      u_locktime.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_locktime.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_locktime.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_locktime.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->locktime = u_locktime.real;
      offset += sizeof(this->locktime);
      this->tracking_status =  ((uint32_t) (*(inbuffer + offset)));
      this->tracking_status |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tracking_status |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tracking_status |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tracking_status);
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/RangeInformation"; };
    const char * getMD5(){ return "2c29299d245fc707e8f7544af871f110"; };

  };

}
#endif
