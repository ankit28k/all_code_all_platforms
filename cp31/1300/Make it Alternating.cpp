#include<bits/stdc++.h>
using namespace std;

long long mod = 998244353;

int main(){

    vector<long long> fact(200001);
    fact[0] = 1;
    for(int i=1;i<=200000;i++) fact[i] = (fact[i-1]*i)%mod;

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int cnt = 0 , n = s.length();

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) cnt++;
        } 

        long long temp=1 ,ss = 1;

        for(int i=1;i<n;i++){

            if(s[i]==s[i-1]) temp++;

            else{
                if(temp>1){
                    // ss= (ss *temp*fact[temp-1])%mod;....... Wrong Answer...as we arrange(permuatation) at last

                    //example, if you need to delete 2 characters from one block and 1 character from another block, 
                    //the total number of deletions is 3. The number of ways to arrange those 3 total deletions is 3! (which is 6). 
                    //Your code calculates it as 2!*1! = 2, which heavily undercounts the valid sequences.

                    ss = (ss *temp)%mod;
                }

                temp = 1;
            }
        }

        if(temp>1) ss = (ss *temp)%mod;
        ss = (ss*fact[cnt])%mod;

        cout<<cnt<<" "<<ss<<endl;
    }

}