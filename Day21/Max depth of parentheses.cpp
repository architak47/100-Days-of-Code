#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int cnt = 0;
    int maxi = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            cnt++;
        }
        else if(s[i] == ')'){
            maxi = max(cnt, maxi);
            cnt--;
        }
    }
    return maxi;
}

int main()
{
    string str = "(1+(2*3)+((8)/4))+1";
    int ans = maxDepth(str);
    
    cout << "Maximum depth of parentheses is: " << ans << endl;

    return 0;
}
