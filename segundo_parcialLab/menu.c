#include "menu.h"



int menu()
{
	int opcion;

	system("cls");
	printf("    ***  Menu ***\n\n");
	printf("1. Cargar archivo\n");
	printf("2. Imprimir lista\n");
	printf("3. Asignar estad�sticas\n");
	printf("4. Filtrar por pa�ses exitosos\n");
	printf("5. Filtrar por pa�ses en el horno\n");
	printf("6. Ordenar por nivel de vacunaci�n\n");
	printf("7. Mostrar m�s castigado:\n");
	printf("8. Salir\n");
	printf("\nIngrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
