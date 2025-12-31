#include <iostream>
using namespace std;

void print_asterisks(int n, int current = 0) {

    if (current == n) return; 
    cout << "*"; 
    print_asterisks(n, current + 1); 
}

void barres(int n) {
    if (n == 1) cout << "*" << endl; 
    else {
        print_asterisks(n); 
        cout << endl;
        barres(n - 1); 
        barres(n - 1); 
    }
}

int main() {
    int n;
    cin >> n;
    barres(n);
}
