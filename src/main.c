/** @file main.c 
 * @brief Función principal del programa que crea una instancia de alumno_t, serializa sus datos en formato JSON y los imprime en la consola.
*/

#include <stdio.h>
#include "alumno.h"

#define TAMANO_CADENA 200

/** @brief Función principal del programa.
 * Crea una instancia de alumno_t, serializa sus datos en formato JSON y los imprime en la consola.
 * @return Retorna 0 si el programa se ejecuta correctamente.
 */

int main(void)
{
    int resultado = 0;
    char cadena[TAMANO_CADENA];

    alumno_t alumno1 = AlumnoCrear("Ignacio Nicolas", "Saavedra", 12345678);

    resultado = AlumnoSerializar(alumno1, cadena, sizeof(cadena));

    if (resultado == -1)
    {
        fprintf(stderr, "No hay suficientes caracteres para serializar los datos del alumno\n");
    }
    else
    {
        printf("%s\n", cadena);
    }

    return 0;
}