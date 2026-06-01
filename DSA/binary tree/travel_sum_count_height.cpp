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

void preOrder(Node* root){

  if(root == NULL) return;

  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);

}

void inorder(Node* root){
  if(root == NULL) return;

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void postorder(Node* root){
  if(root == NULL) return;

  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

void levelorder(Node* root){

  queue<Node*> q;

  q.push(root);
  q.push(NULL);

  while(!q.empty()){

    Node* curr = q.front();

    q.pop();

    if(curr==NULL){
      
      if(!q.empty()){
        cout<<endl;
        q.push(NULL);
        continue;
      }

      else break;
    }

    cout<<curr->data<<" ";
    
    if(curr->left != NULL) q.push(curr->left);
    if(curr->right != NULL) q.push(curr->right); 
    
  }
}

int heightoftree(Node* root) {

  if(root == NULL) return 0;

  int left = heightoftree(root->left);
  int right = heightoftree(root->right);
  
  return max(left,right) + 1;
}

int countOfNodes(Node* root) {

  if(root == NULL) return 0;

  int left = countOfNodes(root->left);
  int right = countOfNodes(root->right);
  
  return left + right + 1;
}

int sumOfNodes(Node* root){

  if(root == NULL) return 0;

  int leftsum = sumOfNodes(root->left);
  int rightsum = sumOfNodes(root->right);

  return leftsum + rightsum + root->data ;
}

int main(){

  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  //   1
  // 2  3
  //   4 5

  Node* root = buildtree(preorder);
  cout<<root->data<<endl;
  cout<<root->left->data<<endl;
  cout<<root->right->data<<endl;

  preOrder(root);
  cout<<endl;

  inorder(root);
  cout<<endl;

  postorder(root);
  cout<<endl;

  levelorder(root);
  cout<<endl;


  cout<<"Heigth : "<<heightoftree(root)<<endl;
  cout<<"sum : "<<sumOfNodes(root)<<endl;
}