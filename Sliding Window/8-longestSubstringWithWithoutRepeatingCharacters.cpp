// https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestUniqueSubsttr(string s){
        // Creating a map to store the last positions of occurrence
        
        unordered_map<char, int> seen ;
        int maximum_length = 0;
     
        // Starting the initial point of window to index 0
        int start = 0;
     
        for(int end = 0; end < s.length(); end++)
        {
             
            // Checking if we have already seen the element or
            // not
            if (seen.find(s[end]) != seen.end())
            {
                 
                // If we have seen the number, move the start
                // pointer to position after the last occurrence
                start = max(start, seen[s[end]] + 1);
            }
     
            // Updating the last seen value of the character
            seen[s[end]] = end;
            maximum_length = max(maximum_length, end - start + 1);
        }
        return maximum_length;
        
    }
};