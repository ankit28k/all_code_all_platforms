#include <bits/stdc++.h>
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

Node* insert(Node* root , int val){
   
  if(root == NULL ) return new Node(val);

  if(val < root->data) root->left = insert(root->left , val);
  else root->right =  insert(root->right , val);

  return root;

}


Node* builttree(vector<int> arr ){
  Node* root = NULL;

  for(int val : arr){
    root = insert(root, val);
  } 

  return root;
}
 
void inorder(Node* root){

  if(root == NULL) return;
   
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);

}

bool search(Node* root, int val){

  if(root == NULL) return false;
  if(root->data == val) return true;

  if(val < root->data) return search(root->left , val);
  else return search(root->right , val);


}

Node* getInorderSuccessor(Node* root){ //leftmost node in right subtree

  while (root != NULL && root->left != NULL  )  root = root->left;
  return root;

}

Node* deletenode(Node* root, int val){

  if(root == NULL) return root;

  if(val > root->data) root->right = deletenode(root->right , val);

  else if(val < root->data) root->left = deletenode(root->left , val);

  else {  //key == root
    
    if(root->left == NULL) {

      Node* temp = root->right;
      delete root;
      return temp;
    }

    else if(root->right == NULL){

      Node* temp = root->left;
      delete root;
      return temp;

    }

    else { //2 children
    Node* temp = root;
      Node* IS = getInorderSuccessor(root->right);
      root->data = IS->data;
      root->right = deletenode(root->right , IS->data);

    }
    
  }

  return root;

}


int main(){

  vector<int> arr = {3,2,1,5,6,4};

  Node* root = builttree(arr);
   
  cout<<search(root,3)<<endl ;

  inorder(root);
  cout<<endl;

  deletenode(root, 2);
  inorder(root);
  cout<<endl;


}