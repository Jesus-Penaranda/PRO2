#include "searchInBST.hh"
#include <cmath>

// Pre: t és un BST
// Post: Retorna cert si i només si x apareix a t
bool searchInBST(BinTree<int> t, int x) {
    if (t.empty()) return false;
    else if (t.value() == x) return true;
    else {
        if (t.value() >= x) return searchInBST(t.left(),x);
        else return searchInBST(t.right(),x);
    }
    
}