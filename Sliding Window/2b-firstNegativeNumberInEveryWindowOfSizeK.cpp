// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
#include <iostream>
#include <vector>
#include <list>
using namespace std;

// vector<long long> printFirstNegativeInteger(long long int a[], 
//                             long long int n, long long int k) 
// {
//     vector<long long> ans;
//     int i = n-1, j = n-1;
//     int neg = 0, ind=n;
    
//     while(i>=0){
//         if(a[i]<0) {
//             neg = a[i];
//             ind = i;
//         }
//         if(j-i+1<k) i--;
//         else if(j-i+1==k){
//             if(ind>j) neg = 0;
//             ans.push_back(neg);
//             i--; j--;
//         }
//     }
//     reverse(ans.begin(),ans.end());
//     return ans;
    
// }

vector<long long int> firstNegative(long long int A[], long long int N, long long int K){

    long long j, i;
    list<long long> l;
    vector<long long> v;

    while(j < N)
    {
        // Top Calculations
        if(A[j] < 0){
            l.push_back(A[i]);
        }
        if(j-i+1 < K){
            j++;
        }
        else if(j-i+1 == K){
            if(l.size() == 0){
                v.push_back(0);
            }
            else{
                v.push_back(l.front());

                if(A[i] == l.front()){
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
    }
    
    return v;
}


int main()
{
    long long int k= 3; // k = size of window
    long long int arr[5] = {-8, 2, 3, -6, 10};          
    
    vector<long long> ans = firstNegative(arr, 5, k);
    for (auto it : ans){
        cout<< it<< " ";
    }
    cout<< endl;
    return 0;
}