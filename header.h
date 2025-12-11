#ifndef HEADER_H
#define HEADER_H
#include <vector>
typedef std::vector <unsigned> line; // un type représentant une ligne de la grille
typedef std::vector <line> mat; // un type représentant la grille

void clearScreen ();
void couleur (const unsigned & coul);
void initGrid( mat & grid, const size_t & mat_size );
void displayLine( line & ligne );
void  displayGrid (const mat & grid);

#endif // HEADER_H
