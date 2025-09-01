//PROBLEM: Check if the array is sorted 
//EXAMPLE: i/p [2, 4, 6, 8, 9, 33, 4, 66]   o/p: Not sorted  (OR) Sorted
//SOLN: Loop through the array and check if the prev num is less than or equal to the num ahead 
//- TC ⏱️: O(n) 
//- SC 🧾: O(1) -> No extra space used 

#include <bits/stdc++.h>
using namespace std;


bool is_array_sorted(vector<int> arr, int n){
  for(int i = 1; i<n; i++){
    if(arr[i] < arr[i-1]){
      return false;
    }
  }
  return true;
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

  cout << (is_array_sorted(arr, n) ? "Sorted": "Not sorted");    //Using ternary operator for result
}