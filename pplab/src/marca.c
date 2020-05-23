#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

/**
 * @fn void listarMarca(eMarca[], int)
 * @brief Listado de Marcas [ID] [MARCA]
 *
 * @param mar
 * @param tam
 */
void listarMarca(eMarca mar[], int tam)
{
	system("cls");
	printf( "\n"
			"#------#------------#\n"
			"|  ID  |    MARCA   |\n"
			"#------#------------#\n");
	for (int i = 0; i < tam; i++)
		{
		 printf("| %d   %10s |\n", mar[i].id, mar[i].descripcion);
		}
	printf( "#------#------------#\n");
}


/**
 * @fn int cargarDescMarca(char[], int, eMarca[], int)
 * @brief Si se encuentra el ID solicitado copia el nombre de la marca en la variable [descripcion]
 *
 * @param descripcion
 * @param id
 * @param color
 * @param tam
**/

void cargarDescMarca(char descripcion[], int id, eMarca marca[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		if(marca[i].id == id)
		{
			strcpy(descripcion, marca[i].descripcion);
		}
	}
}
