int freq(const T& x) const
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
{
    return freq_aux(x, primer_node);
}
int freq_aux(const T& x, node_arbre* a) const 
{
    if (a == NULL) return 0;
    if (a -> info == x) return 1 + freq_aux(x, a -> segD) + freq_aux(x, a-> segE);
    return 0 + freq_aux(x, a -> segD) + freq_aux(x, a-> segE);
}