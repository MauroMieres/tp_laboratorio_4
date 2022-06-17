/*
 * utn.c
 *
 *  Created on: 5 jun. 2022
 *      Author: knofl
 */

#include "utn.h"

int getCaracter(char* caracter, char mensaje[], char mensajeError[], char caracter1, char caracter2)
{
	int ok = 0;
	char caracterIngresado;

	if(caracter != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado = toupper(caracterIngresado);

		while(caracterIngresado != caracter1 && caracterIngresado != caracter2)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado = toupper(caracterIngresado);
		}
		*caracter=caracterIngresado;
		ok=1;
	}
	return ok;
}

int getString(char string[],char mensaje[],char mensajeError[],int tamString)
{
	int ok=0;
	char cadena[100];
	if(string != NULL && mensaje != NULL && mensajeError != NULL && tamString > 0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		gets(cadena);

		while(!validateSringLenght(cadena, mensajeError, tamString))
		{
			fflush(stdin);
			gets(cadena);
		}
		ok=1;
	}
	strcpy(string,cadena);
	return ok;
}

int validateSringLenght(char *string,char mensajeError[],int tamString)
{
	int ok=0;

	if(string !=NULL && mensajeError != NULL)
	{
		if(strlen(string)>tamString)
		{
			puts(mensajeError);
		}
		else
		{
			ok=1;
		}
	}
	return ok;
}

int validateAlphabeticCharacters(char cadena[])
{
	 int i;
	    for(i=0 ; i<strlen(cadena); i++)
	    {
	        if(!((cadena[i]>=65 && cadena[i]<=90 )||( cadena[i]>=97 && cadena[i]<=122)))
	        {
	        	printf("Error, se ingresaron caracteres invalidos: \n");
	            return 0;
	        }
	    }
	    return 1;
}

int getAlphabetic_Characters_String(char string[],char mensaje[],char mensajeError[],int tamString)
{
	int ok=0;
	char cadena[tamString];
	if(string != NULL && mensaje != NULL && mensajeError != NULL && tamString > 0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		gets(cadena);

		while(!validateSringLenght(cadena, mensajeError, tamString)||!(validateAlphabeticCharacters(cadena)))
		{
			fflush(stdin);
			gets(cadena);
		}


		ok=1;
	}
	strcpy(string,cadena);
	return ok;
}

int changeStringFormat(char cadena[])
{
	int ok=0;

	if(cadena != NULL)
	{
		ok=1;
		for (int indice = 0; cadena[indice] != '\0'; ++indice)
			{
				cadena[indice] = tolower(cadena[indice]);
			}
		cadena[0]= toupper(cadena[0]);
	}
	return ok;
}

int validateFloat(char numeroCad[])
{
	int banderaPunto=0;
    int ok=0;
    for(int i=0; i<strlen(numeroCad); i++)
    {
        if(!(isdigit(numeroCad[i])))
        {
        	if(numeroCad[i]=='.'&&banderaPunto==0)
        	{
        		banderaPunto=1;
        	}
        	else
        	{
        		//printf("Se ingreso un numero invalido\n");
        		return ok;
        	}
        }
    }
    ok=1;

    return ok;
}

int getFloat(float* numero,char mensaje[],char mensajeError[])
{
	int ok=0;
	char auxCad[51];

	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		puts(mensaje);
		fflush(stdin);
		gets(auxCad);
		while(!validateFloat(auxCad))
		{
			puts(mensajeError);
			fflush(stdin);
			gets(auxCad);
		}
		*numero = atof(auxCad);
		ok=1;
	}
	return ok;
}

int getInt(int* numero,char mensaje[],char mensajeError[])
{
	int ok=0;
	char auxCad[51];

	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		puts(mensaje);
		fflush(stdin);
		gets(auxCad);
		while(!validateInteger(auxCad))
		{
			puts(mensajeError);
			fflush(stdin);
			gets(auxCad);
		}
		*numero = atoi(auxCad);
		ok=1;
	}
		return ok;
}

int validateInteger(char numero[])
{
	int banderaSignoMenos=0;
	    for(int i=0; i<strlen(numero); i++)
	    {
	        if(!(isdigit(numero[i])))
	        {
	        	if(numero[i]=='-'&&banderaSignoMenos==0)
	        	{
	        		banderaSignoMenos++;
	        	}
	        	else
	        	{
	        		return 0;
	        	}
	        }
	    }
	    return 1;
}

char *randstring(size_t length)
{

    static char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char *randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {
            for (int n = 0;n < length;n++) {
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }
            randomString[length] = '\0';
        }
    }

    return randomString;
}

int getFloat2(float* numero, char* mensaje, char* mensajeError, float min, float max)
{
	 int retorno = -1;
	 float numeroIngresado;

	    if(numero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	    {
	        printf("%s", mensaje);
	        fflush(stdin);
	        scanf("%f", &numeroIngresado);

	        while(numeroIngresado < min || numeroIngresado > max)
	        {
	            printf("%s", mensajeError);
	            fflush(stdin);
	            scanf("%f", &numeroIngresado);
	        }
	        *numero = numeroIngresado;
	        retorno = 0;
	    }
	    return retorno;
}

int getInt2(int* numero, char* mensaje, char* mensajeError, int min, int max)
{
    int retorno = -1;
    int numeroIngresado;

    if(numero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", &numeroIngresado);
        }

        *numero = numeroIngresado;
        retorno = 0;
    }

    return retorno;
}
