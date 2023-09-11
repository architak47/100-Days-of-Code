#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    int arr1[256] ={1}, arr2[256] = {1};
    int n = s.size();
    
    for(int i = 0; i < n; i++){
        if(arr1[s[i]] != arr2[t[i]]){
            return false;
        }
        arr1[s[i]] = i+2;
        arr2[t[i]] = i+2;
    }
    return true;
}

int main()
{
    string str1 = "paper";
    string str2 = "title";
    
    if(isIsomorphic(str1, str2)){
        cout << "strings are Isomorphic\n";
    }
    else{
        cout << "Strings are not Isomorphic\n";
    }

    return 0;
}
