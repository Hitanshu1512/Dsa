#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;
    q.push("First");
    q.push("Second");
    q.push("Third");
    q.push("Fourth");

    // cout<< q.back();
    while(!q.empty())
    {
        cout<< q.front()<< " ";
        q.pop();
    }
    

    return 0;
}