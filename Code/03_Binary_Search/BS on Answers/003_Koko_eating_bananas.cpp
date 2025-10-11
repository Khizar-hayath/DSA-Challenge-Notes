//PROBLEM: Koko eating bananas 
//- TC: O(N * log(max( a[] )))        where max(a[]) -> max elmt in array
#include <iostream>
#include <vector>
using namespace std;


int findMax(vector<int> &v) {
  int maxi = INT_MIN;
  int n = v.size();

  for (int i = 0; i < n; i++) {
    maxi = max(maxi, v[i]);
  }

  return maxi;
}


int calculateTotalHours(vector<int> &v, int hourly) {
  int totalH = 0;
  int n = v.size();

  for (int i = 0; i < n; i++) {
    totalH += ceil((double)(v[i]) / (double)(hourly));
  }

  return totalH;
}


int minRateToEatBananas(vector<int> v, int h) {
  int low = 1, high = findMax(v);

  while (low <= high) {
    int mid = (low + high) / 2;

    int totalH = calculateTotalHours(v, mid);

    if (totalH <= h) high = mid - 1;
    else low = mid + 1;
  }
  return low;
}



int main(){
  int n, h;
  cout << "Enter number of elements in the array: ";
  cin >> n;

  cout << "Enter elements in the array: ";
  vector<int> v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }

  cout << "Enter value of h";
  cin >> h;

  int ans = minRateToEatBananas(v, h);
  cout << "Piles of banana Koko should eat/hr is: " << ans;
  return 0;
}