/*
 * arrayServicio.c
 *
 *  Created on: 13 may. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "arrayTrabajos.h"

#define LIBRE 0
#define OCUPADO 1

void hardcodeoServicios(eServicio *listaServicio, int tamServicio)
{
	int i;
	int idServicio[4]={20000, 20001, 20002, 20003};
	char descripcionServicio[4][11]={"Limpieza", "Parche", "Centrado", "Cadena"};
	float precioServicio[4]={250, 300, 400, 350};

	for(i=0; i<tamServicio; i++)
	{
		listaServicio[i].idServicio=idServicio[i];
		strcpy(listaServicio[i].descripcionServicio, descripcionServicio[i]);
		listaServicio[i].precioServicio=precioServicio[i];
		listaServicio[i].isEmpty=OCUPADO;
	}
}

int inicializarServicios(eServicio *listaServicio, int tamServicio)
{
	int i;
	int retorno=-1;

	for(i=0; i<tamServicio; i++)
	{
		listaServicio[i].isEmpty=LIBRE;
		retorno=0;
	}

	return retorno;
}

int listadoServicios(eServicio *listaServicios, int tamServicio)
{
	int i;
	int retorno=-1;

	for(i=0; i<tamServicio; i++)
	{
		printf("ID: %d ~ DESCRIPCION: %s ~ PRECIO: $%.2f\n",
				listaServicios[i].idServicio,
				listaServicios[i].descripcionServicio,
				listaServicios[i].precioServicio);
		retorno=0;
	}

	return retorno;
}
