#ifndef FUENTES_H
#define FUENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

using namespace std;

class fuentes
{
public:
    fuentes();
    void menu();
    void getFecha();
    static void alarmhand(int sum);
    static void detenerAlarma(int sum);
    void getProcesoID();
    void getProcesoPadreID();
    void getUserID();
    void getGroupID();
    void openFile();
    void closeFile();
    void createFile();
    void deleteFile();
    void writeFile();
    pid_t proceso;
    pid_t padre;
    uid_t user;
    gid_t group;
    time_t t;// get time now
    int mt;
    static const int distancia = 60;
    FILE *arch;
    char *archivoCreado;
    ssize_t escribir;
};

#endif // FUENTES_H
