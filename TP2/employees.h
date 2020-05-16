typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

/*
*
*\brief Muestra el menu de opciones
*\param TextoOpcionesMenu, Es el texto a mostrar en el menu
*\return retorna el entero que se van a usar como opciones
*
*/
int showMenu(char menuText[]);

/*
*
*\brief Inicializa los lugares del array como vacios
*\param lista, Puntero al array de empleados
*\param len, Es el tamaño del array
*\return retorna -1 si hubo un error, 0 si funciono correctamente
*
*/
int initEmployees(eEmployee* lista, int len);
/*
*
*\brief agrega los datos del empleado
*\param lista, Puntero al array de empleados
*\param len, Es el tamaño del array
*\param id, Id del empleado
*\param name, Nombre del empleado
*\param lastName, Apellido del empleado
*\param salary, Salario del empleado
*\param sector, Sector del empleado
*\return Devuelve -1 si hubo un error y 1 si funciono correctamente
*
*/

int addEmployee(eEmployee* lista, int len, int id, char name[],char lastName[],float salary,int sector);
/*
*
*\brief Encuentra un empleado por su Id
*\param lista, Puntero al array de empleados
*\param len, Es el tamaño del array
*\param id, Es el id del empleado
*\return Devuelve el indice del empleado
*/
int findEmployeeById(eEmployee* lista, int len, int id);
/*
*
*\brief Hace una baja de empleado
*\param lista, Puntero al array de empleados
*\param len, Es el tamaño del array
*\param id, Es el id del empleado que se va a dar de baja
*\return Devuelve -1 si hubo un error y si funciono, el indice del empleado
*
*/
int removeEmployee(eEmployee* lista, int len, int id);
/*
*
*\brief Ordena los empleados por apellido y en caso de igualdad, por sector
*\param lista, Puntero al array de empleados
*\param len, Es el tamaño del array
*\param order, Indica si el orden de ordenado es ascendente o descendente
*\return Devuelve -1 si hubo un error y 0 si funciono correctamente
*
*/
int sortEmployees(eEmployee* lista, int len, int order);

/*
*
*\brief Imprime un solo empleado
*\param lista, lista de empleados
*\return nada
*
*/
void printOneEmployee(eEmployee lista);
/*
*
*\brief Imprime en pantalla el listado de empleados
*\param lista, Puntero al array de empleados
*\param len, Es el tamaño del array
*\return retorna -1 si hubo un error y 1 si funciono correctamente
*
*/
int printEmployees(eEmployee* lista, int len);
/*
*
*\brief Busca lugares del array vacios
*\param lista, Puntero al array de empleados
*\param len, Es el tamaño del array
*\return retorna el indice vacio del array
*
*/
int findIndex(eEmployee* lista, int len);
/*
*
*\brief Muestra el salario total, el promedio y los empleados con salario mayor al promedio
*\param lista, Puntero al array de empleados
*\param len, Es el tamaño del array
*\return retorna 0 si hubo un error y 1 si funciono correctamente
*
*/
int totalAndAverageSalary(eEmployee* lista, int len);
/*
*
*\brief Pide un dato del array de empleados y lo modifica
*\param lista, Puntero al array de empleados
*\param len, Es el tamaño del array
*\return retorna -1 si hubo un error y el lugar del array si funciono correctamente
*
*/
int modifyEmployee(eEmployee* lista, int len);
/*
*
*\brief Agrega un empleado
*\param lista, Puntero al array de empleados
*\param len, Es el tamaño del array
*\param siguienteId Id autoincrementado
*\param flagFirstEntry Bandera primera entrada
*\return Devuelve -1 si hubo un error y 0 si funciono correctamente
*
*/
int employeeAddition(eEmployee* lista, int len,int* siguienteId,int* flagFirstEntry);
