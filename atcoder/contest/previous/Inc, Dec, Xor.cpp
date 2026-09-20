#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n,0),nonzero;
    int q;
    cin>>q;
    int zor =0;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int idx;
            cin>>idx;
            zor ^= arr[idx-1];
            if(arr[idx-1]==0) nonzero.push_back(idx-1);
            arr[idx-1]++;
            zor ^= arr[idx-1];
            cout<<zor<<endl;
        }
        else {
            int tzor=0;
            vector<int> newnonzero;
            for(int i=0;i<nonzero.size();i++){
                arr[nonzero[i]] = max(0,arr[nonzero[i]]-1);
                tzor^=arr[nonzero[i]];
                if(arr[nonzero[i]]>0) newnonzero.push_back(nonzero[i]);
            }
            zor = tzor;
            nonzero = newnonzero;
            cout<<zor<<endl;
        }
    }




}