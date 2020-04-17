int MostrarMenu (char TextoOpcionesMenu[])
{
    int opcion;

    printf("%s", TextoOpcionesMenu);
    scanf("%d", &opcion);

    return opcion;
}

int PedirNumero (char Mensaje[])
{
    int numero;

    printf("%s", Mensaje);
    scanf("%d", &numero);

    return numero;
}

int suma(int NumeroUno, int NumeroDos)
{
    int Sumar;

    Sumar = NumeroUno + NumeroDos;

    return Sumar;
}

int resta(int NumeroUno, int NumeroDos)
{
    int Restar;

    Restar = NumeroUno - NumeroDos;

    return Restar;
}

float division(int NumeroUno, int NumeroDos)
{
    float Dividir;

    Dividir = (float)NumeroUno/NumeroDos;

    return Dividir;
}

int multiplicacion(int NumeroUno, int NumeroDos)
{
    int Multiplicar;

    Multiplicar = NumeroUno*NumeroDos;

    return Multiplicar;
}

long int factorial(int Numero)
{
    int i;
    int fact = 1;

    if(Numero<0)
    {
        printf("No es posible calcular el factorial de un numero negativo.\n");
    }
    else{
        for(i=1;i<=Numero;i++)
        {
            fact = fact * i;
        }

        return fact;
    }
}
