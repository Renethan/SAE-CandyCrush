#include <iostream>
#include <vector>
#include "header.h"
#include <fstream>
#include <limits>

using namespace std;

typedef vector <unsigned> line; // Type représentant une ligne de la grille
typedef vector <line> mat; // Type représentant la grille , aussi utilisé pour la gestion des niveaux

struct maPosition {
    unsigned abs;
    unsigned ord;
}; // une position dans la grille

int progression = 1;
mat configNiveaux = {{7,20,10,4,1},{6,15,10,5,2},{7,10,30,3,3},{8,25,10,8,4},{5,15,10,4,5}};

void makeAMove (mat & grid, const maPosition & pos, const char & direction){
    if(direction == 'Z' || direction == 'z') swap(grid[pos.ord][pos.abs], grid[pos.ord - 1][pos.abs]);
    if(direction == 'S' || direction == 's') swap(grid[pos.ord][pos.abs], grid[pos.ord + 1][pos.abs]);
    if(direction == 'Q' || direction == 'q') swap(grid[pos.ord][pos.abs], grid[pos.ord][pos.abs - 1]);
    if(direction == 'D' || direction == 'd') swap(grid[pos.ord][pos.abs], grid[pos.ord][pos.abs + 1]);
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

// Renvoie true si le caratère de direction est valide en fonction de la position du curseur et de la taille de la grille. Tolère les caractères minuscules et majuscules.
bool isCorrectDirection(maPosition pos, size_t taille, char dir){
    if(dir == 'Z' || dir == 'z') return pos.ord > 0;
    if(dir == 'S' || dir == 's') return pos.ord < taille;
    if(dir == 'Q' || dir == 'q') return pos.abs > 0;
    if(dir == 'D' || dir == 'd') return pos.abs < taille;
    return false;
}

//Lance une partie. Prends en paramètre un vecteur 'config' <unsigned> dont les valeurs sont : [gridSize / nbCoups / nbPoints / nbBonbons / idNiveau]
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
    
    while(nbCoup < config[1]){
        cout << "Points requis : " << config[2] << " - Coups restants : " << config[1] - nbCoup  << endl;
        displayGrid(grille);

        while(true){ // Saisie Abscisses
            cout << endl << "Saisir l'abscisse des coordonnees : " ;
            cin >> pos.abs;
            if(0 <= pos.abs && pos.abs < grille.size()) break;
            cout << "\nValeur incorrecte, reessayez\n";
        }
        while(true){ // Saisie Ordonnées
            cout << endl << "Saisir l'ordonnee des coordonnees : " ;
            cin >> pos.ord;
            if(0 <= pos.ord && pos.ord < grille.size()) break;
            cout << "\nValeur incorrecte, reessayez\n";
        }

        while(true){ // Saisie Direction
            cout << endl << "Entrez 'Z' , 'Q' , 'S' ou 'D' pour vous deplacer respectivement "
                    "vers le haut , a gauche , en bas ou a droite . " << endl;
            cout << endl << "Saisir la direction : " ;
            cin >> dir;
            if(isCorrectDirection(pos,grille.size(),dir)) break;
            cout << "\nValeur incorrecte, reessayez\n";
        }

        makeAMove(grille,pos,dir); // Déplacement
        
        nbHM = 0;
        detecteur.abs = 0;
        detecteur.ord = 0;
        

        while(true){ // Vérif et élim des colonnes et des lignes
            bool ligne = false;
            bool colonne = false;

            if(atLeastThreeInAColumn(grille,detecteur,nbHM)){ // Colonnes
                cout << "\n Combo ! \n";
                nbPts = nbPts + (nbHM - 2) ;
                removalInColumn(grille,detecteur,nbHM);
                colonne = true;
                displayGrid(grille);
                cout << "\n_ _ _ _ _ _\n";
            }

            if(atLeastThreeInARow(grille,detecteur,nbHM)){ // Lignes
                cout << "\n Combo ! \n";
                nbPts = nbPts + (nbHM - 2) ;
                removalInRow(grille,detecteur,nbHM);
                ligne = true;
                displayGrid(grille);
                cout << "\n_ _ _ _ _ _\n";
            }

            if(!ligne && !colonne) break;
        }

        nbCoup++;
        cout << "Nombre de points : " << nbPts << "/" << config[2] << endl;
    }
    if(nbPts >= config[2]){ // Vérification victoire/défaite
        if(config[4] == progression) progression++; // Vérifie si c'est le dernier niveau disponible -> monte la progression
        cout << "Victoire ! Avec " << nbPts << " points." << endl;
    }
    else cout << "Défaite ! Avec " << nbPts << " points sur " << config[2] << endl;
}


