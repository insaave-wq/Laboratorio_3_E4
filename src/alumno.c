/** @brief Implementación de la función Serializar.
 * @file alumno.c
 */

#ifndef ALUMNO_C
#define ALUMNO_C

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

/** @brief Se define la estructura para almacenar los datos de un alumno*/
typedef struct alumno_s
{
    char nombre[20];
    char apellido[20];
    int dni;
} *alumno_t;

/** @brief Crea una instancia de alumno_t con los datos proporcionados.
 * @param nombre Nombre del alumno.
 * @param apellido Apellido del alumno.
 * @param dni DNI del alumno.
 * @return Retorna la estructura alumno_t inicializada.
 */
const alumno_t AlumnoCrear(char nombre[], char apellido[], int dni)
{
    alumno_t alumno = malloc(sizeof(struct alumno_s));
    if (alumno)
    {
        strncpy(alumno->nombre, nombre, sizeof(alumno->nombre) - 1);
        alumno->nombre[sizeof(alumno->nombre) - 1] = '\0';
        
        strncpy(alumno->apellido, apellido, sizeof(alumno->apellido) - 1);
        alumno->apellido[sizeof(alumno->apellido) - 1] = '\0';
        
        alumno->dni = dni;
    }
    else
    {
        return NULL;
    }
    return alumno;
}

/** @brief Serializa los datos de un alumno en formato JSON.
 * @param alumno Estructura alumno_t que contiene los datos del alumno a serializar.
 * @param cadena Cadena de caracteres donde se almacenará el resultado de la serialización.
 * @param bytes Tamaño máximo de la cadena de caracteres.
 * @return Retorna el número de caracteres escritos en la cadena, o -1 si el resultado excede el límite de bytes.
 */
int AlumnoSerializar(const alumno_t alumno, char cadena[], int bytes)
{
    int resultado = 0;

    snprintf(cadena, 200, "{\n\"Nombre\": \"%s\",\n\"Apellido\": \"%s\",\n\"DNI\": \"%d\"\n}\n", alumno->nombre, alumno->apellido, alumno->dni);

    resultado = strlen(cadena);
    if (resultado > bytes)
    {
        resultado = -1;
    }
    return resultado;
}
#endif