#include <stdio.h>

int validarEntero(int valor, int min, int max) {
    if (valor >= min && valor <= max) {
        return 1;
    }
    return 0;
}

int validarDecimal(float valor, float min, float max) {
    if (valor >= min && valor <= max) {
        return 1;
    }
    return 0;
}

void leerEnteroValidado(char mensaje[], int min, int max, int *resultado) {
    int temporal = 0;
    int esValido = 0;
    char c;

    do {
        printf("%s", mensaje);

        if (scanf("%d", &temporal) == 1) {

            c = getchar();

            if (c == '\n') {
                if (validarEntero(temporal, min, max)) {
                    esValido = 1;
                    *resultado = temporal;
                } else {
                    printf("[!] Dato fuera de rango (%d a %d). Intente de nuevo.\n", min, max);
                }
            } else {

                printf("[!] Error: Ingreso caracteres no validos junto al numero.\n");
                while (c != '\n' && c != EOF) {
                    c = getchar();
                }
            }
        } else {

            printf("[!] Error: Debe ingresar un valor numerico.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (esValido == 0);
}

void leerDecimalValidado(char mensaje[], float min, float max, float *resultado) {
    float temporal = 0.0;
    int esValido = 0;
    char c;

    do {
        printf("%s", mensaje);
        
        if (scanf("%f", &temporal) == 1) {
            
            c = getchar();
            
            if (c == '\n') {
                if (validarDecimal(temporal, min, max)) {
                    esValido = 1;
                    *resultado = temporal; 
                } else {
                    printf("[!] Dato fuera de rango (%.1f a %.1f). Intente de nuevo.\n", min, max);
                }
            } else {
                printf("[!] Error: Ingreso caracteres no validos junto al decimal.\n");
                while (c != '\n' && c != EOF) {
                    c = getchar();
                }
            }
        } else {
            printf("[!] Error: Debe ingresar un valor numerico.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (esValido == 0);
}