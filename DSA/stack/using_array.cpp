#include <bits/stdc++.h>
using namespace std;

class Stack {
  int arr[100];  // fixed-size array
  int topIndex;  // keeps track of the top element position

public:
  Stack() {
    topIndex = -1;  // empty stack
  }

  void push(int val) {
    if (topIndex == 99) {
      cout << "Stack overflow\n";
      return;
    }

    topIndex++; 
    arr[topIndex] = val;
  }

  void pop() {
    if (topIndex == -1) {
      cout << "Stack underflow\n";
      return;
    }

    topIndex--;
  }

  int top() {
    if (topIndex == -1) {
      cout << "Stack is empty\n";
      return -1; 
    }
    return arr[topIndex];
  }

  int size() {
    return topIndex + 1;
  }

  bool empty() {
    return topIndex == -1;
  }
};

// all operation Tc = 0(1)
// SC : O(n) in worst case when stack is full
int main() {
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);

  while (!s.empty()) {
      cout << s.top() << " ";
      s.pop();
  }
}
