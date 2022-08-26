#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;
    // list<int> l_copy;  // same as Deque!
    l.push_back(1);
    l.push_front(2);
    l.push_back(3);
    l.push_front(4);
    l.push_back(5);
    l.push_front(6);
    // l.erase(l.begin(), l.end());
    cout<< "Print Before Erase: ";
    for(int x : l)
        cout<< x<< " ";
    cout<< endl;
    l.remove(1); //Deletes 1
    l.remove(4); //Deletes 4
    l.remove(400); //Useless, since 400 is not in out LL!
    
    cout<< "Print After Erase: ";
    for(int x : l)
        cout<< x<< " ";

    return 0;
}