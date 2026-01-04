#include <iostream>
#include <vector>
#include "header.h"
#include <ctime>

using namespace std;

typedef vector <unsigned> line; // Type représentant une ligne de la grille
typedef vector <line> mat; // Type représentant la grille , aussi utilisé pour la gestion des niveaux



const unsigned KReset   (0);
const unsigned KNoir    (30);
const unsigned KRouge   (31);
const unsigned KVert    (32);
const unsigned KJaune   (33);
const unsigned KBleu    (34);
const unsigned KMagenta (35);
const unsigned KCyan    (36);
int KNbcandies = 9;

void clearScreen () {
    cout << "\033[H\033[2J";
}


void couleur (const unsigned & coul) {
    cout << "\033[" << coul <<"m";
}

//fonction qui permet de generer la grille

void initGrid( mat & grid, const size_t & mat_size ){

    srand(time(0));
    grid.resize(mat_size,line(mat_size,0)); //generation de la grille


    for(line & ligne : grid){

        for (size_t i = 0; i < mat_size; ++i) {

            int randNb = rand() % KNbcandies + 1;
            ligne[i] = randNb ;

        }

    }
}


//fonction qui permet l'affichage d'une ligne de la grille

void displayLine( line & ligne ){

    for (size_t i = 0; i < ligne.size(); ++i) {

        switch (ligne[i]) {

        //affiche un espace si un 0 est présent
        case 0:

            couleur(KReset);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;

        //change la couleur de l'écriture selon le chiffre

        case 1:

            couleur(KCyan);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 2:

            couleur(KRouge);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 3:

            couleur(KVert);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 4:

            couleur(KJaune);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 5:

            couleur(KBleu);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 6:

            couleur(KMagenta);

           cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 7:

            couleur(KReset);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 8:

            couleur(KCyan);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 9:

            couleur(KRouge);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        }

    }

}

//fonction qui permet l'affichage de la grille

void  displayGrid (const mat & grid){

    clearScreen() ;

    couleur(KReset) ;

    for (line ligne : grid) {

        displayLine(ligne) ;

        cout << '\n' ;

    }

    couleur(KReset) ;

}
