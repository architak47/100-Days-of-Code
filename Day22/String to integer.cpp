#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int n = s.size();
    if(n == 0) return 0;

    int i = 0;
    while(i < n and s[i] == ' ') i++;
    s = s.substr(i);

    int sign = +1;
    long ans = 0;

    if(s[0] == '-') sign = -1;

    int maxi =INT_MAX, mini =INT_MIN;
    i = (s[0] == '+' or s[0] == '-')?1:0;

    while(i < s.size()){
        if(s[0] == ' ' or !isdigit(s[i])) break;
        ans = ans * 10 + s[i] - '0';
        if(sign == -1 and (-1*ans) < mini)return mini;
        if(sign == 1 and ans > maxi) return maxi;

        i++;
    }
    return (int)(ans*sign);
}

int main()
{
    string str = "4193 with words";
    int ans = myAtoi(str);
    
    cout << ans << endl;

    return 0;
}
