#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validar.h"

/**
 * @fn float inputFloat(char[], int, int)
 * @brief Solicita un numero flotante dentro de un rango.
 *
 * @param message
 * @param min
 * @param max
 * @return float num
 */
float inputFloat(char message[20], int min, int max)
{
	float num;

	printf("Ingrese %s: ", message);
	scanf("%f", &num);

	while (num < min || num > max)
	{
		printf("ERROR: %s invalido. \nIngrese %s nuevamente: \n", message, message);
		fflush(stdin);
		scanf("%f", &num);
	}
	return num;
}

/**
 * @fn int inputInt(char[], int, int)
 * @brief solicita un numero entero dentro de un rango
 *
 * @param message
 * @param min
 * @param max
 * @return int num
 */
int inputInt(char message[20], int min, int max)
{
	int num;

	printf("Ingrese %s: ", message);
	scanf("%d", &num);

	while (validNum(num, min, max) == -1)
	{
		printf("ERROR: %s invalido. \nIngrese %s nuevamente: ", message, message);
		fflush(stdin);
		scanf("%d", &num);
	}
	return num;
}

/**
 * @fn void inputPatente(char[], char*)
 * @brief Solicita el string de la patente y verifica que sea valida actualmente (AAA000 || AA00AAA)
 *
 * @param message
 * @param string
 */
void inputPatente(char message[20], char* string)
{
	int patenteValida = 0;
	printf("Ingrese %s: ", message);
	fflush(stdin);
	gets(string);

	do
	{
		if ((strlen(string) != 6 && strlen(string) != 7) || patenteValida != 0)
		{
			printf("ERROR: Formato invalido. \nIngrese %s nuevamente:", message);
			fflush(stdin);
			gets(string);
			patenteValida = 0;
		}
		else if(strlen(string) == 6) // PARA PATENTES AAA000
		{
			for (int i = 0; i < 3; i++)
			{
				if((isalpha(string[i])))
				{
					string[i] = toupper(string[i]);
					patenteValida++;
				}
			}
			if(patenteValida == 3)
			{
				for (int i = 3; i < strlen(string); i++)
				{
					if((isdigit(string[i])))
					{
						patenteValida++;
					}
				}
			}
		}
		else // PATENTES AA000AA
		{
			for (int i = 0; i < 2; i++)
			{
				if((isalpha(string[i])))
				{
					string[i] = toupper(string[i]);
					patenteValida++;
				}
			}
			if(patenteValida == 2)
			{
				for (int i = 2; i < 5; i++)
				{
					if((isdigit(string[i])))
					{
						patenteValida++;
					}
				}
			}
			if(patenteValida == 5)
			{
				for (int i = 5; i < strlen(string); i++)
				{
					if((isalpha(string[i])))
					{
						string[i] = toupper(string[i]);
						patenteValida++;
					}
				}
			}
		}
	} while(patenteValida != 6 && patenteValida != 7);
}

/**
 * @fn int validNum(int, int, int)
 * @brief valida que el numero este dentro del rango indicado.
 *
 * @param num
 * @param min
 * @param max
 * @return int [num] Ok [-1] Fuera de rango
 */
int validNum(int num, int min, int max)
{
	if (num < min || num > max)
	{
		return -1;
	}
	else
	{
		return num;
	}
}

/**
 * @fn eFecha inputDate()
 * @brief Solicita una fecha y verifica que sea valida
 *
 * @return eFecha
 */
eFecha inputDate()
{
	eFecha fecha;

	printf("Ingrese fecha DD/MM/AAAA: ");
	scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

	do
	{
		fflush(stdin);
		if(validNum(fecha.anio,1900,2020) == -1 || fecha.mes == -1 || fecha.dia == -1)
		{
			printf("ERROR: Fecha invalida.\nIngrese fecha DD/MM/AAAA: ");
			scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
		}
		else
		{
			if(fecha.anio > 1900 && fecha.anio / 4 == 0 && fecha.anio / 100 == 0 && fecha.anio / 400 == 0 && fecha.mes == 2)
			{
				fecha.dia = validNum(fecha.dia, 1, 29);
			}
			else
			{
				fecha.mes = validNum(fecha.mes, 1, 12);
				switch(fecha.mes)
				{
					case 2:
						fecha.dia = validNum(fecha.dia, 1, 28);
						break;
					case 4:
					case 6:
					case 9:
					case 11:
						fecha.dia = validNum(fecha.dia, 1, 30);
						break;
					default:
						fecha.dia = validNum(fecha.dia, 1, 31);
						break;
				}
			}
		}
	}while(fecha.anio == -1 || fecha.mes == -1 || fecha.dia == -1);

	return fecha;
}
