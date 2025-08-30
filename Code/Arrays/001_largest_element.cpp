//PROBLEM: Largest element in an array
//SOLN: Traverse the array and check if any element is greater than the current largest element.
//- TC ⏱️ for optimal: O(n) -> All cases 
//- SC 🧾: O(1) -> All cases

#include <bits/stdc++.h>
using namespace std;

int largestElement_brute(vector<int>& nums, int n) {
  //NOTE: Sort the elements and pick the greates one from the end 
  //- TC ⏱️ for brute: O(n*log(n)) -> All cases 
  //- SC 🧾: O(log(n)) -> All cases
}


int largestElement(vector<int>& nums, int n) {
  int largestnum = nums[0];
  for(int i = 1; i < n; i++){
      if(nums[i] > largestnum){
          largestnum = nums[i];
      }
  }
  return largestnum;
}

int main() {
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in array: ";
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin >> arr[i];
  cout << largestElement(arr, n);
}