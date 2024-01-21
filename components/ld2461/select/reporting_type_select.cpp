#include "reporting_type_select.h"

namespace esphome {
namespace ld2461 {

enum ReportingTypeStructure : uint8_t {
  TRACE_COORDINATES = 0,
  TARGETS = 1,
  BOTH = 2,
};

static const std::map<std::string, uint8_t> REPORTING_TYPE_ENUM_TO_INT{
    {"Trace Coordinates", TRACE_COORDINATES},
    {"Targets Sum", TARGETS},
    {"Both", BOTH}
};

void ReportingType::control(const std::string &value) {
  this->publish_state(value);
  this->parent_->set_reporting_type(REPORTING_TYPE_ENUM_TO_INT.at(value));
}

}  // namespace ld2461
}  // namespace esphome