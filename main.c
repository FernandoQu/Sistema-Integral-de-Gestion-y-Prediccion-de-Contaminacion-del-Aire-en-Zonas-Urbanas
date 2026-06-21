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

    printf("\n=== REGISTRO DE MONITOREO DIARIO ===\n");
    ingresarDatosActuales(&ciudades[0]);

    printf("\nDatos guardados en memoria interna:\n");
    printf("Zona: %s | Temp registrada: %.2f C\n", ciudades[0].zonas, ciudades[0].climaActual.temperatura);

}