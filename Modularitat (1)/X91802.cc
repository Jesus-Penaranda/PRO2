#include "Estudiant.hh"
#include<vector>

 pair<int,int>  max_min_vest(const vector<Estudiant>& v)
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */

{
    double min = 11, max = -1;
    int tam = v.size();
    int pos_max = 0, pos_min = 0;
   
    for (int i = 0; i < tam; i++) 
    {   
        if (!v[i].te_nota());
        else 
        {
            if (v[i].consultar_nota() == max and (v[i].consultar_DNI() < v[pos_max].consultar_DNI())) 
            {
                pos_max = i;
            }
            else if (v[i].consultar_nota() == min and (v[i].consultar_DNI() < v[pos_min].consultar_DNI())) 
            {
                pos_min = i;
            }
            if (v[i].consultar_nota() > max) 
            {
                max = v[i].consultar_nota();
                pos_max = i;
            }
           
            else if (v[i].consultar_nota() < min) 
            {
                min = v[i].consultar_nota();
                pos_min = i;
            }
            
        }
    }
    
    pair<int,int> pos;
    
    if (max == -1 and min == 11) 
    {
        pos.first = -1;
        pos.second = -1;
    }
    else 
    {
        pos.first = pos_max;
        pos.second = pos_min;
    }
    return pos;
}
