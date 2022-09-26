#include <bits/stdc++.h>
using namespace std;

// int getMax(vector<int> v, int n, int k)
// {

// }

// // driver code
// int main()
// {
//     vector<int> v{0,1,4,2,1,7,6,0,-1,3,5,8};
//     int n= v.size(), k;
//     cin>> k;

//     cout<< getMax(v, n, k)<< endl;
//     return 0;
// }

class Hero
{
private:
    int health;

public:
    int power;

    int getHealth()
    {
        return health;
    }
    void setHealth(int x)
    {
        health = x;
    }
};

int main()
{
    Hero loki;
    loki.power = 50;
    loki.setHealth(80);
    cout<< loki.getHealth() << " "<< loki.power;
    return 0;
}