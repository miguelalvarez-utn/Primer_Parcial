#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#define ORQUESTA_MAX 50
#define INSTRUMENTOS_MAX 20
#define MUSICOS_MAX 1000
//--------------------------
int main()
{
    int opcion;
    int opcion1;
    int contadorIdorquesta=0;
    Orquesta arrayOrquesta[ORQUESTA_MAX];
    orquesta_Inicializar(arrayOrquesta,ORQUESTA_MAX);
    orquesta_mock(arrayOrquesta, ORQUESTA_MAX, &contadorIdorquesta) ;
    ////////-------------------------------------------------------------
    int opcion2;
    int contadorIdmusico=0;
    Musico arrayMusico[MUSICOS_MAX];
    musico_Inicializar(arrayMusico,MUSICOS_MAX);
    musico_mock(arrayMusico, MUSICOS_MAX, &contadorIdmusico) ;
    //---------------------------------------------------------------
    int opcion3;
    int contadorIdinstrumento=0;
    Instrumento arrayInstrumento[INSTRUMENTOS_MAX];
    instrumento_Inicializar(arrayInstrumento,INSTRUMENTOS_MAX);
    instrumento_mock(arrayInstrumento, INSTRUMENTOS_MAX, &contadorIdinstrumento) ;

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
                            orquesta_alta(arrayOrquesta,ORQUESTA_MAX,&contadorIdorquesta);
                            break;
                        case 2:
                            orquesta_listar(arrayOrquesta,ORQUESTA_MAX);
                            orquesta_baja(arrayOrquesta,ORQUESTA_MAX);
                            break;
                        case 3:
                            orquesta_listar(arrayOrquesta,ORQUESTA_MAX);
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
                            musico_alta(arrayMusico,arrayOrquesta,arrayInstrumento,MUSICOS_MAX,ORQUESTA_MAX,INSTRUMENTOS_MAX,&contadorIdmusico);
                            break;
                        case 2:
                            musico_listar(arrayMusico,MUSICOS_MAX);
                            musico_baja(arrayMusico,MUSICOS_MAX);
                            break;
                        case 3:
                            musico_listar(arrayMusico,MUSICOS_MAX);
                            musico_modificar(arrayMusico,arrayOrquesta,MUSICOS_MAX,ORQUESTA_MAX);
                            break;
                        case 4:
                            musico_listar(arrayMusico,MUSICOS_MAX);
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
                            instrumento_alta(arrayInstrumento,INSTRUMENTOS_MAX,&contadorIdinstrumento);
                            break;
                        case 2:
                            instrumento_listar(arrayInstrumento,INSTRUMENTOS_MAX);
                            break;

                    }
                }while(opcion3 != 3);
                break;
            //----------------------------------------------------------------------------
        }
    }while(opcion != 4);
    return 0;
}
