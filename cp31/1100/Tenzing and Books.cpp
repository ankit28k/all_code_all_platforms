#include<bits/stdc++.h>
using namespace std;


// You would always choose a number, which has same bits of 1 ..... which X has or else we can never form X.
// example If X is 1011, we can choose 1010 , 1000 , 0011....as its or
// But cannot choose 0100 as it would make a change that is irreversible as its or operation, which will never yield to X... 
//Hence, We Iterate still, we find the number of type one, and as we find a number of type two, we break

bool fun(vector<int>& arr,vector<int>& brr,vector<int>& crr,int x,int n){

    if(x==0) return true;
    int ans =0;
    for(int i=0;i<n;i++){

        if((arr[i]&x) == arr[i]){ // arr[i] has same bits of 1 ....that x has
            ans = ans|arr[i];
            if(ans == x) return true;
        }
        else break;
    }
    for(int i=0;i<n;i++){
        if((brr[i]&x) == brr[i]){  
            ans = ans|brr[i];
            if(ans == x) return true;
        }
        else break;
    }
    for(int i=0;i<n;i++){
        if((crr[i]&x) == crr[i]){  
            ans = ans|crr[i];
            if(ans == x) return true;
        }
        else break;
    }

    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> arr(n),brr(n),crr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) cin>>brr[i];
        for(int i=0;i<n;i++) cin>>crr[i];

        if(fun(arr,brr,crr,x,n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }

}