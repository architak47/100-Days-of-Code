#include <bits/stdc++.h>
using namespace std;

int beautySum(string s) {
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        unordered_map<char, int> mp;
        for(int j = i; j < n; j++){
            mp[s[j]]++;
            int maxi = 0, mini = INT_MAX;
            for(auto it : mp){
                maxi = max(maxi, it.second);
                mini = min(mini, it.second);
            }
            ans += (maxi - mini);
        }           
    }
    return ans;
}

int main()
{
    string str = "ababc";
    int ans = beautySum(str);
    
    cout << ans << endl;

    return 0;
}
