#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
// typedef pair<int, int> pi;
using namespace std;
// uses map!
// Hint: Whenever "frequent/frequency" term is coming -> Think map (unordered) .

void frequencySort(int arr[], int n)
{
    unordered_map<int, int> mp;

    // Push array values in a map
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        // Key : Value  -> Key is storing frequency, Value is arr[i].
    }
    
    priority_queue < pair<int, int>> maxh;

    for(auto i= mp.begin(); i != mp.end(); i++)
    {
        maxh.push({i->first,i->second}); // pushing values in heap from map is done using "->" operator .
    }

    while(maxh.size() > 0){
        int freq = maxh.top().first;
        int value = maxh.top().second;

        for(int i= 1; i <= freq; i++){
            cout<< value << " ";
            maxh.pop();
        }
    }
}

// driver code
int main()
{
    int n;
    cin>> n;
    int arr[n];
    for(int i= 0; i< n;i++){
        cin>> arr[i];
    }

    frequencySort(arr, n);
    cout<< endl;
    return 0;
}