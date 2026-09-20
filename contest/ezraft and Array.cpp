#include<bits/stdc++.h>
using namespace std;

vector<long long> fun(int n){

    if(n==1) return {1};
    if(n==2) return {-1};
   
    vector<long long> arr(n);
    arr[0]=1;
    arr[1]=2;

    long long s = 3;
    for(int i=2;i<n;i++) {
        arr[i] = s;
        s+=arr[i];
    }

    return arr;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<long long> ans = fun(n);
        if(ans.size()==1 && ans[0]==-1) cout<<-1<<endl;
        else{
            for(long long x:ans) cout<<x<<" ";
            cout<<endl;
        }
    }

}