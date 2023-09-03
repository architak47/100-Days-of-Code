#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> &vec, int n, int key){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(vec.at(mid) == key){
            ans = mid;
            end = mid-1;
        }
        else if(vec.at(mid) < key){
            start = mid+1;
        }
        else {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int lastOcc(vector<int> &vec, int n, int key){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(vec.at(mid) == key){
            ans = mid;
            start = mid+1;
        }
        else if(vec.at(mid) < key){
            start = mid+1;
        }
        else {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int low = firstOcc(nums, n, target);
    int high = lastOcc(nums, n, target);
    vector<int> ans = {low, high};
    return ans;
}

int main()
{
    int key = 13;
    vector < int > v = {3,4,13,13,13,20,40};
    vector<int> ans = searchRange(v, key);
    
    cout << ans[0] << ' ' << ans[1] << endl;

    return 0;
}
