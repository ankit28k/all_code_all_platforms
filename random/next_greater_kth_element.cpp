#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    deque<int> dq;
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        while(!dq.empty() && dq.size()>k ) dq.pop_back();
        while(!dq.empty() && dq.front()<=arr[i] ) dq.pop_front();    

        if(dq.size()<k) ans[i] = -1;
        else ans[i] = dq.back();
        dq.push_front(arr[i]);
    }

    for(int x:ans) cout<<x<<" ";
    cout<<endl;


}