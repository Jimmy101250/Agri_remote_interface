#ifndef _ROS_novatel_gps_msgs_TrackstatChannel_h
#define _ROS_novatel_gps_msgs_TrackstatChannel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace novatel_gps_msgs
{

  class TrackstatChannel : public ros::Msg
  {
    public:
      typedef int16_t _prn_type;
      _prn_type prn;
      typedef int16_t _glofreq_type;
      _glofreq_type glofreq;
      typedef uint32_t _ch_tr_status_type;
      _ch_tr_status_type ch_tr_status;
      typedef double _psr_type;
      _psr_type psr;
      typedef float _doppler_type;
      _doppler_type doppler;
      typedef float _c_no_type;
      _c_no_type c_no;
      typedef float _locktime_type;
      _locktime_type locktime;
      typedef float _psr_res_type;
      _psr_res_type psr_res;
      typedef const char* _reject_type;
      _reject_type reject;
      typedef float _psr_weight_type;
      _psr_weight_type psr_weight;

    TrackstatChannel():
      prn(0),
      glofreq(0),
      ch_tr_status(0),
      psr(0),
      doppler(0),
      c_no(0),
      locktime(0),
      psr_res(0),
      reject(""),
      psr_weight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_prn;
      u_prn.real = this->prn;
      *(outbuffer + offset + 0) = (u_prn.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_prn.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->prn);
      union {
        int16_t real;
        uint16_t base;
      } u_glofreq;
      u_glofreq.real = this->glofreq;
      *(outbuffer + offset + 0) = (u_glofreq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_glofreq.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->glofreq);
      *(outbuffer + offset + 0) = (this->ch_tr_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ch_tr_status >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ch_tr_status >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ch_tr_status >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ch_tr_status);
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
      } u_doppler;
      u_doppler.real = this->doppler;
      *(outbuffer + offset + 0) = (u_doppler.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_doppler.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_doppler.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_doppler.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->doppler);
      union {
        float real;
        uint32_t base;
      } u_c_no;
      u_c_no.real = this->c_no;
      *(outbuffer + offset + 0) = (u_c_no.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_c_no.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_c_no.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_c_no.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->c_no);
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
      union {
        float real;
        uint32_t base;
      } u_psr_res;
      u_psr_res.real = this->psr_res;
      *(outbuffer + offset + 0) = (u_psr_res.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_psr_res.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_psr_res.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_psr_res.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->psr_res);
      uint32_t length_reject = strlen(this->reject);
      varToArr(outbuffer + offset, length_reject);
      offset += 4;
      memcpy(outbuffer + offset, this->reject, length_reject);
      offset += length_reject;
      union {
        float real;
        uint32_t base;
      } u_psr_weight;
      u_psr_weight.real = this->psr_weight;
      *(outbuffer + offset + 0) = (u_psr_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_psr_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_psr_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_psr_weight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->psr_weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_prn;
      u_prn.base = 0;
      u_prn.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_prn.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->prn = u_prn.real;
      offset += sizeof(this->prn);
      union {
        int16_t real;
        uint16_t base;
      } u_glofreq;
      u_glofreq.base = 0;
      u_glofreq.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_glofreq.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->glofreq = u_glofreq.real;
      offset += sizeof(this->glofreq);
      this->ch_tr_status =  ((uint32_t) (*(inbuffer + offset)));
      this->ch_tr_status |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ch_tr_status |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->ch_tr_status |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->ch_tr_status);
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
      } u_doppler;
      u_doppler.base = 0;
      u_doppler.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_doppler.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_doppler.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_doppler.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->doppler = u_doppler.real;
      offset += sizeof(this->doppler);
      union {
        float real;
        uint32_t base;
      } u_c_no;
      u_c_no.base = 0;
      u_c_no.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_c_no.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_c_no.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_c_no.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->c_no = u_c_no.real;
      offset += sizeof(this->c_no);
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
      union {
        float real;
        uint32_t base;
      } u_psr_res;
      u_psr_res.base = 0;
      u_psr_res.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_psr_res.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_psr_res.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_psr_res.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->psr_res = u_psr_res.real;
      offset += sizeof(this->psr_res);
      uint32_t length_reject;
      arrToVar(length_reject, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_reject; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_reject-1]=0;
      this->reject = (char *)(inbuffer + offset-1);
      offset += length_reject;
      union {
        float real;
        uint32_t base;
      } u_psr_weight;
      u_psr_weight.base = 0;
      u_psr_weight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_psr_weight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_psr_weight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_psr_weight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->psr_weight = u_psr_weight.real;
      offset += sizeof(this->psr_weight);
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/TrackstatChannel"; };
    const char * getMD5(){ return "295831118c5ddfb83ac5b655586ae7ef"; };

  };

}
#endif
