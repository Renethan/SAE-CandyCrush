#ifndef HEADER_H
#define HEADER_H
#include <vector>
#include "functions_grid.cpp"
#include "functions_game.cpp"
#include "functions_menu.cpp"

typedef vector <unsigned> line; // Type représentant une ligne de la grille
typedef vector <line> mat; // Type représentant la grille , aussi utilisé pour la gestion des niveaux

void clearScreen ();
void couleur (const unsigned & coul);
void initGrid( mat & grid, const size_t & mat_size );
void displayLine( line & ligne );
void displayGrid (const mat & grid);
bool isInteger(string chaine);
void makeAMove (mat & grid, const maPosition & pos, const char & direction);
bool atLeastThreeInARow (const mat & grid, maPosition & pos, unsigned & howMany);
bool atLeastThreeInAColumn (const mat & grid, maPosition & pos, unsigned & howMany);
void removalInColumn(mat & grid, const maPosition & pos, unsigned howMany);
void removalInRow(mat & grid, const maPosition & pos, unsigned howMany);
bool isCorrectDirection(maPosition pos, size_t taille, char dir);
void partie(const size_t & gridSize, unsigned coupMax , unsigned ptsRequis);
void selectNiveau();
void sauvegarde();
void charge();
void guide();
void niveauPerso();

#endif // HEADER_H
