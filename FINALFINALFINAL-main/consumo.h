#ifndef CONSUMO_H_INCLUDED
#define CONSUMO_H_INCLUDED

typedef struct
{
    int id;
    int idCliente;
    char fecha[10];
    int datosConsumidos; /// expresados en mb.
    int baja; /// 0 si está activo - 1 si está eliminado
} stConsumo;

char *CargarFecha();///Carga fecha por teclado,devuelve string
stConsumo cargaConsumo();///Carga estructura consumo
void muestraUnConsumo(stConsumo c);///muestra un consumo
void CargaArchivoConsumo(char ArchivoConsumo[]);///Carga consumos a archivo
void muestraArchivoConsumo(char ArchivoConsumo[],int idCl, char f[]);///Muestra archivo consumo.dat
int idConsumoUnico(char ArchivoConsumo[]);///revisa ultimo id consumo y devuelve uno posterior o 1 si no existe
void ModificarConsumo(char ArchivoConsumo[],int idCon,int datos,int flag);///Carga un consumo a otro existente.

#endif // CONSUMO_H_INCLUDED
