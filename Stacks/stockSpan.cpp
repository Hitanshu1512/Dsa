#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> stockSpan(int arr[], int n)
{
    vector<int> v;
    stack<pair<int, int>> s;    // first -> NGL and second -> i

    for(int i = 0; i<= n-1; i++)
    {
        if(s.size() == 0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top().first > arr[i]){
            v.push_back(s.top().second);
        }
        // or else only!
        else if(s.size() > 0 && s.top().first <= arr[i]){
            while(s.size() > 0 && s.top().first <= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }

    for(int i= 0; i< n; i++){
        v[i] = i - v[i];
    }

    return v;
}

// ------------------------------------------- done by using "count" ------------------------------------------------------
// vector<int> stockSpan(int arr[], int n)
// {
//     vector<int> v;
//     stack<pair<int, int>> s;    // first -> arr[i] and second -> i
//     int count = 1;
//     for(int i = 0; i<= n-1; i++)
//     {
//         if(s.size() == 0){
//             v.push_back(1);
//         }
//         else if(s.size() > 0 && s.top().first > arr[i]){
//             v.push_back(1);
//         }
//         // or else only!
//         else if(s.size() > 0 && s.top().first <= arr[i]){
//             while(s.size() > 0 && s.top().first <= arr[i]){
//                 s.pop();
//                 count++;
//             }
//             v.push_back(count);
//         }
//         s.push({arr[i], i});
//     }
//     return v;
// }
//  -------------------------------------------------------------------------------------------------------------------------

// driver code
int main()
{
    int n;
    cin>> n;
    int arr[n];
    for(int i= 0; i< n; i++){
        cin>> arr[i];
    }
    vector<int> res = stockSpan(arr, n);

    for(auto it : res)
        cout<< it<< " ";

    return 0;
}