

#include <stdio.h>
#include <stdlib.h>
#ifndef PARSERMODELO_H_
#define PARSERMODELO_H_

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int -1 error , 0 correcto
 *
 */
int parser_FromTextEditorial(FILE* pFile , LinkedList* pArrayListEmployee);

/// @fn int parser_FromTextLibros(FILE*, LinkedList*)
/// @brief
///
/// @param pFile
/// @param pArrayListEmployee
/// @return
int parser_FromTextLibros(FILE* pFile, LinkedList* pArrayListEmployee);

#endif /* PARSERMODELO_H_ */
