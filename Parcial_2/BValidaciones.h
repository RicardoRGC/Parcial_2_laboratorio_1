/*
 * BValidaciones.h
 *
 *  Created on: 12 oct. 2021
 *      Author: riky
 */

#ifndef BVALIDACIONES_H_
#define BVALIDACIONES_H_
/// @param nombre char a validar
/// valida un char que sea numerico
/// @return falla la funcion -1 0 si es correcto.
int validarCadenaNumerica(char nombre[]);
/// @param cadena valida una cadena con minimo max
/// @param longitud
/// @param longMin
/// @return falla la funcion -1 0 si es correcto.
int myGetMinMax(char* cadena, int longitud,int longMin);
/// @param nombre valida una cadena q tega espacios
/// @return falla la funcion -1 0 si es correcto.
int validarCadenaConEspacios(char nombre[]);
/// @param numero valida q el numero tenga 11 caracteres
/// @param tam
/// @return falla la funcion -1 0 si es correcto.
int ValidarCuit(char numero[], int tam);
/// @param nombre valida si solo son letras
/// @return retorna 1 si son letras, 0 si es incorrecto.
int validarCadena(char* nombre);
/// @param numero corroborar q sea un numero entero.
/// @param tam tamaño del char.
/// @return 0 si es error, 1 si es valido.
int ValidarCharNumeroEntero(char numero[]);
/// @param numero
/// @param tam
/// @return 0 si es error, 1 si es valido.
int ValidarCharNumerofloat(char numero[]);
/// @param cadena
/// @param longitud
/// @return falla la funcion -1 0 si es correcto.
int myGets(char* cadena, int longitud);

#endif /* BVALIDACIONES_H_ */
