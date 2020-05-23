#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

/**
 * @fn void listarServicio(eServicio[], int)
 * @brief Listado de Servvicios [ID] [SERVICIO] [PRECIO]
 *
 * @param serv
 * @param tam
 */
void listarServicio(eServicio serv[], int tam)
{
	system("cls");
	printf( "\n"
				"#--------#------------#-----------#\n"
				"|   ID   |  SERVICIO  |   PRECIO  |\n"
				"#--------#------------#-----------#\n");
	for (int i = 0; i < tam; i++)
	{
		printf("|  %d   %10s    $%.2f  |\n", serv[i].id, serv[i].descripcion, serv[i].precio);
	}
	printf(		"#--------#------------#-----------#\n");
}

/**
 * @fn int cargarDescServicio(char[], int, eServicio[], int)
 * @brief Si se encuentra el ID solicitado copia el nombre del servicio en la variable [descripcion
 *
 * @param descripcion
 * @param id
 * @param serv
 * @param tam
 */
void cargarDescServicio(char descripcion[], int id, eServicio serv[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		if(serv[i].id == id)
		{
			strcpy(descripcion, serv[i].descripcion);
		}
	}
}
