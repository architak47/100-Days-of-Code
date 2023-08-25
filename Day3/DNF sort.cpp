#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
            // mid++;
        }
    }
    
} 
      

int main()
{
    vector<int> v = {2,0,2,1,1,0};
    sortColors(v);
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    
    return 0;
}
