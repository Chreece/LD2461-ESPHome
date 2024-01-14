import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import CONF_ID

from .const import CONF_LD2461_ID

DEPENDENCIES = ["uart"]
MULTI_CONF = True

ld2461_ns = cg.esphome_ns.namespace("ld2461")
LD2461 = ld2461_ns.class_("LD2461", cg.PollingComponent, uart.UARTDevice)

PresenceRegion = ld2461_ns.class_("PresenceRegion")

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(LD2461)
}).extend(cv.polling_component_schema("1s")).extend(uart.UART_DEVICE_SCHEMA)


def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield uart.register_uart_device(var, config)