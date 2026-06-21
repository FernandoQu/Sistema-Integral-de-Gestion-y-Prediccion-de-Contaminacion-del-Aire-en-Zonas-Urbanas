#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clima.h"

void ingresarDatosActuales(ZonaUrbana *zona) {
    printf("\n--- Ingreso de datos para la zona: %s ---\n", zona->zonas);

    printf("Ingrese la temperatura actual (C): ");
    scanf("%f", &zona->climaActual.temperatura);
    
    printf("Ingrese la velocidad del viento (km/h): ");
    scanf("%f", &zona->climaActual.velocidad);
    
    printf("Ingrese la humedad (%%): ");
    scanf("%f", &zona->climaActual.humedad);

    printf("\nIngrese los niveles actuales de contaminantes:\n");
    
    printf("Nivel de CO2: ");
    scanf("%f", &zona->actual.co2);
    
    printf("Nivel de SO2: ");
    scanf("%f", &zona->actual.so2);
    
    printf("Nivel de NO2: ");
    scanf("%f", &zona->actual.no2);
    
    printf("Nivel de PM2.5: ");
    scanf("%f", &zona->actual.pm25);
    
    printf("\nDatos de la zona %s ingresados correctamente.\n", zona->zonas);
}