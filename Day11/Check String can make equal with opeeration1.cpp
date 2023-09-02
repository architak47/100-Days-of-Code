#include <bits/stdc++.h>
using namespace std;

bool canBeEqual(string s1, string s2) {
    if(s1 == s2)return true;
    
    int n = s1.size();
    int i = 0;
    int j = 2;
    
    while(j < n){
        if(s1[i] == s2[j]){
            swap(s2[i], s2[j]);
        }
        i++;j++;
    }
    
    return s1 == s2;
}

int main()
{
    string s1 = "abcd", s2 = "cdab";
    
    bool ans = canBeEqual(s1, s2);
    if(ans){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    return 0;
}
