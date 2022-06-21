#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"

#define ESC 27

stCliente cargaUnClienteManual ()   /// En esta funcion creo y cargo clientes para retornarlos
{
    stCliente c;

    printf("\n");

    int flagNroCliente = 1;
    while(flagNroCliente == 1)
    {
        printf("\n Nro cliente........: ");
        fflush(stdin);
        scanf("%d", &c.nroCliente);
        flagNroCliente=validarNroCliente("clientes.dat", c.nroCliente);
    }

    printf("\n Nombre........: ");
    fflush(stdin);
    gets(c.nombre);


    printf("\n Apellido......: ");
    fflush(stdin);
    gets(c.apellido);

    ///---------------- Registro Dni con validacion ---------------

    int flagDni =1;
    while(flagDni == 1)
    {
        printf("\n Dni...........: ");
        fflush(stdin);
        gets(c.dni);
        flagDni = validarDni("clientes.dat", c.dni);
    }


    ///---------------- Registro Mail con validacion ---------------

    int flagMail = 1;
    while(flagMail == 1)
    {
        printf("\n Email: ");
        fflush(stdin);
        gets(c.email);
        flagMail = validarMail("clientes.dat", c.email);
    }

    ///---------------- Registro Domicilio ---------------

    printf("\n Domicilio.......: ");
    fflush(stdin);
    gets(c.domicilio);

    ///---------------- Registro Movi/celular con validacion ---------------

    int flagMovil = 1;
    while(flagMovil == 1)
    {
        printf("\n Movil: ");
        fflush(stdin);
        gets(c.movil);
        flagMovil = validarMovil("clientes.dat", c.movil);
    }

    ///---------------- Estado / eliminado ---------------

    c.eliminado=0;

    return c;
}

stCliente cargaUnClienteRandom ()
{

    stCliente c;

    getNombresRand(c.nombre);
    getApellidosRand(c.apellido);
    getDniRand(c.dni);
    getEmailRand(c.email);
    getDomicilioRand(c.domicilio);
    getMovilRand(c.movil);

    c.eliminado=0;

    return c;
}

void muestraUnCliente (stCliente c, int flag)
{

    if (c.eliminado == flag)
    {
        printf("\n id: %d ", c.id);
        printf("\n Numero de cliente: %d ", c.nroCliente);
        printf("\n Nombre: %s ", c.nombre);
        printf("\n Apellido: %s ", c.apellido);
        printf("\n DNI: %s ", c.dni);
        printf("\n Email: %s ", c.email);
        printf("\n Domicilio: %s ", c.domicilio);
        printf("\n Movil: %s ", c.movil);
        if (flag == 0){
           printf("\n Estado: Activo ");
        } else{
            printf("\n Estado: Dado de baja ");
        }


        printf("\n ==============================\n");
    }
}

///------------------------------ CARGA RANDOM --------------------------------------


void getNombresRand(char n[])
{
    char nombres [][30] = {"Pedro", "Pablo", "Pilar", "Lucas","Micaela", "Adrian","Lucia","Jeremias","Belen",
                           "Milagros","Tomas","Martin","Sergio","Victoria","Andrea","Luciano","Romina","Franco","Valentina","Melanie",
                           "Guadalupe","Manuel","Carlos","Andrea","Sebastian","Antonio","Vera","Rocio"
                          };
    strcpy (n, nombres[rand()%(sizeof(nombres)/30)]); /// Sizeof devuelve la cantidad de bits que tiene una variable, en este caso los nombres
} /// copio en el string que recibo (n) un nombre al azar del arreglo Nombres

void getApellidosRand(char a[])
{
    char apellidos [][30] = {"Lopez","Fernandez","Acuña","Martinez","Botero","Verstappen","Alonso","Perez","Leclerc",
                             "Sainz","Norris","Gasly","Vettel","Ricciardo","Senna","Reutemann","Fangio","Barrichello","Hamilton","Trulli","Mansell",
                             "McLaren","Benz","Martin","Williams","Haas","Martinez","Fernandez","Echeverria","Navarro",
                            };
    strcpy (a, apellidos[rand()%(sizeof(apellidos)/30)]);
}

