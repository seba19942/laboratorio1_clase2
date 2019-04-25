#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "Empleado.h"
#define LEN 10

int main()
{
    char seguir='s'; //MENU
    int opcion; //MENU

    while (seguir=='s')
    {
        printf("\t\tMENU");
        printf("\n\n1-Alta empleado");
        printf("\n\n2-Mostrar empleado");
        printf("\n\n3-Borrar nombre");
        printf("\n\n4-Salir\n");

        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
        }
        while (opcion<1 || opcion>4);

        switch (opcion)
        {
        case 1:


            break;

        case 2:


            break;

        case 3:

            break;

        case 4:

            break;
        }
    }
    return 0;
}
