#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Editorial.h"
#include "B.h"
#include "BValidaciones.h"
#include "ControllerP.h"
#include "Libros.h"
#include "parserParcial2.h"
#define TAM 50

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_FromTextEditorial(FILE* pFile, LinkedList* pArrayListEmployee) // recorre el archivo y lo guardad en memoria dinamica heat
{

	int conteoLineaArchivo = 0;
	char idStr[TAM];
	char nombreStr[TAM];

	int rtn = -1;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{

		fscanf(pFile, "%[^,],%[^\n] \n", idStr, nombreStr);
		while (!feof(pFile))
		{

			conteoLineaArchivo = fscanf(pFile, "%[^,],%[^\n] \n", idStr, nombreStr);

			if (conteoLineaArchivo == 2 && validarCadenaConEspacios(nombreStr)&&validarCadenaNumerica(idStr))
			{
					//printf("%s\n",nombreStr);

				eEditorial*editor;
				editor = editorial_newParametros(idStr, nombreStr);

				if (editor != NULL)
				{
					ll_add(pArrayListEmployee, editor);
					rtn = 0;
				}

			}
		}

	}

	fclose(pFile);

	return rtn;
}
int parser_FromTextLibros(FILE* pFile, LinkedList* pArrayListEmployee) // recorre el archivo y lo guardad en memoria dinamica heat
{

	int conteoLineaArchivo = 0;

	char id[TAM];
	char titulo[TAM];
	char autor[TAM];
	char precio[TAM];
	char idEditorial[TAM];

	int rtn = -1;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{


		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n] \n", id, titulo, autor,
						precio, idEditorial);


		while (!feof(pFile))
		{

			conteoLineaArchivo = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n] \n",
							id, titulo, autor, precio, idEditorial);



			if (conteoLineaArchivo == 5 && validarCadenaConEspacios(titulo)&& validarCadenaNumerica(id) && validarCadenaConEspacios(autor)&& ValidarCharNumerofloat(precio))
			{
			//	printf("%s\n",titulo);

				if (ll_add(pArrayListEmployee,
								libros_newParametros(id, titulo, autor, precio, idEditorial))
								== 0)
				{

					rtn = 0;
				}

			}


		}

	}

	fclose(pFile);

	return rtn;
}

