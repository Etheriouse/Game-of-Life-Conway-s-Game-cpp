#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<vector<int>> CreateSpace(int n, int m);
void AfficheSpace(vector<vector<int>> space);
void ViewSpace(vector<vector<int>> space);
vector<vector<int>> CreateSpaceCelulle(int n, int m);
vector<vector<int>> nextSpaceCelulle(int nbLigne, int nbColonne, vector<int> checkingDeces, vector<int> checkingNaissance, vector<vector<int>> space);
void simulation();