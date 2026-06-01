#include <iostream>
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

class List{

  Node* head;
  Node* tail;

public:

  List(){
    head=tail=NULL;
  }

  void push_front(int val){
    Node* newnode = new Node(val); // Node newnode(val); ...creates static which gets deleted after coming out of function
    if(head == NULL)  {
      head = tail = newnode;
      return;
    }

    else {
      newnode->next = head;
      head = newnode;
    }
  }

  void push_back(int val){
    Node* newnode = new Node(val);
    if(head == NULL)  {
      head = tail = newnode;
      return;
    }

    else {
      tail->next = newnode;
      tail = newnode;
    } 

  }

  void pop_front(){

    if(head==NULL) {
      cout<<"ll is empty"<<endl;
      return;
    }

    Node* temp = head;
    head = head->next;
    temp ->next = NULL;
    delete temp; 

  }

  void pop_back(){
    if(head==NULL) {
      cout<<"ll is empty"<<endl;
      return;
    }

    Node* temp = head;
    while(temp->next != tail) temp = temp->next;

    temp->next = NULL;
    delete tail;  // doesnt delete variable name but the storage in memory....like free()
    tail=temp;
  }

  void insert(int val,int pos){

    if(pos<0) {
      cout<<"invalid position"<<endl;
      return;
    }

    if(pos==0 ) push_front(val);

    Node* temp = head;
    for(int i=0;i<pos-1;i++) {
      if(temp->next ==NULL) {
        cout<<"invalid position"<<endl;
        return;
      }
      temp=temp->next;
    }

    Node* newnode = new Node(val);

    newnode->next = temp->next;
    temp->next = newnode;
  }

  int searchll(int target){
    Node* temp = head;
    int idx=0;

    while(temp != NULL){
      if(temp->data == target ) return idx; //return true;
      temp = temp->next;
      idx++;
    }

    return -1;// return false;
  }

  void printll(){
    Node* temp=head;

    while(temp!= NULL){
      cout<<temp->data<<"->";
      temp = temp->next;
    }
    cout<<"NULL"<<endl;

  }

};

int main(){

  List ll;
  List ll2;

  // ll.push_front(1);
  // ll.push_front(2);

  // ll.push_back(4);

  // ll.pop_front();

  // ll.pop_back();

  // ll.printll();

  ll2.push_back(1);
  ll2.push_back(2);
  ll2.push_back(3);
  ll2.push_back(4);

  ll2.insert(7,2);

  ll2.printll();

  cout<<ll2.searchll(4)<<endl;

}