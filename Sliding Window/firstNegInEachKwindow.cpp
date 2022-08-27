// firstNegativeNumberInEveryWindowOfSizeK
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> firstNegative(int arr[], int n, int k)
{
    list<int> l;
    vector<int> v;
    int i= 0, j= 0; 
    while(j < n)
    {
        // top calculations
        if(arr[j] < 0){
            l.push_back(arr[j]);
        }

        // (Single time) comparing window size with k
        if(j-i+1 < k){
            j++;
        }
        
        // window size matches k
        else if(j-i+1 == k){
            // calculations to find the answer
            if(l.size() == 0){
                v.push_back(0);
            }
            else{
                v.push_back(l.front());

                // sliding window and removing first element from list
                if(arr[i] == l.front()){
                    l.pop_front();
                }
                i++;
                j++;
            }
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

    vector<int> res = firstNegative(arr, n, k);
    for(auto it : res)
        cout<< it<< " ";

    return 0;
}

// 9
// -1 2 -3 5 6 -7 8 9 10
// 3