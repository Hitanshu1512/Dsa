#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> left(int arr[], int n)
{
    vector<int> left;
    int pseudoLeft = -1;
    stack<pair<int, int>> s;    // first-> NSL, second-> index 

    // NSL
    for(int i= 0; i< n; i++)
    {
        if(s.size() == 0){
            // s.push({arr[i], pseudoLeft});
            left.push_back(pseudoLeft);
        }
        else if(s.size() > 0 && s.top().first < arr[i]){
            left.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first >= arr[i]){
            while(s.size() > 0 && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                left.push_back(pseudoLeft);
            }
            else{
                left.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    s.empty();
    return left;
}

vector<int> right(int arr[], int n)
{
    int pseudoRight = n;
    vector<int> right;
    stack<pair<int, int>> s;    // first-> NSL, second-> index 

     // NSR
    for(int i= n-1; i>= 0; i--)
    {
        if(s.size() == 0){
            right.push_back(pseudoRight);
        }
        else if(s.size() > 0 && s.top().first < arr[i]){
            right.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first >= arr[i]){
            while(s.size() > 0 && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                right.push_back(pseudoRight);
            }
            else{
                right.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    reverse(right.begin(), right.end());
    return right;
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
    vector<int> l = left(arr, n);
    vector<int> r = right(arr, n);

    int mx = 0;

    //area vector and max value in area = max area.
    for(int i= 0; i< n; i++)
        mx = max(mx, arr[i] * (r[i]-l[i]-1));
    
    cout<< mx<< endl;

    return 0;
}