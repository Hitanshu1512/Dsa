#include <iostream>
#include <array>
using namespace std;

int main()
{   
    //STATIC IN SIZE !
    array<int, 5> arr;
    arr = {1, 2, 3, 4, 5};
    for(auto x : arr)
        cout<< x<< " ";
    return 0;
}