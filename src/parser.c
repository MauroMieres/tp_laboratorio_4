#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

//

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk=-1;
	Passenger* pAuxPassenger = NULL;
	int r=0;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50],var7[50];
	//pFile = fopen("data.csv","r");
	if(pFile == NULL)
	{
		printf("Archivo nulo");
	//return -1;
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
			ll_add(pArrayListPassenger, pAuxPassenger);
			todoOk=1;
		}
	}
	 // fclose(pFile);
	}
	  return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int cantidad; //Cantidad leida
	Passenger* pPassenger;

	if(pFile != NULL)
	{
		do
		{
			pPassenger = Passenger_new();
			cantidad = fread(pPassenger,sizeof(Passenger),1,pFile);
			if(pPassenger != NULL && cantidad == 1)
			{
				ll_add(pArrayListPassenger,pPassenger);
				todoOk = 1;
			}
		}
		while(!feof(pFile));
	}
	return todoOk;
}
