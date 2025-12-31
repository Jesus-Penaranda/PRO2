#include "Estudiant.hh"
#include<vector>

void redondeo (Estudiant &v) 
{
    double aux = v.consultar_nota();
    v.modificar_nota(((int)(10.*(aux+.05)))/10.);
}

void arrodonir_vector(vector<Estudiant>& v)
   /* Pre: cert */
   /* Post: els estudiants de v amb nota passen a tenir la seva nota arrodonida
            a la decima mes propera */
{
    for (int i = 0; i < int(v.size()); i++) 
    {
        
        if(v[i].te_nota()) redondeo(v[i]);
    }
}

