//PROBLEM: First and Last Position of Element in Sorted Array 
//Soln: Find where the target number first appears and where it last appears in the sorted array using binary search 
//EXAMPLE: Floor I/P: nums = [5,7,7,8,8,10], target = 8        O/P: [3,4] 
//EXAMPLE: Ceil  I/P: nums = [5,7,7,8,8,10], target = 6        O/P: [-1,-1] 

#include <iostream>
#include <vector>
using namespace std;


//- TC ⏱️: O (2 * log N) (to base 2) 
int firstOccurance(vector<int>& nums, int target){
  int n = nums.size();
  int low = 0, high = n - 1;
  int first = -1;
  while(low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] == target){
      first = mid;
      high = mid - 1;
    }
    else if(nums[mid] >= target) high = mid - 1;
    else low = mid + 1;
  }
  return first;
}

int lastOccurance(vector<int>& nums, int target){
  int n = nums.size();
  int low = 0, high = n -1;
  int last = -1;
  while(low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] == target){
      last = mid;
      low = mid + 1;
    }
    else if(nums[mid] >= target) high = mid - 1;
    else low = mid + 1;
  }
  return last;
}

vector<int> searchRange(vector<int>& nums, int target) {
  int first = firstOccurance(nums, target);
  if(first == -1) return {-1,-1};

  int last = lastOccurance(nums, target);
  return {first, last};
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

  vector<int> res = searchRange(arr, x);

  for(auto it: res){
    cout << it << " ";
  }
}