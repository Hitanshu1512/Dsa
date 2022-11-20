#include <iostream>
using namespace std;

void print(int n)
{
    if (n == 1){
        cout<< "1"<< " ";
        return;
    }

    cout<< n<< " ";
    print(n-1);
}

// driver code
int main()
{
    int n;
    cin>> n;
    print(n);
    return 0;
}