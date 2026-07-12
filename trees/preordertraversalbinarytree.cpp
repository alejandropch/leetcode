#include <stdio.h>
#include <vector>
using namespace std;
class Node {
  public:
    Node* left;
    int data;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
void inOrder(Node* node, vector<int>* root){
  if(node == nullptr)
    return;

  root->push_back(node->data);
  inOrder(node->left, root);
  inOrder(node->right, root);
}

int main(){
  Node* tree = new Node(8);
  tree->left = new Node(1);
  tree->left->right = new Node(7);
  tree->left->right->right = new Node(10);
  tree->right = new Node(5);
  tree->right->left = new Node(10);
  tree->right->left->left = new Node(6);
  tree->right->right = new Node(6);
  vector<int> res;
  inOrder(tree, &res);

  for(int i : res)printf("%d\n", i);

  return 0;
}
