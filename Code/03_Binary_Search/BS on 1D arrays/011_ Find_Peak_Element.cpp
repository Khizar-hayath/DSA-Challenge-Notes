//PROBLEM: Find peak element
//Soln: Check numbers at a[i-1] and a[i+1] to decide 
//EXAMPLE: I/P: nums = [1,1,2,3,3,4,4,8,8]     O/P: 2 

#include <iostream>
#include <vector>
using namespace std;


//- TC ⏱️: O (log N)
int findPeakElement(vector<int>& nums) {
  int n = nums.size();

  if(n == 1) return 0;
  if(nums[0] > nums[1]) return 0;
  if(nums[n-1] > nums[n-2]) return n-1;

  int low = 1, high = n-2;
  
  while(low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
    else if(nums[mid] > nums[mid - 1]) low = mid + 1;
    else if(nums[mid] > nums[mid + 1]) high = mid - 1;
    else low = mid + 1;
  }
  return -1;
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

  int res = findPeakElement(arr);

  cout << res;
}