#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> ppi;

void closestPoint(int arr[][2], int n, int k)
{
    priority_queue<pair<int, pair<int, int>>> p; // maxheap
    // distance from origin (ignoring sq. root) = x^2 + y^2 

    for(int i= 0; i< n; i++)
    {
        p.push({(arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1]), {arr[i][0], arr[i][1]}}); // ({dis}, {c1, c2})
        if(p.size() > k){
            p.pop();
        }
    }

    while(p.size() > 0){
        cout<< p.top().second.first<< ","<< p.top().second.second<< "  ";
        p.pop();
    }
}

// driver code
int main()
{
    int n, k;
    cin>> n>> k;
    
    // int arr[n][2];
    // for(int i= 0; i< n;i++){
    //     for(int j= 0; j< 2; i++){
    //         cin>> arr[i][j];    // 2D array, with fixed j
    //     }
    // }

    int arr[3][2] = {{ 3, 3 },{ 5, -1 }, { -2, 4 }};


    closestPoint(arr, n, k);
    return 0;
}