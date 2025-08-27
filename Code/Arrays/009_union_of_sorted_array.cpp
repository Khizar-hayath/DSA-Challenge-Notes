//PROBLEM: Union of sorted array 
//EXAMPLE: I/P: arr1 = [1,2,3,4] arr2 = [3,4,5,6]  -> O/P [1,2,3,4,5,6] 


#include <bits/stdc++.h>
using namespace std;

// BRUTE solution
//SOLN: Store elements in set - Set contains only unique elements 
//- TC ⏱️: O(n1 log n + n2 log n) + O(n1 + n2) - where n -> Size of set st 
//- SC 🧾: O(n1 + n2) + [O(n1 + n2)] -> Used to return answer 
vector<int> find_union_brute(vector<int> &arr1, vector<int> &arr2, int n1, int n2)
{
  set<int> st;

  // Add nos from arr1 to set
  for (int i = 0; i < n1; i++)
    st.insert(arr1[i]);

  // Add nos from arr2 to set
  for (int i = 0; i < n2; i++)
    st.insert(arr2[i]);

  vector<int> un;

  // Add nos from set to new "union array" 
  for (auto it : st)                                                              // Remember: variable names may get confusing
  {
    un.push_back(it);
  }
  return un;
}

// OPTIMAL SOLUTION - Two pointer approach 
//SOLN: Iterate in both the arrays and place the smallest one in unionArray, also avoid duplicate values 
//- TC ⏱️: O(n1+n2) 
//- SC 🧾: O(n1+n2) -> To return answer 
vector<int> find_union_optimal(vector<int> &arr1, vector<int> &arr2, int n1, int n2)
{
  vector<int> unArr;
  int i = 0;
  int j = 0;
  while(i<n1 && j<n2){
    if(arr1[i] <= arr2[j]){
      if(unArr.size() == 0 || unArr.back() != arr1[i]){       //! First check if size is zero (Don't interchange), else it returns undefined
        unArr.push_back(arr1[i]);
      }
      i++;
    }
    else{
      if(unArr.size() == 0 || unArr.back() != arr2[j]){
        unArr.push_back(arr2[j]);
      }
      j++;
    }
  }

  //If any elements are left in arr1 or arr2
  while(i<n1){
    if(unArr.size() == 0 || unArr.back() != arr1[i]){ 
      unArr.push_back(arr1[i]);
    }
    i++;
  }

  while(j<n2){
    if(unArr.size() == 0 || unArr.back() != arr2[j]){
      unArr.push_back(arr2[j]);
    }
    j++;
  }

  return unArr;
}


int main()
{
  cout << "Enter number of elements in array 1: ";
  int n1, n2;
  cin >> n1;

  cout << "Enter number of elements in array 2: ";
  cin >> n2;

  cout << "Enter elements in array 1: ";
  vector<int> arr1(n1);
  for (int i = 0; i < n1; i++)
  {
    cin >> arr1[i];
  }

  cout << "Enter elements in array 2: ";
  vector<int> arr2(n2);
  for (int i = 0; i < n2; i++)
  {
    cin >> arr2[i];
  }

  cout << "The union of both arrays is: ";
  vector<int> result = find_union_optimal(arr1, arr2, n1, n2);

  for (auto it : result)
  {
    cout << it << " ";
  }
}