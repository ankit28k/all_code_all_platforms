#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> temp;
    temp.push_back(arr[0]);
    
    for(int i=0;i<n;i++){
        int idx = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
        if(idx == temp.size()) temp.push_back(arr[i]);
        else temp[idx] = arr[i];
    }
    cout<<temp.size()<<endl;

    

}