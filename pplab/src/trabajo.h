#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct
{
	int id;
	char patente[8];
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

#endif /* TRABAJO_H_ */

void initTrabajo (eTrabajo traba[], int tam);
int buscarLibreTraba(eTrabajo traba[], int tam);
void mostrarTrabajo(eTrabajo traba, eServicio serv[], int tamS);
void listarTrabajos(eTrabajo traba[], int tam,  eServicio serv[], int tamS);
int altaTrabajo(eTrabajo traba[], int tam, eServicio serv[], int tamS, eAuto tutu[], int tamA, eColor color[], int tamC, eMarca marca[], int tamM);
