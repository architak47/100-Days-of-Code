#include <bits/stdc++.h>
using namespace std;

int countStudent(vector<int> v, int pages){
    int std = 1;
    long long stdpages = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] + stdpages <= pages){
            stdpages += v[i];
        }
        else{
            std += 1;
            stdpages = v[i];
        }
    }
    return std;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high){
        int mid = (low + high) / 2;\
        int student = countStudent(arr, mid);
        if(student > m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}
int splitArray(vector<int>& nums, int k) {
    return findPages(nums, nums.size(), k);
}

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = splitArray(a, k);
    cout << "The answer is: " << ans << "\n";

    return 0;
}
