#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(6);
    s.insert(6);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    s.insert(10);
    // s.erase(s.begin());

    // set<int>::iterator it = m.begin();   //To remove all elements from the set,                 
    // it++;                                //using a single statement .
    // m.erase(it);

    cout<< s.count(6)<< endl;
    cout<< s.count(15)<< endl;

    for(int i : s)
        cout<< i<< " ";
}
