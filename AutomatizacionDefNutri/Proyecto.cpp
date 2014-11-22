#include "Proyecto.h"


Proyecto::Proyecto(int& argc, char ** argv) :
    QApplication(argc, argv)
{
}

Proyecto::~Proyecto()
{
}

bool Proyecto::notify(QObject * receiver, QEvent * event)
{
    try {
        return QApplication::notify(receiver, event);
    }catch(const char* s){
        QMessageBox::warning(0, QString::fromUtf8("Excepción"),
                             QString::fromUtf8("Excepción: ")
                             + QString::fromUtf8(s));
    } catch(std::exception& e) {
        QMessageBox::warning(0, QString::fromUtf8("Excepción"),
                             QString::fromUtf8("Excepción: ")
                             + QString::fromUtf8(e.what()));
    }
}
