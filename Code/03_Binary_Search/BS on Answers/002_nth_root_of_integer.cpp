//PROBLEM: Find nth root of an Integer 
#include <iostream>
using namespace std;


//BRUTE SOLUTION 
//Soln: Linear Search 
int nth_root(int n, int m) {
  for (int i = 1; i <= m; i++) {
    long long ans = 1;
    for (int j = 0; j < n; j++) ans = ans*i;
    if (ans == m) return i;
    if (ans > m) break;
  }
  return -1;
}



//OPTIMAL SOLUTION 
//Soln: Using binary search 
//- TC ⏱️: O(log m * n) 
//return 1, if == m:
//return 0, if < m:
//return 2, if > m:
int func(int mid, int n, int m) {
  long long ans = 1;

  for (int i = 0; i < n; i++) {
    ans = ans * mid;
    if (ans > m) return 2;
  }

  if (ans == m) return 1;
  return 0;
}

int nth_root_optimal(int n, int m) {
  int low = 1, high = m;

  while (low <= high) {
    int mid = (low + high) / 2;

    int midNum = func(mid, n, m);

    if (midNum == 1) return mid;
    else if (midNum == 0) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}


int main(){
  int n, m;
  cout << "Enter number to find root with: ";
  cin >> n;

  cout << "Enter the number: ";
  cin >> m;

  int res = nth_root(m, n);

  cout << res;
}