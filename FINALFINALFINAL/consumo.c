#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESC 27
#include <conio.h>
#include "consumo.h"
#include <dos.h>
#include "time.h"

char *CargarFecha()///Carga fecha por teclado,devuelve string
{
    int mes=0, dia=0, diaP=0, anio=0, flag=0;
    static char fecha[10];

    printf("\n Ingrese el año\n");
    fflush(stdin);
    while (flag!=3) ///Carga de anio
    {
        scanf("%d", &anio);
        if (anio>=2022)
        {
            fflush(stdin);
            flag=3;
        }
        else
        {
            printf("\n Año no valido, ingrese un anio del 2022 en adelante.\n");
        }
    }
    printf("\nPresione el numero correspondiente al mes: ");
    printf("\n1.Enero");
    printf("\n2.Febrero");
    printf("\n3.Marzo");
    printf("\n4.Abril");
    printf("\n5.Mayo");
    printf("\n6.Junio");
    printf("\n7.Julio");
    printf("\n8.Agosto");
    printf("\n9.Septiembre");
    printf("\n10.Octubre");
    printf("\n11.Noviembre");
    printf("\n12.Diciembre\n");
    fflush(stdin);
    do ///Carga de mes a la estructura
    {
        scanf("%d", &mes);
        if (mes > 0 && mes<13)
        {
            switch(mes)
            {
            case 1:
                mes=1;
                flag=1;
                break;
            case 2:
                mes=2;
                flag=1;
                break;
            case 3:
                mes=3;
                flag=1;
                break;
            case 4:
                mes=4;
                flag=1;
                break;
            case 5:
                mes=5;
                flag=1;
                break;
            case 6:
                mes=6;
                flag=1;
                break;
            case 7:
                mes=7;
                flag=1;
                break;
            case 8:
                mes=8;
                flag=1;
                break;
            case 9:
                mes=9;
                flag=1;
                break;
            case 10:
                mes=10;
                flag=1;
                break;
            case 11:
                mes=11;
                flag=1;
                break;
            case 12:
                mes=12;
                flag=1;
                break;

            }
        }
        else
        {
            printf("\nIngreso un numero incorrecto. Seleccione uno de la lista.\n");
        }
    }
    while(flag !=1);
    printf("\n Ingrese el dia: ");
    fflush(stdin);
    do ///Carga de dia a la estructura
    {
        scanf("%d", &diaP);
        if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
        {
            if (diaP<32)
            {
                dia=diaP;
                flag=2;
            }
            else
            {
                printf("\nFecha erronea, ingrese una fecha valida.\n");
                fflush(stdin);
            }
        }
        if (mes==4 || mes==6 || mes==9 || mes==11)
        {
            if (diaP<31)
            {
                dia=diaP;
                flag=2;
            }
            else
            {
                printf("\nFecha erronea, ingrese una fecha valida.\n");
                fflush(stdin);
            }
        }
        if (mes==2)
        {
            if (diaP<29)
            {
                dia=diaP;
                flag=2;
            }
            else
            {
                printf("\nFecha erronea, ingrese una fecha valida.\n");
                fflush(stdin);
            }
        }
    }
    while(flag!=2);


    system("cls");
    sprintf(fecha,"%d/%d/%d", dia,mes,anio);
    return fecha;
}

stConsumo cargaConsumo()///Carga estructura consumo
{
    stConsumo c;
    printf("\n Ingrese ID Cliente: ");
    fflush(stdin);
    scanf("%d", &c.idCliente);
    strcpy(c.fecha,CargarFecha());
    printf("\n Ingrese la cantidad de datos consumidos: ");
    scanf("%d",&c.datosConsumidos);
    fflush(stdin);
    c.baja=0;
    return c;
}

void muestraUnConsumo(stConsumo c,int flag)///muestra un consumo
{
    if(flag==c.baja || flag==2)
    {
    printf("=============================================");
    printf("\nID CONSUMO: %d",c.id);
    printf("\nFECHA: %s.",c.fecha);
    printf("\nDATOS CONSUMIDOS: %dMB",c.datosConsumidos);
    printf("\nID CLIENTE: %d",c.idCliente);
    printf("\nESTADO(0 ACTIVO, 1 INACTIVO): %d", c.baja);
    printf("\n=============================================\n");
    }

}

void CargaArchivoConsumo(char ArchivoConsumo[])///Carga consumos a archivo
{
    stConsumo c;
    char opcion;
    int idCon=0, id=1;
    FILE *archi=fopen(ArchivoConsumo,"ab");
    if(archi)
    {
        id=idConsumoUnico("consumo.dat");
        do
        {
            c=cargaConsumo();
            c.id=id;
            idCon=BuscaIDConsumo("consumo.dat",c.fecha,c.idCliente);
            if (idCon!=0)
            {
                ModificarConsumo("consumo.dat",idCon,c.datosConsumidos,0);///en vez de id puntero a la struc
                printf("\nYa se cargo un consumo para este usuario en esa fecha. El nuevo consumo se sumara al anterior\n");
            }
            else
            {
                fwrite(&c,sizeof(stConsumo), 1, archi);
                id++;
            }
            printf("\nPresione ESC para salir, cualquier tecla para continuar");
            fflush(stdin);
            opcion=getch();
            system("cls");
        }
        while(opcion!=ESC);
        fclose(archi);

    }
}

