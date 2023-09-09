#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int n = s.size();
    string ans = "";

    string temp = "";
    for(int i = n-1; i >= 0; i--){
        if(s[i] != ' ' and i >= 1){
            temp += s[i];
        }
        else{
            if(i == 0) temp += s[i];
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += ' '; 
            temp = "";
        }
    }
    while(ans [0] == ' '){
        ans.erase(0,1);
    }
    while(ans[ans.size() - 1] == ' '){
        ans.pop_back();
    }
    for(int i = 0; i < ans.size()-1; i++){
         while(ans[i]==' ' && ans[i]==ans[i+1]) //added equal sign
        {
            ans.erase( ans.begin() + i );
        }
    }
    return ans;
}

int main()
{
    string str = "the sky is blue";
    string ans = reverseWords(str);
    cout<<"After reversing words: "<<endl;
    cout<<ans;
    return 0;
}
