#include<bits/stdc++.h>
using namespace std; 
bool fun(vector<int>& arr , vector<int>& p,int n){

    // if(n%2 !=0) {
    //     if(arr[(n+1)/2] != p[(n+1)/2]) return false;
    // } 

    for(int i=1;i<=n;i++){

        if(arr[i] != p[i]){
            bool flag = false;
            for(int j=i;j<=n;j*=2){
                if(arr[j] == p[i]){
                    flag = true;
                    break;
                }
            }

            if(!flag){
                for(int j=i/2;j>0;j/=2){
                    if(arr[j] == p[i]){
                        flag = true;
                        break;
                    }
                }
            }
            

            if(!flag) return false;
        }
    }

    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++) cin>>arr[i];

        vector<int> p(n+1);
        for(int i=1;i<=n;i++) p[i] = i;
        if(fun(arr,p,n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
         
    }

}