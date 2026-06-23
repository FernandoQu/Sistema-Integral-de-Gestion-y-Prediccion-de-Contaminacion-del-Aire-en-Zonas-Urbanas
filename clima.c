#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clima.h"

//esto es solo un menu para elegir la opcion 
int mostrarMenu(){
    int opcion = 0;
    printf("\n======================================================\n");
    printf("\t\tMENU PRINCIPAL\n");
    printf("======================================================\n");
    printf("1. Ingresar monitoreo actual\n");
    printf("2. Mostrar estado actual y alertas preventivas\n");
    printf("3. Generar prediccion a 24 horas\n");
    printf("4. Exportar reporte\n");
    printf("5. Guardar historial del dia y salir\n");
    leerEnteroValidado("Seleccione una opcion (1-5): ", 1, 5, &opcion);
    return opcion;

}

//Es el ingreso de datos tanto de contaminacion como de las condiciones climaticas
void ingresarDatosActuales(ZonaUrbana *zona) {
    //Recibe la estructura en esa posicion 
    //al ser un puntero cambia sus valores
    printf("\n--- Ingreso de datos para la zona: %s ---\n", zona->zonas);

    //se llama a la funcion de leerDecimalValido 
    //la validacion recibe los datos actuales y los midifica con lo que ingresa el usuario
    //linea 51 de validaciones.c
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

//funcion para mostrar el estado y las alertas 
void mostrarEstadoYAlertas(ZonaUrbana *zona) {
    // *zona recibe la estructura en esa posicion con los datos ya rellenados
    //solo muestra los datos de esa estructura
    printf("\n--- ESTADO ACTUAL: %s ---\n", zona->zonas);
    printf("CO2: %.2f | SO2: %.2f | NO2: %.2f | PM2.5: %.2f\n", zona->actual.co2, zona->actual.so2, zona->actual.no2, zona->actual.pm25);

    //una variable sentinela pare verificar si hay o no alternas en esa zona
    int hayAlerta = 0;

    // Evaluacion de limites de la OMS
    //solo se evalua los limites ingresados con los limites y dice las alertas
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
    if (hayAlerta == 0) {
        printf("[+] Todos los niveles se encuentran dentro de los parametros normales.\n");
    }
    //como en el main.c se le pasa la estructura en esa posicion va a poner las alertas de las 5 zonas
}