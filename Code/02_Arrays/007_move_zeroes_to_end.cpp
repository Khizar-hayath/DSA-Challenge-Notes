//TITLE: MOVE ZEROES TO END 
// EXAMPLE: I/P: [0,1,0,3,12] -> O/P: [1,3,12,0,0] 

#include <bits/stdc++.h>
using namespace std;


//BRUTE SOLUTION 
//SOLN: Store first element in temp | Move all elements 1 index before | Place temp at last index 
//- TC: O(n) 
//- SC: O(n) 
void move_zeroes_to_end_brute(vector<int> &arr, int n)
{
  vector<int> temp;

  // Place non-zero nos in temp array
  for (int i = 0; i < n; i++)
  {
    if (arr[i] != 0)
    {
      temp.push_back(arr[i]);
    };
  }

  // Fill the original array with non-zero elements
  for (int i = 0; i < temp.size(); i++)
  {
    arr[i] = temp[i];
  }

  // Fill the remaining elements with zero
  for (int i = temp.size(); i < n; i++)
  {
    arr[i] = 0;
  }
}


//OPTIMAL SOLUTION 
//SOLN: Find the first element with 0 and initialise with j, if no 0 is found swap. Continue until end of array 
//- TC: O(n) 
//- SC: O(1) 
void move_zeroes_to_end_optimal(vector<int> &arr, int n)
{
  int j = -1;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      j = i;
      break;
    }
  }

  for (int i = j + 1; i < n; i++)
  {                                                                             //Remember j = -1 satisfies perfectly if no zero is found
    if (arr[i] != 0)
    {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

int main()
{
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in array: ";
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Array with 0 at end is: ";
  move_zeroes_to_end_optimal(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << "  ";
  }
}