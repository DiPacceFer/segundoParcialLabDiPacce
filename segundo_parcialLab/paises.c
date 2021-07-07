#include <stdio.h>
#include <stdlib.h>
#include "paises.h"


ePais* pais_newParam(char* idStr, char* nombreStr, char* vac1Str, char* vac2Str, char* sinVacStr)
{

    ePais* nuevoPais = pais_new();
    if(nuevoPais != NULL)
    {
        if(!(pais_SetId(nuevoPais, atoi(idStr))&&
                pais_SetNombre(nuevoPais, nombreStr) &&
                pais_SetVac1(nuevoPais, atoi(vac1Str)) &&
                pais_SetVac2(nuevoPais, atoi(vac2Str)) &&
                pais_SetSinVac(nuevoPais, atoi(sinVacStr))))
        {
            nuevoPais = NULL;
        }
    }
    return nuevoPais;
}
ePais* pais_new()
{
    ePais* nuevoPais = (ePais*) malloc(sizeof(ePais));
    if(nuevoPais != NULL)
    {
        nuevoPais->id = 0;
        strcpy(nuevoPais->nombre, "");
        nuevoPais->vac1dosis = 0;
        nuevoPais->vac2dosis = 0;
        nuevoPais->sinVacunar = 0;
    }
    return nuevoPais;
}
int pais_SetId(ePais* pais, int id)
{
    int isOk = 0;
    if(pais != NULL && id > 0)
    {
        pais->id = id;
        isOk=1;
    }
    return isOk;
}
int pais_SetNombre(ePais* pais, char* nombre)
{
    int isOk=0;
    if(pais != NULL && nombre != NULL && strlen(nombre) < 50)
    {
        strcpy(pais->nombre, nombre);
        isOk=1;
    }
    return isOk;
}
int pais_SetVac1(ePais* pais, int vac1)
{
    int isOk = 0;
    if(pais != NULL && vac1 >= 0)
    {
        pais->vac1dosis = vac1;
        isOk=1;
    }
    return isOk;
}
int pais_SetVac2(ePais* pais, int vac2)
{
    int isOk = 0;
    if(pais != NULL && vac2 >= 0)
    {
        pais->vac2dosis = vac2;
        isOk=1;
    }
    return isOk;
}
int pais_SetSinVac(ePais* pais, int sinVac)
{
    int isOk = 0;
    if(pais != NULL && sinVac >= 0)
    {
        pais->sinVacunar = sinVac;
        isOk=1;
    }
    return isOk;
}
int mostrarListaPaises(LinkedList* paises)
{
    int isOk=0;
    int tam = ll_len(paises);
    ePais* auxPais = NULL;
    if(paises != NULL)
    {
        printf("   Id   Nombre        1er Dosis   2da Dosis    Sin Vacunar\n");
        printf("------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam ; i++)
        {
            auxPais = (ePais*) ll_get(paises, i);
            if(!mostrarPais(auxPais))
            {
                printf("Problema para mostrar Pais\n");
                break;
            }
        }
        isOk=1;
    }
    return isOk;
}
int mostrarPais(ePais* unPais)
{
    int isOk=0;
    int id;
    char nombre[50];
    int vac1;
    int vac2;
    int sinVac;
    if(unPais != NULL && pais_GetId(unPais, &id) &&
            pais_GetNombre(unPais, nombre) &&
            pais_GetVac1(unPais, &vac1) &&
            pais_Getvac2(unPais, &vac2) &&
            pais_GetSinVac(unPais, &sinVac))
    {
        printf("%2d    %20s         %2d         %2d        %2d\n", id, nombre, vac1, vac2, sinVac);
        isOk=1;
    }
    return isOk;
}
int pais_GetId(ePais* pais, int* id)
{
    int isOk=0;
    if(pais != NULL && id != NULL)
    {
        *id = pais->id;
        isOk=1;
    }
    return isOk;
}
int pais_GetNombre(ePais* pais, char* nombre)
{
    int isOk=0;
    if(pais != NULL && nombre != NULL)
    {
        strcpy(nombre, pais->nombre);
        isOk=1;
    }
    return isOk;
}
int pais_GetVac1(ePais* pais, int* vac1)
{
    int isOk=0;
    if(pais != NULL && vac1 != NULL)
    {
        *vac1 = pais->vac1dosis;
        isOk=1;
    }
    return isOk;
}
int pais_Getvac2(ePais* pais, int* vac2)
{
    int isOk=0;
    if(pais != NULL && vac2 != NULL)
    {
        *vac2 = pais->vac2dosis;
        isOk=1;
    }
    return isOk;
}
int pais_GetSinVac(ePais* pais, int* sinVac)
{
    int isOk=0;
    if(pais != NULL && sinVac != NULL)
    {
        *sinVac = pais->sinVacunar;
        isOk=1;
    }
    return isOk;
}
int mapearVacunas(void* pais)
{
    int isOk=0;
    ePais* auxpais=NULL;
    int min=1;
    int vac1;
    int vac2;
    int sinVac;
    int vac1Max=60;
    int vac2Max=40;
    int maxSinVac=100;
    if(pais != NULL)
    {
        auxpais = (ePais*) pais;
        vac1 = rand() % (vac1Max - min + 1) + min;
        auxpais->vac1dosis = vac1;
        vac2 = rand() % (vac2Max - min + 1) + min;
        auxpais->vac2dosis = vac2;
        sinVac = (maxSinVac - vac1);
        auxpais->sinVacunar = sinVac;
        if(sinVac != 0)
        {
            isOk=1;
        }
    }
    return isOk;
}
int filtrarPaisesExitosos(void* pais)
{
    int isOk=0;
    ePais* auxPais=NULL;
    if(pais != NULL)
    {
        auxPais = (ePais*) pais;
        if(auxPais->vac2dosis > 30)
        {
            isOk=1;
        }
    }
    return isOk;
}
int filtrarPaisesHorno(void* pais)
{
    int isOk=0;
    ePais* auxPais=NULL;
    if(pais != NULL)
    {
        auxPais = (ePais*) pais;
        if(auxPais->vac1dosis < auxPais->sinVacunar)
        {
            isOk=1;
        }
    }
    return isOk;
}
int ordenarPorVac(void* pais1, void* pais2)
{
    int isOk=0;
	ePais* country1;
	ePais* country2;
	if(pais1 != NULL && pais2 != NULL)
	{
		country1 = (ePais*) pais1;
		country2 = (ePais*) pais2;

		if(country1->vac1dosis > country2->vac1dosis)
		{
			isOk=1;
		}
		if(country1->vac1dosis < country2->vac1dosis)
		{
			isOk=-1;
		}
	}
	return isOk;
}
int mostrarListaMasCastigado(LinkedList* paises)
{
    int isOk=0;
    ePais* auxPais=NULL;
    int menorVac=0;
    int tam;
    if(paises != NULL)
    {
        tam = ll_len(paises);
        for(int i=0;i<tam;i++)
        {
            auxPais = ll_get(paises, i);
            mostrarMasCastigado(auxPais, &menorVac);
        }
        printf("El pais que menos vacunaron solo tienen: %d dosis\n", menorVac);
        isOk=1;
    }
    return isOk;
}
int mostrarMasCastigado(ePais* unPais, int* menorVac)
{
    int isOk=0;
    if(unPais != NULL && menorVac != NULL)
    {
        if(*menorVac == 0 || unPais->vac1dosis < *menorVac)
        {
            *menorVac = unPais->vac1dosis;
            printf("%s\n", unPais->nombre);
        }
    }

    return isOk;
}
