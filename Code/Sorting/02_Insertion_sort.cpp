//TITLE: Insertion sort 
//DEFN: It is a method where you take one item at a time and insert it into its correct position among the already sorted items. 
//- TC ⏱️: O(n^2) -> Worst, Avg case           O(n) -> Best case 
//- SC 🧾: O(1) 

#include<bits/stdc++.h>
using namespace std;


void insertion_sort(int arr[], int n){
  for(int i = 0; i <= n-1; i++){
    int j = i;
    while(j > 0 && arr[j-1] > arr[j]){
      // Swap
      int temp = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = temp;

      j--;                                   //Internal swap of nos until they reach req position
    }
  }

  /*
  //NOTE: Alternative wrong apprach: 
    int j = i;
    while(j >= 0 && arr[j] > arr[j+1]){
!   here j+1 goes out of bond, only use j-1 and j.
  */
}

int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in array: ";
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];

  insertion_sort(arr, n);
  cout << "Sorted Array is: ";
  for(int i = 0; i < n; i++) cout << arr[i] << "  ";
}