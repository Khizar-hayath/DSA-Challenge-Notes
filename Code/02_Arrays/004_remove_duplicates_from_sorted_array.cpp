//TITLE: REMOVE DUPLICATES IN PLACE FROM SORTED ARRAYS 
//EXAMPLE: I/P: [1,1,1,2,3,4,4,4,5]   O/P: [1,2,3,4,5,1,1,4,4] starting all nos are sorted 

#include <bits/stdc++.h>
using namespace std;


// BRUTE SOLUTION 
//SOLN: Store the nos in set, set cannot have duplicate elements 
//- TC: O(n log n)       - n(log(n)) to store in a set 
//- SC: O(n) 

int remove_duplicate_brute(vector<int> &arr, int n){             //Remember - Pass by arr reference only (&)
  set<int> st;

  for(int i = 0; i<n; i++){
    st.insert(arr[i]);
  }

  int index = 0;
  for(auto it: st){
    arr[index] = it;
    index++;
  }
  return index;
}


// OPTIMAL SOLUTION 
//SOLN: Two pointer approach - i=arr[0] & j=arr[1], j scans the array. When j finds a new unique value, place it after i and move i index forward. This continues until all elements from staring become unique 
//- TC: O(n) 
//- SC: O(1) 
int remove_duplicate_optimal(vector<int> &arr, int n){
  if(n == 0) return 0;
  
  int i = 0; 
  for(int j = 1; j<n; j++){
    if(arr[i] != arr[j]){
      arr[i+1] = arr[j];
      i++;
    }
  }
  return i+1;
}


int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;
  
  cout << "Enter elements in array: ";
  vector<int> arr(n);

  for(int i = 0; i < n; i++) cin >> arr[i];
  int ind = remove_duplicate_brute(arr, n);

  for(int i = 0; i < ind; i++){
    cout << arr[i] << "  ";
  }
}