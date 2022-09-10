#include <iostream>
using namespace std;

int knapsack(int val[], int weight[], int n, int w)
{
    // base condition
    if(n == 0 || w == 0){
        return 0;       
    }

    // choice diagram
    if(weight[n-1] <= w){
        return max((val[n-1]+knapsack(val, weight, n-1 ,w-weight[n-1])), knapsack(val, weight, n-1, w));
    }

    else if(weight[n-1] > w){
        return knapsack(val, weight, n-1, w);
    }

    return knapsack(val, weight, n-1, w);
}

// driver code
int main()
{
    int w, n;
    cin>> w>> n;
    int val[n], weight[n];

    for(int i= 0; i< n; i++)
        cin>> val[i]; 
    for(int i= 0; i< n; i++) 
        cin>> weight[i];

    cout<< "Profit: "<< knapsack(val, weight, n, w)<< endl;
    return 0;
}