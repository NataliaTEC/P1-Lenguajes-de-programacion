#include "../headers/clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente* clientes = NULL;
int cantidadClientes = 0;


void registrarClientes(char* nombre, char* cedula, char* telefono) {
	clientes = realloc(clientes, (cantidadClientes + 1) * sizeof(Cliente));

	clientes[cantidadClientes].nombre = malloc(strlen(nombre) + 1);
	strcpy(clientes[cantidadClientes].nombre, nombre);

	clientes[cantidadClientes].cedula = malloc(strlen(cedula) + 1);
	strcpy(clientes[cantidadClientes].cedula, cedula);

	clientes[cantidadClientes].telefono = malloc(strlen(telefono) + 1);
	strcpy(clientes[cantidadClientes].nombre, nombre);
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
			clientes[cantidadClientes].cedula = malloc(strlen(telefono) + 1);
			strcpy(clientes[cantidadClientes].cedula, telefono);
			cantidadClientes++;
		}
	}
	fclose(archivo);
} 