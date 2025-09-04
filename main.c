#include "headers/libros.h"
#include "headers/pedidos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main() {
    printf("Bienvenido al sistema de Librería\n");
    printf("Menu principal:\n");
    printf("1- Opciones Administrativas\n");
    printf("2- Opciones Generales\n");
    printf("3- Salir\n");
    printf("Seleccione una opción: ");
    int respuesta;
    scanf("%d", &respuesta);
    if(respuesta == 1) {
    
    } else if(respuesta == 2) {

    } else if(respuesta == 3) {
        printf("¿Estás seguro que deseas salir (Y/N):");
        char *res;
        scanf("%s", res);
        if(!strcmp(res, "n") || !strcmp(res, "N")){ main();}
        else{
            exit(0);
        }
    } else {
        printf("Opción no válida. Por favor ingrese una de las opciones.\n");
        main();
    }
    return 0;



}