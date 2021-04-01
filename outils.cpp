#include "outils.h"
using namespace outils;


// On initialise la taille du terrain
int C=0;
int L=0;

// On créer ensuite deux plans en miroir
int**PLAN;
int**MIROIR;

const int MAXI = 1000;
const float SEUIL = 0.6*MAXI;

// Les différentes valeurs possibles
enum Types { ARBRE, TERRE, EAU, FEU, CENDRE, CETEINTE };

void  dimension_console(void);
void  creer_matrices(void);
void  detruire__matrices(void);
void  init_bois(void);

void  affiche_plan(void);
void  mem_affiche_plan(void);

void dimension_console()
{
    cout << "Entrez largeur fenetre :" << endl;
    cin >> C;

    cout << "Entrez Hauteur fenetre :" << endl;
    cin >> L;

    // une taille minimum
    C = (C < 10) ? 10 : C;
    L = (L < 10) ? 10 : L;

    O_ConsoleResize(C, L);
}

void creer_matrices()
{
    PLAN = new int*[L];
    MIROIR = new int*[L];
    for (int y = 0; y < L; y++) {
        PLAN[y] = new int[C];
        MIROIR[y] = new int[C];
    }
}

// Destruction des deux matrices
void detruire__matrices()
{
    for (int y = 0; y < L; y++) {
        delete[] PLAN[y];
        delete[] MIROIR[y];
    }
    delete[] PLAN;
    delete[] MIROIR;
}

void init_bois()
{
    int x, y;
    for (y = 0; y<L; y++)
        for (x = 0; x<C; x++) {
            if ((rand() % MAXI)<SEUIL)
                PLAN[y][x] = ARBRE;
            else if
                PLAN[y][x] = TERRE;
                else
                PLAN[y][x] = EAU;
        }
}

// Affichage
void affiche_plan()
{
    int y, x;
    for (y = 0; y<L; y++) {
        for (x = 0; x<C; x++) {
            switch (PLAN[y][x]) {
            case ARBRE: O_Textcolor(6 * 16); break;
            case TERRE: O_Textcolor(7 * 16);   break;
            case FEU: O_Textcolor(12 * 16);  break;
            case CENDRE: O_Textcolor(2 * 16);  break;
            case CETEINTE: O_Textcolor(0);  break;
            }
            O_Gotoxy(x, y);
            putchar(' ');
        }
    }
}
