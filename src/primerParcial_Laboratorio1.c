/*
Pacial 1 - Laboratorio de programacion
Costanza, Lucas
Parte 2
Division 1B
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayTrabajos.h"
#define T 5
#define TS 4
#define LIBRE 0
#define OCUPADO 1

//Declaracion

int main(void) {
	setbuf(stdout, NULL);
	eTrabajo listaTrabajo[T];
	eServicio listaServicio[TS]={{20000, "Limpieza", 250, OCUPADO},
								{20001, "Parche", 300, OCUPADO},
								{20002, "Centrado", 400, OCUPADO},
								{20003, "Cadena", 350, OCUPADO}};
	int menu;
	int res;
	int idTrabajo=0;
	int flagMenu=0;
	int menuInformes;
	inicializarTrabajo(listaTrabajo, T);

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
					if(modificarTrabajo(listaTrabajo, T, listaServicio, TS)!=-1)
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
					if(bajaTrabajo(listaTrabajo, T)!=-1)
					{
						printf("Trabajo dado de baja con exito!\n");
					}
					else
					{
						printf("Se cancelo la baja del trabajo!\n");
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
							"Seleccione una opcion: ");
					scanf("%d", &menuInformes);
					system("cls");
					switch(menuInformes)
					{
						case 1:
							if(mostrarListadoTrabajos(listaTrabajo, T)!=-1)
							{
								printf("Listado de trabajos ordenados por año!\n");
							}
							else
							{
								printf("No hay trabajos que mostrar!\n");
							}
						break;

						case 2:
							if(listadoServicios(listaServicio, TS)!=-1)
							{
								printf("Lista de servicios!\n");
							}
							else
							{
								printf("No hay servicios disponibles para mostrar!\n");
							}
						break;

						case 3:
							if(listadoTrabajosYServicios(listaTrabajo, T, listaServicio, TS)!=-1)
							{
								printf("\nListado de trabajos con sus servicios!\n");
							}
							else
							{
								printf("No hay trabajos y servicios para mostrar!\n");
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
