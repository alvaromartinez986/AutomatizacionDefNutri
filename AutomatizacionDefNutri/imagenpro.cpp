#include "imagenpro.h"
#include <algorithm>    // std::sort
#include <QDebug>
#define PI 3.14159265


imagenPro::imagenPro()
{
}

imagenPro::imagenPro(QString miRuta)
{

    image = new QImage(miRuta);
    for(int i = 0; i<256; i++){
        histograma[i]=0;
    }
    getChannels();

}



void imagenPro::calcularHistograma(QImage imagen)
{
    for(int i= 0; i<imagen.width(); i++){
        for(int j = 0; j<imagen.height(); j++){
            QColor pixel(imagen.pixel(i, j));
            histograma[pixel.red()]++;
            histogramaBlue[pixel.blue()]++;
            histogramaGreen[pixel.green()]++;
        }
    }
    histogramaRed = histograma;

}
/*
void imagenPro::mostrarHisto()
{
        ofstream archivo("Datos.sci");  // constructor de ofstream
        int mayor;
        int menor;
        bool flag = true;

        archivo << "x = [";

    for(int i= 0; i<256; i++){
            archivo << histograma[i] << " ";
            qDebug() << histograma[i] << " ";
            if(flag){
                if(histograma[i]!=0){
                    menor = i;
                    flag = false;
                }
            }
            if(histograma[i]!=0){
                mayor=i;
            }
    }

    archivo << "]";

    archivo.close();
}*/

void imagenPro::sumarCon(int val)
{
    imageProcess = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    for(int i= 0; i<image->width(); i++){
        for(int j= 0; j<image->height(); j++){
            QColor imagen(image->pixel(i, j));



            if((imagen.blue()+val)<255){
                imagen.setBlue(imagen.blue()+val);
            }else{
                imagen.setBlue(255);
            }
            if((imagen.green()+val)<255){
                imagen.setGreen(imagen.green()+val);
            }else{
                imagen.setGreen(255);
            }
            if((imagen.red()+val)<255){
                imagen.setRed(imagen.red()+val);
            }else{
                imagen.setRed(255);
            }
            imageProcess->setPixel(i, j, imagen.rgb());
        }
    }

}

void imagenPro::getChannels()
{
    QVector <int> columnRed;
    QVector <int> columnGreen;
    QVector <int> columnBlue;
    for(int i= 0; i<image->width(); i++){
        for(int j= 0; j<image->height(); j++){
            QColor imagen(image->pixel(i, j));
            columnRed.push_back(imagen.red());
            columnGreen.push_back(imagen.green());
            columnBlue.push_back(imagen.blue());

        }
        red.push_back(columnRed);
        green.push_back(columnGreen);
        blue.push_back(columnBlue);
        columnRed.clear();
        columnGreen.clear();
        columnBlue.clear();
    }

}

void imagenPro::binarizarImg(int umbral)
{
    imageProcess = new QImage(image->width(), image->height(), QImage::Format_Mono);
    for(int i= 0; i<image->width(); i++){
        for(int j= 0; j<image->height(); j++){
            QColor imagen(image->pixel(i, j));
            if(imagen.green()<umbral){
                imageProcess->setPixel(i, j, 0);
            }else{
                imageProcess->setPixel(i, j, 1);
            }

        }
    }
}

void imagenPro::multiThresholding()
{
    imageProcess = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    for(int i= 0; i<image->width(); i++){
        for(int j= 0; j<image->height(); j++){
            QColor imagen(image->pixel(i, j));
            if(imagen.green()<70){
                imageProcess->setPixel(i, j, qRgb(0, 0, 0));
            }else{
                if(imagen.green()<140){
                    imageProcess->setPixel(i, j, qRgb(85, 85, 85));
                }else{
                    if(imagen.green()<170){
                        imageProcess->setPixel(i, j, qRgb(165, 165, 165));
                    }else{
                        imageProcess->setPixel(i, j, qRgb(255, 255, 255));
                }

            }

            }
        }
    }
}

void imagenPro::createPGM()
{
    imageProcess = new QImage(gray.at(0).size(), gray.size(), QImage::Format_Indexed8);
    imageProcess->setColorTable(tabla);

    for(int i=0; i<imageProcess->width(); i++){
        for(int j = 0; j<imageProcess->height(); j++){
            imageProcess->setPixel(i, j, gray[j][i]);
        }
    }

}

