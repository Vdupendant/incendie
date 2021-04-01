/ réservé activité du feu
int cmpt_feu = 0;

int   mise_a_feu(void);
void  propagation(void);

int main()
{
     printf("Appuyez sur une touche pour lancer");
    while (!fin) {
         if (_kbhit()) {
            switch (_getch()) {
            case VK_ESCAPE: fin = 1; break;
            case VK_RETURN :
                init_bois();
                cmpt_feu = mise_a_feu();
                break;
            case 'p': ralenti+=10; break;
            case 'm': ralenti-=10; break;

            }
        }
        if (O_Top(ralenti) && cmpt_feu) {
            propagation();
            //affiche_plan();
            mem_affiche_plan();
        }
    }
    destroy__matrices();
    return 0;
}

// Le feu se propage sur la deuxième colonne
int mise_a_feu()
{
    int y, x = 1, cmpt = 0;

    for (y = 0; y<L; y++)
        if (PLAN[y][x] == ARBRE) {
            PLAN[y][x] = FEU;
             else if (PLAN[y][x] == TERRE) {
            PLAN[y][x] = FEU;
              else (PLAN[y][x] == EAU) {
            PLAN[y][x] = FEU;
            cmpt++;
        }
    for(int y = 0; y<L; y++)
        memcpy(MIROIR[y], PLAN[y], sizeof(int)*C);

    return cmpt;
}

//fonction de propagation

void propagation()
{
    int x, xo, xe, y, yn, ys;
    for (y = 0; y<L; y++) {
        yn = (y - 1 + L) % L;      // nord
        ys = (y + 1) % L;         // sud
        for (x = 0; x<C; x++) {
           xo = (x - 1 + C) % C;   // ouest
           xe = (x + 1) % C;      // est
           if (PLAN[y][x] == ARBRE)
              else if (PLAN[y][x] == TERRE)
                else (PLAN[y][x] == EAU )
              { // si BOIS
              // et si FEU autour
              if (PLAN[yn][x] == FEU || PLAN[ys][x] == FEU ||
                PLAN[y][xo] == FEU || PLAN[y][xe] == FEU) {
               MIROIR[y][x] = FEU; // passe en FEU en MIROIR
               cmpt_feu++;
            }
           }
             // mais si FEU
           else if (PLAN[y][x] == FEU) {
                 // passe à CENDRE dans MIROIR
            MIROIR[y][x] = CENDRE;
                cmpt_feu--;
            }
               // mais si CENDRE
           else (PLAN[y][x] == CENDRE) {
                 // passe à CENDRE ETEINTE dans MIROIR
            MIROIR[y][x] = CETEINTE;
                cmpt_feu--;
            }
        }
    }
    // recopie MIROIR
    for (int y = 0; y<L; y++)
       memcpy(PLAN[y], MIROIR[y], sizeof(int)*C);
}
