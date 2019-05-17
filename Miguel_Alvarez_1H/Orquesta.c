#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Orquesta.h"
#include "utn.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquesta Array of orquesta
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta array[], int size)                                    //cambiar orquesta
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)                    //cambiar orquesta
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)                    //cambiar orquesta
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion)                    //cambiar orquesta
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)                    //cambiar orquesta
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)                          //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int opcion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)                          //cambiar orquesta
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
            MenuTipos();
            utn_getUnsignedInt("\nIngreses: ","\nError",1,sizeof(int),1,4,1,&opcion);
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
                    default:
                    printf("Opcion invalida");
            }
            }while(opcion != 1 && opcion != 2 && opcion != 3);

                       //mensaje + cambiar campo tipo
                    //mensaje + cambiar campo varFloat
            utn_getName("\nIngrese Nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getTexto("\nLugar: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);                 //mensaje + cambiar campo lugar
            printf("ID: %d\n tipo: %d\nnombre: %s\n lugar: %s",
                array[posicion].idUnico,
                array[posicion].tipo,
                array[posicion].nombre,
                array[posicion].lugar);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[], int sizeArray)                                      //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].tipo=0;                                                               //cambiar campo tipo                                                            //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].lugar,"");                                               //cambiar campo lugar
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                array[i].tipo=0;                                                               //cambiar campo tipo                                                            //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].lugar,"");                                               //cambiar campo lugar
            }
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int orquesta_modificar(Orquesta array[], int sizeArray)                                //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       MenuOrquestaModificacion();

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
                        utn_getTexto("Text2: ","\nError\n",1,TEXT_SIZE,1,array[posicion].lugar);             //mensaje + cambiar campo lugar
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
//Ordenar


//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)                      //cambiar orquesta
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
                printf("\n ID: %d\nTipo de Orquesta: %d\nNombre: %s\nLugar: %s",
                       array[i].idUnico,
                       array[i].tipo,
                       array[i].nombre,
                       array[i].lugar);
            }
    //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int orquesta_ordenar(Orquesta array[],int size)
{
   int i,j;
   int retorno;
   Orquesta buffer;

   for(i = 0;i < size-1;i++)
   {
       for(j =i+1;j < size-1;j++)
       {
           if(strcmp(array[i].lugar,array[j].lugar)> 0)
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

void orquesta_mock(Orquesta arrayOrquesta[], int size,int *contadorId)                      //cambiar orquesta
{
    //*******************************************************************
    int aux = 0;
    arrayOrquesta[0].idUnico=0;
    arrayOrquesta[0].isEmpty=0;
    arrayOrquesta[0].tipo=2;
    strcpy(arrayOrquesta[0].lugar,"CCCCC");
    strcpy(arrayOrquesta[0].nombre,"CCCCC");
    *contadorId =++ aux;

    arrayOrquesta[1].idUnico=1;
    arrayOrquesta[1].isEmpty=0;
    arrayOrquesta[1].tipo=1;
    strcpy(arrayOrquesta[1].lugar,"AAAAA");
    strcpy(arrayOrquesta[1].nombre,"AAAAA");
    *contadorId =++ aux;

    arrayOrquesta[2].idUnico=2;
    arrayOrquesta[2].isEmpty=0;
    arrayOrquesta[2].tipo=3;
    strcpy(arrayOrquesta[2].lugar,"BBBBB");
    strcpy(arrayOrquesta[2].nombre,"CCCCCC");
    *contadorId =++ aux;

    arrayOrquesta[3].idUnico=3;
    arrayOrquesta[3].isEmpty=0;
    arrayOrquesta[3].tipo=1;
    strcpy(arrayOrquesta[3].lugar,"BBBBB");
    strcpy(arrayOrquesta[3].nombre,"BBBBBB");

}
//////////////////////////////////
void MenuOrquesta()
{
    printf("\n\nMENU ORQUESTA\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - Listar\n");
    printf("4 - SALIR\n");
    printf("Elija opcion: ");
}

void MenuOrquestaPrincipal()
{
    printf("\n\nMENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - ORQUESTA\n");
    printf("2 - MUSICO\n");
    printf("3 - INSTRUMENTOS\n");
    printf("4 - SALIR\n");
    printf("Elija opcion: ");
}
////////////////////////////////////
void MenuOrquestaModificacion()
{
    printf("\n\nMENU MODIFICACION\n");
    printf("--------------\n");
    printf("1 - Nombre\n");
    printf("2 - float\n");
    printf("3 - text1\n");
    printf("4 - text2\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}
void MenuTipos()
{
    printf("\n\nMENU MODIFICACION\n");
    printf("--------------\n");
    printf("1 - Sinfonia\n");
    printf("2 - Filarmonica\n");
    printf("3 - Camara\n");
    printf("Elija opcion: ");
}
