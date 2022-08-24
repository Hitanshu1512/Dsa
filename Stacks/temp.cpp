#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>> t;
	while(t--)
	{
	    int a,  b, c;
	    cin>> a>> b>> c;
	    float avg = (a+b)/2;
	    if(avg > c){
	        cout<< "YES"<< endl;
	    }else if(avg <= c){
	        cout<< "NO"<< endl;
	    }
	    
	}
	return 0;
}










// #include <iostream>
// #include <vector>
// #include <stack>
// #include <algorithm>
// #include <math.h>
// using namespace std;




// // driver code
// int main()
// {
//     int n;
//     cin>> n;
//     int arr[n];
//     for(int i= 0; i< n; i++){
//         cin>> arr[i];
//     }
//     // vector<int> res = (arr, n);
//     // reverse(res.begin(), res.end());

//     // for(auto it : res)
//     //     cout<< it<< " ";

//     return 0;
// }