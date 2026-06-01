#include<bits/stdc++.h>
using namespace std;
int main(){ 

    int n,q;
    cin>>n>>q;
    vector<pair<int,int>> arr(n);

    long long sum=0;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr[i] = {x,0}; //{value, last update time}
        sum+=x; 
    } 

    int curr=-1 , upd=0;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int i,x;
            cin>>i>>x;
            i--; //0 based

            if(upd >0 && arr[i].second < upd){ // not updated after last update of type 2{
                sum += x - curr;  
                arr[i].first = x; 
                arr[i].second = upd; // update the last update time
            }

            else {
                sum += x - arr[i].first;
                arr[i].first = x; 
            }
            cout<<sum<<endl;
        }

        else{
            int x;
            cin>>x;

            upd++;
            curr = x;
            sum = 1LL*x*n;
            cout<<sum<<endl;
        }
    }
    

}