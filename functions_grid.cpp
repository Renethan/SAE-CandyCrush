#include <iostream>
#include <vector>
#include "header.h"
#include <ctime>

using namespace std;

typedef vector <unsigned> line; // un type représentant une ligne de la grille
typedef vector <line> mat; // un type représentant la grille



const unsigned KReset   (0);
const unsigned KNoir    (30);
const unsigned KRouge   (31);
const unsigned KVert    (32);
const unsigned KJaune   (33);
const unsigned KBleu    (34);
const unsigned KMagenta (35);
const unsigned KCyan    (36);
const int KNbcandies = 9;

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

            couleur(30);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 2:

            couleur(37);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 3:

            couleur(32);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 4:

            couleur(33);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 5:

            couleur(34);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 6:

            couleur(36);

           cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 7:

            couleur(30);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 8:

            couleur(37);

            cout << " " << "|"<< ligne[i] << "|" <<" ";

            break;


        case 9:

            couleur(32);

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

        cout << endl ;

    }

    couleur(KReset) ;

}
