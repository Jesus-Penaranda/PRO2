T max_suma_cami() const
/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
{
    return aux(primer_node);
}

T aux(node_arbre* a) const  
{
    if (a == NULL) return 0;
    return a -> info + max(aux(a->segD), aux(a -> segE));
}