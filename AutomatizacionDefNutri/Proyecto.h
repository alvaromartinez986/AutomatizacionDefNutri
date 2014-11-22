#ifndef PROYECTO_H
#define PROYECTO_H

#include <QApplication>
#include <QMessageBox>

class Proyecto : public QApplication {
public:
    Proyecto(int& argc, char ** argv);
    virtual ~Proyecto();
    virtual bool notify(QObject * receiver, QEvent * event);

};

#endif // PROYECTO_H
