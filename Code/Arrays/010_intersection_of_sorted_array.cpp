//PROBLEM: Intersection of sorted array
//EXAMPLE: I/P: a = [1,2,3,4], b = [2,3,4,5]  -> O/P [2,3,4]

#include <bits/stdc++.h>
using namespace std;


// BRUTE SOLUTION 
//SOLN: For each element in array a, scan through array b until you find a match, mark it as visited in vis array 
//- TC ⏱️: O(n1*n2)
//- SC 🧾: O(n2)  OR O(n1)      depends on size of visitor vector 
vector<int> intersection_brute(vector<int> &a, vector<int> &b, int n1, int n2){
  vector<int> vis(n2, 0);                                                       //Remember: Declaring the vector of size n2 filled with 0
  vector<int> ans;

  for(int i = 0; i<n1; i++){
    for(int j = 0; j<n2; j++){
      if(a[i] == b[j] && vis[j] == 0){
        ans.push_back(b[j]);
        vis[j] = 1;
        break;
      }
      if(b[j] > a[i]) break;   //NOTE: Used to stop loop early - No need to check more (b is sorted), and bigger numbers can't match a[i] 
    }
  }
  return ans;
}


// OPTIMAL SOLUTION 
//SOLN: Move through both sorted arrays at the same time, comparing elements and adding common ones, without going back 
//- TC ⏱️: O(n1+n2) 
//- SC 🧾: O(k) k -> size of ans array 
vector<int> intersection_optimal(vector<int> &a, vector<int> &b, int n1, int n2){
  vector<int> ans;
  int i = 0;
  int j = 0;

  while(i< n1 && j<n2){
    if(a[i] < b[j]) i++;
    else if(a[i] > b[j]) j++;
    else{
      ans.push_back(a[i]);
      i++;
      j++;
    }
  }
  
  return ans;
}



int main(){
  cout << "Enter number of elements in array 1: ";
  int n1, n2;
  cin >> n1;

  cout << "Enter number of elements in array 2: ";
  cin >> n2;

  cout << "Enter elements in array 1: ";
  vector<int> a(n1);
  for (int i = 0; i < n1; i++){
    cin >> a[i];
  }

  cout << "Enter elements in array 2: ";
  vector<int> b(n2);
  for (int i = 0; i < n2; i++){
    cin >> b[i];
  }

  cout << "The intersection of both arrays is: ";
  vector<int> result = intersection_brute(a, b, n1, n2);

  for (auto it : result){
    cout << it << " ";
  }
}