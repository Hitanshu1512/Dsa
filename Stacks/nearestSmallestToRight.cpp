#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> smallestFromRight(int arr[], int N)
{
    vector<int> v;
    stack<int>s;
    for(int i= N-1; i >= 0; i--)
    {
        if(s.size() == 0){
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() < arr[i])
        {
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() >= arr[i]){     // or can be else alone*
            while(s.size() > 0 && s.top() >= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }
        }
        s.push(arr[i]); 
    }
    
    return v;
}

// driver code
int main()
{
    int n;
    cin>> n;
    int arr[n];
    for(int i= 0; i< n; i++){
        cin>> arr[i];
    }
    vector<int> res = smallestFromRight(arr, n);
    reverse(res.begin(), res.end());

    for(auto it : res)
        cout<< it<< " ";

    return 0;
}