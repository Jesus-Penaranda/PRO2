bool buscar(const T& x) const
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
{
    return buscar_aux(primer_node, x);
}

bool buscar_aux(node_arbreGen* a, const T& x) const 
{
    if(a == NULL) return false;
    if (a -> info == x) return true;
    int size = a -> seg.size();
    for (int i = 0; i < size; i++) 
    {
        if(buscar_aux(a -> seg[i], x)) return true;
    }
    return false;
    
}