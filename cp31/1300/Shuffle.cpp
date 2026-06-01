#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,m;
        cin>>n>>x>>m;
        
        int mini = x,maxi = x;
        while(m--){
            int l,r;
            cin>>l>>r;
            
            if( l<= maxi && r >= maxi){
                mini = min(mini,l);
                maxi = max(maxi,r);
            }

            else if(l<= mini && r >= mini){
                mini = min(mini,l);
                maxi = max(maxi,r);
            }

            else if(l<= mini && r >= maxi){
                mini = min(mini,l);
                maxi = max(maxi,r);
            }
            
        }

        cout<<maxi-mini + 1<<endl;
    }

}