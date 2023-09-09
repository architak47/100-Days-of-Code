#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    int n = s.size();
    int cnt = 0;
    string ans = "";

    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            if(cnt > 0){
                ans += '(';
            }
            cnt++;
        }
        else{
            cnt--;
            if(cnt > 0){
                ans+= ')';
            }
        }
    }
    
    return ans;
}

int main()
{
    string str = "(()())(())";
    string ans = removeOuterParentheses(str);
    cout << "string after removing first and last paranthesis: " << ans << endl;
    return 0;
}
