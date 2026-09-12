#include <stdio.h>
#include <math.h>

typedef struct {
    float nominalVoltage;
    int   cellCapacity;
} BatteryCell;

typedef struct {
    int packEnergy;
    int packNominalVoltage;
} BatteryPack;

float seriesStacking(BatteryCell *cellConfig, BatteryPack *packConfig);
float parallelStacking(BatteryCell *cellConfig, BatteryPack *packConfig);

float kWh_to_Wh(float kWh);

int main(void) {

    BatteryCell cell;
    printf("\n--- Battery Cell Configuration ---\n");

    printf("Cell Nominal Voltage(V): ");
    scanf("%f", &cell.nominalVoltage);

    printf("Cell Capacity(Ah): ");
    scanf("%d", &cell.cellCapacity);

    BatteryPack pack;
    printf("\n\n--- Battery Pack Configuration ---\n");

    printf("Battery Pack Energy(kWh): ");
    scanf("%d", &pack.packEnergy);

    printf("Pack Nominal Voltage(V): ");
    scanf("%d", &pack.packNominalVoltage);

    float seriesConnections; 
    seriesConnections = seriesStacking(&cell, &pack);

    float parallelConnections;
    parallelConnections = parallelStacking(&cell, &pack);

    printf("\nseriesConnections: %.2f\n", seriesConnections);
    printf("parallelConnections: %.2f\n\n", parallelConnections);

    return 0;
}

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
    printf("packEnergy: %.2f Wh\n", packEnergy);

    packNominal = packConfig->packNominalVoltage;
    cellCapacity = cellConfig->cellCapacity;

    computedParallel = ( (packEnergy / packNominal) / cellCapacity);
    printf("(packEnergy / packNominal) is %.2f\n", (packEnergy / packNominal));
    return computedParallel;
}

float kWh_to_Wh(float kWh)
{
    return (kWh) * 1000;
}