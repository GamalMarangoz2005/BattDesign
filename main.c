#include "include/battery.h"
#include "include/battery_logic.h"

#include <stdio.h>
#include <math.h>


int main(void) {

    // create batterycells specs function.
    BatteryCell cell;
    printf("\n--- Battery Cell Configuration ---\n");

    printf("Cell Nominal Voltage(V): ");
    scanf("%f", &cell.nominalVoltage);

    printf("Cell Capacity(Ah): ");
    scanf("%d", &cell.cellCapacity);

    // get batteryconfiguration function
    BatteryPack pack;
    printf("\n\n--- Battery Pack Configuration ---\n");

    printf("Battery Pack Energy(kWh): ");
    scanf("%d", &pack.packEnergy);

    printf("Pack Nominal Voltage(V): ");
    scanf("%d", &pack.packNominalVoltage);

    // show the configuration function
    float seriesConnections; 
    seriesConnections = seriesStacking(&cell, &pack);

    float parallelConnections;
    parallelConnections = parallelStacking(&cell, &pack);

    printf("\nseriesConnections: %.2f\n", seriesConnections);
    printf("parallelConnections: %.2f\n\n", parallelConnections);

    return 0;
}

