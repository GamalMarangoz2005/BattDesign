#ifndef BATTERY_H
#define BATTERY_H

typedef struct {
    float nominalVoltage;
    int   cellCapacity;
} BatteryCell;

typedef struct {
    int packEnergy;
    int packNominalVoltage;
} BatteryPack;


#endif

