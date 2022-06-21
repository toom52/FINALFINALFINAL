#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct{

    int id;
    int nroCliente;
    char nombre [30];
    char apellido [30];
    char dni [10];
    char email [30];
    char domicilio [45];
    char movil [12];
    int eliminado;

} stCliente;

stCliente cargaUnClienteManual ();
stCliente cargaUnClienteRandom ();
void muestraUnCliente (stCliente c, int flag);
void getNombresRand(char n[]);
void getApellidosRand(char a[]);
void getDniRand(char d[]);
void getMovilRand(char m[]);
void getEmailRand(char e[]);
void getDomicilioRand(char d[]);
void cargarArchivoClientesRandom (char nombreArchivo[]);
void cargarArchivoClientes (char nombreArchivo[]);
int ultimoId(char nombreArchivo[]);
int ultimoNroCliente(char nombreArchivo[]);
void muestraArchivoClientes (char nombreArchivo[], int flag);
void altaBajaCliente(int flag);
int buscaIdUsuario(char nombreArchivo[], int nroClienteBuscar);
void modificarBajaCliente(char nombreArchivo[], int idCliente,int flag);
int buscarClienteXDni (char nombreArchivo[]);
void cambiarChar();
void modificarMovil(char nombreArchivo[], int idCliente);
void modificarApellido(char nombreArchivo[], int idCliente);
void modificarDni(char nombreArchivo[], int idCliente);
void modificarDomicilio(char nombreArchivo[], int idCliente);

#endif // CLIENTE_H_INCLUDED

