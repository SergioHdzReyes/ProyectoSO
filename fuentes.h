#ifndef FUENTES_H
#define FUENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include <signal.h>
using namespace std;

class fuentes
{
public:
    void getFecha();
    void alarmhand(int);
    void getProcesoID();
    void getProcesoPadreID();
    void getUserID();
    void getGroupID();
    pid_t proceso;
    pid_t padre;
    uid_t user;
    gid_t group;
    time_t t;// get time now
    int mt;
    int distance;
};

#endif // FUENTES_H
