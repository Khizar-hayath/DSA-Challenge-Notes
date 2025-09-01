//PROBLEM: Sum of 2 nos in array 
//EXAMPLE: I/P: [2,5,8,3,2,1,1]  target=13 k=3 -> O/P: "YES" 

#include <bits/stdc++.h>
using namespace std;

//BRUTE solution - Double loop 
//Soln: Try every possible pair of numbers and see if they add up to the target 
//- TC ⏱️: Almost O(n^2) (A bit less than this, because j loop decreases)
//- SC 🧾: O(1) 
int sum_of_2nos_brute(vector<int> &a, int n, int target){
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){  
      //Remember: if j=0, add "if(i == j) continue;". This method will do extra double checks (not req)
      //if(i == j) continue;
      if(a[i] +a[j] == target) return 1;
    }
  }
  return -1;
}

//BETTER solution - Hashing 
//Soln: Keep a quick list of numbers you’ve seen, and for each new number, check if the matching partner is already there 
//- TC ⏱️: Almost O(N*log N) | Unordered map -> O(N)
//- SC 🧾: O(N) 
vector<int> sum_of_2nos_better(vector<int>& nums, int target){
  map<int,int> mpp;
  int n = nums.size();
  for(int i=0; i<n; i++){
    int num = nums[i];
    int moreReq = target - num;
    if(mpp.find(moreReq) != mpp.end()){
      return {mpp[moreReq], i};
    }
    mpp[num] = i;
  }
  return{-1,-1};
}

//OPTIMAL solution - Two pointer approach 
//Soln: Sort the numbers, then move one pointer from the start and one from the end until you find the right pair.
//- TC ⏱️: O(N*log N) + O(N)
//- SC 🧾: O(1) - No extra space used 
string sum_of_2nos_optimal(vector<int>& a, int n, int target){
  sort(a.begin(), a.end());
  int right = n-1;
  int left = 0;

  while(left < right){
    int sum = a[left] + a[right];

    if(sum < target) left++;
    else if(sum > target) right--;
    else return "YES";
  }

  return "NO";
}



int main(){
  int n, target;
  cout << "Enter the value of n: ";
  cin >> n;

  cout << "Enter target sum: ";
  cin >> target;

  cout << "Enter elements in the array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  cout << sum_of_2nos_optimal(arr, n, target);
}