#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int val){
    data = val;
    left = right = NULL;
  }
};
static int idx = -1;

Node* buildtree(vector<int> preorder) {
  idx++;

  if(preorder[idx] == -1)  return NULL;
  

  Node* root = new Node(preorder[idx]);
  root->left = buildtree(preorder);   // LEFT
  root->right = buildtree(preorder);  // RIGHT

  return root;
}

void Kth_level(Node* root,int k){

  if(root == NULL) return;

  if(k == 1){
    cout<<root->data<<" ";
    return;
  }

  Kth_level(root->left,k-1);
  Kth_level(root->right,k-1);
}

int main(){

  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  //   1
  // 2  3
  //   4 5

  Node* root = buildtree(preorder);
   

  Kth_level(root , 2);
  cout<<endl;

   
}