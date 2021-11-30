#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex, void* pElement);

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux =-1;

    if(this != NULL && pFunc != NULL)
    {
        for(int i = 0 ; i< ll_len(this);  i++)
        {

             pFunc(ll_get(this,i));

        }
        returnAux=0;
    }
    return returnAux;
}

LinkedList* ll_filter(LinkedList* this, int (*fn)(void*))
{
	LinkedList*newList = NULL;
	int len;
	int i;

	if (this != NULL && fn != NULL)
	{
		newList = ll_newLinkedList();
		len = ll_len(this);
		for (i = 0; i < len; i++)
		{
			if (fn(ll_get(this, i) ))
			{
				ll_add(newList, ll_get(this, i));
			}
		}
	}
	return newList;
}
/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList*this = NULL;
	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL)
	{
		this->size = 0;
		this->pFirstNode = NULL;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;
	if (this != NULL)
	{
		returnAux = this->size;
	}
	return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{

	Node*auxNode = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		auxNode = this->pFirstNode;

		for (int i = 0; i < nodeIndex; i++)
		{
			auxNode = auxNode->pNextNode;
		}
	}

	return auxNode;

}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
	int returnAux = -1;
	Node*auxNodo = NULL;
	Node*auxNodoAnterior = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		auxNodo = (Node*) malloc(sizeof(Node));
		if (auxNodo != NULL)
		{

			if (nodeIndex == 0) //
			{
				auxNodo->pNextNode = this->pFirstNode;
				this->pFirstNode = auxNodo;

			}
			else
			{

				auxNodoAnterior = getNode(this, nodeIndex - 1);
				auxNodo->pNextNode = auxNodoAnterior->pNextNode;
				auxNodoAnterior->pNextNode = auxNodo;

			}
		}
		this->size++;
		auxNodo->pElement = pElement;

		returnAux = 0;

	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex, void* pElement)
{
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement) //tengo q agregar un elemento con el addNode.
{
	int returnAux = -1;
	if (this != NULL)
	{
		returnAux = addNode(this, ll_len(this), pElement);

	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void*returnAux = NULL;
	Node*auxNode = NULL;
	int len = ll_len(this);
	/*
	 * Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
	 puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
	 verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
	 *
	 */
	if (this != NULL && index <= len && index >= 0)
	{
		auxNode = getNode(this, index);
		if (auxNode != NULL)
		{

			returnAux = auxNode->pElement;

		}

	}

	return returnAux;

}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
	int returnAux = -1;
	/*
	 * Verificando que el puntero this
	 sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
	 falla la función retorna (-1) y si tiene éxito (0).
	 */
	Node*auxNode = NULL;
	if (this != NULL && index <= ll_len(this) && index >= 0)
	{
		//Inserta un elemento en el LinkedList, en el índice especificado.
		auxNode = getNode(this, index);
		if (auxNode != NULL)
		{
			auxNode->pElement = pElement; // asignar
			returnAux = 0;
		}

	}

	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{

	/*
	 * Elimina un elemento del LinkedList, en el índice especificado. Verificando que el puntero this
	 sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
	 falla la función retorna (-1) y si tiene éxito (0).
	 */

	int returnAux = -1;
	Node*auxNodo = NULL;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{

		auxNodo = getNode(this, index);

		if (auxNodo != NULL)
		{
			if (index == 0) //
			{
				this->pFirstNode = auxNodo->pNextNode;
			}
			else
			{

				Node*auxNodoAnterior = getNode(this, index - 1);
				auxNodoAnterior->pNextNode = auxNodo->pNextNode;

			}
			free(auxNodo);
			this->size--;
			returnAux = 0;

		}

	}

	return returnAux;

}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	/*
	 * Borra todos los elementos de LinkedList. Verificando que el puntero this sea distinto de NULL.
	 Si la verificación falla la función retorna (-1) y si tiene éxito (0)
	 */

	int returnAux = -1;
	int len = ll_len(this);
	if (this != NULL)
	{
		for (int i = len; i >= 0; i--)
		{
			ll_remove(this, i);

		}
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	/*
	 * Elimina el LinkedList . Verificando que el puntero this sea distinto de NULL. Si la verificación
	 falla la función retorna (-1), si esta vacío (1) y si contiene elementos (0).
	 */
	int returnAux = -1;

	if (this != NULL)
	{
		returnAux = 1;

		if (!ll_clear(this))
		{
			returnAux = 0;
			free(this);
		}

	}

	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	/*
	 * Retorna el índice de la primera aparición de un elemento (element) en el LinkedList.
	 Verificando que el puntero this sea distinto de NULL. Si la verificación falla o no encuentra el
	 elemento la función retorna (-1) y si encuentra el elemento retorna su índice.
	 *
	 */
	int returnAux = -1;

	int len = ll_len(this);
	if (this != NULL)
	{

		for (int i = 0; i < len; i++)
		{
			if (ll_get(this, i) == pElement) //arreglar
			{
				returnAux = i;
			}
		}
	}
	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	/*
	 * Retorna cero si contiene elementos y uno si no los tiene. Verificando que el puntero this sea
	 distinto de NULL. Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene
	 elementos (0).
	 *
	 */
	int returnAux = -1;

	if (this != NULL)
	{
		returnAux = 0;
		if (this->size == 0)
		{
			returnAux = 1;
		}
	}

	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	/*
	 * Desplaza los elementos e inserta en la posición index. Verificando que el puntero this sea
	 distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación falla
	 la función retorna (-1) y si tiene éxito (0).
	 */
	int returnAux = -1;
	if (this != NULL && index >= 0 && index <= ll_len(this))
	{
		addNode(this, index, pElement);
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index)
{
	void*returnAux = NULL;
	void*auxElement;
	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		auxElement = ll_get(this, index);
		ll_remove(this, index);
		returnAux = auxElement;
	}

	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList* this, void* pElement)
{
	/*
	 * Comprueba si existe el elemento que se le pasa como parámetro. Verificando que tanto el
	 puntero this sea distintos de NULL. Si la verificación falla la función retorna (-1) , si encuentra
	 el elemento (1) y si no lo encuentra (0).
	 */
	int returnAux = -1;
	if (this != NULL)
	{
		returnAux = 0;
		if (ll_indexOf(this, pElement) != -1)
		{
			returnAux = 1;
		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
	/*
	 * Comprueba si los elementos pasados son contenidos por el LinkedList. Verificando que tanto el
	 puntero this como pList2 sean distintos de NULL. Si la verificación falla o no encuentra el
	 elemento la función retorna (-1), si las listas difieren (0) y si ambas listas son iguales retorna
	 (1).
	 *
	 */
	int returnAux = -1;
	void*pElement;
	if (this != NULL && this2 != NULL)
	{
		returnAux = 1;
		for (int i = 0; i < ll_len(this2); i++)
		{
			pElement = ll_get(this2, i);
			if (!ll_contains(this, pElement))
			{
				returnAux = 0;
				break;

			}
		}
	}
	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 o (si el indice from es menor a 0 o mayor al len de la lista)
 o (si el indice to es menor o igual a from o mayor al len de la lista)
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
	/*
	 * Retorna un nuevo LinkedList con el subconjunto de elementos. Verificando que el puntero this
	 sea distinto de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño
	 del array. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo
	 array.
	 */
	LinkedList*cloneArray = NULL;
	void*pElement;

	if (this != NULL && from >= 0 && to <= ll_len(this) && from < ll_len(this)
					&& to >= 0)
	{
		cloneArray = ll_newLinkedList();
		for (int i = from; i < to; i++)
		{
			pElement = ll_get(this, i);
			ll_add(cloneArray, pElement);
		}

	}

	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList* this)
{
	/*
	 * Retorna un nuevo LinkedList copia del LinkedList original. Verificando que el puntero this sea
	 distinto de NULL. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el
	 nuevo array.
	 */
	LinkedList*cloneArray = NULL;

	if (this != NULL)
	{
		cloneArray = ll_newLinkedList();

		cloneArray = ll_subList(this, 0, ll_len(this));

	}
	return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*, void*), int order) // 1 si es mayor -  -1 si es menor.
{
	/*
	 * Ordena los elementos del array recibiendo como parámetro la función que sera la encargada
	 de determinar que elemento es mas grande que otro y si se debe ordenar de manera
	 ascendente o descendente. Verificando que tanto el puntero this como el puntero a la funcion
	 pFunc sean distintos de NULL. Si la verificación falla (-1) caso contrario retorna (1).
	 */
	int returnAux = -1;
	int tam;
	void*auxI = NULL;
	void*auxJ = NULL;
	if (this != NULL && pFunc != NULL && (order == 0 || order == 1)) // mi funcion retorna 1 y -1
	{
		tam = ll_len(this);
		if (tam > 0)
		{

			for (int i = 0; i < tam - 1; i++)
			{
				for (int j = i + 1; j < tam; j++)
				{
					auxI = ll_get(this, i);
					auxJ = ll_get(this, j);

					if ((pFunc(auxI, auxJ) < 0 && !order)
									|| (pFunc(auxI, auxJ) > 0 && order)) //
					{
						ll_set(this, i, auxJ);
						ll_set(this, j, auxI);

					}

				}
			}
			returnAux = 0;
		}

	}
	return returnAux;
}

