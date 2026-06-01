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

        if(arr[n-2]<=arr[n-1]){

            cout<<n-2<<endl;
            for(int i=0;i<n-2;i++){
                cout<<i+1<<" "<<n-1<<" "<<n<<endl;
            }
        }

        else{
            cout<<-1<<endl;
        }
    }

}