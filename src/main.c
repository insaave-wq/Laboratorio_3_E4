/*********************************************************************************************************************
Copyright 2016-2026, Ignacio Nicolas Saavedra
Facultad de Ciencias Exactas y Tecnologia
Universidad Nacional de Tucuman
http://www.microprocesadores.unt.edu.ar/

Copyright 2016-2026, Ignacio Nicolas Saavedra <insaave@gmail.com>

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

/** @file main.c
 ** @brief Punto de entrada de la aplicacion
 **/

/* === Headers files inclusions ================================================================ */

#include <stdio.h>
#include "alumno.h"

#define TAMANO_CADENA 200

/**
 * @brief Ejecuta el flujo principal del programa.
 * @return int Retorna 0 cuando la ejecucion finaliza correctamente.
 */

int main(void) {
    int resultado = 0;
    char cadena[TAMANO_CADENA];

    alumno_t alumno1 = AlumnoCrear("Ignacio Nicolas", "Saavedra", 12345678);

    resultado = AlumnoSerializar(alumno1, cadena, sizeof(cadena));

    if (resultado == -1) {
        fprintf(stderr, "No hay suficientes caracteres para serializar los datos del alumno\n");
    } else {
        printf("%s\n", cadena);
    }

    return 0;
}