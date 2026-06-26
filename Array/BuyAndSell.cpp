//Given prices of shares for a particular period.to determine the maximum profits we can make by buying and selling of these shares. max profits can be achieved only if we purchase the share at a lower rate and sell it for a higher rate. For eg if price in previous week were {9,5,2,0,6,8,1}. if the price is 0, it indicates that the market is closed and buying or selling of share is not possible also note that buying should preceed selling. Also we cannot buy the share on last day as we are not able to sell it. Note that if we are unable tio make profit then max profit will be 0

#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(vector<int> &arr){
  int buyPrice = INT_MAX;
  int maxProfit = 0;

  for(int i= 0; i<arr.size();i++){

    if(arr[i]==0){
      continue;
    }
    maxProfit = max(maxProfit,arr[i]-buyPrice);
    if (i != arr.size() - 1) {
            buyPrice = min(buyPrice, arr[i]);
        }
  }
  return maxProfit;
}

int main() {
    vector<int> arr = {9, 5, 2, 0, 6, 8, 1};

    cout << "Maximum Profit = " << getMaxProfit(arr) << endl;

    return 0;
}

