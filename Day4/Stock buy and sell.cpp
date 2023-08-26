#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    int buy_price = INT_MAX;

    for(int i = 0; i < prices.size(); i++){
       if(prices[i] < buy_price){
           buy_price = prices[i];
       }
       int temp = prices[i] - buy_price;
       if(profit < temp){
           profit = temp;
       }
    }
    return profit;
}

int main()
{
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);

    return 0;
}
