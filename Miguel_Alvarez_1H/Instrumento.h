#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED
#define TEXT_SIZE 20
/*
1*  REEMPLAZAR LOS TRES TIPOS DE NOMBRES "INSTRUMENTO X EL QUE QUIERAS(todo mayuscula)"
    "Instrumento x el que Quieras(primer letra en mayuscula)""instrumentos x que quieras(todo minuscula)"
*/
typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;


}Instrumento;


#endif // INSTRUMENTO_H_INCLUDED

int instrumento_Inicializar(Instrumento array[], int size);                                    //cambiar instrumento
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion);                    //cambiar instrumento
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion);                    //cambiar instrumento
int instrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion);                    //cambiar instrumento
int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice);                    //cambiar instrumento
int instrumento_alta(Instrumento array[], int size, int* contadorID);                          //cambiar instrumento
int instrumento_baja(Instrumento array[], int sizeArray);                                      //cambiar instrumento
int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado);
int instrumento_modificar(Instrumento array[], int sizeArray);                                //cambiar instrumento
int instrumento_ordenarPorDobleCriterio(Instrumento array[],int size, int orderFirst, int orderSecond);                                  //cambiar instrumento
int instrumento_listar(Instrumento array[], int size);                      //cambiar instrumento
void instrumento_mock(Instrumento arrayInstrumento[], int size,int *contadorId);                      //cambiar instrumento
void MenuInstrumento();
void MenuInstrumentoPrincipal();
void MenuInstrumentoModificacion();
int instrumento_ordenar(Instrumento array[],int size);
void MenuTipos2();

