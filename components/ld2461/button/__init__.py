import esphome.codegen as cg
from esphome.components import button
import esphome.config_validation as cv
from esphome.const import (
    DEVICE_CLASS_RESTART,
    ENTITY_CATEGORY_DIAGNOSTIC,
    ICON_RESTART,
    ICON_RESTART_ALERT,
    ICON_DATABASE,
)
from .. import LD2461, ld2461_ns
from ..const import CONF_FACTORY_RESET, CONF_REBOOT, CONF_LD2461_ID

ResetButton = ld2461_ns.class_("ResetButton", button.Button)
RebootButton = ld2461_ns.class_("RebootButton", button.Button)

CONFIG_SCHEMA = {
    cv.GenerateID(CONF_LD2461_ID): cv.use_id(LD2461),
    cv.Optional(CONF_FACTORY_RESET): button.button_schema(
        ResetButton,
        device_class=DEVICE_CLASS_RESTART,
        entity_category=ENTITY_CATEGORY_DIAGNOSTIC,
        icon=ICON_RESTART_ALERT,
    ),
    cv.Optional(CONF_REBOOT): button.button_schema(
        RebootButton,
        device_class=DEVICE_CLASS_RESTART,
        entity_category=ENTITY_CATEGORY_DIAGNOSTIC,
        icon=ICON_RESTART,
    )
}


async def to_code(config):
    ld2461 = await cg.get_variable(config[CONF_LD2461_ID])
    if factory_reset_config := config.get(CONF_FACTORY_RESET):
        b = await button.new_button(factory_reset_config)
        await cg.register_parented(b, config[CONF_LD2461_ID])
        cg.add(ld2461.set_reset_button(b))
    if restart_config := config.get(CONF_REBOOT):
        b = await button.new_button(restart_config)
        await cg.register_parented(b, config[CONF_LD2461_ID])
        cg.add(ld2461.set_reboot_button(b))
