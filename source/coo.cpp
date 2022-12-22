#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

#include "../headers/space.hpp"

bool random = true;

vector<vector<int>> init(vector<vector<int>> space)
{
    for (int i(0); i < space.size(); i += 1)
    {
        for (int y(0); y < space[i].size(); y += 1)
        {
            space[i][y] = -1;
        }
    }
    return space;
}

bool estPresente(vector<vector<int>> space, int a, int b)
{
    for (int i(0); i < space.size(); i += 1)
    {
        if (space[i][0] == a && space[i][1] == b)
        {
            return false;
        }
    }
    return true;
}

vector<vector<int>> assignate(int nbLigne, int nbColonne, int nbCelulle, int type)
{
    vector<vector<int>> coo;
    srand(time(0));
    if ((nbLigne * nbColonne < nbCelulle) && type == 1)
    {
        cout << "Error, out of Celulle :(" << endl;
        exit(0);
    }

    switch (type)
    {
    case 1 /*random*/:
        if(nbCelulle < 0) {
            cout << "do not set -1 cells" << endl;
            exit(1);
        }
        coo = CreateSpace(nbCelulle, 2);
        for (int i(0); i < nbCelulle; i += 1)
        {
            bool coo_valide = false;
            while (!coo_valide)
            {
                int x(rand() % nbColonne);
                int y(rand() % nbLigne);
                if (estPresente(coo, x, y))
                {
                    //(rand() % (ub - lb + 1)) + lb generation random de ub a lb // rand() % N generation de 0 a N
                    coo_valide = true;
                    coo[i][0] = x;
                    coo[i][1] = y;
                }
            }
        }
        break;

    case 2 /*check regle*/:
        coo = CreateSpace(7, 2);
        coo[0][0] = 2;
        coo[0][1] = 0;

        coo[1][0] = 2;
        coo[1][1] = 1;

        coo[2][0] = 2;
        coo[2][1] = 2;

        coo[3][0] = 4;
        coo[3][1] = 5;

        coo[4][0] = 4;
        coo[4][1] = 6;

        coo[5][0] = 5;
        coo[5][1] = 5;

        coo[6][0] = 5;
        coo[6][1] = 6;
        break;

    case 3:
        coo = CreateSpace(5, 2);
        coo[0][0] = nbColonne/2;
        coo[0][1] = (nbLigne/2)-1;

        coo[1][0] = nbColonne/2;
        coo[1][1] = (nbLigne/2);

        coo[2][0] = nbColonne/2;
        coo[2][1] = (nbLigne/2)+1;

        coo[3][0] = (nbColonne/2)+1;
        coo[3][1] = (nbLigne/2)-1;

        coo[4][0] = (nbColonne/2)-1;
        coo[4][1] = (nbLigne/2);

        break;
    default:
        cout << "number invalide" << endl;
        exit(1);
    }
    return coo;
}