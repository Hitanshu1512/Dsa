#include <bits/stdc++.h>
using namespace std;

int getAnagrams(string s, string p)
{
    unordered_map<char, int>mp;
    int n = s.size();
    int k  = p.size();
    int i= 0, j= 0, ans= 0;

    //storing the occ. of string p in the map
    for(auto &it : p){
        mp[it]++;
    }
    int count = mp.size();
 
    while(j < n)
    {
        //calculation part
        if (mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if (mp[s[j]] == 0){
                count--;
            }
        }

        //window length not achived yet
        if (j-i+1 < k){
            j++;
        }

        //window length achived, find ans and slide the window
        else if (j-i+1 == k){
            //finding the ans
            if (count == 0){
                ans++;
            }
            if (mp.find(s[i]) != mp.end()){
                mp[s[i]]++;
                if (mp[s[i]] == 1){
                    count++;
                }
            }

            //slide the window
            i++;
            j++;
        }
    }
    return ans;

}

// driver code
int main()
{
    string s, p;
    cin>> s>> p;

    cout<< getAnagrams(s, p)<< endl;
    return 0;
}