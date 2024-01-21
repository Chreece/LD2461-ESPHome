#pragma once
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"

#include "typedefs.h"

#ifdef USE_SENSOR
#include "esphome/components/sensor/sensor.h"
#endif

#ifdef USE_BINARY_SENSOR
#include "esphome/components/binary_sensor/binary_sensor.h"
#endif

#ifdef USE_NUMBER
#include "esphome/components/number/number.h"
#include "number/entry_point.h"
#include "number/presence_region.h"
#endif

#ifdef USE_TEXT_SENSOR
#include "esphome/components/text_sensor/text_sensor.h"
#endif

#ifdef USE_SWITCH
#include "esphome/components/switch/switch.h"
#endif

#ifdef USE_BUTTON
#include "esphome/components/button/button.h"
#endif

#ifdef USE_SELECT
#include "esphome/components/select/select.h"
#endif

namespace esphome {
namespace ld2461 {

class EntryPoint;
class PresenceRegion;

class LD2461 : public uart::UARTDevice, public PollingComponent {
#ifdef USE_SENSOR
  SUB_SENSOR(position_x_0)
  SUB_SENSOR(position_y_0)

  SUB_SENSOR(position_x_1)
  SUB_SENSOR(position_y_1)

  SUB_SENSOR(position_x_2)
  SUB_SENSOR(position_y_2)

  SUB_SENSOR(position_x_3)
  SUB_SENSOR(position_y_3)

  SUB_SENSOR(position_x_4)
  SUB_SENSOR(position_y_4)
  
  SUB_SENSOR(target_count)
#endif

#ifdef USE_NUMBER
  SUB_NUMBER(presence_timeout)
#endif

#ifdef USE_BINARY_SENSOR
  SUB_BINARY_SENSOR(target)
#endif

#ifdef USE_TEXT_SENSOR
  SUB_TEXT_SENSOR(version)
  SUB_TEXT_SENSOR(uuid)
#endif

#ifdef USE_BUTTON
  SUB_BUTTON(reset)
#endif

#ifdef USE_SELECT
  SUB_SELECT(baud_rate)
  SUB_SELECT(regions_type)
  SUB_SELECT(reporting_type)
#endif

  public:
    void setup() override;
    void loop() override;
    void update() override;
    void dump_config() override;
    void read_all_info();
    void restore_factory();
    void set_baud_rate(uint8_t state);
    void set_regions_type(uint8_t state);
    void set_reporting_type(uint8_t state);
    void add_entry_point(EntryPoint *entry_point);
    void add_presence_region(PresenceRegion *presence_region);

#ifdef USE_NUMBER
    void set_region_number(int region, int coord, number::Number *n);
    void set_region(uint8_t region);
    void set_presence_timeout_number();
#endif

  private:
    enum Constants {
        SET_BAUDRATE = 0x01,
        SET_REPORTING = 0x02,
        GET_REPORTING = 0x03,
        SET_REGIONS = 0x04,
        DISABLE_REGIONS = 0x05,
        GET_REGIONS = 0x06,
        GET_COORDINATES = 0x07,
        GET_NUM_TARGETS = 0x08,
        READ_FIRMWARE = 0x09,
        RESTORE_FACTORY = 0x0A,
        FH_LAST = 0xDD,
        FE_LAST = 0xFF
    };   

    uint8_t FRAME_HEADER[3] = { 0xFF, 0xEE, 0xDD };
    uint8_t FRAME_END[3] = { 0xDD, 0xEE, 0xFF };

    serial_buffer_struct serial_data;
    frame_start_struct response_frame_header;
    uint8_t response_buffer[256];
    data_packet_struct received_data;
    regions sensor_regions;
    reporting sensor_reporting;
    std::string version_;
    std::string uuid_;
    coordinates person[5];
    coordinates person_before[5];
    float presence_timeout = 0.0;
    int32_t presence_millis[5];
    std::vector<EntryPoint *> entry_points;
    std::vector<PresenceRegion *> presence_regions;

#ifdef USE_NUMBER
    std::vector<std::vector<number::Number*>> region_numbers_ = std::vector<std::vector<number::Number*>>(3, std::vector<number::Number*>(4));;
#endif

    int16_t transform(uint16_t data);
    void report_position(void);

    void send_command_(uint8_t command_str, const uint8_t *command_value, int command_value_len);
    void get_version_();
    void get_regions_();
    void get_reporting_();
};


}  // namespace ld2461
}  // namespace esphome
