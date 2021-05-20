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

int servicioMasCaro(eServicio *listaServicios, int tamServicio)
{
	int i;
	int j;
	int retorno=-1;
	int flagPrecio=0;
	float masCaro;
	char descripcionCaro[11];

	for(i=0; i<tamServicio-1; i++)
	{
		for(j=i+1; j<tamServicio; j++)
		{
			if(listaServicios[i].precioServicio > listaServicios[j].precioServicio || flagPrecio==0)
			{
				masCaro=listaServicios[i].precioServicio;
				strcpy(descripcionCaro, listaServicios[i].descripcionServicio);
				flagPrecio=1;
			}
		}
	}

	printf("El servicio mas caro es %s, con un precio de %.2f", descripcionCaro, masCaro);

	return retorno;
}
