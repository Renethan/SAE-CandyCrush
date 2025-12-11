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

const unsigned KReset   (0);
const unsigned KNoir    (30);
const unsigned KRouge   (31);
const unsigned KVert    (32);
const unsigned KJaune   (33);
const unsigned KBleu    (34);
const unsigned KMagenta (35);
const unsigned KCyan    (36);
const int KNbcandies = 9;



int main()
{
    mat grille ;

    initGrid(grille, 4) ;

    displayGrid(grille) ;

    return 0 ;
}