void getDniRand(char d[])
{
    char dni [][10] = { "40071806","25950389","36220384","23609394","48374340","24611056","20875483","25561375","23529970",
                        "42702914","25823104","23510643","35870208","43230986","48793337","39127081","36133229","28467159","49487624","42327681",
                        "24276308","40700732","42806674","43728905","26798160","40668574","41524893","47690661","49443934","42562538","49860038",
                        "34981787","23632064","39390078","21709893","29207068","26941265","47466613","28391121","42463351","41868030","22381072",
                        "48447821","23681686","36931954","24988332","46017297","22806674","24594967","35929735","27230290","26813292","33622072",
                        "45650178","48729911","27369620","30197350","20294090","42979277","25931641"
                      };
    strcpy (d, dni[rand()%(sizeof(dni)/10)]);
}

void getMovilRand(char m[])
{
    char movil [][12] = {"2236061754","2234503390","2235781366","2233401323","2237981129","2237291253","2234658321","2233288855","2236174305",
                         "2234196536","2237488576","2232739648","2238760278","2237624572","2231269795","2236293741","2235025582","2239915224","2234693660",
                         "2236893747","2236737742","2234857627","2237936409","2238770137","2233696345","2237899989","2238643393","2234746861","2233411082",
                         "2231340698","2239679798","2236537005","2234412436","2236042346","2239872817","2235555163","2236192570","2232363587","2232204243","2237446339",
                         "2237712144","2235825323","2233139566","2233446212","2236566623","2235646432"
                        };
    strcpy (m, movil[rand()%(sizeof(movil)/12)]);
}

void getEmailRand(char e[])
{
    char email [][30] = {"suscipit.nonummy@icloud","nulla.vulputate@aol","fusce.mi@protonmail.org","accumsan.ipsum@outlook.net","quis.pede@protonmail.edu","id.blandit@icloud.net",
                         "dui.augue@aol.ca","phasellus.nulla@google.com","non.dapibus@protonmail.ca","gravida.sit.amet@icloud.edu",
                         "ut.pellentesque@outlook.ca","interdum.libero@icloud.edu","ornare@hotmail.org","phasellus@icloud.couk","eget.ipsum@aol.net","arcu.sed@aol.couk",
                         "nulla@hotmail.couk","interdum.sed@hotmail.couk","penatibus@protonmail.edu","nullam.vitae@hotmail.net","odio.vel.est@google.ca",
                         "risus.donec@hotmail.org","phasellus@protonmail.com","urna.vivamus@icloud.ca","malesuada@icloud.com","est.ac@outlook.ca",
                         "penatibus@aol.com","blandit@icloud.ca","facilisis@outlook.org","nibh.lacinia@outlook.couk","accumsan@google.com",
                         "arcu.ante@icloud.","proin.duis@protonmail.net","mauris.magna@hotmail.org","sem.mollis@aol.couk","curabitur@yahoo.couk",
                         "neque@protonmail.couk","scelerisque@protonmail.org","aliquam@aol.com","quam@google.org","cubiliae@hotmail.edu",
                         "lacus.non@google.net","senectus.@icloud.net","lorem.dolor@aol.net","est.mollis@outlook.ca","consectetuer@hotmail.couk",
                         "purustellus@outlook.com","feugiat.sit@protonmail.net","eu@outlook.ca","turpis.egestas@outlook.org","urna.ut@hotmail.edu","viverra.iaculis@protonmail.com",
                         "magna.malesuada.vel@google.com","dolor.tempus@protonmail.ca","fringilla@google.edu","at.fringilla@google.org","iaculis@outlook.edu","sit.amet@protonmail.edu",
                         "et.arcu@yahoo.ca","blandit.at@protonmail.org","hendrerit@icloud.org","eu.elit@outlook.com","ante@outlook.com","a.malesuada@protonmail.edu",
                         "enim.nisl@icloud.ca","est.ac@yahoo.org","nisi.cum.sociis@google.couk","hendrerit@hotmail.ca","non.lorem@google.org","pellentesque@icloud.couk",
                         "consequat.purus@hotmail.ca","fermentumligula@icloud.ca","magnis.dis@hotmail.ca","orci.luctus.et@aol.couk","nascetur@protonmail.couk","nulla.eget.metus@mail",
                         "a@protonmail.com","et@protonmail.com","egestas@protonmail.com","lacus.mauris@google.ca","mollis.non@google.couk","dolor.elit@outlook.couk",
                         "magna@icloud.ca","turpis.condimentum@outlook","duis.elementum@icloud.couk","id.ante.nunc@yahoo.org","vestibulum.mauris@hotmail.couk",
                         "nascetur@icloud.com","risus.duis@yahoo.couk","posuere@protonmail.ca","viverra.maecenas@hotmail.com","auctor@yahoo.com",
                         "sem@aol.net","orci.phasellus@icloud.org","arcu.curabitur@protonmail.ca","nec.tempus@aol.org","mauris.@protonmail.org"
                        };
    strcpy (e, email[rand()%(sizeof(email)/30)]);
}

