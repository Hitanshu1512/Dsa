#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

int maxArea(int arr[], int n)
{
    int mx = 0;
    int pseudoLeft = -1;
    int pseudoRight = n;
    vector<int> left;
    vector<int> right;
    vector<int> area;
    stack<pair<int, int>> sl, sr;    // first-> NSL, second-> index 

    // NSL
    for(int i= 0; i< n; i++)
    {
        if(sl.size() == 0){
            left.push_back(pseudoLeft);
        }
        else if(sl.size() > 0 && sl.top().first < arr[i]){
            left.push_back(sl.top().second);
        }
        else if(sl.size() > 0 && sl.top().first >= arr[i]){
            while(sl.size() > 0 && sl.top().first >= arr[i]){
                sl.pop();
            }
            if(sl.size() == 0){
                left.push_back(pseudoLeft);
            }
            else{
                left.push_back(sl.top().second);
            }
        }
        sl.push({arr[i], i});
    }

    // NSR
    for(int i= n-1; i>= 0; i--)
    {
        if(sr.size() == 0){
            right.push_back(pseudoRight);
        }
        else if(sr.size() > 0 && sr.top().first < arr[i]){
            right.push_back(sr.top().second);
        }
        else if(sr.size() > 0 && sr.top().first >= arr[i]){
            while(sr.size() > 0 && sr.top().first >= arr[i]){
                sr.pop();
            }
            if(sr.size() == 0){
                right.push_back(pseudoRight);
            }
            else{
                right.push_back(sr.top().second);
            }
        }
        sr.push({arr[i], i});
    }
    reverse(right.begin(), right.end());

    // area = height * width and width[i] = right[i]-left[i]-1; 

    //area vector and max value in area = max area.
    for(int i= 0; i< n; i++){
        // area[i] = arr[i] * (right[i]-left[i]-1);
        // mx = max(mx, area[i]);
        mx = max(mx,(right[i]-left[i]-1)*arr[i]);
    }
    return mx;
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
    
    cout<< maxArea(arr, n);
    cout<< endl;

    return 0;
}