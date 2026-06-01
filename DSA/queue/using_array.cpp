#include <bits/stdc++.h>
using namespace std;

class Queue {
  int arr[100];
  int frontIndex;
  int rearIndex;
  int count; // to track size

public:
  Queue() {
    frontIndex = -1;
    rearIndex = -1;
    count = 0;
  }

  void push(int val) {
    if (count == 100) {
      cout << "Queue overflow\n";
      return;
    }

    if(count==0) {
      frontIndex = 0;
      rearIndex = 0;
    }

    else rearIndex = (rearIndex + 1) % 100; // circular indexing

    arr[rearIndex] = val;
    count++;
  }

  void pop() {
    if (count == 0) {
      cout << "Queue underflow\n";
      return;
    }

    if(count == 1){
      frontIndex = -1;
      rearIndex = -1;
    }
    
    else frontIndex = (frontIndex + 1) % 100; // move front ahead
    count--;
  }

  int front() {
    if (count == 0) {
      cout << "Queue is empty\n";
      return -1;
    }
    
    return arr[frontIndex];
  }

  bool empty() {
    return count == 0;
  }

  int size() {
    return count;
  }
};

int main() {
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);

  cout << "Size: " << q.size() << endl;

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
}
