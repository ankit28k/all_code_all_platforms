#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> visr(n+1,false) , visc(n+1,false);

    vector<pair<int,int>> arr(m);
    for(int i=0;i<m;i++){
        int r,c;
        cin>>r>>c;
        arr[i] = {r,c};
    }

    int ans=0;
    for(int i=m-1;i>=0;i--){
        int r = arr[i].first , c = arr[i].second;
        if(!visr[r] && !visc[c]) {
            ans++;
        }
        visr[r]=true;
        visc[c]=true;
    }

    cout<<ans<<endl;

}