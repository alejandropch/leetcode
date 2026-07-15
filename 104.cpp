#include <iostream>
using namespace std;

class TreeNode{
  public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x){
      val = x;
      left = right = nullptr;
    } 
};

int maxDepth(TreeNode* root){
  TreeNode *prev;
  int max = 0, current_max = 0, steps = 1;
  while(root != nullptr){
    if(root->left == nullptr){
      current_max++;
      if(current_max > max){
        max = current_max;
      }
      cout<<root->val<<endl;
      root = root->right;
    }
    else{
      prev = root->left;
      steps = 1;
      while(prev->right != nullptr && prev->right != root){
        prev = prev->right;
        steps++;
      }
      if(prev->right == nullptr){
        current_max++;
        if(current_max > max){
          max = current_max;
        }
        prev->right = root;
        root = root->left;
      }else{
        current_max = current_max - steps;
        cout<<root->val<<endl;
        prev->right = nullptr;
        root = root->right;
      }
    }
  }
  cout << "max: " << max << endl;
  return max;
}
int main(){
  TreeNode *tree = new TreeNode(3);
  tree->left = new TreeNode(9);
  tree->right = new TreeNode(20);
  tree->right->left = new TreeNode(15);
  tree->right->right = new TreeNode(7);
  maxDepth(tree);



}
