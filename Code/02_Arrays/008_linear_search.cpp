//PROBLEM: Linear Search 
//EXAMPLE: I/P: [1,2,3,4], d=3  -> O/P: 2 (index of 3) 
//SOLN: Loop through the array to find the number required 
//- TC ⏱️: O(n) 
//- SC 🧾: O(1) 


#include <bits/stdc++.h>
using namespace std;

int linear_search(vector<int> &arr, int n, int d)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == d)
    {
      return i;
    }
  }
  return -1;
}


int main()
{
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int d;
  cout << "Enter number whose index is to be found: ";
  cin >> d;

  cout << "The index of the number is: ";
  cout << linear_search(arr, n, d);
}