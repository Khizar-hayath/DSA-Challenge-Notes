  //PROBLEM: Majority element in the array 
  //EXAMPLE: I/P: [2,2,3,3,1,2,2,]                      O/P: 2 

  #include <bits/stdc++.h>
  using namespace std;


  //BRUTE SOLUTION - Multiple loops 
  //Soln: Run 2 loops and check with every number if its greater than n/2 
  //- TC ⏱️: O(N^2) 
  //- SC 🧾: O(1) 
  int majority_element_brute(vector<int> &nums, int n){
    for(int i=0; i<n; i++){
    int cnt = 0;
      for(int j=0; j<n; j++){
        if(nums[i] == nums[j]){
          cnt++;
        }
      }
      if (cnt > n/2) return nums[i];
    }
    return -1;
  }


  //BETTER SOLUTION - Hashmap 
  //Soln: Craete a map iterate values into them. Check how many times it repeats and returns the num that repeats 
  //- TC ⏱️: O(N logN) + O(N) = O(N logN)
  //- SC 🧾: O(N) 
  int majority_element_better(vector<int>& nums, int n){
    map<int,int> mpp;

    for(int i=0; i<n; i++){
      mpp[nums[i]]++;                 //! mpp.insert(nums[i]); is wrong         mpp(nums[i])++; is also wrong
    }

    for(auto it:mpp){
      if(it.second > n/2){
        return it.first;
      }
    }

  /*
  !! My mistake
    for(int i=0; i<mpp.size(); i++){
      if(mpp.first > n/2){
        return mpp.second
      }
    }
  */
    return -1;
  }


  //OPTIMAL SOLUTION - Moores Voting Algorithm 
  //Soln: Check if a num is > n/2 in multiple sub arrays 
  //- TC ⏱️: O(N) 
  //- SC 🧾: O(1) 
  int majority_element_optimal(vector<int>& nums, int n){
    int el;
    int cnt = 0;
    for(int i=0; i<n; i++){
      if(cnt == 0){
        el = nums[i];
        cnt++;
      }
      else if (nums[i] == el) cnt++;
      else cnt--;
    }

    int freq = 0;
    for(int j=0; j<n; j++){
      if(nums[j] == el) freq++;
    }

    if(freq > n/2) return el;

    return -1;
  }



  int main(){
    int n;
    cout << "The value of n is: ";
    cin >> n;

    cout << "Enter elements in the array: ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
      cin >> arr[i];
    }

    int melement = majority_element_better(arr, n);

    cout << melement;
  }