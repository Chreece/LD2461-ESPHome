import esphome.codegen as cg
from esphome.components import text_sensor
import esphome.config_validation as cv
from esphome.const import (
    ENTITY_CATEGORY_DIAGNOSTIC,
    CONF_VERSION,
    CONF_UID,
    ICON_BLUETOOTH,
    ICON_CHIP,
)
from . import LD2461
from .const import CONF_LD2461_ID

DEPENDENCIES = ["ld2461"]

CONFIG_SCHEMA = {
    cv.GenerateID(CONF_LD2461_ID): cv.use_id(LD2461),
    cv.Optional(CONF_VERSION): text_sensor.text_sensor_schema(
        entity_category=ENTITY_CATEGORY_DIAGNOSTIC, icon=ICON_CHIP
    ),
    cv.Optional(CONF_UID): text_sensor.text_sensor_schema(
        entity_category=ENTITY_CATEGORY_DIAGNOSTIC, icon=ICON_BLUETOOTH
    ),
}

async def to_code(config):
    ld2461 = await cg.get_variable(config[CONF_LD2461_ID])
    if version_config := config.get(CONF_VERSION):
        sens = await text_sensor.new_text_sensor(version_config)
        cg.add(ld2461.set_version_text_sensor(sens))
    if uid_config := config.get(CONF_UID):
        sens = await text_sensor.new_text_sensor(uid_config)
        cg.add(ld2461.set_uuid_text_sensor(sens))
