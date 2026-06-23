#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clima.h"

int main() {

    //un arreglo de estructuras ya inicializado en las 5 zonas
    ZonaUrbana ciudades[TOTAL_ZONAS] = {
        {"Zona Norte"},
        {"Zona Sur"},
        {"Zona Noreste"},
        {"Zona Este"},
        {"Zona Oeste"}
    };

    printf("=== SISTEMA DE GESTION AMBIENTAL URBANA ===\n");
    printf("\t\t=== ZONAS ===\n");
    printf("Zona Norte \nZona Sur \nZona Noreste \nZona Este \nZona Oeste\n");

    //se carga los datos historicos de historial_datos.txt
    //como solo se va a cargar y no modificar nada no es necesario el &
    cargarHistorial(ciudades, TOTAL_ZONAS);

    //cont sirve para verificar si se ingreso o no datos en la opcion 1
    int cont = 0;
    int opcion = 0;

    while (opcion != 5) {


        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                printf("\n--- REGISTRO DE MONITOREO DIARIO ---\n");
                //se le pasa el arreglo de ZonaUrbana para que la funcion la rellene
                for (int i = 0; i < TOTAL_ZONAS; i++) {
                    ingresarDatosActuales(&ciudades[i]);
                }
                cont++;
                break;
                
            case 2:
                if (cont > 0) {
                    //mostrarEstadoYAlertas lineas 47 de clima.c
                    printf("\n--- ESTADO ACTUAL Y ALERTAS ---\n");
                    //se le pasa el arreglo de estructuras que ya esta con datos
                    for (int i = 0; i < TOTAL_ZONAS; i++) {
                        //mostrarEstadoYAlertas essta en la linea 47 del clima.c
                        mostrarEstadoYAlertas(&ciudades[i]);
                        //analizarPromediosHistoricos linea 99 de clima.c
                        analizarPromediosHistoricos(&ciudades[i]);
                    }
                } else {
                    printf("\n[!]No se encontro ningun registro actual. Por favor, seleccione la opcion 1 primero.\n");
                }
                break;
                
            case 3:

                break;
                
            case 4:

                break;
                
            case 5:

                break;
        }
    }
    return 0;
}