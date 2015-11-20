/*
 * En este programa podemos ver el uso de distintas funciones
 * que son llamadas al sistema operativo en este caso Linux
*/
#include <fuentes.h>
using namespace std;

int main(void)
{
    fuentes obj;
    int opc;

    while(true){
        obj.menu();
        cin>>opc;
        system("clear");
        switch(opc){
        case 1:
            obj.getFecha();
            getchar();
            break;
        case 2:
            obj.getProcesoID();
            getchar();
            break;
        case 3:
            obj.getProcesoPadreID();
            getchar();
            break;
        case 4:
            obj.getUserID();
            getchar();
            break;
        case 5:
            signal(SIGALRM, obj.alarmhand);
            obj.alarmhand(1);
            getchar();
            break;
        case 6:
            obj.detenerAlarma(1);
            getchar();
            break;
        case 7:
            obj.openFile();
            getchar();
            break;
        case 8:
            obj.closeFile();
            getchar();
            break;
        case 9:
            obj.createFile();
            getchar();
            break;
        case 10:
            obj.deleteFile();
            getchar();
            break;
        case 11:
            obj.writeFile();
            getchar();
            break;
        case 0:
            exit(1);
        }
        getchar();
        system("clear");
    }

    return 0;
}
