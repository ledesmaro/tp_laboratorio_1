#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employees.h"
#include "utn.h"

int showMenu(char menuText[])
{
    int option;

    printf("%s", menuText);
    scanf("%d", &option);

    return option;
}

int initEmployees(eEmployee* lista, int len)
{
    int respuesta = -1;
    int i;
    if(lista != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            respuesta = 0;
            lista[i].isEmpty = 1;
        }
    }

    return respuesta;
}

int employeeAddition(eEmployee* lista, int len,int* siguienteId,int* flagFirstEntry)
{
    int bandera = -1;
    int banderaNombre = 0;
    int banderaApellido = 0;
    int banderaSalario = 0;
    int banderaSector = 0;

    if(lista != NULL && len > 0)
    {
        int existe;
        int id;

        eEmployee miEmpleado;

        id=*siguienteId;


        existe = findIndex(lista,len);

        if(existe == -1)
        {
            printf("El sistema esta lleno.\n");
            system("pause");
        }
        else
        {
            system("cls");
            if(utn_getNombre(miEmpleado.name,51,"Ingrese un nombre ","Error, solo se puede poner letras y nombres sin espacios.\n",3)==0)
            {
                banderaNombre = 1;
            }
            if(utn_getNombre(miEmpleado.lastName,51,"Ingrese un apellido ","Error, solo se puede poner letras y apellidos sin espacios\n",3)==0)
            {
                banderaApellido = 1;
            }
            if(utn_getNumeroFlotante(&miEmpleado.salary,"Ingrese un salario: ","Error. Solo se pueden poner numeros entre 0 y 100.000.\n",0,100000,3)==0)
            {
                banderaSalario = 1;
            }
            if(utn_getNumero(&miEmpleado.sector,"Ingrese un sector(1 - 5): ","Error. Solo disponible sectores del 1 al 5.\n",1,5,3)==0)
            {
                banderaSector = 1;
            }
            if(banderaNombre && banderaApellido && banderaSalario && banderaSector && addEmployee(lista,len,id,miEmpleado.name,miEmpleado.lastName,miEmpleado.salary,miEmpleado.sector) == -1)
            {
                printf("Error al cargar datos. \n");
                system("pause");
            }
            else
            {
                (*siguienteId)++;
                (*flagFirstEntry)=1;
                bandera = 0;
                system("pause");
            }
        }
    }
    return bandera;
}

int totalAndAverageSalary(eEmployee* lista, int len)
{
    int i;
    int j;
    float acumulador = 0;
    int contadorEmpleados = 0;
    int contadorSuperaPromedio = 0;
    int flag = 0;
    float promedio;

    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty == 0)
        {
            acumulador = acumulador + lista[i].salary;
            contadorEmpleados++;
            flag = 1;
        }
    }

    promedio = (float)acumulador/contadorEmpleados;

    for(j=0;j<len;j++)
    {
        if(lista[j].isEmpty == 0 && lista[j].salary > promedio)
        {
            contadorSuperaPromedio++;
        }
    }

    if(flag == 1)
    {
        printf("Total de salarios: %.2f\n", acumulador);
        printf("Promedio de salarios: %.2f\n", promedio);
        printf("Total de empleados que superan el promedio de salario: %d \n", contadorSuperaPromedio);
    }

    return flag;
}

int findIndex(eEmployee* lista, int len)
{
    int i;
    int indice;

    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int addEmployee(eEmployee* lista, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int bandera = -1;

    if(lista != NULL && len > 0)
    {
        int indice = -1;

        eEmployee miEmpleado;

        indice = findIndex(lista, len);

        miEmpleado.id = id;
        strcpy(miEmpleado.name, name);
        strcpy(miEmpleado.lastName, lastName);
        miEmpleado.salary = salary;
        miEmpleado.sector = sector;
        miEmpleado.isEmpty = 0;

        lista[indice] = miEmpleado;
        bandera = 1;
    }

    return bandera;
}

int printEmployees(eEmployee* lista, int len)
{
    int i;
    int bandera = -1;


    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty == 0)
        {
            printOneEmployee(lista[i]);
            bandera = 1;
        }
    }
    if(bandera == -1)
    {
        printf("No se han podido mostrar los empleados.\n");
        system("pause");
    }

    return bandera;
}

