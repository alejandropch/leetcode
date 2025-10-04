#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  string s = "aacc";
  string t = "ccac";

  if (s.size() != t.size()) return false;

  unordered_map<int, int> hashmap;
  unordered_map<int, int> t_hashmap;

  for (int i = 0; i<s.size(); i++)
  {
    hashmap[s.at(i)]++;
    hashmap[t.at(i)]--;
  }
  for(const auto &pair : hashmap){
    if (pair.second != 0) cout<<"false"; 
  }

  cout<<"true";
  return 0;
}


