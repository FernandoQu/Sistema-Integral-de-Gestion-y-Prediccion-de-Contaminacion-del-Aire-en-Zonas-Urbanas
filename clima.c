#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clima.h"

void ingresarDatosActuales(ZonaUrbana *zona) {
    printf("\n--- Ingreso de datos para la zona: %s ---\n", zona->zonas);

    leerDecimalValidado("Ingrese la temperatura actual (-20 a 60, C): ", -20.0, 60.0, &zona->climaActual.temperatura);
    leerDecimalValidado("Ingrese la velocidad del viento (0 a 250, km/h): ", 0.0, 250.0, &zona->climaActual.velocidad);
    leerDecimalValidado("Ingrese la humedad (0% - 100%): ", 0.0, 100.0, &zona->climaActual.humedad);

    printf("\nIngrese los niveles actuales de contaminantes:\n");
    
    leerDecimalValidado("Nivel de CO2 (0 a 2000, ppm): ", 0.0, 2000.0, &zona->actual.co2);
    leerDecimalValidado("Nivel de SO2 (0 a 1000, ug/m3): ", 0.0, 1000.0, &zona->actual.so2);
    leerDecimalValidado("Nivel de NO2 (0 a 1000, ug/m3): ", 0.0, 1000.0, &zona->actual.no2);
    leerDecimalValidado("Nivel de PM2.5 (0 a 1000, ug/m3): ", 0.0, 1000.0, &zona->actual.pm25);
    
    printf("\nDatos de la zona %s ingresados correctamente.\n", zona->zonas);
}

void mostrarEstadoYAlertas(ZonaUrbana *zona) {
    printf("\n--- ESTADO ACTUAL: %s ---\n", zona->zonas);
    printf("CO2: %.2f | SO2: %.2f | NO2: %.2f | PM2.5: %.2f\n", 
           zona->actual.co2, zona->actual.so2, zona->actual.no2, zona->actual.pm25);

    int hayAlerta = 0;

    // Evaluacion de limites de la OMS
    if (zona->actual.co2 > 1000.0) {
        printf("[!] ALERTA: Nivel de CO2 excede el limite de la OMS (1000.0).\n");
        hayAlerta = 1;
    }
    if (zona->actual.so2 > 40.0) {
        printf("[!] ALERTA: Nivel de SO2 excede el limite de la OMS (40.0).\n");
        hayAlerta = 1;
    }
    if (zona->actual.no2 > 25.0) {
        printf("[!] ALERTA: Nivel de NO2 excede el limite de la OMS (25.0).\n");
        hayAlerta = 1;
    }
    if (zona->actual.pm25 > 15.0) {
        printf("[!] ALERTA: Nivel de PM2.5 excede el limite de la OMS (15.0).\n");
        hayAlerta = 1;
    }

    if (!hayAlerta) {
        printf("[+] Todos los niveles se encuentran dentro de los parametros normales.\n");
    }
}