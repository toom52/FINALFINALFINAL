#ifndef CONSUMO_H_INCLUDED
#define CONSUMO_H_INCLUDED

typedef struct
{
    int id;
    int idCliente;
    char fecha[10]; ///Cambiado a char por funcionalidad, consultado previamente y permitido por la catedra.
    int datosConsumidos; /// expresados en mb.
    int baja; /// 0 si está activo - 1 si está eliminado
} stConsumo;

char *CargarFecha();///Carga fecha por teclado,devuelve string
stConsumo cargaConsumo();///Carga estructura consumo
void muestraUnConsumo(stConsumo c,int flag);///muestra un consumo
void CargaArchivoConsumo(char ArchivoConsumo[]);///Carga consumos a archivo
void muestraArchivoConsumo(char ArchivoConsumo[],int idCl, char f[],int flag);///Muestra archivo consumo.dat
int idConsumoUnico(char ArchivoConsumo[]);///revisa ultimo id consumo y devuelve uno posterior o 1 si no existe
void ModificarConsumo(char ArchivoConsumo[],int idCon,int datos,int flag);///Carga un consumo a otro existente.

///CARGA RANDOM DE CONSUMOS
void CargaArchivoConsumoRnd(char ArchivoteConsumo[]);
int getDatosRand(int d);
char getFechaRand(char f[]);
int getIDclienteRand(int idCl);

#endif // CONSUMO_H_INCLUDED
