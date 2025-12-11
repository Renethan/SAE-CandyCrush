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
    if(direction == 'Z') swap(grid[pos.ord][pos.abs], grid[pos.ord - 1][pos.abs]);
    if(direction == 'S') swap(grid[pos.ord][pos.abs], grid[pos.ord + 1][pos.abs]);
    if(direction == 'Q') swap(grid[pos.ord][pos.abs], grid[pos.ord][pos.abs - 1]);
    if(direction == 'D') swap(grid[pos.ord][pos.abs], grid[pos.ord][pos.abs + 1]);
}

bool atLeastThreeInARow (const mat & grid, maPosition & pos, unsigned & howMany){
    for(size_t i = 0; i<grid.size();i++){
        for(size_t j = 0; j<grid.size();j++){
            unsigned compte = 1;
            size_t m = j+1 ;
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
    cout << "IN COLUMN" << endl;
    for(size_t i = 0; i<grid.size();i++){
        for(size_t j = 0; j<grid.size();j++){
            unsigned compte = 1;
            size_t m = j+1 ;
            while(m < grid.size()){
                if(grid[j][i] != grid[m][i] || grid[j][i] == 0) break;  // ||grid[i][j] == 0  temp debug
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
        grid[j][pos.abs] = 0;
        j++;
    }
}

void removalInRow(mat & grid, const maPosition & pos, unsigned howMany){
    cout << "Row pos "<< pos.ord << pos.abs << endl;
    size_t i = pos.abs;
    while(i + howMany < grid.size()){
        removalInColumn(grid,maPosition{pos.ord,i},1);
        cout << "Row pos "<< pos.ord << i << endl;
        i++;
    }
}
