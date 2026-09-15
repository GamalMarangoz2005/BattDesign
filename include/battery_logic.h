#ifndef BATTERY_LOGIC_H
#define BATTERY_LOGIC_H
#include "battery.h"

float seriesStacking(BatteryCell *cellConfig, BatteryPack *packConfig);
float parallelStacking(BatteryCell *cellConfig, BatteryPack *packConfig);
float kWh_to_Wh(float kWh);



#endif