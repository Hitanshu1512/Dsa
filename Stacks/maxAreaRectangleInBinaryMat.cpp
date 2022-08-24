// Max Area Rectangle in binary matrix : https://practice.geeksforgeeks.org/problems/max-rectangle/1
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int MAH(vector<int> arr)
{
    int mx = 0;
    int pseudoLeft = -1;
    int pseudoRight = arr.size();
    vector<int> left;
    vector<int> right;
    stack<pair<int, int>> sl, sr;    // first-> NSL, second-> index 

    // NSL
    for(int i= 0; i< arr.size(); i++)
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
    for(int i= arr.size()-1; i>= 0; i--)
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
    for(int i= 0; i< arr.size(); i++){
        // area[i] = arr[i] * (right[i]-left[i]-1);
        // mx = max(mx, area[i]);
        mx = max(mx,(right[i]-left[i]-1)*arr[i]);
    }
    return mx;
}
//-------------- correct! ------------------

int maxArea(int M[MAX][MAX], int n, int m)
        {
            vector<int> v;
            for(int j= 0; j < m; j++){
                v.push_back(M[0][j]); // copy first row of the matrix in our vector
            }
            int maxArea = MAH(v);
        
            for(int i= 1; i< n; i++){
                for(int j= 0; j< m; j++){
                    if(M[i][j] == 0){
                        v[j] = 0;
                    }
                    else{
                        v[j] += M[i][j];
                    }
                }
                maxArea = max(maxArea, MAH(v));
            }
        
            return maxArea;
        }

// driver code
int main()
{
    int arr[MAX][MAX];
    int n, m;
    cin>> n>> m;
    for(int i= 0; i< n; i++){
        for(int j= 0; j< m; j++){
            cin >> arr[i][j];
        }
    }
    cout<< maxArea(arr, n, m)<< endl;

    return 0;
}