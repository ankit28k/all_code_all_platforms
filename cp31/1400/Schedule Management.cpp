#include<bits/stdc++.h>
using namespace std;

bool poss(long long mid,vector<int>& arr,int n,int m){
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(mid>=arr[i]){
            ans += arr[i];
            ans += (mid-arr[i])/2;
        }
        else{
            ans += mid;
        }
    }
    return ans>=m;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> arr(n+1);
        map<int,int> mp;
        for(int i=0;i<m;i++)  {
            int x;
            cin>>x;
            arr[x]++;
        }

        long long l=1,h=2*m,ans=2*m;
        while(l<=h){
            long long mid = l+(h-l)/2;
            if(poss(mid,arr,n,m)){
                ans = mid;
                h=mid-1;
            }
            else l = mid+1;
        }

        cout<<ans<<endl;
    }

}