#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"
#include "color.h"
#include "menu.h"
#include "validar.h"
#include "marca.h"
#include "informes.h"

void mostrarInformes(eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM)
{
	switch(infoMenu())
	{
		case 1:
			autoColorSelec(tutu, tam, color, tamC, marca, tamM);
			break;
		case 2:
			autoMarcaSelec(tutu, tam, color, tamC, marca, tamM);
			break;
		case 3:
			autoMasViejo(tutu, tam, color, tamC, marca, tamM);
			break;
		case 4:
			autosPorMarca(tutu, tam, color, tamC, marca, tamM);
			break;
		case 5:
			cantAutoColorMarca(tutu, tam, color, tamC, marca, tamM);
			break;
		case 6:
			marcaMasElegida(tutu, tam, marca, tamM);
	}
}
void autoColorSelec (eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM)
{
	int auxColor;
	char nombreColor[20];
	int hayAuto = 0;
	system("cls");
	printf("Listado de autos por color determinado.\n\n");
	listarColor(color, tamC);
	auxColor = inputInt("ID del color", 5000, 5004);

	cargarDescColor(nombreColor, auxColor, color, tamC);

	for (int i = 0; i < tam; i++) {
		if (tutu[i].idColor == auxColor && tutu[i].isEmpty == 0) {
			mostrarAuto(tutu[i], color, tamC, marca, tamM);
			hayAuto = 1;
		}
	}
	if (!hayAuto) {
		printf("No hay autos color %s.", nombreColor);
	}
}

void autoMarcaSelec (eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM)
{
	int auxMarca;
	char nombreMarca[20];
	int hayAuto = 0;
	system("cls");
	printf("Listado de autos por marca determinada.\n\n");
	listarMarca(marca, tamM);
	auxMarca = inputInt("ID de la marca", 1000, 1004);

	cargarDescMarca(nombreMarca, auxMarca, marca, tamM);

	for (int i = 0; i < tam; i++) {
		if (tutu[i].idMarca == auxMarca && tutu[i].isEmpty == 0) {
			mostrarAuto(tutu[i], color, tamC, marca, tamM);
			hayAuto = 1;
		}
	}
	if (!hayAuto) {
		printf("No hay autos de la marca %s.\n", nombreMarca);
	}
}

void autoMasViejo (eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM)
{
	int masViejo;

	system("cls");

	for (int i = 0; i < tam; i++)
	{
		if (tutu[i].isEmpty == 0 && (tutu[i].modelo < masViejo || i == 0)) {
			masViejo = tutu[i].modelo;
		}
	}

	printf("Modelo mas antiguo:\n");
	for (int i = 0; i < tam; i++)
	{
		if (tutu[i].isEmpty == 0 && tutu[i].modelo == masViejo)
		{
			mostrarAuto(tutu[i], color, tamC, marca, tamM);
		}
	}
}

void autosPorMarca (eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM)
{
	int hayMarca = 0;

	for (int i = 0; i < tamM; i++)
	{
		printf(	"#====================#\n"
				"  Marca  %s\n", marca[i].descripcion);
		printf( "#====================#\n");
		for (int t = 0; t < tam; t++)
		{
			if (tutu[t].isEmpty == 0 && tutu[t].idMarca == marca[i].id)
			{
				mostrarAuto(tutu[t], color, tamC, marca, tamM);
				hayMarca = 1;
			}
		}
		if (!hayMarca)
		{
			printf("No hay autos de la marca %s.", marca[i].descripcion);
		}
		printf("\n");
	}
}

void cantAutoColorMarca (eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM)
{
	int auxColor;
	char nombreColor[20];
	int auxMarca;
	char nombreMarca[20];
	int cantCM = 0;

	system("cls");
	printf("Cantidad de autos por color y marca determinadas.\n\n");
	listarColor(color, tamC);
	auxColor = inputInt("ID del color", 5000, 5004);
	cargarDescColor(nombreColor, auxColor, color, tamC);
	listarMarca(marca, tamM);
	auxMarca = inputInt("ID de la marca", 1000, 1004);
	cargarDescMarca(nombreMarca, auxMarca, marca, tamM);

	for (int i = 0; i < tam; i++)
	{
		if (tutu[i].idColor == auxColor && tutu[i].idMarca == auxMarca && tutu[i].isEmpty == 0)
		{
			cantCM++;
		}
	}

	printf("Hay %d autos de color %s y marca %s\n", cantCM, nombreColor, nombreMarca);
}

void marcaMasElegida (eAuto tutu[], int tam, eMarca marca[], int tamM)
{
	int max = 0;
	eMarca masElegida[5] = {0};

	for (int i = 0; i < tamM; i++)
	{
		for (int t = 0; t < tam; t++)
		{
			strcpy(masElegida[i].descripcion,marca[i].descripcion);
			if (tutu[t].isEmpty == 0 && tutu[t].idMarca == marca[i].id)
			{
				masElegida[i].id = max++;
				if(max > masElegida[i].id)
				{
					max = masElegida[i].id;
				}
			}
		}
	}

	for (int i = 0; i < tamM; i++)
	{
		if(masElegida[i].id == max)
		{
			printf("La marca mas elegida es %s\n", masElegida[i].descripcion);
		}
	}
}
