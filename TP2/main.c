#include <stdio.h>
#include <stdlib.h>
#include "employees.h"
#include "utn.h"

#define ELEMENTS 1000

int main()
{
    int option;

    eEmployee listEmployees[ELEMENTS];
    initEmployees(listEmployees, ELEMENTS);
    int id = 10;
    int idABuscar = 10;
    int flag = 0;
    int orden;

    do
    {
        option = showMenu("1- ALTAS\n2- MODIFICAR\n3- BAJA\n4- INFORMAR\n5- Salir\nElija una opcion: ");

        switch(option)
        {
            case 1:
                employeeAddition(listEmployees, ELEMENTS,&id,&flag);
                break;
            case 2:
                modifyEmployee(listEmployees, ELEMENTS);
                system("pause");
                system("cls");
                break;
            case 3:
                printf("Ingrese id: ");
                scanf("%d", &idABuscar);
                removeEmployee(listEmployees, ELEMENTS, idABuscar);
                break;
            case 4:
                printf("1- Ordenar ascendetemente.\n2- Ordenar descendentemente.\nIngrese la forma de ordenamiento (1-2): \n");
                scanf("%d", &orden);
                sortEmployees(listEmployees, ELEMENTS, orden);
                system("pause");
                system("cls");
                printEmployees(listEmployees, ELEMENTS);
                totalAndAverageSalary(listEmployees, ELEMENTS);
                system("pause");
                system("cls");
                break;
        }
    }while(option!=5);

    return 0;
}
