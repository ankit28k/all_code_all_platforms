#include<bits/stdc++.h>
using namespace std;

//a%x = b%x  => a = px + r ....b = qx +r.....=> a-px = b-qx.....(p-q)x = (a-b) ....tx = a-b ....=> x = (a-b)/t
//=>  x must divide every .....a-b....=> gcd of all a-b

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        if(n==1){
            cout<<0<<endl;
            continue;
        }

        int ans =0;
        for(int i=0,j=n-1;i<j;i++,j--){
            ans = gcd(ans,abs(arr[j]-arr[i]));
        }

        cout<<ans<<endl;
            
    
    }

}