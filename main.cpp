#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

typedef vector <unsigned> line; // Type représentant une ligne de la grille
typedef vector <line> mat; // Type représentant la grille , aussi utilisé pour la gestion des niveaux


int main(){
    while(true){
        int level = selectNiveau();
        if(level == 0) break;
        partie(configNiveaux[level-1]);
    }
    cout << "\n SORTIE \n";
    return 0;
}