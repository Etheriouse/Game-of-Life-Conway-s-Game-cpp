#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findCell(vector<vector<int>> t, int l);
vector<vector<int>> emplacementCelulle(vector<vector<int>> t, int y, int i);
int nbVivant(vector<vector<int>> zoom);
int nbMorte(vector<vector<int>> zoom);
void affvect(vector<int> t);