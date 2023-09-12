#include <bits/stdc++.h>
using namespace std;

int countSubStrings(string str, int k) 
{
    int n = str.size();
    int res = 0;
    int cnt[26] = {0};

    for(int i = 0; i < n; i++){
        int dist = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int j = i; j < n; j++){
            if(cnt[str[j] - 'a'] == 0){
                dist++;
            }
            cnt[str[j] - 'a']++;
            if(dist == k)res++;
        }
    }
    return res;
}

int main()
{
    string str = "aacfssa";
    int k = 3;
    int ans = countSubStrings(str, k);
    
    cout << "substrins with k distinct characters are: " << ans << endl;

    return 0;
}
