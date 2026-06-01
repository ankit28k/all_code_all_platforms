#include <bits/stdc++.h>
using namespace std;

class MinStack {
  stack<int> s, ss;
public:
  MinStack() { }
  
  void push(int val) {
    s.push(val);
    if (ss.empty() || ss.top() >= val)  { //val<=ss.top(
      ss.push(val); 
    }
      
  }
  
  void pop() {
    if (s.empty()) return;   // nothing to pop
    int ans = s.top();
    s.pop();
    if (!ss.empty() && ss.top() == ans)  ss.pop();
    //return ans
  }
  
  int top() {
    if (s.empty()) return -1;  // safety
    return s.top();
  }
  
  int getMin() {
    if (ss.empty()) return -1; // safety
    return ss.top();
}
};

int main() {
  MinStack st;
  
  st.push(5);
  st.push(3);
  st.push(7);
  st.push(2);

  cout << "Top: " << st.top() << endl;       // 2
  cout << "Min: " << st.getMin() << endl;   // 2

  st.pop();
  cout << "Top after pop: " << st.top() << endl;   // 7
  cout << "Min after pop: " << st.getMin() << endl; // 3

  st.pop();
  cout << "Top after pop: " << st.top() << endl;   // 3
  cout << "Min after pop: " << st.getMin() << endl; // 3

  st.pop();
  cout << "Top after pop: " << st.top() << endl;   // 5
  cout << "Min after pop: " << st.getMin() << endl; // 5 
}
