#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(string s, string t) {
    int n = s.length();
    int m = t.length();
    int j = 0;

    for (int i = 0; i < m && j < n; i++)
        if (s[j] == t[i])
            j++;
    return (j == n);
}

int main() {
    string s = "abc";
    string t = "ahbgdc";

    if (isSubsequence(s, t)) {
        cout << "\"" << s << "\" is a subsequence of \"" << t << "\"" << endl;
    } else {
        cout << "\"" << s << "\" is not a subsequence of \"" << t << "\"" << endl;
    }

    return 0;
}
