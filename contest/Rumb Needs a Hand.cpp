#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n),temp;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i] != i+1) temp.push_back(arr[i]);
        }

        bool flag = true;
        int nt = temp.size();
        for(int i=1;i<nt;i++){
            if(temp[i]>=temp[i-1]){
                flag = false;
                break;
            }
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}