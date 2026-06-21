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
            
            //se lee los nombres de las zonas que el usuario ingresa 
            fgets(ciudades[i].zonas, 50, stdin);

            //al usar el fgets se debe eliminar el enter (\n) porque el fgets lo lee tambien
            //tambien se crea una variable para comprobar que no se dejo el campo vacio
            int longitud = 0;
            while (ciudades[i].zonas[longitud] != '\0') {
                if (ciudades[i].zonas[longitud] == '\n') {
                    ciudades[i].zonas[longitud] = '\0';
                    break;
                }
                longitud++;
            }

            //se comprueba que solo se ingrese letras y se comprueba la longitud 
            //tambien se comprueba si la longitud es > 0 para comprobar que se ingreso algo
            //validarSoloLetras esta en la linea 30 de validaciones.h
            //validarLongitudMaxima esta en la linea 17 de validaciones.h
            if (validarSoloLetras(ciudades[i].zonas) && 
                validarLongitudMaxima(ciudades[i].zonas, 49) && 
                longitud > 0) {
                esValido = 1;
            } else {
                printf("Nombre invalido. Solo se puede usar solo letras y no dejar el campo vacio.\n");
            }
        } while (!esValido);
    }
    printf("\nLas %d zonas han sido nombradas y configuradas correctamente.\n", totalZonas);
}

void ingresarDatosActuales(ZonaUrbana *zona) {
    printf("\n--- Ingreso de datos para la zona: %s ---\n", zona->zonas);

    //Se usa la validacion de leer decimal valido --linea 88 de validaciones.c
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

void mostrarEstadoYAlertas(ZonaUrbana *zona) {
    printf("\n--- ESTADO ACTUAL: %s ---\n", zona->zonas);
    printf("CO2: %.2f | SO2: %.2f | NO2: %.2f | PM2.5: %.2f\n",zona->actual.co2, zona->actual.so2, zona->actual.no2, zona->actual.pm25);

    int hayAlerta = 0;

    if (zona->actual.co2 > 1000.0) {
        printf("ALERTA: Nivel de CO2 excede el limite de la OMS (1000.0).\n");
        hayAlerta = 1;
    }
    if (zona->actual.so2 > 20.0) {
        printf("ALERTA: Nivel de SO2 excede el limite de la OMS (20.0).\n");
        hayAlerta = 1;
    }
    if (zona->actual.no2 > 40.0) {
        printf("ALERTA: Nivel de NO2 excede el limite de la OMS (40.0).\n");
        hayAlerta = 1;
    }
    if (zona->actual.pm25 > 15.0) {
        printf("ALERTA: Nivel de PM2.5 excede el limite de la OMS (15.0).\n");
        hayAlerta = 1;
    }

    if (!hayAlerta) {
        printf("Todos los niveles se encuentran dentro de los parametros normales.\n");
    }
}