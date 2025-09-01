//PROBLEM: Missing number in an array 
//EXAMPLE: I/P: [1,2,3,4]  -> O/P 3 
#include <bits/stdc++.h>
using namespace std;


// BRUTE SOLUTION 
//SOLN: Loop through numbers from 1 to n (since one number is missing) and check if each number exists in the array 

//- TC ⏱️: O(n^2) 
//- SC 🧾: O(1) 
int missing_number_brute(vector<int> arr, int n){
  for(int i = 1; i<=n; i++){                             //The number to be found  //NOTE: n becuse a number is missing 
    int cnt = 0;                                         //Remember: to be placed here only
    for(int j = 0; j<n; j++){
      if(arr[j] == i){
        cnt = 1;
        break;
      }
    }
    if(cnt == 0) return i;
  }
  return -1;
}

//BETTER SOLUTION 
//SOLN: Store index of nos with 1 in hash vector, iterate and find out the answer 
//- TC ⏱️: O(2n) 
//- SC 🧾: O(n) 
int missing_number_better(vector<int> arr, int n){
  // Using hashing
  vector<int> hash(n+1, 0);

  for(int i = 0; i<n; i++){
    hash[arr[i]] = 1;                    //Remember the initialisation of hash as arr[i]
  }

  for(int j = 1; j<=n; j++){
    if(hash[j] == 0){
      return j;
    }
  }
  return -1;
}


// OPTIMAL SOLUTION 1 
//SOLN: Find sum of all numbers in array | Find expected sum using formula | Subtract both of them to find answer 
//- TC ⏱️: O(n) 
//- SC 🧾: O(1) 
int missing_number_optimal_sum(vector<int>& nums, int n) {
  int sum = n*(n+1)/2;
  int s2 = 0;

  for(int i=0; i<n; i++){
    s2 += nums[i];
  }
  return sum - s2;
} 


// OPTIMAL SOLUTION 2 
//SOLN: XOR of all numbers from 1 to n and all array elements leaves missing number 
//- TC ⏱️: O(n) 
//- SC 🧾: O(1) 
//! Two properties of XOR
//!  a ^ a = 0
//!  a ^ 0 = a

int missing_number_optimal_xor(vector<int>& nums, int n) {
  int XOR1 = 0, XOR2 = 0;
  for (int num : nums) {            //num is the value in the array 
    XOR1 = XOR1 ^ num;
  }

  for (int i=1; i<=n; i++) {
    XOR2 = XOR2 ^ i;
  }

  return XOR1 ^ XOR2;
}




int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in the array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  cout << "The missing number in the array is: ";
  cout << missing_number_optimal_sum(arr, n);
}