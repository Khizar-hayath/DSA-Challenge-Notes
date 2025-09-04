//PROBLEM: Rearrange Array Elements by sign (Equal elements) 
//EXAMPLE: I/P: [3,1,-2,-5,2,-4]         O/P: [3,-2,1,-5,2,-4] 

#include <bits/stdc++.h>
using namespace std;


//BRUTE SOLUTION 
//Soln: Using while loop and 3 indexes to iterate and arrange as required 
//- TC ⏱️: O(2N) 
//- SC 🧾: O(N) 
vector<int> a(vector<int> &nums, int n){
  vector<int> pos;
  vector<int> neg;

//NOTE: Modern way of iteration if elements are required, and there is no use of index 
  for(int x: nums){ //x is the element in the array
    if(x > 0) pos.push_back(x);
    else neg.push_back(x);
  }

  int i=0, j=0, k=0;
  while(i<pos.size() && j<neg.size()){                       //NOTE: " while(k < n) " to be used if we assume even no of elements in array
    nums[k++] = pos[i++];
    nums[k++] = neg[j++];
  }

  return nums;
}


//OPTIMAL SOLUTION: 
//Soln: Use only one loop to check if nos are +ve or negative, and assign them at required indexes 
//- TC ⏱️: O(N) 
//- SC 🧾: O(N) 
vector<int> rearrange_by_sign(vector<int> &nums, int n){
  int posIndex = 0;
  int negIndex = 1;
  vector<int> ans(n);   //Presetting the index size

  for(int i=0; i<n; i++){
    if (nums[i] > 0){
      ans[posIndex] = nums[i]; 
      posIndex+=2;
    } 
    else {
      ans[negIndex] = nums[i];
      negIndex+=2;  // Required do after the above step is completed.       //! ans[negIndex+=2] = nums[i]; is wrong
    } 
  }
  return ans;
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

  vector<int> newArr = rearrange_by_sign(arr, n);

  for(int i=0; i<n; i++){
    cout << newArr[i] <<" ";
  }
}