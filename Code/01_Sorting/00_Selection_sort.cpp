// TITLE: Selection Sort
// DEFN: It is a method where you repeatedly pick the smallest item from the unsorted part and place it at the beginning, until everything is sorted.
//- TC ⏱️: O(n^2) -> Worst, Avg, Best case
//- SC 🧾: O(1)

#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
  for (int i = 0; i < n - 2; i++){                                             // Remember it's [ n-2 ] || 2nd last element(last element is automatically sorted/ need not be sorted)
    int mini = i;
    for (int j = i; j < n - 1; j++){                                           // Remember it's [ n-1 ] || last element
      if (arr[j] < arr[mini])
        mini = j;
    }

    // Sorting
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }
}

int main()
{
  cout << "Enter number of elements in array: ";
  int n;
  cin >> n;

  cout << "Enter elements in array: ";
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  selection_sort(arr, n);
  cout << "Sorted Array is: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << "  ";
}
