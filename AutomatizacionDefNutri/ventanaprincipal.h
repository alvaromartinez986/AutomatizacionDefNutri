#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H
#include <QFileDialog>
#include <QMainWindow>

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();
    
private slots:

    /**
     * @brief on_actionAbrir_Imagen_triggered slot para
     */
    void on_actionAbrir_Imagen_triggered();

    void on_actionHistograma_triggered();

private:
    Ui::VentanaPrincipal *ui;
};

#endif // VENTANAPRINCIPAL_H
