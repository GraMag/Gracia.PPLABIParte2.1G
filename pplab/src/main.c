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
#include "menu.h"
#include "validar.h"
#include "informes.h"
#define TAMMC 5 	// TAManio Marca Color
#define TAMS 4 		// TAManio Servicio
#define TAMA 100 	// TAManio Auto
#define TAMT 1000   // TAM Trabajo
#define TAMH 9		// TAM Hardcodeo

int main(void) {

	char continuar = 's';
	int readyAuto = 1;
	eMarca marca[TAMMC] = {{1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};
	eColor color[TAMMC] = {{5000, "Negro"}, {5001, "Blanco"}, {5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};
	eServicio servicio[TAMS] = {{20000, "Lavado", 250}, {20001, "Pulido", 300}, {20002, "Encerado", 400}, {20003, "Completo", 600}};
	eAuto tutu[TAMA];
	eTrabajo trabajo[TAMT];

	setbuf(stdout, NULL);


	initAuto(tutu, TAMA);
	initTrabajo(trabajo, TAMT);
	hardcodearAuto(tutu, TAMH);
	printf("*** BIENVENIDO ***\n\n");

	do
		{
			system("cls");
			fflush(stdin);

			switch(menu())
			{
				case 'a':
					if (altaAuto(tutu, TAMA, marca, TAMMC, color, TAMMC) == 0)
					{
						readyAuto = 1;
					}
					break;
				case 'b':
					if (hayAuto(readyAuto))
					{
					modificarAuto(tutu, TAMA, color, TAMMC, marca, TAMMC);
					}
					break;
				case 'c':
					if (hayAuto(readyAuto))
					{
					bajaAuto(tutu, TAMA, color, TAMMC, marca, TAMMC);
					}
					break;
				case 'd':
					if (hayAuto(readyAuto))
					{
					ordenarAuto(tutu, TAMA, color, TAMMC, marca, TAMMC);
					}
					break;
				case 'e':
					if (hayAuto(readyAuto))
					{
					listarMarca(marca, TAMMC);
					}
					break;
				case 'f':
					if (hayAuto(readyAuto))
					{
					listarColor(color, TAMMC);
					}
					break;
				case 'g':
					if (hayAuto(readyAuto))
					{
						listarServicio(servicio, TAMS);
					}
					break;
				case 'h':
					if (hayAuto(readyAuto))
					{
						altaTrabajo(trabajo, TAMT, servicio, TAMS, tutu, TAMA, color, TAMMC, marca, TAMMC);
					}
					break;
				case 'i':
					if (hayAuto(readyAuto))
					{
						listarTrabajos(trabajo,TAMS, servicio, TAMS);
					}
					break;
				case 'j':
					if (hayAuto(readyAuto))
					{
						mostrarInformes(tutu, TAMA, color, TAMMC, marca, TAMMC);
					}
					break;
				default:
					printf("Opcion invalida\n");
					break;
			}
			system("pause");
			fflush(stdin);
		}while(continuar == 's');

	return EXIT_SUCCESS;
}
