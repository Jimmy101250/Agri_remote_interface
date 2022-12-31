#ifndef _ROS_marti_common_msgs_Matrix3x3Stamped_h
#define _ROS_marti_common_msgs_Matrix3x3Stamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace marti_common_msgs
{

  class Matrix3x3Stamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      double matrix[9];

    Matrix3x3Stamped():
      header(),
      matrix()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_matrixi;
      u_matrixi.real = this->matrix[i];
      *(outbuffer + offset + 0) = (u_matrixi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_matrixi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_matrixi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_matrixi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_matrixi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_matrixi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_matrixi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_matrixi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->matrix[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_matrixi;
      u_matrixi.base = 0;
      u_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_matrixi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->matrix[i] = u_matrixi.real;
      offset += sizeof(this->matrix[i]);
      }
     return offset;
    }

    const char * getType(){ return "marti_common_msgs/Matrix3x3Stamped"; };
    const char * getMD5(){ return "6f6aca2b78f71bd7b958ad349352f091"; };

  };

}
#endif
