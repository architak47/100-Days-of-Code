#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
     unordered_map<char, int> mp ={
        {'M',1000},
        {'D',500},
        {'C',100},
        {'L',50},
        {'X',10},
        {'V',5},
        {'I',1}
    };
    
    int ans = mp[s.back()];
    for(int i = s.size()-2; i >= 0; i--){
        if(mp[s[i]] < mp[s[i+1]]){
            ans -= mp[s[i]];
        }
        else{
            ans += mp[s[i]];
        }
    }
    return ans;
}

int main()
{
    string str = "MCMXCIV";
    int ans = romanToInt(str);
    
    cout << "Integer conversion of the roman no. is: " << ans << endl;

    return 0;
}
