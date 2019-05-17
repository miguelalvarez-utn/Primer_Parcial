#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED
#define TEXT_SIZE 20
/*
1*  REEMPLAZAR LOS TRES TIPOS DE NOMBRES "FANTASMA X EL QUE QUIERAS(todo mayuscula)"
    "Fantasma x el que Quieras(primer letra en mayuscula)""fantasmas x que quieras(todo minuscula)"
*/
typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE];
    char varLongString[TEXT_SIZE];
    int varInt;
    float varFloat;
    char varChar;


}Fantasma;


#endif // FANTASMA_H_INCLUDED

int fantasma_Inicializar(Fantasma array[], int size);                                    //cambiar fantasma
int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion);                    //cambiar fantasma
int fantasma_buscarID(Fantasma array[], int size, int valorBuscado, int* posicion);                    //cambiar fantasma
int fantasma_buscarInt(Fantasma array[], int size, int valorBuscado, int* posicion);                    //cambiar fantasma
int fantasma_buscarString(Fantasma array[], int size, char* valorBuscado, int* indice);                    //cambiar fantasma
int fantasma_alta(Fantasma array[], int size, int* contadorID);                          //cambiar fantasma
int fantasma_baja(Fantasma array[], int sizeArray);                                      //cambiar fantasma
int fantasma_bajaValorRepetidoInt(Fantasma array[], int sizeArray, int valorBuscado);
int fantasma_modificar(Fantasma array[], int sizeArray);                                //cambiar fantasma
int fantasma_ordenarPorDobleCriterio(Fantasma array[],int size, int orderFirst, int orderSecond);                                  //cambiar fantasma
int fantasma_listar(Fantasma array[], int size);                      //cambiar fantasma
void fantasma_mock(Fantasma arrayFantasma[], int size,int *contadorId);                      //cambiar fantasma
void MenuFantasma();
void MenuFantasmaPrincipal();
void MenuFantasmaModificacion();
int fantasma_ordenar(Fantasma array[],int size);
