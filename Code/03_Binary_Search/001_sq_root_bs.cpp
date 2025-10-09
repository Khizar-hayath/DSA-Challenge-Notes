//PROBLEM: Integer square root of a given number using Binary Search 
//Soln: Find where the target number first appears and where it last appears in the sorted array using binary search 
//EXAMPLE: I/P: nums = 36      O/P: 6 

#include <iostream>
#include <vector>
using namespace std;


//- TC ⏱️: O (2 * log N) (to base 2) 
int sqrt_bs(int n){
  int low = 1, high = n - 1;

  while(low <= high){
    int mid = (low + high) / 2;
    long long val = mid * mid;

    if(val <= n) low = mid + 1;
    else high = mid - 1;
  }
  return high;
}

int main(){
  int n;
  cout << "Enter the number: ";
  cin >> n;


  int res = sqrt_bs(n);

  cout << res;
}