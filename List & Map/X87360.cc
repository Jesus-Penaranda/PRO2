#include<iostream>
#include<list>
#include<iterator>

using namespace std;

/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
void inter(list<int>& uno, const list<int>& dos ) {
    list<int>:: iterator it1 = uno.begin();
    list<int>:: const_iterator it2 = dos.begin();
   
    while(it1 != uno.end() and it2 != dos.end()) {
        if (*it2 > *it1) {
            it1 = uno.erase(it1);
           
        }
        else if (*it2 == *it1) {
           
            ++it1;
            ++it2;
        }
        else  ++it2;
    }
    while(it1 != uno.end())
        it1 = uno.erase(it1);   
    
}