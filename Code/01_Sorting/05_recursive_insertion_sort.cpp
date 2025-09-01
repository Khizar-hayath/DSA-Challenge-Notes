//TITLE: Recursive Insertion sort 
//DEFN: It is a method where you take one item at a time and insert it into its correct position among the already sorted items. Here function is called again(recursion) to decrease the value of n (instead of loop earlier)
//- TC ⏱️: O(n^2) -> Worst, Avg case           O(n) -> Best case 
//- SC 🧾: O(n)    (Due to recursion)

#include<bits/stdc++.h>
using namespace std;


void insertion_sort(int arr[],int i, int n){
  if(i == n) return;
  
  int j = i;
  while(j > 0 && arr[j-1] > arr[j]){
    // Swap
    int temp = arr[j-1];
    arr[j-1] = arr[j];
    arr[j] = temp;

    j--;                                   //Internal swap of nos until they reach req position
  }
  insertion_sort(arr, i+1, n);             //Value of i is increased
}

int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in array: ";
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];

  insertion_sort(arr, 0, n);
  cout << "Sorted Array is: ";
  for(int i = 0; i < n; i++) cout << arr[i] << "  ";
}