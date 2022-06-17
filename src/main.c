#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menus.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int flagSave=0;
    int contadorPasajeros=0;
    char seguir='s';
    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
        switch(option=menuOpcion())
        {

        case 1:
        			controller_loadFromText("data.csv",listaPasajeros);
        			contadorPasajeros = ll_len(listaPasajeros);
        			break;
        		case 2:
        			controller_loadFromBinary("data.bin",listaPasajeros);
        			contadorPasajeros = ll_len(listaPasajeros);
        			break;
        		case 3:
        			controller_addPassenger(listaPasajeros,"data.csv");
        			contadorPasajeros = ll_len(listaPasajeros);
        			break;
        		case 4:
        			if(contadorPasajeros>0)
        			{
        				controller_editPassenger(listaPasajeros);
        			}
        			else
        			{
        				printf("No hay pasajeros cargados en el sistema\n");
        			}
        			break;
        		case 5:
        			if(contadorPasajeros>0)
        			{
        			controller_removePassenger(listaPasajeros);
        			}
        			else
        			{
        				printf("No hay pasajeros cargados en el sistema\n");
        			}
        			break;
        		case 6:
        			if(contadorPasajeros>0)
        			{
        				controller_ListPassenger(listaPasajeros);
        			}
        			else
					{
						printf("No hay pasajeros cargados en el sistema\n");
					}
        			break;
        		case 7:
        			if(contadorPasajeros>0)
        			{
        				controller_sortPassenger(listaPasajeros);
        			}
        			else
					{
						printf("No hay pasajeros cargados en el sistema\n");
					}
        			break;
        		case 8:
        			if(contadorPasajeros<=0)
        			{
        				printf("No hay nada para guardar!\n");
        			}
        			else
        			{
        				controller_saveAsText("data.csv", listaPasajeros);
        				printf("Archivo guardado\n");
        				flagSave=1;
        			}
        			break;
        		case 9:
        			if(contadorPasajeros<=0)
        			{
        				printf("No hay nada para guardar!\n");
        			}
        			else
        			{
        				controller_saveAsBinary("data.bin", listaPasajeros);
						printf("Archivo guardado\n");
						flagSave=1;
        			}
        			break;
        		case 10:
        			if(!flagSave)
        			{
        				printf("No se puede salir sin guardar! \n");
        			}
        			else
        			{
        				printf("Salir.\n");
        				seguir='n';
        			}
        			break;
        		default:
        			printf("Opcion invalida!\n");
        			break;
        }
    }while(seguir=='s');
   ll_deleteLinkedList(listaPasajeros);
    return 0;
}

