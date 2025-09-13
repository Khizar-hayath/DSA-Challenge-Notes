//PROBLEM:Pascal's triangle 
/*//EXAMPLE: 
I/P: numRows = 5
O/P:  
  [[1],
  [1,1],
  [1,2,1],
  [1,3,3,1],
  [1,4,6,4,1]] 
*/


#include <bits/stdc++.h>
using namespace std;


//OPTIMAL SOLUTION 
//Soln: Build each row using binomial coefficients iteratively from previous element 
//- TC ⏱️: O(N^2) 
//- SC 🧾: O(1) 

vector<int> generateRow(int row){
  long long ans = 1;
  vector<int> ansRow;
  ansRow.push_back(1);

  for(int col=1; col<row; col++){
    ans = ans * (row - col);
    ans = ans / col;
    ansRow.push_back(ans);
  }
  return ansRow;
}


vector<vector<int>> generate(int numRows) {
  vector<vector<int>> ans;
  for(int i=0; i< numRows; i++){
    ans.push_back(generateRow(i+1));
  }
  return ans;
}