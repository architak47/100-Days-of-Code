#include <bits/stdc++.h>
using namespace std;

bool isOdd(int n){
    return n % 2 != 0;
}
string largestOddNumber(string num) {
    int n = num.size();
    
    for(int i = n-1; i >= 0; i--){
        int val = int(num[i]);
        if(isOdd(val)){
            return num.substr(0,i+1);
        }
    }
    return "";
}

int main()
{
    string str = "35427";
    string ans = largestOddNumber(str);
    if(ans.size() <= 0) cout << "No odd no. in the string\n";
    else cout << ans;
    return 0;
}
