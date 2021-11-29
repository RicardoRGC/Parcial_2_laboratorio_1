#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/*
 * eEditorial:
• idEditorial
• nombre
 */

typedef struct
{
    int idEditorial;
    char nombre[20];

}eEditorial;



/// @param valor1
/// @param valor2
/// compara y ordena de a-z
/// @return 0 de la a-z mayor que 0 z-a
int libros_comparebyautor(void* valor1, void* valor2);

/// @param this
/// imprime un solo empleado
void printOne(eEditorial* this);


/// @return
eEditorial* editorial_new();
/// @param idStr
/// @param nombreStr
/// @param horasTrabajadasStr
/// @param sueldo
///  agrega los parametros a un empleado y lo devuelve
/// @return retorna el empleado
eEditorial* editorial_newParametros(char* idStr,char* nombreStr);
/// @param empleado
/// borra un empleado
void employee_delete(eEditorial* empleado);

/// @param this
/// @param id
/// ingresa el id en la lista
/// @return falla la funcion -1 0 si es correcto.
int editorial_setId(eEditorial* this,int id);
/// @param this
/// @param id
/// copia el id de la lista en un putero
/// @return falla la funcion -1 0 si es correcto.
int editorial_getId(eEditorial* this,int* id);
/// @param this
/// @param nombre
/// ingresa el nombre en la lista
/// @return falla la funcion -1 0 si es correcto.
int editorial_setNombre(eEditorial* this,char* nombre);
/// @param this
/// @param nombre
/// copia el nombre de la lista en un putero
/// @return falla la funcion -1 0 si es correcto.
int editorial_getNombre(eEditorial* this,char* nombre);



#endif // employee_H_INCLUDED
