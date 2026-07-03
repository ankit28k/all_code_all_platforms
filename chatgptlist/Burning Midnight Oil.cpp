#include<bits/stdc++.h>
using namespace std;

bool check(int m,int n,int k){

    int sum=m;
    while(m){
        m = m/k;
        sum+=m;
    }

    return sum>=n;
}
int main(){
    int n,k;
    cin>>n>>k;

    /* THE MATH TRAP:
    Why the geometric series formula v = (n * (k-1)) / k fails:
    
    The pure math formula assumes continuous, perfect decimal numbers. 
    However, the problem explicitly uses integer division (the floor function). 
    Every time we do `v / k`, we truncate and "lose" the decimal remainder. 
    Because of these lost fractions at every step, the pure math formula 
    will frequently underestimate the required starting value 'v'.
    
    Solution: Since the total lines written strictly increases as 'v' increases, 
    we must use Binary Search to simulate the integer division and find the exact minimum.
    */
    // long long val = (n*k - n )/k;
    // cout<<val+1<<endl;

    int l=0,h=n,ans=n;
    while(l<=h){
        int m = l +(h-l)/2;
        if(check(m,n,k)){
            ans=m;
            h=m-1;
        }

        else l = m+1;
    }

    cout<<ans<<endl;
}