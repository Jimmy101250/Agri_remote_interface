#ifndef _ROS_SERVICE_NovatelFRESET_h
#define _ROS_SERVICE_NovatelFRESET_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace novatel_gps_msgs
{

static const char NOVATELFRESET[] = "novatel_gps_msgs/NovatelFRESET";

  class NovatelFRESETRequest : public ros::Msg
  {
    public:
      typedef const char* _target_type;
      _target_type target;

    NovatelFRESETRequest():
      target("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_target = strlen(this->target);
      varToArr(outbuffer + offset, length_target);
      offset += 4;
      memcpy(outbuffer + offset, this->target, length_target);
      offset += length_target;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_target;
      arrToVar(length_target, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target-1]=0;
      this->target = (char *)(inbuffer + offset-1);
      offset += length_target;
     return offset;
    }

    const char * getType(){ return NOVATELFRESET; };
    const char * getMD5(){ return "10e5cb524446adda5ea1765c6838590d"; };

  };

  class NovatelFRESETResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    NovatelFRESETResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return NOVATELFRESET; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class NovatelFRESET {
    public:
    typedef NovatelFRESETRequest Request;
    typedef NovatelFRESETResponse Response;
  };

}
#endif
