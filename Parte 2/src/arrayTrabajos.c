/*
 * arrayTrabajos.c
 *
 *  Created on: 13 may. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include "arrayTrabajos.h"
#include "UTN.h"
#define T 5
#define TS 4
#define LIBRE 0
#define OCUPADO 1

void inicializarTrabajo(eTrabajo listaTrabajo[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		listaTrabajo[i].isEmpty=LIBRE;
	}
}

eTrabajo pedirDatosTrabajo()
{
	eTrabajo miTrabajo;

	utn_getString(miTrabajo.marcaBicicleta, "Ingrese la marca de la bicicleta: ", "Error! marca incorrecta\n", 21, 4);

	utn_getNumero(&miTrabajo.rodadoBicicleta, "Ingrese el rodado de su bicicleta: ", "Error, rodado incorrecto\n", 1, 29, 4);

	utn_getNumero(&miTrabajo.idServicio, "Ingrese el ID de su servicio: ", "Error, ID incorrecto", 20000, 20020, 4);

	utn_getNumero(&miTrabajo.fechaTrabajo.dia, "Ingrese el dia del servicio: ", "Error, dia incorrecto", 1, 31, 4);

	utn_getNumero(&miTrabajo.fechaTrabajo.mes, "Ingrese el mes del servicio: ", "Error, mes incorrecto", 1, 12, 4);

	utn_getNumero(&miTrabajo.fechaTrabajo.anio, "Ingrese el anio del servicio: ", "Error, anio incorrecto", 2010, 2021, 4);

	miTrabajo.isEmpty=OCUPADO;

	return miTrabajo;
}

int altaTrabajo(eTrabajo listaTrabajo[], int tam, int *idTrabajo)
{
	int i;
	i=buscarTrabajoLibre(listaTrabajo, tam);

	if(i!=-1)
	{
		listaTrabajo[i]=pedirDatosTrabajo();
		listaTrabajo[i].idTrabajo=*idTrabajo+1;
		*idTrabajo=listaTrabajo[i].idTrabajo;
	}

	return i;
}

int buscarTrabajoLibre(eTrabajo listaTrabajo[], int tam)
{
	int i;
	int retorno;

	for(i=0; i<tam; i++)
	{
		if(listaTrabajo[i].isEmpty==LIBRE)
		{
			retorno=i;
			break;
		}
	}

	return retorno;
}

void mostrarUnTrabajo(eTrabajo unTrabajo)
{
	printf("%d %s %d %d %d %d %d \n",
			unTrabajo.idTrabajo,
			unTrabajo.marcaBicicleta,
			unTrabajo.rodadoBicicleta,
			unTrabajo.idServicio,
			unTrabajo.fechaTrabajo.dia,
			unTrabajo.fechaTrabajo.mes,
			unTrabajo.fechaTrabajo.anio);
}

int mostrarListadoTrabajos(eTrabajo listaTrabajo[], int tam)
{
	int i;
	int retorno=-1;

	for(i=0; i<tam; i++)
	{
		if(listaTrabajo[i].isEmpty==OCUPADO)
		{
			ordenarTrabajos(listaTrabajo, tam);
			mostrarUnTrabajo(listaTrabajo[i]);
			retorno=0;
		}
	}

	return retorno;
}

int modificarTrabajo(eTrabajo listaTrabajo[], int tam, eServicio listaServicio[], int tamServicio)
{
	int i;
	int j;
	int retorno=-1;
	int idIngresado;
	int eleccion;

	for(i=0; i<tam; i++)
	{
		for(j=0; j<tamServicio; j++)
		{
			if(listaServicio[i].isEmpty==OCUPADO && listaTrabajo[j].isEmpty==OCUPADO)
			{
				printf("Trabajos y servicios disponibles para modificar!\n");
				listadoTrabajosYServicios(listaTrabajo, tam, listaServicio, tamServicio);
				utn_getNumero(&idIngresado, "\nIngrese el ID del trabajo a modificar: ", "Error, ID incorrecto\n", 1, 10, 4);
				system("cls");
				if(idIngresado==listaTrabajo[i].idTrabajo && listaTrabajo[i].idServicio==listaServicio[j].idServicio)
				{
					printf("-- MODIFICAR --\n"
							"1.Marca\n"
							"2.Servicio\n"
							"\nBicicleta y servicio seleccionado:\n"
							"\n-> ID: %d ~ Marca: %s ~ Rodado: %d ~ ID Servicio: %d ~ Descripcion servicio: %s ~ Precio: $%.2f\n"
							"\nSeleccione una opcion: ",
							listaTrabajo[i].idTrabajo, listaTrabajo[i].marcaBicicleta, listaTrabajo[i].rodadoBicicleta,
							listaServicio[j].idServicio, listaServicio[j].descripcionServicio, listaServicio[j].precioServicio);
					scanf("%d", &eleccion);
					system("cls");
					switch(eleccion)
					{
						case 1:
							utn_getString(listaTrabajo[i].marcaBicicleta, "Ingrese la marca de la bicicleta: ", "Error! marca incorrecta\n", 21, 4);
							retorno=0;
						break;

						case 2:
							utn_getString(listaServicio[j].descripcionServicio, "Ingrese la descripcion del servicio: ", "Error! servicio incorrecto\n", 21, 4);
							retorno=0;
						break;
					}
				}
			}
		}
		break;
	}

	return retorno;
}

int bajaTrabajo(eTrabajo listaTrabajo[], int tam)
{
	int i;
	int retorno=-1;
	int idIngresado;


	for(i=0; i<tam; i++)
	{
		printf("Trabajos disponibles para dar de baja!\n");
		mostrarListadoTrabajos(listaTrabajo, tam);
		utn_getNumero(&idIngresado, "Ingrese el ID del trabajo a modificar: ", "Error, ID incorrecto\n", 1, 10, 4);
		if(idIngresado==listaTrabajo[i].idTrabajo)
		{
			listaTrabajo[i].isEmpty=LIBRE;
			retorno=0;
			break;
		}
	}

	return retorno;
}

void ordenarTrabajos(eTrabajo listaTrabajo[], int tam)
{
	int i;
	int j;
	eTrabajo auxTrabajo;

	for(i=0; i<tam-1; i++)
	{
		for(j=i+1; j<tam; j++)
		{
			if(listaTrabajo[i].fechaTrabajo.anio < listaTrabajo[j].fechaTrabajo.anio)
			{
				auxTrabajo=listaTrabajo[i];
				listaTrabajo[i]=listaTrabajo[j];
				listaTrabajo[j]=auxTrabajo;
			}
		}
	}
}

int listadoTrabajosYServicios(eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio)
{
	int i;
	int j;
	int retorno=-1;

	for(i=0; i<tamTrabajo; i++)
	{
		for(j=0; j<tamServicio; j++)
		{
			if(listaTrabajo[i].idServicio==listaServicios[j].idServicio)
			{
				printf("%d %s %d %d %s %.2f\n",
						listaTrabajo[i].idTrabajo,
						listaTrabajo[i].marcaBicicleta,
						listaTrabajo[i].rodadoBicicleta,
						listaTrabajo[i].idServicio,
						listaServicios[j].descripcionServicio,
						listaServicios[j].precioServicio);
				retorno=0;
			}
		}
	}

	return retorno;
}

int sumaPrecios(eServicio *listaServicios, int tamServicio, eTrabajo *listaTrabajo, int tamTrabajo)
{
	int i;
	int j;
	int retorno=-1;
	float acumuladorPrecio=0;

	if(listaServicios!=NULL && tamServicio>0)
	{
		for(i=0; i<tamServicio; i++)
		{
			for(j=0; j<tamTrabajo; j++)
			{
				if(listaTrabajo[j].idServicio==listaServicios[i].idServicio)
				{
					acumuladorPrecio+=listaServicios[i].precioServicio;
					retorno=0;
				}
			}
		}
	}

	printf("La suma de los servicios prestados es: $%.2f", acumuladorPrecio);

	return retorno;
}
