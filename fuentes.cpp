#include "fuentes.h"

fuentes::fuentes(){
}

void fuentes::menu(){
    cout<<"Elija la opcion deseada\n"<<"1) Obtener fecha del sistema\n"<<"2) Obtener ID del proceso corriente\n"
        <<"3) Obtener ID del proceso padre\n"<<"4) Obtener ID de grupo del usuario actual\n"
        <<"5) Comenzar alarma repetida con lapsos de 1 segundo\n"<<"6) Detener Alarma!\n"<<"7) Abrir archivo\n"
        <<"8) Cerrar archivo\n"<<"9) Crear un archivo\n"<<"10) Borrar archivo creado\n"
        <<"11) Escribir en archivo creado en punto 9) \n"
        <<"12) \n"
        <<"13) \n"
        <<"14) \n"
        <<"15) \n"
        <<"0) Salir\n";
}
//Obtener fecha con formato
void fuentes::getFecha(){
    t = time(0);
    struct tm * now = localtime( & t );
    cout<<"Fecha actual del sistema en formato YYYY-MM-DD\n";
    cout<<(now->tm_year+1900)<<'-'<<(now->tm_mon+1)<<'-'<<now->tm_mday<< endl;
}
//Inicia una alarma de 1 segundo entre cada señal
void fuentes::alarmhand(int sum){
    cout<<"\t\t\t\t\t\t Alarma!\n";
    alarm(1);
}
//Se detiene la alarma con alarm(0)
void fuentes::detenerAlarma(int sum){
    cout<<"Se detiene la alarma con alarm(0)\n"
        <<"Alarma Detenida!!";
    alarm(0);
}
//Imprime descripcion del metodo e imprime el ID del proceso
void fuentes::getProcesoID(){
    fuentes::proceso = getpid();
    cout<<"Se obtiene el ID del proceso de este programa\n"
        <<fuentes::proceso<<endl;
}
//Imprime descripcion del metodo e imprime el ID del proceso padre
void fuentes::getProcesoPadreID(){
    fuentes::padre = getppid();
    cout<<"Se obtiene el ID del proceso padre de este programa\n"
        <<fuentes::padre<<endl;
}
//Imprime descripcion del metodo e imprime el ID del usuario
void fuentes::getUserID(){
    fuentes::user = getuid();
    cout<<"Se obtiene el ID del usuario actual\n"
        <<fuentes::user<<endl;
}
//Imprime descripcion del metodo e imprime el ID del grupo del usuario actual
void fuentes::getGroupID(){
    fuentes::group = getgid();
    cout<<"Se obtiene el ID del grupo del usuario actual\n"
       <<fuentes::group<<endl;
}
//Metodo para abrir un archivo
void fuentes::openFile(){
    fuentes::arch = fopen("/home/sergio/QT/ProyectoSO/Archivo.txt", "r");
    if(!fuentes::arch){
        getchar();
        cout<<"No se pudo abrir el archivo";
    }
    while(!feof(fuentes::arch)) fputc(fgetc(fuentes::arch), stdout);
}
//Metodo para cerrar el archivo una vez abierto
void fuentes::closeFile(){
    try {
        fclose(fuentes::arch);
        cout<<"Archivo Archivo.txt cerrado!";
    } catch (int e) {
        cout<<e;
    }
}

void fuentes::createFile(){
    char *nombre;
    cout<<"Escribe la ruta completa del archivo en /home/sergio/ABCDEF.txt\n";
    cin>>nombre;
    fuentes::archivoCreado = nombre;
    open(nombre, O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
}

void fuentes::deleteFile(){
    unlink(fuentes::archivoCreado);
    cout<<"Archivo "<<fuentes::archivoCreado<<" eliminado";
}

void fuentes::writeFile(){
    FILE *escribir = fopen(fuentes::archivoCreado, "wb");
    char *content;

    cout<<"Ingresa el contenido del archivo:\n";
    cin>>content;
    fwrite(content, sizeof(char), sizeof(content), escribir);
}
