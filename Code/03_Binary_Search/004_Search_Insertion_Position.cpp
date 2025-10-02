//PROBLEM: Upper Bound 
//Soln: Smallest index such that arr[ind] > x 
//EXAMPLE: I/P: [2, 3, 4, 5, 6] x = 3        O/P: 2 

#include <iostream>
#include <vector>
using namespace std;


//- TC ⏱️: O (logN) (to base 2) 
int searchInsert(vector<int>& nums, int target) {
  int n = nums.size();
  int low = 0, high = n-1;

  while(low <= high){
    int mid = (low + high) / 2;

    if(target == nums[mid]) return mid;
    else if(nums[mid] > target) high = mid - 1;
    else low = mid + 1;
  }
  
return low;
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

  int res = searchInsert(arr, n);
  cout << res;
}