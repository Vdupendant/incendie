#define OUTILS_H

// regroupement des bibliothèques utiles dans le projet
#include <cstdio>
#include<cstdlib>
#include <conio.h>


// bibliothèques nécessaires pour outils.h
#include<ctime>
#include <iostream>
#include<Windows.h>
#include <string>
#include <exception>
#include <QLabel>
#include <QStylePainter>
using namespace std;

// éventuellement possibilité de répartir le code
// sur plusieurs fichiers
/*void QLabel::paintEvent(QPaintEvent event)
{
       QStylePainter painter(this);
       painter.rotate(90);
       painter.drawText(0, 0, text());
}*/


namespace outils
{
    HANDLE O_GetStdout();
    void O_ConsoleResize(int& width, int& height);
    COORD O_ConsoleMinSize(HANDLE h);
    int O_Top(int dur);
    void O_Gotoxy(int x, int y);
    void O_Textcolor(int color);
    void O_ConsoleCursor(int val);
    void O_Blit(CHAR_INFO*dat, SMALL_RECT*datsrc,
                               SMALL_RECT*consdest);
    void O_ClearToColor(int color, char lettre);

}

namespace outils
{
    /******************
    ConsoleGetStdout fonction
    Récupère le handle pour les sorties sur la fenêtre
    console
    */
    HANDLE O_GetStdout()
    {
        static HANDLE h = nullptr;
        if (h == nullptr) {
            h = GetStdHandle(STD_OUTPUT_HANDLE);
            if (h == INVALID_HANDLE_VALUE)
                 {}


        }
        return h;
    }

    /* Redimensionne la fenêtre console, partie visible et
    partie mémoire sont ajustées */

    void O_ConsoleResize(int width, int height)
    {
        HANDLE h = O_GetStdout();

        // récupération des tailles maximum et minimum
        // supportées par la console
        COORD max = GetLargestConsoleWindowSize(h);
        COORD min = O_ConsoleMinSize(h);
        width = (width > max.X) ? max.X :
                ((width < min.X) ? min.X : width);
        height = (height > max.Y) ? max.Y :
                ((height < min.Y) ? min.Y : height);

        CONSOLE_SCREEN_BUFFER_INFO info;
        if (!GetConsoleScreenBufferInfo(h, &info))



        // si la hauteur  demandée est inférieure à la
        // hauteur actuelle
        if (height < info.dwSize.Y) {

           // diminuer d’abord le rectangle fenêtre
           info.srWindow.Bottom = height - 1;
           if (!SetConsoleWindowInfo(h, TRUE, &info.srWindow))


           // ensuite le buffer correspondant
           info.dwSize.Y = height;
           if (!SetConsoleScreenBufferSize(h, info.dwSize))



        // si la taille demandée est supérieure à
        // la taille actuelle

           // d’abord augmenter la taille du buffer
           info.dwSize.Y = height;
           if (!SetConsoleScreenBufferSize(h, info.dwSize))


           // ensuite le rectangle correspondant de la fenêtre
           info.srWindow.Bottom = height - 1;
           if (!SetConsoleWindowInfo(h, TRUE, &info.srWindow))


        // idem pour la largeur
        if (width < info.dwSize.X) {
             info.srWindow.Right = width - 1;
           if (!SetConsoleWindowInfo(h, TRUE, &info.srWindow))


           info.dwSize.X = width;
           if (!SetConsoleScreenBufferSize(h, info.dwSize))



           info.dwSize.X = width;
           if (!SetConsoleScreenBufferSize(h, info.dwSize))


           info.srWindow.Right = width - 1;
           if (!SetConsoleWindowInfo(h, TRUE, &info.srWindow))



}
}
}

}
