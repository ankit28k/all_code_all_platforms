#include<bits/stdc++.h>
using namespace std;

int fun(int n){

    if(n==1) return 0;

    int ans = n;

    for(int i=2;i<n;i++){
        if(n%i==0){
            ans = min(ans, i + n/i);
        }
    }

    ans= min(ans,n-1);
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        cout<<fun(n)<<endl;
    }

}