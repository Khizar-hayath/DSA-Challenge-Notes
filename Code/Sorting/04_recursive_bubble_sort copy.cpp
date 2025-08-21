//TITLE: Recursive Bubble Sort
//DEFN: Compare and swap neighbors like usual, but instead of using loops to decrease the value of n. We call the same function again (recursion) until it reaches base case (condition required to stop).
//- TC : O(n^2) -> Worst, Avg case           O(n) -> Best case
//- SC : O(n) 


#include<bits/stdc++.h>
using namespace std;

void recursive_bubble_sort(int arr[], int n){
  if (n == 1) return;

  int did_swap = 0;
    for(int j = 0; j < n-1; j++){
      if(arr[j] > arr[j + 1]){
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        did_swap = 1;
      }
    }

  if (did_swap == 0) return;

  recursive_bubble_sort(arr, n-1);      //Instead of doing backward loop to decrease n everytime, we are using recursion to decrease n
}


int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in array: ";
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];

  recursive_bubble_sort(arr, n);
  cout << "Sorted Array is: ";
  for(int i = 0; i < n; i++) cout << arr[i] << "  ";
}