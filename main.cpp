#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

typedef vector <unsigned> line; // Type représentant une ligne de la grille
typedef vector <line> mat; // Type représentant la grille , aussi utilisé pour la gestion des niveaux


int main(){
    string action;
    cout << "  Bienvenue !";
    while(true){
        cout << " \nVeuillez selectionner votre action :\n"
            << "   1 - Jouer\n"
            << "   2 - Sauvegarder\n"
            << "   3 - Charger\n" 
            << "   4 - Guide d'aide\n"
            << "   5 - Quitter\n";
        cin >> action;
        if(isInteger(action)){
            if(stoi(action) == 1) selectNiveau(); // Jouer
            else if(stoi(action) == 2) sauvegarde(); // Sauvegarde
            else if(stoi(action) == 3) charge(); // Charge
            else if(stoi(action) == 4) guide(); // Guide
            else if(stoi(action) == 5) break; // Quitter
            else cout << "\nValeur incorrecte, veuillez reesayer \n";
        }else cout << "\nVous devez entrer le numero de l'action, veuillez reesayer \n";
    }
    cout << "\nAu revoir !\n";
    return 0;
}