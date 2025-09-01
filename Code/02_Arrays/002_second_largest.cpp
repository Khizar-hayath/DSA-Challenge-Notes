//PROBLEM: Return second largest element in an array 
//EXAMPLE: i/p [2, 4, 6, 8, 9, 33, 4, 66]   o/p: 33

#include <bits/stdc++.h>
using namespace std;


//BRUTE SOLUTION 
//SOLN: Sort the array and Traverse the array from end to find the second largest element 
//- TC ⏱️: O(n + n(log(n))                       (n(log(n) for sorting technique) 
//- SC 🧾: O(1) -> No extra space used 
//NOTE: The array should be sorted/ take externally sorted element
int s_largest_brute(vector<int> arr, int n){
  int largest = arr[n-1];
  for(int i = n-2; i >= 0; i--){
    if(arr[i] != largest){
      int secondlargest = arr[i];
      break;
    }
  }
  return -1;       //Assuming all values are equal
}


//BETTER SOLUTION 
//SOLN: Loop through the array 2 times, first to find largest and then to find second largest element 
//- TC ⏱️: O(2*n) -> for 2 loops
//- SC 🧾: O(1) -> No extra space used 

int s_largest_better(const vector<int>& arr, int n){
  int largest = arr[0];

  for(int i = 0; i < n; i++){
    if(arr[i] > largest){
      largest = arr[i];
    }
  }

  int s_largest = INT_MIN;
  for(int i = 0; i < n; i++){
    if(arr[i] > s_largest && arr[i] != largest){
      s_largest = arr[i];
    }
  }
  return s_largest;
}


//OPTIMAL SOLUTION 
//SOLN: Looping througn the array only one time and declaring largest and second largest num at once 
//- TC ⏱️: O(n) 
//- SC 🧾: O(1) -> No extra space used 

int s_largest_optimal(const vector<int>& arr, int n){
  int largest = INT_MIN;
  int s_largest = arr[0];

  for(int i = 0; i < n; i++){
    if(arr[i] >= largest){
      s_largest = largest;
      largest = arr[i];
    }
    else if(arr[i] < largest && arr[i] > s_largest){
      s_largest = arr[i];
    }
  }
  return s_largest;
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

  cout << "Second largest element is: ";
  cout << s_largest_optimal(arr, n);
}