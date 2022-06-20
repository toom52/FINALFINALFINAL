#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESC 27
#include <conio.h>
#include "consumo.h"
#include "menu.h"
#include "cliente.h"

int BuscarConsumo(char ArchivoConsumo[],char fecha[]);
int BuscaIDCliente(char ArchivoConsumo[],int idC);
int BuscaIDConsumo(char ArchivoConsumo[],char fecha[],int idC);
void MostrarConsumoXFECHA();
void MostrarConsumoXUSUARIO();
void MostrarConsumoXFyU();

int validarMail(char nombreArchivo[], char email[]);
int validarNumero(char numero[]);
int validarDni(char nombreArchivo[], char dni[]);
int validarMovil(char nombreArchivo[], char movil[]);
int validarNroCliente(char nombreArchivo[], int nroCliente);
int validarUnEntero(int num);




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



///-----------------------------------------CLIENTES-------------------------------------------------------



///----------------------------------Validaciones Cliente--------------------------------------------------

int validarMail(char nombreArchivo[], char email[])
{
    if(strstr(email, "@") == NULL)
    {
        ///yellow();
        printf("\nEste mail no es valido\n");
        printf("Intenta con otro mail\n");
        ///white();
        return 1;
    }

    FILE *archivo = fopen(nombreArchivo, "rb");
    stCliente c;
    if(archivo)
    {
        while(fread(&c, sizeof(stCliente), 1, archivo) > 0)
        {
            if(strcmp(c.email, email) == 0)
            {
                ///yellow();
                printf("\nEste mail ya se encuentra registrado\n");
                printf("Intenta con otro Email\n");
                ///white();
                return 1;
            }
        }
        fclose(archivo);
    }
    return 0;
}


int validarNumero(char numero[])
{

    int i=0;
    int flag=0;
    int esNumero;

    while(i<strlen(numero)&& flag==0)
    {
        esNumero = isdigit(numero[i]);
        if (esNumero !=0)       /// ingreso al if si esta todo bien, si hasta el momento son numeros
        {
            i++;
        }
        else
        {
            /// aca ingresa si el dato es incorrecto
            flag=1;
        }
    }
    return flag;
}


int validarDni(char nombreArchivo[], char dni[])
{


    if (validarNumero(dni) != 0)
    {
        printf("\n DNI no valido, vuelva a ingresarlo ");
        return 1;
    }

    FILE *archivo = fopen(nombreArchivo, "rb");
    stCliente c;
    if(archivo)
    {
        while(fread(&c, sizeof(stCliente), 1, archivo) > 0)
        {
            if(strcmp(c.dni, dni) == 0)
            {
                ///yellow();
                printf("\nEste dni ya se encuentra registrado\n");
                printf("Intenta con otro dni\n");
                ///white();
                return 1;
            }
        }
        fclose(archivo);
    }
    return 0;
}

int validarMovil(char nombreArchivo[], char movil[])
{

    if (validarNumero(movil) != 0)
    {
        printf("\n Numero no valido, vuelva a ingresarlo ");
        return 1;
    }
}

int validarNroCliente(char nombreArchivo[], int nroCliente)
{

    if (validarUnEntero(nroCliente) != 0)
    {
        printf("\n Numero incorrecto, vuelva a ingresar en el rango de 1-999 ");
        return 1;
    }

    FILE *archivo = fopen(nombreArchivo, "rb");
    stCliente c;
    if(archivo)
    {
        while(fread(&c, sizeof(stCliente), 1, archivo) > 0)
        {
            if(c.nroCliente == nroCliente)
            {
                ///yellow();
                printf("\n Este numero de cliente ya se encuentra registrado\n");
                printf("Intenta con otro numero \n");
                ///white();
                return 1;
            }
        }
        fclose(archivo);
    }
    return 0;
}

int validarUnEntero(int num)
{
    int flag = 0;
    int i=0;
    while (flag == 0 && i==0)
    {
        if ((num<0) || (num>1000))
    {
        /// printf("\n Numero incorrecto, vuelva a ingresar en el rango de 1-999");
        flag = 1;
        }
        i++;
    }
    return flag;
}


