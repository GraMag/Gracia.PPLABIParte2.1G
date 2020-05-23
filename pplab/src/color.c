#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

/**
 * @fn void listarColor(eColor[], int)
 * @brief Listado de Colores [ID] [COLOR]
 *
 * @param color
 * @param tam
 */
void listarColor(eColor color[], int tam)
{
	system("cls");

	printf( "#------#--------#\n"
			"|  ID  |  COLOR |\n"
			"#------#--------#\n");

	for (int i = 0; i < tam; i++)
	{
		printf("| %d   %6s |\n", color[i].id, color[i].nombreColor);
	}
	printf("#------#--------#\n");
}

/**
 * @fn int cargarDescColor(char[], int, eColor[], int)
 * @brief Si se encuentra el ID solicitado copia el nombre del color en la variable [descripcion]
 *
 * @param descripcion
 * @param id
 * @param color
 * @param tam
 * @return int [1] esta ok [0] no existe.
 */
int cargarDescColor(char descripcion[], int id, eColor color[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		if(color[i].id == id)
		{
			strcpy(descripcion, color[i].nombreColor);
			return 1;
		}
	}
	return 0;
}