int *imagenPro::getHisto()
{
    return histograma;
}

void imagenPro::leerArchPP(QString ruta)
{

    QFile imagen(ruta);
    imagen.open(QIODevice::ReadOnly);
    QTextStream infoImagen(&imagen);
    QString formato;
    formato = infoImagen.readLine();
    QString comments;
    infoImagen >> comments;
    QString ancho;
    ancho = comments;
    while((ancho.at(0)=='#')||(comments.at(0)=='#')){
        infoImagen >> ancho;
    }

    QString largo;
    QString max;
    infoImagen >> largo;
    infoImagen >> max;

    for(int i = 0; i<max.toInt(); i++){
        tabla.push_back(qRgb(i, i ,i));
    }

    QVector <int> filas;
    for(int i = 0; i<largo.toInt(); i++){
        for(int j = 0; j<ancho.toInt(); j++){
            QString valorP;
            infoImagen >> valorP;
            filas.push_back(valorP.toInt());

        }
        gray.push_back(filas);
        filas.clear();
    }



    imagen.close();

}




QPixmap imagenPro::resultado()
{
    return QPixmap::fromImage(*imageProcess);

}

void imagenPro::filtroMediana()
{
    int valorMed;
    valorMed = 0;
    imageProcess = new QImage(image->size(), QImage::Format_ARGB32);
    for(int i=1; i<(imageProcess->width()-1); i++){
        for(int j=1; j<(imageProcess->height()-1); j++){
            valorMed = operMediana(i, j);
            imageProcess->setPixel(i, j, qRgb(valorMed, valorMed, valorMed));
        }
    }
}

int imagenPro::operMediana(int i, int j)
{

    int matrizMed[9];
    int k;
    k = 0;
    for(int m=(i-1); m<(i+2); m++){
        for(int h=(j-1); h<(j+2); h++){
            matrizMed[k]= green[m][h];
            k++;
        }

    }

    std::sort(matrizMed, matrizMed+9);

    return matrizMed[5];

}

void imagenPro::filtroSobel()
{
    imageProcess = new QImage(image->size(), QImage::Format_ARGB32);
    //Construccion de las matrices Hx y Hy
    float valoresSobelX[3][3] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    float valoresSobelY[3][3] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    QVector < int> filas;
    QVector <int> colum;
    QVector <int> valoresE;
    QVector <int> valoresGradiente;
    int valorEx, valorEy, valorE, valorGradiente;
    valorEx = 0;
    valorEy = 0;
    valorE = 0;

    for(int i=1; i<(imageProcess->width()-1); i++){
        for(int j=1; j<(imageProcess->height()-1); j++){
            valorEx = operacionConvolucion(valoresSobelX, i, j);
            valorEy = operacionConvolucion(valoresSobelY, i, j);
            filas.push_back(valorEx);
            colum.push_back(valorEy);
            valorE = sqrt(pow(valorEx, 2)+pow(valorEy, 2));
            if(valorEy==0){
                valorGradiente =90;
            }else{
                valorGradiente = (int)(atan(valorEx/valorEy)*(180/PI));
                if(valorGradiente<0){
                    valorGradiente = 360+valorGradiente;
                }
            }
            valoresGradiente.push_back(valorGradiente);
            if(valorE<255){
                imageProcess->setPixel(i, j, qRgb(valorE, valorE, valorE));
            }else{

                valorE=255;
                imageProcess->setPixel(i, j, qRgb(255, 255, 255));
            }
             valoresE.push_back(valorE);
        }
        valoresEx.push_back(filas);
        valoresEy.push_back(colum);
        this->valoresE.push_back(valoresE);
        gradiente.push_back(valoresGradiente);
        filas.clear();
        colum.clear();
        valoresE.clear();
        valoresGradiente.clear();

    }

}

int imagenPro::operacionConvolucion(float valor[3][3], int i, int j)
{
    float resultado;
    int k , l;
    k = l = 0;
    resultado = 0;
    for(int m=(i-1); m<(i+2); m++){
        for(int h=(j-1); h<(j+2); h++){
            resultado += valor[k][l]*green[m][h];
            k++;
        }
        l++;
        k=0;
    }

    return resultado;

}

