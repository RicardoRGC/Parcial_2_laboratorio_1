
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
#include "B.h"
#include "parserParcial2.h"
#include "BValidaciones.h"
#include "ControllerP.h"
#define TAM 50
int main(void)
{

	setbuf(stdout, NULL);

	LinkedList*listaEditoriales = ll_newLinkedList();
	LinkedList*listaLibros = ll_newLinkedList();
	int option = 0;
	int flagArchivo = 0;
	int flagArchivo1 = 0;

	//int flagEmpleados = 0;

	do
	{
		if (getNumero(&option, "1.Cargar archivo Libros:\n"
						"2.Cargar archivo Editoriales:\n"
						"3. Ordenar la lista generada en el ítem anterior:\n"
						"4. Imprimir por pantalla todos los datos de los libros.:\n"
						"5.Realizar un listado de los libros de la editorial MINOTAURO. \n"
						"0.SALIR\n", "Error opcion incorrecta", 0, 10, 3) == -1)
		{
			printf("error");
		}
		switch (option)
		{
		case 1:


			if (flagArchivo == 0
							&& controller_loadFromText(listaLibros,parser_FromTextLibros)!= -1)
			{
				printf("correcto\n");
				flagArchivo = 1;
			}
			else
			{
				printf("no se puedo cargar\n");
			}

			break;
		case 2:

			if (flagArchivo1==0&&controller_loadFromText(listaEditoriales, parser_FromTextEditorial)!=-1)

					{
						printf("correcto\n");
						flagArchivo1 = 1;
					}
					else
					{
						printf("no se puedo cargar\n");
					}


			break;
		case 3://ordenamiento “Autor” de manera ascendente.
if(controller_sortLibros(listaLibros))
{
	printf("no se puedo cargar\n");
}



			break;
		case 4://Imprimir por pantalla todos los datos de los libros.
			if(controller_imprimirLibros(listaLibros, listaEditoriales) != 0)
			{
				printf("no se puedo cargar\n");
			}

			break;
		case 5:
			if(controller_filterLibros(listaLibros, listaEditoriales)!= 0)
			{
				printf("no se puedo cargar\n");
			}



			break;
		case 6:


			controller_saveMap(listaLibros,listaEditoriales);


			break;
		case 0:

			if (ll_deleteLinkedList(listaLibros) != -1
							&& ll_deleteLinkedList(listaEditoriales)!= -1)
					{
						printf("el programa se cerro exitosamente");
					}

			break;

		default:
			printf("\nOpcion invalida ingrece una opcion del 0 al 5\n ");
		}
	}
	while (option != 0);

	return EXIT_SUCCESS;
}

