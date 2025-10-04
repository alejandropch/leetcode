class Solution {
public:

    string encode(vector<string>& strs) {
string res;
  for (const string &str : strs)
  {
    res = res + to_string(str.size()) + "#" + str;
  }
  return res;
    }

    vector<string> decode(string s) {

vector<string> output;
  string buffer;
  int size = -1;
  bool first_time = 1;
  for (const char &c : s)
  {
    if (c == '#' && first_time)
    {
      // i need to get the already stored data

      size = stoi(buffer);
      buffer.clear();
      first_time = false;
    }

    buffer.push_back(c);  
      
    if (size == 0) // end of a string - string that should be pushed in an slot of the result vector
    {   
      buffer.erase(0,1);
      output.push_back(buffer);
      buffer.clear();
      first_time = true;
    }
    
    size--;
  }

  return output;
    }
};

