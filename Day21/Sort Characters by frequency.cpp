#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> mp;
    for(char c : s) mp[c]++;

    priority_queue<pair<int, char>> pq;
    for(auto it : mp)pq.push({it.second, it.first});

    string ans = "";

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        int freq = temp.first;
        char ch = temp.second;
        ans += string(freq, ch);
    }
    return ans;
}

int main()
{
    string str = "tree";
    string ans = frequencySort(str);
    
    cout << ans << endl;

    return 0;
}
