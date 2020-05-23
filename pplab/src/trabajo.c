#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"
#include "color.h"
#include "fecha.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "validar.h"

/**
 * @fn void initTrabajo(eTrabajo[], int)
 * @brief indica que todas las posiciones del vector estan vacias utilizando la bandera
 * .isEmpty = 1
 *
 * @param traba
 * @param tam
 */
void initTrabajo (eTrabajo traba[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		traba[i].isEmpty = 1;
	}
}

/**
 * @fn int buscarLibreTraba(eTrabajo[], int)
 * @brief busca la primera posicion disponible dentro del vector
 *
 * @param traba
 * @param tam
 * @return int [i] primera posicion disponible [-1] vector completo.
 */
int buscarLibreTraba(eTrabajo traba[], int tam)
{
	for(int i = 0; i < tam; i++) {
		if(traba[i].isEmpty == 1)
		{
			return i;
		}
	}
	printf("No hay lugares libres");
	return -1;
}

/**
 * @fn int altaTrabajo(eTrabajo[], int, eServicio[], int, eAuto[], int, eColor[], int, eMarca[], int)
 * @brief Si existen posiciones libres solicita los datos del trabajo
 *
 * @param traba
 * @param tam
 * @param serv
 * @param tamS
 * @param tutu
 * @param tamA
 * @param color
 * @param tamC
 * @param marca
 * @param tamM
 * @return int [-1] No hay lugar [0] Ok
 */
int altaTrabajo(eTrabajo traba[], int tam, eServicio serv[], int tamS, eAuto tutu[], int tamA, eColor color[], int tamC, eMarca marca[], int tamM)
{
	eTrabajo auxTrab;
	int existe;
	int index = buscarLibreTraba(traba, tam);

	system("cls");
	if(index == -1)
	{
		return -1;
	}
	else
	{
		listarAutos(tutu, tamA, color, tamC, marca, tamM);
		inputPatente("patente (AAA000 || AA000AA)", auxTrab.patente);

		existe = buscarAuto(auxTrab.patente, tutu, tamA);
		if(existe == -1)
		{
			printf("No existe la patente %s.\n\n", auxTrab.patente);
		}
		else
		{
			auxTrab.id = index;
			listarServicio(serv, tamS);
			auxTrab.idServicio = inputInt("ID del servicio", 20000, 20003);
			auxTrab.fecha = inputDate();
			auxTrab.isEmpty = 0;

			traba[index] = auxTrab;
		}
	}
	return 0;
}

/**
 * @fn void mostrarTrabajo(eTrabajo, eServicio[], int)
 * @brief muestra los datos del servicio [ID] [PATENTE] [SERVICIO] [FECHA]
 *
 * @param traba
 * @param serv
 * @param tamS
 */
void mostrarTrabajo(eTrabajo traba, eServicio serv[], int tamS)
{
	char desServicio [20];
	cargarDescServicio(desServicio, traba.idServicio, serv, tamS);


	printf(	"| %04d          %s           %10s       %02d/%02d/%d |\n", traba.id, traba.patente, desServicio, traba.fecha.dia, traba.fecha.mes, traba.fecha.anio);

}

/**
 * @fn void listarTrabajos(eTrabajo[], int, eServicio[], int)
 * @brief Listado de trabajo
 *
 * @param traba
 * @param tam
 * @param serv
 * @param tamS
 */
void listarTrabajos(eTrabajo traba[], int tam,  eServicio serv[], int tamS)
{
	int ok = 0;
	system("cls");
	printf(	"#======#======================#=================#=============#\n"
			"|  ID  |        PATENTE       |     SERVICIO    |    FECHA    |\n"
			"#======#======================#=================#=============#\n");
	for (int i = 0; i < tam; i++)
	{
		if(traba[i].isEmpty == 0)
		{
			mostrarTrabajo(traba[i], serv, tamS);
			ok = 1;
		}
	}
	printf( "#======#======================#=================#=============#\n");
	if (!ok)
	{
		printf("No hay datos para mostrar");
	}
}


