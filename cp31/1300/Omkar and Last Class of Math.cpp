#include<bits/stdc++.h>
using namespace std; 

pair<int,int> fun(int n){

    if(n%2 == 0) return {n/2,n/2}; 
    
    // lcm = ab/hcf.....=> a(n-a)/hcf(a,(n-a)) ......as hcf(a,n-a) = a........
    // => lcm = a(n-a)/hcf = a(n-a)/a..... = n-a.....where (n-a) % a == 0.....so maximize a ...and minimize n-a
    // for(int i= n/2;i>=1;i--){
    //     if((n-i)%i ==0) return {i,n-i};
    // }
      
    bool flag = false;

    for(int i=2;i*i<=n;i++){

        if(n%i==0){
            int k = n/i;
            return {k,n-k}; 
        }

    }

    return {1,n-1};
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        pair<int,int> ans = fun(n);
        cout<<ans.first<<" "<<ans.second<<endl;
    }

}