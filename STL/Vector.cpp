#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4); 
    v.push_back(5);
    v.push_back(6);

    // v.clear();
    // USER DRIVEN :-
    // for(int i = 0; i < 6; i++)
    //     cout<< v[i]<<" ";

    // int n;
    // cin>> n;
    // vector<int> v(n);
    // for(auto i= 0; i < n; i++)
    //     cin>>v[i];
    
    // for(auto x : v)
    //     cout<< x<< " "; 

    cout<< "Capacity: "<< v.capacity()<< endl;
    cout<< "Size: "<< v.size()<< endl;
    cout<< "Front: "<< v.front()<< "\n"<< "Back: "<< v.back()<< endl;
    //PRACTICE ROTATE FUNCTION !
    vector<int> v2(6, 5);
    cout<< "Print v2: ";
    for(auto x  : v2)
        cout<< x<< " ";
    
    cout<< "\n";

    vector<int> v_copy(v);
    cout<< "Print Copy of v: ";
    for(auto x  : v_copy)
        cout<< x<< " ";
    return 0;
}