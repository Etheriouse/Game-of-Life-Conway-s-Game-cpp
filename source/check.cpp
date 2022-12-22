#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../headers/other.hpp"

vector<int> chekingNaissance(vector<vector<int>> space) {
    vector<int> numbCel (findCell(space, -1), 0);
    int k(0);
    for(int i(0); i<space.size(); i+=1) {
        for(int y(0); y<space[i].size(); y+=1) {
            if(space[i][y] == -1 && k<numbCel.size()) {
                vector<vector<int>> rayon = emplacementCelulle(space, y, i);
                numbCel[k] = nbMorte(rayon);
                k+=1;
            }
        }
    }
    return numbCel;
}

vector<int> checkingDeces(vector<vector<int>> space) {
    vector<int> numbCel (findCell(space, 0), 0);
    int k(0);
    for(int i(0); i<space.size(); i+=1) {
        for(int y(0); y<space[i].size(); y+=1) {
            if(space[i][y] == 0 && k<numbCel.size()) {
                vector<vector<int>> rayon = emplacementCelulle(space, y, i);
                numbCel[k] = nbVivant(rayon);
                k+=1;
            }
        }
    }
    return numbCel;
}