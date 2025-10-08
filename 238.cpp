#include <stdio.h>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
  vector <int> output;
  // pre fixes
  int prefix = 1;
  for (int i = 0; i < nums.size(); i++)
  {
    output.push_back(prefix);
    prefix = prefix * nums[i];
  }
  
  // post fixes 
  int postfix = 1;
  for (int i = nums.size() -1 ; i >= 0; i--)
  {
    output[i] = output[i] * postfix;
    postfix = nums[i] * postfix;
  }

  return output;
}

int main()
{
  vector<int> nums = {-1, 1, 2, -3, 3};

  vector<int> output = productExceptSelf(nums);

  for (const int &it : output)
  {
    printf("%d\n",it);
  }

  return 0;
}