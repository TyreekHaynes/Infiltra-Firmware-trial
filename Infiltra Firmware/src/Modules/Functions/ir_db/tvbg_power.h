#pragma once
#include "tvbg_ir_types.h"

static const TVBGToken TVBG_POWER_LIST[] PROGMEM = {
  
  { "LG",      "Power", IRProto::NEC, 0x20DF10EF,    32,   nullptr, 0, 38 },
  { "Samsung", "Power", IRProto::NEC, 0xE0E040BF,    32,   nullptr, 0, 38 },
  
  { "Sony",    "Power", IRProto::SONY, 0x0A90,       12,   nullptr, 0, 40 },
};

static constexpr size_t TVBG_POWER_COUNT = sizeof(TVBG_POWER_LIST)/sizeof(TVBG_POWER_LIST[0]);
