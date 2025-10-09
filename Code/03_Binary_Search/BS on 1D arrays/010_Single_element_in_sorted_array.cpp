//PROBLEM: Single element in sorted array 
//Soln: Keep checking the middle number and its neighbor, moving right if they’re a pair and left if not, until one number remains 
//EXAMPLE: I/P: nums = [1,1,2,3,3,4,4,8,8]     O/P: 2 

#include <iostream>
#include <vector>
using namespace std;


//- TC ⏱️: O (log N)
int singleNonDuplicate(vector<int>& nums) {
  int low = 0, high = nums.size() - 1;

  while(low < high) {
    int mid = (low + high)/2;

    if(mid % 2 == 1) mid--;

    if(nums[mid] == nums[mid + 1]) {
      low = mid + 2;
    } else {
      high = mid;
    }
  }
  return nums[low];
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

  int res = singleNonDuplicate(arr);

  cout << res;
}