/*
 * menus.c
 *
 *  Created on: 2 jun. 2022
 *      Author: knofl
 */

#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int menuOpcion()
{
	printf("  				 *** ABM PASAJEROS ***\n\n");
	int opcion;
	printf("1)CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO DATA.CSV (Modo Texto)\n");
	printf("2)CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO DATA.BIN (Modo Bin)\n");
	printf("3)ALTA PASAJERO\n");
	printf("4)MODIFICAR DATOS DEL PASAJERO\n");
	printf("5)BAJA DE PASAJERO \n");
	printf("6)LISTAR PASAJEROS \n");
	printf("7)ORDENAR PASAJEROS \n");
	printf("8)GUARDAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO DATA.CSV (Modo Texto) \n");
	printf("9)GUARDAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO DATA.BIN (Modo Bin) \n");
	printf("10)SALIR\n");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
