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

        vector<int> pzor(n),szor(n);
        pzor[0] = arr[0];
        szor[n-1] = arr[n-1];
        for(int i=1;i<n;i++) pzor[i] = pzor[i-1]^arr[i];
        for(int i=n-2;i>=0;i--) szor[i] = szor[i+1]^arr[i];

        bool flag = false;
        for(int i=0;i<n-1;i++){
            if(pzor[i]==szor[i+1]) flag = true;
        }

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int a = pzor[i] ,b = pzor[j]^pzor[i], c= szor[j+1];
                if(a==b && b==c) flag = true;
            }
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


}