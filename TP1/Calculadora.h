/*
*
*\brief Muestra el menu de opciones
*\param TextoOpcionesMenu, Es el texto a mostrar en el menu
*\return retorna el entero que se van a usar como opciones
*
*/
int MostrarMenu (char TextoOpcionesMenu[]);

/*
*
*\brief Pide al usuario que ingrese un numero
*\param Mensaje, Es lo que el usuario va a ver cuando se le pida que ingrese el numero
*\return retorna el numero ingresado
*
*/
int PedirNumero (char Mensaje[]);

/*
*
*\brief suma dos numeros
*\param NumeroUno, es el primer numero a sumar
*\param NumeroDos, es el segundo numero a sumar
*\return retorna el resultado de la suma
*
*/
int suma(int NumeroUno, int NumeroDos);

/*
*
*\brief resta dos numeros
*\param NumeroUno, es el primer numero a restar
*\param NumeroDos, es el segundo numero a restar
*\return retorna el resultado de la resta
*
*/
int resta(int NumeroUno, int NumeroDos);

/*
*
*\brief divide dos numeros
*\param NumeroUno, es el dividendo
*\param NumeroDos, es el divisor
*\return retorna el resultado de la division
*
*/
float division(int NumeroUno, int NumeroDos);

/*
*
*\brief multiplicacion dos numeros
*\param NumeroUno, es el primer numero a multiplicar
*\param NumeroDos, es el segundo numero a multiplicar
*\return retorna el producto de la multiplicacion
*
*/
int multiplicacion(int NumeroUno, int NumeroDos);

/*
*
*\brief calcula el factorial de un numero
*\param NumeroUno, es el primer numero al que se le calculara el factorial
*\param NumeroDos, es el segundo numero al que se le calculara el factorial
*\return retorna retorna el factorial de los numeros
*
*/
long int factorial(int Numero);
