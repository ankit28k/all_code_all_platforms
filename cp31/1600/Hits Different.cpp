#include<bits/stdc++.h>
using namespace std;
 
int main(){

    vector<long long> dp(1000000+1);
    set<int> first ,last;

    int f = 4 , l=6 , diff = 3 , lvl =3;

    while(lvl<2023){

        first.insert(f);
        last.insert(l);
        f += diff;
        l+= diff+1;
        diff++;
        lvl++;

    }


    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 10;

    int level = 3;

    for(int i=4;i<=1000000;i++){

        if(first.find(i) != first.end()){ //first
            dp[i] = 1LL*i*i + dp[i-level+1];
        }   

        else if(last.find(i) != last.end()){ //last
            dp[i] = 1LL*i*i + dp[i-level];
            level++;
        }

        else{ //between
            dp[i] = 1LL*i*i + dp[i-level] + dp[i-level+1] - dp[i - 2*level +1 +1];
        }
        
        
    }

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }

}