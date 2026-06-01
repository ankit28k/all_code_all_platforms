#include<bits/stdc++.h>
using namespace std;

/* 
 logic
 1. THE CONSTRAINT:
    The problem says we can swap (a, b) only if (a & b) == X.
    This equation implies that X must be a "submask" of both 'a' and 'b'.
    (i.e., Every bit that is 1 in X must also be 1 in 'a' AND 1 in 'b').

 2. THE BOTTLENECK:
    Identify all elements that are currently in the wrong position (where p[i] != i).
    Every single one of these "misplaced" elements MUST move at least once to get sorted.
    Therefore, X must be a submask of EVERY misplaced element. 
    
    If X had a bit set to 1 that even one misplaced number didn't have, 
    that number could never swap, and the array could never be sorted.

 3. THE SOLUTION:
    To maximize X, we simply take the Bitwise AND of all misplaced elements.
    This gives us the largest possible mask that fits inside everyone who needs to move.
    
    Ans = AND(all p[i] where p[i] != i)
 
 ADDRESSING YOUR DOUBT: "If pairwise AND is bigger than X, how do we swap?" 
 
 Q: Let's say we have 3 and 2. Their individual AND is 2. But the global X is 0.
    Since (3 & 2) == 2 (which is != 0), we can't swap them directly. So how does it work?

 A: We do NOT need to swap every pair directly. We use X as a "Bridge" or "Hub".
    Since X is a submask of everyone, everyone can swap with the element containing X.
    
    Example: 
    - We need to swap A and B. Direct swap is impossible.
    - But somewhere in the array, there is an element with value X (or a proxy for it).
    - We swap A with X (Allowed because A & X == X).
    - Then we swap B with X (Allowed because B & X == X).
    so swap 3 , 0 then 0,2
    
    By using the X-value element as a temporary holding spot (a taxi driver), 
    we can move elements anywhere they need to go, even if they can't swap directly with each other.
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        
 
        for(int i=0;i<n;i++) cin>>arr[i];  
 
        vector<int> p(n);
        for(int i=0;i<n;i++) p[i]=i;

        int idx =-1,ans;
        for(int i=0;i<n;i++){
            if(arr[i] != p[i]){
                idx = i;
                ans = arr[i];
                break;
            }
        }

        for(int i=idx+1;i<n;i++){
            if(arr[i] != p[i]) ans  = ans& arr[i];
        }

        cout<<ans<<endl;

        // int ans =INT_MAX;
       
        // for(int i=0;i<n;i++){
        //     if(arr[i] != p[i]) ans = min(ans,arr[i]&p[i]);
        // }
 
        // cout<<ans<<endl;
    }
 
}