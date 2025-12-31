#include<iostream>
#include<stack>

using namespace std;

int main() {
    char ch;
    stack <char> parent;
    int contador = 0; 
    int aux = 1;
    cin >> ch;
    while (ch != '.') {
        
        if (ch == '(' or ch == '[') {
            parent.push(ch);
        }
        else if (!parent.empty()) {
            if ((ch == ')' and parent.top() == '(') or (ch == ']' and parent.top() == '[')) parent.pop();
            else if (contador == 0) contador = aux;
        }
        else if (contador == 0) contador = aux;
        ++aux;
        cin >> ch;
        
    }

    if (contador != 0) {
        cout << "Incorrecte" << ' ' << contador << endl;
    }
    else if (!parent.empty()) cout << "Incorrecte" << ' ' << aux - 1 << endl;
    else cout << "Correcte" << endl;
}