//PROBLEM: Find number of times array is rotated 
//Soln: Track index along with the values in the array. Return index at end 
//EXAMPLE: I/P: nums = [3,4,5,1,2]      O/P: 3 

#include <iostream>
#include <vector>
using namespace std;


//- TC ⏱️: O (log N) (to base 2) 
//BRUTE METHOD 
int times_arr_rot(vector<int>& nums) {
  int n = nums.size();
  int low = 0, high = n - 1;
  int ans = INT_MAX;
  int index = -1;

  while(low <= high){
    int mid = (low + high) / 2;

    if (nums[low] <= nums[high]){    //Already sorted
      if (nums[low] < ans) {
        ans = nums[low];
        index = low;
      } 
      break;
    }

    if(nums[low] <= nums[mid]){     //Left half
      if(nums[low] < ans){
        index = low;
        ans = nums[low];
      }
      low = mid + 1;
    }
    else{      //Right half
      high = mid - 1;
      if(nums[mid] < ans){
        index = mid;
        ans = nums[mid];
      }
    }
  }

  return index;
}

//OPTIMAL METOHOD: No extra checks
int times_arr_rot(vector<int>& nums) {
  int low = 0, high = nums.size() - 1;

  while (low < high) {
    int mid = (low + high) / 2;

    if (nums[mid] > nums[high]) 
      low = mid + 1;
    else high = mid;
  }
  return low; //Remember
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

  int res = times_arr_rot(arr);

  cout << res;
}