void muestraArchivoConsumo(char ArchivoConsumo[], int idCl, char f[],int flag)///Muestra archivo consumo.dat
{
    stConsumo c;
    FILE *archi= fopen(ArchivoConsumo, "rb");
    printf("\n Archivo de Consumo:\n");


    if(archi)
    {
        if(idCl==0 && f==NULL)///muestra todo el archivo de consumo
        {
            while(fread(&c, sizeof(stConsumo),1,archi)>0)
            {
                muestraUnConsumo(c,flag);
            }
        }
        else
        {
            if (idCl<0 && f!=NULL)///muestra si fecha y idcliente son iguales
            {
                while(fread(&c,sizeof(stConsumo),1,archi)>0)
                {
                    if (strncmp(c.fecha,f,strlen(f))==0 && c.idCliente==idCl)
                    {
                        muestraUnConsumo(c,flag);
                    }
                }
            }
            else
            {
                if(idCl>0 && f==NULL)///muestra consumo de cliente
                {
                    while(fread(&c,sizeof(stConsumo),1,archi)>0)
                    {
                        if (idCl==c.idCliente)
                        {
                            muestraUnConsumo(c,flag);
                        }
                    }
                }
                if (idCl==0 && f!=NULL)///muestra consumo de una fecha
                {
                    while(fread(&c,sizeof(stConsumo),1,archi)>0)
                    {
                        if (strncmp(c.fecha,f,strlen(f))==0)
                        {
                            muestraUnConsumo(c,flag);
                        }
                    }
                }
            }
        }
        fclose(archi);
    }
}

int idConsumoUnico(char ArchivoConsumo[])///revisa ultimo id consumo y devuelve uno posterior o 1 si no existe
{
    stConsumo c;
    int id=1;
    FILE *archi= fopen(ArchivoConsumo, "rb");
    if(archi)
    {
        fseek(archi, -1*sizeof(stConsumo),SEEK_END);
        if(fread(&c,sizeof(stConsumo),1,archi)>0)
        {
            id=c.id+1;
        }

    fclose(archi);
    }
    return id;
}

void ModificarConsumo(char ArchivoConsumo[],int idCon,int datos,int flag) ///Carga un consumo a otro existente.
{
    stConsumo c;
    FILE *archi= fopen(ArchivoConsumo, "rb+");
    if(archi)
    {
    fseek(archi,(idCon-1)*sizeof(stConsumo),SEEK_SET);
    fread(&c,sizeof(stConsumo),1,archi);
    if (flag==0)
    {
          c.datosConsumidos+=datos;
    }
    else
    {
        c.datosConsumidos=datos;
    }
    fseek(archi,(idCon-1)*sizeof(stConsumo),SEEK_SET);
    fwrite(&c,sizeof(stConsumo),1,archi);

        fclose(archi);
    }
}

void AltayBajaCon(char ArchivoConsumo[],int idCon,int ab)/// da de alta o de baja un consumo
{
    stConsumo c;
    FILE *archi= fopen(ArchivoConsumo, "rb+");
    if(archi)
    {
    fseek(archi,(idCon-1)*sizeof(stConsumo),SEEK_SET);
    fread(&c,sizeof(stConsumo),1,archi);
    c.baja=ab;
    fseek(archi,(idCon-1)*sizeof(stConsumo),SEEK_SET);
    fwrite(&c,sizeof(stConsumo),1,archi);

        fclose(archi);
    }
}
///----------------------------CARGA RANDOM CONSUMO--------------------------------------\\\

stConsumo cargaConsumoRnd()
{
    stConsumo c;
    c.idCliente=getIDclienteRand(c.idCliente);
    getFechaRand(c.fecha);
    c.datosConsumidos=getDatosRand(c.datosConsumidos);
    c.baja=0;

    return c;
}
int getIDclienteRand(int idCl)
{
    int clmin=1,clmax=50;
    srand(time(0));
    int id=(rand()%(clmax-clmin+1))+clmin;
    return id;
}

char getFechaRand(char f[])
{
    int diaMin=1,diaMax=28,mesMin=1,mesMax=6,anio=2022;
    char fecha[10];
    srand(time(0));
        int dia=(rand()%(diaMax-diaMin+1))+diaMin;
        int mes=(rand()%(mesMax-mesMin+1))+mesMin;

    sprintf(fecha,"%d/%d/%d", dia,mes,anio);
    strcpy(f,fecha);

}

int getDatosRand(int d)
{
    d=rand()%10000;
      return d;
}

void CargaArchivoConsumoRnd(char ArchivoConsumo[])
{
    stConsumo c;
    int static id=1;
    FILE *archi=fopen(ArchivoConsumo,"ab");
    if(archi)
    {

        id=idConsumoUnico("consumo.dat");

        for (int i=0;i<2000;i++)
        {
            c=cargaConsumoRnd();
            c.id=id;
            fwrite(&c,sizeof(stConsumo), 1, archi);

            id++;
            i++;
        }
        fclose(archi);
    }
    printf("\n===========CARGA FINALIZADA===========\n");
}
