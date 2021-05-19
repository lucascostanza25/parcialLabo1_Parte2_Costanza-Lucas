/*
 * arrayServicio.h
 *
 *  Created on: 13 may. 2021
 *      Author: Lucas
 */

#ifndef ARRAYSERVICIO_H_
#define ARRAYSERVICIO_H_
#include "arrayTrabajos.h"

typedef struct
{
	int idServicio;
	char descripcionServicio[26];
	float precioServicio;

	int isEmpty;
}eServicio;

void hardcodeoServicios(eServicio *listaServicio, int tamServicio);

int inicializarServicios(eServicio *listaServicio, int tamServicio);

int listadoServicios(eServicio *listaServicios, int tamServicio);



#endif /* ARRAYSERVICIO_H_ */
