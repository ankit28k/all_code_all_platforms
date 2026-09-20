#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n),drr(n),brr(n);
    for(int i=0;i<n;i++) cin>>arr[i]>>drr[i]>>brr[i];

    vector<int> curr(n) ;
    map<int,int> fq;
    vector<vector<int>> ch(m+1);

    for(int i=0;i<n;i++){
        ch[drr[i]].push_back(i);

        if(drr[i]==1) curr[i]=brr[i];
        else curr[i]= arr[i];

        fq[curr[i]]++;
        
    }

    cout<<fq.size()<<endl;

    for(int day =2;day<=m;day++){

        for(auto it:ch[day]){

            if(curr[it]==brr[it]) continue;
            fq[curr[it]]--;
            if(fq[curr[it]]==0) fq.erase(curr[it]);

            curr[it]=brr[it];
            fq[curr[it]]++;
        }

        cout<<fq.size()<<endl;
    }

}