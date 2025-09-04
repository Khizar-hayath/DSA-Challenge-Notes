//PROBLEM: Rearrange Array Elements by sign (unequal elements)
//EXAMPLE: I/P: [3,1,-2,-5,2,-4,2,3]         O/P: [3,-2,1,-5,2,-4,2,3] 

#include <bits/stdc++.h>
using namespace std;


//BRUTE SOLUTION 1 
//Soln: Rearranging elements assuming there are un-equal nos in array 
//- TC ⏱️: O(2N) 
//- SC 🧾: O(N) 
vector<int> rearrange_by_sign_b1(vector<int> &nums, int n){
  vector<int> pos;
  vector<int> neg;

  for(int x: nums){
    if(x > 0) pos.push_back(x);
    else neg.push_back(x);
  }

  int i=0, j=0, k=0;
  while(i<pos.size() && j<neg.size()){
    nums[k++] = pos[i++];
    nums[k++] = neg[j++];
  }

  while(i < pos.size()) nums[k++] = pos[i++];
  while(j < neg.size()) nums[k++] = neg[j++];

  return nums;
}


//BRUTE SOLUTION 2 
//SOLN: Different approach using for loop and indexes
//- TC ⏱️: O(2N) 
//- SC 🧾: O(N) 
vector<int> rearrange_by_sign_b2(vector<int> &nums, int n){
  vector<int> pos;
  vector<int> neg;

  for(int i=0; i<n; i++){
    if(nums[i] > 0) pos.push_back(nums[i]);
    else neg.push_back(nums[i]);
  }

  if(pos.size() > neg.size()){
    //Initialisation of equal +ves and -ves
    for(int i=0; i<neg.size(); i++){                                              //Remember: It's "i<neg.size()" because it has min length 
      nums[2*i] = pos[i];
      nums[2*i + 1] = neg[i];
    }

    //Adding extra  +ves or -ves
    int index = neg.size() * 2;               //(*2) bcz, we r adding 1 element from +ve array and other from -ve array
    for(int i=neg.size(); i<pos.size(); i++){                                         //Loop for tracing extra positive os in +ve array
      nums[index] = pos[i];
      index++;
    }
  }
  
  else{
    for(int i=0; i<pos.size(); i++){
      nums[2*i] = pos[i];
      nums[2*i + 1] = neg[i];
    }

    int index = pos.size() * 2;               
    for(int i=pos.size(); i<neg.size(); i++){
      nums[index] = neg[i];
      index++;
    }
  }
  return nums;
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

  vector<int> newArr = rearrange_by_sign_b1(arr, n);

  for(int i=0; i<n; i++){
    cout << newArr[i] <<" ";
  }
}