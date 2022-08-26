#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m; // IT IS ORDERED SET, AND ALWAYS RETURN RESULTS IN SORTED ORDER!
    m[1] = "Key 1";
    m[2] = "Key 2";
    m[3] = "Key 3";
    m[4] = "Key 4";
    m[5] = "Key 5";
    m[6] = "Key 6";
    // m[5] = "Key 5";
    m.insert({10, "End Of Map"});

    for (auto i : m)
        cout << i.first << " " << i.second << endl;
    

    for (auto i : m)
        cout << i.first << " " << i.second << endl;

    m.insert({11, "End Key"});
     
    cout<< "Count: "<< m.count(5)<< " "<< m.count(20)<< endl;
    return 0;
}