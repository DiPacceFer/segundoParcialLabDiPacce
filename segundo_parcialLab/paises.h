#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include <string.h>

#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

typedef struct{
    int id;
    char nombre[50];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}ePais;


#endif // PAISES_H_INCLUDED

ePais* pais_newParam(char* idStr, char* nombreStr, char* vac1Str, char* vac2Str, char* sinVacStr);
ePais* pais_new();
int pais_SetId(ePais* pais, int id);
int pais_SetNombre(ePais* pais, char* nombre);
int pais_SetVac1(ePais* pais, int vac1);
int pais_SetVac2(ePais* pais, int vac2);
int pais_SetSinVac(ePais* pais, int sinVac);
int mostrarListaPaises(LinkedList* paises);
int mostrarListaPaises(LinkedList* paises);
int mostrarPais(ePais* unPais);
int pais_GetId(ePais* pais, int* id);
int pais_GetNombre(ePais* pais, char* nombre);
int pais_GetVac1(ePais* pais, int* vac1);
int pais_Getvac2(ePais* pais, int* vac2);
int pais_GetSinVac(ePais* pais, int* vac2);
int mapearVacunas(void* pais);
int filtrarPaisesExitosos(void* pais);
int filtrarPaisesHorno(void* pais);
int ordenarPorVac(void* pais1, void* pais2);
int mostrarMasCastigado(ePais* unPais, int* menorVac);
int mostrarListaMasCastigado(LinkedList* paises);

