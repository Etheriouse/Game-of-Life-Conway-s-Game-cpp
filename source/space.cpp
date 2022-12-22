#include <iostream>
#include <string>
#include <vector> 
#include <stdlib.h>   
#include <chrono>
#include <thread>

#include "../headers/coo.hpp"
#include "../headers/check.hpp"
#include "../headers/other.hpp"

using namespace this_thread;
using namespace std;

int NumberOfCelulle = 7;

void ViewSpace(vector<vector<int>> space);

vector<vector<int>> CreateSpace(int n, int m) {
    vector<vector<int>> space;
    for(int i(0); i<n; i+=1) {
        space.push_back(vector<int>(m, -1));
    }
    return space;
}

vector<vector<int>> CreateSpaceCelulle(int n, int m) {
    vector<vector<int>> SpaceCelulle = CreateSpace(n, m);
    int type(-1);
    cout << "choice the type of simulation:\n1) random\n2)check the rules\n3) five set" << endl;
    cin >> type;
    cin.ignore();

    cout << "choice the number of cells, if the previous choice is not 1 the number of cells is not used" << endl;
    cin >> NumberOfCelulle;
    cin.ignore();

    vector<vector<int>> coo = assignate(n, m, NumberOfCelulle, type);
    for(int i(0); i<coo.size(); i+=1) {
        SpaceCelulle[coo[i][1]][coo[i][0]] = 0;
    }
    return SpaceCelulle;
}

vector<vector<int>> nextSpaceCelulle(int nbLigne, int nbColonne, vector<int> checkingDeces, vector<int> checkingNaissance, vector<vector<int>> space) {
    int count(0);
    int countN(0);
    for(int i(0); i<space.size(); i+=1) {

        for(int y(0); y<space[i].size(); y+=1) {
            if(space[i][y] == 0) {
                if(checkingDeces[count]<2) {
                    space[i][y] = -1;
                }
                if(checkingDeces[count]>3) {
                    space[i][y] = -1;
                }
                
                if(checkingDeces[count] == 2 || checkingDeces[count] == 3) {
                    space[i][y] = 0;
                }
                count+=1;

            } else {
                if(checkingNaissance[countN] == 3) {
                    space[i][y] = 0;
                } else {
                    space[i][y] = -1;
                }
                countN+=1;
            }
        }
    }
    //affvect(checkingDeces);
    //affvect(checkingNaissance);
    printf("Nombre de celulle vivante: %d\n", count);

    return space;
}

void simulation() {
    int nombreItteration(-1);
    int tps(-1);
    int borderlen(-1);
    cout << "choice the number of itteration" << endl;
    cin >> nombreItteration;
    cin.ignore();

    cout << "choice the latence without two generation (ms)" << endl;
    cin >> tps;
    cin.ignore();

    cout << "choice the length of border" << endl;
    cin >> borderlen;
    cin.ignore();

    if(tps < 0 || NumberOfCelulle < 0 || borderlen < 5) {
        cout << "invalide tps or numberItteration or border" << endl;
        exit(1);
    }
    vector<vector<int>> t = CreateSpaceCelulle(borderlen, borderlen);
    ViewSpace(t);
    for(int i(0); i<nombreItteration; i+=1) {
        vector<int> Deces = checkingDeces(t);
        vector<int> Naissance = chekingNaissance(t);
        t = nextSpaceCelulle(borderlen, borderlen, Deces, Naissance, t);
        sleep_for(chrono::milliseconds(tps));
        system("cls");
        ViewSpace(t);
        cout << "round " << i << endl;
    }
}

void ViewSpace(vector<vector<int>> space) {
    for(int i(0); i<space.size()+2; i+=1) {
        cout << "% ";
    }
    cout << "" << endl;
    for(int i(0); i<space.size(); i+=1) {
        cout << "% ";
        for(int y(0); y<space[i].size(); y+=1) {
            if(space[i][y] != -1) {
                cout << "@ ";
            } else {
                cout << "  ";
            }
        }
        cout << "% " << endl;
    }
    for(int i(0); i<space.size()+2; i+=1) {
        cout << "% ";
    }
    cout << "" << endl;
}

void AfficheSpace(vector<vector<int>> space) {
    for(int i(0); i<space.size(); i+=1) {
        for(int y(0); y<space[i].size(); y+=1) {
            cout << space[i][y] << " ";
        }
        cout << "" << endl;
    }
}