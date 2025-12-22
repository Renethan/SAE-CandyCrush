#ifndef HEADER_H
#define HEADER_H
#include <vector>
#include "functions_grid.cpp"
#include "functions_game.cpp"

typedef std::vector <unsigned> line; // un type représentant une ligne de la grille
typedef std::vector <line> mat; // un type représentant la grille

void clearScreen ();
void couleur (const unsigned & coul);
void initGrid( mat & grid, const size_t & mat_size );
void displayLine( line & ligne );
void  displayGrid (const mat & grid);
void makeAMove (mat & grid, const maPosition & pos, const char & direction);
bool atLeastThreeInARow (const mat & grid, maPosition & pos, unsigned & howMany);
bool atLeastThreeInAColumn (const mat & grid, maPosition & pos, unsigned & howMany);
void removalInColumn(mat & grid, const maPosition & pos, unsigned howMany);
void removalInRow(mat & grid, const maPosition & pos, unsigned howMany);
void partie(const size_t & gridSize, unsigned coupMax , unsigned ptsRequis);

#endif // HEADER_H
