#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clima.h"

//esto es solo un menu para elegir la opcion 
int mostrarMenu(){
    int opcion = 0;
    printf("\n======================================================\n");
    printf("\t\tMENU PRINCIPAL\n");
    printf("======================================================\n");
    printf("1. Ingresar monitoreo actual\n");
    printf("2. Mostrar estado actual y alertas preventivas\n");
    printf("3. Generar prediccion a 24 horas\n");
    printf("4. Exportar reporte\n");
    printf("5. Guardar historial del dia y salir\n");
    leerEnteroValidado("Seleccione una opcion (1-5): ", 1, 5, &opcion);
    return opcion;

}

//Es el ingreso de datos tanto de contaminacion como de las condiciones climaticas
void ingresarDatosActuales(ZonaUrbana *zona) {
    //Recibe la estructura en esa posicion 
    //al ser un puntero cambia sus valores
    printf("\n--- Ingreso de datos para la zona: %s ---\n", zona->zonas);

    //se llama a la funcion de leerDecimalValido 
    //la validacion recibe los datos actuales y los midifica con lo que ingresa el usuario
    //linea 51 de validaciones.c
    leerDecimalValidado("Ingrese la temperatura actual (-20 a 60, C): ", -20.0, 60.0, &zona->climaActual.temperatura);
    leerDecimalValidado("Ingrese la velocidad del viento (0 a 250, km/h): ", 0.0, 250.0, &zona->climaActual.velocidad);
    leerDecimalValidado("Ingrese la humedad (0% - 100%): ", 0.0, 100.0, &zona->climaActual.humedad);

    printf("\nIngrese los niveles actuales de contaminantes:\n");
    
    leerDecimalValidado("Nivel de CO2 (0 a 2000, ppm): ", 0.0, 2000.0, &zona->actual.co2);
    leerDecimalValidado("Nivel de SO2 (0 a 1000, ug/m3): ", 0.0, 1000.0, &zona->actual.so2);
    leerDecimalValidado("Nivel de NO2 (0 a 1000, ug/m3): ", 0.0, 1000.0, &zona->actual.no2);
    leerDecimalValidado("Nivel de PM2.5 (0 a 1000, ug/m3): ", 0.0, 1000.0, &zona->actual.pm25);
    
    printf("\nDatos de la zona %s ingresados correctamente.\n", zona->zonas);
}

//funcion para mostrar el estado y las alertas 
void mostrarEstadoYAlertas(ZonaUrbana *zona) {
    // *zona recibe la estructura en esa posicion con los datos ya rellenados
    //solo muestra los datos de esa estructura
    printf("\n--- ESTADO ACTUAL: %s ---\n", zona->zonas);
    printf("CO2: %.2f | SO2: %.2f | NO2: %.2f | PM2.5: %.2f\n", zona->actual.co2, zona->actual.so2, zona->actual.no2, zona->actual.pm25);

    //una variable sentinela pare verificar si hay o no alternas en esa zona
    int hayAlerta = 0;

    // Evaluacion de limites de la OMS
    //solo se evalua los limites ingresados con los limites y dice las alertas
    if (zona->actual.co2 > 1000.0) {
        printf("[!] ALERTA: Nivel de CO2 excede el limite de la OMS (1000.0).\n");
        hayAlerta = 1;
    }
    if (zona->actual.so2 > 40.0) {
        printf("[!] ALERTA: Nivel de SO2 excede el limite de la OMS (40.0).\n");
        hayAlerta = 1;
    }
    if (zona->actual.no2 > 25.0) {
        printf("[!] ALERTA: Nivel de NO2 excede el limite de la OMS (25.0).\n");
        hayAlerta = 1;
    }
    if (zona->actual.pm25 > 15.0) {
        printf("[!] ALERTA: Nivel de PM2.5 excede el limite de la OMS (15.0).\n");
        hayAlerta = 1;
    }
    if (hayAlerta == 0) {
        printf("[+] Todos los niveles se encuentran dentro de los parametros normales.\n");
    }
    //como en el main.c se le pasa la estructura en esa posicion va a poner las alertas de las 5 zonas
}

//Se carga el historial de datos de historial_datos.txt
void cargarHistorial(ZonaUrbana ciudades[], int totalZonas) {
    //se abre el archivo en modo lectura para copiarlos en el historial
    //linea 34 de clima.h
    FILE *archivo = fopen("historial_datos.txt", "r");
    
    //un blucle para cargar el historial de los ultimos 30 por cada ciudad
    for (int i = 0; i < totalZonas; i++) {
        for (int j = 0; j < 30; j++) {
            //lee linea por linea los datos del archivo historial_datos.txt
            fscanf(archivo, "%f %f %f %f", 
                &ciudades[i].historial[j].co2, &ciudades[i].historial[j].so2, 
                &ciudades[i].historial[j].no2, &ciudades[i].historial[j].pm25);
        }
    }
    fclose(archivo);
    printf("\n[+]Historial cargado exitosamente.\n");
}

