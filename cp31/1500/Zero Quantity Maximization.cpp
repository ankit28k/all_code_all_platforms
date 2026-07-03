#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n),brr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>brr[i];

    int cnt=0 , maxi =0;

    map<pair<int,int> , int> mp;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            if(brr[i]==0) cnt++;
            continue;
        }

        int num = brr[i] , denom= arr[i];
        int c = gcd(arr[i],brr[i]);
        num = num/c ;
        denom = denom/c; 

        mp[{num,denom}]++;
    }

    for(auto it:mp) maxi = max(maxi,it.second);
    cout<<maxi+cnt<<endl;

    

}