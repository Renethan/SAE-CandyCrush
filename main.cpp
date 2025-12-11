#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

typedef vector <unsigned> line; // un type représentant une ligne de la grille
typedef vector <line> mat; // un type représentant la grille


int main(){
    mat grille;
    initGrid(grille,8);

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

        cout << endl << "Entrez 'Q' , 'E' , 'S' ou 'Z' pour vous deplacer respectivement "
                "vers la gauche , droite , en bas ou en haut. " << endl;
        cout << endl << "Saisir la direction : " ;
        cin >> dir;

        makeAMove(grille,pos,dir);

        unsigned nbHM = 0;

        while(atLeastThreeInAColumn(grille,pos,nbHM)){ // Vérif et élim des colonnes
            atLeastThreeInAColumn(grille,pos,nbHM);
            removalInColumn(grille,pos,nbHM);
        }
        while(atLeastThreeInARow(grille,pos,nbHM)){ // Vérif et élim des lignes
            atLeastThreeInARow(grille,pos,nbHM);
            removalInRow(grille,pos,nbHM);
        }
        nbCoup++;
    }
    return 0;
}