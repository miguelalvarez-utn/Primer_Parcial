#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#define TEXT_SIZE 20
#include "Orquesta.h"
#include "Instrumento.h"
/*
1*  REEMPLAZAR LOS TRES TIPOS DE NOMBRES "MUSICO X EL QUE QUIERAS(todo mayuscula)"
    "Musico x el que Quieras(primer letra en mayuscula)""musicos x que quieras(todo minuscula)"
*/
typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int edad;
    int idOrquesta;
    int idInstrumento;
}Musico;


#endif // MUSICO_H_INCLUDED

int musico_Inicializar(Musico array[], int size);                                    //cambiar musico
int musico_buscarEmpty(Musico array[], int size, int* posicion);                    //cambiar musico
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice);                    //cambiar musico
int musico_alta(Musico array[], Orquesta arrayB[],Instrumento arrayC[],int size, int sizeB,int sizeC,int* contadorID) ;                        //cambiar musico
int musico_baja(Musico array[], int sizeArray);                                      //cambiar musico
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], int sizeArray);                                //cambiar musico
int musico_ordenarPorDobleCriterio(Musico array[],int size, int orderFirst, int orderSecond);                                  //cambiar musico
int musico_listar(Musico array[], int size);                      //cambiar musico
void musico_mock(Musico arrayMusico[], int size,int *contadorId);                      //cambiar musico
void MenuMusico();
void MenuMusicoPrincipal();
void MenuMusicoModificacion();
int musico_ordenar(Musico array[],int size);
