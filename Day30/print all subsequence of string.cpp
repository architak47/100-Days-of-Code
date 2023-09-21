#include <bits/stdc++.h>
#include <vector>

using namespace std; 

vector<string> generateSubsequences(string s)
{
    int n = s.length();
	vector<string>ans;
    ans.push_back("'Empty String'");

	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main() {
    string s="abc";
	vector<string>ans = generateSubsequences(s);
	//printint all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	}

    return 0;
}
