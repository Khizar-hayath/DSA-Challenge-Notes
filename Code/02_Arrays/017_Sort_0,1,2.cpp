//PROBLEM: Sort an array of 0's, 1's and 2's 
//EXAMPLE: I/P: [1,2,0,2,1,2,0,0,1]        O/P: [0,0,0,1,1,1,2,2] 

#include <bits/stdc++.h>
using namespace std;


//BRUTE SOLUTION - Sorting 
//Soln: Sort the array, that's the answer 
//- TC ⏱️: N(log N) 
//- SC 🧾: O(log N) 
//! Check Space Complexity here, why N?
void a(vector<int> &arr, int n){
  sort(arr.begin(), arr.end());
}


//BETTER SOLUTION 
//Soln: Use of 3 counter variables to count no of 0,1,2 in the array and then place them in original array 
//- TC ⏱️:  O(2N)
//- SC 🧾:  O(1)
vector<int> sort_012_better(vector<int>& arr){
  int cnt0 = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  int n = arr.size();

  for(int i=0; i<n; i++){
    if(arr[i] == 0) cnt0++;
    else if(arr[i] == 1) cnt1++;
    else if(arr[i] == 2) cnt2++;
  }
                                                                  //! Mind the rage in the below for loops
  for(int i=0; i<cnt0; i++) arr[i] = 0;
  for(int i=cnt0; i<cnt0 + cnt1; i++) arr[i] = 1;
  for(int i=cnt0+cnt1; i<n; i++) arr[i] = 2;

  return arr;
}


//OPTIMAL SOLUTION - Dutch National Flag Algorithm 
//Soln: Check the numbers in the unsorted array using "if" condition, move pointers ahead if val == 0,1. Move pointer back if val == 2 
//- TC ⏱️: O(N) 
//- SC 🧾: O(1) 
void sort_012_optimal(vector<int>& arr, int n){
  int low=0, mid=0, high=n-1;
  while(mid <= high){
    //Remember: We are checking based on arr[mid] only 
    if(arr[mid] == 0){
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    }

    else if(arr[mid] == 1){
      mid++;
    }

    else{
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}



int main(){
  int n;
  cout << "Enter the number of elements in array: ";
  cin >> n;

  cout << "Enter elements in the array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  sort_012_optimal(arr, n); //! No need of return value of nothing is assigned while calling the function 

  for(int i=0; i<n; i++){
    cout << arr[i] <<" ";
  }
}