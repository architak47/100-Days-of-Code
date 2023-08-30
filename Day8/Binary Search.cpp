#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end-start)/2;
    while(start<=end){
        
        if(nums.at(mid) == target){
            return mid; 
        }
        else if(target > nums.at(mid)){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = search(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "<< ind << endl;

    return 0;
}
