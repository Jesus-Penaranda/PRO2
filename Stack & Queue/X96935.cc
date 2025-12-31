#include<iostream>
#include<stack>

using namespace std;

int main() {
    stack<int> pila1;

    bool pal = true;
    int n;

    cin >> n;

    int num;

    for (int i = 0; i < n/2; ++i) {
        cin >> num;
        pila1.push(num);
    }
    if (n%2 != 0) {
        cin >> num;
        n = (n - n/2 )- 1;
    }
    else n = n - n/2;
    for(int j = 0; j < n; ++j) {
        cin >> num;
        if (pila1.top() != num) pal = false;
        pila1.pop();
    } 
   
    if (pal) cout << "SI" << endl;
    else cout << "NO" << endl;
}
