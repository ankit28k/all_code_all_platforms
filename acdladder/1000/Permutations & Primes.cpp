#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if(n <= 1) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        if(n == 1){
            cout<<1<<endl;
            continue;
        }

        vector<int> primes , nonprimes;
        for(int i=2;i<=n;i++) {
            if(isprime(i)) primes.push_back(i);
            else nonprimes.push_back(i);
        }
        vector<int> ans(n,-1); 

        ans[n/2] =1;//
        
        int i=0;
        for(int j=0;j<primes.size();j+=2){

            if(ans[i] != -1) {
                i++;
                j-=2;
                continue;
            }
            ans[i] = primes[j];
            if(j< primes.size()-1) ans[n-1-i] = primes[j+1];
            i++;
        }

        int k = 0;
        for(int j=0; j<n; j++){
            if(ans[j] == -1) {
                ans[j] = nonprimes[k++];
            }
        }

        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }

}