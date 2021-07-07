#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    int isOk=0;
    if(path != NULL && pArrayList != NULL)
    {
        FILE* f = fopen(path, "r");
        if(f==NULL)
        {
            printf("No se pudo abrir el archivo.\n");
            exit(1);
        }
        if(parser_ListFromText(f, pArrayList))
        {
            system("pause");
            isOk = 1;
        }
        fclose(f);
    }
    return isOk;
}
int controller_ListVac(LinkedList* paises)
{
    int isOk=0;
    if(paises != NULL)
    {
        mostrarListaPaises(paises);
        isOk=1;
    }
    return isOk;
}
int controller_saveAsText(char* path , LinkedList* paises)
{
    int isOk=0;
    FILE* f = NULL;
    char confirmacion = 'n';
    if(path != NULL && paises)
    {
    			f = fopen(path, "w");
            if(f!= NULL)
    			{
    				parser_PaisesToText(f, paises);
    				isOk=1;
    			}
    		else
    		{
    			exit(1);
    		}

    	fclose(f);
    }
	return isOk;
}
