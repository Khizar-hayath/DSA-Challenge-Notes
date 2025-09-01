//TITLE: Merge sort 
//DEFN: Here we keep splitting the array into smaller parts until each part has one item, then merge them back together in the correct order.
//- TC ⏱️: O(n log n) -> Worst, Avg, Best case
//- SC 🧾: O(n)

#include <bits/stdc++.h>
using namespace std;

void merge(vector <int> &arr, int low, int mid, int high) {
  vector<int> temp;
  int left = low;
  int right = mid + 1;
  // Merge both halves in sorted order
  while(left <= mid && right <= high){
    if(arr[left] <= arr[right]){
      temp.push_back(arr[left]);
      left++;                                                                          //Remember
    }
    else{
      temp.push_back(arr[right]);
      right++;                                                                         //Remember
    }
  };

  // Copy remaining elements from left half (if any)
  while(left <= mid){
    temp.push_back(arr[left]);
    left++;
  }

  // Copy remaining elements from right half (if any)
  while(right <= high){
    temp.push_back(arr[right]);
    right++;
  }

  //Sorted elements back to original array
  for(int i = low; i <= high; i++){
    arr[i] = temp[i - low];                                                             //Remember
  }
}

void merge_sort(vector <int> &arr, int low, int high){
  if(low >= high) return;
  int mid = (low + high ) / 2;
  merge_sort(arr, low, mid);              
  merge_sort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in array: ";
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin >> arr[i];

  merge_sort(arr, 0, arr.size() - 1);
  cout << "Sorted Array is: ";
  for(int i = 0; i < n; i++) cout << arr[i] << "  ";
}