#include <stdio.h>
#include "battery_logic.h"
#include "battery.h"

float seriesStacking(BatteryCell *cellConfig, BatteryPack *packConfig)
{
    float computedSeries;

    int packNominal;
    float cellNominal;

    packNominal = packConfig->packNominalVoltage;
    cellNominal = cellConfig->nominalVoltage;

    computedSeries = (packNominal / cellNominal);

    return computedSeries;
}

float parallelStacking(BatteryCell *cellConfig, BatteryPack *packConfig)
{
    float computedParallel;

    float packEnergy;
    int packNominal;
    int cellCapacity;

    packEnergy =  kWh_to_Wh(packConfig->packEnergy);
    packNominal = packConfig->packNominalVoltage;
    cellCapacity = cellConfig->cellCapacity;

    computedParallel = ( (packEnergy / packNominal) / cellCapacity);

    return computedParallel;
}

float kWh_to_Wh(float kWh)
{
    return (kWh) * 1000;
}