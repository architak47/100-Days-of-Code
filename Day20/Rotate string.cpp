#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.size()!=goal.size()) return false;
    string ans=s+s;
    if(ans.find(goal)!=string::npos){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string str1 = "abcde";
    string str2 = "cdeab";
    
    if(rotateString(str1, str2)){
        cout << "strings are same after rotation\n";
    }
    else{
        cout << "Strings are not same after rotation\n";
    }

    return 0;
}
