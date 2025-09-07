//PROBLEM: Longest consecutive sequence 
//EXAMPLE: I/P: [102,4,100,1,101,3,2,1,1]   O/P: 4 

#include <bits/stdc++.h>
using namespace std;


//BRUTE SOLUTION -  
//Soln: Use 2 loops and do linear search on all of the elements 
//- TC ⏱️: O(N^3) 
//- SC 🧾: O(1) 
void longest_consecutive_seq_brute(){
// Use 2 loops and do linear search on all of the elements  
}


//BETTER SOLUTION  
//Soln: Sort the array and check if current num is exact successor of the prev num. Use current_counter for temp loop, and longest for result ans 
//- TC ⏱️: O(N log N + N) 
//- SC 🧾: O(1) if sorting is allowed or O(N) if extra array copy is made 
int longest_consecutive_seq_better(vector<int>& nums, int n){
  if (n == 0) return 0;

  sort(nums.begin(), nums.end());
  int last_num = INT_MIN;
  int cnt = 0;
  int longest = 1;

  for(int i=0; i<n; i++){
    if(nums[i] - 1 == last_num){   // If the current num is successor of prev num 
      cnt += 1;
      last_num = nums[i];
    }
    else if(last_num != nums[i]){   //If last_num is different from current num also skips duplication
      cnt = 1;
      last_num = nums[i];
    }
    longest = max(longest, cnt);
  }

  return longest;
}


//NOTE: We use "SET" to search elements with TC -> O(1). Same linear search takes O(N) time 
//OPTIMAL SOLUTION  
//Soln: Put all elements into set, and only start counting when (num-1) is not present. Then count the length of that sequence. 
//- TC ⏱️: O(N) on average 
//- SC 🧾: O(N) 
int longest_consecutive_seq_optimal(vector<int>& nums, int n) {
  if (n == 0) return 0;

  int longest = 1;
  unordered_set<int> st;

  for (int i = 0; i < n; i++) {
    st.insert(nums[i]);
  }

  for (auto it : st) {
    if (it == INT_MIN || st.find(it - 1) == st.end()) {
      int cnt = 1;
      int x = it;
      while (x < INT_MAX && st.find(x + 1) != st.end()) {
          x = x + 1;
          cnt = cnt + 1;
      }
      longest = max(longest, cnt);
    }
  }
  return longest;
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

  cout << longest_consecutive_seq_better(arr, n);


}
