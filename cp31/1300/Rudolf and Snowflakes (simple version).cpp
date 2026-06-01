#include<bits/stdc++.h>
using namespace std; 

int main(){

    // avoid using pow ...as it can give precision errors
    
    set<long long> ans;

    for(int i=2;i<1000;i++){
        
        long long sum = 1 + i + i*i;
        ans.insert( sum);

        long long k = i*i;

        for(int j=3;j<20;j++){

            k = k*i;

            sum += k; 
            if(k <= 1e6) ans.insert(sum);
            else break;
        }
    }
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; 
        if(ans.find(n) == ans.end()) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

}