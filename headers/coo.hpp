#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool estPresente(vector<vector<int>> space, int a, int b);
vector<vector<int>> init(vector<vector<int>> space);
vector<vector<int>> assignate(int nbLigne, int nbColonne, int nbCelulle, int type);