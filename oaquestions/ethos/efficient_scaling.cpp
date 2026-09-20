#include<bits/stdc++.h>
using namespace std;

bool poss(long long m,long long n,vector<long long>& th,vector<long long>& sc , long long bd){

    int cost =0;
    for(int i=0;i<n;i++){
        int temp = (((m+th[i]-1)/th[i]) -1)*sc[i];
        cost += temp;
    }
    return cost<=bd;
}
int main(){
    long long n , bd;
    cin>>n>>bd;
    vector<long long> th(n) , sc(n);
    for(int i=0;i<n;i++) cin>>th[i];
    for(int i=0;i<n;i++) cin>>sc[i];

    long long l=1 , h = 0;
    for(int i=0;i<n;i++){
        long long temp = th[i]*(1 + bd/sc[i]);
        h = max(h,temp);
    }

    long long ans=h;
    while(l<=h){
        long long m = l + (h-l)/2;
        if(poss(m,n,th,sc,bd)){
            ans = m;
            l=m+1;
        }
        else h=m-1;
    }
    cout<<ans<<endl;
}