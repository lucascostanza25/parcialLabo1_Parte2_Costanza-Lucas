/*
 * arrayBicicleta.h
 *
 *  Created on: 20 may. 2021
 *      Author: Lucas
 */

#ifndef ARRAYBICICLETA_H_
#define ARRAYBICICLETA_H_
#include "arrayServicio.h"
#include "arrayTrabajos.h"

typedef struct
{
	int idBicicleta;
	char marcaBicicleta[26];
	int rodadoBicicleta;
	char colorBicicleta[11];

	int isEmpty;
}eBicicleta;
/**
 * \brief Se hardodea los datos de la bicicleta
 *
 * \pre
 * \post
 * \param Se le pasa el array de bicicletas
 * \param Se le pasa el tamaño del array
 */
void hardcodeoBicicleta(eBicicleta *listaBicicleta, int tamBicicleta);

/**
 * \brief Inicializa todos los espacios en disponibles
 *
 * \pre
 * \post
 * \param Se le pasa el array de bicicletas
 * \param Se le pasa el tamaño del array
 * \return Retorna 0 en caso de que pudo completar la accion o -1 si dio error
 */
int inicializarBicicleta(eBicicleta *listaBicicleta, int tamBicicleta);

/**
 * \brief Permite dar de baja una bicicleta
 *
 * \pre
 * \post
 * \param Se le pasa el array de bicicletas
 * \param Se le pasa el tamaño del array
 * \return Retorna 0 en caso de que pudo completar la accion o -1 si dio error
 */
int bajaBicicleta(eBicicleta *listaBicicleta, int tamBicicleta);

/**
 * \brief Muestra el listado de las bicicletas
 *
 * \pre
 * \post
 * \param Se le pasa el array de bicicletas
 * \param Se le pasa el tamaño del array
 * \return Retorna 0 en caso de que pudo completar la accion o -1 si dio error
 */
int listadoBicicletas(eBicicleta *listaBicicleta, int tamBicicleta);

#endif /* ARRAYBICICLETA_H_ */