void printOneEmployee(eEmployee lista)
{

    printf("%4d %4s %4s %.2f %4d\n", lista.id,
                                     lista.name,
                                     lista.lastName,
                                     lista.salary,
                                     lista.sector);
}

int findEmployeeById(eEmployee* lista, int len, int id)
{
    int i;
    int indice;

    if(lista != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int removeEmployee(eEmployee* lista, int len, int id)
{
    int existe = -1;

    if(lista != NULL && len > 0)
    {
        existe = findEmployeeById(lista, len, id);

        if(existe == -1)
        {
            printf("No existe.\n");
            system("pause");
        }
        else
        {
            lista[existe].isEmpty = 1;
            printf("Baja de empleado realizada con exito.\n");
            system("pause");
            system("cls");
        }
    }

    return existe;
}

int modifyEmployee(eEmployee* lista, int len)
{
    int existe = -1;

    if(lista != NULL && len > 0)
    {
        int id;
        int opcion;
        eEmployee miEmpleado;

        printf("Ingrese el id a buscar:\n");
        scanf("%d", &id);

        existe = findEmployeeById(lista, len, id);

        if(existe== -1)
        {
            printf("No existe empleado.");
        }
        else
        {

            do
            {
                printf("1. Modificar nombre\n2. Modificar apellido\n3. Modificar salario\n4. Modificar sector\n5. Salir\nElija una opcion: ");
                scanf("%d", &opcion);

                switch(opcion)
                {
                    case 1:
                        if(utn_getNombre(miEmpleado.name,51,"Ingrese el nuevo nombre: \n","Solo podes digitar letras y un nombre sin espacios.",3)== -1)
                        {
                            printf("No se ha podido modificar el nombre.");
                        }
                        else
                        {
                            strcpy(lista[existe].name, miEmpleado.name);
                        }
                        break;
                    case 2:
                        if(utn_getNombre(miEmpleado.lastName,51,"Ingrese el nuevo apelllido: \n","Solo podes digitar letras y un apellido sin espacios. \n",3)==-1)
                        {
                            printf("No se ha podido modificar el apellido.");
                        }
                        else
                        {
                            strcpy(lista[existe].lastName, miEmpleado.lastName);
                        }
                        break;
                    case 3:
                        if(utn_getNumeroFlotante(&miEmpleado.salary,"Ingrese un salario ","Error. Solo se puede poner numeros entre 0 y 100.000.\n",0,100000,3)== -1)
                        {
                            printf("No se ha podido modificar el salario.");
                        }
                        else
                        {
                            lista[existe].salary = miEmpleado.salary;
                        }
                        break;
                    case 4:
                        if(utn_getNumero(&miEmpleado.sector,"Ingrese el sector(1 - 5): ","Error. Solo disponibles sectores del 1 al 5.\n",1,5,3)==-1)
                        {
                            printf("No se ha podido modificar el sector.");
                        }
                        else
                        {
                            lista[existe].sector = miEmpleado.sector;
                        }
                }
            }while(opcion!= 5);
        }
    }

    return existe;
}

int sortEmployees(eEmployee* lista, int len, int order)
{
    int error = -1;

    if(lista != NULL && len > 0)
    {
        error = 0;

        eEmployee aux;

        if(order == 1)
        {
            int i;
            int j;

            for(i=0; i<len-1; i++)
            {
                for(j=i+1; j<len; j++)
                {
                    if(strcmp(lista[i].lastName, lista[j].lastName)>0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].lastName, lista[j].lastName)==0 && lista[i].sector < lista[j].sector)
                        {
                            aux = lista[i];
                            lista[i] = lista[j];
                            lista[j] = aux;
                        }
                    }
                }
            }
        }

        if(order == 2)
        {
            int i;
            int j;

            for(i=0; i<len-1; i++)
            {
                for(j=i+1; j<len; j++)
                {
                    if(strcmp(lista[i].lastName, lista[j].lastName)<0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].lastName, lista[j].lastName)==0 && lista[i].sector > lista[j].sector)
                        {
                            aux = lista[i];
                            lista[i] = lista[j];
                            lista[j] = aux;
                        }
                    }
                }
            }
        }
    }

    return error;
}
