#include<iostream>
#include<vector>
#include<string>

using namespace std;

int op () {
    char num;
    char operacio1, operacio2;
    int x = 0,y = 0;
    cin >> num;
    if (num == '(') x = op();
    else if (num >= '0' and num <= '9') x = num - '0';
    cin >> operacio1;
    cin >> operacio2;

    if (operacio2 == '(') y = op();
    else if (operacio2 >= '0' and operacio2 <= '9' ) y = operacio2 - '0';

    cin >> num;

    if(operacio1 == '*') return (x*y);
    else if(operacio1 == '+') return (x+y);
    else return (x-y);

   
}
int main() {
    
    cout << op() << endl;
    
}