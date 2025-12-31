#include "Estudiant.hh"
#include<vector>
#include<iostream>

using namespace std;

vector<Estudiant> imprimir(const vector<Estudiant> &v) 
{
    int n = v.size();
    vector<Estudiant> v1;
   
    
    for (int i = 0; i < n; i++) 
    {
        int m = v1.size();
        
        if (m == 0) v1.push_back(v[i]);
        else if (v[i].consultar_DNI() == v1[m - 1].consultar_DNI()) 
        {
            if (!v1[m - 1].te_nota() or (v[i].te_nota() and v[i].consultar_nota() > v1[m - 1].consultar_nota())) v1[m - 1] = v[i];
        }
        else v1.push_back(v[i]);
    }

    return v1;
    
    
}

int main() 
{
   
    int n;
    cin >> n;
    vector<Estudiant> v(n);

    for (int i = 0; i < n; i++) 
    {
        v[i].llegir();
    }

    vector<Estudiant> v1 =  imprimir(v);
    for(int i = 0; i < v1.size(); i++) v1[i].escriure();
}