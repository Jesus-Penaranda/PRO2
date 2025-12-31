// Input: Una línea con dos enteros n > 0 y x. A continuación, n secuencias de
// enteros separadas por saltos de linea. Todas las secuencias contienen el valor x.
// Output: Para cada secuencia, la suma de todos los elementos que preceden a
// la primera aparición de x.

#include<iostream>
using namespace std;

int main() {

    int n,x;
    cin >> n >> x;

    for(int i = 1; i <= n; ++i) {
        int sum = 0;
        int num;
        string s;
        bool trobat = false;
        while(not trobat and cin >> num) {
            if (num == x) {
                getline(cin,s);
                trobat = true;
            }
            else sum += num;
        }
        cout << "La suma de la secuencia " << i << " es " << sum << endl;
    }
}
