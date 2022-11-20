#include<bits/stdc++.h>
using namespace std;

// Call by reference
void insertElement(vector<int> &arr, int temp)
{
    if(arr.size() == 0 || arr[arr.size()-1] <= temp){
        arr.push_back(temp);
        return;
    }

    int x = arr[arr.size()-1];
    arr.pop_back();
    insertElement(arr, temp);
    arr.push_back(x);
    return;
}

// Call by reference
void sortArr(vector<int> &arr)
{
    // base -> hypothesis -> induction

    if(arr.size() == 1)
        return;
    
    int temp = arr[arr.size()-1];
    arr.pop_back();
    sortArr(arr);
    insertElement(arr, temp);
}

// Driver code
int main(){
    int n;
    cin>> n;
    vector<int> arr;
    for(int i= 0; i< n; i++){
        int x;
        cin>> x;
        arr.push_back(x);
    }

    sortArr(arr);
    for(auto it : arr){
        cout<< it<< " ";
    }
    return 0;
}