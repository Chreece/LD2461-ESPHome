#pragma once

#include "esphome/components/button/button.h"
#include "../ld2461.h"

namespace esphome {
namespace ld2461 {

class RebootButton : public button::Button, public Parented<LD2461> {
    public:
        RebootButton() = default;

    protected:
        void press_action() override;
};

}  // namespace ld2461
}  // namespace esphome