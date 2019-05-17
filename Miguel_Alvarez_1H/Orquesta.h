#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED
#define TEXT_SIZE 20
/*
1*  REEMPLAZAR LOS TRES TIPOS DE NOMBRES "ORQUESTA X EL QUE QUIERAS(todo mayuscula)"
    "Orquesta x el que Quieras(primer letra en mayuscula)""orquestas x que quieras(todo minuscula)"
*/
typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char lugar[TEXT_SIZE];
    int tipo;

}Orquesta;


#endif // ORQUESTA_H_INCLUDED

int orquesta_Inicializar(Orquesta array[], int size);                                    //cambiar orquesta
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);                    //cambiar orquesta
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice);                    //cambiar orquesta
int orquesta_alta(Orquesta array[], int size, int* contadorID);                          //cambiar orquesta
int orquesta_baja(Orquesta array[], int sizeArray);                                      //cambiar orquesta
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado);
int orquesta_modificar(Orquesta array[], int sizeArray);                                //cambiar orquesta
int orquesta_ordenarPorDobleCriterio(Orquesta array[],int size, int orderFirst, int orderSecond);                                  //cambiar orquesta
int orquesta_listar(Orquesta array[], int size);                      //cambiar orquesta
void orquesta_mock(Orquesta arrayOrquesta[], int size,int *contadorId);                      //cambiar orquesta
void MenuOrquesta();
void MenuOrquestaPrincipal();
void MenuOrquestaModificacion();
int orquesta_ordenar(Orquesta array[],int size);
void MenuTipos();

