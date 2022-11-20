#include <iostream>
using namespace std;

void print(int n)
{
    if(n == 1){             // base condition
        cout<< "1"<< " ";
        return;
    }

    print(n-1);     // Induction
    cout<< n<< " ";
    // IBH - Induction-Base-Production
}

// driver code
int main()
{
    int n;
    cin>> n;
    print(n);
    return 0;
}