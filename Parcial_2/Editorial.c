#include "BValidaciones.h"
#include "B.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "Editorial.h"

#include "ControllerP.h"
#define TAM 20
void employee_delete(eEditorial* empleado)
{
	free(empleado);

}
int libros_comparebyautor(void* valor1, void* valor2) // respeta el prototipo que pide el sort
{
	int rtn;

	eEditorial*e1;
	eEditorial*e2;

	e1 = (eEditorial*) valor1; //castea
	e2 = (eEditorial*) valor2;

	rtn = strcmp(e1->nombre, e2->nombre); //comparo 2 cadenas a-z. el orden lo determina el sort.

	return rtn;
}
/*
int employee_comparebyId(void* valor1, void* valor2)
{
	int rtn = 0;
	eEditorial*e1;
	eEditorial*e2;

	e1 = (eEditorial*) valor1; //castea
	e2 = (eEditorial*) valor2;

	if (e1->id > e2->id) // ordena numericamente.
	{
		rtn = 1;
	}
	else
	{
		if (e1->id < e2->id)
		{
			rtn = -1;
		}

	}
	return rtn;
}
*/


void printOne(eEditorial* this)
{
	int id;
	char nombre[TAM];

	if (this != NULL)
	{
		if (editorial_getId(this, &id) != -1
						&& editorial_getNombre(this, nombre) != -1)
		{

			printf("%-5d  %-15s\n", id, nombre);
		}

	}
}




eEditorial* editorial_newParametros(char* idStr, char* nombreStr)
{

	eEditorial*Editorial = editorial_new();

	if (Editorial == NULL || (editorial_setId(Editorial, atoi(idStr)) != 0)
					|| (editorial_setNombre(Editorial, nombreStr) != 0))

	{
printf("borro editorial\n");
		employee_delete(Editorial);



	}
//	printf("%d %s\n",Editorial->idEditorial,Editorial->nombre);
	return Editorial;
}


eEditorial* editorial_new()
{
	eEditorial*empleado;
	empleado = (eEditorial*) malloc(sizeof(eEditorial));
	if (empleado != NULL)
	{
		empleado->idEditorial = 0;
		strcpy(empleado->nombre, "");

	}

	return empleado;
}


int editorial_setId(eEditorial* this, int id)
{
	int rtn = -1;

	if (id > 0 && this != NULL)
	{
		this->idEditorial = id;
		rtn = 0;
	}

	return rtn;
}

int editorial_getId(eEditorial* this, int* id)
{
	int rtn = -1;

	if (this != NULL && id > 0)
	{
		*id = this->idEditorial;
		rtn = 0;

	}

	return rtn;
}

int editorial_setNombre(eEditorial* this, char* nombre)
{
	int rtn = -1;

	if (nombre != NULL && this != NULL && validarCadenaConEspacios(nombre))
	{
		strcpy(this->nombre, nombre);
		rtn = 0;
	}

	return rtn;

}
int editorial_getNombre(eEditorial* this, char* nombre)
{
	int rtn = -1;
	if (nombre != NULL && this != NULL)
	{
		strcpy(nombre, this->nombre);
		rtn = 0;
	}
	return rtn;
}

