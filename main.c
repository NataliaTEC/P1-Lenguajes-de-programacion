#include "headers/libros.h"
#include "headers/pedidos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void admin(){
    printf("Estamos en admin");
    
}

void general(){
    printf("Estamos en general");
}



void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    while(true){
        printf("Bienvenido al sistema de Librería\n");
        printf("Menu principal:\n");
        printf("1- Opciones Administrativas\n");
        printf("2- Opciones Generales\n");
        printf("3- Salir\n");
        printf("Seleccione una opción: ");
        int respuesta;
        if(scanf("%d", &respuesta)==1){
            if(respuesta == 1) {
            admin();
            } else if(respuesta == 2) {
                general();
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
        }else{
            printf("Entrada incorrecta. Por favor, ingresa un número\n");
            limpiarBuffer();
        }
        
    }
    
    return 0;

}

