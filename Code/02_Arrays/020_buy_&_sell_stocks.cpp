//PROBLEM: Buy and sell stocks 
//EXAMPLE: I/P: [7,1,5,3,6,4]           O/P: 5 (This is max profit, buy -> 1 | sell -> 6) 

#include <bits/stdc++.h>
using namespace std;



//OPTIMAL SOLUTION 
//Soln: Try selling everyday in array and claculate profit. If stock price is is less, initialise it as min stock price. Use this min price as buying price to maximise the profit. 
//- TC ⏱️: O(N) 
//- SC 🧾: O(1) 
int buy_sell_stocks_optimal(vector<int>& nums, int n){
  int profit = 0, mini = nums[0];
  for(int i=0; i<n; i++){
    int cost = nums[i] - mini;      //Potential profit if we sell now 

    profit=max(profit, cost);
    mini=min(mini, nums[i]);
  }
  return profit;
}



int main(){
  int n;
  cout << "Enter number of elements in the array: ";
  cin >> n;

  cout << "Enter elements in the array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  cout << "The profit is: " << buy_sell_stocks_optimal(arr, n);
}






//!! My wrong solutions (It's here so you know what are the mistakes to avoid)
//err ❌ WRONG SOLUTION 1
int buy_sell_stocks(vector<int> &nums, int n){ //Attempt 1
  int buy=0, sell=0;
  int index = 0;
  //Find minimum number in array (until 2nd last element)
  for(int i=1; i<n-1; i++){
    if(nums[i-1] < nums[i]){
      buy = nums[i-1];
    }
    index = i+1;
  }

  //Find max element after min buying element in the array
  for(int j=index; j<n; j++){
    if(nums[j] > buy) sell = nums[j];
  }
  
  return sell - buy;
}


//err ❌ WRONG SOLUTION 2
int buy_sell_two_pass(vector<int>& nums, int n) { //Attempt 2
  int minIndex = 0;
  for (int i = 1; i < n; i++) {
    if (nums[i] < nums[minIndex]) {
      minIndex = i;
    }
  }

  int maxPrice = nums[minIndex];
  for (int j = minIndex + 1; j < n; j++) {
    if (nums[j] > maxPrice) {
      maxPrice = nums[j];
    }
  }

  return maxPrice - nums[minIndex];
}


//! To find max only 2 adjucent elements are scanned, not all of the elements
//! Finding global min, and then evaluating based on maximum difference after global min 
//! We neither require random global min nor g-max. We only require max differennce