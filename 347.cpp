#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> nums = {1, 1, 3, 2, 2 ,2 ,2}; // size = 7
  int k = 1;
  vector <int> output;

  // saving ocurrences
  unordered_map <int, int>hashmap;
  for(const int& it : nums){
    hashmap[it]++;
  }

  // bucket sort algorithm
  vector<vector<int>> bucketSort (nums.size()+1); // 7 + 1 -> remember that we are not using the 0 slot, since doesn't make sence to use it
                                                  // hence we need one extra space
                                          
  // filling the bucketSort vector
  for(const auto& pair : hashmap){
    bucketSort.at(pair.second).push_back(pair.first); // using number of occurences as index for the bucketSort vector -- remember that our approach is using this vector's index as number of ocrrences. since the nums lenght is 7, the max index this vector can have is 7. this is the worst case scenario (imagine that the same number repites 7 times, that would be 7 numbers in the same index 7)
  }

  // sorting the buckedSort vector for getting the top k repeated elements
  for (int i = bucketSort.size()-1; i > 0 ; i--) // the for loop would go from (i > 0 && i = 8) -> (1 - 7), i= 8 to get the slot where 7 ocurrences happened, remember that we dont care about the 0 slot
  {
     for (int j = 0; j < bucketSort.at(i).size(); j++)
     {  
        if(k == 0) return output;
        output.push_back(bucketSort.at(i).at(j)); // getting the numbers from each slot (all repeated numbers (in a slot) since remember that they are occurences)
        k--;
     } 
  }
  


  return 0;
}
