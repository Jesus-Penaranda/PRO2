#include<vector>
#include<iostream>
#include<stack>
#include<string>

using namespace std;

void opcio1(string nom, int n, vector<stack<string>>& c) {
    c[n - 1].push(nom);


}
void opcio2(int cant, int cat, vector<stack<string>> &c) {
    for(int i = 0; i < cant; ++i) c[cat - 1].pop();

    
}
void opcio3(int categ, vector<stack<string>> &c) {
    cout << "Pila de la categoria " << categ << endl;
    stack<string> temp(c[categ - 1]);
    int libros = c[categ - 1].size();
    for (int j = 0; j < libros; ++j) {
        cout << temp.top() << endl;
        temp.pop();
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    int opcion, cat, cantidad;
    string nombre;
    bool finish = false;
    vector<stack<string>> categorias(n);
    while (not finish and cin >> opcion) {
        
        if (opcion == -1) {
            cin >> nombre >> cat;
            opcio1(nombre,cat, categorias);
        }
        else if (opcion == -2) {
            cin >> cantidad >> cat;
            opcio2(cantidad, cat, categorias);
        }
        else if(opcion == -3) { 
            cin >> cat;
            opcio3(cat, categorias);
        }
        else finish = true;
    }
}