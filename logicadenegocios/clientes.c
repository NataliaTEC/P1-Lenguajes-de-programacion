#include "../headers/clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

Cliente* clientes = NULL;
int cantidadClientes = 0;


char* clienteToString(Cliente cliente) {
	int largo = strlen(cliente.nombre) + strlen(cliente.cedula) + strlen(cliente.telefono) + 50;
	char* resultado = malloc(largo);
	if (resultado == NULL) {
		return NULL;
	}
	snprintf(resultado, largo,  "Nombre: %s | Cédula: %s | Teléfono: %s",cliente.nombre, cliente.cedula, cliente.telefono);
	return resultado;
}

void cargarClientes(void) {
	FILE* archivo = fopen("store/clientes.json", "r");
	if (archivo == NULL) {
		cantidadClientes = 0;
		return;
	}
	char buffer[100];
	char nombre[100];
	char cedula[100];
	char telefono[100];
	fgets(buffer, sizeof(buffer),archivo);
	while (fgets(buffer,sizeof(buffer),archivo)) {

		// Para el nombre
		if (strstr(buffer, "\"nombre\":")) {

			char* inicio = strchr(buffer, '\"');
			inicio = strchr(inicio + 1, '\"') + 1;
			char* fin = strchr(inicio, '\"');

			int largo = fin - inicio;
			strncpy(nombre, inicio, largo);
			nombre[largo] = '\0';
		}
		// Para la cedula
		if (strstr(buffer, "\"cedula\":")) {

			char* inicio = strchr(buffer, '\"');
			inicio = strchr(inicio + 1, '\"') + 1;
			char* fin = strchr(inicio, '\"');

			int largo = fin - inicio;
			strncpy(cedula, inicio, largo);
			cedula[largo] = '\0';
		}
		if (strstr(buffer, "\"telefono\":")) {

			char* inicio = strchr(buffer, '\"');
			inicio = strchr(inicio + 1, '\"') + 1;
			char* fin = strchr(inicio, '\"');

			int largo = fin - inicio;
			strncpy(telefono, inicio, largo);
			telefono[largo] = '\0';

			clientes = realloc(clientes, (cantidadClientes + 1) * sizeof(Cliente));

			//Para el nombre
			clientes[cantidadClientes].nombre = malloc(strlen(nombre) + 1);
			strcpy(clientes[cantidadClientes].nombre, nombre);

			//Para la cedula
			clientes[cantidadClientes].cedula = malloc(strlen(cedula) + 1);
			strcpy(clientes[cantidadClientes].cedula, cedula);

			//Para el telefono
			clientes[cantidadClientes].telefono = malloc(strlen(telefono) + 1);
			strcpy(clientes[cantidadClientes].telefono, telefono);
			cantidadClientes++;
		}
	}
	fclose(archivo);
} 


bool validarTelefono(char* telefono) {
	if (telefono == NULL && strlen(telefono) == 0) {
		printf("El numero de telefono no puede estar vacio");
		return false;
	}
	if (strlen(telefono) != 8) {
		printf("El numero de telefono solo puede tener 8 digitos");
	}
	for (int i = 0; telefono[i] != '\0'; i++) {
		if (!isdigit(telefono)) {
			printf("El numero de telefono solo debe contener numeros");
		}
	}
}
bool validarCedula(char*  cedula) {
	if (cedula == NULL && strlen(cedula) == 0) {
		printf("El numero de cedula no puede estar vacio");
	}
	if (strlen(cedula) != 9) {
		printf("La cedula solo puede tener 9 digitos");
	}
	for (int i = 0; cedula[i] != '\0'; i++) {
		if (!isdigit(cedula)) {
			printf("La cedula solo debe contener numeros");
		}
	}
}

bool validarNombre(char* nombre) {
	if (nombre == NULL || strlen(nombre) == 0) {
		printf("El nombre no puede estar vacío\n");
		return false;
	}
	for (int i = 0; nombre[i] != '\0'; i++) {
		if (!isalpha(nombre[i] && nombre[i] != ' ')) {
			printf("El nombre solo puede contener letras y espacios");
			return false;
		}
	}
	return true;
}

void guardarClientes(void) {
	FILE* archivo = fopen("store/clientes.json", "w");
	fprintf(archivo, "[\n");
	for (int i = 0; i < cantidadClientes; i++) {
	    fprintf(archivo, "    {\n");
	    fprintf(archivo, "        \"nombre\": \"%s\",\n", clientes[i].nombre);
		fprintf(archivo, "        \"cedula\": \"%s\",\n", clientes[i].cedula);
		fprintf(archivo, "        \"telefono\": \"%s\"\n", clientes[i].telefono);
	    if ( i < cantidadClientes -1) {
            fprintf(archivo, "    },\n");
        } else {
            fprintf(archivo, "    }\n");
        }
	}
	fprintf(archivo, "]\n");
	fclose(archivo);
}




void registrarClientes(char* nombre, char* cedula, char* telefono) {
	clientes = realloc(clientes, (cantidadClientes + 1) * sizeof(Cliente));

	clientes[cantidadClientes].nombre = malloc(strlen(nombre) + 1);
	strcpy(clientes[cantidadClientes].nombre, nombre);

	clientes[cantidadClientes].cedula = malloc(strlen(cedula) + 1);
	strcpy(clientes[cantidadClientes].cedula, cedula);

	clientes[cantidadClientes].telefono = malloc(strlen(telefono) + 1);
	strcpy(clientes[cantidadClientes].telefono, telefono);

	cantidadClientes++;
	printf("El cliente ha sido registrado!\n");
	guardarClientes();
}


void registrarCliente(void) {
	
    char nombre[100];
    char cedula[100];
    char telefono[100];
    bool datosValidos = false;
    
    printf("\n=== REGISTRAR NUEVO CLIENTE ===\n");

    while (!datosValidos) {

        do {
            printf("Ingrese el nombre del cliente: ");
            fgets(nombre, sizeof(nombre), stdin);
            if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n')) {
                nombre[strlen(nombre) - 1] = '\0';
            }
        } while (!validarNombre(nombre));
        
   
        do {
            printf("Ingrese el numero de cedula (9 digitos): ");
            fgets(cedula, sizeof(cedula), stdin);
            if ((strlen(cedula) > 0) && (cedula[strlen(cedula) - 1] == '\n')) {
                cedula[strlen(cedula) - 1] = '\0';
            }
        } while (!validarCedula(cedula));
        

        do {
            printf("Ingrese el numero de telefono (8 digitos): ");
            fgets(telefono, sizeof(telefono), stdin);
            if ((strlen(telefono) > 0) && (telefono[strlen(telefono) - 1] == '\n')) {
                telefono[strlen(telefono) - 1] = '\0';
            }
        } while (!validarTelefono(telefono));
        
        datosValidos = true;
    }
    
    registrarClientes(nombre, cedula, telefono);
}









