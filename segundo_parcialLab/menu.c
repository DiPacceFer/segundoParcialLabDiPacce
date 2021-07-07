#include "menu.h"



int menu()
{
	int opcion;

	system("cls");
	printf("    ***  Menu ***\n\n");
	printf("1. Cargar archivo\n");
	printf("2. Imprimir lista\n");
	printf("3. Asignar estadísticas\n");
	printf("4. Filtrar por países exitosos\n");
	printf("5. Filtrar por países en el horno\n");
	printf("6. Ordenar por nivel de vacunación\n");
	printf("7. Mostrar más castigado:\n");
	printf("8. Salir\n");
	printf("\nIngrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
