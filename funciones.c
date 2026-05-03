#include<stdio.h>
#include<string.h>
#include "funciones.h"
int menu (){
        int opc=0;
        printf("........Inventario de supermecado........\n");
        printf("1.....Ingresar un producto nuevo.........\n");
        printf("2.....Mostrar el inventario..............\n");
        printf("3.....Producto mas caro y barato.........\n");
        printf("4.....Buscar producto....................\n");
        printf(">>");
        opc=validarEnteroconRango(1,4);
    return opc;
}
int registrarproducto(char productos[10][20],float precio[10],int stock [10],int cont){
    printf("Ingrese el nombre del producto %d\n",cont);
    leercadena(productos[cont],20);
    printf("Ingrese el precio del producto %d\n",cont);
    precio[cont]=validarfloatonrango(0,10000);
    printf("Ingrese el stock del producto %d\n",cont);
    stock[cont]=validarEnteroconRango(0,100000);
    return cont+1;
}
void verInventario(char productos[10][20],float precio[10],int stock [10],int cont){
    float totalProducto=0;
    float valortotaldelinventario=0;
    float precioPromedio = 0;
    printf("#\t\tNombre\t\tStock\t\tPrecio\t\tTotal\n");
    
    for (int i = 0; i < cont ; i++) {
        totalProducto= stock [i]*precio[i];
        valortotaldelinventario+=totalProducto;
        precioPromedio+=precio[i];
        printf("%d \t\t %s \t\t %d \t\t %.2f\t\t %.2f\n",i,productos[i],stock[i],precio[i],totalProducto);
    }
    printf("Total inventario: %.2f \n",valortotaldelinventario);
    if (cont>0) {
        precioPromedio/=cont;
        printf("Precio promedio de los productos:%.2f\n",precioPromedio);
    }
}
void leercadena(char cadena[],int n){
    int len;
    fgets(cadena,n,stdin);
    len = strlen(cadena)-1;
    cadena[len]='\0';
}
int validarEnteroconRango(int a ,int b){
    int n;
    int aux;
    do {
        aux=scanf("%d",&n);
        while((getchar())!='\n');
        if (aux!=1||n<a||n>b){
            printf("El valor ingresado es incorrecto\n");
            printf(">>");
        }
    } while(aux!=1||n<a||n>b);
    return n;
}
float validarfloatonrango(int a ,int b){
    float n;
    int aux;
    do {
        aux=scanf("%f",&n);
        while((getchar())!='\n');
        if (aux!=1||n<a||n>b){
            printf("El valor ingresado es incorrecto\n");
            printf(">>");
        }
    } while(aux!=1||n<a||n>b);
    return n;
}
void ProductoMasCaro (char productos[10][20],float precio[10],int cont){
    
   int productmax=0;
    if (cont==0) {
        printf("No hay productos registrados");
        return;
    }
    for (int i = 0; i < cont; i++) {
        if (precio[i]>precio[productmax]){
            productmax=i;
        }
    }
    printf("El producto mas caro es %s\t\t %.2f\n", productos[productmax],precio[productmax]);
}
void ProductoMasBarato (char productos[10][20],float precio[10],int cont){
   int productmin=0;
   if (cont==0) {
       printf("No hay productos registrados");
       return;
   }
    for (int i = 0; i < cont; i++) {
        if (precio[i]<precio[productmin]){
            productmin=i;
        }
    }
    printf("El producto mas barato es %s\t\t %.2f\n", productos[productmin],precio[productmin]);
}
int Encontrarproduc(char productos[10][20],int cont,char buscar[]){
    if (cont==0) {
       printf("No hay productos registrados");
       return -1;
   }
    for (int i = 0; i < cont; i++) {
        if (strcmp(productos[i],buscar)==0) {
            return i;
        } 
    }
    return -1;
}
void buscarproduct(char productos[10][20],float precio[10],int stock [10],int cont){

    if (cont==0) {
       printf("No hay productos registrados");
       return;
   }

    char buscar [20];
    int buscador;
    do{
        printf("Ingresa el nombre del producto que deseas buscar: ");
        fgets(buscar,sizeof(buscar),stdin);
        buscar[strcspn(buscar,"\n")]=0;

        buscador= Encontrarproduc(productos,cont,buscar);
            if (buscador != -1) {
                float total=stock[buscador]*precio[buscador];
                printf("---------Producto encontrado---------\n");
                printf("#\t\tNombre\t\tStock\t\tPrecio\t\tTotal\n");
                printf("%d\t\t%s \t\t %d \t\t%.2f \t\t%.2f\n" ,buscador,productos[buscador],stock[buscador],precio[buscador],total);
            }else{
                printf("Producto No encontrado");
            }
    }while(buscador==-1);
}