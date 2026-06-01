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

        if(n%2==0){
            cout<<2<<endl;
            cout<<1<<" "<<n<<endl;  // all same number 
            cout<<1<<" "<<n<<endl; // all zero
        }

        else{
            cout<<4<<endl;
            cout<<1<<" "<<n<<endl; //all same
            cout<<1<<" "<<n-1<<endl; // all zero except last which is say a
            cout<<n-1<<" "<<n<<endl; // both same that is a
            cout<<n-1<<" "<<n<<endl;  //both zero

        }
    }

}