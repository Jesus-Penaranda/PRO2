#include "Estudiant.hh"
#include<vector>
#include<algorithm>

using namespace std;

bool comp (const Estudiant &a, const Estudiant &b) 
{
    if (a.consultar_nota() == b.consultar_nota()) return a.consultar_DNI() < b.consultar_DNI();
    else return a.consultar_nota() > b.consultar_nota();
}

int main() 
{
    int M;
    cin >> M;
    vector<Estudiant> v(M);

    int N, S;
    cin >> N >> S;

    int dni;

    vector<int> asig(S);

    for (int i = 0; i < S; i++) 
    {
        int as;
        cin >> as;
        asig[i] = as;
    }

    for(int i = 0; i < M; i++)
    {
        double suma = 0;
        cin >> dni;
        v[i] = Estudiant(dni);

            vector<double> notes(N);

            for (int j = 0; j < N; j++) 
            {
                double notas;
                cin >> notas;
                notes[j] = notas;
            }
        
            for (int h = 0; h < asig.size(); h++) 
            {
                suma += notes[asig[h] - 1];
            }

        v[i].afegir_nota(suma / double(asig.size()));
    }
    sort(v.begin(),v.end(),comp);
    for (int i = 0; i < v.size(); i++) v[i].escriure();
}