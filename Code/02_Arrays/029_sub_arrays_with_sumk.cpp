//PROBLEM: Number of sub-arrays with sum k 
//EXAMPLE:I/P: a = [1, 2, 3], k = 3            O/P: 2  ([1,2] and [3]) 

#include <bits/stdc++.h>
using namespace std;


// BRUTE SOLUTION 
//- TC ⏱️: O(n^3) 
//- SC 🧾: O(1) 
//SOLN: Check all possible sub-arrays with sum and compare with the required sum using 3 loops. If matches increase counter 
int left_subarray_with_SumK_brute(vector<int> &a, int k){
  int n = a.size();
  int cnt = 0;

  for(int i =0; i<n; i++){
    for(int j = i; j<n; j++){
      int sum = 0;
      for(int l=i; l<j; l++) sum+=a[l];
      if(sum == k) cnt++;
    }
  }
  return cnt;
}

// BETTER SOLUTION 
//- TC ⏱️: O(n^2) 
//- SC 🧾: O(1) 
//SOLN: Check all possible sub-arrays with sum and compare with the required sum using 2 loops. Igf matches increase counter 
int left_subarray_with_SumK_brute(vector<int> &a, int k){
  int n = a.size();
  int cnt = 0;

  for(int i =0; i<n; i++){
    int sum = 0;
    for(int j = i; j<n; j++){
      sum+=a[j];
      if(sum == k) cnt++;
    }
  }
  return cnt;
}


//OPTIMAL SOLUTION - Hashing 
//Soln: Keep track of prefix sums and use a map to check if we’ve seen the required sum before to find the longest subarray 
//- TC ⏱️: O(N*logN) 
//- SC 🧾: O(N) 
int a_optimal(vector<int>& nums, int n, int k){
  map<int,int> mpp;
  mpp[0] = 1;
  int preSum = 0, cnt = 0;

  for(int i=0; i<n; i++){
    preSum += nums[i];
    int remove = preSum - k;
    cnt += mpp[remove];   //! Count number of prefix with remove as the required sum. 
    mpp[preSum] += 1;
  }
  return cnt;
}