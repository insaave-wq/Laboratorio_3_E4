/*********************************************************************************************************************
Copyright 2026-2026
Facultad de Ciencias Exactas y Tecnologia
Universidad Nacional de Tucuman
http://www.microprocesadores.unt.edu.ar/

Copyright 2026-2026, Ignacio Nicolas Saavedra <insaave@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file alumno.c
 * @brief Implementación de la estructura alumno y funciones relacionadas.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

/** @brief Se define la estructura para almacenar los datos de un alumno*/
typedef struct alumno_s {
    char nombre[20];
    char apellido[20];
    int dni;
} * alumno_t;

/** @brief Crea una instancia de alumno_t con los datos proporcionados.
 * @param nombre Nombre del alumno.
 * @param apellido Apellido del alumno.
 * @param dni DNI del alumno.
 * @return Retorna la estructura alumno_t inicializada.
 */
const alumno_t AlumnoCrear(char nombre[], char apellido[], int dni) {
    alumno_t alumno = malloc(sizeof(struct alumno_s));
    if (alumno) {
        strncpy(alumno->nombre, nombre, sizeof(alumno->nombre) - 1);
        alumno->nombre[sizeof(alumno->nombre) - 1] = '\0';

        strncpy(alumno->apellido, apellido, sizeof(alumno->apellido) - 1);
        alumno->apellido[sizeof(alumno->apellido) - 1] = '\0';

        alumno->dni = dni;

    } else {
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
int AlumnoSerializar(const alumno_t alumno, char cadena[], int bytes) {
    int resultado = 0;

    snprintf(cadena, 200, "{\n\"Nombre\": \"%s\",\n\"Apellido\": \"%s\",\n\"DNI\": \"%d\"\n}\n", alumno->nombre,
             alumno->apellido, alumno->dni);

    resultado = strlen(cadena);
    if (resultado > bytes) {
        resultado = -1;
    }
    return resultado;
}