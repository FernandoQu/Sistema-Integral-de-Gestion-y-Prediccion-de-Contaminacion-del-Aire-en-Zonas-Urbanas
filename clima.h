#ifndef CLIMA_H
#define CLIMA_H

typedef struct 
{
    float temperatura;
    float velocidad;

} FactoresClimaticos;

typedef struct
{
    
    float co2;
    float so2;
    float no2;
    float pm25;

} Contaminantes;

typedef struct
{
    char zonas[50];

    Contaminantes actual;
    Contaminantes historial[30];
    Contaminantes prediccion;   
    
    FactoresClimaticos climaActual;
} ZonaUrbana;



#endif