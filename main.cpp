#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

typedef vector <unsigned> line; // un type représentant une ligne de la grille
typedef vector <line> mat; // un type représentant la grille


int main(){
    mat grille;
    initGrid(grille,5);

    unsigned coupMax = 20;
    unsigned nbCoup = 0;
    maPosition pos;
    char dir;

    while(nbCoup < coupMax){
        displayGrid(grille);
        cout << endl << "Saisir l'abscisse des coordonnees : " ;
        cin >> pos.abs;
        cout << endl << "Saisir l'ordonnee des coordonnees : " ;
        cin >> pos.ord;

        cout << endl << "Entrez 'Z' , 'Q' , 'S' ou 'D' pour vous deplacer respectivement "
                "vers le haut , à gauche , en bas ou à droite . " << endl;
        cout << endl << "Saisir la direction : " ;
        cin >> dir;

        makeAMove(grille,pos,dir);
        unsigned nbHM = 0;
        
        maPosition detecteur;
        while(true){ // Vérif et élim des colonnes
            atLeastThreeInAColumn(grille,detecteur,nbHM);
            if(!atLeastThreeInAColumn(grille,detecteur,nbHM)) break;
            removalInColumn(grille,detecteur,nbHM);
        }

        maPosition detecteur2;
        int g = 0;
        while(true){ // Vérif et élim des colonnes
            atLeastThreeInARow(grille,detecteur2,nbHM);
            if(!atLeastThreeInARow(grille,detecteur2,nbHM)) break;
            cout << "atLeast3InARow" << endl;
            removalInRow(grille,detecteur2,nbHM);
            g++;
            if(g > 20) {
                cout << "overflow exit" << endl;
                break;
            }
        }
        nbCoup++;
    }
    return 0;
}