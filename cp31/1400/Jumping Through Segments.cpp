#include<bits/stdc++.h>
using namespace std;

bool poss(int k,vector<pair<int,int>>& arr,int n){
    pair<int,int> st = {-k,k};

    for(int i=0;i<n;i++){

        /*
        * WHY WE INTERSECT EVERY STEP INSTEAD OF JUST USING [-n*k, n*k]:
        * Intermediate intervals act as physical bottlenecks that restrict and reset your actual position.
        * 
        * Example: k = 10. Targets = [0,0], [0,0], [30,30].
        * - If we only checked absolute distance (3 steps * 10 = 30), we would think [30,30] is reachable.
        * - Reality: Steps 1 and 2 FORCE you to stay at exactly 0. 
        * - From 0, your max jump for Step 3 is only 10, making [30,30] physically impossible.
        * 
        * Taking the intersection step-by-step anchors your next jump to where you 
        * actually are, not where you theoretically could be in an empty void.
        */
        st.first = max(st.first,arr[i].first);
        st.second = min(st.second , arr[i].second);

        if(st.first > st.second ) return false;
        st = {st.first -k , st.second+k};
        
    }
    return true;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++) {
            int a,b;
            cin>>a>>b;
            arr[i] = {a,b};
        }

        int l=0,h=1e9,ans=1e9;
        while(l<=h){
            int m=l+(h-l)/2;
            if(poss(m,arr,n)){
                ans = m;
                h=m-1;
            }
            else l = m+1;
        }

        cout<<ans<<endl;
    }

    

}