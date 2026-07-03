#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> nsr(n),nsl(n);
    stack<int> st1,st2;

    for(int i=0;i<n;i++){
        while(!st1.empty() && arr[st1.top()] >= arr[i]) st1.pop();
        if(st1.empty()) nsl[i] = -1;
        else nsl[i] = st1.top();

        st1.push(i);

    }

    for(int i=n-1;i>=0;i--){
        while(!st2.empty() && arr[st2.top()] >= arr[i]) st2.pop();
        if(st2.empty()) nsr[i] = n;
        else nsr[i] = st2.top();

        st2.push(i);

    }

    long long ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans,1LL*(nsr[i]-nsl[i]-1)*arr[i]);
    }

    cout<<ans<<endl;


}