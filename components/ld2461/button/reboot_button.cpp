#include "reboot_button.h"

namespace esphome {
namespace ld2461 {

void RebootButton::press_action() { this->parent_->reboot_and_read(); }

}  // namespace ld2461
}  // namespace esphome