#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return (b,a%b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<long long> gcdl(n) , gcdr(n);
        vector<long long> multiplyl(n) , multiplyr(n);

        gcdl[0] = arr[0];
        multiplyl[0] = arr[0];
        gcdr[n-1] = arr[n-1];
        multiplyr[n-1] = arr[n-1];

        for(int i=1;i<n;i++){
            gcdl[i] = gcd(gcdl[i-1],arr[i] );
            multiplyl[i] = multiplyl[i-1]*arr[i];
        }

        for(int i=n-2;i>=0;i--){
            gcdr[i] = gcd(gcdr[i+1],arr[i] );
            multiplyr[i] = multiplyr[i+1]*arr[i];
        }

        vector<long long> ans(n);
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i] = multiplyr[i+1]/gcdr[i+1];
            }

            else if(i==n-1){
                ans[i] = multiplyl[i-1] / gcdl[i-1];
            }

            else{

                int hcf = gcd(gcdl[i-1],gcdr[i+1]);
                long long ab = multiplyl[i-1]*multiplyr[i+1];
                ans[i] = ab/hcf;
            }
        }
        

        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }

}