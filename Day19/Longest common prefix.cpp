#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if(n==0){
        return "";
    }
    string st = "";
    
    sort(strs.begin() ,strs.end());
    string p = strs[0]; string q = strs[n-1];
    for(int i = 0 ; i < p.size() ; i++){
        if(p[i]==q[i]){
            st = st+p[i];
        }
        else{
            break;
        }
    }
    return st;
}

int main()
{
    vector<string> strs = {"flower","flow","flight"};
    string ans = longestCommonPrefix(strs);
    if(ans.size() <= 0) {
        cout << "There are no common prefixes\n";
    }
    else{
        cout << ans << "\n";
    }
    return 0;
}
