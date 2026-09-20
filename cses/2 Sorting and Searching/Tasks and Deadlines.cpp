#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b){
    if(a.first==b.first) return a.second.first<b.second.first;
    return a.first>b.first;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> arr(n);
    for(int i=0;i<n;i++) {
        int d,dl;
        cin>>d>>dl;
        int v = dl-d;
        arr[i] = {v,{d,dl}};
    }

    sort(arr.begin(),arr.end(),comp);

    int time=0,ans=0;
    for(int i=0;i<n;i++){
        int d = arr[i].second.first , dl = arr[i].second.second;
        time += d;
        ans += dl - time;
    }
    cout<<ans<<endl;

}