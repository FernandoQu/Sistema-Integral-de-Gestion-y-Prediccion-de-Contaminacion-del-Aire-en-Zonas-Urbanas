#ifndef VALIDACIONES_H
#define VALIDACIONES_H

int validarEntero(int valor, int min, int max);
int validarDecimal(float valor, float min, float max);
int validarLongitudMaxima(char cadena[], int limiteMaximo);
int validarSoloLetras(char cadena[]);

int validarOpcionSN(char opcion);
int validarLongitudExacta(char cadena[], int longitudEsperada);

void leerEnteroValidado(char mensaje[], int min, int max, int *resultado);
void leerDecimalValidado(char mensaje[], float min, float max, float *resultado);

void leerOpcionSN(char mensaje[], char *resultado);

#endif