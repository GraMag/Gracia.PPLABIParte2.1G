#ifndef MARCA_H_
#define MARCA_H_

typedef struct
{
	int id;
	char descripcion[20];
}eMarca;

#endif /* MARCA_H_ */

void listarMarca(eMarca mar[], int tam);
void cargarDescMarca(char descripcion[], int id, eMarca marca[], int tam);

