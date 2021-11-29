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

int controller_filterLibros(LinkedList* listaLibros, LinkedList* Editorial)
{
	int rtn = -1;

	LinkedList*listaFiltrados = ll_filter(listaLibros, fnMinotauro);

	if (listaFiltrados != NULL)
	{

		controller_imprimirLibros(listaFiltrados, Editorial);
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

	//if ((strcmp(NombreArchivo, "libros.csv") == 0
				//	|| strcmp(NombreArchivo, "editoriales.csv") == 0))
	{

		pFile = fopen(NombreArchivo, "r");

		if (pFile != NULL && pArrayListEmployee != NULL)
		{

			rtn = pfunc(pFile, pArrayListEmployee);

		}

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

	int rtn = -1;

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