void getDomicilioRand(char d[])
{
    char domicilio [][45] = {"Dorrego 2143","Quintana 254","Luro 3400","Luro 2342","Punta del este 1103","Roca 1324","Primera junta 213",
                             "Edison 3450","Salta 3000","España 3421","San juan 1321","Formosa 2134","Luro 1234","Colon 1354","Colon 4321","Vieytes 1234",
                             "Larrea 3234","Quintana 3745","Pelegrini 3212","Sarmiento 4341","Guemes 1432","Alem 321","Cordoba 2134", "Aristobulo 3746"
                             "Alsina 3212","Mendoza 3543","Falucho 234","Brawn 241","Formosa 212","Avellaneda 2344","Garay 1234", "Alberti 434"
                            };
    strcpy (d, domicilio[rand()%(sizeof(domicilio)/45)]);
}

void cargarArchivoClientesRandom (char nombreArchivo[])
{
    stCliente c;
    char opcion;
    int static id = 0;
    id =  ultimoId(nombreArchivo);

    int static nroCliente = 0;
    nroCliente =  ultimoNroCliente(nombreArchivo);

    FILE *archi = fopen(nombreArchivo, "ab");
    if (archi)
    {
        for (int i=0; i<50; i++)
        {
            id++;
            nroCliente++;
            c=cargaUnClienteRandom();
            c.id=id;
            c.nroCliente=nroCliente;
            fwrite(&c,sizeof(stCliente), 1, archi);
            i++;
        }

        fclose(archi);
    }
}


/// ----------------------------- ARCHIVOS ------------------------------------------


void cargarArchivoClientes (char nombreArchivo[])
{
    stCliente c;
    char opcion;
    int static id = 0;
    id =  ultimoId(nombreArchivo);
    ///int static id =  ultimoId(nombreArchivo);
    FILE *archi = fopen(nombreArchivo, "ab");
    if (archi)
    {
        do
        {
            id++;
            c=cargaUnClienteManual();
            c.id=id;
            fwrite(&c,sizeof(stCliente), 1, archi);
            printf("\n ESC para salir, cualquier tecla para continuar");
            opcion=getch();
        }
        while(opcion!=ESC);
        fclose(archi);
    }
}

void muestraArchivoClientes (char nombreArchivo[], int flag)
{
    stCliente c;
    FILE *archi = fopen(nombreArchivo, "rb");
    if (archi)
    {
        while (fread(&c,sizeof (stCliente), 1, archi)>0)
        {


                muestraUnCliente(c,flag);


        }
        fclose(archi);
    }
}

