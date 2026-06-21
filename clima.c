#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clima.h"

void ingresarDatosActuales(ZonaUrbana *zona) {
    printf("\n--- Ingreso de datos para la zona: %s ---\n", zona->zonas);

    leerDecimalValidado("Ingrese la temperatura actual (C): ", -20.0, 60.0, &zona->climaActual.temperatura);
    leerDecimalValidado("Ingrese la velocidad del viento (km/h): ", 0.0, 250.0, &zona->climaActual.velocidad);
    leerDecimalValidado("Ingrese la humedad (%): ", 0.0, 100.0, &zona->climaActual.humedad);

    printf("\nIngrese los niveles actuales de contaminantes:\n");
    
    leerDecimalValidado("Nivel de CO2: ", 0.0, 2000.0, &zona->actual.co2);
    leerDecimalValidado("Nivel de SO2: ", 0.0, 1000.0, &zona->actual.so2);
    leerDecimalValidado("Nivel de NO2: ", 0.0, 1000.0, &zona->actual.no2);
    leerDecimalValidado("Nivel de PM2.5: ", 0.0, 1000.0, &zona->actual.pm25);
    
    printf("\nDatos de la zona %s ingresados correctamente.\n", zona->zonas);
}