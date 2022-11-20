#include <iostream>
using namespace std;

int factorial(int n)
{
    // base condition
    if(n == 0){
        return 1;
    }

    // Induction + hypothesis    
    return n * factorial(n-1);
}

// driver code
int main()
{
    int n;
    cin>> n;
    cout<< factorial(n);
    return 0;
}