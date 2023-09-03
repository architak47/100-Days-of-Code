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

int count(vector<int>& arr, int n, int x) {
    int first = firstOcc(arr, n, x);
    if (first == -1) return 0;
    int last = lastOcc(arr, n, x);
    return (last - first + 1);
}


int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, x = 8;
    int ans = count(arr, n, x);
    cout << "The number of occurrences is: "<< ans << "\n";
    return 0;
}
