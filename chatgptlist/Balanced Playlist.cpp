#include<bits/stdc++.h>
using namespace std;

bool comp(int a,int b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    vector<int> nsr(n) , ngr(n,-1);

    stack<int> st1;
    for(int i= 2*n-1;i>=0;i--){
        while(!st1.empty() && arr[st1.top()%n]*2 >= arr[i%n]){
            st1.pop();
        }

        if(st1.empty()) nsr[i%n]=-1;
        else nsr[i%n] = st1.top();
        st1.push(i);
    }
    
    vector<int> maxr(2*n);
    maxr[2*n-1] = arr[n-1];
    for(int i=2*n-2;i>=0;i--) maxr[i] = max(maxr[i+1],arr[i%n]);

    
    for(int i=0;i<n;i++){
        int idx = lower_bound(maxr.begin()+i+1,maxr.end(),arr[i],comp) - maxr.begin();
        idx--;

        if(i<idx) ngr[i] = idx;

    }

    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        if(ngr[i]== -1) ans[i] = nsr[i]-i ;
        else if(nsr[i] == -1) ans[i]= ngr[i]-i+ ans[ngr[i]%n];
        else if(nsr[i]<ngr[i]) ans[i] = nsr[i]-i;
        else if(nsr[i]>ngr[i]) ans[i] = ngr[i]-i + ans[ngr[i]%n];

    }

    for(int x:ans) cout<<x<<" ";
    cout<<endl;

}