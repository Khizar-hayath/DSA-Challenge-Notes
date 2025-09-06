//PROBLEM: Leaders in an array 
//EXAMPLE: I/P: [10,22,12,3,0,6]     O/P: [22,12,6] 

#include <bits/stdc++.h>
using namespace std;


//BRUTE SOLUTION 
//Soln: Run 2 loops and check for num greater than the selected elemt in 1st loop 
//- TC ⏱️: O(N^2) 
//- SC 🧾: O(N) -> To store solution  
vector<int> leaders_in_array_brute(vector<int> &nums, int n){
  vector<int> ans;
  for(int i=0; i<n; i++){
    bool leader = true;   //! Should be true itself in beginning, can't interchange with false here and true below
    for(int j=i+1; j<n; j++){
      if(nums[j] > nums[i]) {
        leader = false;
        break;
      }
    }
    if(leader == true) ans.push_back(nums[i]);
  }

  return ans;
}


//OPTIMAL SOLUTION  
//Soln: Last elmt in array is max elmt | Traverse from end | if nums[i] > max_elmt, add max_elmt in ans array | That nums[i] is new max_elmt
//- TC ⏱️: O(N) 
//- SC 🧾: O(N) -> To store answer 
vector<int> leaders_in_array_optimal(vector<int> &nums, int n){
  int max_el = nums[n-1];
  vector<int> leader;

  leader.push_back(max_el);
  for(int i=n-2; i>=0; i--){
    if(nums[i] > max_el){
      leader.push_back(nums[i]);
      max_el=nums[i];
    }
  }

  reverse(leader.begin(), leader.end());

  return leader;
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

  vector<int> l = leaders_in_array_brute(arr, n);

  for(int i=0; i<l.size(); i++){
    cout << l[i] <<" ";
  }
}