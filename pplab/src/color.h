#ifndef COLOR_H_
#define COLOR_H_

typedef struct
{
	int id;
	char nombreColor[20];
}eColor;

#endif /* COLOR_H_ */

void listarColor(eColor color[], int tam);
int cargarDescColor(char descripcion[], int id, eColor color[], int tam);
