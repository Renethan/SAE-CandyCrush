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

    unsigned nbHM = 0;
    maPosition detecteur;
    detecteur.abs = 0;
    detecteur.ord = 0;
    while(true){ // Vérif et élim des colonnes
        atLeastThreeInAColumn(grille,detecteur,nbHM);
        if(!atLeastThreeInAColumn(grille,detecteur,nbHM)) break;
        removalInColumn(grille,detecteur,nbHM);
    }

    while(true){ // Vérif et élim des lignes
        atLeastThreeInARow(grille,detecteur,nbHM);
        if(!atLeastThreeInARow(grille,detecteur,nbHM)) break;
        removalInRow(grille,detecteur,nbHM);
    }
    

    while(nbCoup < coupMax){
        displayGrid(grille);
        cout << endl << "Saisir l'abscisse des coordonnees : " ;
        cin >> pos.abs;
        cout << endl << "Saisir l'ordonnee des coordonnees : " ;
        cin >> pos.ord;

        cout << endl << "Entrez 'Z' , 'Q' , 'S' ou 'D' pour vous deplacer respectivement "
                "vers le haut , a gauche , en bas ou a droite . " << endl;
        cout << endl << "Saisir la direction : " ;
        cin >> dir;

        makeAMove(grille,pos,dir);
        
        nbHM = 0;
        detecteur.abs = 0;
        detecteur.ord = 0;
        
        while(true){ // Vérif et élim des colonnes
            atLeastThreeInAColumn(grille,detecteur,nbHM);
            if(!atLeastThreeInAColumn(grille,detecteur,nbHM)) break;
            removalInColumn(grille,detecteur,nbHM);
        }

        while(true){ // Vérif et élim des lignes
            atLeastThreeInARow(grille,detecteur,nbHM);
            if(!atLeastThreeInARow(grille,detecteur,nbHM)) break;
            removalInRow(grille,detecteur,nbHM);
        }
        nbCoup++;
    }
    return 0;
}