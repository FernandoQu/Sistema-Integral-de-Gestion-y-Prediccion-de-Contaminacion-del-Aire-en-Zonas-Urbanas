#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clima.h"

int main() {

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

    cargarHistorial(ciudades, TOTAL_ZONAS);

    int cont = 0;
    int opcion = 0;

    while (opcion != 5) {


        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                printf("\n--- REGISTRO DE MONITOREO DIARIO ---\n");
                for (int i = 0; i < TOTAL_ZONAS; i++) {
                    ingresarDatosActuales(&ciudades[i]);
                }
                cont++;
                break;
                
            case 2:

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