#include <stdio.h>
#include <vector>
using namespace std;

class Node{
  public:
    Node* left;
    int root;
    Node* right;

    Node(int x){
      root = x;
      left = right = NULL;
    }
};

void inOrder(Node* root, vector<int>*res){
  if(root == nullptr)
    return;
  
  inOrder(root->left, res);
  res->push_back(root->root);
  inOrder(root->right, res);
}


int main(){
  int input[] = {};
  vector<int> res;
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->right->right = new Node(6);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  inOrder(root, &res);
  for (int i : res) {
    printf("%d\n", i);
  }


  return 0;
}
