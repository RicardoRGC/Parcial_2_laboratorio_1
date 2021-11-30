#include "ControllerP.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
#include "Editorial.h"
#include "B.h"
#include "Libros.h"
#define TAM 20

#define REINTENTOS 3
int fMapeado(void* this)
{
	/*
	 * * PLANETA: 20% (si el monto es mayor o igual a $300)  id 1
	 * SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)   id 2
	 */
	int idEditorial;
	float precio;
	float descuento;
	int rtn = -1;

	if (this != NULL)
	{
		libros_getIdEditorial(this, &idEditorial);
		libros_getPrecio(this, &precio);

		if (idEditorial == 1 && precio >= 300)
		{

			descuento = precio - (precio * 20 / 100);
			rtn = libros_setPrecio(this, descuento);
		}
		else
		{
			if (idEditorial == 2 && precio <= 200)
			{
				descuento = precio - (precio * 10 / 100);
				rtn = libros_setPrecio(this, descuento);
			}
		}


	}
	return rtn;
}
int controller_saveMap(LinkedList* lista)
{
	int rtn = -1;

	if (lista != NULL)
	{

	//	LinkedList*listaClonada = ll_clone(lista);//clonarla para no modificar la principal.

		rtn=ll_map(lista, fMapeado);

		controller_saveAsText("mapead.csv", lista);

	}
	return rtn;
}
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	int tamLista;
	    int id;
	    char titulo[50];
	    char autor[50];
	    float precio;
	    int idEditorial;

	if (path != NULL && pArrayListEmployee != NULL)
	{

		tamLista = ll_len(pArrayListEmployee);

		FILE*pFile = fopen(path, "w");

		if (pFile != NULL)
		{

		  	eLibro* libro = libros_new();

			for (int i = 0; i < tamLista; i++)
			{
				libro = (eLibro*) ll_get(pArrayListEmployee, i);

				if (libros_getAutor(libro, autor)!= -1
								&& libros_getId(libro, &id)!= -1
								&& libros_getIdEditorial(libro, &idEditorial)!=-1
								&& libros_getPrecio(libro, &precio)!=-1
								&&libros_getTitulo(libro, titulo)!=-1)
				{
					fprintf(pFile, "%d,%s,%s,%.2f,%d\n", id,titulo,autor,precio, idEditorial); //Se escribe al archivo
				}

			}
			rtn = 0;
			fclose(pFile);
		}

	}

	return rtn;
}
int controller_filterLibros(LinkedList* listaLibros, LinkedList* Editorial)
{
	int rtn = -1;

	LinkedList*listaFiltrados = ll_filter(listaLibros, fnMinotauro);

	if (listaFiltrados != NULL&& 	controller_saveAsText("MINOTAURO.csv", listaFiltrados)!=-1)
	{


		rtn=controller_imprimirLibros(listaFiltrados, Editorial);
	}

	return rtn;
}

int controller_loadTextId(char* path, char* cadena)
{
	int rtn = -1;
	FILE*pFile;

	if (path != NULL)
	{
		pFile = fopen(path, "r");

		fgets(cadena, TAM, pFile);

		fclose(pFile);
		rtn = 0;

	}

	return rtn;
}
int controller_saveTextId(char* path, int idmaximo)
{
	int rtn = -1;
	FILE*idArchivo;
	if (path != NULL)
	{
		idArchivo = fopen(path, "w");
		fprintf(idArchivo, "%d", idmaximo);
		fclose(idArchivo);
		rtn = 0;
	}
	return rtn;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListEmployee,
				int (*pfunc)(FILE*, LinkedList*))
{
	char NombreArchivo[TAM];

	int rtn = -1;

	getString(NombreArchivo, TAM, "ingrese nombre del archivo", "error", 3);

	FILE*pFile;



		pFile = fopen(NombreArchivo, "r");

		if (pFile != NULL && pArrayListEmployee != NULL)
		{

			rtn = pfunc(pFile, pArrayListEmployee);

		}


	return rtn;
}
int controller_loadFromTextVuelos(char* path, LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	FILE*pFile;
	pFile = fopen(path, "r");

	if (pFile != NULL && pArrayListEmployee != NULL)
	{

		//rtn = parser_EmployeeFromTextVuelos(pFile, pArrayListEmployee);

	}

	return rtn;
}

int controller_imprimirLibros(LinkedList* libros, LinkedList* editorial)
{

	int rtn =-1;

	eLibro*auxLibros;

	int lenLibros = ll_len(libros);

	int idEditorial;

	if (libros != NULL && lenLibros != 0)
	{

		printf("ID  "
						"TITULO  "
						"                     AUTOR  "
						"                   PRECIO  "
						"EDITORIAL "
						"  \n\n");
		for (int i = 0; i < lenLibros; i++)
		{
			auxLibros = (eLibro*) ll_get(libros, i);

			libros_getIdEditorial(auxLibros, &idEditorial);
			//funcion
			BuscaMismaEditorialImprime(editorial, idEditorial, auxLibros);

		}
		rtn = 0;
	}
	return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortLibros(LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	if (pArrayListEmployee != NULL)
	{
		rtn = ll_sort(pArrayListEmployee, libros_comparebyAutor, 1);

	}

	return rtn;
}
