#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  vector <int> nums = {2,5,5,11};
  int target = 10;
  unordered_map <int, int>hashmap; 
  for (size_t i = 0; i < nums.size(); i++)
  {
    if(hashmap.find( target - nums[i] ) == hashmap.end()){
      hashmap[nums[i]] = i;
    }
    else{
      cout << hashmap[target - nums[i]] <<" "<< i<<endl;
    }
    
    
  }
  cout << "result?";
  
  return 0;
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map <int, int>hashmap; 
      for (int i = 0; i < nums.size(); i++)
      {
        if(hashmap.find( target - nums[i] ) == hashmap.end()){
          hashmap[nums[i]] = i;
        }
        else{
          return {hashmap[target - nums[i]], i};
        }
    
      }
    }
};