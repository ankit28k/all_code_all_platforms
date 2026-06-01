#include<bits/stdc++.h>
using namespace std;


//gcd(i,ai) <= i ....=> gcd(1,a1) = 1.....since all distinct....=> gcd(2,a2) = 2....as i's all divisor already came befor....
// => gcd(i,ai) = i
// ai is a multiple of i


vector<int> fun(int n,int l ,int r){

    vector<int> ans;

    // This below condition is wrong. A small range can still have valid multiples.
    // ex 1000 .....has gcd 1 with 1....gcd 2 with 2....gcd 4 with 4....ie gcd(1000,1) =1 , gcd(1000,2) =2 , gcd(1000,4) =4
    //if((r-l+1) <n) return {};
 
    for(int i=1;i<=n;i++){

        // Find smallest multiple of i that is >= l
        long long val = 1LL*((l + i - 1) / i) * i;
        
        // If the smallest multiple exceeds r, it's impossible
        if (val > r) return {};
        ans.push_back(val);
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,l,r;
        cin>>n>>l>>r; 

        vector<int> ans = fun(n,l,r);
        if(ans.empty()){
            cout<<"NO"<<endl; 
        }

        else{
            cout<<"YES"<<endl;
            for(int x:ans) cout<<x<<" ";
            cout<<endl; 
        }
    }

}