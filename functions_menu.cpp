#include <iostream>
#include "header.h"
#include <fstream>
#include <limits>

// Permet de creer son propre niveau (changer les paramètres)
void niveauPerso(){
    string taille, nbCoups, nbPts, nbBonbons;
    while(true){ // Taille
        cout << "\nSelectionnez la taille de la grille :  [3 - 20]\n";
        cin >> taille;
        if(isInteger(taille) && stoi(taille) >= 3 && stoi(taille) <= 20) break;
        cout << "\nValeur incorrecte, reessayez\n";
    }
    while(true){ // Coups max
        cout << "\nSelectionnez le nombre de coups maximal :  [1 - 1000]\n";
        cin >> nbCoups;
        if(isInteger(nbCoups) && stoi(nbCoups) >= 1 && stoi(nbCoups) <= 1000) break;
        cout << "\nValeur incorrecte, reessayez\n";
    }
    while(true){ // Points requis
        cout << "\nSelectionnez le nombre de points requis :  [0 - 100000]\n";
        cin >> nbPts;
        if(isInteger(nbPts) && stoi(nbPts) >= 0 && stoi(nbPts) <= 100000) break;
        cout << "\nValeur incorrecte, reessayez\n";
    }
    while(true){ // Bonbons
        cout << "\nSelectionnez le nombre de bonbons differents :  [2 - 9]\n";
        cin >> nbBonbons;
        if(isInteger(nbBonbons) && stoi(nbBonbons) >= 2 && stoi(nbBonbons) <= 9) break;
        cout << "\nValeur incorrecte, reessayez\n";
    }
    line config = {stoul(taille),stoul(nbCoups),stoul(nbPts),stoul(nbBonbons),0};
    cout << "\nLancement de la partie personnalisee\n";
    partie(config);
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

        cout << "\nSaisissez niveau que vous souhaitez jouer.\nEntrez '0' pour lancer une partie personalisee. \nEntrez 'exit' pour sortir. \n";
        
        cin >> reponse; // Sélection
        
        if(reponse == "exit") break; // Cas de sortie
        else if(isInteger(reponse) && stoi(reponse) == 0) niveauPerso(); // Lancement niveau personalisé
        else if(isInteger(reponse) && 1 <= stoi(reponse) && stoi(reponse) <= progression && stoi(reponse) <= configNiveaux.size()) partie(configNiveaux[stoi(reponse)-1]); // Lancement d'un niveau
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

// Affiche le guide
void guide(){
    ifstream ifs("guide.txt");
    if(ifs.is_open()){
        couleur(KVert);
        string ligne;
        while(!ifs.eof()){
            getline(ifs,ligne);
            cout << ligne << '\n' ;
        }
        couleur(KReset);
    } else cout << "\nErreur de chargement du guide\n";
    ifs.close();
}