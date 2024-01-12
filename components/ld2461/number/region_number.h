#pragma once

#include "esphome/components/number/number.h"
#include "../ld2461.h"

namespace esphome {
namespace ld2461 {

class RegionNumber : public number::Number, public Parented<LD2461> {
    public:
        RegionNumber(uint8_t region);

    protected:
        uint8_t region_;
        void control(float value) override;
};

}  // namespace ld2461
}  // namespace esphome