#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "validaciones.h"



int parser_ListFromText(FILE* pFile , LinkedList* pArrayList)
{
    int isOk=0;
    char auxCadena[100];
    char buffer[5][50];
    ePais* auxPais = NULL;
    int cant=0;
    int flag;
    char confirma='n';
    if(pFile != NULL && pArrayList != NULL)
    {

        if(ll_len(pArrayList) > 0)
        {
            pedirChar(&confirma, "Se van a sobreescribir los datos ingresados de la lista!! confirma? s/n: ", "Error. ");
        }
        if(ll_len(pArrayList) == 0 || confirma == 's')
        {
            ll_clear(pArrayList);
            fscanf(pFile, "%[^\n]", auxCadena);
            while(!feof(pFile))
            {
                cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
                if(cant == 5)
                {
                    auxPais = pais_newParam(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

                    if(auxPais != NULL)
                    {
                        ll_add(pArrayList, auxPais);
                        auxPais = NULL;
                        flag = 0;
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    flag = 2;
                    break;
                }
            }
        }
        if(flag == 0)
        {
            printf("Paises cargados exitosamente!!\n");
            isOk=1;
        }
        else if(flag == 1)
        {
            printf("Problema en la carga del pais\n");
        }
        else if(flag ==2)
        {
            printf("Problema para leer paises\n");
            printf("cant: %d\n", cant);
        }
    }
    return isOk;
}
int parser_PaisesToText(char* path , LinkedList* paises)
{
    int isOk = 0;
	ePais* auxPais = NULL;
	if(path != NULL && paises != NULL)
	{
		for(int i=0;i< ll_len(paises);i++)
		{
			auxPais = (ePais*) ll_get(paises, i);
			fprintf(path, "%d,%s,%d,%d,%d\n", auxPais->id, auxPais->nombre, auxPais->vac1dosis,auxPais->vac2dosis, auxPais->sinVacunar);
		}
	}
	else if(path != NULL)
	{
		printf("problemas con pFile\n");
	}
	else if(paises)
	{
		printf("problemas con el listado\n");
	}

	return isOk;
}
