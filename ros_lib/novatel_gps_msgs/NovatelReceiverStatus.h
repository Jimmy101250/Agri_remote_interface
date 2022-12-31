#ifndef _ROS_novatel_gps_msgs_NovatelReceiverStatus_h
#define _ROS_novatel_gps_msgs_NovatelReceiverStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace novatel_gps_msgs
{

  class NovatelReceiverStatus : public ros::Msg
  {
    public:
      typedef uint32_t _original_status_code_type;
      _original_status_code_type original_status_code;
      typedef bool _error_flag_type;
      _error_flag_type error_flag;
      typedef bool _temperature_flag_type;
      _temperature_flag_type temperature_flag;
      typedef bool _voltage_supply_flag_type;
      _voltage_supply_flag_type voltage_supply_flag;
      typedef bool _antenna_powered_type;
      _antenna_powered_type antenna_powered;
      typedef bool _antenna_is_open_type;
      _antenna_is_open_type antenna_is_open;
      typedef bool _antenna_is_shorted_type;
      _antenna_is_shorted_type antenna_is_shorted;
      typedef bool _cpu_overload_flag_type;
      _cpu_overload_flag_type cpu_overload_flag;
      typedef bool _com1_buffer_overrun_type;
      _com1_buffer_overrun_type com1_buffer_overrun;
      typedef bool _com2_buffer_overrun_type;
      _com2_buffer_overrun_type com2_buffer_overrun;
      typedef bool _com3_buffer_overrun_type;
      _com3_buffer_overrun_type com3_buffer_overrun;
      typedef bool _usb_buffer_overrun_type;
      _usb_buffer_overrun_type usb_buffer_overrun;
      typedef bool _rf1_agc_flag_type;
      _rf1_agc_flag_type rf1_agc_flag;
      typedef bool _rf2_agc_flag_type;
      _rf2_agc_flag_type rf2_agc_flag;
      typedef bool _almanac_flag_type;
      _almanac_flag_type almanac_flag;
      typedef bool _position_solution_flag_type;
      _position_solution_flag_type position_solution_flag;
      typedef bool _position_fixed_flag_type;
      _position_fixed_flag_type position_fixed_flag;
      typedef bool _clock_steering_status_enabled_type;
      _clock_steering_status_enabled_type clock_steering_status_enabled;
      typedef bool _clock_model_flag_type;
      _clock_model_flag_type clock_model_flag;
      typedef bool _oemv_external_oscillator_flag_type;
      _oemv_external_oscillator_flag_type oemv_external_oscillator_flag;
      typedef bool _software_resource_flag_type;
      _software_resource_flag_type software_resource_flag;
      typedef bool _aux1_status_event_flag_type;
      _aux1_status_event_flag_type aux1_status_event_flag;
      typedef bool _aux2_status_event_flag_type;
      _aux2_status_event_flag_type aux2_status_event_flag;
      typedef bool _aux3_status_event_flag_type;
      _aux3_status_event_flag_type aux3_status_event_flag;

    NovatelReceiverStatus():
      original_status_code(0),
      error_flag(0),
      temperature_flag(0),
      voltage_supply_flag(0),
      antenna_powered(0),
      antenna_is_open(0),
      antenna_is_shorted(0),
      cpu_overload_flag(0),
      com1_buffer_overrun(0),
      com2_buffer_overrun(0),
      com3_buffer_overrun(0),
      usb_buffer_overrun(0),
      rf1_agc_flag(0),
      rf2_agc_flag(0),
      almanac_flag(0),
      position_solution_flag(0),
      position_fixed_flag(0),
      clock_steering_status_enabled(0),
      clock_model_flag(0),
      oemv_external_oscillator_flag(0),
      software_resource_flag(0),
      aux1_status_event_flag(0),
      aux2_status_event_flag(0),
      aux3_status_event_flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->original_status_code >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->original_status_code >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->original_status_code >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->original_status_code >> (8 * 3)) & 0xFF;
      offset += sizeof(this->original_status_code);
      union {
        bool real;
        uint8_t base;
      } u_error_flag;
      u_error_flag.real = this->error_flag;
      *(outbuffer + offset + 0) = (u_error_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error_flag);
      union {
        bool real;
        uint8_t base;
      } u_temperature_flag;
      u_temperature_flag.real = this->temperature_flag;
      *(outbuffer + offset + 0) = (u_temperature_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temperature_flag);
      union {
        bool real;
        uint8_t base;
      } u_voltage_supply_flag;
      u_voltage_supply_flag.real = this->voltage_supply_flag;
      *(outbuffer + offset + 0) = (u_voltage_supply_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->voltage_supply_flag);
      union {
        bool real;
        uint8_t base;
      } u_antenna_powered;
      u_antenna_powered.real = this->antenna_powered;
      *(outbuffer + offset + 0) = (u_antenna_powered.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->antenna_powered);
      union {
        bool real;
        uint8_t base;
      } u_antenna_is_open;
      u_antenna_is_open.real = this->antenna_is_open;
      *(outbuffer + offset + 0) = (u_antenna_is_open.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->antenna_is_open);
      union {
        bool real;
        uint8_t base;
      } u_antenna_is_shorted;
      u_antenna_is_shorted.real = this->antenna_is_shorted;
      *(outbuffer + offset + 0) = (u_antenna_is_shorted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->antenna_is_shorted);
      union {
        bool real;
        uint8_t base;
      } u_cpu_overload_flag;
      u_cpu_overload_flag.real = this->cpu_overload_flag;
      *(outbuffer + offset + 0) = (u_cpu_overload_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cpu_overload_flag);
      union {
        bool real;
        uint8_t base;
      } u_com1_buffer_overrun;
      u_com1_buffer_overrun.real = this->com1_buffer_overrun;
      *(outbuffer + offset + 0) = (u_com1_buffer_overrun.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->com1_buffer_overrun);
      union {
        bool real;
        uint8_t base;
      } u_com2_buffer_overrun;
      u_com2_buffer_overrun.real = this->com2_buffer_overrun;
      *(outbuffer + offset + 0) = (u_com2_buffer_overrun.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->com2_buffer_overrun);
      union {
        bool real;
        uint8_t base;
      } u_com3_buffer_overrun;
      u_com3_buffer_overrun.real = this->com3_buffer_overrun;
      *(outbuffer + offset + 0) = (u_com3_buffer_overrun.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->com3_buffer_overrun);
      union {
        bool real;
        uint8_t base;
      } u_usb_buffer_overrun;
      u_usb_buffer_overrun.real = this->usb_buffer_overrun;
      *(outbuffer + offset + 0) = (u_usb_buffer_overrun.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->usb_buffer_overrun);
      union {
        bool real;
        uint8_t base;
      } u_rf1_agc_flag;
      u_rf1_agc_flag.real = this->rf1_agc_flag;
      *(outbuffer + offset + 0) = (u_rf1_agc_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rf1_agc_flag);
      union {
        bool real;
        uint8_t base;
      } u_rf2_agc_flag;
      u_rf2_agc_flag.real = this->rf2_agc_flag;
      *(outbuffer + offset + 0) = (u_rf2_agc_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rf2_agc_flag);
      union {
        bool real;
        uint8_t base;
      } u_almanac_flag;
      u_almanac_flag.real = this->almanac_flag;
      *(outbuffer + offset + 0) = (u_almanac_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->almanac_flag);
      union {
        bool real;
        uint8_t base;
      } u_position_solution_flag;
      u_position_solution_flag.real = this->position_solution_flag;
      *(outbuffer + offset + 0) = (u_position_solution_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->position_solution_flag);
      union {
        bool real;
        uint8_t base;
      } u_position_fixed_flag;
      u_position_fixed_flag.real = this->position_fixed_flag;
      *(outbuffer + offset + 0) = (u_position_fixed_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->position_fixed_flag);
      union {
        bool real;
        uint8_t base;
      } u_clock_steering_status_enabled;
      u_clock_steering_status_enabled.real = this->clock_steering_status_enabled;
      *(outbuffer + offset + 0) = (u_clock_steering_status_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clock_steering_status_enabled);
      union {
        bool real;
        uint8_t base;
      } u_clock_model_flag;
      u_clock_model_flag.real = this->clock_model_flag;
      *(outbuffer + offset + 0) = (u_clock_model_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clock_model_flag);
      union {
        bool real;
        uint8_t base;
      } u_oemv_external_oscillator_flag;
      u_oemv_external_oscillator_flag.real = this->oemv_external_oscillator_flag;
      *(outbuffer + offset + 0) = (u_oemv_external_oscillator_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->oemv_external_oscillator_flag);
      union {
        bool real;
        uint8_t base;
      } u_software_resource_flag;
      u_software_resource_flag.real = this->software_resource_flag;
      *(outbuffer + offset + 0) = (u_software_resource_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->software_resource_flag);
      union {
        bool real;
        uint8_t base;
      } u_aux1_status_event_flag;
      u_aux1_status_event_flag.real = this->aux1_status_event_flag;
      *(outbuffer + offset + 0) = (u_aux1_status_event_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->aux1_status_event_flag);
      union {
        bool real;
        uint8_t base;
      } u_aux2_status_event_flag;
      u_aux2_status_event_flag.real = this->aux2_status_event_flag;
      *(outbuffer + offset + 0) = (u_aux2_status_event_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->aux2_status_event_flag);
      union {
        bool real;
        uint8_t base;
      } u_aux3_status_event_flag;
      u_aux3_status_event_flag.real = this->aux3_status_event_flag;
      *(outbuffer + offset + 0) = (u_aux3_status_event_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->aux3_status_event_flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->original_status_code =  ((uint32_t) (*(inbuffer + offset)));
      this->original_status_code |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->original_status_code |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->original_status_code |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->original_status_code);
      union {
        bool real;
        uint8_t base;
      } u_error_flag;
      u_error_flag.base = 0;
      u_error_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->error_flag = u_error_flag.real;
      offset += sizeof(this->error_flag);
      union {
        bool real;
        uint8_t base;
      } u_temperature_flag;
      u_temperature_flag.base = 0;
      u_temperature_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->temperature_flag = u_temperature_flag.real;
      offset += sizeof(this->temperature_flag);
      union {
        bool real;
        uint8_t base;
      } u_voltage_supply_flag;
      u_voltage_supply_flag.base = 0;
      u_voltage_supply_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->voltage_supply_flag = u_voltage_supply_flag.real;
      offset += sizeof(this->voltage_supply_flag);
      union {
        bool real;
        uint8_t base;
      } u_antenna_powered;
      u_antenna_powered.base = 0;
      u_antenna_powered.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->antenna_powered = u_antenna_powered.real;
      offset += sizeof(this->antenna_powered);
      union {
        bool real;
        uint8_t base;
      } u_antenna_is_open;
      u_antenna_is_open.base = 0;
      u_antenna_is_open.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->antenna_is_open = u_antenna_is_open.real;
      offset += sizeof(this->antenna_is_open);
      union {
        bool real;
        uint8_t base;
      } u_antenna_is_shorted;
      u_antenna_is_shorted.base = 0;
      u_antenna_is_shorted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->antenna_is_shorted = u_antenna_is_shorted.real;
      offset += sizeof(this->antenna_is_shorted);
      union {
        bool real;
        uint8_t base;
      } u_cpu_overload_flag;
      u_cpu_overload_flag.base = 0;
      u_cpu_overload_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cpu_overload_flag = u_cpu_overload_flag.real;
      offset += sizeof(this->cpu_overload_flag);
      union {
        bool real;
        uint8_t base;
      } u_com1_buffer_overrun;
      u_com1_buffer_overrun.base = 0;
      u_com1_buffer_overrun.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->com1_buffer_overrun = u_com1_buffer_overrun.real;
      offset += sizeof(this->com1_buffer_overrun);
      union {
        bool real;
        uint8_t base;
      } u_com2_buffer_overrun;
      u_com2_buffer_overrun.base = 0;
      u_com2_buffer_overrun.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->com2_buffer_overrun = u_com2_buffer_overrun.real;
      offset += sizeof(this->com2_buffer_overrun);
      union {
        bool real;
        uint8_t base;
      } u_com3_buffer_overrun;
      u_com3_buffer_overrun.base = 0;
      u_com3_buffer_overrun.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->com3_buffer_overrun = u_com3_buffer_overrun.real;
      offset += sizeof(this->com3_buffer_overrun);
      union {
        bool real;
        uint8_t base;
      } u_usb_buffer_overrun;
      u_usb_buffer_overrun.base = 0;
      u_usb_buffer_overrun.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->usb_buffer_overrun = u_usb_buffer_overrun.real;
      offset += sizeof(this->usb_buffer_overrun);
      union {
        bool real;
        uint8_t base;
      } u_rf1_agc_flag;
      u_rf1_agc_flag.base = 0;
      u_rf1_agc_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rf1_agc_flag = u_rf1_agc_flag.real;
      offset += sizeof(this->rf1_agc_flag);
      union {
        bool real;
        uint8_t base;
      } u_rf2_agc_flag;
      u_rf2_agc_flag.base = 0;
      u_rf2_agc_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rf2_agc_flag = u_rf2_agc_flag.real;
      offset += sizeof(this->rf2_agc_flag);
      union {
        bool real;
        uint8_t base;
      } u_almanac_flag;
      u_almanac_flag.base = 0;
      u_almanac_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->almanac_flag = u_almanac_flag.real;
      offset += sizeof(this->almanac_flag);
      union {
        bool real;
        uint8_t base;
      } u_position_solution_flag;
      u_position_solution_flag.base = 0;
      u_position_solution_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->position_solution_flag = u_position_solution_flag.real;
      offset += sizeof(this->position_solution_flag);
      union {
        bool real;
        uint8_t base;
      } u_position_fixed_flag;
      u_position_fixed_flag.base = 0;
      u_position_fixed_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->position_fixed_flag = u_position_fixed_flag.real;
      offset += sizeof(this->position_fixed_flag);
      union {
        bool real;
        uint8_t base;
      } u_clock_steering_status_enabled;
      u_clock_steering_status_enabled.base = 0;
      u_clock_steering_status_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clock_steering_status_enabled = u_clock_steering_status_enabled.real;
      offset += sizeof(this->clock_steering_status_enabled);
      union {
        bool real;
        uint8_t base;
      } u_clock_model_flag;
      u_clock_model_flag.base = 0;
      u_clock_model_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clock_model_flag = u_clock_model_flag.real;
      offset += sizeof(this->clock_model_flag);
      union {
        bool real;
        uint8_t base;
      } u_oemv_external_oscillator_flag;
      u_oemv_external_oscillator_flag.base = 0;
      u_oemv_external_oscillator_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->oemv_external_oscillator_flag = u_oemv_external_oscillator_flag.real;
      offset += sizeof(this->oemv_external_oscillator_flag);
      union {
        bool real;
        uint8_t base;
      } u_software_resource_flag;
      u_software_resource_flag.base = 0;
      u_software_resource_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->software_resource_flag = u_software_resource_flag.real;
      offset += sizeof(this->software_resource_flag);
      union {
        bool real;
        uint8_t base;
      } u_aux1_status_event_flag;
      u_aux1_status_event_flag.base = 0;
      u_aux1_status_event_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->aux1_status_event_flag = u_aux1_status_event_flag.real;
      offset += sizeof(this->aux1_status_event_flag);
      union {
        bool real;
        uint8_t base;
      } u_aux2_status_event_flag;
      u_aux2_status_event_flag.base = 0;
      u_aux2_status_event_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->aux2_status_event_flag = u_aux2_status_event_flag.real;
      offset += sizeof(this->aux2_status_event_flag);
      union {
        bool real;
        uint8_t base;
      } u_aux3_status_event_flag;
      u_aux3_status_event_flag.base = 0;
      u_aux3_status_event_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->aux3_status_event_flag = u_aux3_status_event_flag.real;
      offset += sizeof(this->aux3_status_event_flag);
     return offset;
    }

    const char * getType(){ return "novatel_gps_msgs/NovatelReceiverStatus"; };
    const char * getMD5(){ return "cf2774401808a6dde392e2ebdb09ca15"; };

  };

}
#endif
