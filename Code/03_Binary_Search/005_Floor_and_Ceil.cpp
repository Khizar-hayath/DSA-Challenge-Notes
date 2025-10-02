//PROBLEM: Floor and Ceil 
//Soln: Follow 2 conditions: arr[ind] >= x    &     arr[ind] <= x. Return value not index 
//EXAMPLE: Floor I/P: [2, 3, 4, 5, 6] target = 3        O/P: 2 
//EXAMPLE: Ceil  I/P: [2, 3, 4, 5, 6] target = 3        O/P: 4 

#include <iostream>
#include <vector>
using namespace std;


//- TC ⏱️: O (logN) (to base 2) 
int ceil_bs(vector<int> &nums, int target){
  int n = nums.size();
  int low = 0, high = n-1;
  int ans = n;
  while(low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] >= target) {
      ans = mid;
      high = mid-1;
    }
    else low = mid+1;
  }

  return ans;
}


int floor_bs(vector<int> &nums, int target){
  int n = nums.size();
  int low = 0, high = n-1;
  int ans = n;
  int ans = -1;  //no floor exists

  while(low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] <= target) {
      ans = mid;
      low = mid+1;
    }
    else high = mid-1;
  }

  return ans;
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

  int res = ceil_bs(arr, x);

  cout << res;
}