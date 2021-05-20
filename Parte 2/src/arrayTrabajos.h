/*
 * arrayTrabajos.h
 *
 *  Created on: 13 may. 2021
 *      Author: Lucas
 */

#ifndef ARRAYTRABAJOS_H_
#define ARRAYTRABAJOS_H_

#define T 5
#define TS 4
#define LIBRE 0
#define OCUPADO 1
#include "arrayServicio.h"
#include "arrayBicicleta.h"

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int idTrabajo;

	int idServicio;

	int idBicicleta;

	eFecha fechaTrabajo;

	int isEmpty;
}eTrabajo;

eTrabajo pedirDatosTrabajo();

/**
 * \brief Inicializa todos los espacios del array en libres
 *
 * \pre
 * \post
 * \param listaTrabajo
 * \param tam del array
 */
void inicializarTrabajo(eTrabajo *listaTrabajo, int tam);

/**
 * \brief Muestra un solo trabajo
 *
 * \pre
 * \post
 * \param Se le pasa la estructura del trabajo
 */
void mostrarUnTrabajo(eTrabajo);

/**
 * \brief Muestra el listado de trabajos en el array
 *
 * \pre
 * \post
 * \param listaTrabajo
 * \param tam tam del array
 * \return retorna estado, si es -1 dio error, si es 0 no.
 */
int mostrarListadoTrabajos(eTrabajo *listaTrabajo, int tam);

/**
 * \brief Da de alta un trabajo
 *
 * \pre
 * \post
 * \param Se le pasa el array de trabajo
 * \param Se le pasa el tamaño del array
 * \param Se le pasa mediante pasaje de referencia el id autoincremental
 * \return Retorna el estado. si es 0 fue exitoso, si es -1 no hay mas espacio en el array
 */
int altaTrabajo(eTrabajo *listaTrabajo, int tam, int *idTrabajo);

/**
 * \brief Permite buscar un espacio libre en el array
 *
 * \pre
 * \post
 * \param Se le pasa el array de trabajo
 * \param Se le pasa el tamaño del array
 * \return estado
 */
int buscarTrabajoLibre(eTrabajo *listaTrabajo, int tam);

/**
 * \brief Permite modificar un trabajo o servicio
 *
 * \pre
 * \post
 * \param Se le pasa el array de trabajo
 * \param Se le pasa el tamaño del array trabajo
 * \param Se le pasa el array de servicio
 * \param Se le pasa el tamaño del array de servicio
 * \return retorna 0 en caso de que pudo mostrar empleados o -1 si dio error
 */
int modificarTrabajo(eTrabajo *listaTrabajo, int tam, eServicio *listaServicio, int tamServicio, eBicicleta *listaBicicleta, int tamBicicleta);

/**
 * \brief Permite dar de baja un trabajo
 *
 * \pre
 * \post
 * \param Se le pasa el array de trabajo
 * \param Se le pasa el tamaño del array
 * \return retorna 0 en caso de que pudo mostrar empleados o -1 si dio error
 */
int bajaTrabajo(eTrabajo *listaTrabajo, int tam);

/**
 * \brief Permite ordenar los trabajos por año
 *
 * \pre
 * \post
 * \param Se le pasa el array de trabajo
 * \param Se le pasa el tamaño del array
 */
int ordenarTrabajos(eTrabajo *listaTrabajo, int tam);

/**
 * \brief Muestra el listado de trabajos, bicicletas y servicios
 *
 * \pre
 * \post
 * \param Se le pasa el array de trabajo
 * \param Se le pasa el tamaño del array trabajo
 * \param Se le pasa el array de servicios
 * \param Se le pasa el tamaño del array de servicios
 * \param Se le pasa el array de bicicletas
 * \param Se le pasa el tamaño del array de bicicletas
 * \return Retorna 0 en caso de que pudo completar la accion o -1 si dio error
 */
int listadoTrabajosYServicios(eTrabajo *listaTrabajo, int tamTrabajo, eServicio *listaServicios, int tamServicio, eBicicleta *listaBicicleta, int tamBicicleta);

/**
 * \brief Informa de la suma de los precios de todos los servicios prestados e ingresados
 *
 * \pre
 * \post
 * \param Se le pasa el array de servicios
 * \param Se le pasa el tamaño del array de servicios
 * \param Se le pasa el array de trabajo
 * \param Se le pasa el tamaño del array trabajo
 * \return Retorna 0 en caso de que pudo completar la accion o -1 si dio error
 */
int sumaPrecios(eServicio *listaServicios, int tamServicio, eTrabajo *listaTrabajo, int tamTrabajo);

/**
 * \brief Ordena por marca las bicicletas ingresadas
 *
 * \pre
 * \post
 * \param Se le pasa el array de trabajo
 * \param Se le pasa el tamaño del array trabajo
 * \param Se le pasa el array de servicios
 * \param Se le pasa el tamaño del array de servicios
 * \param Se le pasa el array de bicicletas
 * \param Se le pasa el tamaño del array de bicicletas
 * \return Retorna 0 en caso de que pudo completar la accion o -1 si dio error
 */
int ordenarTrabajosPorMarca(eTrabajo *listaTrabajo, int tamTrabajo, eServicio *listaServicios, int tamServicio, eBicicleta *listaBicicleta, int tamBicicleta);

/**
 * \brief Muestra la cantidad de bicicletas color Rojo que se trabajaron
 *
 * \pre
 * \post
 * \param Se le pasa el array de trabajo
 * \param Se le pasa el tamaño del array trabajo
 * \param Se le pasa el array de bicicletas
 * \param Se le pasa el tamaño del array de bicicletas
 * \return Retorna 0 en caso de que pudo completar la accion o -1 si dio error
 */
int bicicletasRojo(eTrabajo *listaTrabajo, int tamTrabajo, eBicicleta *listaBicicleta, int tamBicicleta);

/**
 * \brief Muestra un listado de servicios con sus respectivas bicicletas trabajadas
 *
 * \pre
 * \post
 * \param Se le pasa el array de servicios
 * \param Se le pasa el tamaño del array de servicios
 * \param Se le pasa el array de bicicletas
 * \param Se le pasa el tamaño del array de bicicletas
 * \param Se le pasa el array de trabajo
 * \param Se le pasa el tamaño del array trabajo
 * \return Retorna 0 en caso de que pudo completar la accion o -1 si dio error
 */
int listadoServiciosBicis(eServicio *listaServicio, int tamServicio, eBicicleta *listaBicicleta, int tamBicicleta, eTrabajo *listaTrabajo, int tamTrabajo);

#endif /* ARRAYTRABAJOS_H_ */
