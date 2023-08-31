#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    long long n = a.size();
    long long sn = (n * (n+1))/2;
    long long sn2 = (n * (n+1) * (2 * n + 1))/6;

    long long s = 0, s2 = 0;
    for(int i = 0; i < n; i++){
        s += a[i];
        s2 += (long long)a[i] * (long long)a[i];
    }

    long long val1 = s - sn;
    long long val2 = s2 - sn2;
    val2 = val2 / val1;

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"<< ans[0] << ", " << ans[1] << "}\n";

    return 0;
}
