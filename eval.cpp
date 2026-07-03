#include<bits/stdc++.h>
using namespace std;

long long eval(string& s) {
    vector<long long> stk;
    long long num = 0;
    char last_op = '+';
    
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        if (!isdigit(s[i]) || i == s.length() - 1) {
            if (last_op == '+') stk.push_back(num);
            else if (last_op == '-') stk.push_back(-num);
            else if (last_op == '*') {
                long long top = stk.back();
                stk.pop_back();
                stk.push_back(top * num);
            }
            else if (last_op == '/') {
                if (num == 0) return LLONG_MIN; // Still keeping divide-by-zero protection
                long long top = stk.back();
                stk.pop_back();
                stk.push_back(top / num);
            }
            last_op = s[i];
            num = 0;
        }
    }
    
    long long res = 0;
    for (long long val : stk) res += val;
    return res;
}

int main(){
    string s = "1+10*08+5";
    cout<<eval(s)<<endl;
}