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
#include "arrayBicicleta.h"
#include "UTN.h"

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

int darDeBajaServicio(eServicio *listaServicio, int tamServicio)
{
	int i;
	int retorno=-1;
	int idIngresado;
	int eleccion;

	if(listaServicio!=NULL && tamServicio>0)
	{
		printf("-- DAR DE BAJA --\n"
				"\nServicios disponibles para dar de baja!\n");
		listadoServicios(listaServicio, tamServicio);
		utn_getNumero(&idIngresado, "\nIngrese el ID del servicio a dar de baja: ", "Error, ID incorrecto\n", 20000, 20003, 4);
		for(i=0; i<tamServicio; i++)
		{
			if(listaServicio[i].isEmpty==OCUPADO)
			{
				if(idIngresado==listaServicio[i].idServicio)
				{
					system("cls");
					printf("Seguro que desea dar de baja el servicio ID Nro %d?\n"
							"1.SI\n"
							"2.NO\n", listaServicio[i].idServicio);
					utn_getNumero(&eleccion, "\nSelecione una opcion: ", "", 1, 2, 1);
					if(eleccion==1)
					{
						listaServicio[i].isEmpty=LIBRE;
						retorno=0;
						system("cls");
						break;
					}
					else
					{
						system("cls");
						printf("No se dio de baja el servicio ID Nro %d!\n", listaServicio[i].idServicio);
					}

				}
			}
		}
	}

	return retorno;
}

int listadoServicios(eServicio *listaServicio, int tamServicio)
{
	int i;
	int retorno=-1;

	for(i=0; i<tamServicio; i++)
	{
		if(listaServicio[i].isEmpty==OCUPADO)
		{
			printf("ID: %d ~ DESCRIPCION: %s ~ PRECIO: $%.2f\n",
					listaServicio[i].idServicio,
					listaServicio[i].descripcionServicio,
					listaServicio[i].precioServicio);
			retorno=0;
		}
	}

	return retorno;
}

int servicioMasTrabajos(eServicio *listaServicio, int tamServicio)
{
	int i;
	int j;
	int retorno=-1;
	//int masServicios;
	int contadorUno=0;
	int contadorDos=0;

	for(i=0; i<tamServicio-1; i++)
	{
		for(j=i+1; j<tamServicio; j++)
		{
			switch(listaServicio[i].idServicio)
			{
				case 20000:
					contadorUno++;
				break;

				case 20001:
					contadorDos++;
				break;
			}
			if(contadorUno>contadorDos)
			{

			}
		}
	}

	return retorno;
}
