#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
 
        vector<pair<int,int>> arr(n-1);
        for(int i=0;i<n-1;i++) {
            int x,y;
            cin>>x>>y;
            arr[i] = {x,y};
        }

        vector<int> vis(n+1,false);
        vis[1] = true;
        
        set<int> st;
        for(int i=0;i<n-1;i++) st.insert(i);
        
        int ans=0;
        while(st.size()>0){
            for(auto it =st.begin(); it!= st.end();){
                int i = *(it);
                int x =  arr[i].first , y = arr[i].second;

                if(vis[x] || vis[y]){
                    if(!vis[x]) vis[x] = true;
                    if(!vis[y]) vis[y]=true;
                    it = st.erase(it);
                }
                else it++;
            }
            ans++;
        }

        cout<<ans<<endl;
    }

}