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
    int c;

    do {
        printf("%s", mensaje);
        
        int valoresLeidos = scanf("%d", &temporal);

        while ((c = getchar()) != '\n' && c != EOF);

        if (valoresLeidos == 1 && validarEntero(temporal, min, max)) {
            esValido = 1;
            *resultado = temporal;
        } else {
            printf("Dato fuera de rango o invalido, intente de nuevo\n");
        }
    } while (esValido == 0);
}


void leerDecimalValidado(char mensaje[], float min, float max, float *resultado) {
    float temporal = 0.0;
    int esValido = 0;
    int c;

    do {
        printf("%s\n", mensaje);
        int valoresLeidos = scanf("%f", &temporal);
        
        while ((c = getchar()) != '\n' && c != EOF);

        if (valoresLeidos == 1 && validarDecimal(temporal, min, max)) {
            esValido = 1;
            *resultado = temporal; 
        } else {
            printf("Dato fuera de rango o invalido, intente de nuevo\n");
        }
    } while (esValido == 0);
}
