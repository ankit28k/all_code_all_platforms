#include<bits/stdc++.h>
using namespace std;

/*
1. Why Odd 'n' has no solution (-1):
    - Humari equation hai: a + b = 2n. Iska matlab (a + b) hamesha EVEN hoga.
    - Agar 'n' ODD hai, toh a ^ b = n (ODD) hoga.
    - XOR Odd tabhi aata hai jab ek number Odd aur doosra Even ho.
    - Lekin ek Odd aur ek Even number ka sum (a + b) hamesha ODD aayega!
    - Contradiction: Sum Even hona chahiye (2n), par logic keh raha hai sum Odd aayega. 
        Isliye odd 'n' ke liye koi 'a' aur 'b' exist nahi karta.

2. How we got (a & b) = n / 2:
    - Universal Bitwise Formula: a + b = (a ^ b) + 2 * (a & b)
    - Question ki given values: a ^ b = n  aur  a + b = 2n
    - Formula mein values dalne par: 2n = n + 2 * (a & b)
    - Solve karne par: n = 2 * (a & b)  =>  (a & b) = n / 2
    - Isliye hum 'a' aur 'b' dono mein '1' tabhi set karte hain jab (n/2) ka woh bit 1 ho.
=========================================
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> a(30),b(30);
        for(int i=0;i<30;i++){
            if((n>>i)&1){
                a[i] = 0;
                b[i] = 1;
            }

            else{

                if(((n/2)>>i)&1){
                    a[i] = 1;
                    b[i] = 1;
                }
                else {
                    a[i] = 0;
                    b[i] = 0;
                }
                
            }

        }

        long long p=0 ,q=0;
        for(int i=0;i<30;i++){
            if(a[i]) p += pow(2,i);
            if(b[i]) q += pow(2,i);
        }
        
        if(p+q == 1LL*2*n)cout<<p<<" "<<q<<endl;
        else cout<<-1<<endl;
    }

}


// void fun(int idx,int msb,int n,string& a,string& b,pair<int,int>& ans){

//     if(ans.first != -1 ) return;

//     if(idx > msb) {
//         int x=0,y=0;

//         for(int i=0;i<=msb;i++){
//             if(a[i]=='1') x+=pow(2,i);
//             if(b[i]=='1') y += pow(2,i);

//         }

//         if((x+y)/2==n) ans = {x,y};
//         return;
//     }

//     int cbit = (n>>idx)&1;

//     if(cbit == 1){
//         a.push_back('1');
//         b.push_back('0');
//         fun(idx+1,msb,n,a,b,ans);

//         a.pop_back();
//         b.pop_back();

//     }

//     else{

//         a.push_back('0');
//         b.push_back('0');
//         fun(idx+1,msb,n,a,b,ans);

//         a.pop_back();
//         b.pop_back();

//         a.push_back('1');
//         b.push_back('1');
//         fun(idx+1,msb,n,a,b,ans);
//         a.pop_back();
//         b.pop_back();
//     }

// }

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
        
//         int msb = log2(n);
//         map<int,int> mp;

//         string a,b ;
//         pair<int,int> ans{-1,-1};
//         fun(0,msb,n,a,b,ans);

//         if(ans.first == -1) cout<<-1<<endl;
//         else cout<<ans.first<<" "<<ans.second<<endl;
        
//     }

//}