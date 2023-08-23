#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr, int n) {
    //code here.
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    cout << largestElement(v,5);

    return 0;
}
