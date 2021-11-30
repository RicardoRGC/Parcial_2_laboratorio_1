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

int BuscaMismaEditorialImprime(LinkedList* editorial, int idComparacion,eLibro* auxlibro);

int fnMinotauro(void* valor1,void* valor2);


void vuelo_delete(eLibro* empleado);
void imprimirLibros(eLibro* this, eEditorial* piloto);

eLibro* libros_newParametros(char* id, char* titulo, char* autor,
				char* precio, char* idEditorial);
int libros_setId(eLibro* this, int id);
int libros_setPrecio(eLibro* this, float precio);
int libros_setIdEditorial(eLibro* this, int horaLlegada);

int vuelo_setidPiloto(eLibro* this, int idPiloto);
int libros_setAutor(eLibro* this, char* fecha);
int libros_setTitulo(eLibro* this, char* destino);

int libros_getId(eLibro* this, int* id);
int libros_getPrecio(eLibro* this, float* precio);
int libros_getIdEditorial(eLibro* this, int* idEditorial);


int libros_getAutor(eLibro* this, char* fecha);
int libros_getTitulo(eLibro* this, char* destino);


#endif /* LIBROS_H_ */
