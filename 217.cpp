#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<int> arr = {1,2,3,1};

  sort(arr.begin(), arr.end());

   for(int i=1;i<arr.size(); i++){
    if(arr.at(i-1) == arr.at(i))return true;
  }

  return 0;
}


