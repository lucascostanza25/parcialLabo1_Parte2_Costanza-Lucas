/*
Pacial 1 - Laboratorio de programacion
Costanza, Lucas
Parte 2
Division 1B
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayTrabajos.h"
#include "arrayServicio.h"
#include "arrayBicicleta.h"
#define T 5
#define TS 4
#define TB 5
#define LIBRE 0
#define OCUPADO 1

int main(void) {
	setbuf(stdout, NULL);
	eTrabajo listaTrabajo[T];
	eServicio listaServicio[TS];
	eBicicleta listaBicicleta[TB];
	int menu;
	int res;
	int idTrabajo=0;
	int flagMenu=0;
	int menuInformes;
	int menuBaja;
	inicializarTrabajo(listaTrabajo, T);
	inicializarServicios(listaServicio, TS);
	hardcodeoServicios(listaServicio, TS);
	inicializarBicicleta(listaBicicleta, TB);
	hardcodeoBicicleta(listaBicicleta, TB);

	do
	{
		printf("-- ABM TRABAJOS BICICLETA --\n"
				"1.Alta trabajo\n"
				"2.Modificar trabajo\n"
				"3.Baja trabajo\n"
				"4.Informar\n"
				"Seleccione una opcion: ");
		scanf("%d", &menu);
		system("cls");
		switch(menu)
		{
			case 1:
				res=altaTrabajo(listaTrabajo, T, &idTrabajo);
				if(res!=-1)
				{
					system("cls");
					printf("Trabajo dado de alta exitosamente!\n");
				}
				else
				{
					printf("No hay mas espacio para listar trabajo!\n");
				}
				flagMenu=1;
				system("Pause");
			break;

			case 2:
				if(flagMenu!=0)
				{
					if(modificarTrabajo(listaTrabajo, T, listaServicio, TS, listaBicicleta, TB)!=-1)
					{
						printf("Trabajo modificado con exito!\n");
					}
					else
					{
						printf("Se cancelo la modificacion del trabajo!\n");
					}
				}
				else
				{
					printf("Primero ingrese un trabajo!\n");
				}
				system("pause");
			break;

			case 3:
				if(flagMenu!=0)
				{
					printf("-- DAR DE BAJA --\n"
							"1.Dar de baja trabajo\n"
							"2.Dar de baja servicio\n"
							"3.Dar de baja bicicleta\n");
					scanf("%d", &menuBaja);
					system("cls");
					switch(menuBaja)
					{
						case 1:
							if(bajaTrabajo(listaTrabajo, T)!=-1)
							{
								printf("Trabajo dado de baja con exito!\n");
							}
							else
							{
								printf("Se cancelo la baja del trabajo!\n");
							}
						break;

						case 2:
							if(darDeBajaServicio(listaServicio, TS)!=-1)
							{
								printf("Servicio dado de baja con exito!\n");
							}
							else
							{
								printf("Se cancelo la baja del servicio!\n");
							}
						break;

						case 3:
							if(bajaBicicleta(listaBicicleta, TB)!=-1)
							{
								printf("Bicicleta dada de baja con exito!\n");
							}
							else
							{
								printf("Se cancelo la baja de la bicicleta!\n");
							}
						break;
					}
				}
				else
				{
					printf("Primero ingrese un trabajo!\n");
				}
				system("pause");
			break;

			case 4:
				if(flagMenu!=0)
				{
					printf("-- INFORMAR --\n"
							"1.Mostrar listado de trabajos\n"
							"2.Mostrar listado de servicios\n"
							"3.Mostrar listado de trabajos con sus servicios\n"
							"4.Total gastado\n"
							"5.Listado de trabajos ordenados por marca\n"
							"6.Cantidad de bicicletas color rojo trabajadas\n"
							"7.Listado de servicios y bicicletas\n"
							"Seleccione una opcion: ");
					scanf("%d", &menuInformes);
					system("cls");
					switch(menuInformes)
					{
						case 1:
							if(ordenarTrabajos(listaTrabajo, T)!=-1)
							{
								printf("\nListado de trabajos ordenados por anio!\n");
							}
							else
							{
								printf("No hay trabajos que mostrar!\n");
							}
						break;

						case 2:
							if(listadoServicios(listaServicio, TS)!=-1)
							{
								printf("\nLista de servicios!\n");
							}
							else
							{
								printf("No hay servicios disponibles para mostrar!\n");
							}
						break;

						case 3:
							if(listadoTrabajosYServicios(listaTrabajo, T, listaServicio, TS, listaBicicleta, TB)!=-1)
							{
								printf("\nListado de trabajos con sus servicios!\n");
							}
							else
							{
								printf("No hay trabajos y servicios para mostrar!\n");
							}
						break;

						case 4:
							if(sumaPrecios(listaServicio, TS, listaTrabajo, T)!=-1)
							{
								printf("\nSuma de los servicios prestados!\n");
							}
							else
							{
								printf("\nNo se pudo completar la suma!\n");
							}
						break;

						case 5:
							if(ordenarTrabajosPorMarca(listaTrabajo, T, listaServicio, TS, listaBicicleta, TB)!=-1)
							{
								printf("\nTrabajos ordenados por marca!\n");
							}
							else
							{
								printf("No se pudo completar el ordenamiento!\n");
							}
						break;

						case 6:
							if(bicicletasRojo(listaTrabajo, T, listaBicicleta, TB)!=-1)
							{
								printf("\nCantidad de bicicletas rojas trabajadas!\n");
							}
							else
							{
								printf("\nNo se trabajaron bicicletas rojas!\n");
							}
						break;

						case 7:
							if(listadoServiciosBicis(listaServicio, TS, listaBicicleta, TB, listaTrabajo, T)!=-1)
							{
								printf("\nListado de servicios con sus bicicletas ingresadas!\n");
							}
							else
							{
								printf("No se puede mostrar el listado!\n");
							}
						break;
					}
				}
				else
				{
					printf("Primero ingrese un trabajo!\n");
				}
				system("pause");
			break;
		}
		system("cls");
	}while(menu!=0);

	return EXIT_SUCCESS;
}
