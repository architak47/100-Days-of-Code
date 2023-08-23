#include <bits/stdc++.h>
using namespace std;

void getSecondOrderElements(int n, vector<int> a) {
    //code here.
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int sec_max = INT_MIN;
    int sec_min = INT_MAX;

    for(int i = 0; i < n; i++){
        if(a[i] > maxi){
            maxi = a[i];
        }
        if(a[i] < mini){
            mini = a[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] > sec_max and a[i] < maxi){
            sec_max = a[i];
        }
        if(a[i] < sec_min and a[i] > mini){
            sec_min = a[i];
        }
    }
    cout << "second minimum :" << sec_min << ' ' << "second maximum :" << sec_max;
}


int main()
{
    vector<int> v = {1,3,5,6,4,2};
    getSecondOrderElements(6, v); 

    return 0;
}
