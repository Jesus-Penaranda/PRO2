#include "BinTree.hh"
#include "ParInt.hh"

/*Pre: a = A */
/*Post: a es com a A amb k sumat al segon component de cada node */
void sumak(BinTree<ParInt>& a, int k)
{
    if (!a.empty()) 
    {
        ParInt arrel(a.value().primer(), a.value().segon() + k);
        BinTree<ParInt> iz, de;
            if(!a.left().empty())
            {
                iz = a.left();
                sumak(iz, k);
            }
            if(!a.right().empty())
            {
                de = a.right();
                sumak(de, k);
            }
        BinTree<ParInt> A(arrel, iz, de);
        a = A;
    }
    
}
 