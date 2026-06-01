#include<bits/stdc++.h>
using namespace std;

/*
PROBLEM LOGIC & TIME COMPLEXITY AVOIDANCE (TLE):

We want to make all characters equal to 'c'. In one operation with a chosen number 'x', 
we replace EVERY character EXCEPT those at 1-based indices that are multiples of 'x'.

Step 1: 0 Operations
- If the string is already entirely 'c', we need 0 operations.

Step 2: 1 Operation (The Easy Case)
- If the very last character of the string is 'c', we can just choose x = n.
- Why? The only multiple of 'n' within the string is 'n' itself. So every single 
  character except the last one gets replaced. Since the last one is already 'c', we win.

Step 3: 1 Operation (The Hidden Case)
- What if the last character isn't 'c'? We search for a single 'x' (from 2 to n-1) 
  that can fix it in 1 step. 
- For 'x' to work, ALL characters at multiples of 'x' (x, 2x, 3x...) MUST already be 'c'.
- OPTIMIZATION (Fixing TLE): Instead of checking every character, we jump our loop by 'x' 
  (j += i). This reduces the time complexity to a Harmonic Series O(N log N), easily 
  passing the 2-second time limit instead of the O(N^2) TLE.

Step 4: 2 Operations (The Absolute Fallback)
- If no single 'x' works, we are forced to use 2 operations. The numbers (n-1) and 'n' 
  are consecutive, meaning they share no common multiples within the string's length. 
- Operation 1 (using n): Overwrites everything except position 'n'.
- Operation 2 (using n-1): Overwrites everything except position 'n-1'.
- Together, they mathematically guarantee every single character is changed to 'c'.

EXAMPLE:
Let n = 5, c = 'a', and s = "bbabb" (1-based indices: 1 2 3 4 5)

- Step 1: Is it all 'a'? No.
- Step 2: Is s[5] == 'a'? No, it's 'b'.
- Step 3: Search for a valid 'x':
    - x = 2: Multiples are 2, 4. s[2] is 'b'. Fails!
    - x = 3: Multiples are 3. s[3] is 'a'. SUCCESS!
    We choose x = 3. The operation replaces indices 1, 2, 4, 5. Since index 3 
    is already 'a', the whole string becomes "aaaaa" in exactly 1 operation.
*/

pair<int,int> fun(string& s,char c,int n){

    if(s[n-1]==c) return {n,-1};

    // Let BOTH even and odd lengths go through the loop to search for a 1-step win
    for(int i=2;i<n;i++){
        if(n%i !=0) {

            bool flag = true;

            //starting at i-1 (the first multiple in 0-based indexing) and jumping by i, we skip all the non-multiples entirely.
            for(int j=i-1;j<n;j+=i){ // as for(int j=0;j<n;j++){ gives tle.....
                if( s[j] !=c) { //if((j+1)%i ==0 && s[j] !=c) {
                    flag = false;
                    break;
                }
            }

            if(flag) return {i,-1};
        }
    }

    // If the loop finishes and nothing worked, THEN apply the 2-step fallbacks
    return {n-1,n};


    //if(s[n-1]==c) return {n,-1};
    // else{
    //     if(n%2 != 0){

    //         //if all different at odd place
    //         bool flag = true;
    //         for(int i=0;i<n;i++){
    //             if((i+1)%2 ==0 && s[i] !=c) flag = false;
    //         }

    //         if(flag) return {2,-1};
    //         else return {2,n};
    //     }

    //     else{
    //         for(int i=2;i<n;i++){
    //             if(n%i !=0) {

    //                 bool flag = true;
    //                 for(int j=0;j<n;j++){
    //                     if((j+1)%i ==0 && s[j] !=c) flag = false; // not j%i != 0....its gives wrong answer 
    //                 }

    //                 if(flag) return {i,-1};

    //                 // Wait for the loop to check all 1-step options; if none work, returning {n-1, n} guarantees a 2-step win.
    //                 // else return {i,n};
    //             }
    //         }

    //         return {n-1,n};
    //     }
    // }

    // return {-1,-1};

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;

        bool flag = true;
        for(int i=0;i<n;i++) {
            if(s[i] != c) flag = false;
        }

        if(flag){
            cout<<0<<endl;
            continue;
        }

        else{
            pair<int,int> ans = fun(s,c,n);
            if(ans.second != -1) {
                cout<<2<<endl;
                cout<<ans.first<<" "<<ans.second;
            }
            else {
                cout<<1<<endl; 
                cout<<ans.first<<" ";
            }
            cout<<endl;
        }
        

    }

}