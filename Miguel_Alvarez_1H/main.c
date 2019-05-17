#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#define QTY_ARRAY_TIPO 10
//--------------------------
int main()
{
    int opcion;
    int opcion1;
    int contadorIdorquesta=0;
    Orquesta arrayOrquesta[QTY_ARRAY_TIPO];
    orquesta_Inicializar(arrayOrquesta,QTY_ARRAY_TIPO);
    orquesta_mock(arrayOrquesta, QTY_ARRAY_TIPO, &contadorIdorquesta) ;
    ////////-------------------------------------------------------------
    int opcion2;
    int contadorIdmusico=0;
    Musico arrayMusico[QTY_ARRAY_TIPO];
    musico_Inicializar(arrayMusico,QTY_ARRAY_TIPO);
    musico_mock(arrayMusico, QTY_ARRAY_TIPO, &contadorIdmusico) ;
    //---------------------------------------------------------------
    int opcion3;
    int contadorIdinstrumento=0;
    Instrumento arrayInstrumento[QTY_ARRAY_TIPO];
    instrumento_Inicializar(arrayInstrumento,QTY_ARRAY_TIPO);
    instrumento_mock(arrayInstrumento, QTY_ARRAY_TIPO, &contadorIdinstrumento) ;

    do
    {
        MenuOrquestaPrincipal();
           utn_getUnsignedInt("","\nError",1,sizeof(int),1,4,1,&opcion);
        switch(opcion)
        {
            //------------------------------------------------------------------------
            case 1:
                do
                {
                    MenuOrquesta();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,4,1,&opcion1);
                    switch(opcion1)
                    {
                        case 1:
                            orquesta_alta(arrayOrquesta,QTY_ARRAY_TIPO,&contadorIdorquesta);
                            break;
                        case 2:
                            orquesta_listar(arrayOrquesta,QTY_ARRAY_TIPO);
                            orquesta_baja(arrayOrquesta,QTY_ARRAY_TIPO);
                            break;
                        case 3:
                            orquesta_listar(arrayOrquesta,QTY_ARRAY_TIPO);
                            break;
                    }
                }while(opcion1 != 4);
                break;
            //----------------------------------------------------------------------------
            case 2:
                do
                {
                    MenuMusico();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion2);
                    switch(opcion2)
                    {
                        case 1:
                            musico_alta(arrayMusico,arrayOrquesta,arrayInstrumento,QTY_ARRAY_TIPO,QTY_ARRAY_TIPO,QTY_ARRAY_TIPO,&contadorIdmusico);
                            break;
                        case 2:
                            musico_listar(arrayMusico,QTY_ARRAY_TIPO);
                            musico_baja(arrayMusico,QTY_ARRAY_TIPO);
                            break;
                        case 3:
                            musico_listar(arrayMusico,QTY_ARRAY_TIPO);
                            musico_modificar(arrayMusico,QTY_ARRAY_TIPO);
                            break;
                        case 4:
                            musico_listar(arrayMusico,QTY_ARRAY_TIPO);
                            break;
                    }
                }while(opcion2 != 5);
                break;
            //----------------------------------------------------------------------------
            case 3:
                do
                {
                    MenuInstrumento();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion3);
                    switch(opcion3)
                    {
                        case 1:
                            instrumento_alta(arrayInstrumento,QTY_ARRAY_TIPO,&contadorIdinstrumento);
                            break;
                        case 2:
                            instrumento_listar(arrayInstrumento,QTY_ARRAY_TIPO);
                            break;

                    }
                }while(opcion3 != 3);
                break;
            //----------------------------------------------------------------------------
        }
    }while(opcion != 4);
    return 0;
}
