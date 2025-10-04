//PROBLEM: Search in Rotated Sorted Array 
//Soln: Identify sorted half and apply binary search conditions 
//EXAMPLE: Floor I/P: nums = [4,5,6,7,0,1,2], target = 0      O/P: 4 

#include <iostream>
#include <vector>
using namespace std;

//Remember way to approch problems asking duplicate: Solve the problem for unique case, at end add exception for duplicate case
//- TC ⏱️: O (log N) (to base 2) | worst case: O(N/2)
int search(vector<int>& nums, int target) {
  int n = nums.size();
  int low = 0, high = n - 1;
  while(low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] == target) return mid;

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
  return -1;
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