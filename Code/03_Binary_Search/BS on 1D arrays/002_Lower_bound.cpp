//PROBLEM: Lower Bound 
//Soln: Smallest index such that arr[ind] >= x 
//EXAMPLE: I/P: [2, 3, 4, 5, 6] x = 3        O/P: 1 

#include <iostream>
#include <vector>
using namespace std;


//- TC ⏱️: O (logN) (to base 2) 
// There may be only 2 cases: Maybe an answer, cannot be an answer.

int lower_bound_bs(vector<int> &nums, int n, int x){
  int low = 0, high = n;
  int ans = n;
  while(low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] >= x) {               //Maybe an answer in left 
      ans = mid;
      high = mid-1;                    //Looking smaller index
    }
    else low = mid+1;                  //No, search in right!
  }

//Remember shortcut:  int lb = lower_bound(nums.begin(), nums.begin() + 3, x) - nums.begin(); // lower_bound returns iterator

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

  int res = lower_bound_bs(arr, n, x);

  cout << res;
}