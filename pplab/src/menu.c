#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "validar.h"
#include "trabajo.h"
#include "servicio.h"
/**
 * @fn char menu()
 * @brief Menu principal. Ofrece las opciones de ABM y listados.
 *
 * @return char [a - i] Opcion ingresada por el usuario.
 */
char menu()
{
	char opcion;
	printf("Seleccione una opcion: \n\n");
	printf( "A.- Alta auto\n"
			"B.- Modificar auto\n"
			"C.- Baja auto\n"
			"D.- Listar autos\n"
			"E.- Listar marcas\n"
			"F.- Listar colores\n"
			"G.- Listar servicios\n"
			"H.- Alta trabajo\n"
			"I.- Listar trabajo\n"
			"J.- Informes\n");
	fflush(stdin);
	scanf(" %c", &opcion);
	opcion = tolower(opcion);
	return opcion;
}

/**
 * @fn int modifMenu()
 * @brief Menu modificar para seleccionar que parametro del auto cambiar.
 *
 * @return int [1] Color [2] Modelo
 */
int modifMenu()
{
	system("cls");
	int num;
	printf("Que atributo desea modificar? \n"
				"1.- Color\n"
				"2.- Modelo\n");
	num = inputInt("atributo", 1, 2);
	return num;
}

int infoMenu()
{
	system("cls");
	int num;
	printf("Seleccione informe: \n"
			"1.- Mostrar autos del color seleccionado\n"
			"2.- Mostrar autos de una marca seleccionada\n"
			"3.- Informar el o los autos más viejos\n"
			"4.- Mostrar un listado de los autos separados por marca\n"
			"5.- Elegir un color y una marca y contar cuantos autos hay de ese color y esa marca\n"
			"6.- Mostrar la o las marcas más elegidas por los clientes.\n"
			"7.- Trabajos realizados a un auto");
	num = inputInt("informe", 1, 7);
	return num;
}