// Permet de sélectionner et éxécuter un niveau parmis la liste des niveaux disponible. Cette liste dépends de la progression
void selectNiveau(){
    string reponse = "";
    while(true){
        cout << "\nLes niveaux en vert sont les niveaux finis, en bleu les niveaux debloque et en blanc a debloquer plus tard \n";
        
        int i = 1; // Affichage
        couleur(KVert);
        for(i; i<progression && i<configNiveaux.size(); i++) cout << i << ' '; // Niveaux terminés

        couleur(KBleu);
        cout << i << ' '; //Niveau disponible
        i++;

        couleur(KReset);
        for(i; i<=configNiveaux.size(); i++) cout << i << ' '; // Niveaux non-débloqués

        cout << "\nSaisissez niveau que vous souhaitez jouer. \nEntrez 'exit' pour sortir. \n";
        
        cin >> reponse; // Sélection
        
        if(reponse == "exit") break; // Cas de sortie
        if(1 <= stoi(reponse) && stoi(reponse) <= progression && stoi(reponse) <= configNiveaux.size()) partie(configNiveaux[stoi(reponse)-1]); // Lancement d'un niveau
        else cout << "\n Valeur incorrecte. \n"; // Autre valeur incorecte
    }
}


// Enregistre la progression dans un fichier texte dont le nom est précisé au clavier par l'utilisateur
void sauvegarde(){
    string nom;
    while(true){
        cout << "\n Selectionnez le nom de la sauvegarde:  (n'entrez rien pour annuler) \n";

        cin.clear(); // Vidage du buffer pour le getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,nom);
        if(nom.empty()) break; // Annulation

        ifstream ifs("saves/"+nom+".txt");
        if(ifs.is_open()){ // Si le fichier existe , on propose de le remplacer
            char rep;
            cout << "Le fichier existe deja, le remplacer ? [O/N] \n";
            cin >> rep;

            if(rep == 'o' || rep == 'O'){ // Oui -> On réécrit par dessus
                ifs.close();
                ofstream ofs("saves/"+nom+".txt");
                ofs << progression;
                ofs.close();
                cout << "Progression sauvegardee dans le fichier " << nom << ".txt \n";
                break;

            } else if(rep == 'n' || rep == 'N'){ // Non -> On annule
                ifs.close();
                break;

            } else cout << "\nValeur incorecte\n"; // Autre caractère entré -> on propose de réésayer

        } else { // Sinon , on enregistre
            ifs.close();
            ofstream ofs("saves/"+nom+".txt");
            ofs << progression;
            ofs.close();
            cout << "Progression sauvegardee dans le fichier " << nom << ".txt \n";
            break;
        }
    }
}

// Charge la progression depuis un fichier texte dont le nom est précisé au clavier par l'utilisateur
void charge(){
    string nom;
    while(true){
        cout << "\n Selectionnez le nom de la sauvegarde:  (n'entrez rien pour annuler) \n";
        
        cin.clear(); // Vidage du buffer pour le getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,nom);
        if(nom.empty()) break;

        ifstream ifs("saves/"+nom+".txt");
        if(ifs.is_open()){ // Si le fichier existe , on le charge
            string p;
            getline(ifs,p);
            progression = stoi(p);
            ifs.close();
            cout << "La sauvegarde " << nom << ".txt a ete chargee avec succes !\n";
            break;

        } else { // Sinon, on propose de réésayer
            ifs.close();
            cout << "La sauvegarde n'existe pas , veuillez reesayer\n";
        }
    }
}