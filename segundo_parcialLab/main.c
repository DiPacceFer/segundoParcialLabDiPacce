#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "paises.h"
#include "menu.h"
#include "Controller.h"
#include "validaciones.h"

int main()
{
    int opcion;
    char nombreArchivo[120];

    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* paisesExitosos = ll_newLinkedList();
    LinkedList* paisesHorno = ll_newLinkedList();
    srand(time(NULL));
    do{
        switch(menu())
        {
       case 1:
            printf("Ingrese nombre del archivo: ");
            fflush(stdin);
            gets(nombreArchivo);
            controller_loadFromText(nombreArchivo, listaPaises);
            break;
       case 2:
            if(ll_isEmpty(listaPaises)==1)
            {
                printf("Primero debe cargar el archivo vacunas.csv en opcion 1\n");
                system("pause");
                break;
            }
            else
            {
                controller_ListVac(listaPaises);
                system("pause");
                break;
            }
       case 3:
            ll_map(listaPaises, mapearVacunas);
            system("pause");
            break;
       case 4:
            paisesExitosos = ll_filter(listaPaises, filtrarPaisesExitosos);
            controller_saveAsText("paisesExitosos.csv", paisesExitosos);
            break;
       case 5:
            paisesHorno = ll_filter(listaPaises, filtrarPaisesHorno);
            controller_saveAsText("paisesEnElHorno.csv", paisesHorno);
            break;
       case 6:
            ll_sort(listaPaises, ordenarPorVac, 1);
            mostrarListaPaises(listaPaises);
            system("pause");
            break;
       case 7:
            mostrarListaMasCastigado(listaPaises);
            system("pause");
            break;
       case 8:
        opcion = 8;
        break;
        }
    }while(opcion != 8);





    return 0;
}
