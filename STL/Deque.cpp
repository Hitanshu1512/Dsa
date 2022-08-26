#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);
    dq.push_front(4);
    dq.push_back(5);

    cout<<"Before Popping: ";
    for(auto x : dq)
        cout<< x<< " ";
    cout<<endl;
    dq.pop_back();
    dq.pop_front();
    cout<<"After Popping: ";
    for(auto x : dq)
        cout<< x<< " ";
    cout<<endl;
    cout<< dq.at(2);

    // dq.erase(dq.begin(), dq.end());
    // for(auto x : dq)
    //     cout<< x<< " ";
    

    return 0;
}