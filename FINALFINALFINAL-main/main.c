#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESC 27
#include <conio.h>
#include "consumo.h"
#include "menu.h"

int BuscarConsumo(char ArchivoConsumo[],char fecha[]);
int BuscaIDCliente(char ArchivoConsumo[],int idC);
int BuscaIDConsumo(char ArchivoConsumo[],char fecha[],int idC);
void MostrarConsumoXFECHA();
void MostrarConsumoXUSUARIO();
void MostrarConsumoXFyU();


int main()
{
    menuPrincipal();

   // CargaArchivoConsumo("consumo.dat");
   // system("cls");
   // muestraArchivoConsumo("consumo.dat",0,NULL);
   //MostrarConsumoXFECHA();
    MostrarConsumoXUSUARIO();
    //MostrarConsumoXFyU();
    return 0;
}


int BuscarConsumo(char ArchivoConsumo[],char fecha[])///busca un consumo por fecha. Devuelve flag.
{
    stConsumo c;
    int found=0;
    FILE*archi= fopen(ArchivoConsumo, "rb");
    if (archi)
    {
        while(found==0 && fread(&c, sizeof(stConsumo),1,archi)>0)
        {
            if (strncmp(c.fecha,fecha,strlen(fecha))==0)
            {
                found=1;
            }
        }
        fclose(archi);
    }
    return found;
}

int BuscaIDCliente(char ArchivoConsumo[],int idC)///busca el consumo por cliente. Devuelve flag
{
    stConsumo c;
    int found=0;
    FILE *archi= fopen(ArchivoConsumo,"rb");
    if (archi)
    {
        while (found==0 && fread(&c,sizeof(stConsumo),1,archi)>0)
        {
            if (idC==c.idCliente)
            {
                found=1;

            }
        }
        fclose(archi);
    }
    return found;
}

int BuscaIDConsumo(char ArchivoConsumo[],char fecha[],int idC) ///Busca si hay un consumo para fecha y usuario. Devuelve id consumo
{
    stConsumo c;
    int idCon=0,flag=0;
    FILE*archi=fopen(ArchivoConsumo,"rb");
    if (archi)
    {
        while(flag==0 && fread(&c,sizeof(stConsumo),1,archi)>0)
        {
            if (strncmp(c.fecha,fecha,strlen(fecha))==0 && c.idCliente==idC)
            {
                idCon=c.id;
                flag=1;
            }
        }

        fclose(archi);
    }
    return idCon;
}

void MostrarConsumoXFECHA()
{
    char fecha[10];
    system("cls");
    strcpy(fecha,CargarFecha());
    system("cls");
    if(BuscarConsumo("consumo.dat",fecha)==0)
    {
        printf("\nNo se registran consumos en esa fecha");
    }
    else
    {
        muestraArchivoConsumo("consumo.dat",0,fecha);
    }

}

void MostrarConsumoXUSUARIO()
{
    int idC=0;
    system("cls");
    printf("\n Ingrese su numero de cliente: ");
    fflush(stdin);
    scanf("%d",&idC);
    if(BuscaIDCliente("consumo.dat", idC)==0)
    {
        printf("\nCliente no encontrado.");
    }
    else
    {
        muestraArchivoConsumo("consumo.dat",idC,NULL);
    }
}

void MostrarConsumoXFyU()
{
    int idC=0;
    char fecha[10];
    system("cls");
    printf("\n Ingrese su numero de cliente: ");
    fflush(stdin);
    scanf("%d",&idC);
    system("cls");
    strcpy(fecha,CargarFecha());
    system("cls");
    if(BuscaIDConsumo("consumo.dat",fecha,idC)==0)
    {
        printf("\nNo se encontro el consumo");
    }
    else
    {
        muestraArchivoConsumo("consumo.dat",idC,fecha);
    }
}
