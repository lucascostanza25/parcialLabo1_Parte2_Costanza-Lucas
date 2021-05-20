/*
 * arrayBicicleta.c
 *
 *  Created on: 20 may. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "arrayTrabajos.h"
#include "arrayServicio.h"
#include "UTN.h"

#define LIBRE 0
#define OCUPADO 1


void hardcodeoBicicleta(eBicicleta *listaBicicleta, int tamBicicleta)
{
	int i;
	int idBicicleta[5]={25, 26, 27, 28, 29};
	int rodadoBicicleta[5]={25, 26, 27, 28, 29};
	char colorBicicleta[5][11]={"Azul", "Rojo", "Amarilla", "Negra", "Rosa"};
	char marcaBicicleta[5][26]={"Nodari", "Raleigh", "Spindola", "Fight", "Merida"};

	for(i=0; i<tamBicicleta; i++)
	{
		listaBicicleta[i].idBicicleta=idBicicleta[i];
		strcpy(listaBicicleta[i].colorBicicleta, colorBicicleta[i]);
		listaBicicleta[i].rodadoBicicleta=rodadoBicicleta[i];
		listaBicicleta[i].isEmpty=OCUPADO;
		strcpy(listaBicicleta[i].marcaBicicleta, marcaBicicleta[i]);
	}
}

int inicializarBicicleta(eBicicleta *listaBicicleta, int tamBicicleta)
{
	int i;
	int retorno=-1;

	for(i=0; i<tamBicicleta; i++)
	{
		listaBicicleta[i].isEmpty=LIBRE;
		retorno=0;
	}

	return retorno;
}

int listadoBicicletas(eBicicleta *listaBicicleta, int tamBicicleta)
{
	int i;
	int retorno=-1;

	for(i=0; i<tamBicicleta; i++)
	{
		if(listaBicicleta[i].isEmpty==OCUPADO)
		{
			printf("ID: %d ~ MARCA: %s ~ COLOR: %s\n",
					listaBicicleta[i].idBicicleta,
					listaBicicleta[i].marcaBicicleta,
					listaBicicleta[i].colorBicicleta);
			retorno=0;
		}
	}

	return retorno;
}

int bajaBicicleta(eBicicleta *listaBicicleta, int tamBicicleta)
{
	int i;
	int retorno=-1;
	int idIngresado;
	int eleccion;

	if(listaBicicleta!=NULL && tamBicicleta>0)
	{
		printf("-- DAR DE BAJA --\n"
				"\nBicicletas disponibles para dar de baja!\n");
		listadoBicicletas(listaBicicleta, tamBicicleta);
		utn_getNumero(&idIngresado, "\nIngrese el ID de la bicicleta a dar de baja: ", "Error, ID incorrecto\n", 20000, 20003, 4);
		for(i=0; i<tamBicicleta; i++)
		{
			if(listaBicicleta[i].isEmpty==OCUPADO)
			{
				if(idIngresado==listaBicicleta[i].idBicicleta)
				{
					system("cls");
					printf("Seguro que desea dar de baja la bicicleta ID Nro %d?\n"
							"1.SI\n"
							"2.NO\n", listaBicicleta[i].idBicicleta);
					utn_getNumero(&eleccion, "\nSelecione una opcion: ", "", 1, 2, 1);
					if(eleccion==1)
					{
						listaBicicleta[i].isEmpty=LIBRE;
						retorno=0;
						system("cls");
						break;
					}
					else
					{
						system("cls");
						printf("No se dio de baja la bicicleta ID Nro %d!\n", listaBicicleta[i].idBicicleta);
					}

				}
			}
		}
	}

	return retorno;
}
