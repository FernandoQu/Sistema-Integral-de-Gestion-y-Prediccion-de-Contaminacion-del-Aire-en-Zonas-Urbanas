#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clima.h"

void configurarNombresZonas(ZonaUrbana ciudades[], int totalZonas) {
    for (int i = 0; i < totalZonas; i++) {
        int esValido = 0;
        
        do {
            printf("Ingrese el nombre para la zona %d (Solo letras, max 49 caracteres): ", i + 1);
            
            fgets(ciudades[i].zonas, sizeof(ciudades[i].zonas), stdin);

            int longitud = 0;
            while (ciudades[i].zonas[longitud] != '\0') {
                if (ciudades[i].zonas[longitud] == '\n') {
                    ciudades[i].zonas[longitud] = '\0';
                    break;
                }
                longitud++;
            }

            if (validarSoloLetras(ciudades[i].zonas) && 
                validarLongitudMaxima(ciudades[i].zonas, 49) && 
                longitud > 0) {
                esValido = 1;
            } else {
                printf("Nombre invalido. Recuerde usar solo letras y no dejar el campo vacio.\n");
            }
        } while (!esValido);
    }
    printf("\n[!] Las %d zonas han sido nombradas y configuradas correctamente.\n", totalZonas);
}

void ingresarDatosActuales(ZonaUrbana *zona) {
    printf("\n--- Ingreso de datos para la zona: %s ---\n", zona->zonas);

    //Se usa la validacion de leer decimal valido linea 88 de validaciones.c
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