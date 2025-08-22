//TITLE: Quick sort 
//DEFN: Pick one item as a pivot, put all smaller items on its left and bigger ones on its right, then repeat the same process for each side until everything is sorted 
//- TC ⏱️: O(n*n) -> Worst case                  O(n*log(n)) -> Best & Average case 
//- SC 🧾: O(log n) -> Best & Average            O(n) -> Worst

#include <bits/stdc++.h>
using namespace std;


int f(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i <= high - 1) i++;

        while(arr[j] > pivot && j >= low + 1) j--;
        
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);

    return j;
}

void qs(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = f(arr, low, high);

        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}



int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in array: ";
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin >> arr[i];

  qs(arr, 0, arr.size() - 1);
  cout << "Sorted Array is: ";
  for(int i = 0; i < n; i++) cout << arr[i] << "  ";
}