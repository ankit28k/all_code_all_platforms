#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  Node(int val){
    data = val;
    next = NULL;
  } 

};

class CircularList{
  Node* head;
  Node* tail;

public:
  CircularList(){
    head = tail = NULL;
  }

  void insertathead(int val){
    Node* newNode = new Node(val);

    if(head==NULL){
      head = tail = newNode;
      tail->next = head;
    }

    else {
      newNode->next = head;
      head = newNode;
      tail->next = head;
    }
  }

  void insertatend(int val){
    Node* newNode = new Node(val);

    if(head==NULL){
      head = tail = newNode;
      tail->next = head;
    }

    else{
      newNode->next = head;
      tail->next = newNode;
      tail = newNode;
    }
  }

  void deleteathead(){
    if(head==NULL) return; // 0 node

    else if(head == tail){  //single node 
      delete head;
      head = tail = NULL;
    }

    else {
      Node* temp = head;  //double node
      head = head->next;
      tail->next = head;
      temp->next = NULL;
      delete temp;
    }
    
  }

  void deleteatend(){

    if(head==NULL) return; // 0 node

    else if(head == tail){  //single node 
      delete head;
      head = tail = NULL;
    }
    else{
      Node* temp = tail;
      Node* prev = head;

      while(prev->next != tail) prev =prev->next;
      tail = prev;
      tail->next = head;
      temp->next =NULL;
      delete temp;
    }
  }

  void print(){
    
    if(head==NULL) return;
    cout<<head->data<<" -> ";
    Node* temp = head->next;

    while(temp != head){
      cout<<temp->data<<" -> ";
      temp = temp->next;
    }
    cout<<temp->data<<endl;
  }
  

};


int main(){

  CircularList cll;

  cll.insertathead(1);
  cll.insertathead(2);
  cll.insertathead(3);
  cll.insertathead(4);

  cll.insertatend(8);
  cll.insertatend(9);

  cll.deleteathead();
  cll.deleteatend();

  cll.print();

}