#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> arr(n),brr(m);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<m;i++) cin>>brr[i];

        long long suma=0,sumb=0;
        for(int i=0;i<n-1;i++){
            int d1 = arr[i]-arr[i+1]+1;
            suma += d1;
        }
        for(int i=0;i<m-1;i++){
            int d2= brr[i]-brr[i+1]+1;
            sumb += d2;
        }

        suma+=arr[n-1];
        sumb+=brr[m-1];
        if(suma>=sumb) cout<<1<<endl;
        else cout<<2<<endl;
    }

}