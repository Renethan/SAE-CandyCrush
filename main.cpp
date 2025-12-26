#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

typedef vector <unsigned> line; // Type représentant une ligne de la grille
typedef vector <line> mat; // Type représentant la grille , aussi utilisé pour la gestion des niveaux

mat configNiveaux = {{7,20,10,4},{6,15,5,5},{7,20,18,3},{8,25,10,8}};


int main(){
    int level = 0; 
    while(true){
        cout << "Saisissez le numero du niveau : \n";
        cin >> level; 
        if(level < 0 || level >= configNiveaux.size()) break;
        partie(configNiveaux[level]);
    }
    cout << "\n SORTIE \n";
    return 0;
}