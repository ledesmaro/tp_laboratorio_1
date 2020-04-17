#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

int main()
{
    int opcion;
    int PrimerNumero;
    int SegundoNumero;
    int ResSuma;
    int ResResta;
    float ResDivision;
    int ResMultiplicacion;
    long int FactorialNumeroUno;
    long int FactorialNumeroDos;

    do
    {
        opcion = MostrarMenu("1- Ingresar 1er operando\n2- Ingresar 2do operando\n3- Calcular todas las operaciones\n4- Mostrar los resultados\n5- Salir\nElija una opcion: ");

        switch(opcion)
        {
            case 1:
                PrimerNumero = PedirNumero("Ingrese un numero: ");
                break;
            case 2:
                SegundoNumero = PedirNumero("Ingrese otro numero: ");
                system("pause");
                system("cls");
                break;
            case 3:
                printf("a) Calcular la suma\n");
                printf("b) Calcular la resta\n");
                printf("c) Calcular la division\n");
                printf("d) Calcular la multiplicacion\n");
                printf("e) Calcular el factorial\n");
                suma(PrimerNumero, SegundoNumero);
                resta(PrimerNumero, SegundoNumero);
                division(PrimerNumero, SegundoNumero);
                multiplicacion(PrimerNumero, SegundoNumero);
                system("pause");
                system("cls");
                break;
            case 4:
                ResSuma = suma(PrimerNumero, SegundoNumero);
                printf("El resultado de la suma es: %d\n", ResSuma);
                ResResta = resta(PrimerNumero, SegundoNumero);
                printf("El resultado de la resta es: %d\n", ResResta);
                if(SegundoNumero == 0)
                {
                    printf("Error. No es posible dividir por cero.\n");
                }else{
                    ResDivision = division(PrimerNumero, SegundoNumero);
                    printf("El resultado de la division es: %.2f\n", ResDivision);
                }
                ResMultiplicacion = multiplicacion(PrimerNumero, SegundoNumero);
                printf("El resultado de la multiplicacion es: %d\n", ResMultiplicacion);
                FactorialNumeroUno = factorial(PrimerNumero);
                printf("El factorial del 1er operando es: %ld\n", FactorialNumeroUno);
                FactorialNumeroDos = factorial(SegundoNumero);
                printf("El factorial del 2do operando es: %ld\n", FactorialNumeroDos);
                break;
        }
    }while(opcion!=5);


    return 0;
}

