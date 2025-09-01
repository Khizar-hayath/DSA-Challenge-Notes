//PROBLEM: Find the number that appears once and others twice 
//EXAMPLE: I/P: [1,1,2,2,3,3,4]  -> O/P: 4 

#include <bits/stdc++.h>
using namespace std;



// BRUTE SOLUTION 
//SOLN: Linear search with every element in array, if not found again in the array it's ans 
//- TC ⏱️: O(n^2)
//- SC 🧾: O(1) 

int no_appears_once_brute(vector<int> arr, int n){
  for(int i = 0; i<arr.size(); i++){                           //The number to be found  //NOTE: n becuse a number is missing 
    int cnt = 0;                                                //Remember: to be placed here only
    int num = arr[i];
    for(int j = 0; j<arr.size(); j++){         
      if(arr[j] == num){
        cnt++;
      }
    }
    if(cnt == 1) return num;
  }
  return -1;
}


//BETTER SOLUTION 1 
//SOLN: Using hashing | Find max no | Declare hash using max no & use hashing to store index | Retrieve through hash and check if cnt==1 
//- TC ⏱️: O(n) 
//- SC 🧾: O(maxElement in array) (Bigger the number, that many indexes required in hash vector)
int no_appears_once_better(vector<int> arr, int n){
  int maxi = 0;
  for(int i=0;i<n; i++){
    maxi = max(maxi, arr[i]);
  }

  vector<int> hash(maxi+1, 0);

  for(int i=0; i<n; i++){
    hash[arr[i]]++;
  }

  for(int i=0; i<n; i++){
    if(hash[arr[i]] == 1){
      return arr[i];
    }
  }
  return -1;
}


//BETTER SOLUTION 2 
// SOLN: Use an ordered map to count frequency of each number, then return the one with count = 1.
//- TC ⏱️: O(n log M) + O(M) -> where M is size of map 
//- SC 🧾: O(M) -> where M is size of map 
int no_appears_once_better_map(vector<int> arr, int n){
  map<int,int> mpp;
  for(int i=0; i<n; i++){
    mpp[arr[i]]++;
  }

  for(auto it: mpp){
    if(it.second == 1) return it.first;
  }

  return -1;
}


// OPTIMAL SOLUTION 
//SOLN: XOR all the elements, the number present only once is returned as answer 
//- TC ⏱️: O(n) 
//- SC 🧾: O(1) 
//! Two properties of XOR
//!  a ^ a = 0
//!  a ^ 0 = a
int no_appears_once_optimal(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
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

  cout << "The number that appears once is: ";
  cout << no_appears_once_optimal(arr);    //Pass n as parameter if req
}
//! It can also be solved using summation method as done in pev quetion(Q-12)