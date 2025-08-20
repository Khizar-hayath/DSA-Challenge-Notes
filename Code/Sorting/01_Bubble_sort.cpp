//TITLE: Bubble Sort
//DEFN: It is a method where you keep comparing two neighbors and swap them if they’re in the wrong order, making the biggest items slowly “bubble up” to the end.
//- TC : O(n^2) -> Worst, Avg case           O(n) -> Best case
//- SC : O(0)


#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
  int did_swap = 0;
  for(int i = n-1; i>=1; i--){
    for(int j = 0; j < i; j++){
      if(arr[j] > arr[j + 1]){
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        did_swap = 1;
      }
    }
    if(did_swap == 0){
      break;
    }
    cout << "The given loop is not orderd!!";
  }
}


int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in array: ";
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];

  bubble_sort(arr, n);
  cout << "Sorted Array is: ";
  for(int i = 0; i < n; i++) cout << arr[i] << "  ";
}