void arbsuma(ArbreNari& asum) const
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
{
    asum.primer_node = copia_node_arbreNari(primer_node);
    suma_aux(asum.primer_node);

}

int suma_aux(node_arbreNari* a) const
{
    
    if (a == NULL) return 0;
    int p = a -> info;
    for (int i = 0; i < a -> seg.size(); i++) 
    {
        p += (suma_aux(a -> seg[i]));
    }
    a -> info = p; 
    return p;

}