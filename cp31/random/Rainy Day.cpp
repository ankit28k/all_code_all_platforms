#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr,int n,int m){

    for(int i=0;i<n;i+=m){
        if((i+1)%arr[i] == 0) return false;
    }

    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        int ans = n;
        int l = 0,h = n;
        while(l<=h){
            int m = l + (h-l)/2;
            if(check(arr,n,m)){
                ans = m;
                h = m-1;
            }

            else l = m+1;
        }
    }

}