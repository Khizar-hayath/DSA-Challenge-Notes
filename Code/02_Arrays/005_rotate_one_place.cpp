//TITLE: ROATATE ARRAY BY 1 PLACE 
//EXAMPLE: I/P: [1,2,3,4]  -> O/P [2,3,4,1]
//SOLN: Store first element in temp, move all elements 1 index befor and place temp at last index 
//- TC: O(n) 
//- SC: O(1) 

#include <bits/stdc++.h>
using namespace std;


void left_rotate_1_place(vector<int>& arr, int n){
  int temp = arr[0];
  
  for(int i = 1; i<n; i++){
    arr[i - 1] = arr[i];
  }
  arr[n] = temp;
}


int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in array: ";
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin >> arr[i];

  cout << "Left rotated array is: ";
  left_rotate_1_place(arr, n);
  for(int i = 0; i < n; i++){
    cout << arr[i] << "  ";
  }
} 