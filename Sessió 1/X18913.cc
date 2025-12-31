#include<iostream>
#include<vector>

using namespace std;

int busqueda_lin(const vector<int>& v, int x) {
    /* Pre: cierto */
    /* Post: si el resultado es v.size(), x no esta en v;
    en caso contrario, indica la posicion de la primera aparicion de x en v */
    bool trobat = false;
    int i = 0;
    while (not trobat and i < v.size()) {
        if (v[i] == x) trobat = true;

        else ++i;
    }
    return i;
}
