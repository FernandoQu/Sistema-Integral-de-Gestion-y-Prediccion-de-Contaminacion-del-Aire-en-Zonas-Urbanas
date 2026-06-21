#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clima.h"

int main(){

    // se inicia un arreglo de estructuras
    ZonaUrbana ciudades[TOTAL_ZONAS] = {0};

    printf("=== SISTEMA DE GESTION AMBIENTAL URBANA ===\n");

    //se llama a la funcion para colocar el nombre de las zonas linea 7 de clima.c
    configurarNombresZonas(ciudades, TOTAL_ZONAS);
    int cont = 0;
    int opcion = 0;

    while (opcion != 4) {
        printf("\n======================================================\n");
        printf("\t\tMENU PRINCIPAL\n");
        printf("======================================================\n");
        printf("1. Ingresar monitoreo actual\n");
        printf("2. Mostrar estado actual y alertas preventivas\n");
        printf("3. Generar prediccion a 24 horas\n");
        printf("4.\n");
 
        leerEnteroValidado("Seleccione una opcion (1-4): ", 1, 4, &opcion);

        switch (opcion) {
            case 1:
                printf("\n--- REGISTRO DE MONITOREO DIARIO ---\n");
                for (int i = 0; i < TOTAL_ZONAS; i++) {
                    ingresarDatosActuales(&ciudades[i]);
                    cont ++;
                }
                break;
                
            case 2:
            if (cont > 0)
            {
                printf("\n--- ESTADO ACTUAL Y ALERTAS ---\n");
            } else
            {
                printf("No se encontro ningun registro\n");
            }
                break;
                
            case 3:
            if (cont > 0)
            {
                printf("\n--- PREDICCION A 24 HORAS ---\n");
            } else
            {
                printf("No se encontro ningun registro\n");
            }
            
                break;
                
            case 4:

                break;

            case 5:

                break;
        }
    }

}