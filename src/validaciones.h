/*
 * validaciones.h
 *
 *  Created on: 5 jun. 2022
 *      Author: knofl
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */

/** \brief valida el codigo de vuelo
 *
 * \param flyCode[] char
 * \return int devuelve 1 si no hubo error
 *
 */
int validateFlightCode(char flyCode[]);

/** \brief cambia el formato de un string a: XXXXXXXX (todo mayus)
 *
 * \param cadena[] char
 * \return int devuelve 1 si no hubo error
 *
 */
int toupperString(char cadena[]);

/** \brief valida que se ingrese un tipo de pasajero valido -1/0/1
 *
 * \param num int el tipo de pasajero ingresado
 * \return int devuelve 1 si no hubo error
 *
 */
int validateTypePassenger(int num);

/** \brief valida que se ingrese un estado de vuelo correcto, 0/1
 *
 * \param num int
 * \return int devuelve 1 si no hubo error
 *
 */
int validateFlightStatus(int num);

/** \brief valida que se ingrese solo caracteres alfabeticos a-z / A-Z
 *
 * \param nombre[] char
 * \return int devuelve 1 si no se ingreso un caracter fuera de rango
 *
 */
int validateNameOrLastName(char nombre[]);

/** \brief cambia el formado del nombre o apellido a: Xxxxxx
 *
 * \param char*nombre
 * \return int devuelve 1 si no hubo error en la funcion
 *
 */
int correctCharactersNameOrLastName(char*nombre);



