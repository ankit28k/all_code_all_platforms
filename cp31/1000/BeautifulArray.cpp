#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k,b,s;
        cin>>n>>k>>b>>s;
        
        if(s<(b*k)) { //if((s/k)<b) => if (s<b*k)
            cout<<-1<<endl;
            continue;
        }

        long long last_el = min(s,(b*k + k-1));
        long long left = s - last_el;

        // long long to_fil = left / (k-1);

        // if( to_fil <= n-1){          => left  <= (k-1 )* (n-1 )
        // not used above as it ignores remainders
        // Let's say: You have 1 empty bucket available (n-1 = 1).
        // The bucket size is 10 (k-1 = 10).
        // You have 15 liters of water (left = 15).
        // Ideally: You can clearly see that 15 liters will NOT fit into 1 bucket of size 10. It will overflow.
        // Your Code's Logic:
        // It calculates 15 / 10.
        // In C++ integer math, 15 / 10 is 1 (it throws away the .5).
        // Your code checks: Is 1 <= 1?
        // The answer is YES.
        // Result: Your code incorrectly thinks "I can fit 15 liters into a size-10 bucket!" because it forgot about the extra 5 liters.


        // The Second Problem: The Crash
        // If k = 1, then k-1 becomes 0. Your line left / (k-1) becomes left / 0. This causes your program to crash immediately (Runtime Error).

        if( left <= (k-1)*(n-1)){
            vector<long long> ans(n,0);
            ans[n-1] = last_el;

            for(int i=0;i<n-1;i++){
                
                if(left <=0) break;

                else if(left >= k-1) {
                    ans[i] = k-1;
                    left -= k-1;
                }

                else if(left>0 && left<k-1) {
                    ans[i]=left;
                    left -= k-1;
                }
            }

            for(int i=0;i<n;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }

}