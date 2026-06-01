#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr,int n){
    
    vector<int> temp1,temp2;
    int cnt1 =0,cnt2 =0;

    for(int i=n-2;i>0;i--){
        if(arr[i]>arr[i-1]) {
            temp1.push_back(arr[i]);
        }

        else temp2.push_back(arr[i]);
    }

    temp2.push_back(arr[0]);
    reverse(temp1.begin(),temp1.end());
    reverse(temp2.begin(),temp2.end());

    for(int i=0;i+1<temp1.size();i++){
        if(temp1[i]<temp1[i+1]) cnt1++;
    }

    for(int i=0;i+1<temp2.size();i++){
        if(temp2[i]<temp2[i+1]) cnt2++;
    }

    return cnt1 + cnt2;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<fun(arr,n)<<endl;
    }

}