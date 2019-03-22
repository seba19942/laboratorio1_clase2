#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_REP 3

int PedirAcumularMostrar();
{

    int acumulador=0;
    int buffer;
    int i;
    for(i=0;i<CANTIDAD_REP;i++)

    printf("ingrese numero %d: ",i+1);
    scanf("%d",&buffer);
    //falta validar
    acumulador = acumulador + buffer;

    printf("El promedio es: %f",(float)acumulador / CANTIDAD_REP);

    return 0;





}




















