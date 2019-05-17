#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Musico.h"
#include "Orquesta.h"
#include "utn.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)                                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)                                                   //cambiar campo edad
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice)                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], Orquesta arrayB[],Instrumento arrayC[],int size, int sizeB,int sizeC,int* contadorID)                          //cambiar musico
{
    int retorno=-1;
    int posicion;
    int auxId;
    int auxId2;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)                          //cambiar musico
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            orquesta_listar(arrayB,sizeB);
            utn_getUnsignedInt("\nID del orquesta: ","\nError",1,sizeof(int),1,10,1,&auxId);
            if(orquesta_buscarID(arrayB,sizeB,auxId,&posicion))
            {
                printf("Id orquesta no existe");
            }
            else
            {

                instrumento_listar(arrayC,sizeC);
                utn_getUnsignedInt("\nID del instrumento: ","\nError",1,sizeof(int),1,10,1,&auxId2);
                if(instrumento_buscarID(arrayC,sizeC,auxId2,&posicion))
                {
                    printf("ID Instrumento no existe");
                }
                else
                {
                    (*contadorID)++;
                    array[posicion].idOrquesta = auxId;
                    array[posicion].idInstrumento = auxId2;
                    array[posicion].idUnico=*contadorID;                                                       //campo ID
                    array[posicion].isEmpty=0;
                    utn_getName("Nombre: ","\nError\n",1,TEXT_SIZE,1,array[posicion].nombre);
                    utn_getName("Apellido: ","\nError\n",1,TEXT_SIZE,1,array[posicion].apellido);                 //mensaje + cambiar campo titulo
                    printf("ID: %d\nID orquesta: %d\nID instrumento: %d\nNombre: %s\nApellido: %s",
                    array[posicion].idUnico,
                    array[posicion].idOrquesta,
                    array[posicion].idInstrumento,
                    array[posicion].nombre,
                    array[posicion].apellido);
                    retorno=0;

                }
            }

        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)                                      //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].edad=0;                                                               //cambiar campo edad
                                                                    //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");                                               //cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                array[i].edad=0;                                                               //cambiar campo edad
                                                                            //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[],Orquesta arrayB[],int sizeArray,int sizeB)                                //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;
    int auxId;                                                                                       //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       MenuMusicoModificacion();

                utn_getUnsignedInt("","\nError",1,sizeof(int),1,4,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getUnsignedInt("Edad: ","\nError\n",1,sizeof(int),1,10,1,&array[posicion].edad);            //mensaje + cambiar campo edad
                        break;
                    case 2:
                        utn_getName("Nombre: ","\nError\n",1,TEXT_SIZE,1,array[posicion].nombre); //mensaje + cambiar campo varFloat
                        break;
                    case 3:
                        utn_getName("Apellido: ","\nError\n",1,TEXT_SIZE,1,array[posicion].apellido);                      //mensaje + cambiar campo nombre
                        break;
                    case 4:
                        utn_getUnsignedInt("Edad: ","\nError\n",1,sizeof(int),1,10,1,&auxId);
                        if(orquesta_buscarID(arrayB,sizeB,auxId,&posicion))
                        {
                            printf("ID No existe");
                            break;
                        }
                        array[posicion].idOrquesta = auxId;

                    default:

                        printf("\nOpcion no valida\n");
                }
            }while(opcion!=4);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size)                      //cambiar musico
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
                printf("\n ID: %d\nEdad: %d\nNombre: %s\nApellido: %s\nID orquesta %d\nID instrumento: %d\n",
                       array[i].idUnico,
                       array[i].edad,
                       array[i].nombre,
                       array[i].apellido,
                       array[i].idOrquesta,
                       array[i].idInstrumento);

            }
     //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array musico Array de musico
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenar(Musico array[],int size)
{
   int i,j;
   int retorno;
   Musico buffer;

   for(i = 0;i < size-1;i++)
   {
       for(j =i+1;j < size-1;j++)
       {
           if(strcmp(array[i].apellido,array[j].apellido)> 0)
           {
               buffer = array[i];
               array[i] = array[j];
               array[j] = buffer;
               retorno = 0;
           }
           else if(strcmp(array[i].nombre,array[j].nombre)> 0)
           {
               buffer = array[i];
               array[i] = array[j];
               array[j] = buffer;
               retorno = 0;
           }
       }
   }
   return retorno;
}

void musico_mock(Musico arrayMusico[], int size,int *contadorId)                      //cambiar musico
{
    //*******************************************************************
    int aux = 0;
    arrayMusico[0].idUnico=0;
    arrayMusico[0].isEmpty=0;
    arrayMusico[0].edad=20;
    strcpy(arrayMusico[0].apellido,"CCCCC");
    strcpy(arrayMusico[0].nombre,"CCCCC");
    arrayMusico[0].idOrquesta=1;
    arrayMusico[0].idInstrumento=1;
    *contadorId =++ aux;

    arrayMusico[1].idUnico=1;
    arrayMusico[1].isEmpty=0;
    arrayMusico[1].edad=21;
    strcpy(arrayMusico[1].apellido,"AAAAA");
    strcpy(arrayMusico[1].nombre,"AAAAA");
    arrayMusico[1].idOrquesta=2;
    arrayMusico[1].idInstrumento=2;
    *contadorId =++ aux;

    arrayMusico[2].idUnico=2;
    arrayMusico[2].isEmpty=0;
    arrayMusico[2].edad=22;
    strcpy(arrayMusico[2].apellido,"BBBBB");
    strcpy(arrayMusico[2].nombre,"CCCCCC");
    arrayMusico[2].idOrquesta=3;
    arrayMusico[2].idInstrumento=3;
    *contadorId =++ aux;

    arrayMusico[3].idUnico=3;
    arrayMusico[3].isEmpty=0;
    arrayMusico[3].edad=23;
    strcpy(arrayMusico[3].apellido,"BBBBB");
    strcpy(arrayMusico[3].nombre,"BBBBBB");
    arrayMusico[3].idOrquesta=1;
    arrayMusico[3].idInstrumento=1;

}
//////////////////////////////////
void MenuMusico()
{
    printf("\n\nMENU MUSICOS\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - Modificacion\n");
    printf("4 - Listar\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}

void MenuMusicoPrincipal()
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
void MenuMusicoModificacion()
{
    printf("\n\nMENU MODIFICACION\n");
    printf("--------------\n");
    printf("1 - Nueva edad\n");
    printf("2 - Nuevo nombre\n");
    printf("3 - Nuevo apellido\n");
    printf("4 - Nueva tipo Orquesta\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}

