//PROBLEM: Next permutation 
//EXAMPLE: I/P: [2,1,5,4,3,0,0]     O/P: [2,3,0,0,1,4,5] 

#include <bits/stdc++.h>
using namespace std;


//Soln:Find break index(longest prefix match) | find num > break index (but smallest one of them) | Place remaining elements in sorted order 
//- TC ⏱️: O(3N) 
//- SC 🧾: O(1) 
vector<int> next_permutation(vector<int>& nums, int n){
  int break_index = -1;
  for(int i=n-2; i>=0; i--){       //Remember: It's i>=0 for reverse loop
    if(nums[i] < nums[i+1]){
      break_index = i;
      break;  //!Important
    }
  }

  if(break_index == -1){
    reverse(nums.begin(), nums.end());
    return nums;
  }

  for(int i=n-1; i>break_index; i--){         //Remember: It's i>break_index for reverse loop
    if(nums[i] > nums[break_index]){
      swap(nums[i], nums[break_index]); 
      break;  //!Important
    }  
  }

/*
  NOTE: We assuming that the numbers are in sorted order after break index? Why?
  Remember:The suffix after break_index is always in descending order(bcz of the first loop in above code). Worst case: Only 1 element exists after break_index i.e nums are not in descending order
  ! Ignore mutiple dips and highs in nums before break_index. We don't care(atleast now)
*/

  reverse(nums.begin() + break_index + 1, nums.end());

  return nums;
}



int main(){
  int n;
  cout << "Enter number of elements in the array: ";
  cin >> n;

  cout << "Enter elements in the array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  arr = next_permutation(arr, n);

  for(int i=0; i<n; i++){
    cout << arr[i] <<" ";
  }
}