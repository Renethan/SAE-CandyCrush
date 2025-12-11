#include <iostream>
#include <vector>
#include <header.h>

using namespace std;

typedef vector <unsigned> line; // un type représentant une ligne de la grille
typedef vector <line> mat; // un type représentant la grille

struct maPosition {
    unsigned abs;
    unsigned ord;
}; // une position dans la girlle

//void makeAMove (mat & grid, const maPosition & pos, const char & direction)
