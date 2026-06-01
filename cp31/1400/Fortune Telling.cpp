#include<bits/stdc++.h>
using namespace std;
/*
 * LOGIC AND INTUITION: THE PARITY INVARIANT
 * 
 * The problem gives a choice between Addition (+) and Bitwise XOR (^). 
 * The core trick is that both operations affect the parity [whether a number 
 * is even or odd] of a number in the EXACT same way.
 * 
 * WHY? 
 * Parity is entirely controlled by the Least Significant Bit (LSB) [the 
 * rightmost bit or 1s column in binary]. 
 * - Addition (+) is essentially XOR but with carry-overs. 
 * - When you add two 1s in binary (Odd + Odd), the LSB becomes 0, and a 1 
 *   carries over to the next column. 
 * - When you XOR two 1s (Odd ^ Odd), the LSB also becomes 0, just with no carry.
 * Because addition carries only ever alter higher bits (the 2s, 4s, 8s columns), 
 * the LSB always ends up being the exact same whether you use + or ^.
 * 
 * EXAMPLE: 5 (Odd) and 3 (Odd)
 * - Binary of 5: 0101
 * - Binary of 3: 0011
 *   -> Addition: 5 + 3 = 8 (Binary 1000) -> LSB is 0 (Even)
 *   -> XOR:      5 ^ 3 = 6 (Binary 0110) -> LSB is 0 (Even)
 * Both operations result in an even number.
 * 
 * HOW THIS SOLVES THE PROBLEM:
 * Alice starts with 'x' and Bob starts with 'x + 3'. 
 * Because they are an odd distance apart, one starts Even and the other Odd. 
 * As they process the array, their parities shift by the exact same amount 
 * at every step, regardless of whether they choose + or ^. 
 * Therefore, their final numbers will ALWAYS have opposite parities. 
 * We just calculate what Alice's final parity would be using simple addition: 
 * (x + total_sum) % 2, and check if it matches the target 'y' parity.
 */
int main(){
    int t;
    cin>>t;
    while(t--){
        
        long long n,x,y;
        cin>>n>>x>>y;

        long long sum=0;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            sum+=x;
        }

        if((x+sum)%2 == y%2) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
        

    }

}