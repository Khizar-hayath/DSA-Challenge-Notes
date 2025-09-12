//PROBLEM: Spiral Traversal of a matrix 
/*//EXAMPLE: 
I/P:                       O/P:  1 2 3 6 9 8 7 4 5
1  2  3
4  5  6
7  8  9
*/

#include <bits/stdc++.h>
using namespace std;


//OPTIMAL SOLUTION 
//Soln: Run 4 loops to iterate in 4 different directions: top, bottom, left, right. Decrease their value by 1 each time soon their size will decrease and it'll end. 
//- TC ⏱️:  
//- SC 🧾:  
vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  int top = 0, bottom = n-1;
  int left = 0, right = m-1;
  vector<int> ans;

  while(left <= right && top <= bottom){
    for(int i=left; i<=right; i++){
      ans.push_back(matrix[top][i]);
    }
    top++;

    for(int i=top; i<=bottom; i++){
      ans.push_back(matrix[i][right]);
    }
    right--;

    if(top <= bottom){
      for(int i=right; i>=left; i--) ans.push_back(matrix[bottom][i]);
      bottom--;
    }

    if(left <= right){
      for(int i=bottom; i>=top; i--) ans.push_back(matrix[i][left]);
      left++;
    }
  }

  return ans;
}