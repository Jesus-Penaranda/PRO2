#include "reverseTree.hh"

// Pre:  
// Post: retorna el revessat de t.
BinTree<int> reverseTree(BinTree<int> t) {
   
    if (t.empty()) return t;
    else  {
        BinTree<int> reverse(t.value(), reverseTree(t.right()), reverseTree(t.left()));
        return reverse;
        
    }
}