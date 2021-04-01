
#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <QtGui>

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>



/*
//code complexe plus une aide à la méthode
#include <QApplication>
#include "outils.h"
#include <QtGui>
#include <QtGui/QImage>
#include <QtCore/QDebug>
#include <QLabel>

int main(int argc, char *argv[])
{
QApplication app(argc, argv);

QWidget fenetre;
QImage monImage("C:/Users/vdupe/incendie/couleur/terre.jpg");
qDebug() << monImage.size().width() << "x" << monImage.size().height();

QLabel *label = new QLabel(&fenetre);
QPixmap pixmap("C:/Users/vdupe/incendie/couleur/terre.jpg");
label->setPixmap(pixmap);
label->resize(pixmap.size());
fenetre.show();

return app.exec();
}

*/
//code le plus aboutie pb sur les widgets
//mais travail avec des pointeurs donc plus simple pour la suite A PRIVILEGIE
#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <QtGui>

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>

/*
int main(int argc, char *argv[])
{
/
    QApplication app(argc, argv);
    QLabel *label;


QWidget *widget = new QWidget;
QLabel  *label  = new QLabel;
QPixmap *pixmap_img = new QPixmap("C:/Users/vdupe/incendie/couleur/terre.jpg");
// lieu ou se trouve l'image

label->setPixmap(*pixmap_img);

QLabel *label = new QLabel(this);
label->setPixmap(QPixmap("C:/Users/vdupe/incendie/couleur/terre.jpg"));

widget->show();

    return app.exec();

}
*/

//code de base, le plus simple, mais affiche les trois couleurs sur 3 pages différentes

int main(int argc, char* argv[])

{

    QApplication app(argc, argv);
    QLabel label;
    QLabel label1;
    QLabel label2;
    QWidget fenetre;










    //on donne l'image au label
    label.setPixmap(QPixmap("C:/Users/vdupe/incendie/couleur/terre.jpg"));
    //taille image
    label.setGeometry(0,0,100,100);



    label1.setPixmap(QPixmap("C:/Users/vdupe/incendie/couleur/arbre.jpg"));
    label1.setGeometry(0,0,400,200);




    label2.setPixmap(QPixmap("C:/Users/vdupe/incendie/couleur/eau.png"));
    label2.setGeometry(0,0,400,200);




 QGridLayout *layout= 0;
    for(int row = 0; row < 10; row++)
    {
        for(int column = 0; column < 10; column++)
           {
            layout = new QGridLayout;



            layout->addWidget(new QLabel("C:/Users/vdupe/incendie/couleur/arbre.jpg"));
            layout->addWidget(new QLabel("C:/Users/vdupe/incendie/couleur/eau.png"));
            layout->addWidget(new QLabel("C:/Users/vdupe/incendie/couleur/terre.jpg"));


        }

    }




    fenetre.setLayout(layout);
    fenetre.show();

    return app.exec();


}

