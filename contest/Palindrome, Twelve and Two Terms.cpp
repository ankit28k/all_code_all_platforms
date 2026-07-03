#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

        long long p[12]={0,1,2,3,4,5,6,7,8,9,22,11};
        int r = n%12;
        if(n>=p[r]) cout<<p[r]<<" "<<n-p[r]<<endl;
        else cout <<-1<<endl;
    }

}