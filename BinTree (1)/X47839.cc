#include "maximumTree.hh"

// Pre: Rep dos arbres binaris d'enters positius t1 i t2.
// Post: Retorna un arbre, on a la seva arrel hi ha el màxim de les arrels de t1,t2,
// en l'arrel del fill esquerre hi ha el màxim de les arrels dels fills esquerre de t1,t2,
// en l'arrel del fill dret hi ha el màxim de les arrels dels fills drets de t1,t2,
// i així successivament.
// Quan un dels arbres no té valors definits en alguna posició, l'arbre resultant hi té
// el valor de l'altre arbre en aquella posició.
BinTree<int> maximumTree(BinTree<int> t1,BinTree<int> t2)
{
    if (t1.empty()) return t2;
    else if(t2.empty()) return t1;
    else
    {
        int x;
        if (t1.value() >= t2.value()) x = t1.value();
        else x = t2.value();
        return BinTree<int>(x,maximumTree(t1.left(),t2.left()),maximumTree(t1.right(),t2.right()));
    }
}