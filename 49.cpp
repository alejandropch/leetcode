#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

int main(){
  vector <string> strs = {"eat","tea","tan","ate","nat","bat"};
  unordered_map < string, vector<string>>holder;
      vector <vector<string>> response;

      for (const & it : strs)
      {
        string sorted = it;
        sort(sorted.begin(), sorted.end());
        holder[sorted].push_back(it);
      }

    
    for(auto& pair : holder ){
      response.push_back(pair.second);
    }
    return response;
  return 0;
}


