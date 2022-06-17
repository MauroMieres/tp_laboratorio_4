#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#include "validaciones.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	    FILE* pFile;

	    if ( path != NULL && pArrayListPassenger != NULL )
	    {
	        printf("Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");

	        pFile = fopen( path, "r");
	        if ( pFile == NULL )
	        {
	            printf("No se pudo abrir el archivo\n");
	        }
	        else
	        {
	            if (parser_PassengerFromText(pFile, pArrayListPassenger))
	            {
	                printf( "Carga de archivo de texto exitosa\n" );
	                todoOk = 1;
	            }
	        }
	    }
	    fclose(pFile);
	    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk  = 0;
		FILE* p;

		if(path != NULL && pArrayListPassenger != NULL)
		{
			printf("Cargar los datos de los empleados desde el archivo data.bin (modo bin).\n");
			p = fopen(path,"rb");
			if(p == NULL)
			{
				printf("No se pudo abrir el archivo\n");
			}
			else
			{
				if(parser_PassengerFromBinary(p,pArrayListPassenger))
				{
					printf("Carga de archivo de texto exitosa\n");
					todoOk = 1;
				}
			}
		}
		fclose(p);
		return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,char* path)
{
	Passenger* newPassenger = NULL;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero_int;
	int statusFlight_int;
	char  tipoPasajero[15];
	char codigoVuelo[15];
	char statusFlight[15];
	int todoOk = 0;
	int tam;
	if(pArrayListPassenger != NULL){

		 tam = ll_len(pArrayListPassenger);
		 if(tam==0)
		 {
			 FILE* pFile;
			 pFile = fopen(path,"r");
			 id=passenger_getMaxId(pFile)+1;
		 }
		 else
		 {
			 id = controller_IdSiguiente(pArrayListPassenger);
			 id++;
		 }
		   printf("***Add Passenger***\n\n");

		   getAlphabetic_Characters_String(nombre,"Ingresar nombre: ","Nombre muy largo, reingrese: ",51);
		   changeStringFormat(nombre);

		   getAlphabetic_Characters_String(apellido,"Ingresar apellido: ","Apellido muy largo, reingrese: ",51);
		   changeStringFormat(apellido);

		   getFloat2(&precio, "Ingrese el precio del vuelo: ", "Error, ingrese un precio valido: ",1,1000000);

		   //se genera aleatoriamente un codigo de vuelo de 7 caracteres
		   strcpy(codigoVuelo,randstring(7));

		   statusFlight_int = rand() % (3 + 1 - 1) + 1;

		   switch(statusFlight_int)
			   {
			   case 1:
				   strcpy(statusFlight,"En Vuelo");
				   break;
			   case 2:
				   strcpy(statusFlight,"Aterrizado");
				   break;
			   case 3:
				   strcpy(statusFlight,"Demorado");
				   break;
			   }

		   getInt2(&tipoPasajero_int, "Ingrese tipo de pasajero\n1)EconomyClass/2)FirstClass/3)ExecutiveClass: ", "Error, ingrese un tipo de pasajero valido", 1, 3);

		   switch(tipoPasajero_int)
			   {
			   case 1:
				   strcpy(tipoPasajero,"EconomyClass");
				   break;
			   case 2:
				   strcpy(tipoPasajero,"FirstClass");
				   break;
			   case 3:
				   strcpy(tipoPasajero,"ExecutiveClass");
				   break;
			   }

		newPassenger = Passenger_new();

		if(newPassenger != NULL)
		{
			if(    Passenger_setId(newPassenger,id)
				&& Passenger_setNombre(newPassenger, nombre)
				&& Passenger_setApellido(newPassenger, apellido)
				&& Passenger_setPrecio(newPassenger, precio)
				&& Passenger_setStatusFlight(newPassenger, statusFlight)
				&& Passenger_setCodigoVuelo(newPassenger, codigoVuelo)
				&& Passenger_setTipoPasajero(newPassenger, tipoPasajero))
			{
				printf("\n** Pasajero agregado con exito!! **\n");
				ll_add(pArrayListPassenger,newPassenger);
			}
			else
			{
				free(newPassenger);
				printf("\n** Error**\n");
			}
		}
		todoOk = 1;
	}
	else
	{
		printf("**\n No hay espacio**\n");
	}
	return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
		int idPasajero=-1;
		int indice;
		int opcion;
		char respuesta;

		char nombre[50];
		char apellido[50];
		float precio;
		char tipoPasajero[15];
		int tipoPasajeroInt;
		char codigoVuelo[15];
		char statusFlight[15];
		int statusFlightInt;

		Passenger* auxPassenger=NULL;

		if(pArrayListPassenger!=NULL)
		{
			controller_ListPassenger(pArrayListPassenger);
			do
			{
				getInt(&idPasajero, "Ingrese el id: ", "Ingrese un id valido: ");
			}while(idPasajero<0);

			auxPassenger = controller_searchPassengerID(pArrayListPassenger, idPasajero, &indice);
			if(indice!=-1)
			{
				printf("***Menu modificacion pasajero***\n");
				Passenger_header();
				controller_showPassenger(auxPassenger);
				printf("1)Modificar nombre.\n2)Modificar apellido.\n3)Modificar precio del vuelo.\n4)Modificar Codigo de vuelo.\n5)Modificar Tipo de pasajero.\n6)Modificar estado de vuelo.\n");
				getInt(&opcion, "Ingrese una opcion:", "Error, ingrese una opcion valida: ");
				switch(opcion)
				{
				case 1:
					getAlphabetic_Characters_String(nombre,"1) Modificar nombre: ","Nombre muy largo, reingrese: ",51);
				    changeStringFormat(nombre);
				    printf("Nombre ingresado: %s\n",nombre);
				    getCaracter(&respuesta,"Confirma modificacion? S/N","ERROR, ingrese un caracter valido: ", 'S', 'N');
					   switch(respuesta)
					   {
					   case 'S':
						   Passenger_setNombre(auxPassenger,nombre);
						   printf("Modificacion exitosa!\n");
						   break;
					   case 'N':
						   printf("Modificacion cancelada\n");
						   break;
					   }
					break;
				case 2:
					getAlphabetic_Characters_String(apellido,"2) Modificar apellido: ","Apellido muy largo, reingrese: ",51);
					changeStringFormat(apellido);
					printf("Apellido ingresado: %s\n",apellido);
					getCaracter(&respuesta,"Confirma modificacion? S/N","ERROR, ingrese un caracter valido: ", 'S', 'N');
					   switch(respuesta)
					   {
					   case 'S':
						   Passenger_setApellido(auxPassenger,apellido);
						   printf("Modificacion exitosa!\n");
						   break;
					   case 'N':
						   printf("Modificacion cancelada\n");
						   break;
					   }
					break;
				case 3:
					getFloat2(&precio, "3)Modificar precio del vuelo: ", "Error, ingrese un precio valido: ",1,1000000);
					printf("Precio ingresado: %.2f\n",precio);
					getCaracter(&respuesta,"Confirma modificacion? S/N","ERROR, ingrese un caracter valido: ", 'S', 'N');
					   switch(respuesta)
					   {
					   case 'S':
						   Passenger_setPrecio(auxPassenger,precio);
						   printf("Modificacion exitosa!\n");
						   break;
					   case 'N':
						   printf("Modificacion cancelada\n");
						   break;
					   }
					break;
				case 4:
					 getString(codigoVuelo, "4)Modificar codigo de vuelo: ", "Error, maximo 10 caracteres por codigo",10);
					 toupperString(codigoVuelo);
					 printf("Codigo de vuelo ingresado: %s\n",codigoVuelo);
					 getCaracter(&respuesta,"Confirma modificacion? S/N","ERROR, ingrese un caracter valido: ", 'S', 'N');
					   switch(respuesta)
					   {
					   case 'S':
						   Passenger_setCodigoVuelo(auxPassenger, codigoVuelo);
						   printf("Modificacion exitosa!\n");
						   break;
					   case 'N':
						   printf("Modificacion cancelada\n");
						   break;
					   }
					break;
				case 5:
					getInt2(&tipoPasajeroInt, "5)Modificar tipo de pasajero: 1)EconomyClass 2)FirstClass 3)ExecutiveClass", "ERROR, ingrese un tipo de pasajero valido: ", 1, 3);
					switch(tipoPasajeroInt)
					{
					case 1:
						printf("Tipo de pasajero ingresado: EconomyClass\n");
						strcpy(tipoPasajero,"EconomyClass");
						break;
					case 2:
						printf("Tipo de pasajero ingresado: FirstClass\n");
						strcpy(tipoPasajero,"FirstClass");
						break;
					case 3:
						printf("Tipo de pasajero ingresado: ExecutiveClass\n");
						strcpy(tipoPasajero,"ExecutiveClass");
						break;
					}
					getCaracter(&respuesta,"Confirma modificacion? S/N","ERROR, ingrese un caracter valido: ", 'S', 'N');
					switch(respuesta)
					   {
					   case 'S':
						   Passenger_setTipoPasajero(auxPassenger,tipoPasajero);
						   printf("Modificacion exitosa!\n");
						   break;
					   case 'N':
						   printf("Modificacion cancelada\n");
						   break;
					   }
					break;
				case 6:
					getInt2(&statusFlightInt, "6)Modificar estado de vuelo: 1)En vuelo 2)Aterrizado 3)Demorado", "ERROR, ingrese un estado de vuelo valido: ", 1, 3);
						switch(statusFlightInt)
						{
						case 1:
							printf("Estado de vuelo ingresado: En vuelo\n");
							strcpy(statusFlight,"En vuelo");
							break;
						case 2:
							printf("Estado de vuelo ingresado: Aterrizado\n");
							strcpy(statusFlight,"Aterrizado");
							break;
						case 3:
							printf("Estado de vuelo ingresado: Demorado\n");
							strcpy(statusFlight,"Demorado");
							break;
						}
						getCaracter(&respuesta,"Confirma modificacion? S/N","ERROR, ingrese un caracter valido: ", 'S', 'N');
						switch(respuesta)
						   {
						   case 'S':
							   Passenger_setStatusFlight(auxPassenger, statusFlight);
							   printf("Modificacion exitosa!\n");
							   break;
						   case 'N':
							   printf("Modificacion cancelada\n");
							   break;
						   }
					break;
				default:
					printf("Se ingreso una opcion invalida!\n");
				}
			}
			else
			{
				printf("No existe pasajero con el id: %d\n",idPasajero);
			}
			retorno=1;
		}
		return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
   int retorno=-1;
   int indice;
   char respuesta;
   int idPasajero=-1;
   		Passenger* auxPassenger=NULL;

		if(pArrayListPassenger!=NULL)
		{

			controller_ListPassenger(pArrayListPassenger);
			do
			{
				getInt(&idPasajero, "Ingrese el id: ", "Ingrese un id valido: ");
			}while(idPasajero<0);
			auxPassenger = controller_searchPassengerID(pArrayListPassenger, idPasajero, &indice);
			if(indice!=-1)
			{
				Passenger_header();
				controller_showPassenger(auxPassenger);
				getCaracter(&respuesta,"Confirma baja? S/N","ERROR, ingrese un caracter valido: ", 'S', 'N');
				   switch(respuesta)
				   {
				   case 'S':
					   ll_remove(pArrayListPassenger,indice);
					   printf("Baja exitosa!\n");
					   break;
				   case 'N':
					   printf("Baja cancelada\n");
					   break;
				   }
			}
		}
		else
		{
			printf("El id %d no existe en el sistema",idPasajero);
		}
   return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pAuxPassenger = NULL;
		int todoOk = 0;
		int tam;

		if(pArrayListPassenger != NULL)
		{
			tam =  ll_len(pArrayListPassenger);
			printf("                     		     ***Lista de Pasajeros  ***\n");
			Passenger_header();
			for(int i = 0; i < tam; i++)
			{
				pAuxPassenger = ll_get(pArrayListPassenger,i);
				controller_showPassenger(pAuxPassenger);
			}
			todoOk =1;
		}
		return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
		int opcion;
		int orden;
		//1 es de menor a mayor, 0 es de mayor a menor en ll_sort
		if (pArrayListPassenger != NULL)
		{
			printf("***Ordenar pasajeros***\n");
			printf("1)Ordenar por nombre\n2)Ordenar por apellido\n3)Ordenar por precio de vuelo\n4)Ordenar por codigo de vuelo\n5)Ordenar por tipo de pasajero\n6)Ordenar por estado de vuelo\n7)Ordenar por Id\n");
			getInt2(&opcion, "Ingrese una opcion:", "ERROR, ingrese una opcion correcta: ", 1, 7);
			getInt2(&orden, "0: Mayor a menor\n1: Menor a mayor", "ERROR, ingrese una opcion correcta: ", 0, 1);
			switch(opcion)
			{
				case 1:
					ll_sort( pArrayListPassenger,controller_compareNames,orden);
					controller_ListPassenger(pArrayListPassenger);
					break;
				case 2:
					ll_sort( pArrayListPassenger,controller_compareLastNames,orden);
					controller_ListPassenger(pArrayListPassenger);
					break;
				case 3:
					ll_sort( pArrayListPassenger,controller_comparePrices,orden);
					controller_ListPassenger(pArrayListPassenger);
					break;
				case 4:
					ll_sort( pArrayListPassenger,controller_compareFlyCodes,orden);
					controller_ListPassenger(pArrayListPassenger);
					break;
				case 5:
					ll_sort( pArrayListPassenger,controller_comparePassengerType,orden);
					controller_ListPassenger(pArrayListPassenger);
					break;
				case 6:
					ll_sort( pArrayListPassenger,controller_compareStatusFlight,orden);
					controller_ListPassenger(pArrayListPassenger);
					break;
				case 7:
					ll_sort( pArrayListPassenger,controller_compareId,orden);
					controller_ListPassenger(pArrayListPassenger);
					break;
				default:
					printf("Opcion invalida\n");
			}
			retorno=1;
		}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	FILE* pFile;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char  tipoPasajero[15];
	char codigoVuelo[15];
	char statusFlight[15];
	Passenger* auxPassenger;

	if ( path != NULL && pArrayListPassenger != NULL )
	{
		pFile = fopen(path, "w");
		if (pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}

		fprintf(pFile, "id,nombre,apellido,precio,tipoPasajero,codigoVuelo,statusFlight\n");

		for (int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPassenger = ll_get(pArrayListPassenger, i);
			if ( Passenger_getId(auxPassenger,&id)
		    		&&
					Passenger_getNombre(auxPassenger, nombre)
					&&
				 	Passenger_getApellido(auxPassenger, apellido)
					&&
					Passenger_getPrecio(auxPassenger,&precio)
					&&
					Passenger_getStatusFlight(auxPassenger, statusFlight)
					&&
				 	Passenger_getCodigoVuelo(auxPassenger, codigoVuelo)
					&&
					Passenger_getTipoPasajero(auxPassenger, tipoPasajero))
			{
				fprintf(pFile, "%d,%s,%s,%f,%s,%s,%s\n",id,nombre,apellido,precio,tipoPasajero,codigoVuelo,statusFlight);
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_showPassenger(Passenger* pPassenger)
{
	int todoOk=0;
    int id;
    char nombre[50];
    char apellido[50];
    float precio;
	char tipoPasajero[15];
	char codigoVuelo[15];
	char statusFlight[15];

    if(pPassenger != NULL &&
    		Passenger_getId(pPassenger,&id)
    		&&
			Passenger_getNombre(pPassenger, nombre)
			&&
		 	Passenger_getApellido(pPassenger, apellido)
			&&
			Passenger_getPrecio(pPassenger,&precio)
			&&
			Passenger_getStatusFlight(pPassenger, statusFlight)
			&&
		 	Passenger_getCodigoVuelo(pPassenger, codigoVuelo)
			&&
			Passenger_getTipoPasajero(pPassenger, tipoPasajero))
    {
        printf(" %d 	%-10s	%-10s	%.2f	%-15s 	%-15s	%-15s\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,statusFlight);
        todoOk = 1;
    }
    return todoOk;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	FILE* pFile;
	Passenger* auxPassenger;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "wb");
		if (pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}

		for (int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPassenger = ll_get(pArrayListPassenger, i);
			if ((auxPassenger) != NULL)
			{
				fwrite(auxPassenger, sizeof(Passenger), 1, pFile);
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

int controller_IdSiguiente(LinkedList* pArrayListPassenger)
{
	Passenger* auxPassenger = NULL;
	int maximo;
	int id;
	int tam;
	if(pArrayListPassenger != NULL)
	{
		tam = ll_len(pArrayListPassenger);
		for(int i = 0; i < tam ; i++)
		{
			auxPassenger = ll_get(pArrayListPassenger,i);
			Passenger_getId(auxPassenger, &id);
			if(id > maximo || i == 0)
			{
				maximo = id;
			}
		}
	}
	return maximo;
}

Passenger* controller_searchPassengerID(LinkedList* pArrayListPassenger,int id, int* index)
{
	Passenger* auxPassenger = NULL;
	int auxId;
	*index = -1;
	for(int i = 0 ; i < ll_len(pArrayListPassenger) ; i++ )
	{
		auxPassenger  = (Passenger*)ll_get(pArrayListPassenger,i);
		Passenger_getId(auxPassenger ,&auxId);
		if(auxPassenger  != NULL && auxId == id)
		{
			(*index) = i;
			break;
		}
	}
return auxPassenger;
}

int controller_comparePrices(void* a, void* b )
{
	int todoOk = 0;
	if(a != NULL && b != NULL)
	{
		if(((Passenger*)a)->precio > ((Passenger*)b)->precio)
		{
			todoOk = 1;
		}
		else
		{
			if(((Passenger*)a)->precio < ((Passenger*)b)->precio)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}

int controller_compareNames(void* a, void* b )
{
	int retorno = 0;
	char passengerA[40];
	char passengerB[40];
	if(a != NULL && b != NULL)
	{
		strcpy(passengerA,((Passenger*)a)->nombre);
		strcpy(passengerB,((Passenger*)b)->nombre);
		retorno = strcmp(passengerA,passengerB);
	}
	return retorno;
}

int controller_compareLastNames(void* a, void* b )
{
	int retorno = 0;
	char passengerA[40];
	char passengerB[40];
	if(a != NULL && b != NULL)
	{
		strcpy(passengerA,((Passenger*)a)->apellido);
		strcpy(passengerB,((Passenger*)b)->apellido);
		retorno = strcmp(passengerA,passengerB);
	}
	return retorno;
}

int controller_compareId(void* a, void* b )
{
	int todoOk = 0;
	if(a != NULL && b != NULL)
	{
		if(((Passenger*)a)->id > ((Passenger*)b)->id)
		{
			todoOk = 1;
		}
		else
		{
			if(((Passenger*)a)->id < ((Passenger*)b)->id)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}

int controller_compareFlyCodes(void* a, void* b )
{
	int retorno = 0;
	char passengerA[40];
	char passengerB[40];
	if(a != NULL && b != NULL)
	{
		strcpy(passengerA,((Passenger*)a)->codigoVuelo);
		strcpy(passengerB,((Passenger*)b)->codigoVuelo);
		retorno = strcmp(passengerA,passengerB);
	}
	return retorno;
}

int controller_comparePassengerType(void* a, void* b )
{
	int retorno = 0;
	char passengerA[40];
	char passengerB[40];
	if(a != NULL && b != NULL)
	{
		strcpy(passengerA,((Passenger*)a)->tipoPasajero);
		strcpy(passengerB,((Passenger*)b)->tipoPasajero);
		retorno = strcmp(passengerA,passengerB);
	}
	return retorno;
}

int controller_compareStatusFlight(void* a, void* b )
{
	int retorno = 0;
	char passengerA[40];
	char passengerB[40];
	if(a != NULL && b != NULL)
	{
		strcpy(passengerA,((Passenger*)a)->statusFlight);
		strcpy(passengerB,((Passenger*)b)->statusFlight);
		retorno = strcmp(passengerA,passengerB);
	}
	return retorno;
}


