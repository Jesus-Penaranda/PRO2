void arb_sumes(Arbre<int> &asum) const
/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
{
    asum.primer_node = copia_node_arbre(primer_node);
    aux(asum.primer_node);
}

T aux (node_arbre* a) const
{
    if (a == NULL) return 0;
    int p1 = aux(a ->segD);
    int p2 = aux(a -> segE);
    a -> info = a -> info + p1 + p2;    
    return a -> info;
}