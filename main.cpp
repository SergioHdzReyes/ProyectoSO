/*
 * En este programa podemos ver el uso de distintas funciones
 * que son llamadas al sistema operativo en este caso Linux
*/
#include <fuentes.h>
using namespace std;

int main(void)
{
    fuentes obj;

    obj.proceso = getpid();
    obj.getFecha();
    obj.padre = getppid();
    obj.user = getuid();
    obj.group = getgid();

    printf("Proceso: %d\nPadre: %d\n", obj.proceso, obj.padre);

    cout<<"\n";
    return 0;
}
