/*
 * vuelos.h
 *
 *  Created on: 20 nov. 2021
 *      Author: riky
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include <stdio.h>
#include <stdlib.h>

#include "Editorial.h"
#include "LinkedList.h"
/*
 * eLibro:
• id
• titulo
• autor
• precio
• idEditorial
eEditorial:
• idEditorial
• nombre
 */
typedef struct
{
    int id;
    char titulo[20];
    char autor[20];
    float precio;
    int idEditorial;

}eLibro;



/// @fn eLibro libros_new*()
/// @brief contructor por defecto
///
/// @return devuelve el libro con los datos en defecto.
eLibro* libros_new();

/// @fn int libros_comparebyAutor(void*, void*)
/// @brief
///
/// @param valor1
/// @param valor2
/// @return
int libros_comparebyAutor(void* valor1, void* valor2);
/// @fn int BuscaMismaEditorialImprime(LinkedList*, int, eLibro*)
/// @brief
///
/// @param editorial
/// @param idComparacion
/// @param auxlibro
/// @return
int BuscaMismaEditorialImprime(LinkedList* editorial, int idComparacion,eLibro* auxlibro);
/// @fn int fnMinotauro(void*, void*)
/// @brief
///
/// @param valor1
/// @param valor2
/// @return
int fnMinotauro(void* valor1);

/// @fn void vuelo_delete(eLibro*)
/// @brief
///
/// @param empleado
void vuelo_delete(eLibro* empleado);
/// @fn void imprimirLibros(eLibro*, eEditorial*)
/// @brief
///
/// @param this
/// @param piloto
void imprimirLibros(eLibro* this, eEditorial* piloto);
/// @fn eLibro libros_newParametros*(char*, char*, char*, char*, char*)
/// @brief
///
/// @param id
/// @param titulo
/// @param autor
/// @param precio
/// @param idEditorial
/// @return
eLibro* libros_newParametros(char* id, char* titulo, char* autor,
				char* precio, char* idEditorial);
/// @fn int libros_setId(eLibro*, int)
/// @brief
///
/// @param this
/// @param id
/// @return
int libros_setId(eLibro* this, int id);
/// @fn int libros_setPrecio(eLibro*, float)
/// @brief
///
/// @param this
/// @param precio
/// @return
int libros_setPrecio(eLibro* this, float precio);
/// @fn int libros_setIdEditorial(eLibro*, int)
/// @brief
///
/// @param this
/// @param horaLlegada
/// @return
int libros_setIdEditorial(eLibro* this, int horaLlegada);

/// @fn int vuelo_setidPiloto(eLibro*, int)
/// @brief
///
/// @param this
/// @param idPiloto
/// @return
int vuelo_setidPiloto(eLibro* this, int idPiloto);
/// @fn int libros_setAutor(eLibro*, char*)
/// @brief
///
/// @param this
/// @param fecha
/// @return
int libros_setAutor(eLibro* this, char* fecha);
/// @fn int libros_setTitulo(eLibro*, char*)
/// @brief
///
/// @param this
/// @param destino
/// @return
int libros_setTitulo(eLibro* this, char* destino);
/// @fn int libros_getId(eLibro*, int*)
/// @brief
///
/// @param this
/// @param id
/// @return
int libros_getId(eLibro* this, int* id);
/// @fn int libros_getPrecio(eLibro*, float*)
/// @brief
///
/// @param this
/// @param precio
/// @return
int libros_getPrecio(eLibro* this, float* precio);
/// @fn int libros_getIdEditorial(eLibro*, int*)
/// @brief
///
/// @param this
/// @param idEditorial
/// @return
int libros_getIdEditorial(eLibro* this, int* idEditorial);

/// @fn int libros_getAutor(eLibro*, char*)
/// @brief
///
/// @param this
/// @param fecha
/// @return
int libros_getAutor(eLibro* this, char* fecha);
/// @fn int libros_getTitulo(eLibro*, char*)
/// @brief
///
/// @param this
/// @param destino
/// @return
int libros_getTitulo(eLibro* this, char* destino);


#endif /* LIBROS_H_ */