void imagenPro::filtroCanny()
{

    discretisarMatrizGradiente();

    imageProcess = new QImage(image->size(), QImage::Format_ARGB32);
    int valorMx, valorMy, valorD1, valorD2;
    valorMx = valorMy = valorD1, valorD2 = 0;

    QVector <QVector <int> > valoresGMx;
    QVector <QVector <int> > valoresGMy;
    QVector <int> valoresMx;
    QVector <int> valoresMy;


    for(int i=1; i<(imageProcess->width()-1); i++){
        for(int j=1; j<(imageProcess->height()-1); j++){

            valorD1 = valoresE[valoresGMx[i-1][j-1]+i][valoresGMy[i-1][j-1]+j];
            valorD2 = valoresE[(valoresGMx[i-1][j-1]*-1)+i][(valoresGMy[i-1][j-1]*-1)+j];
            if(valorD1<valoresE[i][j]){
                imageProcess->setPixel(i, j, qRgb(valoresE[i][j], valoresE[i][j],valoresE[i][j]));
            }else{
                imageProcess->setPixel(i, j, qRgb(0, 0,0));
            }
            if(valorD2<valoresE[i][j]){
                imageProcess->setPixel(i, j, qRgb(valoresE[i][j], valoresE[i][j],valoresE[i][j]));
            }else{
                imageProcess->setPixel(i, j, qRgb(0, 0,0));
            }
        }
    }
}


int imagenPro::operMov(double l)
{
    if(l>0){
        return 1;
    }else{
        if(l<0){
            return -1;
        }else{
            return 0;
        }
    }
}


int imagenPro::dosPicosThres(){

    int max1=0;
    for(int i=0;i<256;i++)
        if(histograma[i]>histograma[max1])
            max1=i;

    int h = 0;
    int maxH= 0;

    int histograma2[256];
    for(int i=0; i<256; i++){
        histograma2[i] = (int)(pow((i-max1), 2)*histograma[i]);
    }


    int max2=0;
    for(int i=0;i<256;i++)
        if(histograma2[i]>histograma2[max2])
            max2=i;

    int min=0;
    for(int i=max2;i<max1;i++)
        if(histograma[i]<histograma[min])
            min=i;



    return min;
}

int imagenPro::isoData()
{

    double u2 = 0;
    double u1 = 0;

    double t1= 0;
    double t2 = 0;
    int m = 20;

    for(int i = 0; i<m; i++){
        u1+= histograma[i];
    }
    u1 = u1/m;


    for(int i = m; i<256; i++){
        u2+= histograma[i];
    }
    u2 = u2/(255-m);

    t1 = (u1+u2)/2;
    qDebug() << "valor de u1" << u1 << "valor de u2 " << u2 << "valor de t " << t1 << "valor de m " << m;
    do{

        u1 = (m*u1+histograma[m+1])/(m+1);
        u2 = ((256-m)*u2-histograma[m+1])/(255-m);

        t2 = (u1+u2)/2;
        qDebug() << "valor de u1" << u1 << "valor de u2 " << u2 << "valor de t " << t1 << "valor de m " << m;


        t1 = t2;
        m++;
    }while(m<250);

    return t2;
}
/*
void imagenPro::dilatacion()
{
    int elementoEstructural[3][3] = {0, 1, 0, 0, 1, 0, 1, 0, 1, 1};


}*/

void imagenPro::discretisarMatrizGradiente()
{
    int valor;
    valor= 0;
    for(int i=0; i<gradiente.size(); i++){
        for(int j = 0; j<gradiente.size(); j++){
            valor= gradiente[i][j];
            if(((valor>157.5)&&(valor<=202.5))||((valor>337.5)&&(valor<=22.5))){
                    gradiente[i][j]=0;
            }else{
                if(((valor>202.5)&&(valor<=247.5))||((valor>22.5)&&(valor<=67.5))){
                    gradiente[i][j]=45;
                }else{
                    if(((valor>247.5)&&(valor<=292.5))||((valor>67.5)&&(valor<=112.5))){
                        gradiente[i][j]=90;

                    }else{
                        if(((valor>292.5)&&(valor<=337.5))||((valor>112.5)&&(valor<=157.5))){
                            gradiente[i][j]=135;
                        }
                    }
                }
            }

        }
    }

}





