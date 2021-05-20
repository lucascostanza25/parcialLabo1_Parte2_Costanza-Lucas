/*
 * arrayServicio.h
 *
 *  Created on: 13 may. 2021
 *      Author: Lucas
 */

#ifndef ARRAYSERVICIO_H_
#define ARRAYSERVICIO_H_
#include "arrayTrabajos.h"
#include "arrayBicicleta.h"

typedef struct
{
	int idServicio;
	char descripcionServicio[26];
	float precioServicio;

	int isEmpty;
}eServicio;

/**
 * brief Hardcodeo de los datos del servicio
 *
 * \pre
 * \post
 * \param Se le pasa el array de servicios
 * \param Se le pasa el tamaño del array
 */
void hardcodeoServicios(eServicio *listaServicio, int tamServicio);

/**
 * \brief Inicializa todos los espacios en libres
 *
 * \pre
 * \post
 * \param Se le pasa el array de servicios
 * \param Se le pasa el tamaño del array
 * \return Retorna 0 en caso de que pudo completar la accion o -1 si dio error
 */
int inicializarServicios(eServicio *listaServicio, int tamServicio);

/**
 * \brief Permite dar de baja un servicio
 *
 * \pre
 * \post
 * \param Se le pasa el array de servicios
 * \param Se le pasa el tamaño del array
 * \return Retorna 0 en caso de que pudo completar la accion o -1 si dio error
 */
int darDeBajaServicio(eServicio *listaServicio, int tamServicio);

/**
 * \brief Muestra el listado de todos los servicios
 *
 * \pre
 * \post
 * \param Se le pasa el array de servicios
 * \param Se le pasa el tamaño del array
 * \return Retorna 0 en caso de que pudo completar la accion o -1 si dio error
 */
int listadoServicios(eServicio *listaServicio, int tamServicio);



#endif /* ARRAYSERVICIO_H_ */
