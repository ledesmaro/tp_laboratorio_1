#ifndef UTN_H_
#define UTN_H_

/**
 * \brief Pide un entero, con limite de minimo y maximo, limite de intentos y mensaje de error
 * \param pResultado Puntero a la direccion de memoria donde va el retorno
 * \param mensaje Mensaje pidiendo el numero
 * \param mensajeError Muestra un posible mensaje de error
 * \param minimo Es el numero maximo que se puede poner
 * \param maximo Es el minimo minimo que se puede poner
 * \param reintentos Es la cantidad de veces que se puede pedir
 * \return Retorna 0 si se guardo el numero y -1 si hubo un error
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief Pide un numero flotante, con limite de minimo y maximo, limite de intentos y mensaje de error
 * \param pResultado Puntero a la direccion de memoria donde va el retorno
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \param reintentos Es la cantidad de veces que se puede pedir
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
 * \brief Pide un nombre y muestra un mensaje para pedirlo y un mensaje de error en caso de que no haya funcionado, tambien tiene limite de intentos
 * \param pResultado Puntero a la direccion de memoria donde va el retorno
 * \param longitud Es la longitud del array
 * \param mensaje Es el mensaje que pide el nombre
 * \param mensajeError Muestra un posible mensaje de error
 * \param reintentos Es la cantidad de veces que se puede pedir
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);


#endif /* UTN_H_ */
