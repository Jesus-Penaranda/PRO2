#include <vector>
#include "vectorIOint.hh"
using namespace std;
 
 struct parint {int prim, seg;};
 
 parint max_min1(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
 {
    
    int max = v[0], min = v[0];
     for (int i = 0; i < v.size(); ++i) {
         if (v[i] <= min) min = v[i];
         else if (v[i] >= max) max = v[i];
     }
    parint resultado;
    resultado.prim = max;
    resultado.seg = min;
    return resultado;
    
 }
 
 pair<int,int> max_min2(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
 {
 int max = v[0], min = v[0];
     for (int i = 0; i < v.size(); ++i) {
         if (v[i] <= min) min = v[i];
         else if (v[i] >= max) max = v[i];
     }
    pair<int,int> resultado;
    resultado.first = max;
    resultado.second = min;
    return resultado;
 }
 
 void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
    x = v[0], y = v[0];
     for (int i = 0; i < v.size(); ++i) {
         if (v[i] <= y) y = v[i];
         else if (v[i] >= x) x = v[i];
     }
 }