/** @file alumno.h
 * @brief Declaración de la estructura alumno y funciones relacionadas.
 */

#ifndef ALUMNO_H
#define ALUMNO_H

/** @brief Se define la estructura para almacenar los datos de un alumno*/
typedef struct alumno_s *alumno_t;


/** @brief Crea una instancia de alumno_t con los datos proporcionados.
 * @param nombre Nombre del alumno.
 * @param apellido Apellido del alumno.
 * @param dni DNI del alumno.
 * @return Retorna la estructura alumno_t inicializada.
 */
const alumno_t AlumnoCrear(char nombre[], char apellido[], int dni);

/** @brief Serializa los datos de un alumno en formato JSON.
 * @param alumno Estructura alumno_t que contiene los datos del alumno a serializar.
 * @param cadena Cadena de caracteres donde se almacenará el resultado de la serialización.
 * @param bytes Tamaño máximo de la cadena de caracteres.
 * @return Retorna el número de caracteres escritos en la cadena, o -1 si el resultado excede el límite de bytes.
 */
int AlumnoSerializar(const alumno_t alumno, char cadena[], int bytes);

#endif