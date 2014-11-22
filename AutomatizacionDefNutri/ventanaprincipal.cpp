#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_actionAbrir_Imagen_triggered()
{
    QString archivo = QFileDialog::getOpenFileName(this, tr("Seleccionar archivo"),
                                                   "",
                                                   tr("Images (*.png *.pgm *.jpg *.pgm)"));
    QPixmap* imagenPx = new QPixmap(archivo);

    ui->imagen->setPixmap(archivo);

}

void VentanaPrincipal::on_actionHistograma_triggered()
{

}
