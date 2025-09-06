#ifndef CLIENTES_H
#define CLIENTES_H
#include <stdbool.h> 

typedef struct cliente {
	char* nombre;
	char* cedula;
	char* telefono;
} Cliente;

extern Cliente* clientes;
extern int cantidadClientes;


char* clienteToString(Cliente cliente);
void cargarClientes(void);
bool validarTelefono(char* telefono);
bool validarCedula(char*  cedula);
bool validarNombre(char* nombre);
void guardarClientes(void);
void registrarClientes(char* nombre, char* cedula, char* telefono);
void registrarCliente(void);


#endif