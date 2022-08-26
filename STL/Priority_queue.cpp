#include <iostream>
#include <queue>
using namespace std;

int main()
{
    //MAX HEAP
    //It will return the greatest element in the queue!
    priority_queue<int> maxi;

    //MIN HEAP
    //It will return the smallest element in the queue!
    priority_queue<int, vector<int>, greater<int>> mini;
    maxi.push(10);
    maxi.push(0);
    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    maxi.push(4);
    mini.push(5);
    mini.push(6);
    mini.push(7);
    mini.push(8);
    mini.push(9);
    mini.push(10);
    //OUTPUT
    int m =  maxi.size();
    for(int i = 0; i < m; i++)
    {
        cout<< maxi.top()<< " ";
        maxi.pop();
    }
    cout<< endl;

    // while(!maxi.empty())
    // {
    //     cout<< maxi.top()<< " ";
    //     maxi.pop();
    // }

    while(!mini.empty())
    {
        cout<< mini.top()<< " ";
        mini.pop();
    }
    cout<< endl;
    return 0;
}