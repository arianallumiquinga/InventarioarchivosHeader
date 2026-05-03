#include<stdio.h>
#include "funciones.h"
#include <string.h>
int main(int argc, char* argv[]){

    char productos [10][20];
    int stock [10];
    float precio  [10];

    int opc1 =0, opc2=0, cont=0;

    do {
        opc1=menu(); 
        switch (opc1){
            case 1:
                cont=registrarproducto(productos,precio,stock,cont);
                break;
            case 2:
                verInventario(productos,precio,stock,cont);
                break;
            case 3:
                ProductoMasCaro (productos, precio, cont);
                ProductoMasBarato (productos, precio, cont);
                break;
            case 4:
                buscarproduct (productos,precio,stock,cont);
                break;
            default:
                break;
        }
        printf("Desea seleccionar otra opcion 1.Si/2.No\n");
        opc2=validarEnteroconRango(1,2);
    } while(opc2==1);
    return 0;
}