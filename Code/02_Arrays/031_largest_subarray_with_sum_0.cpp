//PROBLEM: Largest sub-array with sum 0 
//EXAMPLE I/P: {15, -2, 2, -8, 1, 7, 10, 23}        O/P: 5(Subarray is {-2, 2, -8, 1, 7}) 

#include <bits/stdc++.h>
using namespace std;

//OPTIMAL SOLUTION 
//Soln: Use prefix sum + hashmap to track first occurrences and update max length when sum repeats 
//- TC ⏱️: O(N logN) 
//- SC 🧾: O(N) 
int a_optimal(vector<int>& nums, int n){
  unordered_map<int,int> mpp;
  int maxi = 0;
  int sum = 0;

  for(int i=0; i<n; i++){
    sum += nums[i];

    if(sum == 0){
      maxi = i+1;
    }

    else{
      if(mpp.find(sum) != mpp.end()){   //Check if that sum existed in hashmap before  
        maxi = max(maxi, i - mpp[sum]);
      }

      else{
        mpp[sum] = i;
      }
    }
  } 
  return maxi;
}