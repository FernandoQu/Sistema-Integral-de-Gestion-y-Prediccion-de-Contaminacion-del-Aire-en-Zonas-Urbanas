#ifndef VALIDACIONES_H
#define VALIDACIONES_H

int validarEntero(int valor, int min, int max);
int validarDecimal(float valor, float min, float max);

void leerEnteroValidado(char mensaje[], int min, int max, int *resultado);
void leerDecimalValidado(char mensaje[], float min, float max, float *resultado);



#endif