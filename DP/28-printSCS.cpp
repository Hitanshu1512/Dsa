#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

// global dp matrix
int t[1001][1001];

string printSCS(string X, string Y, int n, int m)
{
    string s;
    // base cond.
    for(int i= 0; i< n+1; i++)
        t[i][0] = 0;
    for(int j= 0; j< m+1; j++)
        t[0][j] = 0;

    // Now fill remaining part of lookup table
    for(int i= 1; i< n+1; i++){
        for(int j= 1; j< m+1; j++){

            if(X[i-1] == Y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max (t[i][j-1], t[i-1][j]);
        }
    }
    
    // here printing process is beginning ...
    int i = n, j= m;
    while(i> 0 && j>0){
        if(X[i-1] == Y[j-1]){
            s.push_back(X[i-1]);  //Or s += X[i-1];
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                s.push_back(Y[j-1]);
                j--;
            }else{
                s.push_back(X[i-1]);
                i--;
            }
        }
    }

    while(i > 0){
        s.push_back(X[i-1]);
        i--;
    }
    while (j > 0){
        s.push_back(Y[j-1]);
        j--;
    }
    
    reverse(s.begin(), s.end());
    return s;
}

// driver code
int main()
{
    string X, Y;
    cin>> X>> Y;     // Given sorted strings!

    int n= X.length();
    int m= Y.length();

    cout<< printSCS(X, Y, n, m)<< endl;
    return 0;
}