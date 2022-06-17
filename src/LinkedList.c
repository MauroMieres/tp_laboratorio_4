#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this =  (LinkedList*)malloc(sizeof(LinkedList));

		    if(this != NULL )
		    {
		    	this->pFirstNode = NULL;
		    	this->size= 0;
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
	 Node* nodo = NULL;
		if ( this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
		{
			nodo = this->pFirstNode;
			while (nodeIndex>0)
			{
				nodo = nodo->pNextNode;
				nodeIndex--;
			}
		}
		return nodo;
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode = NULL;//primero creo el nuevo nodo
    Node* previousNode = NULL;//y este nodo es que uso en caso de q el indice no sea cero

    	if ( this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))//validacion
    	{
    		newNode=(Node*)malloc(sizeof(Node));//pido memoria para el nuevonodo
    		if(newNode!=NULL)//si no es nulo--
    		{
    			newNode->pElement = pElement;//le cargo el elemento q me mandaron
    			newNode->pNextNode=NULL;//todavia no se si hay un nodo posterior, entonces le pongo null
    			if(nodeIndex==0)//si el index es cero, entonces es el primer nodo
    			{
    				newNode->pNextNode = this->pFirstNode;//si el index es cero entonces es el first node
    				this->pFirstNode = newNode;//llamo a la ll y le pido el primernodo
    			}
    			else
    			{
    				previousNode = getNode(this, nodeIndex-1);//pido el nodo, pero el indice es -1 porq es el anterior
    				newNode->pNextNode=previousNode->pNextNode;//la direccion de memoria del nuevo nodo es la del previo
    				previousNode->pNextNode=newNode;//y ahora el previo tiene la dir del nuevo o proximo
    			}
    			this->size++;//agrandar el tamanio de la linkedlist
    			returnAux=0;
    		}
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
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux = addNode(this,ll_len(this),pElement);
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
    void* returnAux = NULL;
    Node* pNode=NULL;
    //retorna el puntero al elemento
    if(this!=NULL && index >=0 && index <= ll_len(this))
    {
    	pNode = getNode(this,index);
    	if(pNode!=NULL)
    	{
    		returnAux = pNode->pElement;
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
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode=NULL;
    //por definicion funcional no validamos el pElement!=NULL
    if(this!=NULL&&index>=0&&index<ll_len(this))//index<ll_len tiene que ser menor y no menor igual
    {
		pNode = getNode(this,index);
		if(pNode!=NULL)
		{
			pNode->pElement=pElement;
			returnAux = 0;
		}
    }
    return returnAux;
}


/** \brief Elimina un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del nodo a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;
	Node* previousNode = NULL;
	Node* auxNode=NULL;
	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		auxNode=getNode(this,index);
		if (index == 0)
		{
			this->pFirstNode = auxNode->pNextNode;
		}
		else
		{
			previousNode = getNode(this, index-1);//el nodo previo es el del indice-1
			if (previousNode != NULL)
			{
				previousNode->pNextNode = auxNode->pNextNode;
			}
		}
		free(auxNode);
		this->size--; //lo mismo que en addNode, pero aca reduzco el tamanio de la linkedlist
		returnAux = 0;
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
    int returnAux = -1;
    if(this!=NULL)
    {
    	while(ll_len(this))
    	{
    		returnAux= ll_remove(this,0);
    		if(returnAux)
    		{
    			break;
    		}
    	}
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
    int returnAux = -1;
    if(this!=NULL&&!(ll_clear(this)))
    {
    	free(this);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 * aca se devuelve el indice de donde se encuentra el elemento, ll_contains solo te dice si encuentra o no el elemento
 * i < ll_len(this) es menor y no menor igual porque: la linkedlist tiene un tamaño 5, sin embargo, los indices comienzan
 * en el cero, entonces: 0 1 2 3 4 seran los indices recorridos
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
		for (int i = 0; i < ll_len(this);i++)
		{
			if (pElement == ll_get(this, i))
			{
				returnAux = i;
				break;
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
    int returnAux = -1;
    if(this!=NULL)
    {
		returnAux = 1;
		if (ll_len(this)) // si hay algo en la lista, entro y devuelvo 0
		{
			returnAux = 0;
		}
		else
		{
			returnAux=1;
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
    int returnAux = -1;
    if(this!=NULL&&index>=0&&index<=ll_len(this))
    {
    	returnAux = addNode(this,index,pElement);
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
void* ll_pop(LinkedList* this,int index)
{
	void* returnAux = NULL;

	returnAux = ll_get(this, index);
	ll_remove(this, index);

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
	int returnAux = -1;

	if ( this != NULL )
	{
		returnAux = 0;
		if (ll_indexOf(this, pElement) >= 0 )
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
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	if (this != NULL && this2 != NULL)
	{
		returnAux = 1;
		for (int i = 0; i < ll_len(this2); i++)
		{
			if ( !ll_contains(this, ll_get(this2, i)) )
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
               ll_len(this) = 5; pasajero1,pasajero2,pasajero3,pasajero4,pasajero5
                 	 	 	 	 	 0			1		2			3		4
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* arrayCopy = NULL;//tiene que ser menor al ll_len, lo igualamos por el tema del test
	if (this != NULL && from >= 0 && to <= ll_len(this) && to > from ) //to <= ll_len(this) porque tengo que poder copiar HASTA el indice que ingrese, sino es uno menos
	{
		arrayCopy = ll_newLinkedList();
		if (arrayCopy != NULL)
		{
			for (int i=from;i<to;i++)//i<to ahora es solo < porque los indices son 1 menos que el tamanio del linkedlist
			{
				ll_add(arrayCopy, ll_get(this,i));
			}
		}
	}
    return arrayCopy;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* arrayCopy = NULL;

	if (this != NULL  )
	{
		arrayCopy = ll_newLinkedList();
		if (arrayCopy != NULL)
		{
			for (int i = 0; i < ll_len(this); i++)
			{
				ll_add(arrayCopy, ll_get(this, i));
			}
		}
	}
	return arrayCopy;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;
	int tam = ll_len(this);
	void* aux;

	if (this != NULL && pFunc != NULL && order >= 0 && order <= 1)
	{
		for (int i=0;i<tam-1;i++)
		{
			for (int j=i+1;j<tam;j++)
			{
				//podria usar dos auxiliares aca para no usar el ll_get en cada iteracion
				if ((pFunc(ll_get(this,i),ll_get(this,j))>0&&order)|| //si es mayor a 0 el retorno y si order es = 1
				   (pFunc(ll_get(this,i),ll_get(this,j))<0&&!order)) // o si el retorno es menor a 0 y el orden es distinto a 1
				{
					aux = ll_get(this,i);
					ll_set(this,i,ll_get(this,j));
					ll_set(this,j,aux);
				}
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

/*
 * Completa un campo del elemento, recibiendo como parámetro
 * la función que sera la encargada de calcular el valor de ese campo.
 * Verificando que tanto el puntero this como el puntero a la funcion
 * fn sean distintos de NULL. Retorna la lista completa.
 * */
LinkedList* ll_map(LinkedList* this, void (*fn)(void*element))
{
	if(this!=NULL && fn!=NULL)
	{
		for(int i=0;i<ll_len(this);i++)
		{
			fn(ll_get(this,i));
		}
	}
	return this;
}

/*
 * Filtra la lista con una condición, recibiendo como parámetro
 * la función que sera la encargada de decidir si cada elemento
 * cumple la condición (1) o no (0) y si se agrega a una nueva lista filtrada.
 * Verificando que tanto el puntero this como el puntero a la funcion
 * fn sean distintos de NULL. Retorna la lista nueva lista filtrada.
 * */
LinkedList* ll_filter(LinkedList* this, int(*fn)(void*))
{
	LinkedList* newList = NULL;

	if (this!=NULL&&fn!=NULL)
	{
		newList = ll_newLinkedList();
		if (newList != NULL)
		{
			for (int i= 0;i<ll_len(this);i++)
			{
				if (fn(ll_get(this,i)))
				{
					ll_add(newList,ll_get(this,i));
				}
			}
		}
	}
	return newList;
}
