//PROBLEM: Longest subarray with sum k | Natural nos only 
//EXAMPLE: I/P: [7,1,3,1,1,1,2,1,2], k=3 -> O/P: [1,1,1] length = 3 

#include <bits/stdc++.h>
using namespace std;



// BRUTE SOLUTION 
//- TC ⏱️: O(n^2) 
//- SC 🧾: O(1) 
//SOLN: Check all possible sub-arrays sum and compare with the required sum using 2 loops 
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


//BETTER SOLUTION - Hashing 
//- TC ⏱️: O(N*log(N)) -> log N for map 
//- SC 🧾: O(N) 
//SOLN: Keep track of prefix sums and use a map to check if we’ve seen the required sum before to find the longest subarray 
int left_subarray_with_SumK_better(vector<int> a, long long k){
  map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;

  for(int i = 0; i<a.size(); i++){
    sum+=a[i];
    if(sum == k){   //Remember: If the whole array is perfect sum
      maxLen = max(maxLen, i+1);
    }

    int rem = sum - k;

    if(preSumMap.find(rem) != preSumMap.end()){
      int len = i - preSumMap[rem];
      maxLen = max(maxLen, len);
    }

    if (preSumMap.find(sum) == preSumMap.end()) {
      preSumMap[sum] = i; // store only first occurrence
    }
  }
  return maxLen;
}
//! if(map.find(value) != map.end())-> This line checks whether the key `value` is present in the map 



// OPTIMAL SOLUTION 
//- TC ⏱️: O(2*N) 
//- SC 🧾: O(1) 
//SOLN: Use two pointers to grow and shrink the imaginar array until its sum matches k and track the maximum length.
int left_subarray_with_SumK_optimal(vector<int> a, long long k){
  int left = 0, right = 0;
  long long sum = 0;
  int maxLen = 0;
  int n = a.size();


  while(right < n) {
    sum += a[right];  //Doing from first index  

    while(sum > k){
      sum -= a[left];
      left++;
    }

    if(sum == k){
      maxLen = max(maxLen, right-left+1);
    }

    right++;
  }
  return maxLen;
}



int main(){
  int n;
  long long k;

  cout << "Enter number of elements in array: ";
  cin >> n;

  cout << "Enter elements in the array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  cout << "Enter sum of elements to be found in array: ";
  cin >> k;

  cout << "Longest subarray with sum k is of length: ";
  cout << left_subarray_with_SumK_brute(arr, k);
}