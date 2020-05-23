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
#include "menu.h"
#include "hardcodeo.h"

/**
 * @fn void initAuto(eAuto[], int)
 * @brief indica que todas las posiciones del vector estan vacias utilizando la bandera
 * .isEmpty = 1
 *
 * @param tutu
 * @param tam
 */
void initAuto (eAuto tutu[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		tutu[i].isEmpty = 1;
	}
}

/**
 * @fn int hayAuto(int)
 * @brief funciona como trigger hasta que se ingrese el primer auto.
 *
 * @param ready
 * @return int [1] si esta OK [0] si aun no hay autos.
 */
int hayAuto (int ready)
{
	if(!(ready))
	{
		printf("Aun no se han ingresado autos.\n\n");
		return 0;
	}
	return 1;
}

/**
 * @fn int buscarLibreAuto(eAuto[], int)
 * @brief busca la primera posicion disponible dentro del vector
 *
 * @param tutu
 * @param tam
 * @return int [i] primera posicion disponible [-1] vector completo.
 */

int buscarLibreAuto(eAuto tutu[], int tam)
{
	for(int i = 0; i < tam; i++)
	{
		if(tutu[i].isEmpty == 1)
		{
			return i;
		}
	}
	printf("Lista completa.\n");
	return -1;
}

/**
 * @fn int buscarAuto(char[], eAuto[], int)
 * @brief busca si la patente solicitada se encuentra en el vector.
 *
 * @param patente
 * @param tutu
 * @param tam
 * @return int [i] posicion encontrada [-1] posicion no encontrada.
 */
int buscarAuto(char patente[], eAuto tutu[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		if((strcmp(tutu[i].patente, patente) == 0) && tutu[i].isEmpty == 0)
		{
			return i;
		}
	}
	return -1;
}

/**
 * @fn int altaAuto(eAuto[], int, eMarca[], int, eColor[], int)
 * @brief Si existen posiciones libres solicita los datos del auto.
 *
 * @param tutu
 * @param tam
 * @param marca
 * @param tamM
 * @param color
 * @param tamC
 * @return int [0] Ok [-1] Vector completo.
 */
int altaAuto(eAuto tutu[], int tam, eMarca marca[], int tamM, eColor color[], int tamC)
{
	eAuto auxAuto;
	int index = buscarLibreAuto(tutu, tam);

	system("cls");
	if(index == -1)
	{
		return -1;
	}
	else
	{
		auxAuto.id = index;
		inputPatente("patente (AAA000 || AA000AA)", auxAuto.patente);
		system("cls");
		listarMarca(marca, tamM);
		auxAuto.idMarca = inputInt("ID de la marca", 1000, 1004);
		system("cls");
		listarColor(color, tamC);
		auxAuto.idColor = inputInt("ID del color", 5000, 5004);
		system("cls");
		auxAuto.modelo = inputInt("modelo (1980-2020)", 1980, 2020);
		auxAuto.isEmpty = 0;

		tutu[index] = auxAuto;

		printf("Auto ingresado correctamente.\n\n");
	}
	return 0;
}

/**
 * @fn void bajaAuto(eAuto[], int, eColor[], int, eMarca[], int)
 * @brief hace una baja logica si la patente se encuentra en el listado,
 *
 * @param tutu
 * @param tam
 * @param color
 * @param tamC
 * @param marca
 * @param tamM
 */
void bajaAuto(eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM)
{
	char patente[7];
	int index;
	char seguir;

	system("cls");

	listarAutos(tutu, tam, color, tamC, marca, tamM);
	inputPatente("patente (AAA000 || AA000AA)", patente);

	index = buscarAuto(patente, tutu, tam);
	if(index == -1)
	{
		printf("No existe la patente %s.\n\n", patente);
	}
	else
	{
		printf("Patente encontrada:\n");
		mostrarAuto(tutu[index],color, tamC, marca, tamM);

		printf("Esta seguro que desea eliminar al auto patente %s? S/N \n", patente);
		fflush(stdin);
		scanf("%c", &seguir);
		seguir = tolower(seguir);
		if(seguir == 's')
		{
			tutu[index].isEmpty = 1;
			printf("Auto eliminado.\n");
		}
		else
		{
			printf("No se realizaron cambios en el registro.\n");
		}
	}
}

