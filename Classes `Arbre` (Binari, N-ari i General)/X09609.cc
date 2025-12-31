void sub_arrel(Arbre& asub, const T& x)
 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
{
    int contador = 0;
    asub.primer_node = copia_node_arbre(aux(primer_node, x, contador));
}

node_arbre* aux(node_arbre* m, const T& x, int& contador)
/* Pre: cert */
/* Post: el resultat es NULL si m es NULL;
    en cas contrari, el resultat apunta al node arrel
    d'una jerarquia de nodes que es una copia de la
    jerarquia de nodes que te el node apuntat per m com a arrel */
{
    if (m == nullptr) return nullptr;
    if (m -> info == x) return m;

    ++contador;
    int contador1 = contador;
    int contador2 = contador;


    node_arbre* punt1 = aux(m -> segE, x, contador1);
    node_arbre* punt2 = aux(m -> segD, x, contador2);

    if (punt1 == nullptr and punt2 == nullptr) return nullptr;
    if (punt1 == nullptr or punt2 == nullptr) 
    {
        if (punt1 == nullptr) return punt2;
        return punt1;
    }
    if (contador1 > contador2) return punt2;
    return punt1;
}