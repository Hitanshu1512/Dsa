#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
// typedef pair<int, int> pi;
using namespace std;
// uses map!
// Hint: Whenever "frequent/frequency" term is coming -> Think map (unordered) .

void topFrequent(int arr[], int n, int k)
{
    unordered_map<int, int> mp;

    // Push array values in a map
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        // Key : Value  -> Key is storing frequency, Value is arr[i].
    }
    
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;

    for(auto i= mp.begin(); i != mp.end(); i++)
    {
        minh.push({i->second, i->first});
        if(minh.size() > k){
            minh.pop();
        }
    }

    while(minh.size() > 0){
        cout<< minh.top().second<< " ";
        minh.pop();
    }
}

// driver code
int main()
{
    int n, k;
    cin>> n>> k;
    int arr[n];
    for(int i= 0; i< n;i++){
        cin>> arr[i];
    }

    topFrequent(arr, n, k);
    cout<< endl;
    return 0;
}