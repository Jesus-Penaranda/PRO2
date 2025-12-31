#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int main() {
    stack <int> cadena;
    string parent;

    while (cin >> parent) {
        int i = 0;
        int contador = 1;
            while (i < parent.length()) {
                if (parent[i] == '(') {
                    cout << parent[i] << contador;
                    cadena.push(contador);
                    ++contador;
                }
                else if (parent[i] == ')') {
                    cout << parent[i] << cadena.top();
                    cadena.pop();

                }
                
                ++i;
        }
        cout << endl;
     
    }
} 