//PROBLEM: Maximum consecutive 1's in an array
//Soln: Iterate in the array and count no of ones in array, cnt=0 (reset) if there is gap in finding 1 
//- TC ⏱️: O(n)
//- SC 🧾: O(1) 
//EXAMPLE: I/P: [1,1,0,1,1,1,0,1,1]  -> O/P: 3 


#include <bits/stdc++.h>
using namespace std;


int max_ones_in_array(vector<int> &arr, int n){
  int maxi = 0;
  int cnt = 0;
  for(int i = 0; i<n; i++){
    if(arr[i] == 1){
      cnt++;
      maxi = max(cnt, maxi);                                    //NOTE: (OR) if(cnt > maxi) maxi = cnt;
    }
    else cnt = 0;
  }

  return maxi;
}

int main(){
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in the array: ";
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  cout << "The max consecutive 1's in a row are: ";
  cout << max_ones_in_array(a, n);
}