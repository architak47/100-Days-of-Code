#include <bits/stdc++.h>
using namespace std;

int Binary_Search(vector<int> &nums, int target, int start, int last) {
    int mid = start + (last - start)/2;
    while(last >= start) 
    {
        if(nums[mid] == target){
            return mid;
        } 
        else if(nums[mid] < target) {
            start = mid + 1;
        }
        else{
            last = mid - 1;
        }        
        mid = start + (last - start)/2;
    }   
    return -1;
}

int minElement(vector<int> &arr){
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end-start)/2;
    
    if(arr.size() == 1) return 0;
    if(arr.at(end) < arr.at(end - 1)){
        return end;
    }
    
    while(end > start){
        int next = (mid+1) % arr.size();
        int prev = (mid + arr.size() -1) % arr.size();
        if(arr[mid] < arr[next] && arr[mid] < arr[prev]) {
            return mid;
        }
        else if(arr[mid] < arr[end]) {
            end  = mid ;
        }
        else {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return 0;
}
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int mini = minElement(nums);
    int a = -1, b = -1;
    a = Binary_Search(nums, target, 0, mini-1);
    b = Binary_Search(nums, target, mini, n-1);
    if(a!=-1) return a;
    if(b!=-1) return b;
    return -1;
}


int main()
{
     vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int k = 1;
    int ans = search(arr, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}
