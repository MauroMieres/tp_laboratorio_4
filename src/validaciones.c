/*
 * validaciones.c
 *
 *  Created on: 5 jun. 2022
 *      Author: knofl
 */

#include "validaciones.h"

int validateFlightCode(char flyCode[])
{
	int ok=0;

	if(strlen(flyCode)==9)
	{
		ok=1;
	}
	return ok;
}

int toupperString(char cadena[])
{
	int ok=0;

	if(cadena != NULL)
	{
		ok=1;
		for (int indice = 0; cadena[indice] != '\0'; ++indice)
			{
				cadena[indice] = toupper(cadena[indice]);
			}
	}
	return ok;
}

int validateTypePassenger(int num)
{
	int ok;
	if(num!=-1&&num!=0&&num!=1)
	{
		printf("Error, ingrese una opcion correcta.\n");
		ok=0;
	}
	else
	{
		ok=1;
	}
	return ok;
}

int validateFlightStatus(int num)
{
	int ok;
		if(num!=0&&num!=1)
		{
			printf("Error, ingrese una opcion correcta.\n");
			ok=0;
		}
		else
		{
			ok=1;
		}
		return ok;
}

int validateNameOrLastName(char nombre[])
{
	 int i;
	    for(i=0 ; i<strlen(nombre); i++)
	    {
	        if(!((nombre[i]>=65 && nombre[i]<=90 )||( nombre[i]>=97 && nombre[i]<=122)))
	        {
	            return 0;
	        }
	    }
	    return 1;
}


