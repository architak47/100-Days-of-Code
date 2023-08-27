#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int>&a) {
    int maxi = INT_MIN;
    int n = a.size();
    vector<int> ans;


    for(int i = n-1; i >= 0; i--){
        if(maxi < a[i]){
            maxi = max(a[i],maxi);
            ans.push_back(a[i]);
        }
    }
    sort(begin(ans), end(ans));
    return ans;
}

int main()
{
  int n = 6;
  vector<int> arr = {10, 22, 12, 3, 0, 6};

  vector<int> ans = superiorElements(arr);
  
  
  for(int i = ans.size()-1;i>=0;i--){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;

    return 0;
}
