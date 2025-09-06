typedef struct cliente {
	char* nombre;
	char* cedula;
	char* telefono;
} Cliente;

extern Cliente* clientes;
extern int cantidadClientes;



void registrarCliente(char* cedula, char* nombre, char* telefono);
void cargarClientes(void);
void guardarClientes(void);