void analizarPromediosHistoricos(ZonaUrbana *zona) {
    float sumaCO2 = 0, sumaSO2 = 0, sumaNO2 = 0, sumaPM25 = 0;

    // Sumar los 30 dias almacenados en el historial
    // linea 34 clima.h
    for (int i = 0; i < 30; i++) {
        sumaCO2 += zona->historial[i].co2;
        sumaSO2 += zona->historial[i].so2;
        sumaNO2 += zona->historial[i].no2;
        sumaPM25 += zona->historial[i].pm25;
    }

    // Calcular el promedio mensual
    float promCO2 = sumaCO2 / 30.0;
    float promSO2 = sumaSO2 / 30.0;
    float promNO2 = sumaNO2 / 30.0;
    float promPM25 = sumaPM25 / 30.0;

    printf("\n--- PROMEDIO HISTORICO (30 DIAS): %s ---\n", zona->zonas);
    printf("Promedios -> CO2: %.2f | SO2: %.2f | NO2: %.2f | PM2.5: %.2f\n", promCO2, promSO2, promNO2, promPM25);

    // Comparar promedios historicos con limites de la OMS
    if (promCO2 > 1000.0 || promSO2 > 40.0 || promNO2 > 25.0 || promPM25 > 15.0) {
        printf("[!] ADVERTENCIA HISTORICA: La zona supera sistematicamente los limites de la OMS a largo plazo.\n");
    } else {
        printf("[+] El historial indica niveles saludables promedio durante el ultimo mes.\n");
    }
    //como en el main.c se le pasa la estructura en esa posicion va a poner las alertas de las 5 zonas
}

void generarPrediccion(ZonaUrbana *zona) {
    // Algoritmo de prediccion: Promedio ponderado de los ultimos 3 dias del historial
    // Se le da más peso a los días más recientes: Ayer (50%), Anteayer (30%), Hace 3 dias (20%)
    
    zona->prediccion.co2 = (zona->actual.co2 * 0.5) + (zona->historial[28].co2 * 0.3) + (zona->historial[27].co2 * 0.2);
    zona->prediccion.so2 = (zona->actual.so2 * 0.5) + (zona->historial[28].so2 * 0.3) + (zona->historial[27].so2 * 0.2);
    zona->prediccion.no2 = (zona->actual.no2 * 0.5) + (zona->historial[28].no2 * 0.3) + (zona->historial[27].no2 * 0.2);
    zona->prediccion.pm25 = (zona->actual.pm25 * 0.5) + (zona->historial[28].pm25 * 0.3) + (zona->historial[27].pm25 * 0.2);

    // Influencia de los factores climaticos actuales sobre la base historica
    // Si la velocidad del viento es menor a 10 km/h, la contaminacion aumenta un 15%
    if (zona->climaActual.velocidad < 10.0) {
        zona->prediccion.co2 *= 1.15;
        zona->prediccion.so2 *= 1.15;
        zona->prediccion.no2 *= 1.15;
        zona->prediccion.pm25 *= 1.15;
    }

    // La alta humedad (> 80%) atrapa las particulas finas, aumentando PM2.5 en un 10%
    if (zona->climaActual.humedad > 80.0) {
        zona->prediccion.pm25 *= 1.10;
    }

    printf("\n--- PREDICCION A 24H: %s ---\n", zona->zonas);
    printf("CO2 esperado: %.2f | SO2 esperado: %.2f\n", zona->prediccion.co2, zona->prediccion.so2);
    printf("NO2 esperado: %.2f | PM2.5 esperado: %.2f\n", zona->prediccion.no2, zona->prediccion.pm25);
    printf("-> Base: Algoritmo historico ponderado + Clima actual (Viento: %.1f km/h | Humedad: %.1f%%)\n", 
           zona->climaActual.velocidad, zona->climaActual.humedad);

    // Emision de alertas y recomendaciones preventivas
    if (zona->prediccion.pm25 > 15.0 || zona->prediccion.co2 > 1000.0) {
        printf(">> [!] ALERTA PREVENTIVA: Se preve que se superaran los limites permitidos manana.\n");
        printf(">> [!] RECOMENDACION: Aplicar reduccion del trafico vehicular y suspension de actividades al aire libre.\n");
    }
}

