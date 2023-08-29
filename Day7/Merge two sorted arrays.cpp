#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> nums((m+n) , 0);
    
    int i = 0 , j = 0;
    int k = 0;
    

    while(i < m && j < n){
        if(nums1[i] < nums2[j]){
            nums[k++] = nums1[i++];
        }
        else{
            nums[k++] = nums2[j++];
        }
    }

    while(i < m){
        nums[k++] = nums1[i++];
    }

    while(j < n){
        nums[k++] = nums2[j++];
    }
    nums1 = nums;
}

int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, n, arr2, m);
    for(int i = 0; i < arr1.size(); i++){
        cout << arr1[i] << ' ';
    }
    cout << endl;

    return 0;
}
