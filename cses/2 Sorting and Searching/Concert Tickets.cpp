#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    multiset<int> arr;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr.insert(x);
    }

    while(t--){
        int val;
        cin>>val;
        auto it = arr.lower_bound(val);
        if(*it == val){
            arr.erase(it);
            cout<<val<<endl;
        }

        else {
            if(it == arr.begin()){
                cout<<-1<<endl;
            }
            else{
                it--;
                cout<<*it<<endl;
                arr.erase(it);
            }
        }
    } 


}