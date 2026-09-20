#include<bits/stdc++.h>
using namespace std;

bool poss(int mid,int n,vector<int>& queries,vector<pair<int,int>>& seg){

    vector<int> arr(n+1,0);
    for(int i=0;i<=mid;i++) arr[queries[i]]=1;
    
    vector<int> nz(n+1,0),no(n+1,0);

    for(int i=1;i<=n;i++){
        if(arr[i]==0){
            nz[i] = nz[i-1]+1;
            no[i] = no[i-1];
        }
        else {
            no[i] = no[i-1]+1;
            nz[i] = nz[i-1];
        }
    }

    for(auto it:seg){
        int a = it.first , b = it.second;
        if(no[b]-no[a-1] > nz[b]-nz[a-1]) return true;
    }
    return false;


}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> seg(m);
        for(int i=0;i<m;i++) {
            int a,b;
            cin>>a>>b;
            seg[i] = {a,b};
        }

        int q;
        cin>>q;
        vector<int> queries(q);
        for(int i=0;i<q;i++) cin>>queries[i];

        int l=0,h=q-1,ans=-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(poss(mid,n,queries,seg)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }

        if(ans==-1) cout<<-1<<endl;
        else cout<<ans+1<<endl;
    }

}