//TITLE: Left rotate the array by D places 
//EXAMPLE: I/P: [1,2,3,4], d=1  -> O/P [2,3,4,1] 

#include <bits/stdc++.h>
using namespace std;


//BRUTE SOLUTION 
//SOLN: Store d elements in temp array | Move elements by d places to right | Place values from temp array into original array 
//- TC: O(n+d) 
//- SC: O(d) 
void left_rotate_dplaces_brute(vector<int>& arr, int n, int d){
  vector<int> temp;

  d = d % n;                          //NOTE: Because after 1 full rotation, the array remains same. Therefore finding remainder 

  for(int i = 0; i < d; i++){
    temp.push_back(arr[i]);
  }

  for(int i = d; i < n; i++){
    arr[i - d] = arr[i];
  }

  for(int i = n-d; i<n; i++){
    arr[i] = temp[i - (n-d)];
  }
}

//OPTIMAL SOLUTION 
//SOLN: Rotate first d elements, then remaining n-d elements and finally rotate the whole array. Boom!! You found the answer 
//- TC: O(2n) 
//- SC: O(1) No extra space used 
void left_rotate_dplaces_optimal(vector<int>& arr, int n, int d){
  d = d % n;

  reverse(arr.begin(), arr.begin() + d);
  reverse(arr.begin()+d, arr.end());
  reverse(arr.begin(), arr.end());
}


//! Learn to right rotate an array by d places too
void right_rotate_dplaces(vector<int> &nums, int k){
  int n = nums.size();
  k = k%n;
  reverse(nums.begin(), nums.begin()+(n-k));
  reverse(nums.begin()+(n-k), nums.end());
  reverse(nums.begin(), nums.end());
}


int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;
  cout << "Enter no of places array to rotate by: ";
  int d;
  cin >> d;

  cout << "Enter elements in array: ";
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin >> arr[i];

  cout << "Left rotated array is: ";
  left_rotate_dplaces_optimal(arr, n, d);
  for(int i = 0; i < n; i++){
    cout << arr[i] << "  ";
  }
} 