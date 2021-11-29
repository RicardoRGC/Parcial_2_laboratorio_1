
#include "B.h"
#include "LinkedList.h"
#include "parserParcial2.h"

int controller_filterLibros(LinkedList* listaLibros, LinkedList* Editorial);

int controller_imprimirLibros(LinkedList* listaVuelos,LinkedList* pilotos);



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int falla la funcion -1 0 si es correcto.
 *
 */
int controller_loadFromText(LinkedList* pArrayListEmployee, int(*pfunc)(FILE*,LinkedList*));





/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int falla la funcion -1 0 si es correcto.
 *
 */
int controller_sortLibros(LinkedList* pArrayListEmployee);




