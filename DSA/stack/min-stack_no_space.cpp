#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> s;
    long long minelement;
public:
    MinStack() { }
    
    void push(int val) {
        long long x = val;
        if (s.empty()) {
            s.push(x);
            minelement = x;
        } else {
            if (x >= minelement) {
                s.push(x);
            } else { 
                // encode the value
                s.push(2LL * x - minelement);
                minelement = x;
            }
        }
    }
    
    void pop() {
        if (s.empty()) return;
        
        if (s.top() >= minelement) {
            s.pop();
        } else {
            // decode previous min
            minelement = 2LL * minelement - s.top();
            s.pop();
        }
    }
    
    int top() {
        if (s.empty()) return -1;
        if (s.top() >= minelement) return (int)s.top();
        else return (int)minelement;
    }
    
    int getMin() {
        if (s.empty()) return -1;
        return (int)minelement;
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

    return 0;
}
