/********************************************************************************
** Form generated from reading UI file 'ventanaprincipal.ui'
**
** Created: Fri Nov 21 19:42:29 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAPRINCIPAL_H
#define UI_VENTANAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QAction *actionAbrir_Imagen;
    QAction *actionGuardar_Imagen;
    QAction *actionHistograma;
    QWidget *centralwidget;
    QLabel *imagen;
    QMenuBar *menubar;
    QMenu *menuInicio;
    QMenu *menuImagen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QString::fromUtf8("VentanaPrincipal"));
        VentanaPrincipal->resize(640, 480);
        actionAbrir_Imagen = new QAction(VentanaPrincipal);
        actionAbrir_Imagen->setObjectName(QString::fromUtf8("actionAbrir_Imagen"));
        actionGuardar_Imagen = new QAction(VentanaPrincipal);
        actionGuardar_Imagen->setObjectName(QString::fromUtf8("actionGuardar_Imagen"));
        actionHistograma = new QAction(VentanaPrincipal);
        actionHistograma->setObjectName(QString::fromUtf8("actionHistograma"));
        centralwidget = new QWidget(VentanaPrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        imagen = new QLabel(centralwidget);
        imagen->setObjectName(QString::fromUtf8("imagen"));
        imagen->setGeometry(QRect(20, 20, 350, 350));
        imagen->setScaledContents(true);
        VentanaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaPrincipal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 25));
        menuInicio = new QMenu(menubar);
        menuInicio->setObjectName(QString::fromUtf8("menuInicio"));
        menuImagen = new QMenu(menubar);
        menuImagen->setObjectName(QString::fromUtf8("menuImagen"));
        VentanaPrincipal->setMenuBar(menubar);
        statusbar = new QStatusBar(VentanaPrincipal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VentanaPrincipal->setStatusBar(statusbar);

        menubar->addAction(menuInicio->menuAction());
        menubar->addAction(menuImagen->menuAction());
        menuInicio->addAction(actionAbrir_Imagen);
        menuInicio->addAction(actionGuardar_Imagen);
        menuImagen->addAction(actionHistograma);

        retranslateUi(VentanaPrincipal);

        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QApplication::translate("VentanaPrincipal", "Proyecto analisis deficiencias nutricionales", 0, QApplication::UnicodeUTF8));
        actionAbrir_Imagen->setText(QApplication::translate("VentanaPrincipal", "Abrir Imagen", 0, QApplication::UnicodeUTF8));
        actionGuardar_Imagen->setText(QApplication::translate("VentanaPrincipal", "Guardar Imagen", 0, QApplication::UnicodeUTF8));
        actionHistograma->setText(QApplication::translate("VentanaPrincipal", "Histograma", 0, QApplication::UnicodeUTF8));
        imagen->setText(QString());
        menuInicio->setTitle(QApplication::translate("VentanaPrincipal", "Inicio", 0, QApplication::UnicodeUTF8));
        menuImagen->setTitle(QApplication::translate("VentanaPrincipal", "Imagen", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
