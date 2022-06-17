/*
 * utn.h
 *
 *  Created on: 5 jun. 2022
 *      Author: knofl
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef UTN_H_
#define UTN_H_

#endif /* UTN_H_ */

/** \brief pide al usuario que ingrese un caracter, valida que se haya ingresado alguno de los dos pasados por parametro como validos
 *
 * \param  caracter es el puntero al caracter que se ingresara
 * \param  mensaje es el mensaje que vera el usuario
 * \param  mensajeError es el mensaje que vera el usuario en caso de ingresar algun caracter que no sea alguno de los dos pasados por parametro
 *\param caracter1 es uno de los 2 caracteres validos
 *\param caracter2 es el otro caracter valido
 * \return 1 devuelve 1 si no hay error
 */
int getCaracter(char* caracter, char mensaje[], char mensajeError[], char caracter1, char caracter2);

/** \brief pide al usuario el ingreso de un string
 *
 * \param string es el string que sera ingresado por el usuario
 * \param mensaje es el mensaje que vera el usuario
 * \param mensajeError es el mensaje que vera el usuario en caso de ingresar un string que supere el largo permitido
 * \param es el tamaño del string
 * return 1 devuelve 1 si no hay error
 */
int getString(char string[],char mensaje[],char mensajeError[],int tamString);

/** \brief valida el largo de un string
 *
 * \param string es el string que sera ingresado por el usuario
 * \param mensaje es el mensaje que vera el usuario
 * \param mensajeError es el mensaje que vera el usuario en caso de ingresar un string que supere el largo permitido
 * \param es el tamaño del string
 * return 1 devuelve 1 si no hay error
 */
int validateSringLenght(char *string,char mensajeError[],int tamString);

/** \brief valida que se hayan ingresado SOLO caracteres del alfabeto a-z / A-Z
 *
 * \param cadena[] char es la cadena que sera validada
 * \return int devuelve 1 si no hay error
 *
 */
int validateAlphabeticCharacters(char cadena[]);

/** \brief pide el ingreso de una cadena de caracteres solo alfabeticos a-z / A-Z
 *
 * \param string[] char es la cadena que se ingresa
 * \param mensaje[] char es el mensaje que ve el usuario
 * \param mensajeError[] char s el mensaje de error por si ingresa un caracter invalido
 * \param tamString int es el tamaño de la cadena
 * \return int devuelve 1 si no hay error
 *
 */
int getAlphabetic_Characters_String(char string[],char mensaje[],char mensajeError[],int tamString);

/** \brief convierte un string al siguiente formato: Xxxxxxx (primer letra mayuscula y las siguientes minusculas)
 *
 * \param cadena[] char la cadena que sera cambiada de formato
 * \return int devuelve 1 si no hay error
 *
 */
int changeStringFormat(char cadena[]);

/** \brief recibe un char [], el que luego sera validado y convertido a float con atof
 *
 * \param numeroCad[] char es el numero recibido
 * \return int devuelve 1 si no hay error
 *
 */
int validateFloat(char numeroCad[]);

/** \brief solicita el ingreso de un float
 *
 * \param numero float*
 * \param mensaje[] char mensaje que ve el usuario
 * \param mensajeError[] char mensaje de error que ve el usuario si no ingresa un float
 * \return int devuelve 1 si no hay error
 *
 */
int getFloat(float* numero,char mensaje[],char mensajeError[]);

/** \brief recibe un char [], el cual sera evaluado posicion por posicion, y luego sera converrtido con atoi
 *
 * \param numero[] char el numero recibido
 * \return int devuelve 1 si no hay error
 *
 */
int validateInteger(char numero[]);

/** \brief solicita el ingreso de un integer
 *
 * \param numero int* numero que sera ingresado
 * \param mensaje[] char mensaje de instruccion al usuario
 * \param mensajeError[] char mensaje de error si se ha ingresado algo invalido
 * \return int devuelve 1 si no hubo error
 *
 */
int getInt(int* numero,char mensaje[],char mensajeError[]);

char *randstring(size_t length) ;

int getFloat2(float* flotante, char* mensaje, char* mensajeError, float min, float max);

int getInt2(int* numero, char* mensaje, char* mensajeError, int min, int max);
