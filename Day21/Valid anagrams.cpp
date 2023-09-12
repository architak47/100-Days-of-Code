#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    int arr[26] = {0};
    for(int i = 0; i < s.size(); i++){
        arr[s[i] - 'a']++;
    }
    for(int i = 0; i < t.size(); i++){
        arr[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(arr[i] != 0)return false;
    }
    return true;
}

int main()
{
    string Str1 = "INTEGER";
    string Str2 = "TEGERNI";
    if(isAnagram(Str1, Str2))
        cout << "True" << endl;
    else
        cout<<"False"<<endl;

    return 0;
}
