#include<bits/stdc++.h>
using namespace std;

// breaking in 2 is always better than breaking in three....as ...let 3 segments of sum a,b,c....
//=> gcd(a,b+c) >= gcd(a,b,c) ...as
// let k = gcd(a,b,c) => a= mk ,b = nk, c=lk.....
// gcd(a,b+c) = gcd(mk , (n+l) k ) ......if n+l and m has no common divisor...then gcd(a,b+c) = gcd(a,b,c)....if they a common divisor then
// => gcd(a,b+c) > gcd(a,b,c)....hence always break in 2

long long gcd(int a,int b){
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

        vector<long long> lsum(n),rsum(n);
        lsum[0]=arr[0] ;
        rsum[n-1] = arr[n-1];

        for(int i=1;i<n;i++) lsum[i] = lsum[i-1]+arr[i];
             
        for(int j=n-2;j>=0;j--) rsum[j]= rsum[j+1] + arr[j];
        

        long long ans=0;
        for(int i=0;i<n-1;i++){
            ans = max(ans,gcd(lsum[i],rsum[i+1]));
        }

        cout<<ans<<endl;
    }

}