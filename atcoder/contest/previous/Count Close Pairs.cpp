#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    long long ans=0;
    int r=1;
    for(int i=1;i<n;i++){
        
        if(r<i) r=i;

        while(r+1<=n){
            cout<<"? "<<i<<" "<<r+1<<endl;

            string s;
            cin>>s;
            if(s=="Yes") r++;
            else break;
        }

        ans+=r-i;
        
    }

    cout<<"! "<<ans<<endl;

}