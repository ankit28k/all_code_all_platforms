#include<bits/stdc++.h>
using namespace std;

long long fun(vector<long long>& arr,int n){

    bool allodd = true,alleven = true;
    for(int i=0;i<n;i++){

        if(arr[i]%2 == 0) allodd = false;
        if(arr[i]% 2 != 0 ) alleven = false;
    }

    if(allodd == false && alleven == false) return 2;

    bool flag = true;
    long long ans;
    int i=2;
    while(flag && i<61){ // as 61
        long long curr = (1LL << i); //pow(2,i);.....pow also works

        set<long long> st;
        for(int j=0;j<n;j++){
            st.insert(arr[j]%curr);
        }

        if(st.size() == 2) {
            flag = false;
            ans = curr;
        }
        i++;
    }

    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<fun(arr,n)<<endl;
    }

}