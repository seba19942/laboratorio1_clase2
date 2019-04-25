#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "arraynuevo.h"
#define REINTENTOS 3

int Empleado_inicializarArray(Empleado* pEmpleado,int len)
{
    int i;
    for(i=0; i<len;i++)
    {
        pEmpleado[i].isEmpty=1;
        pEmpleado[i].legajo=-1;
    }
    return 0;
}

int Empleado_mostrarArray(Empleado* pEmpleado,int len)
{
    int i;
    int flag;
    for(i=0;i<len;i++)
    {
        if(pEmpleado[i].isEmpty==0)
        {
            flag=0;
            printf("Lugar %d:  -   %s %s - Legajo: %d\n",i+1,pEmpleado[i].nombre,pEmpleado[i].apellido,pEmpleado[i].legajo);
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

int Empleado_alta(Empleado* pEmpleado,int len,int pIndex,char* msgE)
{
    char bufferName[20];
    char bufferSurname[20];
    char bufferLegajo[20];
    int auxLegajo;
    int retorno=0;
    while(retorno==0)
    {
        if(getStringLetras(bufferName,"\nIngrese Nombre: ",msgE))
        {
            break;
        }
        if(getStringLetras(bufferSurname,"\nIngrese Apellido: ",msgE))
        {
            break;
        }
        if(getStringNumeros(bufferLegajo,"\nIngrese Legajo: ",msgE))
        {
            break;
        }
        auxLegajo=atoi(bufferLegajo);
        if(Empleado_findLegajo(pEmpleado,len,auxLegajo)!=-1)
        {
            printf("\n----El legajo ya existe----\n");
            break;
        }
        strncpy(pEmpleado[pIndex].nombre,bufferName,sizeof(bufferName));
        strncpy(pEmpleado[pIndex].apellido,bufferSurname,sizeof(bufferSurname));
        pEmpleado[pIndex].legajo=auxLegajo;
        pEmpleado[pIndex].isEmpty=0;
        retorno=1;
    }
    return retorno;
}

int Empleado_modify(Empleado* pEmpleado, int len,char* msgE)
{
    char bufferLegajo[20];
    char bufferName[20];
    char bufferSurname[20];
    int auxLegajo;
    int retorno=0;

    do
    {
        if(getStringNumeros(bufferLegajo,"\nIngrese Legajo a modificar: ",msgE))
        {
            break;
        }
        auxLegajo=atoi(bufferLegajo);
        if(Empleado_findLegajo(pEmpleado,len,auxLegajo)==-1)
        {
            printf("\n----El legajo no existe!----\n");
            break;
        }
        if(getStringLetras(bufferName,"\nIngrese NUEVO Nombre: ",msgE))
        {
            break;
        }
        if(getStringLetras(bufferSurname,"\nIngrese NUEVO Apellido: ",msgE))
        {
            break;
        }
        strncpy(pEmpleado[auxLegajo].nombre,bufferName,sizeof(bufferName));
        strncpy(pEmpleado[auxLegajo].apellido,bufferSurname,sizeof(bufferSurname));
        retorno=1;
    }while(retorno==0);
    return retorno;
}


int Empleado_findLegajo(Empleado* pEmpleado, int len, int valor)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pEmpleado[i].legajo==valor)
        {
            ret=i;
        }
    }
    return ret;
}

int Empleado_ordenarNameAtoZ(Empleado* pEmpleado, int len)
{
    int i;
    int j;
    Empleado buffer;
    for(i=0;i<len-1;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<len;j++)
        {
            if(pEmpleado[j].isEmpty==1)
            {
                continue;
            }
            if(strcmp(pEmpleado[i].nombre,pEmpleado[j].nombre)>0)
            {
                buffer=pEmpleado[i];
                pEmpleado[i]=pEmpleado[j];
                pEmpleado[j]=buffer;
            }
        }
    }
    return 0;
}

int Empleado_ordenarSurnameAtoZ(Empleado* pEmpleado, int len)
{
    int i;
    int j;
    Empleado buffer;
    for(i=0;i<len-1;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<len;j++)
        {
            if(pEmpleado[j].isEmpty==1)
            {
                continue;
            }
            if(strcmp(pEmpleado[i].apellido,pEmpleado[j].apellido)>0)
            {
                buffer=pEmpleado[i];
                pEmpleado[i]=pEmpleado[j];
                pEmpleado[j]=buffer;
            }
        }
    }
    return 0;
}

int Empleado_posLibre(Empleado* pEmpleado, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