int ultimoId(char nombreArchivo[])
{
    int id=0;
    stCliente c;
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo)
    {
        fseek(archivo, -1*sizeof(stCliente),SEEK_END);/// multiplicando por -1 pongo en negativo al empleado, se mueve -68bytes pj para atras
        if (fread(&c,sizeof(stCliente),1,archivo)>0)
        {
            id= c.id;
        }
        fclose(archivo);
    }
    return id;
}

int ultimoNroCliente(char nombreArchivo[])
{
    int nroCliente=0;
    stCliente c;
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo)
    {
        fseek(archivo, -1*sizeof(stCliente),SEEK_END);/// multiplicando por -1 pongo en negativo al empleado, se mueve -68bytes pj para atras
        if (fread(&c,sizeof(stCliente),1,archivo)>0)
        {
            nroCliente= c.nroCliente;
        }
        fclose(archivo);
    }
    return nroCliente;
}

///-------------------------------DAR DE BAJA CLIENTE----------------------------------------

void altaBajaCliente(int flag)
{
    int nroCliBus =0;
    int idCliente =0;
    printf("\n Ingrese nro de cliente: ");
    scanf("%d", &nroCliBus);

    idCliente=buscaIdUsuario("clientes.dat",nroCliBus);

    if (idCliente==0)
    {
        printf("\n No se encontro ningun cliente asociado a ese numero de cliente");
    }
    else
    {
        modificarBajaCliente("clientes.dat", idCliente, flag);
    }
}

int buscaIdUsuario(char nombreArchivo[], int nroClienteBuscar)///busca el consumo por cliente.
{
    stCliente c;
    int found=0;
    int idCliente=0;
    FILE *archivo= fopen(nombreArchivo,"rb");
    if (archivo)
    {
        while (found==0 && fread(&c,sizeof(stCliente),1,archivo)>0)
        {
            if (nroClienteBuscar==c.nroCliente)
            {
                idCliente = c.id;
                found=1;
            }
        }
        fclose(archivo);

    }
    return idCliente;
}

void modificarBajaCliente(char nombreArchivo[], int idCliente,int flag) ///Carga un consumo a otro existente.
{
    stCliente c;
    FILE *archivo= fopen(nombreArchivo, "rb+");
    if(archivo)
    {
        fseek(archivo,(idCliente-1)*sizeof(stCliente),SEEK_SET); /// me pone el puntero en el numero de registro que le paso
        fread(&c,sizeof(stCliente),1,archivo);

        c.eliminado=flag;
    }

    fseek(archivo,(idCliente-1)*sizeof(stCliente),SEEK_SET);
    fwrite(&c,sizeof(stCliente),1,archivo);

    fclose(archivo);
}


///--------------------------------------buscar cliente-----------------------------------------------------

int buscarClienteXDni (char nombreArchivo[]){
    stCliente c;
    int found=0;

    char dni[10];

    printf("\n Ingrese dni a buscar: ");
    fflush(stdin);
    gets(dni);

    FILE *archivo = fopen(nombreArchivo,"rb");

    if (archivo)
    {
        while (found==0 && fread(&c,sizeof(stCliente),1,archivo)>0)
        {
            if (strncmp(c.dni,dni,strlen(dni))==0)
            {
                found=1;
                muestraUnCliente(c,1);
                muestraUnCliente(c,0);
                muestraArchivoConsumo("consumo.dat",c.nroCliente,NULL,2);
            }
        }

        if(found==0){
             printf("\n No hay ningun cliente asignado al numero %s \n", dni);
        }

        fclose(archivo);
    }
    return found;
}

///-----------------------------------Modificacion clientes------------------------------------------

