#include<bits/stdc++.h>
using namespace std;

int fun(int n,int k){
    if(n%2 ==0) {
        int val = k%n;
        if(val==0) return n;
        else return val;
    }

    else{
        int skip = (n-1)/2; //n+1 gives position but n-1 tells how many elements are skipped in between two elements in the cycle  

        int actual = k%n;
        if(actual ==0) actual = n;  
 
        int elements_skipped  = (k-1) /skip;  

        int shiffted = (actual + elements_skipped)%n;
        if(shiffted == 0) return n;
        else return shiffted;
        
        
        
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k; 

        cout<<fun(n,k)<<endl;


        // int i=0,j=n-1;
        // k--; // at 1st hour its the same case
        // while(k--){

        //     if((i+1)%n == (j-1+n)%n){
        //         i = (i+2)%n;
        //         j = (j-1 +n)%n;
        //     }

        //     else{
        //         i = (i+1)%n;
        //         j = (j-1+n)%n;
        //     }
        // }

        // cout<<i+1<<endl;
    }

}