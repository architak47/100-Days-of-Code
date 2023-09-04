#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr){
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int idx = -1;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                idx = low;
                ans = arr[low];
            }
            break;
        }
        else if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                ans = arr[low];
                idx = mid;
            }
            low = mid + 1;
        }
        else{
            if(arr[mid] < ans){
                ans = arr[mid];
                idx = mid;
            }
            high = mid - 1;
        }
    }    
    return idx;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";

    return 0;
}
