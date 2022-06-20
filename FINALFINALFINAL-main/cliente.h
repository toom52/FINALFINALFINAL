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
void muestraUnCliente (stCliente c);
int getNroClienteRand (int n);
void getNombresRand(char n[]);
void getApellidosRand(char a[]);
void getDniRand(char d[]);
void getMovilRand(char m[]);
void getEmailRand(char e[]);
void getDomicilioRand(char d[]);
void cargarArchivoClientesRandom (char nombreArchivo[]);
void cargarArchivoClientes (char nombreArchivo[]);
int ultimoId(char nombreArchivo[]);
void muestraArchivoClientes (char nombreArchivo[]);
void altaBajaCliente(int flag);
int buscaIdUsuario2(char nombreArchivo[], int nroClienteBuscar);
void modificarCliente(char nombreArchivo[], int idCliente,int flag);

#endif // CLIENTE_H_INCLUDED
