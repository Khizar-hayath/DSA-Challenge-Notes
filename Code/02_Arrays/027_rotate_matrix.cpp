//PROBLEM: Rotate matrix by 90 degree 
/*//EXAMPLE: 
I/P: []                           O/P: []
1 2 3                             7 4 1
4 5 6                             8 5 2
7 8 9                             9 6 3
*/

#include <bits/stdc++.h>
using namespace std;

//BRUTE SOLUTION 
//Soln:  
//- TC ⏱️: O(N^2) 
//- SC 🧾: O(N^2) -> To store solution  
void rotate_matrix_brute(vector<vector<int>>& matrix, int n, int m) {
  int n = matrix.size();
  vector<vector<int>> res(n, vector<int>(m));

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      res[j][n-1-i] = matrix[i][j];
    }
  }
}



//OPTIMAL SOLUTION 
//Soln: Transpose | Reverse the row elements 
//- TC ⏱️: O(N/2 * N/2) + O(N * N/2) 
//- SC 🧾: O(1) 
void rotate_matrix_optimal(vector<vector<int>>& matrix) {
  int n = matrix.size();

  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  for(int i=0; i<n; i++){
    reverse(matrix[i].begin(), matrix[i].end());
  }
}