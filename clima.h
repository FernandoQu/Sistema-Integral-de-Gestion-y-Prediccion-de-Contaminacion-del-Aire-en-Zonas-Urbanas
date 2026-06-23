#ifndef CLIMA_H
#define CLIMA_H
#define TOTAL_ZONAS 5

typedef struct 
{
    float temperatura;
    float velocidad;
    float humedad;

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

    //se usa la anterior estructura para usarlo para cada zona actual
    //tambien para el historial y para usar las predicciones
    Contaminantes actual;
    Contaminantes historial[30];
    Contaminantes prediccion;   
    
    //se usa otra estructura para usarlo en el clima actual por cada zona
    FactoresClimaticos climaActual;
} ZonaUrbana;

int mostrarMenu();
void ingresarDatosActuales(ZonaUrbana *zona);
void mostrarEstadoYAlertas(ZonaUrbana *zona);

#endif