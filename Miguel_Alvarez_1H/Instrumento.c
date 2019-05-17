#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Instrumento.h"
#include "utn.h" //cambiar por nombre entidad

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array instrumento Array of instrumento
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumento_Inicializar(Instrumento array[], int size)                                    //cambiar instrumento
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipo==valorBuscado)                                                   //cambiar campo tipo
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento array[], int size, int* contadorID)                          //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int opcion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)                          //cambiar instrumento
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            do
            {
                MenuTipos2();
                utn_getUnsignedInt("\nElija tipo: ","\nError",1,sizeof(int),1,10,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        array[posicion].tipo = 1;
                        break;
                    case 2:
                        array[posicion].tipo = 2;
                        break;
                    case 3:
                        array[posicion].tipo = 3;
                        break;
                    case 4:
                        array[posicion].tipo = 4;
                        break;
                        default:
                        printf("Opcion invalida");
                }
            }while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);

                       //mensaje + cambiar campo tipo
                         //mensaje + cambiar campo varFloat
            utn_getName("\nNombre de instrumento: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                           //mensaje + cambiar campo varLongString
            printf("ID: %d\ntipo: %d\nnombre: %s",
                    array[posicion].idUnico,
                    array[posicion].tipo,
                    array[posicion].nombre);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_baja(Instrumento array[], int sizeArray)                                      //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].tipo=0;                                                               //cambiar campo tipo
                                                                        //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
                                                //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].tipo=0;                                                               //cambiar campo tipo
                                                                            //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                                                              //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int instrumento_modificar(Instrumento array[], int sizeArray)                                //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       MenuInstrumentoModificacion();

                utn_getUnsignedInt("","\nError",1,sizeof(int),1,6,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getUnsignedInt("Int: ","\nError\n",1,sizeof(int),1,10,1,&array[posicion].tipo);            //mensaje + cambiar campo tipo
                        break;
                    case 2:
                                   //mensaje + cambiar campo varFloat
                        break;
                    case 3:
                        utn_getName("Text1: ","\nError\n",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 4:
                                     //mensaje + cambiar campo varLongString
                        break;
                    default:
                        printf("\nOpcion no valida\n");
                }
            }while(opcion!=6);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************


//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento array[], int size)                      //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                printf("\n---------------------------------------\n");
                printf("\nID: %d\ntipo Instrumento: %d\nnombre: %s\n",
                       array[i].idUnico,
                       array[i].tipo,
                       array[i].nombre);
            }
     //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


void instrumento_mock(Instrumento arrayInstrumento[], int size,int *contadorId)                      //cambiar instrumento
{
    //*******************************************************************
    int aux = 0;
    arrayInstrumento[0].idUnico=0;
    arrayInstrumento[0].isEmpty=0;
    arrayInstrumento[0].tipo=2;
    strcpy(arrayInstrumento[0].nombre,"CCCCC");
    *contadorId =++ aux;

    arrayInstrumento[1].idUnico=1;
    arrayInstrumento[1].isEmpty=0;
    arrayInstrumento[1].tipo=1;
    strcpy(arrayInstrumento[1].nombre,"AAAAA");
    *contadorId =++ aux;

    arrayInstrumento[2].idUnico=2;
    arrayInstrumento[2].isEmpty=0;
    arrayInstrumento[2].tipo=4;
    strcpy(arrayInstrumento[2].nombre,"CCCCCC");
    *contadorId =++ aux;

    arrayInstrumento[3].idUnico=3;
    arrayInstrumento[3].isEmpty=0;
    arrayInstrumento[3].tipo=3;
    strcpy(arrayInstrumento[3].nombre,"BBBBBB");

}
//////////////////////////////////
void MenuInstrumento()
{
    printf("\n\nMENU INSTRUMENTOS\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - lista\n");
    printf("Elija opcion: ");
}

void MenuInstrumentoPrincipal()
{
    printf("\n\nMENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - struct1\n");
    printf("2 - struct2\n");
    printf("3 - struct3\n");
    printf("4 - struct4\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}
////////////////////////////////////
void MenuInstrumentoModificacion()
{
    printf("\n\nMENU MODIFICACION\n");
    printf("--------------\n");
    printf("1 - int\n");
    printf("2 - float\n");
    printf("3 - text1\n");
    printf("4 - text2\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}
void MenuTipos2()
{
    printf("\n\nMENU MODIFICACION\n");
    printf("--------------\n");
    printf("1 - cuerdas\n");
    printf("2 - viento-madera\n");
    printf("3 - viento-metal\n");
    printf("4 - percusion\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}

