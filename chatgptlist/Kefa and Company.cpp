#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) {
        int m,s;
        cin>>m>>s;
        arr[i] = {m,s};
    }

    sort(arr.begin(),arr.end());

    int l=0,r=0;
    long long ans=0,sum=0;
    while(r<n){

        sum += arr[r].second;
        while(l<=r && arr[r].first >= arr[l].first+d){
            sum -= arr[l].second;
            l++;
        }

        ans = max(ans,sum);
        r++;
    }

    cout<<ans<<endl;

}