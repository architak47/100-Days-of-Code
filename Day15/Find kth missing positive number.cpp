#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& A, int k) {
int l = 0, r = A.size(), m;
while (l < r) {
    m = (l + r) / 2;
    if (A[m] - 1 - m < k)
        l = m + 1;
    else
        r = m;
}
return l + k;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int k = 4;
    int ans = findKthPositive(vec, k);
    cout << "The missing number is: " << ans << "\n";

    return 0;
}
