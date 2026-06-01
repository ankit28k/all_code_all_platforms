#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first == b.first) return a.second<b.second;
    return a.first>b.first;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr[i] = {x,i};
        }

        sort(arr.begin(),arr.end(),comp);
        vector<pair<int,int>> temp(n+1,{-1,-1});

        temp[0] ={0,0};

        long long cost =0;
        int steps =1;
        for(int i=1;i<n;i+=2){
            int right = arr[i-1].second;
            int left = arr[i].second;

            temp[i] = {right,steps};
            temp[i+1] ={left,-steps};

            cost += 1LL* steps* 2* arr[i-1].first;
            cost += 1LL* steps* 2* arr[i].first;

            steps++;
        }

        if(temp[n].first==-1) {
            temp[n]={arr[n-1].second,steps};
            cost += 1LL* steps* 2* arr[n-1].first;
        }
        
        sort(temp.begin()+1,temp.end());

        vector<int> ans(n+1); 

        for(int i=0;i<=n;i++){
            ans[i] = temp[i].second;
        }
 

        cout<<cost<<endl;
        for(int x:ans) cout<<x<<" ";
        cout<<endl;

    }

}