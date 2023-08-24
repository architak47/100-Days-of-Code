#include <bits/stdc++.h>
using namespace std;

vector < int > sortedArray(vector < int > a, vector < int > b) {
    int size_a = a.size();
    int size_b = b.size();
    vector<int> ans;
    int i = 0, j = 0;

    while(i < size_a and j < size_b){
        if(a[i] < b[j]){
            if(ans.size() == 0 or ans.back() < a[i]){
                ans.push_back(a[i]);
            }
            i++;
        }
        else{
            if(ans.size() == 0 or ans.back() < b[j]){
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    while(i < size_a){
        if(ans.back() < a[i]){
            ans.push_back(a[i]);
        }
        i++;
    }
    while(j < size_b){
        if(ans.back() < b[j]){
            ans.push_back(b[j]);
        }
        j++;
    }

    return ans;
}


int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    
    vector<int> ans = sortedArray(arr1, arr2);
    
    for(auto it : ans) cout << it << ' ';

    return 0;
}
