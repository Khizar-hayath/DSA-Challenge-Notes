// PROBLEM: Set Matrix 0 

#include <bits/stdc++.h>
using namespace std;

// OPTIMAL SOLUTION 
// - TC ⏱️: O(2*(N * M)) 
// - SC 🧾: O(1) 
vector<vector<int>> setMatrixZero(vector<vector<int>> &matrix, int n, int m) {
    int col0 = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          if (j != 0) matrix[0][j] = 0;
          else col0 = 0;
        }
      }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
              if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
      for (int j = 0; j < m; j++) matrix[0][j] = 0;
    }
    if (col0 == 0) {
      for (int i = 0; i < n; i++) matrix[i][0] = 0;
    }

    return matrix;
}

int main() {
    int n, m;
    cout << "Enter number of rows in the array: ";
    cin >> n;

    cout << "Enter number of columns in the array: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter elements in the array:\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          cin >> matrix[i][j];
      }
    }

    vector<vector<int>> result = setMatrixZero(matrix, n, m);

    cout << "Modified matrix:\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          cout << result[i][j] << " ";
      }
      cout << "\n";
    }

    return 0;
}
