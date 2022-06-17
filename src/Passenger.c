/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"
#include "string.h"

Passenger* Passenger_new()
{
	Passenger* newPassenger =  (Passenger*)malloc(sizeof(Passenger));

	    if(newPassenger != NULL )
	    {
	    	newPassenger->id = 0;
	        strcpy(newPassenger->nombre," ");
	        strcpy(newPassenger->apellido," ");
	        newPassenger->precio = 0;
	        strcpy(newPassenger->tipoPasajero," ");
	        strcpy(newPassenger->statusFlight," ");
	        strcpy(newPassenger->codigoVuelo," ");
	    }
	    return newPassenger;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* statusFlight)
{
	Passenger* pPassenger = Passenger_new();
	    if(pPassenger != NULL)
	    {
	        if(!( Passenger_setId(pPassenger, atoi(idStr) )
	           && Passenger_setNombre(pPassenger, nombreStr)
	           && Passenger_setApellido(pPassenger, apellidoStr)
	           && Passenger_setPrecio(pPassenger, atof(precioStr))
			   && Passenger_setTipoPasajero(pPassenger,tipoPasajeroStr)
			   && Passenger_setStatusFlight(pPassenger, statusFlight)
			   && Passenger_setCodigoVuelo(pPassenger, codigoVueloStr)))
			{
	                free(pPassenger);
	                pPassenger = NULL;
	        }
	    }
	    return pPassenger;
}

int Passenger_setId(Passenger* this,int id)
{

	int todoOk = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{

	int todoOk = 0;
		if(this != NULL && this != NULL && strlen(nombre) > 1 && strlen(nombre) < 50)
		{
			strcpy(this->nombre,nombre);
			todoOk = 1;
		}
		return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;
			if(this != NULL && this != NULL && strlen(apellido) > 1 && strlen(apellido) < 50)
			{
				strcpy(this->apellido,apellido);
				todoOk = 1;
			}
			return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;
				if(this != NULL && this != NULL && strlen(codigoVuelo) > 1 && strlen(codigoVuelo) < 15)
				{
					strcpy(this->codigoVuelo,codigoVuelo);
					todoOk = 1;
				}
				return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajeroo)
{
	int todoOk = 0;
					if(this != NULL && this != NULL && strlen(tipoPasajeroo) > 1 && strlen(tipoPasajeroo) < 15)
					{
						strcpy(this->tipoPasajero,tipoPasajeroo);
						todoOk = 1;
					}
					return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{

	int todoOk = 0;
	if(this != NULL && precio > 0 && precio < 1000000)
	{
		this->precio = precio;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getId(Passenger* this,int* id)
{
	int todoOk = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk = 0;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int todoOk = 0;
	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getStatusFlight(Passenger* this,char* statusFlight)
{
	int todoOk = 0;
	if(this != NULL && statusFlight != NULL)
	{
		strcpy(statusFlight,this->statusFlight);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setStatusFlight(Passenger* this,char* statusFlight)
{
	int todoOk = 0;
	if(this != NULL && this != NULL && strlen(statusFlight) > 1 && strlen(statusFlight) < 15)
	{
		strcpy(this->statusFlight,statusFlight);
		todoOk = 1;
	}
	return todoOk;
}

void Passenger_header(void)
{
	printf("---------------------------------------------------------------------------------------------------------------\n");
	printf(" ID     NOMBRE          APELLIDO        PRECIO          CODIGO VUELO            TIPO PASAJERO   ESTADO DE VUELO\n");
	printf("---------------------------------------------------------------------------------------------------------------\n");
}

int passenger_getMaxId(FILE* pFile)
{
	int maxId=0;
	Passenger* pAuxPassenger = NULL;
	int r=0;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50],var7[50];
	pFile = fopen("data.csv","r");
	if(pFile == NULL)
	{
		printf("Archivo nulo");
	}
	else
	{
	//lectura fantasma
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7);
	//printf("%s	%s	%s	%s	%s	%s	%s\n\n",var1,var2,var3,var4,var5,var6,var7);

	while(!feof(pFile))
	{

		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7);
		if(r<7)
		{
			break;
		}

		pAuxPassenger = Passenger_newParametros(var1,var2,var3,var4,var5,var6,var7);

		if(pAuxPassenger!=NULL)
		{
			maxId++;
		}
	}
	  fclose(pFile);
	}
	  return maxId;
}
