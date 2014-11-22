#include <iostream>
#include "ventanaprincipal.h"
#include "Proyecto.h"

using namespace std;

int main(int argc, char *argv[])
{

    Proyecto miProyecto(argc, argv);
    VentanaPrincipal w;
    w.show();

    return miProyecto.exec();
}


