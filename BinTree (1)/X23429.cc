#include "sumOfTree.hh"


// Pre:
// Post: Retorna la suma dels valors de t
int sumOfTree(BinTree<int> t) {
    int x;
    if (t.empty()) return x = 0;
    else {
        return x = t.value() + sumOfTree(t.right()) + sumOfTree(t.left());
    }
}

