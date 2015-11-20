#include "fuentes.h"

//Obtener fecha con formato
void fuentes::getFecha(){
    t = time(0);
    struct tm * now = localtime( & t );
    distance = 60;
    cout<<(now->tm_year+1900)<<'-'<<(now->tm_mon+1)<<'-'<<now->tm_mday<< endl;
}

void fuentes::alarmhand(int)
{
    cout<< distance;
}
