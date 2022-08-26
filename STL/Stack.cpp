#include <iostream>
#include <stack>
using namespace std;
//STACK FOLLOWS FIRST IN LAST OUT (LIFO)
int main()
{
    stack<int> s;
    s.push(12);   
    s.push(11);
    s.push(10);
    
    //it is working here in case of int!
    // cout<< s.top()<< " ";
    // cout<< s.top()-1<< " ";
    // cout<< s.top()-2<< endl;

    //Correct way :
    while(!s.empty())//while(true)-->s.empty() != 0
    {
        cout<<s .top()<< " ";
        s.pop();
    }
    cout<< endl;
    stack<string> str;
    str.push("Twelve");
    str.push("Eleven");
    str.push("Ten");

    while(!str.empty())
    {
        cout<< str.top()<< " ";
        str.pop();
    }
}