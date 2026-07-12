#include <iostream>
using namespace std;

class Node{

  public:
    Node *left;
    Node *right;
    int data;
    Node(int x){
      left = right = nullptr;
      data = x;
    }
};
void morris(Node* curr){
  Node *prev;
  
  while(curr != nullptr){

    if(curr->left == nullptr){
      cout<<curr->data<<endl;
      curr = curr->right;
    }
    else {
      prev = curr->left; // prev = 2  
                         // curr = 4
      while(prev->right != nullptr && prev->right != curr)
      {
        prev = prev->right;
      }
      if(prev->right == nullptr){
        prev->right = curr;
        curr = curr->left;
      }else{
        cout << curr->data<<endl;
        prev->right = nullptr;
        curr = curr->right;
      }
    }

  }


}
int main(){

  Node *tree = new Node(4);
  tree->left = new Node(2);
  tree->left->left = new Node(1);
  tree->left->right = new Node(3);
  tree->right = new Node(5);
  morris(tree);
  return 0;
}
