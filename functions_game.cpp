#include <iostream>
#include <vector>
#include "header.h"


using namespace std;

typedef vector <unsigned> line; // Type représentant une ligne de la grille
typedef vector <line> mat; // Type représentant la grille , aussi utilisé pour la gestion des niveaux

struct maPosition {
    unsigned abs;
    unsigned ord;
};

// une position dans la girlle

void makeAMove (mat & grid, const maPosition & pos, const char & direction){
    if(direction == 'Z') swap(grid[pos.ord][pos.abs], grid[pos.ord - 1][pos.abs]);
    if(direction == 'S') swap(grid[pos.ord][pos.abs], grid[pos.ord + 1][pos.abs]);
    if(direction == 'Q') swap(grid[pos.ord][pos.abs], grid[pos.ord][pos.abs - 1]);
    if(direction == 'D') swap(grid[pos.ord][pos.abs], grid[pos.ord][pos.abs + 1]);
}

bool atLeastThreeInARow (const mat & grid, maPosition & pos, unsigned & howMany){
    for(size_t j = 0; j<grid.size();j++){
        for(size_t i = 0; i<grid.size();i++){
            unsigned compte = 1;
            size_t m = i+1 ;
            while(m < grid.size()){
                if(grid[j][m] != grid[j][i]) break;
                compte++;
                m++;
            }
            if(compte >= 3){
                pos.abs = i;
                pos.ord = j;
                howMany = compte;
                return true;
            }
        }
    }
    return false;
}

bool atLeastThreeInAColumn (const mat & grid, maPosition & pos, unsigned & howMany){
    for(size_t i = 0; i<grid.size();i++){
        for(size_t j = 0; j<grid.size();j++){
            unsigned compte = 1;
            size_t m = j+1 ;
            while(m < grid.size()){
                if(grid[j][i] != grid[m][i]) break;
                compte++;
                m++;
            }
            if(compte >= 3){
                pos.ord = j;
                pos.abs = i;
                howMany = compte;
                return true;
            }
        }
    }
    return false;
}

void removalInColumn(mat & grid, const maPosition & pos, unsigned howMany){
    size_t j = pos.ord;
    while(j + howMany < grid.size()){
        grid[j][pos.abs] = grid[j+howMany][pos.abs];
        j++;
    }
    while(j < grid.size()){
        grid[j][pos.abs] = rand() % KNbcandies +1;
        j++;
    }
}

void removalInRow(mat & grid, const maPosition & pos, unsigned howMany){
    size_t i = pos.abs;
    while(i < pos.abs + howMany){
        removalInColumn(grid,maPosition{i,pos.ord},1);
        i++;
    }
}

//Lance une partie. Prends en paramètre un vecteur 'config' <unsigned> dont les valeurs sont : [gridSize / nbCoups / nbPoints / nbBonbons]
void partie(vector<unsigned> config ){
    KNbcandies = config[3];
    mat grille;
    initGrid(grille,config[0]);

    unsigned nbCoup = 0;
    unsigned nbPts = 0;
    maPosition pos;
    char dir;

    unsigned nbHM = 0;
    maPosition detecteur;
    detecteur.abs = 0;
    detecteur.ord = 0;

    while(true){ // Vérif et élim des colonnes et des lignes
        bool ligne = false;
        bool colonne = false;

        if(atLeastThreeInAColumn(grille,detecteur,nbHM)){
            removalInColumn(grille,detecteur,nbHM);
            colonne = true;
        }

        if(atLeastThreeInARow(grille,detecteur,nbHM)){
            removalInRow(grille,detecteur,nbHM);
            ligne = true;
        }

        if(!ligne && !colonne) break;
    }
    
    cout << "Points requis : " << config[2] << endl;
    while(nbCoup < config[1]){
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
        

        while(true){ // Vérif et élim des colonnes et des lignes
        bool ligne = false;
        bool colonne = false;

        if(atLeastThreeInAColumn(grille,detecteur,nbHM)){
            if(nbHM >= 3) nbPts = nbPts + (nbHM - 2) ;
            removalInColumn(grille,detecteur,nbHM);
            colonne = true;
        }

        if(atLeastThreeInARow(grille,detecteur,nbHM)){
            if(nbHM >= 3) nbPts = nbPts + (nbHM - 2) ;
            removalInRow(grille,detecteur,nbHM);
            ligne = true;
        }

        if(!ligne && !colonne) break;
        }

        nbCoup++;
        cout << "Nombre de points : " << nbPts << "/" << config[2] << " - Coups restants : " << config[1] - nbCoup  << endl;
    }
    if(nbPts >= config[2]) cout << "Victoire ! Avec " << nbPts << " points." << endl;
    else cout << "Défaite ! Avec " << nbPts << " points sur " << config[2] << endl;
}
