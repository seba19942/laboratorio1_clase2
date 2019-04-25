#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    char nombre[50];
    char direccion[250];
    float precio;
    int tipo;
    int isEmpty; ///1vacio - 0ocupado
    int idPantalla; ///clave unica de identidad univoca
}Pantalla;

int pan_alta(Pantalla* pPantalla,int len,int pIndex,char* msgE);
int pan_baja(Pantalla* pPantalla,int len);
int pan_inicializarArray(Pantalla* pPantalla,int len);
int pan_mostrarArray(Pantalla* pPantalla,int len);
int pan_modify(Pantalla* pPantalla,int len, int posID,char* msgE);
int pan_posLibre(Pantalla* pPantalla, int len);

#endif // PANTALLA_H_INCLUDED
