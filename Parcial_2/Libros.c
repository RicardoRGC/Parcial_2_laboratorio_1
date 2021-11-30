/*
 * vuelos.c
 *
 *  Created on: 20 nov. 2021
 *      Author: riky
 */

#include "B.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "BValidaciones.h"
#include "Libros.h"
#include "ControllerP.h"
#define TAM 50

int libros_comparebyAutor(void* valor1, void* valor2) // respeta el prototipo que pide el sort
{
	int rtn;

	eLibro*e1;
	eLibro*e2;

	if (valor1 != NULL && valor2 != NULL)
	{
		e1 = (eLibro*) valor1; //castea
		e2 = (eLibro*) valor2;
		rtn = strcmp(e1->autor, e2->autor); //comparo 2 cadenas a-z. el orden lo determina el sort.

	}

	return rtn;
}
int BuscaMismaEditorialImprime(LinkedList* editorial, int idComparacion,
				eLibro* auxlibro)
{
	int rtn = -1;
	int lenEditoriales = ll_len(editorial);
	eEditorial*auxEditoriales;
	int auxIdEditorial;
	if (editorial != NULL && idComparacion > 0 && auxlibro != NULL)
	{
		for (int j = 0; j < lenEditoriales; j++)
		{
			auxEditoriales = (eEditorial*) ll_get(editorial, j);

			editorial_getId(auxEditoriales, &auxIdEditorial);

			if (idComparacion == auxIdEditorial)
			{
				imprimirLibros(auxlibro, auxEditoriales);

			}
		}
		rtn = 0;
	}
	return rtn;
}
/*
 int fn_acount(void* valor1)
 {
 int rtn = 0;
 eLibro*vuelo;
 int cantPasajeros;


 vuelo = (eLibro*) valor1; //castea

 cantPasajeros= vuelo->cantidadPasajeros;

 if(cantPasajeros>0)
 {
 rtn=cantPasajeros;
 }





 return rtn;
 }
 int fn(void* valor1)
 {
 int rtn = 0;
 eLibro*vuelo;
 int horasDeVuelo;


 vuelo = (eLibro*) valor1; //castea

 horasDeVuelo=vuelo->horaLlegada-vuelo->horaDespegue;

 if(horasDeVuelo<=3)
 {
 rtn=1;
 }




 return rtn;
 }
 */
int fnMinotauro(void* valor1)
{
	int rtn = 0;
	eLibro*libro;


	libro = (eLibro*) valor1; //castea
	if (libro->idEditorial == 4)
	{
		rtn = 1;
	}

	return rtn;
}


void imprimirLibros(eLibro* this, eEditorial* Editorial)
{
	/*
	 * id
	 • titulo
	 • autor
	 • precio
	 • idEditorial
	 */
	int id;
	char titulo[TAM];
	char autor[TAM];
	float precio;
	char NombreEditorial[TAM];

	if (this != NULL)
	{

		if (!libros_getId(this, &id) && !libros_getTitulo(this, titulo)
						&& !libros_getAutor(this, autor) && !libros_getPrecio(this, &precio)
						&& !editorial_getNombre(Editorial, NombreEditorial)

						)

		{

			printf("%d %-30s %-25s %-8.f %s \n", id, titulo, autor, precio,
							NombreEditorial);

			/*printf("%d %-25s %-20s %.0f %-5s \n", this->id, this->titulo,
			 this->autor, this->precio, Editorial->nombre);*/
		}

	}
}
eLibro* libros_new()
{
	eLibro*libros;
	libros = (eLibro*) malloc(sizeof(eLibro));
	if (libros != NULL)
	{

		libros->id = 0;
		strcpy(libros->titulo, "");
		strcpy(libros->autor, "");
		libros->precio = 0;
		libros->idEditorial = 0;

	}

	return libros;
}

eLibro* libros_newParametros(char* id, char* titulo, char* autor, char* precio,
				char* idEditorial)
{

	eLibro*libros = libros_new();

	if (libros == NULL || libros_setPrecio(libros, atof(precio))
					|| libros_setIdEditorial(libros, atoi(idEditorial))
					|| libros_setTitulo(libros, titulo) || libros_setAutor(libros, autor)
					|| libros_setId(libros, atoi(id)))
	{

		vuelo_delete(libros);
	}

	return libros;
}

void vuelo_delete(eLibro* empleado)
{
	free(empleado);

}

int libros_setId(eLibro* this, int id)
{
	int rtn = -1;

	if (id > 0 && this != NULL)
	{
		this->id = id;
		rtn = 0;
	}

	return rtn;
}
int libros_getId(eLibro* this, int* id)
{
	int rtn = -1;

	if (this != NULL && id > 0)
	{
		*id = this->id;
		rtn = 0;

	}

	return rtn;
}

int libros_setPrecio(eLibro* this, float precio)
{
	int rtn = -1;

	if (precio > 0 && this != NULL)
	{
		this->precio = precio;
		rtn = 0;
	}

	return rtn;
}
int libros_getPrecio(eLibro* this, float* precio)
{
	int rtn = -1;

	if (precio > 0 && this != NULL)
	{
		*precio = this->precio;
		rtn = 0;
	}

	return rtn;
}

int libros_setIdEditorial(eLibro* this, int idEditorial)
{
	int rtn = -1;

	if (idEditorial > 0 && this != NULL)
	{
		this->idEditorial = idEditorial;
		rtn = 0;
	}

	return rtn;
}
int libros_getIdEditorial(eLibro* this, int* idEditorial)
{
	int rtn = -1;

	if (idEditorial > 0 && this != NULL)
	{
		*idEditorial = this->idEditorial;
		rtn = 0;
	}

	return rtn;
}

int libros_setTitulo(eLibro* this, char* titulo)
{
	int rtn = -1;

	if (titulo != NULL && this != NULL)
	{
		strcpy(this->titulo, titulo);
		rtn = 0;
	}

	return rtn;

}
int libros_getTitulo(eLibro* this, char* titulo)
{
	int rtn = -1;
	if (titulo != NULL && this != NULL)
	{
		strcpy(titulo, this->titulo);
		rtn = 0;
	}
	return rtn;
}

int libros_setAutor(eLibro* this, char* autor)
{
	int rtn = -1;

	if (autor != NULL && this != NULL)
	{
		strcpy(this->autor, autor);
		rtn = 0;
	}

	return rtn;

}
int libros_getAutor(eLibro* this, char* autor)
{
	int rtn = -1;
	if (autor != NULL && this != NULL)
	{
		strcpy(autor, this->autor);
		rtn = 0;
	}
	return rtn;
}

