//PROBLEM: Majority Element (> n/3) 
//EXAMPLE: I/P: nums = [1,1,1,3,3,2,2,2]  O/P: [1,2] 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//OPTIMAL SOLUTION - Boyer–Moore Majority Vote 
//Soln: First finding up to 2 possible nums, then counting their actual frequency to confirm which appear more than ⌊n/3⌋ times 
//- TC ⏱️: O(2N) 
//- SC 🧾: O(1) 
vector<int> a_optimal(vector<int>& nums, int n){
  int cnt1 = 0, cnt2 = 0;
  int el1 = INT_MIN;
  int el2 = INT_MIN;

  for(int i = 0; i < n; i++){
    if(cnt1 == 0 && el2 != nums[i]){
      cnt1 = 1;
      el1 = nums[i];
    }
    else if(cnt2 == 0 && el1 != nums[i]){
      cnt2 = 1;
      el2 = nums[i];
    }

    else if(nums[i] == el1) cnt1++;
    else if(nums[i] == el2) cnt2++;
    else cnt1--, cnt2--;
  }

  int num1 = 0, num2 = 0;
  for(int i=0; i<n; i++){
    if(el1 == nums[i]) num1 ++;
    else if(el2 == nums[i]) num2 ++;
  }

  vector<int> ls;
  int mini = (n/3) + 1;

  if(num1 >= mini) ls.push_back(el1);
  if(num2 >= mini) ls.push_back(el2);

  sort(ls.begin(), ls.end());

  return ls;
}