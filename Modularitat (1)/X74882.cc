#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
#include <vector>

#include<iostream>

using namespace std;

int main() 
{
    Cjt_estudiants a,b;

    a.llegir();
    b.llegir();

    for(int i = 0; i < a.mida(); i++) 
    {
        Estudiant a1 = a.consultar_iessim(i + 1);
        Estudiant a2 = b.consultar_iessim(i + 1);

        if (a1.te_nota() and a2.te_nota())
        {
            if (a1.consultar_nota() > a2.consultar_nota()) a.modificar_iessim(i + 1, a1);
            else a.modificar_iessim(i + 1, a2);
        }
        else if (!a1.te_nota() and a2.te_nota()) a.modificar_iessim(i + 1, a2);
        else a.modificar_iessim(i + 1, a1);
    }
    a.escriure();
}