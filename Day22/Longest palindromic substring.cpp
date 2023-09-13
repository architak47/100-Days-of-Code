#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    if(n <= 1) return s;
    int st = 0, end = 0;
    int maxi = 1;

    // For odd length
    for(int i = 0; i < n-1; i++){
        int l = i, r = i;
        while(l >= 0 and r < n){
            if(s[l] == s[r]){
                l--, r++;
            } 
            else{
                break;
            }
        }
        int len = r-l-1;
        if(len >= maxi){
            maxi = len;
            st = l+1, end = r-1;
        }
    }
    
    // for even length
    for(int i = 0; i < n-1; i++){
        int l = i, r = i+1;
        while(l >= 0 and r < n){
            if(s[l] == s[r]){
                l--, r++;
            } 
            else{
                break;
            }
        }
        int len = r-l-1;
        if(len >= maxi){
            maxi = len;
            st = l+1, end = r-1;
        }
    }
    return s.substr(st, maxi);
}

int main()
{
    string str = "ababc";
    string ans = longestPalindrome(str);
    
    cout << ans << endl;

    return 0;
}
