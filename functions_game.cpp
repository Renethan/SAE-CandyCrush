#include <iostream>
#include <vector>

using namespace std;

typedef vector <unsigned> line; // un type représentant une ligne de la grille
typedef vector <line> mat; // un type représentant la grille
struct maPosition {
    unsigned abs;
    unsigned ord;
};

// une position dans la girlle

void makeAMove (mat & grid, const maPosition & pos, const char & direction){
    if(direction == 'Z') swap(grid[pos.abs][pos.ord], grid[pos.abs][pos.ord - 1]);
    if(direction == 'S') swap(grid[pos.abs][pos.ord], grid[pos.abs][pos.ord + 1]);
    if(direction == 'Q') swap(grid[pos.abs][pos.ord], grid[pos.abs - 1][pos.ord]);
    if(direction == 'D') swap(grid[pos.abs][pos.ord], grid[pos.abs + 1][pos.ord]);
}

bool atLeastThreeInARow (const mat & grid, maPosition & pos, unsigned & howMany){
    for(size_t i = 0; i<grid.size();i++){
        for(size_t j = 0; j<grid.size();j++){
            unsigned compte = 1;
            size_t m = j+1 ;
            while(m < grid.size()){
                if(grid[i][m] != grid[i][j]) break;
                compte++;
                m++;
            }
            if(compte >= 3){
                pos.abs = j;
                pos.ord = i;
                howMany = compte;
                return true;
            }
        }
    }
    return false;
}

bool atLeastThreeInAColumn (const mat & grid, maPosition & pos, unsigned & howMany){
    for(size_t j = 0; j<grid.size();j++){
        for(size_t i = 0; i<grid.size();i++){
            unsigned compte = 1;
            size_t m = i+1 ;
            while(m < grid.size()){
                if(grid[m][j] != grid[i][j]) break;
                compte++;
                m++;
            }
            if(compte >= 3){
                pos.abs = j;
                pos.ord = i;
                howMany = compte;
                return true;
            }
        }
    }
    return false;
}
void removalInColumn(mat & grid, const maPosition & pos, unsigned howMany){
    size_t i = pos.abs;
    while(i + howMany < grid.size()){
        grid[i][pos.ord] = grid[i+howMany][pos.ord];
        i++;
    }
    while(i < grid.size()){
        grid[i][pos.ord] = 0;
        i++;
    }
}

void removalInRow(mat & grid, const maPosition & pos, unsigned howMany){
    size_t i = pos.ord;
    while(i < pos.ord + howMany){
        removalInColumn(grid,maPosition{pos.abs,i},1);
        i++;
    }
}
