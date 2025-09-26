//PROBLEM: Number of Subarrays with XOR K 
//EXAMPLE: I/P: [4, 2, 2, 6, 4] k = 6           O/P: 4 

#include <iostream>
#include <vector>
#include <map>
using namespace std;



//OPTIMAL SOLUTION 
//Soln: Go through the array while keeping a running XOR of numbers, and for each step, check how many previous XORs would make the current XOR equal to k. Add those to the count.
//- TC ⏱️: O(N) or O(N logN) 
//- SC 🧾: O(N) 
int subarray_with_sum_k(vector<int>& nums, int k){
  int n = nums.size();
  int xr = 0;
  map<int,int> mpp;
  mpp[xr]++;
  int cnt = 0;

  for(int i=0; i<n; i++){
    xr  = xr ^ nums[i];

    int x = xr ^ k;
    cnt += mpp[x];
    mpp[xr]++;
  }
 
  return cnt;
}

int main() {
  int n, k;
  cout << "Enter number of elements in the array: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter elements in the array: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Enter value of k: ";
  cin >> k;

  int result = subarray_with_sum_k(arr, k);
  cout << "Number of subarrays with XOR " << k << " is: " << result << endl;

  return 0;
}