//sirve para exportar el reporte 
void exportarReporte(ZonaUrbana ciudades[], int totalZonas) {
    //se abre el archivo en modo escritura
    FILE *archivo = fopen("reporte_analisis.txt", "w");
    
    //comprobacion para ver si el archivo existe
    if (archivo == NULL) {
        printf("[+] Error al crear el archivo de reporte.\n");
        return;
    }

    fprintf(archivo, "======================================================\n");
    fprintf(archivo, "\tREPORTE DE CALIDAD DEL AIRE Y PREDICCIONES     \n");
    fprintf(archivo, "======================================================\n\n");

    //esta parte es por si no se ejecuto la opcion 3 antes
    // si se ejecuto la opcion 3 antes no pasa nada
    // para colocar los datos de prediccion en los datos guardados
    for (int i = 0; i < totalZonas; i++) {

        ciudades[i].prediccion.co2 = (ciudades[i].actual.co2 * 0.5) + (ciudades[i].historial[28].co2 * 0.3) + (ciudades[i].historial[27].co2 * 0.2);
        ciudades[i].prediccion.so2 = (ciudades[i].actual.so2 * 0.5) + (ciudades[i].historial[28].so2 * 0.3) + (ciudades[i].historial[27].so2 * 0.2);
        ciudades[i].prediccion.no2 = (ciudades[i].actual.no2 * 0.5) + (ciudades[i].historial[28].no2 * 0.3) + (ciudades[i].historial[27].no2 * 0.2);
        ciudades[i].prediccion.pm25 = (ciudades[i].actual.pm25 * 0.5) + (ciudades[i].historial[28].pm25 * 0.3) + (ciudades[i].historial[27].pm25 * 0.2);

        if (ciudades[i].climaActual.velocidad < 10.0) {
            ciudades[i].prediccion.co2 *= 1.15;
            ciudades[i].prediccion.so2 *= 1.15;
            ciudades[i].prediccion.no2 *= 1.15;
            ciudades[i].prediccion.pm25 *= 1.15;
        }

        if (ciudades[i].climaActual.humedad > 80.0) {
            ciudades[i].prediccion.pm25 *= 1.10;
        }
    }    

    //se coloca los datos de todas las zonas en el archivo
    for (int i = 0; i < totalZonas; i++) {
        fprintf(archivo, "--- ZONA: %s ---\n", ciudades[i].zonas);
        fprintf(archivo, "Niveles Actuales: CO2: %.2f | SO2: %.2f | NO2: %.2f | PM2.5: %.2f\n", 
                ciudades[i].actual.co2, ciudades[i].actual.so2, 
                ciudades[i].actual.no2, ciudades[i].actual.pm25);
                
        fprintf(archivo, "Prediccion 24H  : CO2: %.2f | SO2: %.2f | NO2: %.2f | PM2.5: %.2f\n", 
                ciudades[i].prediccion.co2, ciudades[i].prediccion.so2, 
                ciudades[i].prediccion.no2, ciudades[i].prediccion.pm25);
        
        if (ciudades[i].prediccion.pm25 > 15.0 || ciudades[i].prediccion.co2 > 1000.0) {
            fprintf(archivo, ">> ESTADO: ALERTA PREVENTIVA\n");
            fprintf(archivo, ">> RECOMENDACION: Aplicar restriccion vehicular (Pico y Placa) y limitar actividades industriales.\n\n");
        } else {
            fprintf(archivo, ">> ESTADO: NORMAL\n");
            fprintf(archivo, ">> RECOMENDACION: Ninguna medida de mitigacion adicional requerida.\n\n");
        }
    }

    // se cierra el archivo
    fclose(archivo);
    printf("\n[+] El reporte se ha exportado exitosamente al archivo 'reporte_analisis.txt'\n");
}

//se lo usa para la opcio 5
//guarga y actualiza el historial eliminando los datos mas antiguos y reemplazandolos por los nuevos
void actualizarYGuardarHistorial(ZonaUrbana ciudades[], int totalZonas) {
    for (int i = 0; i < totalZonas; i++) {
        
        for (int j = 0; j < 29; j++) {
            ciudades[i].historial[j] = ciudades[i].historial[j + 1];
        }
        
        ciudades[i].historial[29] = ciudades[i].actual;
    }

    FILE *archivo = fopen("historial_datos.txt", "w");
    if (archivo != NULL) {
        for (int i = 0; i < totalZonas; i++) {
            for (int j = 0; j < 30; j++) {
                fprintf(archivo, "%.2f %.2f %.2f %.2f\n", 
                        ciudades[i].historial[j].co2, ciudades[i].historial[j].so2, 
                        ciudades[i].historial[j].no2, ciudades[i].historial[j].pm25);
            }
        }
        fclose(archivo);
        printf("[v] Historial TXT actualizado correctamente para la proxima ejecucion.\n");
    } else {
        printf("[+] Error al actualizar el archivo de historial.\n");
    }
}