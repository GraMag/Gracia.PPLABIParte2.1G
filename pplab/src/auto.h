#include "marca.h"
#include "color.h"

#ifndef AUTO_H_
#define AUTO_H_

typedef struct
{
	int id;
	char patente[8];
	int idMarca;
	int idColor;
	int modelo;
	int isEmpty;
}eAuto;

#endif /* AUTO_H_ */

void initAuto (eAuto tutu[], int tam);
int hayAuto (int ready);
int buscarLibreAuto(eAuto tutu[], int tam);
int buscarAuto(char patente[], eAuto tutu[], int tam);
int altaAuto(eAuto tutu[], int tam, eMarca marca[], int tamM, eColor color[], int tamC);
void bajaAuto(eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM);
void modificarAuto(eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM);
void mostrarAuto(eAuto tutu, eColor color[], int tamC, eMarca marca[], int tamM);
void listarAutos(eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM);
void ordenarAuto(eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM);
void hardcodearAuto(eAuto tutu[], int tam);
