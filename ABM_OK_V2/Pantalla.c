#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "Empleado.h"
#include "Pantalla.h"

int pan_alta(Pantalla* pPantalla,int len,int pIndex,char* msgE)
{
    char bufferName[50];
    char bufferDireccion[250];
    char bufferPrecio[50];
    float auxPrecio;
    int retorno=0;
    while(retorno==0)
    {
        if(getStringLetras(bufferName,"\nIngrese Nombre de pantalla: ",msgE))
        {
            break;
        }
        if(getStringLetras(bufferDireccion,"\nIngrese direccion: ",msgE))
        {
            break;
        }
        if(getStringNumeros(bufferPrecio,"\nIngrese Precio: ",msgE))
        {
            break;
        }
        auxPrecio=atof(bufferPrecio);

        strncpy(pPantalla[pIndex].nombre,bufferName,sizeof(bufferName));
        strncpy(pPantalla[pIndex].direccion,bufferDireccion,sizeof(bufferDireccion));
        pPantalla[pIndex].precio=auxPrecio;
        pPantalla[pIndex].isEmpty=0;
        retorno=1;
    }
    return retorno;
}

int pan_baja(Pantalla* pPantalla,int len)
{
    return 0;
}
int pan_modify(Pantalla* pPantalla,int len, int posID,char* msgE)

{
    char bufferName[50];
    char bufferDireccion[250];
    char bufferPrecio[50];
    float auxPrecio;
    int retorno=0;

    do
    {

        if(getStringLetras(bufferName,"\nIngrese NUEVO Nombre: ",msgE))
        {
            break;
        }
        if(getStringLetras(bufferDireccion,"\nIngrese NUEVA Direccion ",msgE))
        {
            break;
        }
        if(getStringNumeros(bufferPrecio,"\ningrese nuevo precio",msgE))
        {
            break;
        }
        auxPrecio=atof(bufferPrecio);
        strncpy(pPantalla[posID].nombre,bufferName,sizeof(bufferName));
        strncpy(pPantalla[posID].direccion,bufferDireccion,sizeof(bufferDireccion));
        pPantalla[posID].precio=auxPrecio;
        retorno=1;
    }while(retorno==0);
    return retorno;
}


int pan_inicializarArray(Pantalla* pPantalla,int 4)
{
    int i;
    for(i=0; i<4;i++)
    {
        pPantalla[i].isEmpty=1;

    }
    return 0;
}
int pan_mostrarArray(Pantalla* pPantalla,int len)
{
    return 0;
}

int pan_posLibre(Pantalla* pPantalla, int len)
{
    return 0;
}
