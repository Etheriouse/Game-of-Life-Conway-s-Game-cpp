#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../headers/space.hpp"

int findCell(vector<vector<int>> t, int l)
{
    int count(0);

    for (int i(0); i < t.size(); i += 1)
    {
        for (int y(0); y < t[i].size(); y += 1)
        {
            if (t[i][y] == l)
            {
                count += 1;
            }
        }
    }
    return count;
}

int nbVivant(vector<vector<int>> zoom)
{
    int cel(-1);
    for (int i = 0; i < zoom.size(); i += 1)
    {
        for (int y = 0; y < zoom[i].size(); y += 1)
        {
            // System.out.println(y);
            if (zoom[i][y] == 0)
            {
                cel += 1;
            }
        }
    }
    return cel;
}

int nbMorte(vector<vector<int>> zoom)
{
    int cel(0);
    for (int i = 0; i < zoom.size(); i += 1)
    {
        for (int y = 0; y < zoom[i].size(); y += 1)
        {
            // System.out.println(y);
            if (zoom[i][y] == 0)
            {
                cel += 1;
            }
        }
    }
    return cel;
}

vector<vector<int>> emplacementCelulle(vector<vector<int>> t, int y, int i)
{
    vector<vector<int>> zoom = CreateSpace(3, 3);
    int alpha(0);
    int beta(0);
    for (int a(i - 1); a <= i + 1; a += 1)
    {
        for (int b(y - 1); b <= y + 1; b += 1)
        {
            if (b < 0 || a < 0 || b > t[0].size()-1 || a > t.size()-1)
            {
                zoom[alpha][beta] = 2;
            }
            else
            {
                zoom[alpha][beta] = t[a][b];
            }
            beta += 1;
        }
        beta = 0;
        alpha += 1;
    }
    return zoom;
}

void affvect(vector<int> t) {
    for(int i(0); i<t.size(); i+=1) {
        cout << t[i] << " ";
    }
    cout << "" << endl;
}