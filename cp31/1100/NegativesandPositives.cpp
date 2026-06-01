#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        int mini = INT_MAX , ncnt=0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            mini = min(mini,abs(arr[i]));
            if(arr[i]<0) ncnt++;
            sum += abs(arr[i]);
        }

        if(ncnt%2==0) cout<<sum<<endl;
        else cout<<sum-2*mini<<endl;
    }

}