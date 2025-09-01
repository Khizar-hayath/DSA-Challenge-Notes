//PROBLEM: Longest subarray with sum k | Array has 0 & -ve nos 
//EXAMPLE: I/P: [1,1,0,1,1,1,0,1,1], k=3 -> O/P: [0,1,1,1,0] length = 5 

#include <bits/stdc++.h>
using namespace std;


// BRUTE SOLUTION 
//SOLN: Check all possible sub-arrays sum and compare with the required sum using 2 loops 
//- TC ⏱️: O(n^2) 
//- SC 🧾: O(1) 
int left_subarray_with_SumK_brute(vector<int> &a, int k){
  int n = a.size();
  long long sum = 0;
  int len = 0;

  for(int i =0; i<n; i++){
    int sum = 0;
    for(int j = i; j<n; j++){
      sum+=a[j];
      if(sum == k) len = max(len, j-i+1);
    }
  }
  return len;
}

// OPTIMAL SOLUTION 
//SOLN: Keep track of prefix sums and use a map to check if we’ve seen the required sum before to find the longest subarray 
//- TC ⏱️: O(N*log(N)) -> log N for map 
//- SC 🧾: O(N) 
int lSubarrayWithSumK(vector<int> a, long long k){
  map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;

  for(int i = 0; i<a.size(); i++){
    sum+=a[i];
    if(sum == k){   //Remember: If the whole array is perfect sum
      maxLen = max(maxLen, i+1);
      return maxLen;
    }

    int rem = sum - k;

    if(preSumMap.find(rem) != preSumMap.end()){
      int len = i - preSumMap[rem];
      maxLen = max(maxLen, len);
    }
    preSumMap[sum] = i;
  }
  return maxLen;
}


int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in the array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  cout << "Longest subarray with sum k is of length: ";
  cout << lSubarrayWithSumK(arr, n);
}