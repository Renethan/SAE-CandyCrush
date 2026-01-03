#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

typedef vector <unsigned> line; // Type représentant une ligne de la grille
typedef vector <line> mat; // Type représentant la grille , aussi utilisé pour la gestion des niveaux


int main(){
    int action = 0;
    cout << "  Bienvenue !";
    while(true){
        cout << " Veuillez selectionner votre action :\n"
            << "   1 - Jouer\n"
            << "   2 - Sauvegarder\n"
            << "   3 - Charger\n" 
            << "   4 - Guide d'aide\n"
            << "   5 - Quitter\n";
        cin >> action;
        if(action == 1) selectNiveau(); // Jouer
        if(action == 2) sauvegarde(); // Sauvegarde
        if(action == 3) charge(); // Charge
        if(action == 4) continue; // Guide
        if(action == 5) break; // Quitter
        else cout << "\n Valeur incorecte , veuillez reesayer \n";
    }
    cout << "\n SORTIE \n";
    return 0;
}