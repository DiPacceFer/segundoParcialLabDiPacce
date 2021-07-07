#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "paises.h"


#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED

int parser_ListFromText(FILE* pFile , LinkedList* pArrayList);
int parser_PaisesToText(char* path , LinkedList* paises);