void cambiarChar()
{
    int opcion =0;

    int nroCliBus =0;
    int idCliente =0;
    printf("\n Ingrese el nro de cliente a modificar: ");
    scanf("%d", &nroCliBus);

    idCliente=buscaIdUsuario("clientes.dat",nroCliBus);

    if (idCliente==0)
    {
        printf("\n No se encontro ningun cliente asociado a ese numero de cliente");
    }
    else
    {
        printf("\n Que dato desea modificar: ");
        printf("\n1. Numero Movil: ");
        printf("\n2. Numero Dni: ");
        printf("\n3. Apellido: ");
        printf("\n4. Domicilio: \n");
        opcion=getch();
        switch(opcion)
        {
        case '1':
            modificarMovil("clientes.dat", idCliente);
            break;
        case '2':
            modificarApellido("clientes.dat", idCliente);
            break;
        case '3':
            modificarDni("clientes.dat", idCliente);
            break;
        case '4':
            modificarDomicilio("clientes.dat", idCliente);
            break;
        }
    }
}


void modificarMovil(char nombreArchivo[], int idCliente)
{
    stCliente c;
    char nuevoMovil[10];

    printf("\n Ingrese el nuevo numero de telefono: ");
    scanf("%s", nuevoMovil);

    FILE *archivo= fopen(nombreArchivo, "rb+");
    if(archivo)
    {
        fseek(archivo,(idCliente-1)*sizeof(stCliente),SEEK_SET);
        fread(&c,sizeof(stCliente),1,archivo);

        strcpy(c.movil, nuevoMovil);

    fseek(archivo,(idCliente-1)*sizeof(stCliente),SEEK_SET);
    fwrite(&c,sizeof(stCliente),1,archivo);

    fclose(archivo);
    }
    printf("\n Numero cambiado a %s", nuevoMovil);
}

void modificarApellido(char nombreArchivo[], int idCliente)
{
    stCliente c;
    char nuevoApellido[30];

    printf("\n Ingrese el nuevo apellido: ");
    scanf("%s", nuevoApellido);

    FILE *archivo= fopen(nombreArchivo, "rb+");
    if(archivo)
    {
        fseek(archivo,(idCliente-1)*sizeof(stCliente),SEEK_SET);
        fread(&c,sizeof(stCliente),1,archivo);

        strcpy(c.apellido, nuevoApellido);

    fseek(archivo,(idCliente-1)*sizeof(stCliente),SEEK_SET);
    fwrite(&c,sizeof(stCliente),1,archivo);

    fclose(archivo);
    }
    printf("\n Numero cambiado a %s", nuevoApellido);
}

void modificarDni(char nombreArchivo[], int idCliente)
{
    stCliente c;
    char nuevoDni[10];

    printf("\n Ingrese el nuevo dni: ");
    scanf("%s", nuevoDni);

    FILE *archivo= fopen(nombreArchivo, "rb+");
    if(archivo)
    {
        fseek(archivo,(idCliente-1)*sizeof(stCliente),SEEK_SET);
        fread(&c,sizeof(stCliente),1,archivo);

        strcpy(c.dni, nuevoDni);

    fseek(archivo,(idCliente-1)*sizeof(stCliente),SEEK_SET);
    fwrite(&c,sizeof(stCliente),1,archivo);

    fclose(archivo);
    }
    printf("\n Numero cambiado a %s", nuevoDni);
}

void modificarDomicilio(char nombreArchivo[], int idCliente){
    stCliente c;
    char nuevoDomicilio[45];

    printf("\n Ingrese el nuevo domicilio: ");
    fflush(stdin);
    gets(nuevoDomicilio);

    FILE *archivo= fopen(nombreArchivo, "rb+");
    if(archivo)
    {
        fseek(archivo,(idCliente-1)*sizeof(stCliente),SEEK_SET);
        fread(&c,sizeof(stCliente),1,archivo);

        strcpy(c.domicilio, nuevoDomicilio);

    fseek(archivo,(idCliente-1)*sizeof(stCliente),SEEK_SET);
    fwrite(&c,sizeof(stCliente),1,archivo);

    fclose(archivo);
    }
    printf("\n Numero cambiado a %s", nuevoDomicilio);
}

