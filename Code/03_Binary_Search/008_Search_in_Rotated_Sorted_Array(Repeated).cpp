//PROBLEM: Search in Rotated Sorted Array II (Repeated nos) 
//Soln: Identify sorted half and apply binary search conditions (do high-- & low++ if nos are repeated) 
//EXAMPLE: I/P: nums = [2,5,6,0,0,1,2], target = 0     O/P: true 

#include <iostream>
#include <vector>
using namespace std;


//- TC ⏱️: O (2 * log N) (to base 2) 
bool search(vector<int>& nums, int target) {
  int n = nums.size();
  int low = 0, high = n - 1;
  while(low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] == target) return true;

    if(nums[low] == nums[mid] && nums[mid] == nums[high]){
      low++;
      high--;
      continue;
    }

    // left sorted
    if(nums[low] <= nums[mid]){
      if(nums[low] <= target && target <= nums[mid]){
        high = mid - 1;
      }
      else low = mid + 1;
    }

    // Right sorted
    else {
      if(nums[mid] <= target && target <= nums[high]){
        low = mid + 1;
      }
      else high = mid - 1;
    }
  }
  return false;
}


int main(){
  int n, x;
  cout << "Enter number of elements in the array: ";
  cin >> n;

  cout << "Enter value of x: ";
  cin >> x;

  cout << "Enter elements in the array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  int res = search(arr, x);

  cout << res;
}