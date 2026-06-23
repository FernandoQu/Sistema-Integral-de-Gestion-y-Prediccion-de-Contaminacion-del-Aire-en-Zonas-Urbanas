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

//La estructura engloba las otras dos primeras
typedef struct
{
    char zonas[50];

    //se usa la anterior estructura para usarlo para cada zona actual
    //tambien para el historial y para usar las predicciones
    Contaminantes actual;
    //guarda los datos del contaminate actual

    //esto es un arreglo de estructuras de los contaminantes para los 30 dias
    Contaminantes historial[30];
    Contaminantes prediccion;   
    
    //se usa otra estructura para usarlo en el clima actual por cada zona
    FactoresClimaticos climaActual;
} ZonaUrbana;

int mostrarMenu();

void ingresarDatosActuales(ZonaUrbana *zona);
void mostrarEstadoYAlertas(ZonaUrbana *zona);
void generarPrediccion(ZonaUrbana *zona);
void analizarPromediosHistoricos(ZonaUrbana *zona);
void cargarHistorial(ZonaUrbana ciudades[], int totalZonas);
void actualizarYGuardarHistorial(ZonaUrbana ciudades[], int totalZonas);
void exportarReporte(ZonaUrbana ciudades[], int totalZonas);

#endif