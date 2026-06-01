#include<bits/stdc++.h>
using namespace std;

// To keep the cost minimal, we want to avoid XORing a number that has a high bit set (like 1000) with a number that does not have that bit set (like 0111 ), because that would result in a large value.
//The most "dangerous" jump is between the largest power of 2 less than n (let's call it k) and the numbers smaller than it. For example, if n=10, the largest power of 2 is 8. The jump between 7 (0111) and 8 (1000) results in 15, which is quite high.

// the most affecting part is MSB ....2^k > 2^(k-1) + 2^(k-2) +....2^0
//=> ans >= 2^MSB.....if n=10 ....then ans >= 2^3 or ans>=8 
//=> for ans = 2^MSB....just put 2^MSB -1 to 0 then rest..
// ex = if n=10 ...7 6 5 4 3 2 1 | 0 8 |  9 10
//                 .....<8......   ==8  .....<8


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int ld = n-1;

        int msb = log2(ld);

        int max_val = pow(2,msb);

        int first = max_val-1;

        vector<int> ans;

        for(int i=first;i>=0;i--) ans.push_back(i);
        for(int i=max_val;i<=ld;i++) ans.push_back(i);

        for(auto x: ans) cout<<x<<" ";
        cout<<endl;

    }

}