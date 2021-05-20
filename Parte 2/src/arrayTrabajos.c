/*
 * arrayTrabajos.c
 *
 *  Created on: 13 may. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include "arrayTrabajos.h"
#include "arrayBicicleta.h"
#include "UTN.h"
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

int idBicicleta[5]={25, 26, 27, 28, 29};
	int rodadoBicicleta[5]={25, 26, 27, 28, 29};
	char colorBicicleta[5][11]={"Azul", "Rojo", "Amarilla", "Negra", "Rosa"};
	char marcaBicicleta[5][26]={"Nodari", "Raleigh", "Spindola", "Fight", "Merida"};

eTrabajo pedirDatosTrabajo()
{
	eTrabajo miTrabajo;

	printf("Bicicletas disponibles:\n"
			"ID:25 ~ Marca: Nodari ~ Color: Azul\n"
			"ID:26 ~ Marca: Raleigh ~ Color: Rojo\n"
			"ID:27 ~ Marca: Spindola ~ Color: Amarilla\n"
			"ID:28 ~ Marca: Fight ~ Color: Negra\n"
			"ID:29 ~ Marca: Merida ~ Color: Rosa\n");
	utn_getNumero(&miTrabajo.idBicicleta, "Ingrese el ID de su bicicleta: ", "Error, ID incorrecto", 25, 29, 4);

	printf("Servicios disponibles:\n"
			"ID: 20000 - Limpieza\n"
			"ID: 20001 - Parche\n"
			"ID: 20002 - Centrado\n"
			"ID: 20003 - Cadena\n");
	utn_getNumero(&miTrabajo.idServicio, "Ingrese el ID de su servicio: ", "Error, ID incorrecto", 20000, 20003, 4);

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
	printf("ID Trabajo: %d ~ ID Servicio: %d ~ ID Bicicleta: %d ~ Dia: %d ~ Mes: %d ~ Anio: %d \n",
			unTrabajo.idTrabajo,
			unTrabajo.idServicio,
			unTrabajo.idBicicleta,
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
			mostrarUnTrabajo(listaTrabajo[i]);
			retorno=0;
		}
	}

	return retorno;
}

int modificarTrabajo(eTrabajo *listaTrabajo, int tam, eServicio *listaServicio, int tamServicio, eBicicleta *listaBicicleta, int tamBicicleta)
{
	int i;
	int j;
	int k;
	int retorno=-1;
	int idIngresado;
	int eleccion;

	if(listaTrabajo!=NULL && tam>0 && listaServicio!=NULL && tamServicio>0)
	{
		printf("-- MODIFICAR --\n"
				"\nTrabajos y servicios disponibles para modificar!\n");
		listadoTrabajosYServicios(listaTrabajo, tam, listaServicio, tamServicio, listaBicicleta, tamBicicleta);
		utn_getNumero(&idIngresado, "\nIngrese el ID del trabajo a modificar: ", "Error, ID incorrecto\n", 1, 10, 4);
		system("cls");
		for(i=0; i<tam; i++)
		{
			for(j=0; j<tamServicio; j++)
			{
				if(listaTrabajo[i].isEmpty==OCUPADO && listaServicio[j].isEmpty==OCUPADO)
				{
					for(k=0; k<tamBicicleta; k++)
					{
						if(idIngresado==listaTrabajo[i].idTrabajo && listaTrabajo[i].idServicio==listaServicio[j].idServicio && listaTrabajo[i].idBicicleta==listaBicicleta[k].idBicicleta)
						{
							printf("-- MODIFICAR --\n"
									"\nBicicleta y servicio seleccionado:\n"
									"\n-> ID: %d ~ Marca: %s ~ Rodado: %d ~ ID Servicio: %d ~ Descripcion servicio: %s ~ Precio: $%.2f\n"
									"\nQue desea modificar?\n"
									"1.Marca\n"
									"2.Servicio\n"
									"\nSeleccione una opcion: ",
									listaTrabajo[i].idTrabajo, listaBicicleta[k].marcaBicicleta, listaBicicleta[k].rodadoBicicleta,
									listaServicio[j].idServicio, listaServicio[j].descripcionServicio, listaServicio[j].precioServicio);
							scanf("%d", &eleccion);
							system("cls");
							switch(eleccion)
							{
								case 1:
									utn_getString(listaBicicleta[k].marcaBicicleta, "Ingrese la marca de la bicicleta: ", "Error! marca incorrecta\n", 21, 4);
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
			}
		}
	}

	return retorno;
}

int bajaTrabajo(eTrabajo *listaTrabajo, int tam)
{
	int i;
	int retorno=-1;
	int idIngresado;
	int eleccion;

	if(listaTrabajo!=NULL && tam>0)
	{
		printf("-- DAR DE BAJA --\n"
				"\nTrabajos disponibles para dar de baja!\n");
		mostrarListadoTrabajos(listaTrabajo, tam);
		utn_getNumero(&idIngresado, "\nIngrese el ID del trabajo a dar de baja: ", "Error, ID incorrecto\n", 1, 10, 4);
		for(i=0; i<tam; i++)
		{
			if(listaTrabajo[i].isEmpty==OCUPADO)
			{
				if(idIngresado==listaTrabajo[i].idTrabajo)
				{
					system("cls");
					printf("Seguro que desea dar de baja el trabajo ID Nro %d?\n"
							"1.SI\n"
							"2.NO\n", listaTrabajo[i].idTrabajo);
					utn_getNumero(&eleccion, "\nSelecione una opcion: ", "", 1, 2, 1);
					if(eleccion==1)
					{
						listaTrabajo[i].isEmpty=LIBRE;
						retorno=0;
						system("cls");
						break;
					}
					else
					{
						system("cls");
						printf("No se dio de baja el trabajo ID Nro %d!\n", listaTrabajo[i].idTrabajo);
					}

				}
			}
		}
	}

	return retorno;
}

int ordenarTrabajos(eTrabajo listaTrabajo[], int tam)
{
	int i;
	int j;
	int retorno=-1;
	eTrabajo auxTrabajo;

	if(listaTrabajo!=NULL && tam>0)
	{
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
		mostrarListadoTrabajos(listaTrabajo, tam);
		retorno=0;
	}

	return retorno;
}

int listadoTrabajosYServicios(eTrabajo *listaTrabajo, int tamTrabajo, eServicio *listaServicios, int tamServicio, eBicicleta *listaBicicleta, int tamBicicleta)
{
	int i;
	int j;
	int k;
	int retorno=-1;

	for(i=0; i<tamTrabajo; i++)
	{
		for(j=0; j<tamServicio; j++)
		{
			for(k=0; k<tamBicicleta; k++)
			{
				if(listaTrabajo[i].idServicio==listaServicios[j].idServicio && listaTrabajo[i].idBicicleta==listaBicicleta[k].idBicicleta)
				{
					printf("%d %s %d %d %s %.2f\n",
							listaTrabajo[i].idTrabajo,
							listaBicicleta[k].marcaBicicleta,
							listaBicicleta[k].rodadoBicicleta,
							listaTrabajo[i].idServicio,
							listaServicios[j].descripcionServicio,
							listaServicios[j].precioServicio);
					retorno=0;
				}
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

int ordenarTrabajosPorMarca(eTrabajo *listaTrabajo, int tamTrabajo, eServicio *listaServicios, int tamServicio, eBicicleta *listaBicicleta, int tamBicicleta)
{
	int i;
	int j;
	int retorno=-1;
	eBicicleta auxBicicleta;

	if(listaTrabajo!=NULL && tamTrabajo>0 && listaServicios!=NULL && tamServicio>0 && listaBicicleta!=NULL && tamBicicleta>0)
	{
		for(i=0; i<tamBicicleta-1; i++)
		{
			for(j=i+1; j<tamBicicleta; j++)
			{
				if(strcmp(listaBicicleta[i].marcaBicicleta, listaBicicleta[j].marcaBicicleta)>0)
				{
					auxBicicleta=listaBicicleta[i];
					listaBicicleta[i]=listaBicicleta[j];
					listaBicicleta[j]=auxBicicleta;
				}
			}
		}
		listadoTrabajosYServicios(listaTrabajo, tamTrabajo, listaServicios, tamServicio, listaBicicleta, tamBicicleta);
		retorno=0;
	}

	return retorno;
}

int bicicletasRojo(eTrabajo *listaTrabajo, int tamTrabajo, eBicicleta *listaBicicleta, int tamBicicleta)
{
	int i;
	int j;
	int retorno=-1;
	int contadorBicicleta=0;

	if(listaBicicleta!=NULL && tamBicicleta>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		for(i=0; i<tamBicicleta; i++)
		{
			for(j=0; j<tamTrabajo; j++)
			{
				if(listaBicicleta[i].idBicicleta==26 && listaTrabajo[j].idBicicleta==listaBicicleta[i].idBicicleta)
				{
					contadorBicicleta++;
					retorno=0;
				}
			}
		}
		printf("La cantidad de bicicletas color rojo trabajadas son: %d\n", contadorBicicleta);
	}

	return retorno;
}

int listadoServiciosBicis(eServicio *listaServicio, int tamServicio, eBicicleta *listaBicicleta, int tamBicicleta, eTrabajo *listaTrabajo, int tamTrabajo)
{
	int i;
	int j;
	int k;
	int retorno=-1;

	if(listaServicio!=NULL && tamServicio>0 && listaBicicleta!=NULL && tamBicicleta>0 && listaTrabajo!=NULL && tamTrabajo>0)
	{
		for(i=0; i<tamServicio; i++)
		{
			for(j=0; j<tamBicicleta; j++)
			{
				for(k=0; k<tamTrabajo; k++)
				{
					if(listaServicio[i].idServicio==listaTrabajo[k].idServicio && listaBicicleta[j].idBicicleta==listaTrabajo[k].idBicicleta)
					{
						printf("ID Servicio: %d ~ Descripcion: %s ~ Marca bicicleta: %s ~ Rodado: %d ~ Color: %s\n", listaServicio[i].idServicio, listaServicio[i].descripcionServicio,
								listaBicicleta[j].marcaBicicleta,
								listaBicicleta[j].rodadoBicicleta,
								listaBicicleta[j].colorBicicleta);
					}
				}
			}
		}
		retorno=0;
	}

	return retorno;
}
