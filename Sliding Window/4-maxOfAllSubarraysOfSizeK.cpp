#include <bits/stdc++.h>
using namespace std;

vector<int> getMax(int arr[], int n, int k)
{
    vector<int> v;
    list<int> l;    // or better to use a deque here
    int i= 0, j= 0, mx= 0;

    while(j< n)
    {
        if(l.size() == 0)
            l.push_back(arr[j]);
        while(l.size() > 0 and l.back()<arr[i]){
            l.push_back(arr[i]);
        }
        l.push_back(arr[i]);

        if(j-i+1 < k){
            j++;
        }

        else if(j-i+1 == k){
            v.push_back(l.front());
            if(arr[i] == l.front()){
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return v;
}

// driver code
int main()
{
    int n;
    cin>> n;
    int arr[n];
    for(int i= 0; i< n; i++)
        cin>> arr[i];
    int k;
    cin>> k;

    vector<int> res = getMax(arr, n, k);
    for(auto it : res)
        cout<< it<< " ";
    return 0;
}