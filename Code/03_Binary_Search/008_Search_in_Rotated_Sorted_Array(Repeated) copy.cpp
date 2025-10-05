//PROBLEM: Find Minimum in Rotated Sorted Array 
//Soln: Look for the smallest number by checking the middle and moving to the side that isn’t in order until you find it 
//EXAMPLE: I/P: nums = [3,4,5,1,2]      O/P: 1 (It's smallest) 

#include <iostream>
#include <vector>
using namespace std;


//- TC ⏱️: O (log N) (to base 2) 
int findMin(vector<int>& nums) {
  int n = nums.size();
  int low = 0, high = n - 1, ans = INT_MAX;

  while(low <= high){
    int mid = (low + high) / 2;

    if(nums[low] <= nums[mid]){
      ans = min(ans, nums[low]);
      low = mid + 1;
    }
    else{
      ans = min(ans,nums[mid]);
      high = mid - 1;
    }
  }

  return ans;
}


int main(){
  int n, x;
  cout << "Enter number of elements in the array: ";
  cin >> n;

  cout << "Enter elements in the array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  int res = findMin(arr);

  cout << res;
}