/**
 * @fn void modificarAuto(eAuto[], int, eColor[], int, eMarca[], int)
 * @brief si se encuentra la patente en la lista modifica los parametros [Color] o [Modelo]
 *
 * @param tutu
 * @param tam
 * @param color
 * @param tamC
 * @param marca
 * @param tamM
 */
void modificarAuto(eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM)
{
	char patente[7];
	int index;
	int opcion;

	system("cls");

	listarAutos(tutu, tam, color, tamC, marca, tamM);
	inputPatente("patente (AAA000 || AA000AA)", patente);
	index = buscarAuto(patente, tutu, tam);
	if(index == -1)
	{
		printf("No existe la patente %s.\n\n", patente);
	}
	else
	{
		printf("Patente encontrada:\n");
		mostrarAuto(tutu[index],color, tamC, marca, tamM);

		opcion = modifMenu();
		if(opcion == 1)
		{
			listarColor(color, tamC);
			tutu[index].idColor = inputInt("nuevo ID color: ", 5000, 5004);
		}
		else
		{
			tutu[index].modelo = inputInt("modelo (1980-2020)", 1980, 2020);
		}
		printf("Modificado exitosamente.\n");
	}
}

/**
 * @fn void mostrarAuto(eAuto, eColor[], int, eMarca[], int)
 * @brief muestra los datos del auto [ID] [PATENTE] [MARCA] [COLOR] [MODELO]
 *
 * @param tutu
 * @param color
 * @param tamC
 * @param marca
 * @param tamM
 */
void mostrarAuto(eAuto tutu, eColor color[], int tamC, eMarca marca[], int tamM)
{
	char desColor [20];
	char desMarca [20];
	cargarDescColor(desColor, tutu.idColor, color, tamC);
	cargarDescMarca(desMarca, tutu.idMarca, marca, tamM);

	printf(	"| %04d         %8s          %10s      %8s       %d   |\n", tutu.id, tutu.patente, desMarca, desColor, tutu.modelo);

}

/**
 * @fn void listarAutos(eAuto[], int, eColor[], int, eMarca[], int)
 * @brief Listado de autos
 *
 * @param tutu
 * @param tam
 * @param color
 * @param tamC
 * @param marca
 * @param tamM
 */
void listarAutos(eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM)
{
	int ok = 0;
	system("cls");

	printf(	"#======#====================#=================#=============#==========#\n"
			"|  ID  |       PATENTE      |      MARCA      |    COLOR    |  MODELO  |\n"
			"#======#====================#=================#=============#==========#\n");
	for (int i = 0; i < tam; i++)
	{
		if(tutu[i].isEmpty == 0)
		{
			mostrarAuto(tutu[i], color, tamC, marca, tamM);
			ok = 1;
		}
	}
	printf( "#======#====================#=================#=============#==========#\n");
	if (ok == 0)
	{
		printf("No hay datos para mostrar.");
	}
}

/**
 * @fn void ordenarAuto(eAuto[], int, eColor[], int, eMarca[], int)
 * @brief Ordena el listado alfabeticamente por MARCA, en caso de que la marca se
 * repita se ordena por PATENTE.
 *
 * @param tutu
 * @param tam
 * @param color
 * @param tamC
 * @param marca
 * @param tamM
 */
void ordenarAuto(eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM)
{
	eAuto auxAuto;
	char marcaI[20];
	char marcaJ[20];

	for (int i = 0; i < tam - 1; i++)
	{
		for (int j = i + 1; j < tam; j++)
		{
			cargarDescMarca(marcaI, tutu[i].idMarca, marca, tamM);
			cargarDescMarca(marcaJ, tutu[j].idMarca, marca, tamM);
			if(strcmp(marcaI, marcaJ) > 0)
			{
				auxAuto = tutu[i];
				tutu[i] = tutu[j];
				tutu[j] = auxAuto;
			}
			if((strcmp(marcaI,marcaJ) == 0) && strcmp(tutu[i].patente,tutu[j].patente) > 0 )
			{
				auxAuto = tutu[i];
				tutu[i] = tutu[j];
				tutu[j] = auxAuto;
			}
		}
	}
	listarAutos(tutu, tam, color, tamC, marca, tamM);
}

void hardcodearAuto(eAuto tutu[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		tutu[i].id = i;
		strcpy(tutu[i].patente, pat[i]);
		tutu[i].idMarca = mar[i];
		tutu[i].idColor = col[i];
		tutu[i].modelo = mod[i];
		tutu[i].isEmpty = 0;
	}
}
