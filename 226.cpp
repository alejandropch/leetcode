#include <iostream>

using namespace std;

class TreeNode {
  public: 
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(){
    }
    TreeNode(int x){
      val = x;
      left = right = nullptr;
    }

};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if(root == nullptr) return nullptr;

      cout<<root->val<<endl;

      TreeNode* temp = root->left;
      root->left = root->right;
      root->right = temp;
      this->invertTree(root->left);
      this->invertTree(root->right);

      return root;
    };
};

int main(){
  TreeNode* tree = new TreeNode(4);
  tree->left = new TreeNode(2);
  tree->left->left = new TreeNode(1);
  tree->left->right = new TreeNode(3);
  tree->right = new TreeNode(7);
  tree->right->left = new TreeNode(6);
  tree->right->right = new TreeNode(9);

  Solution* s = new Solution();
  s->invertTree(tree);


  return 0;
}
