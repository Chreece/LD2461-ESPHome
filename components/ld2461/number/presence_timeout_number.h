#pragma once

#include "esphome/components/number/number.h"
#include "esphome/core/preferences.h"
#include "../ld2461.h"

namespace esphome {
namespace ld2461 {

class PresenceTimeoutNumber : public number::Number, public Component, public Parented<LD2461>{
    public:
        void setup() override;
        void set_initial_value(float initial_value) { this->initial_value_ = initial_value; }
        void set_restore_value(bool restore_value) { this->restore_value_ = restore_value; }

    protected:
        float initial_value_{NAN};
        bool restore_value_{true};
        ESPPreferenceObject pref_;
        void control(float value) override;
};

}  // namespace ld2461
}  // namespace esphome
