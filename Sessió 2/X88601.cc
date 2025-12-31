// Add or remove includes
#include <iostream>
#include <string>

using namespace std;

// Pre: 0 <= i <= j < s.size()
// Post: el substring s[i..j] s'ha revessat. La resta de s no ha canviat.
void reverseSubstring(string &s, int i, int j) {
    int tamany = s.length();
    char temp;
    if (tamany == 1);
    else if (i >= j);
    else {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        return reverseSubstring(s,++i, --j);
    }
    
};

// Adapt the call to 'function_name' and the way it is called to your case.
int main()  {
    string s;
    int i, j;
    while (cin >> s >> i >> j) {
        reverseSubstring(s, i, j);
        cout << s << endl;
    }
}
