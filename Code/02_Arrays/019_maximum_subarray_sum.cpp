//PROBLEM: Maximum Subarray Sum 
//EXAMPLE: I/P: [-2,-3,4,-1,-2,5,1,-3]           O/P: 7 (from i=2 -> i=6) 

#include <bits/stdc++.h>
using namespace std;


//BRUTE SOLUTION - 3 loops 
//Soln:Checking every subarray and claculating it's sum 
//- TC ⏱️: O(N^3) 
//- SC 🧾: O(1) 
int max_subarray_sum(vector<int> &nums, int n){
  int maxi = INT_MIN;
  for(int i=0; i<n; i++){
    int sum=0;        //! It should reset here itself 
    for(int j=i; j<n; j++){
      for(int k=i; k<=j; k++){
        sum += nums[k];
      }

      if(sum > maxi) maxi = sum;
    }
  }
  return maxi;
}


//BETTER SOLUTION - Double loop 
//Soln: Instead of recalculating sum in inner loop, maintain running sum 
//- TC ⏱️: O(N^2) 
//- SC 🧾: O(1) 
int max_subarray_sum_better(vector<int>& nums, int n){
  int maxi = INT_MIN;
  for(int i=0; i<n; i++){
    int sum=0;
    for(int j=i; j<n; j++){
      sum = sum + nums[j];
      if(sum > maxi) maxi = sum;
    }
  }
  return maxi;
}


//OPTIMAL SOLUTION - Kandane's Algorithm 
//Soln: Start finding sum of nos from beginning, if sum<0 reset the sum to 0 and start the process again. Also have a maxi cntr which stores max sum in every loop 
//- TC ⏱️: O(N) 
//- SC 🧾: O(1) 
int a_optimal(vector<int>& nums, int n){
  int sum=0;
  int maxi = INT_MIN;
  for(int i=0; i<n; i++){
    sum=sum+nums[i];

    if(maxi < sum) maxi = sum;

    if(sum<0) sum=0;
  }
  return maxi;
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

  cout << "The max sum is: " << max_subarray_sum(arr, n);
}