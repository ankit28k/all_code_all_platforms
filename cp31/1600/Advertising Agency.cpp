#include<bits/stdc++.h>
using namespace std;

bool comp(int a,int b){
    return a>b;
} 
const int mod = 1e9 + 7; 

int main(){ 

    vector<vector<long long>> ncr(1001,vector<long long>(1001));
    for(int i=0; i<=1000; i++){
        ncr[i][0] = 1;
        for(int j=1; j<=i; j++){
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % mod;
        }
    }
    // fact[0] =1;
    // fact[1] = 1; 
    // for(int i=2;i<=1000;i++) fact[i] = (fact[i-1]*i)%mod;

    int t;
    cin>>t;
    while(t--){

        long long n,k;
        cin>>n>>k;
        vector<long long> arr(n); 
        for(int i=0;i<n;i++)  cin>>arr[i]; 

        if(k>=n) {
            cout<<1<<endl;
            continue;
        }

        map<long long ,long long> mp,temp;

        for(int i=0;i<n;i++)  {
            mp[arr[i]]++; 
            temp[arr[i]]++;
        }

        sort(arr.begin(),arr.end(),comp);

        long long ans=0; 
        for(int i=0;i<k;i++){
            temp[arr[i]]--;
        }

        long long left = temp[arr[k-1]];
        long long org  = mp[arr[k-1]];
        long long  combi = (ncr[org][left]) ;

        cout<<combi<<endl;
    }

}