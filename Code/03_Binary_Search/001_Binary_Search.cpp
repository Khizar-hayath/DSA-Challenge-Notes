//PROBLEM: Binary Search
//EXAMPLE: I/P: [4, 6, 8, 10, 12] target = 6           O/P: 1 

#include <iostream>
#include <vector>
using namespace std;



//Soln: Binary search is like guessing a number someone picked by always starting in the middle, then deciding whether to look higher or lower, cutting the choices in half each time until you find it
//- TC ⏱️: O (logN) (to base 2)

int search(vector<int>& nums, int target) {
  int low = 0, high = nums.size() - 1;
  while(low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] == target) return mid;
    else if(target > nums[mid]) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}

int main() {
  int n, target;
  cout << "Enter number of elements in the array: ";
  cin >> n;

  cout << "Enter target element: ";
  cin >> target;

  vector<int> nums(n);
  cout << "Enter elements in the array: ";
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }


  int result = search(nums, target);
  cout << "Index of the target element is: " << result << endl;

  return 0;
}
