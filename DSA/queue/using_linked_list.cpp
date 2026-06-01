#include <bits/stdc++.h>
using namespace std;


class Node{

public:
  int data;
  Node* next;

  Node(int val){
    data = val;
    next=NULL;
  }
};

class Queue{
  Node* head;
  Node* tail;

public:
  Queue(){
    head = tail = NULL;
  }

  void push(int data){ //0(1)
    Node* newnode = new Node(data);

    if(empty()){
      head = tail = newnode;
    }

    else{
      tail->next = newnode;
      tail = newnode;
    }
  }

  void pop(){ //0(1)

    if(empty()){
      cout<<"its empty"<<endl;
      return;
    }
    else {
      Node* temp = head;
      head = head->next;
      delete temp;
    }

  }

  int front(){ //0(1)

    if(empty()){
      cout<<"its empty"<<endl;
      return -1;
    }

    return head->data;
  }

  bool empty(){ //0(1)
    return head == NULL;
  }

};

int main(){

  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;

  queue<int> qu;
  
}