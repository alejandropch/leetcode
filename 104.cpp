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
  if(!root){
    return 0;
  }
  int left = maxDepth(root->left);
  int right = maxDepth(root->right);
  if(left > right)
    return 1 + left;

  return 1 + right;
}
int main(){
  TreeNode *tree = new TreeNode(3);
  tree->left = new TreeNode(9);
  tree->right = new TreeNode(20);
  tree->right->left = new TreeNode(15);
  tree->right->right = new TreeNode(7);
  maxDepth(tree);



}
