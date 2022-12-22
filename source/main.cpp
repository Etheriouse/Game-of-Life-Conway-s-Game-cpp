#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../headers/space.hpp"
#include "../headers/coo.hpp"
#include "../headers/other.hpp"
#include "../headers/check.hpp"

int main() {
    /*vector<vector<int>> space = CreateSpaceCelulle(10,10);
    ViewSpace(space);
    AfficheSpace(space);
    vector<vector<int>> rayon = emplacementCelulle(space, 1, 1);
    AfficheSpace(rayon);
    cout << nbMorte(rayon) << endl;
    */
    simulation();
    return 0;
}