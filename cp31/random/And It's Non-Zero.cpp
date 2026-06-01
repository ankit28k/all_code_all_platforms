#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<int> fq(31);
    vector<int> ans (200001,0);

    for(int i=1;i<200001;i++){

        for(int bit =0;bit<31;bit++){
            if(((i>>bit) & 1) == 0) fq[bit]++;
        }

        int temp=INT_MAX;
        for(int x:fq) temp = min(x,temp);
        ans[i] = temp;
    }

    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<ans[r] - ans[l]<<endl;

    }

}