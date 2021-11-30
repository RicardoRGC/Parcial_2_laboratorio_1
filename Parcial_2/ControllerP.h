
#include "B.h"
#include "LinkedList.h"
#include "parserParcial2.h"
int fMapeado(void* this);
int controller_saveMap(LinkedList* lista, LinkedList* editorial);
/// @fn int controller_saveAsText(char*, LinkedList*)
/// @brief
///
/// @param path
/// @param pArrayListEmployee
/// @return
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
/// @fn int controller_filterLibros(LinkedList*, LinkedList*)
/// @brief
///
/// @param listaLibros
/// @param Editorial
/// @return
int controller_filterLibros(LinkedList* listaLibros, LinkedList* Editorial);
/// @fn int controller_imprimirLibros(LinkedList*, LinkedList*)
/// @brief
///
/// @param listaVuelos
/// @param pilotos
/// @return
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




