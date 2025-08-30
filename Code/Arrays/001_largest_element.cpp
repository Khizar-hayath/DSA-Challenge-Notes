//PROBLEM: Largest element in an array
//EXAMPLE: I/P: [1,1,2,6,9,33,4]  -> O/P: 33 


#include <bits/stdc++.h>
using namespace std;

//BRUTE SOLUTION 
//SOLN: Sort the elements and pick the greates one from the end 
//- TC ⏱️: O(n*log(n)) 
//- SC 🧾: O(log(n)) 
int largestElement_brute(vector<int>& nums, int n) {
  //Really basic, can be done
}

//OPTIMAL SOLUTION 
//SOLN: Traverse the array and check if any element is greater than the current largest element.
//- TC ⏱️: O(N) 
//- SC 🧾: O(1) 
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

  cout << "Largest element in the array is: " << largestElement(arr, n);
}