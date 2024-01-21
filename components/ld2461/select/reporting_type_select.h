#pragma once

#include "esphome/components/select/select.h"
#include "../ld2461.h"

namespace esphome {
namespace ld2461 {

class ReportingType : public select::Select, public Parented<LD2461> {
    public:
        ReportingType() = default;

    protected:
        void control(const std::string &value) override;
};

}  // namespace ld2461
}  // namespace esphome