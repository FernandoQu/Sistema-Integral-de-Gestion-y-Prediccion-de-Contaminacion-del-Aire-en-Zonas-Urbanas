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

int validarLongitudMaxima(char cadena[], int limiteMaximo) {
    int contador = 0;

    while (cadena[contador] != '\0' && cadena[contador] != '\n') {
        contador++;
    }

    if (contador > limiteMaximo) {
        return 0; 
    }
    return 1; 
}

int validarSoloLetras(char cadena[]) {
    if (cadena[0] == '\0') {
        return 0;
    }
    for (int i = 0; cadena[i] != '\0'; i++) {
        char c = cadena[i];
        int esMayuscula = (c >= 'A' && c <= 'Z');
        int esMinuscula = (c >= 'a' && c <= 'z');
        int esEspacio = (c == ' ');

        if (!esMayuscula && !esMinuscula && !esEspacio && c != '\n') {
            return 0;
        }
    }
    return 1;
}

int validarOpcionSN(char opcion) {
    if (opcion == 'S' || opcion == 's' || opcion == 'N' || opcion == 'n') {
        return 1;
    }
    return 0;
}

int validarLongitudExacta(char cadena[], int longitudEsperada) {
    int contador = 0;
    
    while (cadena[contador] != '\0' && cadena[contador] != '\n') {
        contador++;
    }
    if (contador == longitudEsperada) {
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

void leerOpcionSN(char mensaje[], char *resultado) {
    char temporal;
    int esValido = 0;
    int c;

    do {
        printf("%s", mensaje);
        int valoresLeidos = scanf("%c", &temporal);
        
        while ((c = getchar()) != '\n' && c != EOF);

        if (valoresLeidos == 1 && validarOpcionSN(temporal)) {
            esValido = 1;
            *resultado = temporal;
        } else {
            printf("Ingrese solo S o N, intente de nuevo\n");
        }
    } while (esValido == 0);
}